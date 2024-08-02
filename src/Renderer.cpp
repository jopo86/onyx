#pragma warning(disable: 4244)

#include "Renderer.h"

#include "Window.h"
#include "Camera.h"

#include <map>

void onyx_err(const Onyx::Error&);
void onyx_warn(const Onyx::Warning&);

bool Onyx::Renderer::s_wireframe = false;
bool Onyx::Renderer::s_uiWireframeAllowed = false;
float Onyx::Renderer::s_lineWidth = 1.0f;
std::pair<bool, int> Onyx::Renderer::s_vsync = { true, 1 };
std::pair<bool, int> Onyx::Renderer::s_fpsLimit = { false, 60 };

std::recursive_mutex Onyx::Renderer::s_mtx_wireframe;
std::recursive_mutex Onyx::Renderer::s_mtx_uiWireframeAllowed;
std::recursive_mutex Onyx::Renderer::s_mtx_lineWidth;
std::recursive_mutex Onyx::Renderer::s_mtx_vsync;
std::recursive_mutex Onyx::Renderer::s_mtx_fpsLimit;

Onyx::Renderer::Renderer()
{
	m_pWin = nullptr;
	m_pCam = nullptr;
	m_useCamForUi = false;
	m_lightingEnabled = false;
	m_pLighting = nullptr;
	m_fogEnabled = false;
	m_pFog = nullptr;
}

Onyx::Renderer::Renderer(Camera& cam)
{
	m_pWin = nullptr;
	m_pCam = &cam;
	m_useCamForUi = false;
	m_pLighting = nullptr;
	m_lightingEnabled = false;
	m_pFog = nullptr;
	m_fogEnabled = false;
}

Onyx::Renderer::Renderer(Camera& cam, Lighting& lighting)
{
	m_pWin = nullptr;
	m_pCam = &cam;
	m_useCamForUi = false;
	setLighting(lighting);
	m_lightingEnabled = true;
	m_fogEnabled = false;
	m_pFog = nullptr;
}

Onyx::Renderer::Renderer(Camera& cam, Fog& fog)
{
	m_pWin = nullptr;
	m_pCam = &cam;
	m_useCamForUi = false;
	setFog(fog);
	m_fogEnabled = true;
	m_lightingEnabled = false;
	m_pLighting = nullptr;
}

Onyx::Renderer::Renderer(Camera& cam, Lighting& lighting, Fog& fog)
{
	m_pWin = nullptr;
	m_pCam = &cam;
	m_useCamForUi = false;
	setLighting(lighting);
	setFog(fog);
	m_lightingEnabled = true;
	m_fogEnabled = true;
}

void Onyx::Renderer::render()
{
	if (m_pWin == nullptr)
	{
		onyx_err(Error{
			.sourceFunction = "Onyx::Renderer::render()",
			.message = "Window pointer is null.",
			.howToFix = "Make sure the renderer was linked to a window (Window::linkRenderer())."
			}
		);
		return;
	}

	if (m_pCam == nullptr)
	{
		for (Renderable* r : m_renderables) r->render();
		for (TextRenderable3D* tr : m_textRenderables3D) tr->render();
	}
	else
	{
		for (Renderable* r : m_renderables) r->render(m_pCam->getViewMatrix(), m_pCam->getProjectionMatrix(), m_pCam->getPosition());
		for (TextRenderable3D* tr : m_textRenderables3D) tr->render(m_pCam->getViewMatrix(), m_pCam->getProjectionMatrix(), m_pCam->getPosition());
	}

	glDisable(GL_DEPTH_TEST);
	s_mtx_uiWireframeAllowed.lock();
	if (s_uiWireframeAllowed) {
		s_mtx_uiWireframeAllowed.unlock();
		if (!m_useCamForUi)
		{
			for (UiRenderable* uir : m_uiRenderables) uir->render(m_ortho);
			for (TextRenderable* tr : m_textRenderables) tr->render(m_ortho);
		}
		else
		{
			for (UiRenderable* uir : m_uiRenderables) uir->render(m_pCam->getProjectionMatrix() * m_pCam->getViewMatrix());
			for (TextRenderable* tr : m_textRenderables) tr->render(m_pCam->getProjectionMatrix() * m_pCam->getViewMatrix());
		}
	}
	else
	{
		s_mtx_uiWireframeAllowed.unlock();
		s_mtx_wireframe.lock();
		bool _wireframe = s_wireframe;
		s_mtx_wireframe.unlock();
		SetWireframe(false);

		if (!m_useCamForUi)
		{
			for (UiRenderable* uir : m_uiRenderables) uir->render(m_ortho);
			for (TextRenderable* tr : m_textRenderables) tr->render(m_ortho);
		}
		else
		{
			for (UiRenderable* uir : m_uiRenderables) uir->render(m_pCam->getProjectionMatrix() * m_pCam->getViewMatrix());
			for (TextRenderable* tr : m_textRenderables) tr->render(m_pCam->getProjectionMatrix() * m_pCam->getViewMatrix());
		}

		SetWireframe(_wireframe);
	}
	glEnable(GL_DEPTH_TEST);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Renderer::add(Renderable& renderable)
{
	Renderable* p_renderable = &renderable;
	Shader* shader = p_renderable->getShader();
	shader->use();
	shader->setBool("u_lighting.enabled", m_lightingEnabled);
	shader->setBool("u_fog.enabled", m_fogEnabled);
	if (m_pLighting != nullptr)
	{
		shader->setVec3("u_lighting.color", m_pLighting->getColor());
		shader->setFloat("u_lighting.ambientStrength", m_pLighting->getAmbientStrength());
		shader->setVec3("u_lighting.direction", m_pLighting->getDirection());
	}
	if (m_pFog != nullptr)
	{
		shader->setVec3("u_fog.color", m_pFog->getColor());
		shader->setFloat("u_fog.start", m_pFog->getStart());
		shader->setFloat("u_fog.end", m_pFog->getEnd());
	}
	m_renderables.push_back(p_renderable);
}

void Onyx::Renderer::add(ModelRenderable& modelRenderable)
{
	for (std::pair<const std::string, Renderable>& r : modelRenderable.m_renderableMap)
	{
		add(r.second);
	}
}

void Onyx::Renderer::add(UiRenderable& uiRenderable)
{
	m_uiRenderables.push_back(&uiRenderable);
}

void Onyx::Renderer::add(TextRenderable& textRenderable)
{
	m_textRenderables.push_back(&textRenderable);
}

void Onyx::Renderer::add(TextRenderable3D& textRenderable3D)
{
	TextRenderable3D* p_renderable = &textRenderable3D;
	Shader* shader = p_renderable->getShader();
	shader->use();
	shader->setBool("u_fog.enabled", m_fogEnabled);
	if (m_pFog != nullptr)
	{
		shader->setVec3("u_fog.color", m_pFog->getColor());
		shader->setFloat("u_fog.start", m_pFog->getStart());
		shader->setFloat("u_fog.end", m_pFog->getEnd());
	}
	m_textRenderables3D.push_back(p_renderable);
}

void Onyx::Renderer::clear()
{
	m_renderables.clear();
	m_uiRenderables.clear();
	m_textRenderables.clear();
	m_textRenderables3D.clear();
}

void Onyx::Renderer::clearRenderables()
{
	m_renderables.clear();
}

void Onyx::Renderer::clearUiRenderables()
{
	m_uiRenderables.clear();
}

void Onyx::Renderer::clearTextRenderables()
{
	m_textRenderables.clear();
}

void Onyx::Renderer::clearTextRenderables3D()
{
	m_textRenderables3D.clear();
}

bool Onyx::Renderer::isLightingEnabled() const
{
	return m_lightingEnabled;
}

bool Onyx::Renderer::isFogEnabled() const
{
	return m_fogEnabled;
}

void Onyx::Renderer::setLightingEnabled(bool enabled)
{
	if (m_pLighting == nullptr)
	{
		onyx_warn(Warning{
			   .sourceFunction = "Onyx::Renderer::setLightingEnabled(bool enabled)",
			   .message = "Lighting is not set for the renderer, cannot enable/disable it.",
			   .howToFix = "Set lighting for the renderer using Onyx::Renderer::setLighting(Lighting& lighting) (or add it to the constructor) before enabling/disabling it.",
			   .severity = Warning::Severity::Med
			}
		);
		return;
	}

	m_lightingEnabled = enabled;
	for (Renderable* r : m_renderables)
	{
		Shader* shader = r->getShader();
		shader->use();
		shader->setBool("u_lighting.enabled", enabled);
	}
}

void Onyx::Renderer::setFogEnabled(bool enabled)
{
	if (m_pFog == nullptr)
	{
		onyx_warn(Warning{
			   .sourceFunction = "Onyx::Renderer::setFogEnabled(bool enabled)",
			   .message = "Fog is not set for the renderer, cannot enable/disable it.",
			   .howToFix = "Set fog for the renderer using Onyx::Renderer::setFog(Fog& fog) (or add it to the constructor) before enabling/disabling it.",
			   .severity = Warning::Severity::Med
			}
		);
		return;
	}

	m_fogEnabled = enabled;
	for (Renderable* r : m_renderables)
	{
		Shader* shader = r->getShader();
		shader->use();
		shader->setBool("u_fog.enabled", enabled);
	}
	for (TextRenderable3D* tr : m_textRenderables3D)
	{
		Shader* shader = tr->getShader();
		shader->use();
		shader->setBool("u_fog.enabled", enabled);
	}
}

void Onyx::Renderer::toggleLightingEnabled()
{
	setLightingEnabled(!m_lightingEnabled);
}

void Onyx::Renderer::toggleFogEnabled()
{
	setFogEnabled(!m_fogEnabled);
}

const Onyx::Lighting& Onyx::Renderer::getLighting() const
{
	return *m_pLighting;
}

const Onyx::Fog& Onyx::Renderer::getFog() const
{
	return *m_pFog;
}

void Onyx::Renderer::setLighting(Lighting& lighting)
{
	m_pLighting = &lighting;
	for (Renderable* r : m_renderables)
	{
		Shader* shader = r->getShader();
		shader->use();
		shader->setVec3("u_lighting.color", lighting.getColor());
		shader->setFloat("u_lighting.ambientStrength", lighting.getAmbientStrength());
		shader->setVec3("u_lighting.direction", lighting.getDirection());
	}
}

void Onyx::Renderer::setFog(Fog& fog)
{
	m_pFog = &fog;
	for (Renderable* r : m_renderables)
	{
		Shader* shader = r->getShader();
		shader->use();
		shader->setVec3("u_fog.color", fog.getColor());
		shader->setFloat("u_fog.start", fog.getStart());
		shader->setFloat("u_fog.end", fog.getEnd());
	}
	for (TextRenderable3D* tr : m_textRenderables3D)
	{
		Shader* shader = tr->getShader();
		shader->use();
		shader->setVec3("u_fog.color", fog.getColor());
		shader->setFloat("u_fog.start", fog.getStart());
		shader->setFloat("u_fog.end", fog.getEnd());
	}
}

void Onyx::Renderer::refreshLighting()
{
	for (Renderable* r : m_renderables)
	{
		Shader* shader = r->getShader();
		shader->use();
		shader->setBool("u_lighting.enabled", m_lightingEnabled);
		if (m_pLighting != nullptr)
		{
			shader->setVec3("u_lighting.color", m_pLighting->getColor());
			shader->setFloat("u_lighting.ambientStrength", m_pLighting->getAmbientStrength());
			shader->setVec3("u_lighting.direction", m_pLighting->getDirection());
		}
	}
}

void Onyx::Renderer::refreshFog()
{
	for (Renderable* r : m_renderables)
	{
		Shader* shader = r->getShader();
		shader->use();
		shader->setBool("u_fog.enabled", m_fogEnabled);
		if (m_pFog != nullptr)
		{
			shader->setVec3("u_fog.color", m_pFog->getColor());
			shader->setFloat("u_fog.start", m_pFog->getStart());
			shader->setFloat("u_fog.end", m_pFog->getEnd());
		}
	}
	for (TextRenderable3D* tr : m_textRenderables3D)
	{
		Shader* shader = tr->getShader();
		shader->use();
		shader->setBool("u_fog.enabled", m_fogEnabled);
		if (m_pFog != nullptr)
		{
			shader->setVec3("u_fog.color", m_pFog->getColor());
			shader->setFloat("u_fog.start", m_pFog->getStart());
			shader->setFloat("u_fog.end", m_pFog->getEnd());
		}
	}
}

const std::vector<Onyx::Renderable*>& Onyx::Renderer::getRenderables() const
{
	return m_renderables;
}

const std::vector<Onyx::UiRenderable*>& Onyx::Renderer::getUiRenderables() const
{
	return m_uiRenderables;
}

const std::vector<Onyx::TextRenderable*>& Onyx::Renderer::getTextRenderables() const
{
	return m_textRenderables;
}

const std::vector<Onyx::TextRenderable3D*>& Onyx::Renderer::getTextRenderables3D() const
{
	return m_textRenderables3D;
}

const Onyx::Camera& Onyx::Renderer::getCamera() const
{
	return *m_pCam;
}

void Onyx::Renderer::setCamera(Camera& cam)
{
	m_pCam = &cam;
}

void Onyx::Renderer::setUseCameraForUi(bool useCamForUi)
{
	m_useCamForUi = useCamForUi;
}

bool Onyx::Renderer::isUsingCameraForUi() const
{
	return m_useCamForUi;
}

void Onyx::Renderer::SetWireframe(bool _wireframe)
{
	s_mtx_wireframe.lock();
	if (s_wireframe == _wireframe) 
	{
		s_mtx_wireframe.unlock();
		return;
	}

	s_wireframe = _wireframe;
	glPolygonMode(GL_FRONT_AND_BACK, s_wireframe ? GL_LINE : GL_FILL);
	s_mtx_wireframe.unlock();

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Renderer::SetUiWireframeAllowed(bool allowed)
{
	s_mtx_uiWireframeAllowed.lock();
	s_uiWireframeAllowed = allowed;
	s_mtx_uiWireframeAllowed.unlock();
}

void Onyx::Renderer::ToggleWireframe()
{
	s_mtx_wireframe.lock();
	SetWireframe(!s_wireframe);
	s_mtx_wireframe.unlock();
}

void Onyx::Renderer::ToggleUiWireframeAllowed()
{
	s_mtx_uiWireframeAllowed.lock();
	s_uiWireframeAllowed = !s_uiWireframeAllowed;
	s_mtx_uiWireframeAllowed.unlock();
}

void Onyx::Renderer::SetVSync(bool enabled, int interval)
{
	s_mtx_vsync.lock();
	s_vsync = { enabled, interval };
	glfwSwapInterval(s_vsync.first ? s_vsync.second : 0);
	s_mtx_vsync.unlock();
}

void Onyx::Renderer::ToggleVSyncEnabled()
{
	s_mtx_vsync.lock();
	s_vsync.first = !s_vsync.first;
	glfwSwapInterval(s_vsync.first ? s_vsync.second : 0);
	s_mtx_vsync.unlock();
}

void Onyx::Renderer::SetFPSLimit(bool enabled, int fps)
{
	s_mtx_fpsLimit.lock();
	s_fpsLimit = { enabled, fps };
	s_mtx_fpsLimit.unlock();
}

void Onyx::Renderer::ToggleFPSLimitEnabled()
{
	s_mtx_fpsLimit.lock();
	s_fpsLimit.first = !s_fpsLimit.first;
	s_mtx_fpsLimit.unlock();
}

bool Onyx::Renderer::IsWireframe()
{
	s_mtx_wireframe.lock();
	bool _wireframe = s_wireframe;
	s_mtx_wireframe.unlock();
	return _wireframe;
}

bool Onyx::Renderer::IsUiWireframeAllowed()
{
	s_mtx_uiWireframeAllowed.lock();
	bool allowed = s_uiWireframeAllowed;
	s_mtx_uiWireframeAllowed.unlock();
	return allowed;
}

std::pair<bool, int> Onyx::Renderer::GetVSync()
{
	s_mtx_vsync.lock();
	std::pair<bool, int> vsync = s_vsync;
	s_mtx_vsync.unlock();
	return vsync;
}

std::pair<bool, int> Onyx::Renderer::GetFPSLimit()
{
	s_mtx_fpsLimit.lock();
	std::pair<bool, int> fpsLimit = s_fpsLimit;
	s_mtx_fpsLimit.unlock();
	return fpsLimit;
}

void Onyx::Renderer::SetLineWidth(float width)
{
	glLineWidth(width);
	s_mtx_lineWidth.lock();
	s_lineWidth = width;
	s_mtx_lineWidth.unlock();

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

float Onyx::Renderer::GetLineWidth()
{
	s_mtx_lineWidth.lock();
	float width = s_lineWidth;
	s_mtx_lineWidth.unlock();
	return width;
}

void Onyx::Renderer::dispose()
{
	if (m_disposed) return;
	for (Renderable* r : m_renderables) r->dispose();
	for (UiRenderable* uir : m_uiRenderables) uir->dispose();
	for (TextRenderable* tr : m_textRenderables) tr->dispose();
	for (TextRenderable3D* tr : m_textRenderables3D) tr->dispose();
	m_disposed = true;
}
