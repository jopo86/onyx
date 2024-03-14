#include "Math.h"

float Onyx::Math::Radians(float degrees)
{
	return glm::radians(degrees);
}

float Onyx::Math::Degrees(float radians)
{
	return glm::degrees(radians);
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

Onyx::Math::Vec2::Vec2(glm::vec2 vec)
{
	m_vec = vec;
}

float Onyx::Math::Vec2::magnitude()
{
	return glm::length(m_vec);
}

void Onyx::Math::Vec2::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* Onyx::Math::Vec2::data()
{
	return glm::value_ptr(m_vec);
}

float Onyx::Math::Vec2::getX()
{
	return m_vec.x;
}

float Onyx::Math::Vec2::getY()
{
	return m_vec.y;
}

glm::vec2 Onyx::Math::Vec2::getMVec()
{
	return m_vec;
}

Onyx::Math::Vec2 Onyx::Math::Vec2::getNormalized()
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

Onyx::Math::Vec2 Onyx::Math::Vec2::operator+(const Vec2& vec)
{
	return Vec2(m_vec + vec.m_vec);
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator-()
{
	return Vec2(-m_vec);
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator-(const Vec2& vec)
{
	return Vec2(m_vec - vec.m_vec);
}

Onyx::Math::Vec2 Onyx::Math::Vec2::operator*(const float& scalar)
{
	return Vec2(m_vec * scalar);
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

Onyx::Math::Vec3::Vec3(glm::vec3 vec)
{
	m_vec = vec;
}

float Onyx::Math::Vec3::magnitude()
{
	return glm::length(m_vec);
}

void Onyx::Math::Vec3::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* Onyx::Math::Vec3::data()
{
	return glm::value_ptr(m_vec);
}

float Onyx::Math::Vec3::getX()
{
	return m_vec.x;
}

float Onyx::Math::Vec3::getY()
{
	return m_vec.y;
}

float Onyx::Math::Vec3::getZ()
{
	return m_vec.z;
}

glm::vec3 Onyx::Math::Vec3::getMVec()
{
	return m_vec;
}

Onyx::Math::Vec3 Onyx::Math::Vec3::getNormalized()
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

Onyx::Math::Vec3 Onyx::Math::Vec3::operator+(const Vec3& vec)
{
	return Vec3(m_vec + vec.m_vec);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator-()
{
	return Vec3(-m_vec);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator-(const Vec3& vec)
{
	return Vec3(m_vec - vec.m_vec);
}

Onyx::Math::Vec3 Onyx::Math::Vec3::operator*(const float& scalar)
{
	return Vec3(m_vec * scalar);
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

Onyx::Math::Vec4::Vec4(glm::vec4 vec)
{
	m_vec = vec;
}

float Onyx::Math::Vec4::magnitude()
{
	return glm::length(m_vec);
}

void Onyx::Math::Vec4::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* Onyx::Math::Vec4::data()
{
	return glm::value_ptr(m_vec);
}

float Onyx::Math::Vec4::getX()
{
	return m_vec.x;
}

float Onyx::Math::Vec4::getY()
{
	return m_vec.y;
}

float Onyx::Math::Vec4::getZ()
{
	return m_vec.z;
}

float Onyx::Math::Vec4::getW()
{
	return m_vec.w;
}

glm::vec4 Onyx::Math::Vec4::getMVec()
{
	return m_vec;
}

Onyx::Math::Vec4 Onyx::Math::Vec4::getNormalized()
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

Onyx::Math::Vec4 Onyx::Math::Vec4::operator+(const Vec4& vec)
{
	return Vec4(m_vec + vec.m_vec);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator-()
{
	return Vec4(-m_vec);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator-(const Vec4& vec)
{
	return Vec4(m_vec - vec.m_vec);
}

Onyx::Math::Vec4 Onyx::Math::Vec4::operator*(const float& scalar)
{
	return Vec4(m_vec * scalar);
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

glm::mat2x2 Onyx::Math::Mat2x2::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat2x2::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat2x2 Onyx::Math::Mat2x2::operator+(const Mat2x2& mat)
{
	return Mat2x2(m_mat + mat.m_mat);
}

Onyx::Math::Mat2x2 Onyx::Math::Mat2x2::operator-(const Mat2x2& mat)
{
	return Mat2x2(m_mat - mat.m_mat);
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

glm::mat2x3 Onyx::Math::Mat2x3::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat2x3::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat2x3 Onyx::Math::Mat2x3::operator+(const Mat2x3& mat)
{
	return Mat2x3(m_mat + mat.m_mat);
}

Onyx::Math::Mat2x3 Onyx::Math::Mat2x3::operator-(const Mat2x3& mat)
{
	return Mat2x3(m_mat - mat.m_mat);
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

glm::mat2x4 Onyx::Math::Mat2x4::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat2x4::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat2x4 Onyx::Math::Mat2x4::operator+(const Mat2x4& mat)
{
	return Mat2x4(m_mat + mat.m_mat);
}

Onyx::Math::Mat2x4 Onyx::Math::Mat2x4::operator-(const Mat2x4& mat)
{
	return Mat2x4(m_mat - mat.m_mat);
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

glm::mat3x2 Onyx::Math::Mat3x2::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat3x2::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat3x2 Onyx::Math::Mat3x2::operator+(const Mat3x2& mat)
{
	return Mat3x2(m_mat + mat.m_mat);
}

Onyx::Math::Mat3x2 Onyx::Math::Mat3x2::operator-(const Mat3x2& mat)
{
	return Mat3x2(m_mat - mat.m_mat);
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

glm::mat3x3 Onyx::Math::Mat3x3::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat3x3::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat3x3 Onyx::Math::Mat3x3::operator+(const Mat3x3& mat)
{
	return Mat3x3(m_mat + mat.m_mat);
}

Onyx::Math::Mat3x3 Onyx::Math::Mat3x3::operator-(const Mat3x3& mat)
{
	return Mat3x3(m_mat - mat.m_mat);
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

glm::mat3x4 Onyx::Math::Mat3x4::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat3x4::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat3x4 Onyx::Math::Mat3x4::operator+(const Mat3x4& mat)
{
	return Mat3x4(m_mat + mat.m_mat);
}

Onyx::Math::Mat3x4 Onyx::Math::Mat3x4::operator-(const Mat3x4& mat)
{
	return Mat3x4(m_mat - mat.m_mat);
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

glm::mat4x2 Onyx::Math::Mat4x2::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat4x2::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat4x2 Onyx::Math::Mat4x2::operator+(const Mat4x2& mat)
{
	return Mat4x2(m_mat + mat.m_mat);
}

Onyx::Math::Mat4x2 Onyx::Math::Mat4x2::operator-(const Mat4x2& mat)
{
	return Mat4x2(m_mat - mat.m_mat);
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

glm::mat4x3 Onyx::Math::Mat4x3::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat4x3::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat4x3 Onyx::Math::Mat4x3::operator+(const Mat4x3& mat)
{
	return Mat4x3(m_mat + mat.m_mat);
}

Onyx::Math::Mat4x3 Onyx::Math::Mat4x3::operator-(const Mat4x3& mat)
{
	return Mat4x3(m_mat - mat.m_mat);
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

void Onyx::Math::Mat4x4::translate(Vec3 xyz)
{
	m_mat = glm::translate(m_mat, xyz.getMVec());
}

void Onyx::Math::Mat4x4::rotate(float degrees, Vec3 xyzMultiplier)
{
	m_mat = glm::rotate(m_mat, Radians(degrees), xyzMultiplier.getMVec());
	
}

void Onyx::Math::Mat4x4::scale(Vec3 xyzMultiplier)
{
	m_mat = glm::scale(m_mat, xyzMultiplier.getMVec());
}

glm::mat4x4 Onyx::Math::Mat4x4::getMMat()
{
	return m_mat;
}

float* Onyx::Math::Mat4x4::data()
{
	return glm::value_ptr(m_mat);
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::operator+(const Mat4x4& mat)
{
	return Mat4x4(m_mat + mat.m_mat);
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::operator-(const Mat4x4& mat)
{
	return Mat4x4(m_mat - mat.m_mat);
}

Onyx::Math::Mat4x4 Onyx::Math::Mat4x4::Identity()
{
	return Mat4x4(1.0f);
}

Onyx::Math::Mat2x2 Onyx::Math::operator*(Mat2x2& mat1, Mat2x2& mat2)
{
	return Mat2x2(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat2x2 Onyx::Math::operator*(Mat2x3& mat1, Mat3x2& mat2)
{
	return Mat2x2(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat2x2 Onyx::Math::operator*(Mat2x4& mat1, Mat4x2& mat2)
{
	return Mat2x2(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat3x3 Onyx::Math::operator*(Mat3x2& mat1, Mat2x3& mat2)
{
	return Mat3x3(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat3x3 Onyx::Math::operator*(Mat3x3& mat1, Mat3x3& mat2)
{
	return Mat3x3(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat3x3 Onyx::Math::operator*(Mat3x4& mat1, Mat4x3& mat2)
{
	return Mat3x3(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat4x4 Onyx::Math::operator*(Mat4x2& mat1, Mat2x4& mat2)
{
	return Mat4x4(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat4x4 Onyx::Math::operator*(Mat4x3& mat1, Mat3x4& mat2)
{
	return Mat4x4(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Mat4x4 Onyx::Math::operator*(Mat4x4& mat1, Mat4x4& mat2)
{
	return Mat4x4(mat1.getMMat() * mat2.getMMat());
}

Onyx::Math::Vec2 Onyx::Math::operator*(Mat2x2& mat, Vec2& vec)
{
	return Vec2(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec2 Onyx::Math::operator*(Mat2x3& mat, Vec3& vec)
{
	return Vec2(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec2 Onyx::Math::operator*(Mat2x4& mat, Vec4& vec)
{
	return Vec2(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec3 Onyx::Math::operator*(Mat3x3& mat, Vec3& vec)
{
	return Vec3(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec3 Onyx::Math::operator*(Mat3x4& mat, Vec4& vec)
{
	return Vec3(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Vec4 Onyx::Math::operator*(Mat4x4& mat, Vec4& vec)
{
	return Vec4(mat.getMMat() * vec.getMVec());
}

Onyx::Math::Mat4x4 Onyx::Math::LookAt(Vec3 pos, Vec3 target, Vec3 up)
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
