#include "Math.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

float Onyx::Math::Radians(float degrees)
{
	return glm::radians<float>(degrees);
}

double Onyx::Math::Radians(double degrees)
{
	return glm::radians<double>(degrees);
}

float Onyx::Math::Degrees(float radians)
{
	return glm::degrees<float>(radians);
}

double Onyx::Math::Degrees(double radians)
{
	return glm::degrees<double>(radians);
}

Onyx::Math::Vec2::Vec2()
{
	m_vec = glm::vec2(0.0f, 0.0f);
}

Onyx::Math::Vec2::Vec2(float xy)
{
	m_vec = glm::vec2(xy, xy);
}

Onyx::Math::Vec2::Vec2(float x, float y)
{
	m_vec = glm::vec2(x, y);
}

Onyx::Math::Vec2::Vec2(DVec2 vec)
{
	m_vec = glm::vec2(vec.getMVec());
}

Onyx::Math::Vec2::Vec2(IVec2 vec)
{
	m_vec = glm::vec2(vec.getMVec());
}

Onyx::Math::Vec2::Vec2(UVec2 vec)
{
    m_vec = glm::vec2(vec.getMVec());
}

Onyx::Math::Vec2::Vec2(glm::vec2 vec)
{
	m_vec = vec;
}

float Onyx::Math::Vec2::magnitude() const
{
	return glm::length(m_vec);
}

void Onyx::Math::Vec2::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* Onyx::Math::Vec2::data() const
{
	return (float*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::Vec2::isZero() const
{
	return getX() == 0.0f && getY() == 0.0f;
}

std::string Onyx::Math::Vec2::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

float Onyx::Math::Vec2::getX() const
{
	return m_vec.x;
}

float Onyx::Math::Vec2::getY() const
{
	return m_vec.y;
}

glm::vec2 Onyx::Math::Vec2::getMVec() const
{
	return m_vec;
}

Onyx::Math::Vec2 Onyx::Math::Vec2::getNormalized() const
{
	return Vec2(glm::normalize(m_vec));
}

void Onyx::Math::Vec2::setX(float x)
{
	m_vec.x = x;
}

void Onyx::Math::Vec2::setY(float y)
{
	m_vec.y = y;
}

void Onyx::Math::Vec2::set(float x, float y)
{
	m_vec.x = x;
	m_vec.y = y;
}

void Onyx::Math::Vec2::setMagnitude(float magnitude)
{
	normalize();
	m_vec *= magnitude;
}

float Onyx::Math::Vec2::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::Vec2::operator=(const Vec2& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator+(const Vec2& vec) const
{
	return Vec2(m_vec + vec.m_vec);
}

void Onyx::Math::Vec2::operator+=(const Vec2& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator-() const
{
	return Vec2(-m_vec);
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator-(const Vec2& vec) const
{
	return Vec2(m_vec - vec.m_vec);
}

void Onyx::Math::Vec2::operator-=(const Vec2& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator*(const float& scalar) const
{
	return Vec2(m_vec * scalar);
}

void Onyx::Math::Vec2::operator*=(const float& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::Vec3::Vec3()
{
	m_vec = glm::vec3(0.0f, 0.0f, 0.0f);
}

Onyx::Math::Vec3::Vec3(float xyz)
{
	m_vec = glm::vec3(xyz, xyz, xyz);
}

Onyx::Math::Vec3::Vec3(float x, float y, float z)
{
	m_vec = glm::vec3(x, y, z);
}

Onyx::Math::Vec3::Vec3(Vec2 vec, float z)
{
	m_vec = glm::vec3(vec.getMVec(), z);
}

Onyx::Math::Vec3::Vec3(float x, Vec2 vec)
{
	m_vec = glm::vec3(x, vec.getMVec());
}

Onyx::Math::Vec3::Vec3(DVec3 vec)
{
    m_vec = glm::vec3(vec.getMVec());
}

Onyx::Math::Vec3::Vec3(IVec3 vec)
{
    m_vec = glm::vec3(vec.getMVec());
}

Onyx::Math::Vec3::Vec3(UVec3 vec)
{
    m_vec = glm::vec3(vec.getMVec());
}

Onyx::Math::Vec3::Vec3(glm::vec3 vec)
{
	m_vec = vec;
}

float Onyx::Math::Vec3::magnitude() const
{
	return glm::length(m_vec);
}

void Onyx::Math::Vec3::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* Onyx::Math::Vec3::data() const
{
	return (float*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::Vec3::isZero() const
{
	return getX() == 0.0f && getY() == 0.0f && getZ() == 0.0f;
}

std::string Onyx::Math::Vec3::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ")";
}

float Onyx::Math::Vec3::getX() const
{
	return m_vec.x;
}

float Onyx::Math::Vec3::getY() const
{
	return m_vec.y;
}

float Onyx::Math::Vec3::getZ() const
{
	return m_vec.z;
}

glm::vec3 Onyx::Math::Vec3::getMVec() const
{
	return m_vec;
}

Onyx::Math::Vec3 Onyx::Math::Vec3::getNormalized() const
{
	return Vec3(glm::normalize(m_vec));
}

void Onyx::Math::Vec3::setX(float x)
{
	m_vec.x = x;
}

void Onyx::Math::Vec3::setY(float y)
{
	m_vec.y = y;
}

void Onyx::Math::Vec3::setZ(float z)
{
	m_vec.z = z;
}

void Onyx::Math::Vec3::set(float x, float y, float z)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
}

void Onyx::Math::Vec3::setMagnitude(float magnitude)
{
	normalize();
	m_vec *= magnitude;
}

float Onyx::Math::Vec3::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::Vec3::operator=(const Vec3& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator+(const Vec3& vec) const
{
	return Vec3(m_vec + vec.m_vec);
}

void Onyx::Math::Vec3::operator+=(const Vec3& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator-() const
{
	return Vec3(-m_vec);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator-(const Vec3& vec) const
{
	return Vec3(m_vec - vec.m_vec);
}

void Onyx::Math::Vec3::operator-=(const Vec3& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator*(const float& scalar) const
{
	return Vec3(m_vec * scalar);
}

void Onyx::Math::Vec3::operator*=(const float& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Red()
{
	return Vec3(1.0f, 0.0f, 0.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Orange()
{
	return Vec3(1.0f, 0.5f, 0.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Yellow()
{
	return Vec3(1.0f, 1.0f, 0.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Green()
{
	return Vec3(0.0f, 1.0f, 0.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::DarkGreen()
{
	return Vec3(0.0f, 0.5f, 0.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Cyan()
{
	return Vec3(0.0f, 1.0f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::LightBlue()
{
	return Vec3(0.0f, 0.7f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Blue()
{
	return Vec3(0.0f, 0.0f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::NavyBlue()
{
	return Vec3(0.0f, 0.25f, 0.5f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Purple()
{
	return Vec3(0.4f, 0.0f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Pink()
{
	return Vec3(1.0f, 0.6f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Magenta()
{
	return Vec3(0.9f, 0.0f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::White()
{
	return Vec3(1.0f, 1.0f, 1.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::LightGray()
{
	return Vec3(0.8f, 0.8f, 0.8f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::DarkGray()
{
	return Vec3(0.4f, 0.4f, 0.4f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Black()
{
	return Vec3(0.0f, 0.0f, 0.0f);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::Brown()
{
	return Vec3(0.3f, 0.2f, 0.0f);
}

Onyx::Math::Vec4::Vec4()
{
	m_vec = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

Onyx::Math::Vec4::Vec4(float xyzw)
{
	m_vec = glm::vec4(xyzw, xyzw, xyzw, xyzw);
}

Onyx::Math::Vec4::Vec4(float x, float y, float z, float w)
{
	m_vec = glm::vec4(x, y, z, w);
}

Onyx::Math::Vec4::Vec4(Vec2 vec, float z, float w)
{
	m_vec = glm::vec4(vec.getMVec(), z, w);
}

Onyx::Math::Vec4::Vec4(float x, Vec2 vec, float w)
{
	m_vec = glm::vec4(x, vec.getMVec(), w);
}

Onyx::Math::Vec4::Vec4(float x, float y, Vec2 vec)
{
	m_vec = glm::vec4(x, y, vec.getMVec());
}

Onyx::Math::Vec4::Vec4(Vec3 vec, float w)
{
	m_vec = glm::vec4(vec.getMVec(), w);
}

Onyx::Math::Vec4::Vec4(float x, Vec3 vec)
{
	m_vec = glm::vec4(x, vec.getMVec());
}

Onyx::Math::Vec4::Vec4(Vec2 vec1, Vec2 vec2)
{
	m_vec = glm::vec4(vec1.getMVec(), vec2.getMVec());
}

Onyx::Math::Vec4::Vec4(DVec4 vec)
{
    m_vec = glm::vec4(vec.getMVec());
}

Onyx::Math::Vec4::Vec4(IVec4 vec)
{
    m_vec = glm::vec4(vec.getMVec());
}

Onyx::Math::Vec4::Vec4(UVec4 vec)
{
    m_vec = glm::vec4(vec.getMVec());
}

Onyx::Math::Vec4::Vec4(glm::vec4 vec)
{
	m_vec = vec;
}

float Onyx::Math::Vec4::magnitude() const
{
	return glm::length(m_vec);
}

void Onyx::Math::Vec4::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* Onyx::Math::Vec4::data() const
{
	return (float*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::Vec4::isZero() const
{
	return getX() == 0.0f && getY() == 0.0f && getZ() == 0.0f && getW() == 0.0f;
}

std::string Onyx::Math::Vec4::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ", " + std::to_string(getW()) + ")";
}

float Onyx::Math::Vec4::getX() const
{
	return m_vec.x;
}

float Onyx::Math::Vec4::getY() const
{
	return m_vec.y;
}

float Onyx::Math::Vec4::getZ() const
{
	return m_vec.z;
}

float Onyx::Math::Vec4::getW() const
{
	return m_vec.w;
}

glm::vec4 Onyx::Math::Vec4::getMVec() const
{
	return m_vec;
}

Onyx::Math::Vec4 Onyx::Math::Vec4::getNormalized() const
{
	return Vec4(glm::normalize(m_vec));
}

void Onyx::Math::Vec4::setX(float x)
{
	m_vec.x = x;
}

void Onyx::Math::Vec4::setY(float y)
{
	m_vec.y = y;
}

void Onyx::Math::Vec4::setZ(float z)
{
	m_vec.z = z;
}

void Onyx::Math::Vec4::setW(float w)
{
	m_vec.w = w;
}

void Onyx::Math::Vec4::set(float x, float y, float z, float w)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
	m_vec.w = w;
}

void Onyx::Math::Vec4::setMagnitude(float magnitude)
{
	normalize();
	m_vec *= magnitude;
}

float Onyx::Math::Vec4::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::Vec4::operator=(const Vec4& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
	m_vec.w = vec.getW();
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator+(const Vec4& vec) const
{
	return Vec4(m_vec + vec.m_vec);
}

void Onyx::Math::Vec4::operator+=(const Vec4& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator-() const
{
	return Vec4(-m_vec);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator-(const Vec4& vec) const
{
	return Vec4(m_vec - vec.m_vec);
}

void Onyx::Math::Vec4::operator-=(const Vec4& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator*(const float& scalar) const
{
	return Vec4(m_vec * scalar);
}

void Onyx::Math::Vec4::operator*=(const float& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Red(float alpha)
{
	return Vec4(Vec3::Red(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Orange(float alpha)
{
	return Vec4(Vec3::Orange(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Yellow(float alpha)
{
	return Vec4(Vec3::Yellow(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Green(float alpha)
{
	return Vec4(Vec3::Green(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::DarkGreen(float alpha)
{
	return Vec4(Vec3::DarkGreen(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Cyan(float alpha)
{
	return Vec4(Vec3::Cyan(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::LightBlue(float alpha)
{
	return Vec4(Vec3::LightBlue(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Blue(float alpha)
{
	return Vec4(Vec3::Blue(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::NavyBlue(float alpha)
{
	return Vec4(Vec3::NavyBlue(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Purple(float alpha)
{
	return Vec4(Vec3::Purple(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Pink(float alpha)
{
	return Vec4(Vec3::Pink(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Magenta(float alpha)
{
	return Vec4(Vec3::Magenta(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::White(float alpha)
{
	return Vec4(Vec3::White(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::LightGray(float alpha)
{
	return Vec4(Vec3::LightGray(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::DarkGray(float alpha)
{
	return Vec4(Vec3::DarkGray(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Black(float alpha)
{
	return Vec4(Vec3::Black(), alpha);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::Brown(float alpha)
{
	return Vec4(Vec3::Brown(), alpha);
}

Onyx::Math::Vec2 Onyx::Math::Rotate(const Vec2& vec, float angle)
{
	if (vec.isZero() || angle == 0.0f) return vec;

	Vec2 rotated = vec;

	float rad = Radians(angle);
	float s = sinf(rad);
	float c = cosf(rad);
	float x = rotated.getX();
	float y = rotated.getY();
	rotated.setX(x * c - y * s);
	rotated.setY(x * s + y * c);

	return rotated;
}

Onyx::Math::Vec3 Onyx::Math::Rotate(const Vec3& vec, float angle, const Vec3& mask)
{
	if (vec.isZero() || angle == 0.0f) return vec;

	Vec3 rotated = vec;

	float rad = Radians(angle);
	float s = sinf(rad);
	float c = cosf(rad);

	if (mask.getX() != 0.0f)
	{
		float y = rotated.getY();
		float z = rotated.getZ();
		rotated.setY(y * c - z * s);
		rotated.setZ(y * s + z * c);
	}

	if (mask.getY() != 0.0f)
	{
		float x = rotated.getX();
		float z = rotated.getZ();
		rotated.setX(x * c + z * s);
		rotated.setZ(-x * s + z * c);
	}

	if (mask.getZ() != 0.0f)
	{
		float x = rotated.getX();
		float y = rotated.getY();
		rotated.setX(x * c - y * s);
		rotated.setY(x * s + y * c);
	}

	return rotated;
}

Onyx::Math::Vec3 Onyx::Math::Rotate(const Vec3& vec, const Vec3& angles)
{
	if (vec.isZero() || angles.isZero()) return vec;

	Vec3 rotated = vec;

	float radX = Radians(angles.getX());
	float radY = Radians(angles.getY());
	float radZ = Radians(angles.getZ());

	if (radX != 0.0f)
	{
		float s = sinf(radX);
		float c = cosf(radX);
		float y = rotated.getY();
		float z = rotated.getZ();
		rotated.setY(y * c - z * s);
		rotated.setZ(y * s + z * c);
	}

	if (radY != 0.0f)
	{
		float s = sinf(radY);
		float c = cosf(radY);
		float x = rotated.getX();
		float z = rotated.getZ();
		rotated.setX(x * c + z * s);
		rotated.setZ(-x * s + z * c);
	}

	if (radZ != 0.0f)
	{
		float s = sinf(radZ);
		float c = cosf(radZ);
		float x = rotated.getX();
		float y = rotated.getY();
		rotated.setX(x * c - y * s);
		rotated.setY(x * s + y * c);
	}

	return rotated;
}

Onyx::Math::DVec2::DVec2()
{
	m_vec = glm::dvec2(0.0, 0.0);
}

Onyx::Math::DVec2::DVec2(double xy)
{
	m_vec = glm::dvec2(xy, xy);
}

Onyx::Math::DVec2::DVec2(double x, double y)
{
	m_vec = glm::dvec2(x, y);
}

Onyx::Math::DVec2::DVec2(Vec2 vec)
{
    m_vec = glm::dvec2(vec.getMVec());
}

Onyx::Math::DVec2::DVec2(IVec2 vec)
{
    m_vec = glm::dvec2(vec.getMVec());
}

Onyx::Math::DVec2::DVec2(UVec2 vec)
{
    m_vec = glm::dvec2(vec.getMVec());
}

Onyx::Math::DVec2::DVec2(glm::dvec2 vec)
{
	m_vec = vec;
}

double Onyx::Math::DVec2::magnitude() const
{
	return glm::length(m_vec);
}

void Onyx::Math::DVec2::normalize()
{
	m_vec = glm::normalize(m_vec);
}

double* Onyx::Math::DVec2::data() const
{
	return (double*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::DVec2::isZero() const
{
	return getX() == 0.0 && getY() == 0.0;
}

std::string Onyx::Math::DVec2::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

double Onyx::Math::DVec2::getX() const
{
	return m_vec.x;
}

double Onyx::Math::DVec2::getY() const
{
	return m_vec.y;
}

glm::dvec2 Onyx::Math::DVec2::getMVec() const
{
	return m_vec;
}

Onyx::Math::DVec2 Onyx::Math::DVec2::getNormalized() const
{
	return DVec2(glm::normalize(m_vec));
}

void Onyx::Math::DVec2::setX(double x)
{
	m_vec.x = x;
}

void Onyx::Math::DVec2::setY(double y)
{
	m_vec.y = y;
}

void Onyx::Math::DVec2::set(double x, double y)
{
	m_vec.x = x;
	m_vec.y = y;
}

void Onyx::Math::DVec2::setMagnitude(double magnitude)
{
	normalize();
	m_vec *= magnitude;
}

double Onyx::Math::DVec2::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::DVec2::operator=(const DVec2& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
}

Onyx::Math::DVec2 Onyx::Math::DVec2::operator+(const DVec2& vec) const
{
	return DVec2(m_vec + vec.m_vec);
}

void Onyx::Math::DVec2::operator+=(const DVec2& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::DVec2 Onyx::Math::DVec2::operator-() const
{
	return DVec2(-m_vec);
}

Onyx::Math::DVec2 Onyx::Math::DVec2::operator-(const DVec2& vec) const
{
	return DVec2(m_vec - vec.m_vec);
}

void Onyx::Math::DVec2::operator-=(const DVec2& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::DVec2 Onyx::Math::DVec2::operator*(const double& scalar) const
{
	return DVec2(m_vec * scalar);
}

void Onyx::Math::DVec2::operator*=(const double& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::DVec3::DVec3()
{
	m_vec = glm::dvec3(0.0, 0.0, 0.0);
}

Onyx::Math::DVec3::DVec3(double xyz)
{
	m_vec = glm::dvec3(xyz, xyz, xyz);
}

Onyx::Math::DVec3::DVec3(double x, double y, double z)
{
	m_vec = glm::dvec3(x, y, z);
}

Onyx::Math::DVec3::DVec3(DVec2 vec, double z)
{
	m_vec = glm::dvec3(vec.getMVec(), z);
}

Onyx::Math::DVec3::DVec3(double x, DVec2 vec)
{
	m_vec = glm::dvec3(x, vec.getMVec());
}

Onyx::Math::DVec3::DVec3(Vec3 vec)
{
    m_vec = glm::dvec3(vec.getMVec());
}

Onyx::Math::DVec3::DVec3(IVec3 vec)
{
    m_vec = glm::dvec3(vec.getMVec());
}

Onyx::Math::DVec3::DVec3(UVec3 vec)
{
    m_vec = glm::dvec3(vec.getMVec());
}

Onyx::Math::DVec3::DVec3(glm::dvec3 vec)
{
	m_vec = vec;
}

double Onyx::Math::DVec3::magnitude() const
{
	return glm::length(m_vec);
}

void Onyx::Math::DVec3::normalize()
{
	m_vec = glm::normalize(m_vec);
}

double* Onyx::Math::DVec3::data() const
{
	return (double*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::DVec3::isZero() const
{
	return getX() == 0.0 && getY() == 0.0 && getZ() == 0.0;
}

std::string Onyx::Math::DVec3::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ")";
}

double Onyx::Math::DVec3::getX() const
{
	return m_vec.x;
}

double Onyx::Math::DVec3::getY() const
{
	return m_vec.y;
}

double Onyx::Math::DVec3::getZ() const
{
	return m_vec.z;
}

glm::dvec3 Onyx::Math::DVec3::getMVec() const
{
	return m_vec;
}

Onyx::Math::DVec3 Onyx::Math::DVec3::getNormalized() const
{
	return DVec3(glm::normalize(m_vec));
}

void Onyx::Math::DVec3::setX(double x)
{
	m_vec.x = x;
}

void Onyx::Math::DVec3::setY(double y)
{
	m_vec.y = y;
}

void Onyx::Math::DVec3::setZ(double z)
{
	m_vec.z = z;
}

void Onyx::Math::DVec3::set(double x, double y, double z)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
}

void Onyx::Math::DVec3::setMagnitude(double magnitude)
{
	normalize();
	m_vec *= magnitude;
}

double Onyx::Math::DVec3::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::DVec3::operator=(const DVec3& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
}

Onyx::Math::DVec3 Onyx::Math::DVec3::operator+(const DVec3& vec) const
{
	return DVec3(m_vec + vec.m_vec);
}

void Onyx::Math::DVec3::operator+=(const DVec3& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::DVec3 Onyx::Math::DVec3::operator-() const
{
	return DVec3(-m_vec);
}

Onyx::Math::DVec3 Onyx::Math::DVec3::operator-(const DVec3& vec) const
{
	return DVec3(m_vec - vec.m_vec);
}

void Onyx::Math::DVec3::operator-=(const DVec3& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::DVec3 Onyx::Math::DVec3::operator*(const double& scalar) const
{
	return DVec3(m_vec * scalar);
}

void Onyx::Math::DVec3::operator*=(const double& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::DVec4::DVec4()
{
	m_vec = glm::dvec4(0.0, 0.0, 0.0, 0.0);
}

Onyx::Math::DVec4::DVec4(double xyzw)
{
	m_vec = glm::dvec4(xyzw, xyzw, xyzw, xyzw);
}

Onyx::Math::DVec4::DVec4(double x, double y, double z, double w)
{
	m_vec = glm::dvec4(x, y, z, w);
}

Onyx::Math::DVec4::DVec4(DVec2 vec, double z, double w)
{
	m_vec = glm::dvec4(vec.getMVec(), z, w);
}

Onyx::Math::DVec4::DVec4(double x, DVec2 vec, double w)
{
	m_vec = glm::dvec4(x, vec.getMVec(), w);
}

Onyx::Math::DVec4::DVec4(double x, double y, DVec2 vec)
{
	m_vec = glm::dvec4(x, y, vec.getMVec());
}

Onyx::Math::DVec4::DVec4(DVec3 vec, double w)
{
	m_vec = glm::dvec4(vec.getMVec(), w);
}

Onyx::Math::DVec4::DVec4(double x, DVec3 vec)
{
	m_vec = glm::dvec4(x, vec.getMVec());
}

Onyx::Math::DVec4::DVec4(DVec2 vec1, DVec2 vec2)
{
	m_vec = glm::dvec4(vec1.getMVec(), vec2.getMVec());
}

Onyx::Math::DVec4::DVec4(Vec4 vec)
{
    m_vec = glm::dvec4(vec.getMVec());
}

Onyx::Math::DVec4::DVec4(IVec4 vec)
{
    m_vec = glm::dvec4(vec.getMVec());
}

Onyx::Math::DVec4::DVec4(UVec4 vec)
{
    m_vec = glm::dvec4(vec.getMVec());
}

Onyx::Math::DVec4::DVec4(glm::dvec4 vec)
{
	m_vec = vec;
}

double Onyx::Math::DVec4::magnitude() const
{
	return glm::length(m_vec);
}

void Onyx::Math::DVec4::normalize()
{
	m_vec = glm::normalize(m_vec);
}

double* Onyx::Math::DVec4::data() const
{
	return (double*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::DVec4::isZero() const
{
	return getX() == 0.0 && getY() == 0.0 && getZ() == 0.0 && getW() == 0.0;
}

std::string Onyx::Math::DVec4::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ", " + std::to_string(getW()) + ")";
}

double Onyx::Math::DVec4::getX() const
{
	return m_vec.x;
}

double Onyx::Math::DVec4::getY() const
{
	return m_vec.y;
}

double Onyx::Math::DVec4::getZ() const
{
	return m_vec.z;
}

double Onyx::Math::DVec4::getW() const
{
	return m_vec.w;
}

glm::dvec4 Onyx::Math::DVec4::getMVec() const
{
	return m_vec;
}

Onyx::Math::DVec4 Onyx::Math::DVec4::getNormalized() const
{
	return DVec4(glm::normalize(m_vec));
}

void Onyx::Math::DVec4::setX(double x)
{
	m_vec.x = x;
}

void Onyx::Math::DVec4::setY(double y)
{
	m_vec.y = y;
}

void Onyx::Math::DVec4::setZ(double z)
{
	m_vec.z = z;
}

void Onyx::Math::DVec4::setW(double w)
{
	m_vec.w = w;
}

void Onyx::Math::DVec4::set(double x, double y, double z, double w)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
	m_vec.w = w;
}

void Onyx::Math::DVec4::setMagnitude(double magnitude)
{
	normalize();
	m_vec *= magnitude;
}

double Onyx::Math::DVec4::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::DVec4::operator=(const DVec4& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
	m_vec.w = vec.getW();
}

Onyx::Math::DVec4 Onyx::Math::DVec4::operator+(const DVec4& vec) const
{
	return DVec4(m_vec + vec.m_vec);
}

void Onyx::Math::DVec4::operator+=(const DVec4& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::DVec4 Onyx::Math::DVec4::operator-() const
{
	return DVec4(-m_vec);
}

Onyx::Math::DVec4 Onyx::Math::DVec4::operator-(const DVec4& vec) const
{
	return DVec4(m_vec - vec.m_vec);
}

void Onyx::Math::DVec4::operator-=(const DVec4& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::DVec4 Onyx::Math::DVec4::operator*(const double& scalar) const
{
	return DVec4(m_vec * scalar);
}

void Onyx::Math::DVec4::operator*=(const double& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::DVec2 Onyx::Math::Rotate(const DVec2& vec, double angle)
{
	if (vec.isZero() || angle == 0.0f) return vec;

	DVec2 rotated = vec;

	double rad = Radians(angle);
	double s = sin(rad);
	double c = cos(rad);
	double x = rotated.getX();
	double y = rotated.getY();
	rotated.setX(x * c - y * s);
	rotated.setY(x * s + y * c);

	return rotated;
}

Onyx::Math::DVec3 Onyx::Math::Rotate(const DVec3& vec, double angle, const DVec3& mask)
{
	if (vec.isZero() || angle == 0.0f) return vec;

	DVec3 rotated = vec;

	double rad = Radians(angle);
	double s = sin(rad);
	double c = cos(rad);

	if (mask.getX() != 0.0f)
	{
		double y = rotated.getY();
		double z = rotated.getZ();
		rotated.setY(y * c - z * s);
		rotated.setZ(y * s + z * c);
	}

	if (mask.getY() != 0.0f)
	{
		double x = rotated.getX();
		double z = rotated.getZ();
		rotated.setX(x * c + z * s);
		rotated.setZ(-x * s + z * c);
	}

	if (mask.getZ() != 0.0f)
	{
		double x = rotated.getX();
		double y = rotated.getY();
		rotated.setX(x * c - y * s);
		rotated.setY(x * s + y * c);
	}

	return rotated;
}

Onyx::Math::DVec3 Onyx::Math::Rotate(const DVec3& vec, const DVec3& angles)
{
	if (vec.isZero() || angles.isZero()) return vec;

	DVec3 rotated = vec;

	double radX = Radians(angles.getX());
	double radY = Radians(angles.getY());
	double radZ = Radians(angles.getZ());

	if (radX != 0.0f)
	{
		double s = sin(radX);
		double c = cos(radX);
		double y = rotated.getY();
		double z = rotated.getZ();
		rotated.setY(y * c - z * s);
		rotated.setZ(y * s + z * c);
	}

	if (radY != 0.0f)
	{
		double s = sin(radY);
		double c = cos(radY);
		double x = rotated.getX();
		double z = rotated.getZ();
		rotated.setX(x * c + z * s);
		rotated.setZ(-x * s + z * c);
	}

	if (radZ != 0.0f)
	{
		double s = sin(radZ);
		double c = cos(radZ);
		double x = rotated.getX();
		double y = rotated.getY();
		rotated.setX(x * c - y * s);
		rotated.setY(x * s + y * c);
	}

	return rotated;
}

Onyx::Math::IVec2::IVec2()
{
	m_vec = glm::ivec2(0, 0);
}

Onyx::Math::IVec2::IVec2(int xy)
{
	m_vec = glm::ivec2(xy, xy);
}

Onyx::Math::IVec2::IVec2(int x, int y)
{
	m_vec = glm::ivec2(x, y);
}

Onyx::Math::IVec2::IVec2(Vec2 vec)
{
	m_vec = glm::ivec2(vec.getMVec());
}

Onyx::Math::IVec2::IVec2(DVec2 vec)
{
    m_vec = glm::ivec2(vec.getMVec());
}

Onyx::Math::IVec2::IVec2(UVec2 vec)
{
    m_vec = glm::ivec2(vec.getMVec());
}

Onyx::Math::IVec2::IVec2(glm::ivec2 vec)
{
	m_vec = vec;
}

int* Onyx::Math::IVec2::data() const
{
	return (int*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::IVec2::isZero() const
{
	return getX() == 0 && getY() == 0;
}

std::string Onyx::Math::IVec2::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

int Onyx::Math::IVec2::getX() const
{
	return m_vec.x;
}

int Onyx::Math::IVec2::getY() const
{
	return m_vec.y;
}

glm::ivec2 Onyx::Math::IVec2::getMVec() const
{
	return m_vec;
}

void Onyx::Math::IVec2::setX(int x)
{
	m_vec.x = x;
}

void Onyx::Math::IVec2::setY(int y)
{
	m_vec.y = y;
}

void Onyx::Math::IVec2::set(int x, int y)
{
	m_vec.x = x;
	m_vec.y = y;
}

int Onyx::Math::IVec2::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::IVec2::operator=(const IVec2& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
}

Onyx::Math::IVec2 Onyx::Math::IVec2::operator+(const IVec2& vec) const
{
	return IVec2(m_vec + vec.m_vec);
}

void Onyx::Math::IVec2::operator+=(const IVec2& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::IVec2 Onyx::Math::IVec2::operator-() const
{
	return IVec2(-m_vec);
}

Onyx::Math::IVec2 Onyx::Math::IVec2::operator-(const IVec2& vec) const
{
	return IVec2(m_vec - vec.m_vec);
}

void Onyx::Math::IVec2::operator-=(const IVec2& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::IVec2 Onyx::Math::IVec2::operator*(const int& scalar) const
{
	return IVec2(m_vec * scalar);
}

void Onyx::Math::IVec2::operator*=(const int& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::IVec3::IVec3()
{
	m_vec = glm::ivec3(0, 0, 0);
}

Onyx::Math::IVec3::IVec3(int xyz)
{
	m_vec = glm::ivec3(xyz, xyz, xyz);
}

Onyx::Math::IVec3::IVec3(int x, int y, int z)
{
	m_vec = glm::ivec3(x, y, z);
}

Onyx::Math::IVec3::IVec3(IVec2 vec, int z)
{
	m_vec = glm::ivec3(vec.getMVec(), z);
}

Onyx::Math::IVec3::IVec3(int x, IVec2 vec)
{
	m_vec = glm::ivec3(x, vec.getMVec());
}

Onyx::Math::IVec3::IVec3(Vec3 vec)
{
    m_vec = glm::ivec3(vec.getMVec());
}

Onyx::Math::IVec3::IVec3(DVec3 vec)
{
    m_vec = glm::ivec3(vec.getMVec());
}

Onyx::Math::IVec3::IVec3(UVec3 vec)
{
    m_vec = glm::ivec3(vec.getMVec());
}

Onyx::Math::IVec3::IVec3(glm::ivec3 vec)
{
	m_vec = vec;
}

int* Onyx::Math::IVec3::data() const
{
	return (int*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::IVec3::isZero() const
{
	return getX() == 0 && getY() == 0 && getZ() == 0;
}

std::string Onyx::Math::IVec3::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ")";
}

int Onyx::Math::IVec3::getX() const
{
	return m_vec.x;
}

int Onyx::Math::IVec3::getY() const
{
	return m_vec.y;
}

int Onyx::Math::IVec3::getZ() const
{
	return m_vec.z;
}

glm::ivec3 Onyx::Math::IVec3::getMVec() const
{
	return m_vec;
}

void Onyx::Math::IVec3::setX(int x)
{
	m_vec.x = x;
}

void Onyx::Math::IVec3::setY(int y)
{
	m_vec.y = y;
}

void Onyx::Math::IVec3::setZ(int z)
{
	m_vec.z = z;
}

void Onyx::Math::IVec3::set(int x, int y, int z)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
}

int Onyx::Math::IVec3::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::IVec3::operator=(const IVec3& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
}

Onyx::Math::IVec3 Onyx::Math::IVec3::operator+(const IVec3& vec) const
{
	return IVec3(m_vec + vec.m_vec);
}

void Onyx::Math::IVec3::operator+=(const IVec3& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::IVec3 Onyx::Math::IVec3::operator-() const
{
	return IVec3(-m_vec);
}

Onyx::Math::IVec3 Onyx::Math::IVec3::operator-(const IVec3& vec) const
{
	return IVec3(m_vec - vec.m_vec);
}

void Onyx::Math::IVec3::operator-=(const IVec3& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::IVec3 Onyx::Math::IVec3::operator*(const int& scalar) const
{
	return IVec3(m_vec * scalar);
}

void Onyx::Math::IVec3::operator*=(const int& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::IVec4::IVec4()
{
	m_vec = glm::ivec4(0, 0, 0, 0);
}

Onyx::Math::IVec4::IVec4(int xyzw)
{
	m_vec = glm::ivec4(xyzw, xyzw, xyzw, xyzw);
}

Onyx::Math::IVec4::IVec4(int x, int y, int z, int w)
{
	m_vec = glm::ivec4(x, y, z, w);
}

Onyx::Math::IVec4::IVec4(IVec2 vec, int z, int w)
{
	m_vec = glm::ivec4(vec.getMVec(), z, w);
}

Onyx::Math::IVec4::IVec4(int x, IVec2 vec, int w)
{
	m_vec = glm::ivec4(x, vec.getMVec(), w);
}

Onyx::Math::IVec4::IVec4(int x, int y, IVec2 vec)
{
	m_vec = glm::ivec4(x, y, vec.getMVec());
}

Onyx::Math::IVec4::IVec4(IVec3 vec, int w)
{
	m_vec = glm::ivec4(vec.getMVec(), w);
}

Onyx::Math::IVec4::IVec4(int x, IVec3 vec)
{
	m_vec = glm::ivec4(x, vec.getMVec());
}

Onyx::Math::IVec4::IVec4(IVec2 vec1, IVec2 vec2)
{
	m_vec = glm::ivec4(vec1.getMVec(), vec2.getMVec());
}

Onyx::Math::IVec4::IVec4(Vec4 vec)
{
    m_vec = glm::ivec4(vec.getMVec());
}

Onyx::Math::IVec4::IVec4(DVec4 vec)
{
    m_vec = glm::ivec4(vec.getMVec());
}

Onyx::Math::IVec4::IVec4(UVec4 vec)
{
    m_vec = glm::ivec4(vec.getMVec());
}

Onyx::Math::IVec4::IVec4(glm::ivec4 vec)
{
	m_vec = vec;
}

int* Onyx::Math::IVec4::data() const
{
	return (int*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::IVec4::isZero() const
{
	return getX() == 0 && getY() == 0 && getZ() == 0 && getW() == 0;
}

std::string Onyx::Math::IVec4::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ", " + std::to_string(getW()) + ")";
}

int Onyx::Math::IVec4::getX() const
{
	return m_vec.x;
}

int Onyx::Math::IVec4::getY() const
{
	return m_vec.y;
}

int Onyx::Math::IVec4::getZ() const
{
	return m_vec.z;
}

int Onyx::Math::IVec4::getW() const
{
	return m_vec.w;
}

glm::ivec4 Onyx::Math::IVec4::getMVec() const
{
	return m_vec;
}

void Onyx::Math::IVec4::setX(int x)
{
	m_vec.x = x;
}

void Onyx::Math::IVec4::setY(int y)
{
	m_vec.y = y;
}

void Onyx::Math::IVec4::setZ(int z)
{
	m_vec.z = z;
}

void Onyx::Math::IVec4::setW(int w)
{
	m_vec.w = w;
}

void Onyx::Math::IVec4::set(int x, int y, int z, int w)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
	m_vec.w = w;
}

int Onyx::Math::IVec4::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::IVec4::operator=(const IVec4& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
	m_vec.w = vec.getW();
}

Onyx::Math::IVec4 Onyx::Math::IVec4::operator+(const IVec4& vec) const
{
	return IVec4(m_vec + vec.m_vec);
}

void Onyx::Math::IVec4::operator+=(const IVec4& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::IVec4 Onyx::Math::IVec4::operator-() const
{
	return IVec4(-m_vec);
}

Onyx::Math::IVec4 Onyx::Math::IVec4::operator-(const IVec4& vec) const
{
	return IVec4(m_vec - vec.m_vec);
}

void Onyx::Math::IVec4::operator-=(const IVec4& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::IVec4 Onyx::Math::IVec4::operator*(const int& scalar) const
{
	return IVec4(m_vec * scalar);
}

void Onyx::Math::IVec4::operator*=(const int& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::UVec2::UVec2()
{
	m_vec = glm::uvec2(0, 0);
}

Onyx::Math::UVec2::UVec2(uint xy)
{
	m_vec = glm::uvec2(xy, xy);
}

Onyx::Math::UVec2::UVec2(uint x, uint y)
{
	m_vec = glm::uvec2(x, y);
}

Onyx::Math::UVec2::UVec2(glm::uvec2 vec)
{
	m_vec = vec;
}

uint* Onyx::Math::UVec2::data() const
{
	return (uint*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::UVec2::isZero() const
{
	return getX() == 0 && getY() == 0;
}

std::string Onyx::Math::UVec2::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

uint Onyx::Math::UVec2::getX() const
{
	return m_vec.x;
}

uint Onyx::Math::UVec2::getY() const
{
	return m_vec.y;
}

glm::uvec2 Onyx::Math::UVec2::getMVec() const
{
	return m_vec;
}

void Onyx::Math::UVec2::setX(uint x)
{
	m_vec.x = x;
}

void Onyx::Math::UVec2::setY(uint y)
{
	m_vec.y = y;
}

void Onyx::Math::UVec2::set(uint x, uint y)
{
	m_vec.x = x;
	m_vec.y = y;
}

uint Onyx::Math::UVec2::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::UVec2::operator=(const UVec2& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
}

Onyx::Math::UVec2 Onyx::Math::UVec2::operator+(const UVec2& vec) const
{
	return UVec2(m_vec + vec.m_vec);
}

void Onyx::Math::UVec2::operator+=(const UVec2& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::UVec2 Onyx::Math::UVec2::operator-(const UVec2& vec) const
{
	return UVec2(m_vec - vec.m_vec);
}

void Onyx::Math::UVec2::operator-=(const UVec2& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::UVec2 Onyx::Math::UVec2::operator*(const uint& scalar) const
{
	return UVec2(m_vec * scalar);
}

void Onyx::Math::UVec2::operator*=(const uint& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::UVec3::UVec3()
{
	m_vec = glm::uvec3(0, 0, 0);
}

Onyx::Math::UVec3::UVec3(uint xyz)
{
	m_vec = glm::uvec3(xyz, xyz, xyz);
}

Onyx::Math::UVec3::UVec3(uint x, uint y, uint z)
{
	m_vec = glm::uvec3(x, y, z);
}

Onyx::Math::UVec3::UVec3(UVec2 vec, uint z)
{
	m_vec = glm::uvec3(vec.getMVec(), z);
}

Onyx::Math::UVec3::UVec3(uint x, UVec2 vec)
{
	m_vec = glm::uvec3(x, vec.getMVec());
}

Onyx::Math::UVec3::UVec3(glm::uvec3 vec)
{
	m_vec = vec;
}

uint* Onyx::Math::UVec3::data() const
{
	return (uint*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::UVec3::isZero() const
{
	return getX() == 0 && getY() == 0 && getZ() == 0;
}

std::string Onyx::Math::UVec3::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ")";
}

uint Onyx::Math::UVec3::getX() const
{
	return m_vec.x;
}

uint Onyx::Math::UVec3::getY() const
{
	return m_vec.y;
}

uint Onyx::Math::UVec3::getZ() const
{
	return m_vec.z;
}

glm::uvec3 Onyx::Math::UVec3::getMVec() const
{
	return m_vec;
}

void Onyx::Math::UVec3::setX(uint x)
{
	m_vec.x = x;
}

void Onyx::Math::UVec3::setY(uint y)
{
	m_vec.y = y;
}

void Onyx::Math::UVec3::setZ(uint z)
{
	m_vec.z = z;
}

void Onyx::Math::UVec3::set(uint x, uint y, uint z)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
}

uint Onyx::Math::UVec3::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::UVec3::operator=(const UVec3& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
}

Onyx::Math::UVec3 Onyx::Math::UVec3::operator+(const UVec3& vec) const
{
	return UVec3(m_vec + vec.m_vec);
}

void Onyx::Math::UVec3::operator+=(const UVec3& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::UVec3 Onyx::Math::UVec3::operator-(const UVec3& vec) const
{
	return UVec3(m_vec - vec.m_vec);
}

void Onyx::Math::UVec3::operator-=(const UVec3& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::UVec3 Onyx::Math::UVec3::operator*(const uint& scalar) const
{
	return UVec3(m_vec * scalar);
}

void Onyx::Math::UVec3::operator*=(const uint& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::UVec4::UVec4()
{
	m_vec = glm::uvec4(0, 0, 0, 0);
}

Onyx::Math::UVec4::UVec4(uint xyzw)
{
	m_vec = glm::uvec4(xyzw, xyzw, xyzw, xyzw);
}

Onyx::Math::UVec4::UVec4(uint x, uint y, uint z, uint w)
{
	m_vec = glm::uvec4(x, y, z, w);
}

Onyx::Math::UVec4::UVec4(UVec2 vec, uint z, uint w)
{
	m_vec = glm::uvec4(vec.getMVec(), z, w);
}

Onyx::Math::UVec4::UVec4(uint x, UVec2 vec, uint w)
{
	m_vec = glm::uvec4(x, vec.getMVec(), w);
}

Onyx::Math::UVec4::UVec4(uint x, uint y, UVec2 vec)
{
	m_vec = glm::uvec4(x, y, vec.getMVec());
}

Onyx::Math::UVec4::UVec4(UVec3 vec, uint w)
{
	m_vec = glm::uvec4(vec.getMVec(), w);
}

Onyx::Math::UVec4::UVec4(uint x, UVec3 vec)
{
	m_vec = glm::uvec4(x, vec.getMVec());
}

Onyx::Math::UVec4::UVec4(UVec2 vec1, UVec2 vec2)
{
	m_vec = glm::uvec4(vec1.getMVec(), vec2.getMVec());
}

Onyx::Math::UVec4::UVec4(glm::uvec4 vec)
{
	m_vec = vec;
}

uint* Onyx::Math::UVec4::data() const
{
	return (uint*)(glm::value_ptr(m_vec));
}

bool Onyx::Math::UVec4::isZero() const
{
	return getX() == 0 && getY() == 0 && getZ() == 0 && getW() == 0;
}

std::string Onyx::Math::UVec4::toString() const
{
	return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ", " + std::to_string(getZ()) + ", " + std::to_string(getW()) + ")";
}

uint Onyx::Math::UVec4::getX() const
{
	return m_vec.x;
}

uint Onyx::Math::UVec4::getY() const
{
	return m_vec.y;
}

uint Onyx::Math::UVec4::getZ() const
{
	return m_vec.z;
}

uint Onyx::Math::UVec4::getW() const
{
	return m_vec.w;
}

glm::uvec4 Onyx::Math::UVec4::getMVec() const
{
	return m_vec;
}

void Onyx::Math::UVec4::setX(uint x)
{
	m_vec.x = x;
}

void Onyx::Math::UVec4::setY(uint y)
{
	m_vec.y = y;
}

void Onyx::Math::UVec4::setZ(uint z)
{
	m_vec.z = z;
}

void Onyx::Math::UVec4::setW(uint w)
{
	m_vec.w = w;
}

void Onyx::Math::UVec4::set(uint x, uint y, uint z, uint w)
{
	m_vec.x = x;
	m_vec.y = y;
	m_vec.z = z;
	m_vec.w = w;
}

uint Onyx::Math::UVec4::operator[](int index) const
{
	return m_vec[index];
}

void Onyx::Math::UVec4::operator=(const UVec4& vec)
{
	m_vec.x = vec.getX();
	m_vec.y = vec.getY();
	m_vec.z = vec.getZ();
	m_vec.w = vec.getW();
}

Onyx::Math::UVec4 Onyx::Math::UVec4::operator+(const UVec4& vec) const
{
	return UVec4(m_vec + vec.m_vec);
}

void Onyx::Math::UVec4::operator+=(const UVec4& vec)
{
	m_vec += vec.m_vec;
}

Onyx::Math::UVec4 Onyx::Math::UVec4::operator-(const UVec4& vec) const
{
	return UVec4(m_vec - vec.m_vec);
}

void Onyx::Math::UVec4::operator-=(const UVec4& vec)
{
	m_vec -= vec.m_vec;
}

Onyx::Math::UVec4 Onyx::Math::UVec4::operator*(const uint& scalar) const
{
	return UVec4(m_vec * scalar);
}

void Onyx::Math::UVec4::operator*=(const uint& scalar)
{
	m_vec *= scalar;
}

Onyx::Math::Vec3 Onyx::Math::Cross(const Vec3& vec1, const Vec3& vec2)
{
	return Vec3(glm::cross(vec1.m_vec, vec2.m_vec));
}

float Onyx::Math::Dot(const Vec2& vec1, const Vec2& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

float Onyx::Math::Dot(const Vec3& vec1, const Vec3& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

float Onyx::Math::Dot(const Vec4& vec1, const Vec4& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

Onyx::Math::DVec3 Onyx::Math::Cross(const DVec3& vec1, const DVec3& vec2)
{
	return DVec3(glm::cross(vec1.m_vec, vec2.m_vec));
}

double Onyx::Math::Dot(const DVec2& vec1, const DVec2& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

double Onyx::Math::Dot(const DVec3& vec1, const DVec3& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

double Onyx::Math::Dot(const DVec4& vec1, const DVec4& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

bool Onyx::Math::operator==(const Vec2& vec1, const Vec2& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const Vec2& vec1, const Vec2& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const Vec3& vec1, const Vec3& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const Vec3& vec1, const Vec3& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const Vec4& vec1, const Vec4& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const Vec4& vec1, const Vec4& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const DVec2& vec1, const DVec2& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const DVec2& vec1, const DVec2& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const DVec3& vec1, const DVec3& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const DVec3& vec1, const DVec3& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const DVec4& vec1, const DVec4& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const DVec4& vec1, const DVec4& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const IVec2& vec1, const IVec2& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const IVec2& vec1, const IVec2& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const IVec3& vec1, const IVec3& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const IVec3& vec1, const IVec3& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const IVec4& vec1, const IVec4& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const IVec4& vec1, const IVec4& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const UVec2& vec1, const UVec2& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const UVec2& vec1, const UVec2& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const UVec3& vec1, const UVec3& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const UVec3& vec1, const UVec3& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

bool Onyx::Math::operator==(const UVec4& vec1, const UVec4& vec2)
{
	return vec1.m_vec == vec2.m_vec;
}

bool Onyx::Math::operator!=(const UVec4& vec1, const UVec4& vec2)
{
	return vec1.m_vec != vec2.m_vec;
}

Onyx::Math::Mat2x2::Mat2x2()
{
	m_mat = glm::mat2x2(0.0f);
}

Onyx::Math::Mat2x2::Mat2x2(float scalar)
{
	m_mat = glm::mat2x2(scalar);
}

Onyx::Math::Mat2x2::Mat2x2(glm::mat2x2 mat)
{
	m_mat = mat;
}

glm::mat2x2 Onyx::Math::Mat2x2::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat2x2::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat2x2::toString() const
{
	std::string str;
	for (int i = 0; i < 2; i++)
	{
		str += "|";
		for (int j = 0; j < 2; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec2 Onyx::Math::Mat2x2::operator[](int index) const
{
	return Vec2(m_mat[index]);
}

void Onyx::Math::Mat2x2::operator=(const Mat2x2& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat2x2 Onyx::Math::Mat2x2::operator+(const Mat2x2& mat) const
{
	return Mat2x2(m_mat + mat.m_mat);
}

void Onyx::Math::Mat2x2::operator+=(const Mat2x2& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat2x2 Onyx::Math::Mat2x2::operator-() const
{
	return Mat2x2(-m_mat);
}

Onyx::Math::Mat2x2 Onyx::Math::Mat2x2::operator-(const Mat2x2& mat) const
{
	return Mat2x2(m_mat - mat.m_mat);
}

void Onyx::Math::Mat2x2::operator-=(const Mat2x2& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat2x2 Onyx::Math::Mat2x2::Identity()
{
	return Mat2x2(1.0f);
}

Onyx::Math::Mat2x3::Mat2x3()
{
	m_mat = glm::mat2x3(0.0f);
}

Onyx::Math::Mat2x3::Mat2x3(float scalar)
{
	m_mat = glm::mat2x3(scalar);
}

Onyx::Math::Mat2x3::Mat2x3(glm::mat2x3 mat)
{
	m_mat = mat;
}

glm::mat2x3 Onyx::Math::Mat2x3::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat2x3::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat2x3::toString() const
{
	std::string str;
	for (int i = 0; i < 2; i++)
	{
		str += "|";
		for (int j = 0; j < 3; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec3 Onyx::Math::Mat2x3::operator[](int index) const
{
	return Vec3(m_mat[index]);
}

void Onyx::Math::Mat2x3::operator=(const Mat2x3& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat2x3 Onyx::Math::Mat2x3::operator+(const Mat2x3& mat) const
{
	return Mat2x3(m_mat + mat.m_mat);
}

void Onyx::Math::Mat2x3::operator+=(const Mat2x3& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat2x3 Onyx::Math::Mat2x3::operator-() const
{
	return Mat2x3(-m_mat);
}

Onyx::Math::Mat2x3 Onyx::Math::Mat2x3::operator-(const Mat2x3& mat) const
{
	return Mat2x3(m_mat - mat.m_mat);
}

void Onyx::Math::Mat2x3::operator-=(const Mat2x3& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat2x3 Onyx::Math::Mat2x3::Identity()
{
	return Mat2x3(1.0f);
}

Onyx::Math::Mat2x4::Mat2x4()
{
	m_mat = glm::mat2x4(0.0f);
}

Onyx::Math::Mat2x4::Mat2x4(float scalar)
{
	m_mat = glm::mat2x4(scalar);
}

Onyx::Math::Mat2x4::Mat2x4(glm::mat2x4 mat)
{
	m_mat = mat;
}

glm::mat2x4 Onyx::Math::Mat2x4::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat2x4::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat2x4::toString() const
{
	std::string str;
	for (int i = 0; i < 2; i++)
	{
		str += "|";
		for (int j = 0; j < 4; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec4 Onyx::Math::Mat2x4::operator[](int index) const
{
	return Vec4(m_mat[index]);
}

void Onyx::Math::Mat2x4::operator=(const Mat2x4& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat2x4 Onyx::Math::Mat2x4::operator+(const Mat2x4& mat) const
{
	return Mat2x4(m_mat + mat.m_mat);
}

void Onyx::Math::Mat2x4::operator+=(const Mat2x4& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat2x4 Onyx::Math::Mat2x4::operator-() const
{
	return Mat2x4(-m_mat);
}

Onyx::Math::Mat2x4 Onyx::Math::Mat2x4::operator-(const Mat2x4& mat) const
{
	return Mat2x4(m_mat - mat.m_mat);
}

void Onyx::Math::Mat2x4::operator-=(const Mat2x4& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat2x4 Onyx::Math::Mat2x4::Identity()
{
	return Mat2x4(1.0f);
}

Onyx::Math::Mat3x2::Mat3x2()
{
	m_mat = glm::mat3x2(0.0f);
}

Onyx::Math::Mat3x2::Mat3x2(float scalar)
{
	m_mat = glm::mat3x2(scalar);
}

Onyx::Math::Mat3x2::Mat3x2(glm::mat3x2 mat)
{
	m_mat = mat;
}

glm::mat3x2 Onyx::Math::Mat3x2::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat3x2::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat3x2::toString() const
{
	std::string str;
	for (int i = 0; i < 3; i++)
	{
		str += "|";
		for (int j = 0; j < 2; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec2 Onyx::Math::Mat3x2::operator[](int index) const
{
	return Vec2(m_mat[index]);
}

void Onyx::Math::Mat3x2::operator=(const Mat3x2& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat3x2 Onyx::Math::Mat3x2::operator+(const Mat3x2& mat) const
{
	return Mat3x2(m_mat + mat.m_mat);
}

void Onyx::Math::Mat3x2::operator+=(const Mat3x2& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat3x2 Onyx::Math::Mat3x2::operator-() const
{
	return Mat3x2(-m_mat);
}

Onyx::Math::Mat3x2 Onyx::Math::Mat3x2::operator-(const Mat3x2& mat) const
{
	return Mat3x2(m_mat - mat.m_mat);
}

void Onyx::Math::Mat3x2::operator-=(const Mat3x2& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat3x2 Onyx::Math::Mat3x2::Identity()
{
	return Mat3x2(1.0f);
}

Onyx::Math::Mat3x3::Mat3x3()
{
	m_mat = glm::mat3x3(0.0f);
}

Onyx::Math::Mat3x3::Mat3x3(float scalar)
{
	m_mat = glm::mat3x3(scalar);
}

Onyx::Math::Mat3x3::Mat3x3(glm::mat3x3 mat)
{
	m_mat = mat;
}

glm::mat3x3 Onyx::Math::Mat3x3::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat3x3::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat3x3::toString() const
{
	std::string str;
	for (int i = 0; i < 3; i++)
	{
		str += "|";
		for (int j = 0; j < 3; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec3 Onyx::Math::Mat3x3::operator[](int index) const
{
	return Vec3(m_mat[index]);
}

void Onyx::Math::Mat3x3::operator=(const Mat3x3& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat3x3 Onyx::Math::Mat3x3::operator+(const Mat3x3& mat) const
{
	return Mat3x3(m_mat + mat.m_mat);
}

void Onyx::Math::Mat3x3::operator+=(const Mat3x3& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat3x3 Onyx::Math::Mat3x3::operator-() const
{
	return Mat3x3(-m_mat);
}

Onyx::Math::Mat3x3 Onyx::Math::Mat3x3::operator-(const Mat3x3& mat) const
{
	return Mat3x3(m_mat - mat.m_mat);
}

void Onyx::Math::Mat3x3::operator-=(const Mat3x3& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat3x3 Onyx::Math::Mat3x3::Identity()
{
	return Mat3x3(1.0f);
}

Onyx::Math::Mat3x4::Mat3x4()
{
	m_mat = glm::mat3x4(0.0f);
}

Onyx::Math::Mat3x4::Mat3x4(float scalar)
{
	m_mat = glm::mat3x4(scalar);
}

Onyx::Math::Mat3x4::Mat3x4(glm::mat3x4 mat)
{
	m_mat = mat;
}

glm::mat3x4 Onyx::Math::Mat3x4::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat3x4::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat3x4::toString() const
{
	std::string str;
	for (int i = 0; i < 3; i++)
	{
		str += "|";
		for (int j = 0; j < 4; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec4 Onyx::Math::Mat3x4::operator[](int index) const
{
	return Vec4(m_mat[index]);
}

void Onyx::Math::Mat3x4::operator=(const Mat3x4& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat3x4 Onyx::Math::Mat3x4::operator+(const Mat3x4& mat) const
{
	return Mat3x4(m_mat + mat.m_mat);
}

void Onyx::Math::Mat3x4::operator+=(const Mat3x4& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat3x4 Onyx::Math::Mat3x4::operator-() const
{
	return Mat3x4(-m_mat);
}

Onyx::Math::Mat3x4 Onyx::Math::Mat3x4::operator-(const Mat3x4& mat) const
{
	return Mat3x4(m_mat - mat.m_mat);
}

void Onyx::Math::Mat3x4::operator-=(const Mat3x4& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat3x4 Onyx::Math::Mat3x4::Identity()
{
	return Mat3x4(1.0f);
}

Onyx::Math::Mat4x2::Mat4x2()
{
	m_mat = glm::mat4x2(0.0f);
}

Onyx::Math::Mat4x2::Mat4x2(float scalar)
{
	m_mat = glm::mat4x2(scalar);
}

Onyx::Math::Mat4x2::Mat4x2(glm::mat4x2 mat)
{
	m_mat = mat;
}

glm::mat4x2 Onyx::Math::Mat4x2::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat4x2::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat4x2::toString() const
{
	std::string str;
	for (int i = 0; i < 4; i++)
	{
		str += "|";
		for (int j = 0; j < 2; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec2 Onyx::Math::Mat4x2::operator[](int index) const
{
	return Vec2(m_mat[index]);
}

void Onyx::Math::Mat4x2::operator=(const Mat4x2& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat4x2 Onyx::Math::Mat4x2::operator+(const Mat4x2& mat) const
{
	return Mat4x2(m_mat + mat.m_mat);
}

void Onyx::Math::Mat4x2::operator+=(const Mat4x2& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat4x2 Onyx::Math::Mat4x2::operator-() const
{
	return Mat4x2(-m_mat);
}

Onyx::Math::Mat4x2 Onyx::Math::Mat4x2::operator-(const Mat4x2& mat) const
{
	return Mat4x2(m_mat - mat.m_mat);
}

void Onyx::Math::Mat4x2::operator-=(const Mat4x2& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat4x2 Onyx::Math::Mat4x2::Identity()
{
	return Mat4x2(1.0f);
}

Onyx::Math::Mat4x3::Mat4x3()
{
	m_mat = glm::mat4x3(0.0f);
}

Onyx::Math::Mat4x3::Mat4x3(float scalar)
{
	m_mat = glm::mat4x3(scalar);
}

Onyx::Math::Mat4x3::Mat4x3(glm::mat4x3 mat)
{
	m_mat = mat;
}

glm::mat4x3 Onyx::Math::Mat4x3::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat4x3::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat4x3::toString() const
{
	std::string str;
	for (int i = 0; i < 4; i++)
	{
		str += "|";
		for (int j = 0; j < 3; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec3 Onyx::Math::Mat4x3::operator[](int index) const
{
	return Vec3(m_mat[index]);
}

void Onyx::Math::Mat4x3::operator=(const Mat4x3& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat4x3 Onyx::Math::Mat4x3::operator+(const Mat4x3& mat) const
{
	return Mat4x3(m_mat + mat.m_mat);
}

void Onyx::Math::Mat4x3::operator+=(const Mat4x3& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat4x3 Onyx::Math::Mat4x3::operator-() const
{
	return Mat4x3(-m_mat);
}

Onyx::Math::Mat4x3 Onyx::Math::Mat4x3::operator-(const Mat4x3& mat) const
{
	return Mat4x3(m_mat - mat.m_mat);
}

void Onyx::Math::Mat4x3::operator-=(const Mat4x3& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat4x3 Onyx::Math::Mat4x3::Identity()
{
	return Mat4x3(1.0f);
}

Onyx::Math::Mat4x4::Mat4x4()
{
	m_mat = glm::mat4x4(0.0f);
}

Onyx::Math::Mat4x4::Mat4x4(float scalar)
{
	m_mat = glm::mat4x4(scalar);
}

Onyx::Math::Mat4x4::Mat4x4(glm::mat4x4 mat)
{
	m_mat = mat;
}

void Onyx::Math::Mat4x4::translate(const Vec3& xyz)
{
	m_mat = glm::translate(m_mat, xyz.getMVec());
}

void Onyx::Math::Mat4x4::rotate(float degrees, const Vec3& mask)
{
	m_mat = glm::rotate(m_mat, Radians(degrees), mask.getMVec());
}

void Onyx::Math::Mat4x4::scale(const Vec3& xyzMultiplier)
{
	m_mat = glm::scale(m_mat, xyzMultiplier.getMVec());
}

glm::mat4x4 Onyx::Math::Mat4x4::getMMat() const
{
	return m_mat;
}

float* Onyx::Math::Mat4x4::data() const
{
	return (float*)(glm::value_ptr(m_mat));
}

std::string Onyx::Math::Mat4x4::toString() const
{
	std::string str;
	for (int i = 0; i < 4; i++)
	{
		str += "|";
		for (int j = 0; j < 4; j++)
		{
			str += " " + std::to_string(m_mat[i][j]);
		}
		str += " |\n";
	}

	return str;
}

Onyx::Math::Vec4 Onyx::Math::Mat4x4::operator[](int index) const
{
	return Vec4(m_mat[index]);
}

void Onyx::Math::Mat4x4::operator=(const Mat4x4& mat)
{
	m_mat = mat.m_mat;
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::operator+(const Mat4x4& mat) const
{
	return Mat4x4(m_mat + mat.m_mat);
}

void Onyx::Math::Mat4x4::operator+=(const Mat4x4& mat)
{
	m_mat += mat.m_mat;
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::operator-() const
{
	return Mat4x4(-m_mat);
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::operator-(const Mat4x4& mat) const
{
	return Mat4x4(m_mat - mat.m_mat);
}

void Onyx::Math::Mat4x4::operator-=(const Mat4x4& mat)
{
	m_mat -= mat.m_mat;
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::Identity()
{
	return Mat4x4(1.0f);
}

Onyx::Math::Mat2x2 Onyx::Math::operator*(const Mat2x2& mat1, const Mat2x2& mat2)
{
	return Mat2x2(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat2x2 Onyx::Math::operator*(const Mat2x3& mat1, const Mat3x2& mat2)
{
	return Mat2x2(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat2x2 Onyx::Math::operator*(const Mat2x4& mat1, const Mat4x2& mat2)
{
	return Mat2x2(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat3x3 Onyx::Math::operator*(const Mat3x2& mat1, const Mat2x3& mat2)
{
	return Mat3x3(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat3x3 Onyx::Math::operator*(const Mat3x3& mat1, const Mat3x3& mat2)
{
	return Mat3x3(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat3x3 Onyx::Math::operator*(const Mat3x4& mat1, const Mat4x3& mat2)
{
	return Mat3x3(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat4x4 Onyx::Math::operator*(const Mat4x2& mat1, const Mat2x4& mat2)
{
	return Mat4x4(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat4x4 Onyx::Math::operator*(const Mat4x3& mat1, const Mat3x4& mat2)
{
	return Mat4x4(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat4x4 Onyx::Math::operator*(const Mat4x4& mat1, const Mat4x4& mat2)
{
	return Mat4x4(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Vec2 Onyx::Math::operator*(const Mat2x2& mat, const Vec2& vec)
{
	return Vec2(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec2 Onyx::Math::operator*(const Mat2x3& mat, const Vec3& vec)
{
	return Vec2(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec2 Onyx::Math::operator*(const Mat2x4& mat, const Vec4& vec)
{
	return Vec2(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec3 Onyx::Math::operator*(const Mat3x3& mat, const Vec3& vec)
{
	return Vec3(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec3 Onyx::Math::operator*(const Mat3x4& mat, const Vec4& vec)
{
	return Vec3(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec4 Onyx::Math::operator*(const Mat4x4& mat, const Vec4& vec)
{
	return Vec4(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Mat2x2 Onyx::Math::Transpose(const Mat2x2& mat)
{
	return Mat2x2(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat2x3 Onyx::Math::Transpose(const Mat3x2& mat)
{
	return Mat2x3(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat2x4 Onyx::Math::Transpose(const Mat4x2& mat)
{
	return Mat2x4(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat3x2 Onyx::Math::Transpose(const Mat2x3& mat)
{
	return Mat3x2(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat3x3 Onyx::Math::Transpose(const Mat3x3& mat)
{
	return Mat3x3(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat3x4 Onyx::Math::Transpose(const Mat4x3& mat)
{
	return Mat3x4(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat4x2 Onyx::Math::Transpose(const Mat2x4& mat)
{
	return Mat4x2(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat4x3 Onyx::Math::Transpose(const Mat3x4& mat)
{
	return Mat4x3(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat4x4 Onyx::Math::Transpose(const Mat4x4& mat)
{
	return Mat4x4(glm::transpose(mat.getMMat()));
}

Onyx::Math::Mat2x2 Onyx::Math::Inverse(const Mat2x2& mat)
{
	return Mat2x2(glm::inverse(mat.getMMat()));
}

Onyx::Math::Mat3x3 Onyx::Math::Inverse(const Mat3x3& mat)
{
	return Mat3x3(glm::inverse(mat.getMMat()));
}

Onyx::Math::Mat4x4 Onyx::Math::Inverse(const Mat4x4& mat)
{
	return Mat4x4(glm::inverse(mat.getMMat()));
}

Onyx::Math::Mat4x4 Onyx::Math::LookAt(const Vec3& pos, const Vec3& target, const Vec3& up)
{
	return Mat4(glm::lookAt(pos.getMVec(), target.getMVec(), up.getMVec()));
}

Onyx::Math::Mat4x4 Onyx::Math::OrthographicProjection(float left, float right, float top, float bottom)
{
	return Mat4(glm::ortho(left, right, bottom, top));
}

Onyx::Math::Mat4x4 Onyx::Math::PerspectiveProjection(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	return Mat4(glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane));
}
