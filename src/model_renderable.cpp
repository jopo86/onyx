#include <onyx/model_renderable.hpp>

using onyx::math::Vec3, onyx::math::Mat4;

onyx::ModelRenderable::ModelRenderable() 
{
	this->hidden = false;
}

onyx::ModelRenderable::ModelRenderable(Model& model)
{
	for (ModelUnit& unit : model.data)
	{
		this->renderable_map.insert(
			std::pair<std::string, Renderable>(
				unit.name,
				Renderable(unit.mesh, unit.shader, unit.texture)
			)
		);
	}
	this->hidden = false;
}

onyx::ModelRenderable::ModelRenderable(Model& model, Shader shader_override)
{
	for (ModelUnit& unit : model.data)
	{
		this->renderable_map.insert(
			std::pair<std::string, Renderable>(
				unit.name,
				Renderable(unit.mesh, shader_override, unit.texture)
			)
		);
	}
	this->hidden = false;
}

void onyx::ModelRenderable::render()
{
	for (std::pair<const std::string, Renderable>& renderable : this->renderable_map)
	{
		renderable.second.render();
	}
}

void onyx::ModelRenderable::render(const Mat4& view, const Mat4& proj, const Vec3& cam_pos)
{
	for (std::pair<const std::string, Renderable>& renderable : this->renderable_map)
	{
		renderable.second.render(view, proj, cam_pos);
	}
}

void onyx::ModelRenderable::hide()
{
	for (std::pair<const std::string, Renderable>& renderable : this->renderable_map)
	{
		renderable.second.hide();
	}
	this->hidden = true;
}

void onyx::ModelRenderable::show()
{
	for (std::pair<const std::string, Renderable>& renderable : this->renderable_map)
	{
		renderable.second.show();
	}
	this->hidden = false;
}

void onyx::ModelRenderable::toggle_visibility()
{
	for (std::pair<const std::string, Renderable>& renderable : this->renderable_map)
	{
		renderable.second.toggle_visibility();
	}
	this->hidden = !this->hidden;
}

const std::map<std::string, onyx::Renderable>& onyx::ModelRenderable::get_renderables() const
{
	return this->renderable_map;
}

onyx::Renderable& onyx::ModelRenderable::get_renderable(std::string name)
{
	return this->renderable_map.at(name);
}

const Vec3& onyx::ModelRenderable::get_position() const
{
	return this->renderable_map.begin()->second.get_position();
}

const Vec3& onyx::ModelRenderable::get_rotation() const
{
	return this->renderable_map.begin()->second.get_rotation();
}

const Vec3& onyx::ModelRenderable::get_scale() const
{
	return this->renderable_map.begin()->second.get_scale();
}

void onyx::ModelRenderable::set_position(const Vec3& position)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.set_position(position);
	}
}

void onyx::ModelRenderable::set_rotation(const Vec3& rotations)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.set_rotation(rotations);
	}
}

void onyx::ModelRenderable::set_scale(const Vec3& scales)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.set_scale(scales);
	}
}

void onyx::ModelRenderable::translate(const Vec3& translation)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.translate(translation);
	}
}

void onyx::ModelRenderable::translate_local(const Vec3& translation)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.translate_local(translation);
	}
}

void onyx::ModelRenderable::rotate(const Vec3& rotations)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.rotate(rotations);
	}
}

void onyx::ModelRenderable::rotate(const Vec3& rotations, const Vec3& origin)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.rotate(rotations, origin);
	}
}

void onyx::ModelRenderable::scale(const Vec3& scalars)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.scale(scalars);
	}
}

void onyx::ModelRenderable::scale(float scalar)
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.scale(scalar);
	}
}

void onyx::ModelRenderable::reset_transform()
{
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.reset_transform();
	}
}

void onyx::ModelRenderable::dispose()
{
	if (this->disposed) return;
	for (std::pair<const std::string, Renderable>& r : this->renderable_map)
	{
		r.second.dispose();
	}
	this->disposed = true;
}
