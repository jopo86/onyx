#include "Renderer.h"

bool Onyx::Renderer::wireframe = false;
float Onyx::Renderer::lineWidth = 1.0f;

Onyx::Renderer::Renderer()
{
	renderables = {};
	cam = nullptr;
}

Onyx::Renderer::Renderer(Camera& cam)
{
	renderables = {};
	this->cam = &cam;
}

void Onyx::Renderer::render()
{
	for (const std::pair<Renderable*, bool>& renderable : renderables)
	{
		if (renderable.second) {
			cam == nullptr ? renderable.first->render() : renderable.first->render(cam->getViewMatrix(), cam->getProjectionMatrix());
		}
	}
}

void Onyx::Renderer::add(Renderable& renderable)
{
	renderables.push_back({ &renderable, true });
}

void Onyx::Renderer::show(int index)
{
	renderables[index].second = true;
}

void Onyx::Renderer::hide(int index)
{
	renderables[index].second = false;
}

void Onyx::Renderer::toggleVisibility(int index)
{
	renderables[index].second = !renderables[index].second;
}

void Onyx::Renderer::SetWireframe(bool _wireframe)
{
	if (wireframe == _wireframe) return;

	wireframe = _wireframe;
	glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
}

void Onyx::Renderer::ToggleWireframe()
{
	SetWireframe(!wireframe);
}

bool Onyx::Renderer::IsWireframe()
{
	return wireframe;
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
		renderables[i].first->dispose();
	}
}
