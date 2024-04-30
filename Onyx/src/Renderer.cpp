#pragma warning(disable: 4244)

#include "Renderer.h"

#include <map>

void onyx_warn(const Onyx::Warning&);

bool Onyx::Renderer::sm_wireframe = false;
bool Onyx::Renderer::sm_uiWireframeAllowed = false;
float Onyx::Renderer::sm_lineWidth = 1.0f;

Onyx::Renderer::Renderer()
{
	m_pCam = nullptr;
	m_lightingEnabled = false;
	m_pLighting = nullptr;
}

Onyx::Renderer::Renderer(Window& window)
{
	m_pCam = nullptr;
	window.m_pRenderer = this;
	m_pLighting = nullptr;
	m_ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
	m_lightingEnabled = false;
}

Onyx::Renderer::Renderer(Window& window, Camera& cam)
{
	m_pCam = &cam;
	window.m_pRenderer = this;
	m_pLighting = nullptr;
	m_ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
	m_lightingEnabled = false;
}

Onyx::Renderer::Renderer(Window& window, Camera& cam, Lighting& lighting)
{
	m_pCam = &cam;
	setLighting(lighting);
	window.m_pRenderer = this;
	m_ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
	m_lightingEnabled = true;
}

void Onyx::Renderer::render()
{
	if (m_pCam == nullptr) for (Renderable* r : m_renderables) r->render();
	else for (Renderable* r : m_renderables) r->render(m_pCam->getViewMatrix(), m_pCam->getProjectionMatrix());

	glDisable(GL_DEPTH_TEST);
	if (sm_uiWireframeAllowed) {
		for (UiRenderable* uir : m_uiRenderables) uir->render(m_ortho);
		for (TextRenderable* tr : m_textRenderables) tr->render(m_ortho);
	}
	else
	{
		bool _wireframe = sm_wireframe;
		SetWireframe(false);
		for (UiRenderable* uir : m_uiRenderables) uir->render(m_ortho);
		for (TextRenderable* tr : m_textRenderables) tr->render(m_ortho);
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
	if (m_pLighting != nullptr)
	{
		shader->setVec3("u_lighting.color", m_pLighting->getColor());
		shader->setFloat("u_lighting.ambientStrength", m_pLighting->getAmbientStrength());
		shader->setVec3("u_lighting.direction", m_pLighting->getDirection());
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

bool Onyx::Renderer::isLightingEnabled() const
{
	return m_lightingEnabled;
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

void Onyx::Renderer::toggleLightingEnabled()
{
	setLightingEnabled(!m_lightingEnabled);
}

const Onyx::Lighting& Onyx::Renderer::getLighting() const
{
	return *m_pLighting;
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

void Onyx::Renderer::SetWireframe(bool _wireframe)
{
	if (sm_wireframe == _wireframe) return;

	sm_wireframe = _wireframe;
	glPolygonMode(GL_FRONT_AND_BACK, sm_wireframe ? GL_LINE : GL_FILL);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Renderer::SetUiWireframeAllowed(bool allowed)
{
	sm_uiWireframeAllowed = allowed;
}

void Onyx::Renderer::ToggleWireframe()
{
	SetWireframe(!sm_wireframe);
}

void Onyx::Renderer::ToggleUiWireframeAllowed()
{
	sm_uiWireframeAllowed = !sm_uiWireframeAllowed;
}

bool Onyx::Renderer::IsWireframe()
{
	return sm_wireframe;
}

bool Onyx::Renderer::IsUiWireframeAllowed()
{
	return sm_uiWireframeAllowed;
}

void Onyx::Renderer::SetLineWidth(float width)
{
	glLineWidth(width);
	sm_lineWidth = width;

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

float Onyx::Renderer::GetLineWidth()
{
	return sm_lineWidth;
}

void Onyx::Renderer::dispose()
{
	for (Renderable* r : m_renderables) r->dispose();
	for (UiRenderable* r : m_uiRenderables) r->dispose();
	for (TextRenderable* r : m_textRenderables) r->dispose();
}
