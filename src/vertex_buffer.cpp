#pragma warning(disable: 4267; disable: 4305)

#include "vertex_buffer.h"
#include "math_wrappers.h"

using onyx::math::Vec2;

void onyx_add_malloc(void*, bool);

onyx::VertexBuffer::VertexBuffer()
{
	this->vertices = nullptr;
	this->size = 0;
	this->format = onyx::VertexFormat::Null;
	this->heap = false;
}

onyx::VertexBuffer::VertexBuffer(float *vertices, u32 size, VertexFormat format)
{
	this->vertices = vertices;
	this->size = size;
	this->format = format;
	this->heap = false;
}

onyx::VertexFormat onyx::VertexBuffer::get_format() const
{
	return this->format;
}

bool onyx::VertexBuffer::has_normals(onyx::VertexFormat format)
{
	return format == VertexFormat::PN || format == VertexFormat::PNT || format == VertexFormat::PNC || format == VertexFormat::PNCT;
}

bool onyx::VertexBuffer::has_texture_coords(onyx::VertexFormat format)
{
	return format == VertexFormat::PT || format == VertexFormat::PCT || format == VertexFormat::PNT || format == VertexFormat::PNCT;
}

bool onyx::VertexBuffer::has_colors(onyx::VertexFormat format)
{
	return format == VertexFormat::PC || format == VertexFormat::PCT || format == VertexFormat::PNC || format == VertexFormat::PNCT;
}

onyx::VertexBuffer onyx::VertexBuffer::triangle(float side, bool gen_normals, bool gen_tex_coords)
{
	return triangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)), gen_normals, gen_tex_coords);
}

onyx::VertexBuffer onyx::VertexBuffer::triangle(float base, float height, bool gen_normals, bool gen_tex_coords)
{
	if (gen_normals && gen_tex_coords)
	{
		float* vertices = new float[48]{
			-base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,		0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,		1.0f, 0.0f,
			 0.0f,         height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,		0.5f, 1.0f,

			-base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
			 0.0f,         height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,		0.5f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 48 * sizeof(float), VertexFormat::PNT);
		vb.heap = true;
		return vb;
	}
	else if (gen_normals)
	{
		float* vertices = new float[36]{
			-base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 0.0f,         height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,

			-base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 0.0f,         height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 36 * sizeof(float), VertexFormat::PN);
		vb.heap = true;
		return vb;
	}
	else if (gen_tex_coords)
	{
		float* vertices = new float[15]{
			-base / 2.0f, -height / 2.0f,  0.0f,	0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f,  0.0f,	1.0f, 0.0f,
			 0.0f,         height / 2.0f,  0.0f,	0.5f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 15 * sizeof(float), VertexFormat::PT);
		vb.heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[9]{
			-base / 2.0f, -height / 2.0f,  0.0f,
			 base / 2.0f, -height / 2.0f,  0.0f,
			 0.0f,         height / 2.0f,  0.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 9 * sizeof(float), VertexFormat::P);
		vb.heap = true;
		return vb;
	}
}

onyx::VertexBuffer onyx::VertexBuffer::square(float side, bool gen_normals, bool gen_tex_coords)
{
	return quad(side, side, gen_normals, gen_tex_coords);
}

onyx::VertexBuffer onyx::VertexBuffer::quad(float width, float height, bool gen_normals, bool gen_tex_coords)
{
	if (gen_normals && gen_tex_coords)
	{ 
		float* vertices = new float[64]{
			-width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	0.0f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 64 * sizeof(float), VertexFormat::PNT);
		vb.heap = true;
		return vb;
	}
	else if (gen_normals)
	{
		float* vertices = new float[48]{
			-width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			-width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,

			-width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			-width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 48 * sizeof(float), VertexFormat::PN);
		vb.heap = true;
		return vb;
	}
	else if (gen_tex_coords)
	{
		float* vertices = new float[20]{
			-width / 2.0f, -height / 2.0f,  0.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  0.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  0.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  0.0f,	0.0f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 20 * sizeof(float), VertexFormat::PT);
		vb.heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[12]{
			-width / 2.0f, -height / 2.0f,  0.0f,
			 width / 2.0f, -height / 2.0f,  0.0f,
			 width / 2.0f,  height / 2.0f,  0.0f,
			-width / 2.0f,  height / 2.0f,  0.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 12 * sizeof(float), VertexFormat::P);
		vb.heap = true;
		return vb;
	}
}

onyx::VertexBuffer onyx::VertexBuffer::circle(float r, int n_segments, bool gen_normals, bool gen_tex_coords)
{
	return circle(r, 360.0f / n_segments, gen_normals, gen_tex_coords);
}

onyx::VertexBuffer onyx::VertexBuffer::circle(float r, float angle_step_deg, bool gen_normals, bool gen_tex_coords)
{
	float angle_step = math::radians(angle_step_deg);

	if (gen_normals)
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(s * r);
			vertices->push_back(0.001f)	;
			vertices->push_back(0.0f);
			vertices->push_back(0.0f);
			vertices->push_back(1.0f);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(s * r);
			vertices->push_back(-0.001f)	;
			vertices->push_back(0.0f);
			vertices->push_back(0.0f);
			vertices->push_back(-1.0f);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), gen_tex_coords ? VertexFormat::PNT : VertexFormat::PN);
	}
	else
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(s * r);
			vertices->push_back(0.0f);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), gen_tex_coords ? VertexFormat::PT : VertexFormat::P);
	}
}

onyx::VertexBuffer onyx::VertexBuffer::cube(float side, bool gen_normals, bool gen_tex_coords)
{
	return rect_prism(side, side, side, gen_normals, gen_tex_coords);
}

onyx::VertexBuffer onyx::VertexBuffer::rect_prism(float width, float height, float depth, bool gen_normals, bool gen_tex_coords)
{
	if (gen_normals && gen_tex_coords)
	{ 
		float* vertices = new float[192]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,		1.0f, 1.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,		0.0f, 1.0f,

			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,		0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,		0.0f, 1.0f,

			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f,		0.0f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 192 * sizeof(float), VertexFormat::PNT);
		vb.heap = true;
		return vb;
	}
	else if (gen_normals)
	{
		float* vertices = new float[144]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,

			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,

			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 144 * sizeof(float), VertexFormat::PN);
		vb.heap = true;
		return vb;
	}
	else if (gen_tex_coords)
	{
		float* vertices = new float[120]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 1.0f,

			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 1.0f,
		};

		VertexBuffer vb = VertexBuffer(vertices, 120 * sizeof(float), VertexFormat::PT);
		vb.heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[24]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 24 * sizeof(float), VertexFormat::P);
		vb.heap = true;
		return vb;
	}
}

onyx::VertexBuffer onyx::VertexBuffer::cylinder(float r, float height, int n_segments, bool gen_normals, bool gen_tex_coords)
{
	return cylinder(r, height, 360.0f / n_segments, gen_normals, gen_tex_coords);
}

onyx::VertexBuffer onyx::VertexBuffer::cylinder(float r, float height, float angle_step_deg, bool gen_normals, bool gen_tex_coords)
{
	float angle_step = math::radians(angle_step_deg);

	if (gen_normals)
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(0.0f);
			vertices->push_back(1.0f);
			vertices->push_back(0.0f);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(-height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(0.0f);
			vertices->push_back(-1.0f);
			vertices->push_back(0.0f);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(c);
			vertices->push_back(0.0f);
			vertices->push_back(s);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(ang, Vec2(0.0f, math::TAU), Vec2(0.0f, 1.0f)));
				vertices->push_back(1.0f);
			}
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(-height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(c);
			vertices->push_back(0.0f);
			vertices->push_back(s);
			if (gen_tex_coords)
			{
				vertices->push_back(math::remap(ang, Vec2(0.0f, math::TAU), Vec2(0.0f, 1.0f)));
				vertices->push_back(0.0f);
			}
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), gen_tex_coords ? VertexFormat::PNT : VertexFormat::PN);
	}
	else if (gen_tex_coords)
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(-height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(math::remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			vertices->push_back(math::remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(math::remap(ang, Vec2(0.0f, math::TAU), Vec2(0.0f, 1.0f)));
			vertices->push_back(1.0f);
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(-height / 2.0f);
			vertices->push_back(s * r);
			vertices->push_back(math::remap(ang, Vec2(0.0f, math::TAU), Vec2(0.0f, 1.0f)));
			vertices->push_back(0.0f);
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), VertexFormat::PT);
	}
	else
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(height / 2.0f);
			vertices->push_back(s * r);
		}

		for (float ang = 0.0f; ang < math::TAU; ang += angle_step)
		{
			float c = cosf(ang), s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(-height / 2.0f);
			vertices->push_back(s * r);
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), VertexFormat::P);
	}
}
