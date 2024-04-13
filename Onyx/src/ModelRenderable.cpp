#include "ModelRenderable.h"

using Onyx::Math::Vec3, Onyx::Math::Mat4;

Onyx::ModelRenderable::ModelRenderable() 
{
	hidden = false;
}

Onyx::ModelRenderable::ModelRenderable(Model& model)
{
	for (ModelUnit& unit : model.data)
	{
		renderableMap.insert(
			std::pair<std::string, Renderable>(
				unit.name,
				Renderable(unit.mesh, unit.shader, unit.texture)
			)
		);
	}
	hidden = false;
}

void Onyx::ModelRenderable::render()
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.render();
	}
}

void Onyx::ModelRenderable::render(const Mat4& view, const Mat4& proj)
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.render(view, proj);
	}
}

void Onyx::ModelRenderable::hide()
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.hide();
	}
	hidden = true;
}

void Onyx::ModelRenderable::show()
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.show();
	}
	hidden = false;
}

void Onyx::ModelRenderable::toggleVisibility()
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.toggleVisibility();
	}
	hidden = !hidden;
}

void Onyx::ModelRenderable::translate(const Vec3& xyz)
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.translate(xyz);
	}
}

void Onyx::ModelRenderable::rotate(float degrees, const Vec3& mask)
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.rotate(degrees, mask);
	}
}

void Onyx::ModelRenderable::scale(float scalar)
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.scale(scalar);
	}
}

void Onyx::ModelRenderable::scale(const Vec3& xyzScalar)
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.scale(xyzScalar);
	}
}

void Onyx::ModelRenderable::resetTransform()
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.resetTransform();
	}
}

const std::map<std::string, Onyx::Renderable>& Onyx::ModelRenderable::getRenderables() const
{
	return renderableMap;
}

Onyx::Renderable& Onyx::ModelRenderable::getRenderable(std::string name)
{
	return renderableMap.at(name);
}

void Onyx::ModelRenderable::dispose()
{
	for (std::pair<const std::string, Renderable>& renderable : renderableMap)
	{
		renderable.second.dispose();
	}
}
