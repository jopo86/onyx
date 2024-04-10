#pragma once

#include "Shader.h"
#include "Math.h"

namespace Onyx
{
	/*
		@brief A namespace providing access to preset shaders for convenience.
		Users would otherwise have to write their own GLSL shader code.
	 */
	namespace ShaderPresets
	{

		/*
			@brief Creates a shader that colors the mesh the specified color.
			Compatible with vertex format V.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting shader.
		 */
		Shader V_Color(Onyx::Math::Vec4 rgba);

		/*
			@brief Creates a shader that uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			Compatible with vertex format V.
			@return The resulting shader.
		 */
		Shader V_XYZtoRGB();

		/*
			@brief Creates a shader that colors the mesh with the colors found in the vertex array.
			Compatible with vertex format VC/CV.
			@return The resulting shader.
		 */
		Shader VC();

		/*
			@brief Creates a shader that textures the mesh with the texture coordinates found in the vertex array.
			Compatible with vertex format VT/TV.
			@return The resulting shader.
		 */
		Shader VT();

		/*
			@brief Creates a shader that colors/textures the mesh with a blend of the colors and texture coordinates found in the vertex array.
			Compatible with vertex format VCT/VTC/CVT/TVC/CTV/TCV.
			@return The resulting shader.
		 */
		Shader VCT();

		Shader VNC();

		Shader VNT();

		Shader VNCT();

		/*
			@brief Creates a shader for UI elements that colors the mesh the specified color.
			Compatible with vertex format V.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1
			@return The resulting shader.
		 */
		Shader UI_Color(Onyx::Math::Vec4 rgba);

		/*
			@brief Creates a shader for UI elements that textures the mesh with the texture coordinates found in the vertex array.
			Compatible with vertex format VT/TV.
			@return The resulting shader.
		 */
		Shader UI_Texture();

		/*
			@brief Creates a shader for UI text elements.
			Incompatible with any vertex format, only used by TextRenderer.
			@return The resulting shader.
		 */
		Shader UI_Text();
	}
}
