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

const std::map<std::string, Onyx::Renderable>& Onyx::ModelRenderable::getRenderables() const
{
	return renderableMap;
}

Onyx::Renderable& Onyx::ModelRenderable::getRenderable(std::string name)
{
	return renderableMap.at(name);
}

const Vec3& Onyx::ModelRenderable::getPosition() const
{
	return renderableMap.begin()->second.getPosition();
}

const Vec3& Onyx::ModelRenderable::getRotation() const
{
	return renderableMap.begin()->second.getRotation();
}

const Vec3& Onyx::ModelRenderable::getScale() const
{
	return renderableMap.begin()->second.getScale();
}

void Onyx::ModelRenderable::setPosition(const Vec3& position)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.setPosition(position);
	}
}

void Onyx::ModelRenderable::setRotation(const Vec3& rotations)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.setRotation(rotations);
	}
}

void Onyx::ModelRenderable::setScale(const Vec3& scales)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.setScale(scales);
	}
}

void Onyx::ModelRenderable::translate(const Vec3& translation)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.translate(translation);
	}
}

void Onyx::ModelRenderable::translateLocal(const Vec3& translation)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.translateLocal(translation);
	}
}

void Onyx::ModelRenderable::rotate(const Vec3& rotations)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.rotate(rotations);
	}
}

void Onyx::ModelRenderable::rotate(const Vec3& rotations, const Vec3& origin)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.rotate(rotations, origin);
	}
}

void Onyx::ModelRenderable::scale(const Vec3& scalars)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.scale(scalars);
	}
}

void Onyx::ModelRenderable::scale(float scalar)
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.scale(scalar);
	}
}

void Onyx::ModelRenderable::resetTransform()
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.resetTransform();
	}
}

void Onyx::ModelRenderable::dispose()
{
	for (std::pair<const std::string, Renderable>& r : renderableMap)
	{
		r.second.dispose();
	}
}
