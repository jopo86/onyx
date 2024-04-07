#pragma warning(disable: 4244)

#include "Renderer.h"

bool Onyx::Renderer::wireframe = false;
bool Onyx::Renderer::uiWireframeAllowed = false;
float Onyx::Renderer::lineWidth = 1.0f;

Onyx::Renderer::Renderer()
{
	renderables = {};
	cam = nullptr;
	lightingEnabled = false;
	lighting = nullptr;
}

Onyx::Renderer::Renderer(Window& window)
{
	renderables = {};
	cam = nullptr;
	window.p_renderer = this;
	lighting = nullptr;
	ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
	lightingEnabled = false;
}

Onyx::Renderer::Renderer(Window& window, Camera& cam)
{
	renderables = {};
	this->cam = &cam;
	window.p_renderer = this;
	lighting = nullptr;
	ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
	lightingEnabled = false;
}

Onyx::Renderer::Renderer(Window& window, Camera& cam, Lighting& lighting)
{
	renderables = {};
	this->cam = &cam;
	this->lighting = &lighting;
	window.p_renderer = this;
	ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
	lightingEnabled = true;
}

void Onyx::Renderer::render()
{
	if (cam == nullptr) for (Renderable* renderable : renderables) renderable->render();
	else for (Renderable* renderable : renderables) renderable->render(cam->getViewMatrix(), cam->getProjectionMatrix());

	glDisable(GL_DEPTH_TEST);
	if (uiWireframeAllowed) for (UiRenderable* renderable : uiRenderables)renderable->render(ortho);
	else
	{
		bool _wireframe = wireframe;
		SetWireframe(false);
		for (UiRenderable* renderable : uiRenderables) renderable->render(ortho);
		SetWireframe(_wireframe);
	}
	glEnable(GL_DEPTH_TEST);
}

void Onyx::Renderer::add(Renderable& renderable)
{
	Renderable* p_renderable = &renderable;
	Shader* shader = p_renderable->getShader();
	shader->use();
	shader->setBool("u_lighting.enabled", lightingEnabled);
	if (lighting != nullptr)
	{
		shader->setVec3("u_lighting.color", lighting->getColor());
		shader->setFloat("u_lighting.ambientStrength", lighting->getAmbientStrength());
		shader->setVec3("u_lighting.direction", lighting->getDirection());
	}
	renderables.push_back(p_renderable);
}

void Onyx::Renderer::add(UiRenderable& uiRenderable)
{
	uiRenderables.push_back(&uiRenderable);
}

bool Onyx::Renderer::isLightingEnabled() const
{
	return lightingEnabled;
}

void Onyx::Renderer::setLightingEnabled(bool enabled)
{
	if (lighting == nullptr)
	{
		Onyx::Err("setLightingEnabled() was called on a renderer without any lighting settings.");
		return;
	}
	lightingEnabled = enabled;
	for (Renderable* renderable : renderables)
	{
		Shader* shader = renderable->getShader();
		shader->use();
		shader->setBool("u_lighting.enabled", enabled);
	}
}

void Onyx::Renderer::toggleLightingEnabled()
{
	setLightingEnabled(!lightingEnabled);
}

const Onyx::Lighting& Onyx::Renderer::getLighting() const
{
	return *lighting;
}

void Onyx::Renderer::setLighting(Lighting& lighting)
{
	this->lighting = &lighting;
	for (Renderable* renderable : renderables)
	{
		Shader* shader = renderable->getShader();
		shader->use();
		shader->setVec3("u_lighting.color", lighting.getColor());
		shader->setFloat("u_lighting.ambientStrength", lighting.getAmbientStrength());
		shader->setVec3("u_lighting.direction", lighting.getDirection());
	}
}

void Onyx::Renderer::SetWireframe(bool _wireframe)
{
	if (wireframe == _wireframe) return;

	wireframe = _wireframe;
	glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
}

void Onyx::Renderer::SetUiWireframeAllowed(bool allowed)
{
	uiWireframeAllowed = allowed;
}

void Onyx::Renderer::ToggleWireframe()
{
	SetWireframe(!wireframe);
}

void Onyx::Renderer::ToggleUiWireframeAllowed()
{
	uiWireframeAllowed = !uiWireframeAllowed;
}

bool Onyx::Renderer::IsWireframe()
{
	return wireframe;
}

bool Onyx::Renderer::IsUiWireframeAllowed()
{
	return uiWireframeAllowed;
}

void Onyx::Renderer::SetLineWidth(float width)
{
	glLineWidth(width);
	lineWidth = width;
}

float Onyx::Renderer::GetLineWidth()
{
	return lineWidth;
}

void Onyx::Renderer::dispose()
{
	for (int i = 0; i < renderables.size(); i++)
	{
		renderables[i]->dispose();
	}
}
