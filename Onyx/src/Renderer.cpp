#pragma warning(disable: 4244)

#include "Renderer.h"

bool Onyx::Renderer::wireframe = false;
bool Onyx::Renderer::uiWireframeAllowed = false;
float Onyx::Renderer::lineWidth = 1.0f;

Onyx::Renderer::Renderer()
{
	renderables = {};
	cam = nullptr;
}

Onyx::Renderer::Renderer(Window& window)
{
	renderables = {};
	cam = nullptr;
	window.p_renderer = this;
	ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
}

Onyx::Renderer::Renderer(Window& window, Camera& cam)
{
	renderables = {};
	this->cam = &cam;
	window.p_renderer = this;
	ortho = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f).getMatrix();
}

void Onyx::Renderer::render()
{
	for (Renderable* renderable : renderables)
	{
		cam == nullptr ? renderable->render() : renderable->render(cam->getViewMatrix(), cam->getProjectionMatrix());
	}

	glDisable(GL_DEPTH_TEST);
	if (uiWireframeAllowed) for (UiRenderable* renderable : uiRenderables)
	{
		renderable->render(ortho);
	}
	else
	{
		bool _wireframe = wireframe;
		SetWireframe(false);
		for (UiRenderable* renderable : uiRenderables)
		{
			renderable->render(ortho);
		}
		SetWireframe(_wireframe);
	}
	glEnable(GL_DEPTH_TEST);
}

void Onyx::Renderer::add(Renderable& renderable)
{
	renderables.push_back(&renderable);
}

void Onyx::Renderer::add(UiRenderable& uiRenderable)
{
	uiRenderables.push_back(&uiRenderable);
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
