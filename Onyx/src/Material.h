#pragma once

#include "Math.h"
#include "Shader.h"
#include "Texture.h"

namespace Onyx
{
	class Material
	{
	public:
		Material();
		Material(const Shader& shader, const Onyx::Texture& texture, const Math::Vec3& ambient, const Math::Vec3& diffuse, const Math::Vec3& specular, float shininess);

		static Material Color(const Math::Vec3& color, float shininess = 32.0f);
		static Material Texture(const Onyx::Texture& texture, const Math::Vec3& ambient = Math::Vec3(0.1f), const Math::Vec3& diffuse = Math::Vec3(1.0f), const Math::Vec3& specular = Math::Vec3(0.5f), float shininess = 32.0f);

		void use() const;

		Math::Vec3 getAmbient() const;
		Math::Vec3 getDiffuse() const;
		Math::Vec3 getSpecular() const;
		float getShininess() const;
		Shader getShader() const;
		Onyx::Texture getTexture() const;

		void setAmbient(const Math::Vec3& ambient);
		void setDiffuse(const Math::Vec3& diffuse);
		void setSpecular(const Math::Vec3& specular);
		void setShininess(float shininess);
		void setShader(const Shader& shader);
		void setTexture(const Onyx::Texture& texture);

	private:
		Math::Vec3 ambient;
		Math::Vec3 diffuse;
		Math::Vec3 specular;
		float shininess;

		Shader shader;
		Onyx::Texture texture;
		
	};
}