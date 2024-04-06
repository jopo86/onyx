#include "Material.h"

#include "File.h"

using Onyx::Math::Vec3, Onyx::Shader, Onyx::Texture;

Onyx::Material::Material()
{
	shininess = 0.0f;
}

Onyx::Material::Material(const Shader& shader, const Onyx::Texture& texture, const Vec3& ambient, const Vec3& diffuse, const Vec3& specular, float shininess)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
	this->shader = shader;
	this->texture = texture;
}

Onyx::Material Onyx::Material::Color(const Vec3& color, float shininess)
{
	return Material(
		Shader(
			File(Onyx::Resources("shaders/V_Color.vert")).readLiteral(),
			File(Onyx::Resources("shaders/V_Color.frag")).readLiteral()
		),
		Onyx::Texture(),
		color * 0.1f,
		color,
		Vec3(1.0f),
		shininess
	);
}
