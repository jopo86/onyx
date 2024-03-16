#pragma once

#include <string>

#include "Core.h"
#include "Font.h"
#include "Math.h"
#include "Window.h"
#include "Shader.h"
#include "File.h"
#include "Projection.h"

namespace Onyx
{
	class TextRenderer
	{
		friend class Window;

	public:
		TextRenderer();
		TextRenderer(Window& window);

		void renderText(const std::string& text, Onyx::Math::Vec2 pos, Onyx::Math::Vec3 color);
		void renderText(const std::string& text, Onyx::Math::Vec2 pos, float scale, Onyx::Math::Vec3 color);

		void updateProjection(Projection proj);

		uint getVAO();
		uint getVBO();

		void setFont(Font& font);

	private:
		uint vao, vbo;
		Shader shader;

		Font font;
	};
}
