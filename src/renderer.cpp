#pragma warning(disable: 4244)

#include <onyx/renderer.hpp>

#include <onyx/window.hpp>
#include <onyx/camera.hpp>

#include <map>

void onyx_err(const onyx::Error&);
void onyx_warn(const onyx::Warning&);

bool onyx::Renderer::wireframe = false;
bool onyx::Renderer::ui_wireframe_allowed = false;
float onyx::Renderer::line_width = 1.0f;
std::pair<bool, int> onyx::Renderer::vsync = { true, 1 };
std::pair<bool, int> onyx::Renderer::fps_limit = { false, 60 };

std::recursive_mutex onyx::Renderer::mtx_wireframe;
std::recursive_mutex onyx::Renderer::mtx_ui_wireframe_allowed;
std::recursive_mutex onyx::Renderer::mtx_line_width;
std::recursive_mutex onyx::Renderer::mtx_vsync;
std::recursive_mutex onyx::Renderer::mtx_fps_limit;

onyx::Renderer::Renderer()
{
	this->p_win = nullptr;
	this->p_cam = nullptr;
	this->use_cam_for_ui = false;
	this->lighting_enabled = false;
	this->p_lighting = nullptr;
	this->fog_enabled = false;
	this->p_fog = nullptr;
}

onyx::Renderer::Renderer(Camera& cam)
{
	this->p_win = nullptr;
	this->p_cam = &cam;
	this->use_cam_for_ui = false;
	this->p_lighting = nullptr;
	this->lighting_enabled = false;
	this->p_fog = nullptr;
	this->fog_enabled = false;
}

onyx::Renderer::Renderer(Camera& cam, Lighting& lighting)
{
	this->p_win = nullptr;
	this->p_cam = &cam;
	this->use_cam_for_ui = false;
	set_lighting(lighting);
	this->lighting_enabled = true;
	this->fog_enabled = false;
	this->p_fog = nullptr;
}

onyx::Renderer::Renderer(Camera& cam, Fog& fog)
{
	this->p_win = nullptr;
	this->p_cam = &cam;
	this->use_cam_for_ui = false;
	set_fog(fog);
	this->fog_enabled = true;
	this->lighting_enabled = false;
	this->p_lighting = nullptr;
}

onyx::Renderer::Renderer(Camera& cam, Lighting& lighting, Fog& fog)
{
	this->p_win = nullptr;
	this->p_cam = &cam;
	this->use_cam_for_ui = false;
	set_lighting(lighting);
	set_fog(fog);
	this->lighting_enabled = true;
	this->fog_enabled = true;
}

void onyx::Renderer::render()
{
	if (this->p_win == nullptr)
	{
		onyx_err(Error{
			.source_function = "onyx::Renderer::render()",
			.message = "Window pointer is null.",
			.how_to_fix = "Make sure the renderer was linked to a window (Window::link_renderer())."
			}
		);
		return;
	}

	if (this->p_cam == nullptr)
	{
		for (Renderable* r : this->renderables) r->render();
		for (TextRenderable3D* tr : this->text_renderables_3d) tr->render();
	}
	else
	{
		for (Renderable* r : this->renderables) r->render(this->p_cam->get_view_matrix(), this->p_cam->get_projection_matrix(), this->p_cam->get_position());
		for (TextRenderable3D* tr : this->text_renderables_3d) tr->render(this->p_cam->get_view_matrix(), this->p_cam->get_projection_matrix(), this->p_cam->get_position());
	}

	glDisable(GL_DEPTH_TEST);
	Renderer::mtx_ui_wireframe_allowed.lock();
	if (Renderer::ui_wireframe_allowed) {
		Renderer::mtx_ui_wireframe_allowed.unlock();
		if (!this->use_cam_for_ui)
		{
			for (UiRenderable* uir : this->ui_renderables) uir->render(this->ortho);
			for (TextRenderable* tr : this->text_renderables) tr->render(this->ortho);
		}
		else
		{
			for (UiRenderable* uir : this->ui_renderables) uir->render(this->p_cam->get_projection_matrix() * this->p_cam->get_view_matrix());
			for (TextRenderable* tr : this->text_renderables) tr->render(this->p_cam->get_projection_matrix() * this->p_cam->get_view_matrix());
		}
	}
	else
	{
		Renderer::mtx_ui_wireframe_allowed.unlock();
		Renderer::mtx_wireframe.lock();
		bool _wireframe = Renderer::wireframe;
		Renderer::mtx_wireframe.unlock();
		set_wireframe(false);

		if (!this->use_cam_for_ui)
		{
			for (UiRenderable* uir : this->ui_renderables) uir->render(this->ortho);
			for (TextRenderable* tr : this->text_renderables) tr->render(this->ortho);
		}
		else
		{
			for (UiRenderable* uir : this->ui_renderables) uir->render(this->p_cam->get_projection_matrix() * this->p_cam->get_view_matrix());
			for (TextRenderable* tr : this->text_renderables) tr->render(this->p_cam->get_projection_matrix() * this->p_cam->get_view_matrix());
		}

		set_wireframe(_wireframe);
	}
	glEnable(GL_DEPTH_TEST);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Renderer::add(Renderable& renderable)
{
	Renderable* p_renderable = &renderable;
	Shader* shader = p_renderable->get_shader();
	shader->use();
	shader->set_bool("u_lighting.enabled", this->lighting_enabled);
	shader->set_bool("u_fog.enabled", this->fog_enabled);
	if (this->p_lighting != nullptr)
	{
		shader->set_vec3("u_lighting.color", this->p_lighting->get_color());
		shader->set_float("u_lighting.ambient_strength", this->p_lighting->get_ambient_strength());
		shader->set_vec3("u_lighting.direction", this->p_lighting->get_direction());
	}
	if (this->p_fog != nullptr)
	{
		shader->set_vec3("u_fog.color", this->p_fog->get_color());
		shader->set_float("u_fog.start", this->p_fog->get_start());
		shader->set_float("u_fog.end", this->p_fog->get_end());
	}
	this->renderables.push_back(p_renderable);
}

void onyx::Renderer::add(ModelRenderable& model_renderable)
{
	for (std::pair<const std::string, Renderable>& r : model_renderable.renderable_map)
	{
		add(r.second);
	}
}

void onyx::Renderer::add(UiRenderable& ui_renderable)
{
	this->ui_renderables.push_back(&ui_renderable);
}

void onyx::Renderer::add(TextRenderable& text_renderable)
{
	this->text_renderables.push_back(&text_renderable);
}

void onyx::Renderer::add(TextRenderable3D& text_renderable_3d)
{
	TextRenderable3D* p_renderable = &text_renderable_3d;
	Shader* shader = p_renderable->get_shader();
	shader->use();
	shader->set_bool("u_fog.enabled", this->fog_enabled);
	if (this->p_fog != nullptr)
	{
		shader->set_vec3("u_fog.color", this->p_fog->get_color());
		shader->set_float("u_fog.start", this->p_fog->get_start());
		shader->set_float("u_fog.end", this->p_fog->get_end());
	}
	this->text_renderables_3d.push_back(p_renderable);
}

void onyx::Renderer::clear()
{
	this->renderables.clear();
	this->ui_renderables.clear();
	this->text_renderables.clear();
	this->text_renderables_3d.clear();
}

void onyx::Renderer::clear_renderables()
{
	this->renderables.clear();
}

void onyx::Renderer::clear_ui_renderables()
{
	this->ui_renderables.clear();
}

void onyx::Renderer::clear_text_renderables()
{
	this->text_renderables.clear();
}

void onyx::Renderer::clear_text_renderables3_d()
{
	this->text_renderables_3d.clear();
}

bool onyx::Renderer::is_lighting_enabled() const
{
	return this->lighting_enabled;
}

bool onyx::Renderer::is_fog_enabled() const
{
	return this->fog_enabled;
}

void onyx::Renderer::set_lighting_enabled(bool enabled)
{
	if (this->p_lighting == nullptr)
	{
		onyx_warn(Warning{
			   .source_function = "onyx::Renderer::set_lighting_enabled(bool enabled)",
			   .message = "Lighting is not set for the renderer, cannot enable/disable it.",
			   .how_to_fix = "Set lighting for the renderer using onyx::Renderer::set_lighting(Lighting& lighting) (or add it to the constructor) before enabling/disabling it.",
			   .severity = Warning::Severity::Med
			}
		);
		return;
	}

	this->lighting_enabled = enabled;
	for (Renderable* r : this->renderables)
	{
		Shader* shader = r->get_shader();
		shader->use();
		shader->set_bool("u_lighting.enabled", enabled);
	}
}

void onyx::Renderer::set_fog_enabled(bool enabled)
{
	if (this->p_fog == nullptr)
	{
		onyx_warn(Warning{
			   .source_function = "onyx::Renderer::set_fog_enabled(bool enabled)",
			   .message = "Fog is not set for the renderer, cannot enable/disable it.",
			   .how_to_fix = "Set fog for the renderer using onyx::Renderer::set_fog(Fog& fog) (or add it to the constructor) before enabling/disabling it.",
			   .severity = Warning::Severity::Med
			}
		);
		return;
	}

	this->fog_enabled = enabled;
	for (Renderable* r : this->renderables)
	{
		Shader* shader = r->get_shader();
		shader->use();
		shader->set_bool("u_fog.enabled", enabled);
	}
	for (TextRenderable3D* tr : this->text_renderables_3d)
	{
		Shader* shader = tr->get_shader();
		shader->use();
		shader->set_bool("u_fog.enabled", enabled);
	}
}

void onyx::Renderer::toggle_lighting_enabled()
{
	set_lighting_enabled(!this->lighting_enabled);
}

void onyx::Renderer::toggle_fog_enabled()
{
	set_fog_enabled(!this->fog_enabled);
}

const onyx::Lighting& onyx::Renderer::get_lighting() const
{
	return *this->p_lighting;
}

const onyx::Fog& onyx::Renderer::get_fog() const
{
	return *this->p_fog;
}

void onyx::Renderer::set_lighting(Lighting& lighting)
{
	this->p_lighting = &lighting;
	for (Renderable* r : this->renderables)
	{
		Shader* shader = r->get_shader();
		shader->use();
		shader->set_vec3("u_lighting.color", lighting.get_color());
		shader->set_float("u_lighting.ambient_strength", lighting.get_ambient_strength());
		shader->set_vec3("u_lighting.direction", lighting.get_direction());
	}
}

void onyx::Renderer::set_fog(Fog& fog)
{
	this->p_fog = &fog;
	for (Renderable* r : this->renderables)
	{
		Shader* shader = r->get_shader();
		shader->use();
		shader->set_vec3("u_fog.color", fog.get_color());
		shader->set_float("u_fog.start", fog.get_start());
		shader->set_float("u_fog.end", fog.get_end());
	}
	for (TextRenderable3D* tr : this->text_renderables_3d)
	{
		Shader* shader = tr->get_shader();
		shader->use();
		shader->set_vec3("u_fog.color", fog.get_color());
		shader->set_float("u_fog.start", fog.get_start());
		shader->set_float("u_fog.end", fog.get_end());
	}
}

void onyx::Renderer::refresh_lighting()
{
	for (Renderable* r : this->renderables)
	{
		Shader* shader = r->get_shader();
		shader->use();
		shader->set_bool("u_lighting.enabled", this->lighting_enabled);
		if (this->p_lighting != nullptr)
		{
			shader->set_vec3("u_lighting.color", this->p_lighting->get_color());
			shader->set_float("u_lighting.ambient_strength", this->p_lighting->get_ambient_strength());
			shader->set_vec3("u_lighting.direction", this->p_lighting->get_direction());
		}
	}
}

void onyx::Renderer::refresh_fog()
{
	for (Renderable* r : this->renderables)
	{
		Shader* shader = r->get_shader();
		shader->use();
		shader->set_bool("u_fog.enabled", this->fog_enabled);
		if (this->p_fog != nullptr)
		{
			shader->set_vec3("u_fog.color", this->p_fog->get_color());
			shader->set_float("u_fog.start", this->p_fog->get_start());
			shader->set_float("u_fog.end", this->p_fog->get_end());
		}
	}
	for (TextRenderable3D* tr : this->text_renderables_3d)
	{
		Shader* shader = tr->get_shader();
		shader->use();
		shader->set_bool("u_fog.enabled", this->fog_enabled);
		if (this->p_fog != nullptr)
		{
			shader->set_vec3("u_fog.color", this->p_fog->get_color());
			shader->set_float("u_fog.start", this->p_fog->get_start());
			shader->set_float("u_fog.end", this->p_fog->get_end());
		}
	}
}

const std::vector<onyx::Renderable*>& onyx::Renderer::get_renderables() const
{
	return this->renderables;
}

const std::vector<onyx::UiRenderable*>& onyx::Renderer::get_ui_renderables() const
{
	return this->ui_renderables;
}

const std::vector<onyx::TextRenderable*>& onyx::Renderer::get_text_renderables() const
{
	return this->text_renderables;
}

const std::vector<onyx::TextRenderable3D*>& onyx::Renderer::get_text_renderables_3d() const
{
	return this->text_renderables_3d;
}

const onyx::Camera& onyx::Renderer::get_camera() const
{
	return *this->p_cam;
}

void onyx::Renderer::set_camera(Camera& cam)
{
	this->p_cam = &cam;
}

void onyx::Renderer::set_use_camera_for_ui(bool use_cam_for_ui)
{
	this->use_cam_for_ui = use_cam_for_ui;
}

bool onyx::Renderer::is_using_camera_for_ui() const
{
	return this->use_cam_for_ui;
}

void onyx::Renderer::set_wireframe(bool _wireframe)
{
	Renderer::mtx_wireframe.lock();
	if (Renderer::wireframe == _wireframe) 
	{
		Renderer::mtx_wireframe.unlock();
		return;
	}

	Renderer::wireframe = _wireframe;
	glPolygonMode(GL_FRONT_AND_BACK, Renderer::wireframe ? GL_LINE : GL_FILL);
	Renderer::mtx_wireframe.unlock();

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Renderer::set_ui_wireframe_allowed(bool allowed)
{
	Renderer::mtx_ui_wireframe_allowed.lock();
	Renderer::ui_wireframe_allowed = allowed;
	Renderer::mtx_ui_wireframe_allowed.unlock();
}

void onyx::Renderer::toggle_wireframe()
{
	Renderer::mtx_wireframe.lock();
	set_wireframe(!Renderer::wireframe);
	Renderer::mtx_wireframe.unlock();
}

void onyx::Renderer::toggle_ui_wireframe_allowed()
{
	Renderer::mtx_ui_wireframe_allowed.lock();
	Renderer::ui_wireframe_allowed = !Renderer::ui_wireframe_allowed;
	Renderer::mtx_ui_wireframe_allowed.unlock();
}

void onyx::Renderer::set_vsync(bool enabled, int interval)
{
	Renderer::mtx_vsync.lock();
	Renderer::vsync = { enabled, interval };
	glfwSwapInterval(Renderer::vsync.first ? Renderer::vsync.second : 0);
	Renderer::mtx_vsync.unlock();
}

void onyx::Renderer::toggle_vsync_enabled()
{
	Renderer::mtx_vsync.lock();
	Renderer::vsync.first = !Renderer::vsync.first;
	glfwSwapInterval(Renderer::vsync.first ? Renderer::vsync.second : 0);
	Renderer::mtx_vsync.unlock();
}

void onyx::Renderer::set_fps_limit(bool enabled, int fps)
{
	Renderer::mtx_fps_limit.lock();
	Renderer::fps_limit = { enabled, fps };
	Renderer::mtx_fps_limit.unlock();
}

void onyx::Renderer::toggle_fps_limit_enabled()
{
	Renderer::mtx_fps_limit.lock();
	Renderer::fps_limit.first = !Renderer::fps_limit.first;
	Renderer::mtx_fps_limit.unlock();
}

bool onyx::Renderer::is_wireframe()
{
	Renderer::mtx_wireframe.lock();
	bool _wireframe = Renderer::wireframe;
	Renderer::mtx_wireframe.unlock();
	return _wireframe;
}

bool onyx::Renderer::is_ui_wireframe_allowed()
{
	Renderer::mtx_ui_wireframe_allowed.lock();
	bool allowed = Renderer::ui_wireframe_allowed;
	Renderer::mtx_ui_wireframe_allowed.unlock();
	return allowed;
}

std::pair<bool, int> onyx::Renderer::get_vsync()
{
	Renderer::mtx_vsync.lock();
	std::pair<bool, int> vsync = Renderer::vsync;
	Renderer::mtx_vsync.unlock();
	return vsync;
}

std::pair<bool, int> onyx::Renderer::get_fps_limit()
{
	Renderer::mtx_fps_limit.lock();
	std::pair<bool, int> fps_limit = Renderer::fps_limit;
	Renderer::mtx_fps_limit.unlock();
	return fps_limit;
}

void onyx::Renderer::set_line_width(float width)
{
	glLineWidth(width);
	Renderer::mtx_line_width.lock();
	Renderer::line_width = width;
	Renderer::mtx_line_width.unlock();

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

float onyx::Renderer::get_line_width()
{
	Renderer::mtx_line_width.lock();
	float width = Renderer::line_width;
	Renderer::mtx_line_width.unlock();
	return width;
}

void onyx::Renderer::dispose()
{
	if (this->disposed) return;
	for (Renderable* r : this->renderables) r->dispose();
	for (UiRenderable* uir : this->ui_renderables) uir->dispose();
	for (TextRenderable* tr : this->text_renderables) tr->dispose();
	for (TextRenderable3D* tr : this->text_renderables_3d) tr->dispose();
	this->disposed = true;
}
