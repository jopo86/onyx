#include "math.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void onyx_seed_random(u32 seed)
{
	srand(seed);
}

float onyx::math::radians(float degrees)
{
	return glm::radians<float>(degrees);
}

double onyx::math::radians(double degrees)
{
	return glm::radians<double>(degrees);
}

float onyx::math::degrees(float radians)
{
	return glm::degrees<float>(radians);
}

double onyx::math::degrees(double radians)
{
	return glm::degrees<double>(radians);
}

float onyx::math::clamp(float value, float min, float max)
{
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

double onyx::math::clamp(double value, double min, double max)
{
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

float onyx::math::remap(float val, Vec2 old_range, Vec2 new_range)
{
	return ((val - old_range.get_x()) / (old_range.get_y() - old_range.get_x())) * (new_range.get_y() - new_range.get_x()) + new_range.get_x();
}

double onyx::math::remap(double val, DVec2 old_range, DVec2 new_range)
{
	return ((val - old_range.get_x()) / (old_range.get_y() - old_range.get_x())) * (new_range.get_y() - new_range.get_x()) + new_range.get_x();
}

int onyx::math::abs(int value)
{
	return abs(value);
}

float onyx::math::abs(float value)
{
	return abs(value);
}

double onyx::math::abs(double value)
{
	return abs(value);
}

float onyx::math::sqrt(float value)
{
	return sqrt(value);
}

double onyx::math::sqrt(double value)
{
	return sqrt(value);
}

float onyx::math::pow(float base, float exponent)
{
	return pow(base, exponent);
}

double onyx::math::pow(double base, double exponent)
{
	return pow(base, exponent);
}

float onyx::math::sin(float val)
{
	return sinf(val);
}

float onyx::math::cos(float val)
{
	return cosf(val);
}

float onyx::math::tan(float val)
{
	return tanf(val);
}

float onyx::math::asin(float value)
{
	return asinf(value);
}

float onyx::math::acos(float value)
{
	return acosf(value);
}

float onyx::math::atan(float value)
{
	return atanf(value);
}

float onyx::math::atan2(float y, float x)
{
	return atan2f(y, x);
}

double onyx::math::sin(double val)
{
	return sin(val);
}

double onyx::math::cos(double val)
{
	return cos(val);
}

double onyx::math::tan(double val)
{
	return tan(val);
}

double onyx::math::asin(double value)
{
	return asin(value);
}

double onyx::math::acos(double value)
{
	return acos(value);
}

double onyx::math::atan(double value)
{
	return atan(value);
}

double onyx::math::atan2(double y, double x)
{
	return atan2(y, x);
}

float onyx::math::sinh(float val)
{
	return sinhf(val);
}

float onyx::math::cosh(float val)
{
	return coshf(val);
}

float onyx::math::tanh(float val)
{
	return tanhf(val);
}

float onyx::math::asinh(float val)
{
	return asinhf(val);
}

float onyx::math::acosh(float val)
{
	return acoshf(val);
}

float onyx::math::atanh(float val)
{
	return atanhf(val);
}

double onyx::math::sinh(double val)
{
	return sinh(val);
}

double onyx::math::cosh(double val)
{
	return cosh(val);
}

double onyx::math::tanh(double val)
{
	return tanh(val);
}

double onyx::math::asinh(double val)
{
	return asinh(val);
}

double onyx::math::acosh(double val)
{
	return acosh(val);
}

double onyx::math::atanh(double val)
{
	return atanh(val);
}

float onyx::math::floor(float val)
{
	return floorf(val);
}

double onyx::math::floor(double val)
{
	return floor(val);
}

float onyx::math::ceil(float val)
{
	return ceilf(val);
}

double onyx::math::ceil(double val)
{
	return ceil(val);
}

float onyx::math::round(float val)
{
	return roundf(val);
}

double onyx::math::round(double val)
{
	return round(val);
}

float onyx::math::trunc(float val)
{
	return truncf(val);
}

double onyx::math::trunc(double val)
{
	return trunc(val);
}

float onyx::math::fract(float val)
{
	return val - floorf(val);
}

double onyx::math::fract(double val)
{
	return val - floor(val);
}

float onyx::math::mod(float val, float divisor)
{
	return fmodf(val, divisor);
}

double onyx::math::mod(double val, double divisor)
{
	return fmod(val, divisor);
}

int onyx::math::min(int a, int b)
{
	return a < b ? a : b;
}

float onyx::math::min(float a, float b)
{
	return a < b ? a : b;
}

double onyx::math::min(double a, double b)
{
	return a < b ? a : b;
}

int onyx::math::max(int a, int b)
{
	return a > b ? a : b;
}

float onyx::math::max(float a, float b)
{
	return a > b ? a : b;
}

double onyx::math::max(double a, double b)
{
	return a > b ? a : b;
}

float onyx::math::lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

double onyx::math::lerp(double a, double b, double t)
{
	return a + (b - a) * t;
}

onyx::math::Vec2::Vec2()
{
	this->vec = glm::vec2(0.0f, 0.0f);
}

onyx::math::Vec2::Vec2(float xy)
{
	this->vec = glm::vec2(xy, xy);
}

onyx::math::Vec2::Vec2(float x, float y)
{
	this->vec = glm::vec2(x, y);
}

onyx::math::Vec2::Vec2(const DVec2& vec)
{
	this->vec = glm::vec2(vec.get_mvec());
}

onyx::math::Vec2::Vec2(const IVec2& vec)
{
	this->vec = glm::vec2(vec.get_mvec());
}

onyx::math::Vec2::Vec2(const UVec2& vec)
{
	this->vec = glm::vec2(vec.get_mvec());
}

onyx::math::Vec2::Vec2(const glm::vec2& vec)
{
	this->vec = vec;
}

float onyx::math::Vec2::magnitude() const
{
	return glm::length(this->vec);
}

void onyx::math::Vec2::normalize()
{
	this->vec = glm::normalize(this->vec);
}

const float* onyx::math::Vec2::data() const
{
	return (float*)(glm::value_ptr(this->vec));
}

bool onyx::math::Vec2::is_zero() const
{
	return get_x() == 0.0f && get_y() == 0.0f;
}

std::string onyx::math::Vec2::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ")";
}

float onyx::math::Vec2::get_x() const
{
	return this->vec.x;
}

float onyx::math::Vec2::get_y() const
{
	return this->vec.y;
}

const glm::vec2& onyx::math::Vec2::get_mvec() const
{
	return this->vec;
}

onyx::math::Vec2 onyx::math::Vec2::get_normalized() const
{
	return Vec2(glm::normalize(this->vec));
}

void onyx::math::Vec2::set_x(float x)
{
	this->vec.x = x;
}

void onyx::math::Vec2::set_y(float y)
{
	this->vec.y = y;
}

void onyx::math::Vec2::set(float x, float y)
{
	this->vec.x = x;
	this->vec.y = y;
}

void onyx::math::Vec2::set_magnitude(float magnitude)
{
	normalize();
	this->vec *= magnitude;
}

float onyx::math::Vec2::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::Vec2::operator=(const Vec2& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
}

onyx::math::Vec2 onyx::math::Vec2::operator+(const Vec2& vec) const
{
	return Vec2(this->vec + vec.vec);
}

void onyx::math::Vec2::operator+=(const Vec2& vec)
{
	this->vec += vec.vec;
}

onyx::math::Vec2 onyx::math::Vec2::operator-() const
{
	return Vec2(-this->vec);
}

onyx::math::Vec2 onyx::math::Vec2::operator-(const Vec2& vec) const
{
	return Vec2(this->vec - vec.vec);
}

void onyx::math::Vec2::operator-=(const Vec2& vec)
{
	this->vec -= vec.vec;
}

onyx::math::Vec2 onyx::math::Vec2::operator*(const float& scalar) const
{
	return Vec2(this->vec * scalar);
}

void onyx::math::Vec2::operator*=(const float& scalar)
{
	this->vec *= scalar;
}

onyx::math::Vec3::Vec3()
{
	this->vec = glm::vec3(0.0f, 0.0f, 0.0f);
}

onyx::math::Vec3::Vec3(float xyz)
{
	this->vec = glm::vec3(xyz, xyz, xyz);
}

onyx::math::Vec3::Vec3(float x, float y, float z)
{
	this->vec = glm::vec3(x, y, z);
}

onyx::math::Vec3::Vec3(const Vec2& vec, float z)
{
	this->vec = glm::vec3(vec.get_mvec(), z);
}

onyx::math::Vec3::Vec3(float x, const Vec2& vec)
{
	this->vec = glm::vec3(x, vec.get_mvec());
}

onyx::math::Vec3::Vec3(const DVec3& vec)
{
	this->vec = glm::vec3(vec.get_mvec());
}

onyx::math::Vec3::Vec3(const IVec3& vec)
{
	this->vec = glm::vec3(vec.get_mvec());
}

onyx::math::Vec3::Vec3(const UVec3& vec)
{
	this->vec = glm::vec3(vec.get_mvec());
}

onyx::math::Vec3::Vec3(const glm::vec3& vec)
{
	this->vec = vec;
}

float onyx::math::Vec3::magnitude() const
{
	return glm::length(this->vec);
}

void onyx::math::Vec3::normalize()
{
	this->vec = glm::normalize(this->vec);
}

const float* onyx::math::Vec3::data() const
{
	return (float*)(glm::value_ptr(this->vec));
}

bool onyx::math::Vec3::is_zero() const
{
	return get_x() == 0.0f && get_y() == 0.0f && get_z() == 0.0f;
}

std::string onyx::math::Vec3::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ")";
}

float onyx::math::Vec3::get_x() const
{
	return this->vec.x;
}

float onyx::math::Vec3::get_y() const
{
	return this->vec.y;
}

float onyx::math::Vec3::get_z() const
{
	return this->vec.z;
}

const glm::vec3& onyx::math::Vec3::get_mvec() const
{
	return this->vec;
}

onyx::math::Vec3 onyx::math::Vec3::get_normalized() const
{
	return Vec3(glm::normalize(this->vec));
}

void onyx::math::Vec3::set_x(float x)
{
	this->vec.x = x;
}

void onyx::math::Vec3::set_y(float y)
{
	this->vec.y = y;
}

void onyx::math::Vec3::set_z(float z)
{
	this->vec.z = z;
}

void onyx::math::Vec3::set(float x, float y, float z)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
}

void onyx::math::Vec3::set_magnitude(float magnitude)
{
	normalize();
	this->vec *= magnitude;
}

float onyx::math::Vec3::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::Vec3::operator=(const Vec3& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
}

onyx::math::Vec3 onyx::math::Vec3::operator+(const Vec3& vec) const
{
	return Vec3(this->vec + vec.vec);
}

void onyx::math::Vec3::operator+=(const Vec3& vec)
{
	this->vec += vec.vec;
}

onyx::math::Vec3 onyx::math::Vec3::operator-() const
{
	return Vec3(-this->vec);
}

onyx::math::Vec3 onyx::math::Vec3::operator-(const Vec3& vec) const
{
	return Vec3(this->vec - vec.vec);
}

void onyx::math::Vec3::operator-=(const Vec3& vec)
{
	this->vec -= vec.vec;
}

onyx::math::Vec3 onyx::math::Vec3::operator*(const float& scalar) const
{
	return Vec3(this->vec * scalar);
}

void onyx::math::Vec3::operator*=(const float& scalar)
{
	this->vec *= scalar;
}

onyx::math::Vec3 onyx::math::Vec3::red()
{
	return Vec3(1.0f, 0.0f, 0.0f);
}

onyx::math::Vec3 onyx::math::Vec3::orange()
{
	return Vec3(1.0f, 0.5f, 0.0f);
}

onyx::math::Vec3 onyx::math::Vec3::yellow()
{
	return Vec3(1.0f, 1.0f, 0.0f);
}

onyx::math::Vec3 onyx::math::Vec3::green()
{
	return Vec3(0.0f, 1.0f, 0.0f);
}

onyx::math::Vec3 onyx::math::Vec3::dark_green()
{
	return Vec3(0.0f, 0.5f, 0.0f);
}

onyx::math::Vec3 onyx::math::Vec3::cyan()
{
	return Vec3(0.0f, 1.0f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::light_blue()
{
	return Vec3(0.0f, 0.7f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::blue()
{
	return Vec3(0.0f, 0.0f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::navy_blue()
{
	return Vec3(0.0f, 0.25f, 0.5f);
}

onyx::math::Vec3 onyx::math::Vec3::purple()
{
	return Vec3(0.4f, 0.0f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::pink()
{
	return Vec3(1.0f, 0.6f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::magenta()
{
	return Vec3(0.9f, 0.0f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::white()
{
	return Vec3(1.0f, 1.0f, 1.0f);
}

onyx::math::Vec3 onyx::math::Vec3::light_gray()
{
	return Vec3(0.8f, 0.8f, 0.8f);
}

onyx::math::Vec3 onyx::math::Vec3::dark_gray()
{
	return Vec3(0.4f, 0.4f, 0.4f);
}

onyx::math::Vec3 onyx::math::Vec3::black()
{
	return Vec3(0.0f, 0.0f, 0.0f);
}

onyx::math::Vec3 onyx::math::Vec3::brown()
{
	return Vec3(0.3f, 0.2f, 0.0f);
}

onyx::math::Vec4::Vec4()
{
	this->vec = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

onyx::math::Vec4::Vec4(float xyzw)
{
	this->vec = glm::vec4(xyzw, xyzw, xyzw, xyzw);
}

onyx::math::Vec4::Vec4(float x, float y, float z, float w)
{
	this->vec = glm::vec4(x, y, z, w);
}

onyx::math::Vec4::Vec4(const Vec2& vec, float z, float w)
{
	this->vec = glm::vec4(vec.get_mvec(), z, w);
}

onyx::math::Vec4::Vec4(float x, const Vec2& vec, float w)
{
	this->vec = glm::vec4(x, vec.get_mvec(), w);
}

onyx::math::Vec4::Vec4(float x, float y, const Vec2& vec)
{
	this->vec = glm::vec4(x, y, vec.get_mvec());
}

onyx::math::Vec4::Vec4(const Vec3& vec, float w)
{
	this->vec = glm::vec4(vec.get_mvec(), w);
}

onyx::math::Vec4::Vec4(float x, const Vec3& vec)
{
	this->vec = glm::vec4(x, vec.get_mvec());
}

onyx::math::Vec4::Vec4(const Vec2& vec1, const Vec2& vec2)
{
	this->vec = glm::vec4(vec1.get_mvec(), vec2.get_mvec());
}

onyx::math::Vec4::Vec4(const DVec4& vec)
{
	this->vec = glm::vec4(vec.get_mvec());
}

onyx::math::Vec4::Vec4(const IVec4& vec)
{
	this->vec = glm::vec4(vec.get_mvec());
}

onyx::math::Vec4::Vec4(const UVec4& vec)
{
	this->vec = glm::vec4(vec.get_mvec());
}

onyx::math::Vec4::Vec4(const glm::vec4& vec)
{
	this->vec = vec;
}

float onyx::math::Vec4::magnitude() const
{
	return glm::length(this->vec);
}

void onyx::math::Vec4::normalize()
{
	this->vec = glm::normalize(this->vec);
}

const float* onyx::math::Vec4::data() const
{
	return (float*)(glm::value_ptr(this->vec));
}

bool onyx::math::Vec4::is_zero() const
{
	return get_x() == 0.0f && get_y() == 0.0f && get_z() == 0.0f && get_w() == 0.0f;
}

std::string onyx::math::Vec4::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ", " + std::to_string(get_w()) + ")";
}

float onyx::math::Vec4::get_x() const
{
	return this->vec.x;
}

float onyx::math::Vec4::get_y() const
{
	return this->vec.y;
}

float onyx::math::Vec4::get_z() const
{
	return this->vec.z;
}

float onyx::math::Vec4::get_w() const
{
	return this->vec.w;
}

const glm::vec4& onyx::math::Vec4::get_mvec() const
{
	return this->vec;
}

onyx::math::Vec4 onyx::math::Vec4::get_normalized() const
{
	return Vec4(glm::normalize(this->vec));
}

void onyx::math::Vec4::set_x(float x)
{
	this->vec.x = x;
}

void onyx::math::Vec4::set_y(float y)
{
	this->vec.y = y;
}

void onyx::math::Vec4::set_z(float z)
{
	this->vec.z = z;
}

void onyx::math::Vec4::set_w(float w)
{
	this->vec.w = w;
}

void onyx::math::Vec4::set(float x, float y, float z, float w)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
	this->vec.w = w;
}

void onyx::math::Vec4::set_magnitude(float magnitude)
{
	normalize();
	this->vec *= magnitude;
}

float onyx::math::Vec4::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::Vec4::operator=(const Vec4& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
	this->vec.w = vec.get_w();
}

onyx::math::Vec4 onyx::math::Vec4::operator+(const Vec4& vec) const
{
	return Vec4(this->vec + vec.vec);
}

void onyx::math::Vec4::operator+=(const Vec4& vec)
{
	this->vec += vec.vec;
}

onyx::math::Vec4 onyx::math::Vec4::operator-() const
{
	return Vec4(-this->vec);
}

onyx::math::Vec4 onyx::math::Vec4::operator-(const Vec4& vec) const
{
	return Vec4(this->vec - vec.vec);
}

void onyx::math::Vec4::operator-=(const Vec4& vec)
{
	this->vec -= vec.vec;
}

onyx::math::Vec4 onyx::math::Vec4::operator*(const float& scalar) const
{
	return Vec4(this->vec * scalar);
}

void onyx::math::Vec4::operator*=(const float& scalar)
{
	this->vec *= scalar;
}

onyx::math::Vec4 onyx::math::Vec4::red(float alpha)
{
	return Vec4(Vec3::red(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::orange(float alpha)
{
	return Vec4(Vec3::orange(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::yellow(float alpha)
{
	return Vec4(Vec3::yellow(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::green(float alpha)
{
	return Vec4(Vec3::green(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::dark_green(float alpha)
{
	return Vec4(Vec3::dark_green(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::cyan(float alpha)
{
	return Vec4(Vec3::cyan(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::light_blue(float alpha)
{
	return Vec4(Vec3::light_blue(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::blue(float alpha)
{
	return Vec4(Vec3::blue(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::navy_blue(float alpha)
{
	return Vec4(Vec3::navy_blue(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::purple(float alpha)
{
	return Vec4(Vec3::purple(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::pink(float alpha)
{
	return Vec4(Vec3::pink(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::magenta(float alpha)
{
	return Vec4(Vec3::magenta(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::white(float alpha)
{
	return Vec4(Vec3::white(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::light_gray(float alpha)
{
	return Vec4(Vec3::light_gray(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::dark_gray(float alpha)
{
	return Vec4(Vec3::dark_gray(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::black(float alpha)
{
	return Vec4(Vec3::black(), alpha);
}

onyx::math::Vec4 onyx::math::Vec4::brown(float alpha)
{
	return Vec4(Vec3::brown(), alpha);
}

onyx::math::Vec2 onyx::math::rotate(const Vec2& vec, float angle)
{
	if (vec.is_zero() || angle == 0.0f) return vec;

	Vec2 rotated = vec;

	float rad = radians(angle);
	float s = sinf(rad);
	float c = cosf(rad);
	float x = rotated.get_x();
	float y = rotated.get_y();
	rotated.set_x(x * c - y * s);
	rotated.set_y(x * s + y * c);

	return rotated;
}

onyx::math::Vec3 onyx::math::rotate(const Vec3& vec, float angle, const Vec3& mask)
{
	if (vec.is_zero() || angle == 0.0f) return vec;

	Vec3 rotated = vec;

	float rad = radians(angle);
	float s = sinf(rad);
	float c = cosf(rad);

	if (mask.get_x() != 0.0f)
	{
		float y = rotated.get_y();
		float z = rotated.get_z();
		rotated.set_y(y * c - z * s);
		rotated.set_z(y * s + z * c);
	}

	if (mask.get_y() != 0.0f)
	{
		float x = rotated.get_x();
		float z = rotated.get_z();
		rotated.set_x(x * c + z * s);
		rotated.set_z(-x * s + z * c);
	}

	if (mask.get_z() != 0.0f)
	{
		float x = rotated.get_x();
		float y = rotated.get_y();
		rotated.set_x(x * c - y * s);
		rotated.set_y(x * s + y * c);
	}

	return rotated;
}

onyx::math::Vec3 onyx::math::rotate(const Vec3& vec, const Vec3& angles)
{
	if (vec.is_zero() || angles.is_zero()) return vec;

	Vec3 rotated = vec;

	float rad_x = radians(angles.get_x());
	float rad_y = radians(angles.get_y());
	float rad_z = radians(angles.get_z());

	if (rad_x != 0.0f)
	{
		float s = sinf(rad_x);
		float c = cosf(rad_x);
		float y = rotated.get_y();
		float z = rotated.get_z();
		rotated.set_y(y * c - z * s);
		rotated.set_z(y * s + z * c);
	}

	if (rad_y != 0.0f)
	{
		float s = sinf(rad_y);
		float c = cosf(rad_y);
		float x = rotated.get_x();
		float z = rotated.get_z();
		rotated.set_x(x * c + z * s);
		rotated.set_z(-x * s + z * c);
	}

	if (rad_z != 0.0f)
	{
		float s = sinf(rad_z);
		float c = cosf(rad_z);
		float x = rotated.get_x();
		float y = rotated.get_y();
		rotated.set_x(x * c - y * s);
		rotated.set_y(x * s + y * c);
	}

	return rotated;
}

onyx::math::DVec2::DVec2()
{
	this->vec = glm::dvec2(0.0, 0.0);
}

onyx::math::DVec2::DVec2(double xy)
{
	this->vec = glm::dvec2(xy, xy);
}

onyx::math::DVec2::DVec2(double x, double y)
{
	this->vec = glm::dvec2(x, y);
}

onyx::math::DVec2::DVec2(const Vec2& vec)
{
	this->vec = glm::dvec2(vec.get_mvec());
}

onyx::math::DVec2::DVec2(const IVec2& vec)
{
	this->vec = glm::dvec2(vec.get_mvec());
}

onyx::math::DVec2::DVec2(const UVec2& vec)
{
	this->vec = glm::dvec2(vec.get_mvec());
}

onyx::math::DVec2::DVec2(const glm::dvec2& vec)
{
	this->vec = vec;
}

double onyx::math::DVec2::magnitude() const
{
	return glm::length(this->vec);
}

void onyx::math::DVec2::normalize()
{
	this->vec = glm::normalize(this->vec);
}

const double* onyx::math::DVec2::data() const
{
	return (double*)(glm::value_ptr(this->vec));
}

bool onyx::math::DVec2::is_zero() const
{
	return get_x() == 0.0 && get_y() == 0.0;
}

std::string onyx::math::DVec2::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ")";
}

double onyx::math::DVec2::get_x() const
{
	return this->vec.x;
}

double onyx::math::DVec2::get_y() const
{
	return this->vec.y;
}

const glm::dvec2& onyx::math::DVec2::get_mvec() const
{
	return this->vec;
}

onyx::math::DVec2 onyx::math::DVec2::get_normalized() const
{
	return DVec2(glm::normalize(this->vec));
}

void onyx::math::DVec2::set_x(double x)
{
	this->vec.x = x;
}

void onyx::math::DVec2::set_y(double y)
{
	this->vec.y = y;
}

void onyx::math::DVec2::set(double x, double y)
{
	this->vec.x = x;
	this->vec.y = y;
}

void onyx::math::DVec2::set_magnitude(double magnitude)
{
	normalize();
	this->vec *= magnitude;
}

double onyx::math::DVec2::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::DVec2::operator=(const DVec2& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
}

onyx::math::DVec2 onyx::math::DVec2::operator+(const DVec2& vec) const
{
	return DVec2(this->vec + vec.vec);
}

void onyx::math::DVec2::operator+=(const DVec2& vec)
{
	this->vec += vec.vec;
}

onyx::math::DVec2 onyx::math::DVec2::operator-() const
{
	return DVec2(-this->vec);
}

onyx::math::DVec2 onyx::math::DVec2::operator-(const DVec2& vec) const
{
	return DVec2(this->vec - vec.vec);
}

void onyx::math::DVec2::operator-=(const DVec2& vec)
{
	this->vec -= vec.vec;
}

onyx::math::DVec2 onyx::math::DVec2::operator*(const double& scalar) const
{
	return DVec2(this->vec * scalar);
}

void onyx::math::DVec2::operator*=(const double& scalar)
{
	this->vec *= scalar;
}

onyx::math::DVec3::DVec3()
{
	this->vec = glm::dvec3(0.0, 0.0, 0.0);
}

onyx::math::DVec3::DVec3(double xyz)
{
	this->vec = glm::dvec3(xyz, xyz, xyz);
}

onyx::math::DVec3::DVec3(double x, double y, double z)
{
	this->vec = glm::dvec3(x, y, z);
}

onyx::math::DVec3::DVec3(const DVec2& vec, double z)
{
	this->vec = glm::dvec3(vec.get_mvec(), z);
}

onyx::math::DVec3::DVec3(double x, const DVec2& vec)
{
	this->vec = glm::dvec3(x, vec.get_mvec());
}

onyx::math::DVec3::DVec3(const Vec3& vec)
{
	this->vec = glm::dvec3(vec.get_mvec());
}

onyx::math::DVec3::DVec3(const IVec3& vec)
{
	this->vec = glm::dvec3(vec.get_mvec());
}

onyx::math::DVec3::DVec3(const UVec3& vec)
{
	this->vec = glm::dvec3(vec.get_mvec());
}

onyx::math::DVec3::DVec3(const glm::dvec3& vec)
{
	this->vec = vec;
}

double onyx::math::DVec3::magnitude() const
{
	return glm::length(this->vec);
}

void onyx::math::DVec3::normalize()
{
	this->vec = glm::normalize(this->vec);
}

const double* onyx::math::DVec3::data() const
{
	return (double*)(glm::value_ptr(this->vec));
}

bool onyx::math::DVec3::is_zero() const
{
	return get_x() == 0.0 && get_y() == 0.0 && get_z() == 0.0;
}

std::string onyx::math::DVec3::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ")";
}

double onyx::math::DVec3::get_x() const
{
	return this->vec.x;
}

double onyx::math::DVec3::get_y() const
{
	return this->vec.y;
}

double onyx::math::DVec3::get_z() const
{
	return this->vec.z;
}

const glm::dvec3& onyx::math::DVec3::get_mvec() const
{
	return this->vec;
}

onyx::math::DVec3 onyx::math::DVec3::get_normalized() const
{
	return DVec3(glm::normalize(this->vec));
}

void onyx::math::DVec3::set_x(double x)
{
	this->vec.x = x;
}

void onyx::math::DVec3::set_y(double y)
{
	this->vec.y = y;
}

void onyx::math::DVec3::set_z(double z)
{
	this->vec.z = z;
}

void onyx::math::DVec3::set(double x, double y, double z)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
}

void onyx::math::DVec3::set_magnitude(double magnitude)
{
	normalize();
	this->vec *= magnitude;
}

double onyx::math::DVec3::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::DVec3::operator=(const DVec3& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
}

onyx::math::DVec3 onyx::math::DVec3::operator+(const DVec3& vec) const
{
	return DVec3(this->vec + vec.vec);
}

void onyx::math::DVec3::operator+=(const DVec3& vec)
{
	this->vec += vec.vec;
}

onyx::math::DVec3 onyx::math::DVec3::operator-() const
{
	return DVec3(-this->vec);
}

onyx::math::DVec3 onyx::math::DVec3::operator-(const DVec3& vec) const
{
	return DVec3(this->vec - vec.vec);
}

void onyx::math::DVec3::operator-=(const DVec3& vec)
{
	this->vec -= vec.vec;
}

onyx::math::DVec3 onyx::math::DVec3::operator*(const double& scalar) const
{
	return DVec3(this->vec * scalar);
}

void onyx::math::DVec3::operator*=(const double& scalar)
{
	this->vec *= scalar;
}

onyx::math::DVec4::DVec4()
{
	this->vec = glm::dvec4(0.0, 0.0, 0.0, 0.0);
}

onyx::math::DVec4::DVec4(double xyzw)
{
	this->vec = glm::dvec4(xyzw, xyzw, xyzw, xyzw);
}

onyx::math::DVec4::DVec4(double x, double y, double z, double w)
{
	this->vec = glm::dvec4(x, y, z, w);
}

onyx::math::DVec4::DVec4(const DVec2& vec, double z, double w)
{
	this->vec = glm::dvec4(vec.get_mvec(), z, w);
}

onyx::math::DVec4::DVec4(double x, const DVec2& vec, double w)
{
	this->vec = glm::dvec4(x, vec.get_mvec(), w);
}

onyx::math::DVec4::DVec4(double x, double y, const DVec2& vec)
{
	this->vec = glm::dvec4(x, y, vec.get_mvec());
}

onyx::math::DVec4::DVec4(const DVec3& vec, double w)
{
	this->vec = glm::dvec4(vec.get_mvec(), w);
}

onyx::math::DVec4::DVec4(double x, const DVec3& vec)
{
	this->vec = glm::dvec4(x, vec.get_mvec());
}

onyx::math::DVec4::DVec4(const DVec2& vec1, const DVec2& vec2)
{
	this->vec = glm::dvec4(vec1.get_mvec(), vec2.get_mvec());
}

onyx::math::DVec4::DVec4(const Vec4& vec)
{
	this->vec = glm::dvec4(vec.get_mvec());
}

onyx::math::DVec4::DVec4(const IVec4& vec)
{
	this->vec = glm::dvec4(vec.get_mvec());
}

onyx::math::DVec4::DVec4(const UVec4& vec)
{
	this->vec = glm::dvec4(vec.get_mvec());
}

onyx::math::DVec4::DVec4(const glm::dvec4& vec)
{
	this->vec = vec;
}

double onyx::math::DVec4::magnitude() const
{
	return glm::length(this->vec);
}

void onyx::math::DVec4::normalize()
{
	this->vec = glm::normalize(this->vec);
}

const double* onyx::math::DVec4::data() const
{
	return (double*)(glm::value_ptr(this->vec));
}

bool onyx::math::DVec4::is_zero() const
{
	return get_x() == 0.0 && get_y() == 0.0 && get_z() == 0.0 && get_w() == 0.0;
}

std::string onyx::math::DVec4::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ", " + std::to_string(get_w()) + ")";
}

double onyx::math::DVec4::get_x() const
{
	return this->vec.x;
}

double onyx::math::DVec4::get_y() const
{
	return this->vec.y;
}

double onyx::math::DVec4::get_z() const
{
	return this->vec.z;
}

double onyx::math::DVec4::get_w() const
{
	return this->vec.w;
}

const glm::dvec4& onyx::math::DVec4::get_mvec() const
{
	return this->vec;
}

onyx::math::DVec4 onyx::math::DVec4::get_normalized() const
{
	return DVec4(glm::normalize(this->vec));
}

void onyx::math::DVec4::set_x(double x)
{
	this->vec.x = x;
}

void onyx::math::DVec4::set_y(double y)
{
	this->vec.y = y;
}

void onyx::math::DVec4::set_z(double z)
{
	this->vec.z = z;
}

void onyx::math::DVec4::set_w(double w)
{
	this->vec.w = w;
}

void onyx::math::DVec4::set(double x, double y, double z, double w)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
	this->vec.w = w;
}

void onyx::math::DVec4::set_magnitude(double magnitude)
{
	normalize();
	this->vec *= magnitude;
}

double onyx::math::DVec4::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::DVec4::operator=(const DVec4& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
	this->vec.w = vec.get_w();
}

onyx::math::DVec4 onyx::math::DVec4::operator+(const DVec4& vec) const
{
	return DVec4(this->vec + vec.vec);
}

void onyx::math::DVec4::operator+=(const DVec4& vec)
{
	this->vec += vec.vec;
}

onyx::math::DVec4 onyx::math::DVec4::operator-() const
{
	return DVec4(-this->vec);
}

onyx::math::DVec4 onyx::math::DVec4::operator-(const DVec4& vec) const
{
	return DVec4(this->vec - vec.vec);
}

void onyx::math::DVec4::operator-=(const DVec4& vec)
{
	this->vec -= vec.vec;
}

onyx::math::DVec4 onyx::math::DVec4::operator*(const double& scalar) const
{
	return DVec4(this->vec * scalar);
}

void onyx::math::DVec4::operator*=(const double& scalar)
{
	this->vec *= scalar;
}

onyx::math::DVec2 onyx::math::rotate(const DVec2& vec, double angle)
{
	if (vec.is_zero() || angle == 0.0f) return vec;

	DVec2 rotated = vec;

	double rad = radians(angle);
	double s = sin(rad);
	double c = cos(rad);
	double x = rotated.get_x();
	double y = rotated.get_y();
	rotated.set_x(x * c - y * s);
	rotated.set_y(x * s + y * c);

	return rotated;
}

onyx::math::DVec3 onyx::math::rotate(const DVec3& vec, double angle, const DVec3& mask)
{
	if (vec.is_zero() || angle == 0.0f) return vec;

	DVec3 rotated = vec;

	double rad = radians(angle);
	double s = sin(rad);
	double c = cos(rad);

	if (mask.get_x() != 0.0f)
	{
		double y = rotated.get_y();
		double z = rotated.get_z();
		rotated.set_y(y * c - z * s);
		rotated.set_z(y * s + z * c);
	}

	if (mask.get_y() != 0.0f)
	{
		double x = rotated.get_x();
		double z = rotated.get_z();
		rotated.set_x(x * c + z * s);
		rotated.set_z(-x * s + z * c);
	}

	if (mask.get_z() != 0.0f)
	{
		double x = rotated.get_x();
		double y = rotated.get_y();
		rotated.set_x(x * c - y * s);
		rotated.set_y(x * s + y * c);
	}

	return rotated;
}

onyx::math::DVec3 onyx::math::rotate(const DVec3& vec, const DVec3& angles)
{
	if (vec.is_zero() || angles.is_zero()) return vec;

	DVec3 rotated = vec;

	double rad_x = radians(angles.get_x());
	double rad_y = radians(angles.get_y());
	double rad_z = radians(angles.get_z());

	if (rad_x != 0.0f)
	{
		double s = sin(rad_x);
		double c = cos(rad_x);
		double y = rotated.get_y();
		double z = rotated.get_z();
		rotated.set_y(y * c - z * s);
		rotated.set_z(y * s + z * c);
	}

	if (rad_y != 0.0f)
	{
		double s = sin(rad_y);
		double c = cos(rad_y);
		double x = rotated.get_x();
		double z = rotated.get_z();
		rotated.set_x(x * c + z * s);
		rotated.set_z(-x * s + z * c);
	}

	if (rad_z != 0.0f)
	{
		double s = sin(rad_z);
		double c = cos(rad_z);
		double x = rotated.get_x();
		double y = rotated.get_y();
		rotated.set_x(x * c - y * s);
		rotated.set_y(x * s + y * c);
	}

	return rotated;
}

onyx::math::DVec2 onyx::math::reflect(const DVec2& vec, const DVec2& normal)
{
	return DVec2(glm::reflect(vec.get_mvec(), normal.get_mvec()));
}

onyx::math::DVec3 onyx::math::reflect(const DVec3& vec, const DVec3& normal)
{
	return DVec3(glm::reflect(vec.get_mvec(), normal.get_mvec()));
}

onyx::math::DVec4 onyx::math::reflect(const DVec4& vec, const DVec4& normal)
{
	return DVec4(glm::reflect(vec.get_mvec(), normal.get_mvec()));
}

onyx::math::Vec2 onyx::math::reflect(const Vec2& vec, const Vec2& normal)
{
	return Vec2(glm::reflect(vec.get_mvec(), normal.get_mvec()));
}

onyx::math::Vec3 onyx::math::reflect(const Vec3& vec, const Vec3& normal)
{
	return Vec3(glm::reflect(vec.get_mvec(), normal.get_mvec()));
}

onyx::math::Vec4 onyx::math::reflect(const Vec4& vec, const Vec4& normal)
{
	return Vec4(glm::reflect(vec.get_mvec(), normal.get_mvec()));
}

onyx::math::IVec2::IVec2()
{
	this->vec = glm::ivec2(0, 0);
}

onyx::math::IVec2::IVec2(int xy)
{
	this->vec = glm::ivec2(xy, xy);
}

onyx::math::IVec2::IVec2(int x, int y)
{
	this->vec = glm::ivec2(x, y);
}

onyx::math::IVec2::IVec2(const Vec2& vec)
{
	this->vec = glm::ivec2(vec.get_mvec());
}

onyx::math::IVec2::IVec2(const DVec2& vec)
{
	this->vec = glm::ivec2(vec.get_mvec());
}

onyx::math::IVec2::IVec2(const UVec2& vec)
{
	this->vec = glm::ivec2(vec.get_mvec());
}

onyx::math::IVec2::IVec2(const glm::ivec2& vec)
{
	this->vec = vec;
}

const int* onyx::math::IVec2::data() const
{
	return (int*)(glm::value_ptr(this->vec));
}

bool onyx::math::IVec2::is_zero() const
{
	return get_x() == 0 && get_y() == 0;
}

std::string onyx::math::IVec2::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ")";
}

int onyx::math::IVec2::get_x() const
{
	return this->vec.x;
}

int onyx::math::IVec2::get_y() const
{
	return this->vec.y;
}

const glm::ivec2& onyx::math::IVec2::get_mvec() const
{
	return this->vec;
}

void onyx::math::IVec2::set_x(int x)
{
	this->vec.x = x;
}

void onyx::math::IVec2::set_y(int y)
{
	this->vec.y = y;
}

void onyx::math::IVec2::set(int x, int y)
{
	this->vec.x = x;
	this->vec.y = y;
}

int onyx::math::IVec2::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::IVec2::operator=(const IVec2& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
}

onyx::math::IVec2 onyx::math::IVec2::operator+(const IVec2& vec) const
{
	return IVec2(this->vec + vec.vec);
}

void onyx::math::IVec2::operator+=(const IVec2& vec)
{
	this->vec += vec.vec;
}

onyx::math::IVec2 onyx::math::IVec2::operator-() const
{
	return IVec2(-this->vec);
}

onyx::math::IVec2 onyx::math::IVec2::operator-(const IVec2& vec) const
{
	return IVec2(this->vec - vec.vec);
}

void onyx::math::IVec2::operator-=(const IVec2& vec)
{
	this->vec -= vec.vec;
}

onyx::math::IVec2 onyx::math::IVec2::operator*(const float& scalar) const
{
	return IVec2(this->vec.x * scalar, this->vec.y * scalar);
}

void onyx::math::IVec2::operator*=(const float& scalar)
{
	this->vec.x *= scalar;
	this->vec.y *= scalar;
}

onyx::math::IVec3::IVec3()
{
	this->vec = glm::ivec3(0, 0, 0);
}

onyx::math::IVec3::IVec3(int xyz)
{
	this->vec = glm::ivec3(xyz, xyz, xyz);
}

onyx::math::IVec3::IVec3(int x, int y, int z)
{
	this->vec = glm::ivec3(x, y, z);
}

onyx::math::IVec3::IVec3(const IVec2& vec, int z)
{
	this->vec = glm::ivec3(vec.get_mvec(), z);
}

onyx::math::IVec3::IVec3(int x, const IVec2& vec)
{
	this->vec = glm::ivec3(x, vec.get_mvec());
}

onyx::math::IVec3::IVec3(const Vec3& vec)
{
	this->vec = glm::ivec3(vec.get_mvec());
}

onyx::math::IVec3::IVec3(const DVec3& vec)
{
	this->vec = glm::ivec3(vec.get_mvec());
}

onyx::math::IVec3::IVec3(const UVec3& vec)
{
	this->vec = glm::ivec3(vec.get_mvec());
}

onyx::math::IVec3::IVec3(const glm::ivec3& vec)
{
	this->vec = vec;
}

const int* onyx::math::IVec3::data() const
{
	return (int*)(glm::value_ptr(this->vec));
}

bool onyx::math::IVec3::is_zero() const
{
	return get_x() == 0 && get_y() == 0 && get_z() == 0;
}

std::string onyx::math::IVec3::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ")";
}

int onyx::math::IVec3::get_x() const
{
	return this->vec.x;
}

int onyx::math::IVec3::get_y() const
{
	return this->vec.y;
}

int onyx::math::IVec3::get_z() const
{
	return this->vec.z;
}

const glm::ivec3& onyx::math::IVec3::get_mvec() const
{
	return this->vec;
}

void onyx::math::IVec3::set_x(int x)
{
	this->vec.x = x;
}

void onyx::math::IVec3::set_y(int y)
{
	this->vec.y = y;
}

void onyx::math::IVec3::set_z(int z)
{
	this->vec.z = z;
}

void onyx::math::IVec3::set(int x, int y, int z)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
}

int onyx::math::IVec3::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::IVec3::operator=(const IVec3& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
}

onyx::math::IVec3 onyx::math::IVec3::operator+(const IVec3& vec) const
{
	return IVec3(this->vec + vec.vec);
}

void onyx::math::IVec3::operator+=(const IVec3& vec)
{
	this->vec += vec.vec;
}

onyx::math::IVec3 onyx::math::IVec3::operator-() const
{
	return IVec3(-this->vec);
}

onyx::math::IVec3 onyx::math::IVec3::operator-(const IVec3& vec) const
{
	return IVec3(this->vec - vec.vec);
}

void onyx::math::IVec3::operator-=(const IVec3& vec)
{
	this->vec -= vec.vec;
}

onyx::math::IVec3 onyx::math::IVec3::operator*(const float& scalar) const
{
	return IVec3(this->vec.x * scalar, this->vec.y * scalar, this->vec.z * scalar);
}

void onyx::math::IVec3::operator*=(const float& scalar)
{
	this->vec.x *= scalar;
	this->vec.y *= scalar;
	this->vec.z *= scalar;
}

onyx::math::IVec4::IVec4()
{
	this->vec = glm::ivec4(0, 0, 0, 0);
}

onyx::math::IVec4::IVec4(int xyzw)
{
	this->vec = glm::ivec4(xyzw, xyzw, xyzw, xyzw);
}

onyx::math::IVec4::IVec4(int x, int y, int z, int w)
{
	this->vec = glm::ivec4(x, y, z, w);
}

onyx::math::IVec4::IVec4(const IVec2& vec, int z, int w)
{
	this->vec = glm::ivec4(vec.get_mvec(), z, w);
}

onyx::math::IVec4::IVec4(int x, const IVec2& vec, int w)
{
	this->vec = glm::ivec4(x, vec.get_mvec(), w);
}

onyx::math::IVec4::IVec4(int x, int y, const IVec2& vec)
{
	this->vec = glm::ivec4(x, y, vec.get_mvec());
}

onyx::math::IVec4::IVec4(const IVec3& vec, int w)
{
	this->vec = glm::ivec4(vec.get_mvec(), w);
}

onyx::math::IVec4::IVec4(int x, const IVec3& vec)
{
	this->vec = glm::ivec4(x, vec.get_mvec());
}

onyx::math::IVec4::IVec4(const IVec2& vec1, const IVec2& vec2)
{
	this->vec = glm::ivec4(vec1.get_mvec(), vec2.get_mvec());
}

onyx::math::IVec4::IVec4(const Vec4& vec)
{
	this->vec = glm::ivec4(vec.get_mvec());
}

onyx::math::IVec4::IVec4(const DVec4& vec)
{
	this->vec = glm::ivec4(vec.get_mvec());
}

onyx::math::IVec4::IVec4(const UVec4& vec)
{
	this->vec = glm::ivec4(vec.get_mvec());
}

onyx::math::IVec4::IVec4(const glm::ivec4& vec)
{
	this->vec = vec;
}

const int* onyx::math::IVec4::data() const
{
	return (int*)(glm::value_ptr(this->vec));
}

bool onyx::math::IVec4::is_zero() const
{
	return get_x() == 0 && get_y() == 0 && get_z() == 0 && get_w() == 0;
}

std::string onyx::math::IVec4::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ", " + std::to_string(get_w()) + ")";
}

int onyx::math::IVec4::get_x() const
{
	return this->vec.x;
}

int onyx::math::IVec4::get_y() const
{
	return this->vec.y;
}

int onyx::math::IVec4::get_z() const
{
	return this->vec.z;
}

int onyx::math::IVec4::get_w() const
{
	return this->vec.w;
}

const glm::ivec4& onyx::math::IVec4::get_mvec() const
{
	return this->vec;
}

void onyx::math::IVec4::set_x(int x)
{
	this->vec.x = x;
}

void onyx::math::IVec4::set_y(int y)
{
	this->vec.y = y;
}

void onyx::math::IVec4::set_z(int z)
{
	this->vec.z = z;
}

void onyx::math::IVec4::set_w(int w)
{
	this->vec.w = w;
}

void onyx::math::IVec4::set(int x, int y, int z, int w)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
	this->vec.w = w;
}

int onyx::math::IVec4::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::IVec4::operator=(const IVec4& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
	this->vec.w = vec.get_w();
}

onyx::math::IVec4 onyx::math::IVec4::operator+(const IVec4& vec) const
{
	return IVec4(this->vec + vec.vec);
}

void onyx::math::IVec4::operator+=(const IVec4& vec)
{
	this->vec += vec.vec;
}

onyx::math::IVec4 onyx::math::IVec4::operator-() const
{
	return IVec4(-this->vec);
}

onyx::math::IVec4 onyx::math::IVec4::operator-(const IVec4& vec) const
{
	return IVec4(this->vec - vec.vec);
}

void onyx::math::IVec4::operator-=(const IVec4& vec)
{
	this->vec -= vec.vec;
}

onyx::math::IVec4 onyx::math::IVec4::operator*(const float& scalar) const
{
	return IVec4(this->vec.x * scalar, this->vec.y * scalar, this->vec.z * scalar, this->vec.w * scalar);
}

void onyx::math::IVec4::operator*=(const float& scalar)
{
	this->vec.x *= scalar;
	this->vec.y *= scalar;
	this->vec.z *= scalar;
	this->vec.w *= scalar;
}

onyx::math::UVec2::UVec2()
{
	this->vec = glm::uvec2(0, 0);
}

onyx::math::UVec2::UVec2(u32 xy)
{
	this->vec = glm::uvec2(xy, xy);
}

onyx::math::UVec2::UVec2(u32 x, u32 y)
{
	this->vec = glm::uvec2(x, y);
}

onyx::math::UVec2::UVec2(const glm::uvec2& vec)
{
	this->vec = vec;
}

const u32* onyx::math::UVec2::data() const
{
	return (u32*)(glm::value_ptr(this->vec));
}

bool onyx::math::UVec2::is_zero() const
{
	return get_x() == 0 && get_y() == 0;
}

std::string onyx::math::UVec2::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ")";
}

u32 onyx::math::UVec2::get_x() const
{
	return this->vec.x;
}

u32 onyx::math::UVec2::get_y() const
{
	return this->vec.y;
}

const glm::uvec2& onyx::math::UVec2::get_mvec() const
{
	return this->vec;
}

void onyx::math::UVec2::set_x(u32 x)
{
	this->vec.x = x;
}

void onyx::math::UVec2::set_y(u32 y)
{
	this->vec.y = y;
}

void onyx::math::UVec2::set(u32 x, u32 y)
{
	this->vec.x = x;
	this->vec.y = y;
}

u32 onyx::math::UVec2::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::UVec2::operator=(const UVec2& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
}

onyx::math::UVec2 onyx::math::UVec2::operator+(const UVec2& vec) const
{
	return UVec2(this->vec + vec.vec);
}

void onyx::math::UVec2::operator+=(const UVec2& vec)
{
	this->vec += vec.vec;
}

onyx::math::UVec2 onyx::math::UVec2::operator-(const UVec2& vec) const
{
	return UVec2(this->vec - vec.vec);
}

void onyx::math::UVec2::operator-=(const UVec2& vec)
{
	this->vec -= vec.vec;
}

onyx::math::UVec2 onyx::math::UVec2::operator*(const float& _scalar) const
{
	float scalar = abs(_scalar);
	return UVec2(this->vec.x * scalar, this->vec.y * scalar);
}

void onyx::math::UVec2::operator*=(const float& _scalar)
{
	float scalar = abs(_scalar);
	this->vec.x *= scalar;
	this->vec.y *= scalar;
}

onyx::math::UVec3::UVec3()
{
	this->vec = glm::uvec3(0, 0, 0);
}

onyx::math::UVec3::UVec3(u32 xyz)
{
	this->vec = glm::uvec3(xyz, xyz, xyz);
}

onyx::math::UVec3::UVec3(u32 x, u32 y, u32 z)
{
	this->vec = glm::uvec3(x, y, z);
}

onyx::math::UVec3::UVec3(const UVec2& vec, u32 z)
{
	this->vec = glm::uvec3(vec.get_mvec(), z);
}

onyx::math::UVec3::UVec3(u32 x, const UVec2& vec)
{
	this->vec = glm::uvec3(x, vec.get_mvec());
}

onyx::math::UVec3::UVec3(const glm::uvec3& vec)
{
	this->vec = vec;
}

const u32* onyx::math::UVec3::data() const
{
	return (u32*)(glm::value_ptr(this->vec));
}

bool onyx::math::UVec3::is_zero() const
{
	return get_x() == 0 && get_y() == 0 && get_z() == 0;
}

std::string onyx::math::UVec3::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ")";
}

u32 onyx::math::UVec3::get_x() const
{
	return this->vec.x;
}

u32 onyx::math::UVec3::get_y() const
{
	return this->vec.y;
}

u32 onyx::math::UVec3::get_z() const
{
	return this->vec.z;
}

const glm::uvec3& onyx::math::UVec3::get_mvec() const
{
	return this->vec;
}

void onyx::math::UVec3::set_x(u32 x)
{
	this->vec.x = x;
}

void onyx::math::UVec3::set_y(u32 y)
{
	this->vec.y = y;
}

void onyx::math::UVec3::set_z(u32 z)
{
	this->vec.z = z;
}

void onyx::math::UVec3::set(u32 x, u32 y, u32 z)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
}

u32 onyx::math::UVec3::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::UVec3::operator=(const UVec3& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
}

onyx::math::UVec3 onyx::math::UVec3::operator+(const UVec3& vec) const
{
	return UVec3(this->vec + vec.vec);
}

void onyx::math::UVec3::operator+=(const UVec3& vec)
{
	this->vec += vec.vec;
}

onyx::math::UVec3 onyx::math::UVec3::operator-(const UVec3& vec) const
{
	return UVec3(this->vec - vec.vec);
}

void onyx::math::UVec3::operator-=(const UVec3& vec)
{
	this->vec -= vec.vec;
}

onyx::math::UVec3 onyx::math::UVec3::operator*(const float& _scalar) const
{
	float scalar = abs(_scalar);
	return UVec3(this->vec.x * scalar, this->vec.y * scalar, this->vec.z * scalar);
}

void onyx::math::UVec3::operator*=(const float& _scalar)
{
	float scalar = abs(_scalar);
	this->vec.x *= scalar;
	this->vec.y *= scalar;
	this->vec.z *= scalar;
}

onyx::math::UVec4::UVec4()
{
	this->vec = glm::uvec4(0, 0, 0, 0);
}

onyx::math::UVec4::UVec4(u32 xyzw)
{
	this->vec = glm::uvec4(xyzw, xyzw, xyzw, xyzw);
}

onyx::math::UVec4::UVec4(u32 x, u32 y, u32 z, u32 w)
{
	this->vec = glm::uvec4(x, y, z, w);
}

onyx::math::UVec4::UVec4(const UVec2& vec, u32 z, u32 w)
{
	this->vec = glm::uvec4(vec.get_mvec(), z, w);
}

onyx::math::UVec4::UVec4(u32 x, const UVec2& vec, u32 w)
{
	this->vec = glm::uvec4(x, vec.get_mvec(), w);
}

onyx::math::UVec4::UVec4(u32 x, u32 y, const UVec2& vec)
{
	this->vec = glm::uvec4(x, y, vec.get_mvec());
}

onyx::math::UVec4::UVec4(const UVec3& vec, u32 w)
{
	this->vec = glm::uvec4(vec.get_mvec(), w);
}

onyx::math::UVec4::UVec4(u32 x, const UVec3& vec)
{
	this->vec = glm::uvec4(x, vec.get_mvec());
}

onyx::math::UVec4::UVec4(const UVec2& vec1, const UVec2& vec2)
{
	this->vec = glm::uvec4(vec1.get_mvec(), vec2.get_mvec());
}

onyx::math::UVec4::UVec4(const glm::uvec4& vec)
{
	this->vec = vec;
}

const u32* onyx::math::UVec4::data() const
{
	return (u32*)(glm::value_ptr(this->vec));
}

bool onyx::math::UVec4::is_zero() const
{
	return get_x() == 0 && get_y() == 0 && get_z() == 0 && get_w() == 0;
}

std::string onyx::math::UVec4::to_string() const
{
	return "(" + std::to_string(get_x()) + ", " + std::to_string(get_y()) + ", " + std::to_string(get_z()) + ", " + std::to_string(get_w()) + ")";
}

u32 onyx::math::UVec4::get_x() const
{
	return this->vec.x;
}

u32 onyx::math::UVec4::get_y() const
{
	return this->vec.y;
}

u32 onyx::math::UVec4::get_z() const
{
	return this->vec.z;
}

u32 onyx::math::UVec4::get_w() const
{
	return this->vec.w;
}

const glm::uvec4& onyx::math::UVec4::get_mvec() const
{
	return this->vec;
}

void onyx::math::UVec4::set_x(u32 x)
{
	this->vec.x = x;
}

void onyx::math::UVec4::set_y(u32 y)
{
	this->vec.y = y;
}

void onyx::math::UVec4::set_z(u32 z)
{
	this->vec.z = z;
}

void onyx::math::UVec4::set_w(u32 w)
{
	this->vec.w = w;
}

void onyx::math::UVec4::set(u32 x, u32 y, u32 z, u32 w)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
	this->vec.w = w;
}

u32 onyx::math::UVec4::operator[](int index) const
{
	return this->vec[index];
}

void onyx::math::UVec4::operator=(const UVec4& vec)
{
	this->vec.x = vec.get_x();
	this->vec.y = vec.get_y();
	this->vec.z = vec.get_z();
	this->vec.w = vec.get_w();
}

onyx::math::UVec4 onyx::math::UVec4::operator+(const UVec4& vec) const
{
	return UVec4(this->vec + vec.vec);
}

void onyx::math::UVec4::operator+=(const UVec4& vec)
{
	this->vec += vec.vec;
}

onyx::math::UVec4 onyx::math::UVec4::operator-(const UVec4& vec) const
{
	return UVec4(this->vec - vec.vec);
}

void onyx::math::UVec4::operator-=(const UVec4& vec)
{
	this->vec -= vec.vec;
}

onyx::math::UVec4 onyx::math::UVec4::operator*(const float& _scalar) const
{
	float scalar = abs(_scalar);
	return UVec4(this->vec.x * scalar, this->vec.y * scalar, this->vec.z * scalar, this->vec.w * scalar);
}

void onyx::math::UVec4::operator*=(const float& _scalar)
{
	float scalar = abs(_scalar);
	this->vec.x *= scalar;
	this->vec.y *= scalar;
	this->vec.z *= scalar;
	this->vec.w *= scalar;
}

onyx::math::Vec3 onyx::math::cross(const Vec3& vec1, const Vec3& vec2)
{
	return Vec3(glm::cross(vec1.vec, vec2.vec));
}

float onyx::math::dot(const Vec2& vec1, const Vec2& vec2)
{
	return glm::dot(vec1.vec, vec2.vec);
}

float onyx::math::dot(const Vec3& vec1, const Vec3& vec2)
{
	return glm::dot(vec1.vec, vec2.vec);
}

float onyx::math::dot(const Vec4& vec1, const Vec4& vec2)
{
	return glm::dot(vec1.vec, vec2.vec);
}

onyx::math::DVec3 onyx::math::cross(const DVec3& vec1, const DVec3& vec2)
{
	return DVec3(glm::cross(vec1.vec, vec2.vec));
}

double onyx::math::dot(const DVec2& vec1, const DVec2& vec2)
{
	return glm::dot(vec1.vec, vec2.vec);
}

double onyx::math::dot(const DVec3& vec1, const DVec3& vec2)
{
	return glm::dot(vec1.vec, vec2.vec);
}

double onyx::math::dot(const DVec4& vec1, const DVec4& vec2)
{
	return glm::dot(vec1.vec, vec2.vec);
}

bool onyx::math::operator==(const Vec2& vec1, const Vec2& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const Vec2& vec1, const Vec2& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const Vec3& vec1, const Vec3& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const Vec3& vec1, const Vec3& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const Vec4& vec1, const Vec4& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const Vec4& vec1, const Vec4& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const DVec2& vec1, const DVec2& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const DVec2& vec1, const DVec2& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const DVec3& vec1, const DVec3& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const DVec3& vec1, const DVec3& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const DVec4& vec1, const DVec4& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const DVec4& vec1, const DVec4& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const IVec2& vec1, const IVec2& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const IVec2& vec1, const IVec2& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const IVec3& vec1, const IVec3& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const IVec3& vec1, const IVec3& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const IVec4& vec1, const IVec4& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const IVec4& vec1, const IVec4& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const UVec2& vec1, const UVec2& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const UVec2& vec1, const UVec2& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const UVec3& vec1, const UVec3& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const UVec3& vec1, const UVec3& vec2)
{
	return vec1.vec != vec2.vec;
}

bool onyx::math::operator==(const UVec4& vec1, const UVec4& vec2)
{
	return vec1.vec == vec2.vec;
}

bool onyx::math::operator!=(const UVec4& vec1, const UVec4& vec2)
{
	return vec1.vec != vec2.vec;
}

onyx::math::Mat2x2::Mat2x2()
{
	this->mat = glm::mat2x2(0.0f);
}

onyx::math::Mat2x2::Mat2x2(float scalar)
{
	this->mat = glm::mat2x2(scalar);
}

onyx::math::Mat2x2::Mat2x2(glm::mat2x2 mat)
{
	this->mat = mat;
}

glm::mat2x2 onyx::math::Mat2x2::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat2x2::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat2x2::to_string() const
{
	std::string str;
	for (int i = 0; i < 2; i++)
	{
		str += "|";
		for (int j = 0; j < 2; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec2 onyx::math::Mat2x2::operator[](int index) const
{
	return Vec2(this->mat[index]);
}

void onyx::math::Mat2x2::operator=(const Mat2x2& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat2x2 onyx::math::Mat2x2::operator+(const Mat2x2& mat) const
{
	return Mat2x2(this->mat + mat.mat);
}

void onyx::math::Mat2x2::operator+=(const Mat2x2& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat2x2 onyx::math::Mat2x2::operator-() const
{
	return Mat2x2(-this->mat);
}

onyx::math::Mat2x2 onyx::math::Mat2x2::operator-(const Mat2x2& mat) const
{
	return Mat2x2(this->mat - mat.mat);
}

void onyx::math::Mat2x2::operator-=(const Mat2x2& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat2x2 onyx::math::Mat2x2::identity()
{
	return Mat2x2(1.0f);
}

onyx::math::Mat2x3::Mat2x3()
{
	this->mat = glm::mat2x3(0.0f);
}

onyx::math::Mat2x3::Mat2x3(float scalar)
{
	this->mat = glm::mat2x3(scalar);
}

onyx::math::Mat2x3::Mat2x3(glm::mat2x3 mat)
{
	this->mat = mat;
}

glm::mat2x3 onyx::math::Mat2x3::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat2x3::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat2x3::to_string() const
{
	std::string str;
	for (int i = 0; i < 2; i++)
	{
		str += "|";
		for (int j = 0; j < 3; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec3 onyx::math::Mat2x3::operator[](int index) const
{
	return Vec3(this->mat[index]);
}

void onyx::math::Mat2x3::operator=(const Mat2x3& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat2x3 onyx::math::Mat2x3::operator+(const Mat2x3& mat) const
{
	return Mat2x3(this->mat + mat.mat);
}

void onyx::math::Mat2x3::operator+=(const Mat2x3& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat2x3 onyx::math::Mat2x3::operator-() const
{
	return Mat2x3(-this->mat);
}

onyx::math::Mat2x3 onyx::math::Mat2x3::operator-(const Mat2x3& mat) const
{
	return Mat2x3(this->mat - mat.mat);
}

void onyx::math::Mat2x3::operator-=(const Mat2x3& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat2x3 onyx::math::Mat2x3::identity()
{
	return Mat2x3(1.0f);
}

onyx::math::Mat2x4::Mat2x4()
{
	this->mat = glm::mat2x4(0.0f);
}

onyx::math::Mat2x4::Mat2x4(float scalar)
{
	this->mat = glm::mat2x4(scalar);
}

onyx::math::Mat2x4::Mat2x4(glm::mat2x4 mat)
{
	this->mat = mat;
}

glm::mat2x4 onyx::math::Mat2x4::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat2x4::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat2x4::to_string() const
{
	std::string str;
	for (int i = 0; i < 2; i++)
	{
		str += "|";
		for (int j = 0; j < 4; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec4 onyx::math::Mat2x4::operator[](int index) const
{
	return Vec4(this->mat[index]);
}

void onyx::math::Mat2x4::operator=(const Mat2x4& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat2x4 onyx::math::Mat2x4::operator+(const Mat2x4& mat) const
{
	return Mat2x4(this->mat + mat.mat);
}

void onyx::math::Mat2x4::operator+=(const Mat2x4& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat2x4 onyx::math::Mat2x4::operator-() const
{
	return Mat2x4(-this->mat);
}

onyx::math::Mat2x4 onyx::math::Mat2x4::operator-(const Mat2x4& mat) const
{
	return Mat2x4(this->mat - mat.mat);
}

void onyx::math::Mat2x4::operator-=(const Mat2x4& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat2x4 onyx::math::Mat2x4::identity()
{
	return Mat2x4(1.0f);
}

onyx::math::Mat3x2::Mat3x2()
{
	this->mat = glm::mat3x2(0.0f);
}

onyx::math::Mat3x2::Mat3x2(float scalar)
{
	this->mat = glm::mat3x2(scalar);
}

onyx::math::Mat3x2::Mat3x2(glm::mat3x2 mat)
{
	this->mat = mat;
}

glm::mat3x2 onyx::math::Mat3x2::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat3x2::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat3x2::to_string() const
{
	std::string str;
	for (int i = 0; i < 3; i++)
	{
		str += "|";
		for (int j = 0; j < 2; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec2 onyx::math::Mat3x2::operator[](int index) const
{
	return Vec2(this->mat[index]);
}

void onyx::math::Mat3x2::operator=(const Mat3x2& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat3x2 onyx::math::Mat3x2::operator+(const Mat3x2& mat) const
{
	return Mat3x2(this->mat + mat.mat);
}

void onyx::math::Mat3x2::operator+=(const Mat3x2& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat3x2 onyx::math::Mat3x2::operator-() const
{
	return Mat3x2(-this->mat);
}

onyx::math::Mat3x2 onyx::math::Mat3x2::operator-(const Mat3x2& mat) const
{
	return Mat3x2(this->mat - mat.mat);
}

void onyx::math::Mat3x2::operator-=(const Mat3x2& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat3x2 onyx::math::Mat3x2::identity()
{
	return Mat3x2(1.0f);
}

onyx::math::Mat3x3::Mat3x3()
{
	this->mat = glm::mat3x3(0.0f);
}

onyx::math::Mat3x3::Mat3x3(float scalar)
{
	this->mat = glm::mat3x3(scalar);
}

onyx::math::Mat3x3::Mat3x3(glm::mat3x3 mat)
{
	this->mat = mat;
}

glm::mat3x3 onyx::math::Mat3x3::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat3x3::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat3x3::to_string() const
{
	std::string str;
	for (int i = 0; i < 3; i++)
	{
		str += "|";
		for (int j = 0; j < 3; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec3 onyx::math::Mat3x3::operator[](int index) const
{
	return Vec3(this->mat[index]);
}

void onyx::math::Mat3x3::operator=(const Mat3x3& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat3x3 onyx::math::Mat3x3::operator+(const Mat3x3& mat) const
{
	return Mat3x3(this->mat + mat.mat);
}

void onyx::math::Mat3x3::operator+=(const Mat3x3& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat3x3 onyx::math::Mat3x3::operator-() const
{
	return Mat3x3(-this->mat);
}

onyx::math::Mat3x3 onyx::math::Mat3x3::operator-(const Mat3x3& mat) const
{
	return Mat3x3(this->mat - mat.mat);
}

void onyx::math::Mat3x3::operator-=(const Mat3x3& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat3x3 onyx::math::Mat3x3::identity()
{
	return Mat3x3(1.0f);
}

onyx::math::Mat3x4::Mat3x4()
{
	this->mat = glm::mat3x4(0.0f);
}

onyx::math::Mat3x4::Mat3x4(float scalar)
{
	this->mat = glm::mat3x4(scalar);
}

onyx::math::Mat3x4::Mat3x4(glm::mat3x4 mat)
{
	this->mat = mat;
}

glm::mat3x4 onyx::math::Mat3x4::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat3x4::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat3x4::to_string() const
{
	std::string str;
	for (int i = 0; i < 3; i++)
	{
		str += "|";
		for (int j = 0; j < 4; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec4 onyx::math::Mat3x4::operator[](int index) const
{
	return Vec4(this->mat[index]);
}

void onyx::math::Mat3x4::operator=(const Mat3x4& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat3x4 onyx::math::Mat3x4::operator+(const Mat3x4& mat) const
{
	return Mat3x4(this->mat + mat.mat);
}

void onyx::math::Mat3x4::operator+=(const Mat3x4& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat3x4 onyx::math::Mat3x4::operator-() const
{
	return Mat3x4(-this->mat);
}

onyx::math::Mat3x4 onyx::math::Mat3x4::operator-(const Mat3x4& mat) const
{
	return Mat3x4(this->mat - mat.mat);
}

void onyx::math::Mat3x4::operator-=(const Mat3x4& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat3x4 onyx::math::Mat3x4::identity()
{
	return Mat3x4(1.0f);
}

onyx::math::Mat4x2::Mat4x2()
{
	this->mat = glm::mat4x2(0.0f);
}

onyx::math::Mat4x2::Mat4x2(float scalar)
{
	this->mat = glm::mat4x2(scalar);
}

onyx::math::Mat4x2::Mat4x2(glm::mat4x2 mat)
{
	this->mat = mat;
}

glm::mat4x2 onyx::math::Mat4x2::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat4x2::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat4x2::to_string() const
{
	std::string str;
	for (int i = 0; i < 4; i++)
	{
		str += "|";
		for (int j = 0; j < 2; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec2 onyx::math::Mat4x2::operator[](int index) const
{
	return Vec2(this->mat[index]);
}

void onyx::math::Mat4x2::operator=(const Mat4x2& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat4x2 onyx::math::Mat4x2::operator+(const Mat4x2& mat) const
{
	return Mat4x2(this->mat + mat.mat);
}

void onyx::math::Mat4x2::operator+=(const Mat4x2& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat4x2 onyx::math::Mat4x2::operator-() const
{
	return Mat4x2(-this->mat);
}

onyx::math::Mat4x2 onyx::math::Mat4x2::operator-(const Mat4x2& mat) const
{
	return Mat4x2(this->mat - mat.mat);
}

void onyx::math::Mat4x2::operator-=(const Mat4x2& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat4x2 onyx::math::Mat4x2::identity()
{
	return Mat4x2(1.0f);
}

onyx::math::Mat4x3::Mat4x3()
{
	this->mat = glm::mat4x3(0.0f);
}

onyx::math::Mat4x3::Mat4x3(float scalar)
{
	this->mat = glm::mat4x3(scalar);
}

onyx::math::Mat4x3::Mat4x3(glm::mat4x3 mat)
{
	this->mat = mat;
}

glm::mat4x3 onyx::math::Mat4x3::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat4x3::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat4x3::to_string() const
{
	std::string str;
	for (int i = 0; i < 4; i++)
	{
		str += "|";
		for (int j = 0; j < 3; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec3 onyx::math::Mat4x3::operator[](int index) const
{
	return Vec3(this->mat[index]);
}

void onyx::math::Mat4x3::operator=(const Mat4x3& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat4x3 onyx::math::Mat4x3::operator+(const Mat4x3& mat) const
{
	return Mat4x3(this->mat + mat.mat);
}

void onyx::math::Mat4x3::operator+=(const Mat4x3& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat4x3 onyx::math::Mat4x3::operator-() const
{
	return Mat4x3(-this->mat);
}

onyx::math::Mat4x3 onyx::math::Mat4x3::operator-(const Mat4x3& mat) const
{
	return Mat4x3(this->mat - mat.mat);
}

void onyx::math::Mat4x3::operator-=(const Mat4x3& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat4x3 onyx::math::Mat4x3::identity()
{
	return Mat4x3(1.0f);
}

onyx::math::Mat4x4::Mat4x4()
{
	this->mat = glm::mat4x4(0.0f);
}

onyx::math::Mat4x4::Mat4x4(float scalar)
{
	this->mat = glm::mat4x4(scalar);
}

onyx::math::Mat4x4::Mat4x4(glm::mat4x4 mat)
{
	this->mat = mat;
}

void onyx::math::Mat4x4::translate(const Vec3& xyz)
{
	this->mat = glm::translate(this->mat, xyz.get_mvec());
}

void onyx::math::Mat4x4::rotate(float degrees, const Vec3& mask)
{
	this->mat = glm::rotate(this->mat, radians(degrees), mask.get_mvec());
}

void onyx::math::Mat4x4::scale(const Vec3& xyz_multiplier)
{
	this->mat = glm::scale(this->mat, xyz_multiplier.get_mvec());
}

glm::mat4x4 onyx::math::Mat4x4::get_mmat() const
{
	return this->mat;
}

const float* onyx::math::Mat4x4::data() const
{
	return (float*)(glm::value_ptr(this->mat));
}

std::string onyx::math::Mat4x4::to_string() const
{
	std::string str;
	for (int i = 0; i < 4; i++)
	{
		str += "|";
		for (int j = 0; j < 4; j++)
		{
			str += std::string(this->mat[i][j] < 0 ? "" : " ") + std::to_string(this->mat[i][j]) + " ";
		}
		str += "|\n";
	}

	return str;
}

onyx::math::Vec4 onyx::math::Mat4x4::operator[](int index) const
{
	return Vec4(this->mat[index]);
}

void onyx::math::Mat4x4::operator=(const Mat4x4& mat)
{
	this->mat = mat.mat;
}

onyx::math::Mat4x4 onyx::math::Mat4x4::operator+(const Mat4x4& mat) const
{
	return Mat4x4(this->mat + mat.mat);
}

void onyx::math::Mat4x4::operator+=(const Mat4x4& mat)
{
	this->mat += mat.mat;
}

onyx::math::Mat4x4 onyx::math::Mat4x4::operator-() const
{
	return Mat4x4(-this->mat);
}

onyx::math::Mat4x4 onyx::math::Mat4x4::operator-(const Mat4x4& mat) const
{
	return Mat4x4(this->mat - mat.mat);
}

void onyx::math::Mat4x4::operator-=(const Mat4x4& mat)
{
	this->mat -= mat.mat;
}

onyx::math::Mat4x4 onyx::math::Mat4x4::identity()
{
	return Mat4x4(1.0f);
}

onyx::math::Mat2x2 onyx::math::operator*(const Mat2x2& mat1, const Mat2x2& mat2)
{
	return Mat2x2(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat2x2 onyx::math::operator*(const Mat2x3& mat1, const Mat3x2& mat2)
{
	return Mat2x2(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat2x2 onyx::math::operator*(const Mat2x4& mat1, const Mat4x2& mat2)
{
	return Mat2x2(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat3x3 onyx::math::operator*(const Mat3x2& mat1, const Mat2x3& mat2)
{
	return Mat3x3(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat3x3 onyx::math::operator*(const Mat3x3& mat1, const Mat3x3& mat2)
{
	return Mat3x3(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat3x3 onyx::math::operator*(const Mat3x4& mat1, const Mat4x3& mat2)
{
	return Mat3x3(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat4x4 onyx::math::operator*(const Mat4x2& mat1, const Mat2x4& mat2)
{
	return Mat4x4(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat4x4 onyx::math::operator*(const Mat4x3& mat1, const Mat3x4& mat2)
{
	return Mat4x4(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Mat4x4 onyx::math::operator*(const Mat4x4& mat1, const Mat4x4& mat2)
{
	return Mat4x4(mat1.get_mmat() * mat2.get_mmat());
}

onyx::math::Vec2 onyx::math::operator*(const Mat2x2& mat, const Vec2& vec)
{
	return Vec2(mat.get_mmat() * vec.get_mvec());
}

onyx::math::Vec2 onyx::math::operator*(const Mat2x3& mat, const Vec3& vec)
{
	return Vec2(mat.get_mmat() * vec.get_mvec());
}

onyx::math::Vec2 onyx::math::operator*(const Mat2x4& mat, const Vec4& vec)
{
	return Vec2(mat.get_mmat() * vec.get_mvec());
}

onyx::math::Vec3 onyx::math::operator*(const Mat3x3& mat, const Vec3& vec)
{
	return Vec3(mat.get_mmat() * vec.get_mvec());
}

onyx::math::Vec3 onyx::math::operator*(const Mat3x4& mat, const Vec4& vec)
{
	return Vec3(mat.get_mmat() * vec.get_mvec());
}

onyx::math::Vec4 onyx::math::operator*(const Mat4x4& mat, const Vec4& vec)
{
	return Vec4(mat.get_mmat() * vec.get_mvec());
}

onyx::math::Mat2x2 onyx::math::transpose(const Mat2x2& mat)
{
	return Mat2x2(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat2x3 onyx::math::transpose(const Mat3x2& mat)
{
	return Mat2x3(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat2x4 onyx::math::transpose(const Mat4x2& mat)
{
	return Mat2x4(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat3x2 onyx::math::transpose(const Mat2x3& mat)
{
	return Mat3x2(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat3x3 onyx::math::transpose(const Mat3x3& mat)
{
	return Mat3x3(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat3x4 onyx::math::transpose(const Mat4x3& mat)
{
	return Mat3x4(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat4x2 onyx::math::transpose(const Mat2x4& mat)
{
	return Mat4x2(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat4x3 onyx::math::transpose(const Mat3x4& mat)
{
	return Mat4x3(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat4x4 onyx::math::transpose(const Mat4x4& mat)
{
	return Mat4x4(glm::transpose(mat.get_mmat()));
}

onyx::math::Mat2x2 onyx::math::inverse(const Mat2x2& mat)
{
	return Mat2x2(glm::inverse(mat.get_mmat()));
}

onyx::math::Mat3x3 onyx::math::inverse(const Mat3x3& mat)
{
	return Mat3x3(glm::inverse(mat.get_mmat()));
}

onyx::math::Mat4x4 onyx::math::inverse(const Mat4x4& mat)
{
	return Mat4x4(glm::inverse(mat.get_mmat()));
}

float onyx::math::det(const Mat2x2& mat)
{
	return glm::determinant(mat.get_mmat());
}

float onyx::math::det(const Mat3x3& mat)
{
	return glm::determinant(mat.get_mmat());
}

float onyx::math::det(const Mat4x4& mat)
{
	return glm::determinant(mat.get_mmat());
}

onyx::math::Mat4x4 onyx::math::look_at(const Vec3& pos, const Vec3& target, const Vec3& up)
{
	return Mat4(glm::lookAt(pos.get_mvec(), target.get_mvec(), up.get_mvec()));
}

onyx::math::Mat4x4 onyx::math::orthographic_projection(float left, float right, float top, float bottom)
{
	return Mat4(glm::ortho(left, right, bottom, top));
}

onyx::math::Mat4x4 onyx::math::perspective_projection(float fov, float aspect_ratio, float near_plane, float far_plane)
{
	return Mat4(glm::perspective(glm::radians(fov), aspect_ratio, near_plane, far_plane));
}
