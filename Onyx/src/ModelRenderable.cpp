#include "ModelRenderable.h"

using Onyx::Math::Vec3, Onyx::Math::Mat4;

Onyx::ModelRenderable::ModelRenderable() 
{
	hidden = false;
}

Onyx::ModelRenderable::ModelRenderable(Model& model)
{
	for (Triple<Mesh, Texture, Shader>& meshData : model.data)
	{
		renderables.push_back(Renderable(meshData.first, meshData.third, meshData.second));
	}
	hidden = false;
}

void Onyx::ModelRenderable::render()
{
	for (Renderable& renderable : renderables)
	{
		renderable.render();
	}
}

void Onyx::ModelRenderable::render(const Mat4& view, const Mat4& proj)
{
	for (Renderable& renderable : renderables)
	{
		renderable.render(view, proj);
	}
}

void Onyx::ModelRenderable::hide()
{
	for (Renderable& renderable : renderables)
	{
		renderable.hide();
	}
	hidden = true;
}

void Onyx::ModelRenderable::show()
{
	for (Renderable& renderable : renderables)
	{
		renderable.show();
	}
	hidden = false;
}

void Onyx::ModelRenderable::toggleVisibility()
{
	for (Renderable& renderable : renderables)
	{
		renderable.toggleVisibility();
	}
	hidden = !hidden;
}

void Onyx::ModelRenderable::translate(const Vec3& xyz)
{
	for (Renderable& renderable : renderables)
	{
		renderable.translate(xyz);
	}
}

void Onyx::ModelRenderable::rotate(float degrees, const Vec3& mask)
{
	for (Renderable& renderable : renderables)
	{
		renderable.rotate(degrees, mask);
	}
}

void Onyx::ModelRenderable::scale(float scalar)
{
	for (Renderable& renderable : renderables)
	{
		renderable.scale(scalar);
	}
}

void Onyx::ModelRenderable::scale(const Vec3& xyzScalar)
{
	for (Renderable& renderable : renderables)
	{
		renderable.scale(xyzScalar);
	}
}

void Onyx::ModelRenderable::resetTransform()
{
	for (Renderable& renderable : renderables)
	{
		renderable.resetTransform();
	}
}

const std::vector<Onyx::Renderable>& Onyx::ModelRenderable::getRenderables() const
{
	return renderables;
}

void Onyx::ModelRenderable::dispose()
{
	for (Renderable& renderable : renderables)
	{
		renderable.dispose();
	}
}
