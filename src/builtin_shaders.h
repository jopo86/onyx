// The library's built-in shaders.
//
// These are compiled into the binary so the library has no runtime dependency on a resource
// path or on any file shipped alongside it -- Shader::p_color() and friends work with zero
// filesystem setup.
//
// Each entry is a "combined" shader: vertex stage, a #switch line, then the fragment stage.
// Shader::from_source() splits them at #switch. Edit these directly; they are ordinary source.

#pragma once

namespace onyx::builtin_shaders
{
	inline constexpr const char* p_color = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;

out vec3 io_pos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec3 io_pos;

out vec4 o_color;

uniform vec3 u_camPos;
uniform vec4 u_color;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = u_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}

)ONYXGLSL";

	inline constexpr const char* p_ui_color = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;

uniform mat4 u_model;
uniform mat4 u_projection;

void main() {
	gl_Position = u_projection * u_model * vec4(i_pos, 1.0);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

uniform vec4 u_color;

out vec4 o_color;

void main() {
	o_color = u_color;
}
)ONYXGLSL";

	inline constexpr const char* p_xyz_to_rgb = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;

out vec3 io_pos;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	io_color = vec4(i_pos, 1.0);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec3 io_pos;
in vec4 io_color;

out vec4 o_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
})ONYXGLSL";

	inline constexpr const char* pc = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;

out vec3 io_pos;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	io_color = i_color;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec3 io_pos;
in vec4 io_color;

out vec4 o_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main() {
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}

)ONYXGLSL";

	inline constexpr const char* pct = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;
layout (location = 2) in vec2 i_texCoord;

out vec3 io_pos;
out vec4 io_color;
out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	io_color = i_color;
	io_texCoord = i_texCoord;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec3 io_pos;
in vec4 io_color;
in vec2 io_texCoord;

out vec4 o_color;

uniform vec3 u_camPos;
uniform sampler2D u_tex;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = io_color * texture(u_tex, io_texCoord);

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}

)ONYXGLSL";

	inline constexpr const char* pn_color = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 3) in vec3 i_normal;

out vec3 io_pos;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

uniform vec4 u_color;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

uniform Lighting u_lighting;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	if (!u_lighting.enabled)
	{
		io_color = u_color;
		return;
	}

	vec3 normal = normalize(mat3(transpose(u_inverseModel)) * i_normal);
	vec3 color = u_lighting.color * u_color.rgb;
	vec3 ambient = color * u_lighting.ambientStrength;
	
	vec3 lightDir = normalize(-u_lighting.direction);
	float diffuseFactor = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = color * diffuseFactor;

	io_color = vec4(ambient + diffuse, u_color.a);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

out vec4 o_color;

in vec3 io_pos;
in vec4 io_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}
)ONYXGLSL";

	inline constexpr const char* pn_xyz_to_rgb = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 3) in vec3 i_normal;

out vec3 io_pos;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

uniform Lighting u_lighting;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	io_color = vec4(io_pos, 1.0);
	if (!u_lighting.enabled) return;

	vec3 normal = normalize(mat3(transpose(u_inverseModel)) * i_normal);
	vec3 color = u_lighting.color * io_color.rgb;
	vec3 ambient = color * u_lighting.ambientStrength;
	
	vec3 lightDir = normalize(-u_lighting.direction);
	float diffuseFactor = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = color * diffuseFactor;

	io_color = vec4(ambient + diffuse, io_color.a);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

out vec4 o_color;

in vec3 io_pos;
in vec4 io_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}
)ONYXGLSL";

	inline constexpr const char* pnc = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;
layout (location = 3) in vec3 i_normal;

out vec3 io_pos;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

uniform Lighting u_lighting;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	if (!u_lighting.enabled)
	{
		io_color = i_color;
		return;
	}

	vec3 normal = normalize(mat3(transpose(u_inverseModel)) * i_normal);
	vec3 color = u_lighting.color * i_color.rgb;
	vec3 ambient = color * u_lighting.ambientStrength;
	
	vec3 lightDir = normalize(-u_lighting.direction);
	float diffuseFactor = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = color * diffuseFactor;

	io_color = vec4(ambient + diffuse, i_color.a);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

out vec4 o_color;

in vec3 io_pos;
in vec4 io_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}

)ONYXGLSL";

	inline constexpr const char* pnct = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;
layout (location = 2) in vec2 i_texCoord;
layout (location = 3) in vec3 i_normal;

out vec3 io_pos;
out float io_diffuseFactor;
out vec4 io_color;
out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

uniform Lighting u_lighting;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_texCoord = i_texCoord;
	io_color = i_color;
	io_pos = vec3(u_model * vec4(i_pos, 1.0));

	if (!u_lighting.enabled)
	{
		io_diffuseFactor = 1.0;
		return;
	}

	vec3 normal = normalize(mat3(transpose(u_inverseModel)) * i_normal);
	vec3 lightDir = normalize(-u_lighting.direction);
	io_diffuseFactor = max(dot(normal, lightDir), 0.0);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

out vec4 o_color;

in vec3 io_pos;
in float io_diffuseFactor;
in vec4 io_color;
in vec2 io_texCoord;

uniform vec3 u_camPos;
uniform sampler2D u_tex;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Lighting u_lighting;
uniform Fog u_fog;

void main()
{
	vec4 texColor = texture(u_tex, io_texCoord);

	if (!u_lighting.enabled)
	{
		o_color = io_color * texColor;
		if (!u_fog.enabled) return;

		float camDist = distance(u_camPos, io_pos);

		if (camDist > u_fog.start)
		{
			float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
			fogFactor = clamp(fogFactor, 0.0, 1.0);
			float a = o_color.a;
			o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
			o_color.a = a;
		}
	}

	vec3 color = u_lighting.color * io_color.rgb * texColor.rgb;

	vec3 ambient = color * u_lighting.ambientStrength;
	vec3 diffuse = color * io_diffuseFactor;
	
	o_color = vec4(diffuse + ambient, texColor.a * io_color.a);

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}
)ONYXGLSL";

	inline constexpr const char* pnt = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 2) in vec2 i_texCoord;
layout (location = 3) in vec3 i_normal;

out vec3 io_pos;
out float io_diffuseFactor;
out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

uniform Lighting u_lighting;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	io_texCoord = i_texCoord;

	if (!u_lighting.enabled)
	{
		io_diffuseFactor = 1.0;
		return;
	}

	vec3 normal = normalize(mat3(transpose(u_inverseModel)) * i_normal);
	vec3 lightDir = normalize(-u_lighting.direction);
	io_diffuseFactor = max(dot(normal, lightDir), 0.0);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

out vec4 o_color;

in vec3 io_pos;
in float io_diffuseFactor;
in vec2 io_texCoord;

uniform vec3 u_camPos;
uniform sampler2D u_tex;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Lighting u_lighting;
uniform Fog u_fog;

void main()
{
	vec4 texColor = texture(u_tex, io_texCoord);

	if (!u_lighting.enabled)
	{
		o_color = texColor;
		if (!u_fog.enabled) return;

		float camDist = distance(u_camPos, io_pos);

		if (camDist > u_fog.start)
		{
			float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
			fogFactor = clamp(fogFactor, 0.0, 1.0);
			o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		}
	}

	vec3 color = u_lighting.color * texColor.rgb;
	vec3 ambient = color * u_lighting.ambientStrength;
	vec3 diffuse = color * io_diffuseFactor;
	o_color = vec4(diffuse + ambient, texColor.a);
	
	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}
)ONYXGLSL";

	inline constexpr const char* pt = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 2) in vec2 i_texCoord;

out vec3 io_pos;
out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_texCoord = i_texCoord;
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec3 io_pos;
in vec2 io_texCoord;

out vec4 o_color;

uniform vec3 u_camPos;
uniform sampler2D u_tex;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = texture(u_tex, io_texCoord);
	
	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}

)ONYXGLSL";

	inline constexpr const char* pt_ui = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 2) in vec2 i_texCoord;

out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_model * vec4(i_pos, 1.0f);
	io_texCoord = i_texCoord;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;

void main()
{
	o_color = texture(u_tex, io_texCoord);
}

)ONYXGLSL";

	inline constexpr const char* text = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec4 i_vertex;

out vec2 io_texCoord;
out vec3 io_pos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_vertex.xy, 0.0, 1.0);
	io_texCoord = i_vertex.zw;
	io_pos = vec3(u_model * vec4(i_vertex.xy, 0.0, 1.0));
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec2 io_texCoord;
in vec3 io_pos;

out vec4 o_color;

uniform sampler2D u_tex;
uniform vec4 u_color;
uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = u_color * vec4(1.0, 1.0, 1.0, texture(u_tex, io_texCoord).r);
	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}
)ONYXGLSL";

	inline constexpr const char* ui_text = R"ONYXGLSL(
#version 410 core

layout (location = 0) in vec4 i_vertex;

out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_model * vec4(i_vertex.xy, 0.0, 1.0);
	io_texCoord = i_vertex.zw;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;
uniform vec4 u_color;

void main()
{
	o_color = u_color * vec4(1.0, 1.0, 1.0, texture(u_tex, io_texCoord).r);
}

)ONYXGLSL";

}
