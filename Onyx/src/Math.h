/*
	@file A header file containing wrapper classes for vector and matrix math.
 */

#pragma once

#include <string>

#include <glm/glm.hpp>

typedef unsigned int uint;

namespace Onyx
{

	/*
		@brief A namespace providing access to classes for vector and matrix math.
		These classes are wrapper classes that use GLM for the underlying mathematics.
	 */
	namespace Math
	{
		class Vec;
		class Vec2;
		class Vec3;
		class Vec4;

		class DVec;
		class DVec2;
		class DVec3;
		class DVec4;

		class IVec;
		class IVec2;
		class IVec3;
		class IVec4;

		class UVec;
		class UVec2;
		class UVec3;
		class UVec4;

		/*
			@brief The pi constant.
		 */
		const double PI = 3.14159265358979311599796346854;

		/*
			@brief The tau constant, 2 * pi.
		 */
		const double TAU = 2.0 * PI;

		/*
			@brief Converts a degree angle measure to radians.
			@param degrees The degree angle measure.
			@return The resulting radian angle measure.
		 */
		float Radians(float degrees);

		/*
			@brief Converts a degree angle measure to radians.
			@param degrees The degree angle measure.
			@return The resulting radian angle measure.
		 */
		double Radians(double degrees);

		/*
			@brief Converts a radian angle measure to degrees.
			@param radians The radian angle measure.
			@return The resulting degree angle measure.
		 */
		float Degrees(float radians);

		/*
			@brief Converts a radian angle measure to degrees.
			@param radians The radian angle measure.
			@return The resulting degree angle measure.
		 */
		double Degrees(double radians);

		/*
			@brief Clamps a value between a minimum and maximum value.
			@param value The value to clamp.
			@param min The minimum value.
			@param max The maximum value.
		 */
		float Clamp(float value, float min, float max);

		/*
			@brief Clamps a value between a minimum and maximum value.
			@param value The value to clamp.
			@param min The minimum value.
			@param max The maximum value.
		 */
		double Clamp(double value, double min, double max);

		/*
			@brief Remaps a value from a previous range to a new one.
			@param val The value to remap.
			@param oldRange The old range (min, max).
			@param newRange The new range (min, max).
			@return The remapped value.
		 */
		float Remap(float val, Vec2 oldRange, Vec2 newRange);

		/*
			@brief Remaps a value from a previous range to a new one.
			@param val The value to remap.
			@param oldRange The old range (min, max).
			@param newRange The new range (min, max).
			@return The remapped value.
		 */
		double Remap(double val, DVec2 oldRange, DVec2 newRange);

		/*
			@brief Generates a random number, of type T, between a minimum and maximum value, inclusive.
			@param min The minimum value.
			@param max The maximum value.
			@return The random number.
		 */
		template<typename T>
		T Rand(T min, T max)
		{
			static_assert(std::is_arithmetic<T>::value, "Rand can only be used with integral or floating-point types.");
			return min + static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * (max - min);
		}

		int Abs(int val);
		float Abs(float val);
		double Abs(double val);

		float Sqrt(float val);
		double Sqrt(double val);

		float Pow(float base, float exponent);
		double Pow(double base, double exponent);

		float Sin(float val);
		float Cos(float val);
		float Tan(float val);
		float Asin(float val);
		float Acos(float val);
		float Atan(float val);
		float Atan2(float y, float x);

		double Sin(double val);
		double Cos(double val);
		double Tan(double val);
		double Asin(double val);
		double Acos(double val);
		double Atan(double val);
		double Atan2(double y, double x);

		float Sinh(float val);
		float Cosh(float val);
		float Tanh(float val);
		float Asinh(float val);
		float Acosh(float val);
		float Atanh(float val);

		double Sinh(double val);
		double Cosh(double val);
		double Tanh(double val);
		double Asinh(double val);
		double Acosh(double val);
		double Atanh(double val);

		float Floor(float val);
		double Floor(double val);

		float Ceil(float val);
		double Ceil(double val);

		float Round(float val);
		double Round(double val);

		float Trunc(float val);
		double Trunc(double val);

		float Fract(float val);
		double Fract(double val);

		float Mod(float val, float divisor);
		double Mod(double val, double divisor);

		int Min(int val1, int val2);
		float Min(float val1, float val2);
		double Min(double val1, double val2);

		int Max(int val1, int val2);
		float Max(float val1, float val2);
		double Max(double val1, double val2);

		float Lerp(float start, float end, float t);
		double Lerp(double start, double end, double t);

		/*
			@brief A parent class for vectors.
		 */
		class Vec {};


		/*
			@brief A vector with two components.
		 */
		class Vec2 : public Vec
		{
		public:
			Vec2();
			Vec2(float xy);
			Vec2(float x, float y);
			Vec2(const DVec2& vec);
			Vec2(const IVec2& vec);
			Vec2(const UVec2& vec);
			Vec2(const glm::vec2& vec);

			float magnitude() const;
			void normalize();
			const float* data() const;
			bool isZero() const;
			std::string toString() const;

			Vec2 xx() const;
			Vec2 xy() const;
			Vec2 yx() const;
			Vec2 yy() const;

			float getX() const;
			float getY() const;
			const glm::vec2& getMVec() const;
			Vec2 getNormalized() const;

			void setX(float x);
			void setY(float y);
			void set(float x, float y);
			void setMagnitude(float magnitude);

			friend float Dot(const Vec2& vec1, const Vec2& vec2);

			friend bool operator==(const Vec2& vec1, const Vec2& vec2);
			friend bool operator!=(const Vec2& vec1, const Vec2& vec2);

			float operator[](int index) const;

			void operator=(const Vec2& vec);
			Vec2 operator+(const Vec2& vec) const;
			void operator+=(const Vec2& vec);
			Vec2 operator-() const;
			Vec2 operator-(const Vec2& vec) const;
			void operator-=(const Vec2& vec);
			Vec2 operator*(const float& scalar) const;
			void operator*=(const float& scalar);

		private:
			glm::vec2 m_vec;
		};

		/*
			@brief A vector with three components.
		 */
		class Vec3 : public Vec
		{
		public:
			Vec3();
			Vec3(float xyz);
			Vec3(float x, float y, float z);
			Vec3(const Vec2& vec, float z);
			Vec3(float x, const Vec2& vec);
			Vec3(const DVec3& vec);
			Vec3(const IVec3& vec);
			Vec3(const UVec3& vec);
			Vec3(const glm::vec3& vec);

			float magnitude() const;
			void normalize();
			const float* data() const;
			bool isZero() const;
			std::string toString() const;

			Vec2 xx() const;
			Vec2 xy() const;
			Vec2 xz() const;
			Vec2 yx() const;
			Vec2 yy() const;
			Vec2 yz() const;
			Vec2 zx() const;
			Vec2 zy() const;
			Vec2 zz() const;

			Vec3 xxx() const;
			Vec3 xxy() const;
			Vec3 xxz() const;
			Vec3 xyx() const;
			Vec3 xyy() const;
			Vec3 xyz() const;
			Vec3 xzx() const;
			Vec3 xzy() const;
			Vec3 xzz() const;
			Vec3 yxx() const;
			Vec3 yxy() const;
			Vec3 yxz() const;
			Vec3 yyx() const;
			Vec3 yyy() const;
			Vec3 yyz() const;
			Vec3 yzx() const;
			Vec3 yzy() const;
			Vec3 yzz() const;
			Vec3 zxx() const;
			Vec3 zxy() const;
			Vec3 zxz() const;
			Vec3 zyx() const;
			Vec3 zyy() const;
			Vec3 zyz() const;
			Vec3 zzx() const;
			Vec3 zzy() const;
			Vec3 zzz() const;

			float getX() const;
			float getY() const;
			float getZ() const;
			const glm::vec3& getMVec() const;
			Vec3 getNormalized() const;

			void setX(float x);
			void setY(float y);
			void setZ(float z);
			void set(float x, float y, float z);
			void setMagnitude(float magnitude);

			friend Vec3 Cross(const Vec3& vec1, const Vec3& vec2);
			friend float Dot(const Vec3& vec1, const Vec3& vec2);

			friend bool operator==(const Vec3& vec1, const Vec3& vec2);
			friend bool operator!=(const Vec3& vec1, const Vec3& vec2);

			float operator[](int index) const;

			void operator=(const Vec3& vec);
			Vec3 operator+(const Vec3& vec) const;
			void operator+=(const Vec3& vec);
			Vec3 operator-() const;
			Vec3 operator-(const Vec3& vec) const;
			void operator-=(const Vec3& vec);
			Vec3 operator*(const float& scalar) const;
			void operator*=(const float& scalar);

			static Vec3 Red();
			static Vec3 Orange();
			static Vec3 Yellow();
			static Vec3 Green();
			static Vec3 DarkGreen();
			static Vec3 Cyan();
			static Vec3 LightBlue();
			static Vec3 Blue();
			static Vec3 NavyBlue();
			static Vec3 Purple();
			static Vec3 Pink();
			static Vec3 Magenta();
			static Vec3 White();
			static Vec3 LightGray();
			static Vec3 DarkGray();
			static Vec3 Black();
			static Vec3 Brown();

		private:
			glm::vec3 m_vec;
		};

		/*
			@brief A vector with four components.
		 */
		class Vec4 : public Vec
		{
		public:
			Vec4();
			Vec4(float xyzw);
			Vec4(float x, float y, float z, float w);
			Vec4(const Vec2& vec, float z, float w);
			Vec4(float x, const Vec2& vec, float w);
			Vec4(float x, float y, const Vec2& vec);
			Vec4(const Vec3& vec, float w);
			Vec4(float x, const Vec3& vec);
			Vec4(const Vec2& vec1, const Vec2& vec2);
			Vec4(const DVec4& vec);
			Vec4(const IVec4& vec);
			Vec4(const UVec4& vec);
			Vec4(const glm::vec4& vec);

			float magnitude() const;
			void normalize();
			const float* data() const;
			bool isZero() const;
			std::string toString() const;

			Vec2 xx() const;
			Vec2 xy() const;
			Vec2 xz() const;
			Vec2 xw() const;
			Vec2 yx() const;
			Vec2 yy() const;
			Vec2 yz() const;
			Vec2 yw() const;
			Vec2 zx() const;
			Vec2 zy() const;
			Vec2 zz() const;
			Vec2 zw() const;
			Vec2 wx() const;
			Vec2 wy() const;
			Vec2 wz() const;
			Vec2 ww() const;

			Vec3 xxx() const;
			Vec3 xxy() const;
			Vec3 xxz() const;
			Vec3 xxw() const;
			Vec3 xyx() const;
			Vec3 xyy() const;
			Vec3 xyz() const;
			Vec3 xyw() const;
			Vec3 xzx() const;
			Vec3 xzy() const;
			Vec3 xzz() const;
			Vec3 xzw() const;
			Vec3 xwx() const;
			Vec3 xwy() const;
			Vec3 xwz() const;
			Vec3 xww() const;
			Vec3 yxx() const;
			Vec3 yxy() const;
			Vec3 yxz() const;
			Vec3 yxw() const;
			Vec3 yyx() const;
			Vec3 yyy() const;
			Vec3 yyz() const;
			Vec3 yyw() const;
			Vec3 yzx() const;
			Vec3 yzy() const;
			Vec3 yzz() const;
			Vec3 yzw() const;
			Vec3 ywx() const;
			Vec3 ywy() const;
			Vec3 ywz() const;
			Vec3 yww() const;
			Vec3 zxx() const;
			Vec3 zxy() const;
			Vec3 zxz() const;
			Vec3 zxw() const;
			Vec3 zyx() const;
			Vec3 zyy() const;
			Vec3 zyz() const;
			Vec3 zyw() const;
			Vec3 zzx() const;
			Vec3 zzy() const;
			Vec3 zzz() const;
			Vec3 zzw() const;
			Vec3 zwx() const;
			Vec3 zwy() const;
			Vec3 zwz() const;
			Vec3 zww() const;
			Vec3 wxx() const;
			Vec3 wxy() const;
			Vec3 wxz() const;
			Vec3 wxw() const;
			Vec3 wyx() const;
			Vec3 wyy() const;
			Vec3 wyz() const;
			Vec3 wyw() const;
			Vec3 wzx() const;
			Vec3 wzy() const;
			Vec3 wzz() const;
			Vec3 wzw() const;
			Vec3 wwx() const;
			Vec3 wwy() const;
			Vec3 wwz() const;
			Vec3 www() const;

			Vec4 xxxx() const;
			Vec4 xxxy() const;
			Vec4 xxxz() const;
			Vec4 xxxw() const;
			Vec4 xxyx() const;
			Vec4 xxyy() const;
			Vec4 xxyz() const;
			Vec4 xxyw() const;
			Vec4 xxzx() const;
			Vec4 xxzy() const;
			Vec4 xxzz() const;
			Vec4 xxzw() const;
			Vec4 xxwx() const;
			Vec4 xxwy() const;
			Vec4 xxwz() const;
			Vec4 xxww() const;
			Vec4 xyxx() const;
			Vec4 xyxy() const;
			Vec4 xyxz() const;
			Vec4 xyxw() const;
			Vec4 xyyx() const;
			Vec4 xyyy() const;
			Vec4 xyyz() const;
			Vec4 xyyw() const;
			Vec4 xyzx() const;
			Vec4 xyzy() const;
			Vec4 xyzz() const;
			Vec4 xyzw() const;
			Vec4 xywx() const;
			Vec4 xywy() const;
			Vec4 xywz() const;
			Vec4 xyww() const;
			Vec4 xzxx() const;
			Vec4 xzxy() const;
			Vec4 xzxz() const;
			Vec4 xzxw() const;
			Vec4 xzyx() const;
			Vec4 xzyy() const;
			Vec4 xzyz() const;
			Vec4 xzyw() const;
			Vec4 xzzx() const;
			Vec4 xzzy() const;
			Vec4 xzzz() const;
			Vec4 xzzw() const;
			Vec4 xzwx() const;
			Vec4 xzwy() const;
			Vec4 xzwz() const;
			Vec4 xzww() const;
			Vec4 xwxx() const;
			Vec4 xwxy() const;
			Vec4 xwxz() const;
			Vec4 xwxw() const;
			Vec4 xwyx() const;
			Vec4 xwyy() const;
			Vec4 xwyz() const;
			Vec4 xwyw() const;
			Vec4 xwzx() const;
			Vec4 xwzy() const;
			Vec4 xwzz() const;
			Vec4 xwzw() const;
			Vec4 xwwx() const;
			Vec4 xwwy() const;
			Vec4 xwwz() const;
			Vec4 xwww() const;
			Vec4 yxxx() const;
			Vec4 yxxy() const;
			Vec4 yxxz() const;
			Vec4 yxxw() const;
			Vec4 yxyx() const;
			Vec4 yxyy() const;
			Vec4 yxyz() const;
			Vec4 yxyw() const;
			Vec4 yxzx() const;
			Vec4 yxzy() const;
			Vec4 yxzz() const;
			Vec4 yxzw() const;
			Vec4 yxwx() const;
			Vec4 yxwy() const;
			Vec4 yxwz() const;
			Vec4 yxww() const;
			Vec4 yyxx() const;
			Vec4 yyxy() const;
			Vec4 yyxz() const;
			Vec4 yyxw() const;
			Vec4 yyyx() const;
			Vec4 yyyy() const;
			Vec4 yyyz() const;
			Vec4 yyyw() const;
			Vec4 yyzx() const;
			Vec4 yyzy() const;
			Vec4 yyzz() const;
			Vec4 yyzw() const;
			Vec4 yywx() const;
			Vec4 yywy() const;
			Vec4 yywz() const;
			Vec4 yyww() const;
			Vec4 yzxx() const;
			Vec4 yzxy() const;
			Vec4 yzxz() const;
			Vec4 yzxw() const;
			Vec4 yzyx() const;
			Vec4 yzyy() const;
			Vec4 yzyz() const;
			Vec4 yzyw() const;
			Vec4 yzzx() const;
			Vec4 yzzy() const;
			Vec4 yzzz() const;
			Vec4 yzzw() const;
			Vec4 yzwx() const;
			Vec4 yzwy() const;
			Vec4 yzwz() const;
			Vec4 yzww() const;
			Vec4 ywxx() const;
			Vec4 ywxy() const;
			Vec4 ywxz() const;
			Vec4 ywxw() const;
			Vec4 ywyx() const;
			Vec4 ywyy() const;
			Vec4 ywyz() const;
			Vec4 ywyw() const;
			Vec4 ywzx() const;
			Vec4 ywzy() const;
			Vec4 ywzz() const;
			Vec4 ywzw() const;
			Vec4 ywwx() const;
			Vec4 ywwy() const;
			Vec4 ywwz() const;
			Vec4 ywww() const;
			Vec4 zxxx() const;
			Vec4 zxxy() const;
			Vec4 zxxz() const;
			Vec4 zxxw() const;
			Vec4 zxyx() const;
			Vec4 zxyy() const;
			Vec4 zxyz() const;
			Vec4 zxyw() const;
			Vec4 zxzx() const;
			Vec4 zxzy() const;
			Vec4 zxzz() const;
			Vec4 zxzw() const;
			Vec4 zxwx() const;
			Vec4 zxwy() const;
			Vec4 zxwz() const;
			Vec4 zxww() const;
			Vec4 zyxx() const;
			Vec4 zyxy() const;
			Vec4 zyxz() const;
			Vec4 zyxw() const;
			Vec4 zyyx() const;
			Vec4 zyyy() const;
			Vec4 zyyz() const;
			Vec4 zyyw() const;
			Vec4 zyzx() const;
			Vec4 zyzy() const;
			Vec4 zyzz() const;
			Vec4 zyzw() const;
			Vec4 zywx() const;
			Vec4 zywy() const;
			Vec4 zywz() const;
			Vec4 zyww() const;
			Vec4 zzxx() const;
			Vec4 zzxy() const;
			Vec4 zzxz() const;
			Vec4 zzxw() const;
			Vec4 zzyx() const;
			Vec4 zzyy() const;
			Vec4 zzyz() const;
			Vec4 zzyw() const;
			Vec4 zzzx() const;
			Vec4 zzzy() const;
			Vec4 zzzz() const;
			Vec4 zzzw() const;
			Vec4 zzwx() const;
			Vec4 zzwy() const;
			Vec4 zzwz() const;
			Vec4 zzww() const;
			Vec4 zwxx() const;
			Vec4 zwxy() const;
			Vec4 zwxz() const;
			Vec4 zwxw() const;
			Vec4 zwyx() const;
			Vec4 zwyy() const;
			Vec4 zwyz() const;
			Vec4 zwyw() const;
			Vec4 zwzx() const;
			Vec4 zwzy() const;
			Vec4 zwzz() const;
			Vec4 zwzw() const;
			Vec4 zwwx() const;
			Vec4 zwwy() const;
			Vec4 zwwz() const;
			Vec4 zwww() const;
			Vec4 wxxx() const;
			Vec4 wxxy() const;
			Vec4 wxxz() const;
			Vec4 wxxw() const;
			Vec4 wxyx() const;
			Vec4 wxyy() const;
			Vec4 wxyz() const;
			Vec4 wxyw() const;
			Vec4 wxzx() const;
			Vec4 wxzy() const;
			Vec4 wxzz() const;
			Vec4 wxzw() const;
			Vec4 wxwx() const;
			Vec4 wxwy() const;
			Vec4 wxwz() const;
			Vec4 wxww() const;
			Vec4 wyxx() const;
			Vec4 wyxy() const;
			Vec4 wyxz() const;
			Vec4 wyxw() const;
			Vec4 wyyx() const;
			Vec4 wyyy() const;
			Vec4 wyyz() const;
			Vec4 wyyw() const;
			Vec4 wyzx() const;
			Vec4 wyzy() const;
			Vec4 wyzz() const;
			Vec4 wyzw() const;
			Vec4 wywx() const;
			Vec4 wywy() const;
			Vec4 wywz() const;
			Vec4 wyww() const;
			Vec4 wzxx() const;
			Vec4 wzxy() const;
			Vec4 wzxz() const;
			Vec4 wzxw() const;
			Vec4 wzyx() const;
			Vec4 wzyy() const;
			Vec4 wzyz() const;
			Vec4 wzyw() const;
			Vec4 wzzx() const;
			Vec4 wzzy() const;
			Vec4 wzzz() const;
			Vec4 wzzw() const;
			Vec4 wzwx() const;
			Vec4 wzwy() const;
			Vec4 wzwz() const;
			Vec4 wzww() const;
			Vec4 wwxx() const;
			Vec4 wwxy() const;
			Vec4 wwxz() const;
			Vec4 wwxw() const;
			Vec4 wwyx() const;
			Vec4 wwyy() const;
			Vec4 wwyz() const;
			Vec4 wwyw() const;
			Vec4 wwzx() const;
			Vec4 wwzy() const;
			Vec4 wwzz() const;
			Vec4 wwzw() const;
			Vec4 wwwx() const;
			Vec4 wwwy() const;
			Vec4 wwwz() const;
			Vec4 wwww() const;

			float getX() const;
			float getY() const;
			float getZ() const;
			float getW() const;
			const glm::vec4& getMVec() const;
			Vec4 getNormalized() const;

			void setX(float x);
			void setY(float y);
			void setZ(float z);
			void setW(float w);
			void set(float x, float y, float z, float w);
			void setMagnitude(float magnitude);

			friend float Dot(const Vec4& vec1, const Vec4& vec2);

			friend bool operator==(const Vec4& vec1, const Vec4& vec2);
			friend bool operator!=(const Vec4& vec1, const Vec4& vec2);

			float operator[](int index) const;

			void operator=(const Vec4& vec);
			Vec4 operator+(const Vec4& vec) const;
			void operator+=(const Vec4& vec);
			Vec4 operator-() const;
			Vec4 operator-(const Vec4& vec) const;
			void operator-=(const Vec4& vec);
			Vec4 operator*(const float& scalar) const;
			void operator*=(const float& scalar);

			static Vec4 Red(float alpha = 1.0f);
			static Vec4 Orange(float alpha = 1.0f);
			static Vec4 Yellow(float alpha = 1.0f);
			static Vec4 Green(float alpha = 1.0f);
			static Vec4 DarkGreen(float alpha = 1.0f);
			static Vec4 Cyan(float alpha = 1.0f);
			static Vec4 LightBlue(float alpha = 1.0f);
			static Vec4 Blue(float alpha = 1.0f);
			static Vec4 NavyBlue(float alpha = 1.0f);
			static Vec4 Purple(float alpha = 1.0f);
			static Vec4 Pink(float alpha = 1.0f);
			static Vec4 Magenta(float alpha = 1.0f);
			static Vec4 White(float alpha = 1.0f);
			static Vec4 LightGray(float alpha = 1.0f);
			static Vec4 DarkGray(float alpha = 1.0f);
			static Vec4 Black(float alpha = 1.0f);
			static Vec4 Brown(float alpha = 1.0f);

		private:
			glm::vec4 m_vec;
		};

		Vec2 Rotate(const Vec2& vec, float angle);
		Vec3 Rotate(const Vec3& vec, float angle, const Vec3& mask);
		Vec3 Rotate(const Vec3& vec, const Vec3& angles);

		Vec2 Reflect(const Vec2& vec, const Vec2& normal);
		Vec3 Reflect(const Vec3& vec, const Vec3& normal);
		Vec4 Reflect(const Vec4& vec, const Vec4& normal);



		/*
			@brief A parent class for double vectors.
		 */
		class DVec : public Vec {};

		/*
			@brief A double vector with two components.
		 */
		class DVec2 : public DVec
		{
		public:
			DVec2();
			DVec2(double xy);
			DVec2(double x, double y);
			DVec2(const Vec2& vec);
			DVec2(const IVec2& vec);
			DVec2(const UVec2& vec);
			DVec2(const glm::dvec2& vec);

			double magnitude() const;
			void normalize();
			const double* data() const;
			bool isZero() const;
			std::string toString() const;

			DVec2 xx() const;
			DVec2 xy() const;
			DVec2 yx() const;
			DVec2 yy() const;

			double getX() const;
			double getY() const;
			const glm::dvec2& getMVec() const;
			DVec2 getNormalized() const;

			void setX(double x);
			void setY(double y);
			void set(double x, double y);
			void setMagnitude(double magnitude);

			friend double Dot(const DVec2& vec1, const DVec2& vec2);

			friend bool operator==(const DVec2& vec1, const DVec2& vec2);
			friend bool operator!=(const DVec2& vec1, const DVec2& vec2);

			double operator[](int index) const;

			void operator=(const DVec2& vec);
			DVec2 operator+(const DVec2& vec) const;
			void operator+=(const DVec2& vec);
			DVec2 operator-() const;
			DVec2 operator-(const DVec2& vec) const;
			void operator-=(const DVec2& vec);
			DVec2 operator*(const double& scalar) const;
			void operator*=(const double& scalar);

		private:
			glm::dvec2 m_vec;
		};

		/*
			@brief A double vector with three components.
		 */
		class DVec3 : public DVec
		{
		public:
			DVec3();
			DVec3(double xyz);
			DVec3(double x, double y, double z);
			DVec3(const DVec2& vec, double z);
			DVec3(double x, const DVec2& vec);
			DVec3(const Vec3& vec);
			DVec3(const IVec3& vec);
			DVec3(const UVec3& vec);
			DVec3(const glm::dvec3& vec);

			double magnitude() const;
			void normalize();
			const double* data() const;
			bool isZero() const;
			std::string toString() const;

			DVec2 xx() const;
			DVec2 xy() const;
			DVec2 xz() const;
			DVec2 yx() const;
			DVec2 yy() const;
			DVec2 yz() const;
			DVec2 zx() const;
			DVec2 zy() const;
			DVec2 zz() const;

			DVec3 xxx() const;
			DVec3 xxy() const;
			DVec3 xxz() const;
			DVec3 xyx() const;
			DVec3 xyy() const;
			DVec3 xyz() const;
			DVec3 xzx() const;
			DVec3 xzy() const;
			DVec3 xzz() const;
			DVec3 yxx() const;
			DVec3 yxy() const;
			DVec3 yxz() const;
			DVec3 yyx() const;
			DVec3 yyy() const;
			DVec3 yyz() const;
			DVec3 yzx() const;
			DVec3 yzy() const;
			DVec3 yzz() const;
			DVec3 zxx() const;
			DVec3 zxy() const;
			DVec3 zxz() const;
			DVec3 zyx() const;
			DVec3 zyy() const;
			DVec3 zyz() const;
			DVec3 zzx() const;
			DVec3 zzy() const;
			DVec3 zzz() const;

			double getX() const;
			double getY() const;
			double getZ() const;
			const glm::dvec3& getMVec() const;
			DVec3 getNormalized() const;

			void setX(double x);
			void setY(double y);
			void setZ(double z);
			void set(double x, double y, double z);
			void setMagnitude(double magnitude);

			friend DVec3 Cross(const DVec3& vec1, const DVec3& vec2);
			friend double Dot(const DVec3& vec1, const DVec3& vec2);

			friend bool operator==(const DVec3& vec1, const DVec3& vec2);
			friend bool operator!=(const DVec3& vec1, const DVec3& vec2);

			double operator[](int index) const;

			void operator=(const DVec3& vec);
			DVec3 operator+(const DVec3& vec) const;
			void operator+=(const DVec3& vec);
			DVec3 operator-() const;
			DVec3 operator-(const DVec3& vec) const;
			void operator-=(const DVec3& vec);
			DVec3 operator*(const double& scalar) const;
			void operator*=(const double& scalar);

		private:
			glm::dvec3 m_vec;
		};

		/*
			@brief Calculates the reflection of a vector off a surface that has the specified normal.
			@param vec The vector to reflect.
			@param normal The normal of the surface.
			@return The reflected vector.
		 */
		DVec3 Reflect(const DVec3& vec, const DVec3& normal);

		/*
			@brief A double vector with four components.
		 */
		class DVec4 : public DVec
		{
		public:
			DVec4();
			DVec4(double xyzw);
			DVec4(double x, double y, double z, double w);
			DVec4(const DVec2& vec, double z, double w);
			DVec4(double x, const DVec2& vec, double w);
			DVec4(double x, double y, const DVec2& vec);
			DVec4(const DVec3& vec, double w);
			DVec4(double x, const DVec3& vec);
			DVec4(const DVec2& vec1, const DVec2& vec2);
			DVec4(const Vec4& vec);
			DVec4(const IVec4& vec);
			DVec4(const UVec4& vec);
			DVec4(const glm::dvec4& vec);

			double magnitude() const;
			void normalize();
			const double* data() const;
			bool isZero() const;
			std::string toString() const;

			DVec2 xx() const;
			DVec2 xy() const;
			DVec2 xz() const;
			DVec2 xw() const;
			DVec2 yx() const;
			DVec2 yy() const;
			DVec2 yz() const;
			DVec2 yw() const;
			DVec2 zx() const;
			DVec2 zy() const;
			DVec2 zz() const;
			DVec2 zw() const;
			DVec2 wx() const;
			DVec2 wy() const;
			DVec2 wz() const;
			DVec2 ww() const;

			DVec3 xxx() const;
			DVec3 xxy() const;
			DVec3 xxz() const;
			DVec3 xxw() const;
			DVec3 xyx() const;
			DVec3 xyy() const;
			DVec3 xyz() const;
			DVec3 xyw() const;
			DVec3 xzx() const;
			DVec3 xzy() const;
			DVec3 xzz() const;
			DVec3 xzw() const;
			DVec3 xwx() const;
			DVec3 xwy() const;
			DVec3 xwz() const;
			DVec3 xww() const;
			DVec3 yxx() const;
			DVec3 yxy() const;
			DVec3 yxz() const;
			DVec3 yxw() const;
			DVec3 yyx() const;
			DVec3 yyy() const;
			DVec3 yyz() const;
			DVec3 yyw() const;
			DVec3 yzx() const;
			DVec3 yzy() const;
			DVec3 yzz() const;
			DVec3 yzw() const;
			DVec3 ywx() const;
			DVec3 ywy() const;
			DVec3 ywz() const;
			DVec3 yww() const;
			DVec3 zxx() const;
			DVec3 zxy() const;
			DVec3 zxz() const;
			DVec3 zxw() const;
			DVec3 zyx() const;
			DVec3 zyy() const;
			DVec3 zyz() const;
			DVec3 zyw() const;
			DVec3 zzx() const;
			DVec3 zzy() const;
			DVec3 zzz() const;
			DVec3 zzw() const;
			DVec3 zwx() const;
			DVec3 zwy() const;
			DVec3 zwz() const;
			DVec3 zww() const;
			DVec3 wxx() const;
			DVec3 wxy() const;
			DVec3 wxz() const;
			DVec3 wxw() const;
			DVec3 wyx() const;
			DVec3 wyy() const;
			DVec3 wyz() const;
			DVec3 wyw() const;
			DVec3 wzx() const;
			DVec3 wzy() const;
			DVec3 wzz() const;
			DVec3 wzw() const;
			DVec3 wwx() const;
			DVec3 wwy() const;
			DVec3 wwz() const;
			DVec3 www() const;

			DVec4 xxxx() const;
			DVec4 xxxy() const;
			DVec4 xxxz() const;
			DVec4 xxxw() const;
			DVec4 xxyx() const;
			DVec4 xxyy() const;
			DVec4 xxyz() const;
			DVec4 xxyw() const;
			DVec4 xxzx() const;
			DVec4 xxzy() const;
			DVec4 xxzz() const;
			DVec4 xxzw() const;
			DVec4 xxwx() const;
			DVec4 xxwy() const;
			DVec4 xxwz() const;
			DVec4 xxww() const;
			DVec4 xyxx() const;
			DVec4 xyxy() const;
			DVec4 xyxz() const;
			DVec4 xyxw() const;
			DVec4 xyyx() const;
			DVec4 xyyy() const;
			DVec4 xyyz() const;
			DVec4 xyyw() const;
			DVec4 xyzx() const;
			DVec4 xyzy() const;
			DVec4 xyzz() const;
			DVec4 xyzw() const;
			DVec4 xywx() const;
			DVec4 xywy() const;
			DVec4 xywz() const;
			DVec4 xyww() const;
			DVec4 xzxx() const;
			DVec4 xzxy() const;
			DVec4 xzxz() const;
			DVec4 xzxw() const;
			DVec4 xzyx() const;
			DVec4 xzyy() const;
			DVec4 xzyz() const;
			DVec4 xzyw() const;
			DVec4 xzzx() const;
			DVec4 xzzy() const;
			DVec4 xzzz() const;
			DVec4 xzzw() const;
			DVec4 xzwx() const;
			DVec4 xzwy() const;
			DVec4 xzwz() const;
			DVec4 xzww() const;
			DVec4 xwxx() const;
			DVec4 xwxy() const;
			DVec4 xwxz() const;
			DVec4 xwxw() const;
			DVec4 xwyx() const;
			DVec4 xwyy() const;
			DVec4 xwyz() const;
			DVec4 xwyw() const;
			DVec4 xwzx() const;
			DVec4 xwzy() const;
			DVec4 xwzz() const;
			DVec4 xwzw() const;
			DVec4 xwwx() const;
			DVec4 xwwy() const;
			DVec4 xwwz() const;
			DVec4 xwww() const;
			DVec4 yxxx() const;
			DVec4 yxxy() const;
			DVec4 yxxz() const;
			DVec4 yxxw() const;
			DVec4 yxyx() const;
			DVec4 yxyy() const;
			DVec4 yxyz() const;
			DVec4 yxyw() const;
			DVec4 yxzx() const;
			DVec4 yxzy() const;
			DVec4 yxzz() const;
			DVec4 yxzw() const;
			DVec4 yxwx() const;
			DVec4 yxwy() const;
			DVec4 yxwz() const;
			DVec4 yxww() const;
			DVec4 yyxx() const;
			DVec4 yyxy() const;
			DVec4 yyxz() const;
			DVec4 yyxw() const;
			DVec4 yyyx() const;
			DVec4 yyyy() const;
			DVec4 yyyz() const;
			DVec4 yyyw() const;
			DVec4 yyzx() const;
			DVec4 yyzy() const;
			DVec4 yyzz() const;
			DVec4 yyzw() const;
			DVec4 yywx() const;
			DVec4 yywy() const;
			DVec4 yywz() const;
			DVec4 yyww() const;
			DVec4 yzxx() const;
			DVec4 yzxy() const;
			DVec4 yzxz() const;
			DVec4 yzxw() const;
			DVec4 yzyx() const;
			DVec4 yzyy() const;
			DVec4 yzyz() const;
			DVec4 yzyw() const;
			DVec4 yzzx() const;
			DVec4 yzzy() const;
			DVec4 yzzz() const;
			DVec4 yzzw() const;
			DVec4 yzwx() const;
			DVec4 yzwy() const;
			DVec4 yzwz() const;
			DVec4 yzww() const;
			DVec4 ywxx() const;
			DVec4 ywxy() const;
			DVec4 ywxz() const;
			DVec4 ywxw() const;
			DVec4 ywyx() const;
			DVec4 ywyy() const;
			DVec4 ywyz() const;
			DVec4 ywyw() const;
			DVec4 ywzx() const;
			DVec4 ywzy() const;
			DVec4 ywzz() const;
			DVec4 ywzw() const;
			DVec4 ywwx() const;
			DVec4 ywwy() const;
			DVec4 ywwz() const;
			DVec4 ywww() const;
			DVec4 zxxx() const;
			DVec4 zxxy() const;
			DVec4 zxxz() const;
			DVec4 zxxw() const;
			DVec4 zxyx() const;
			DVec4 zxyy() const;
			DVec4 zxyz() const;
			DVec4 zxyw() const;
			DVec4 zxzx() const;
			DVec4 zxzy() const;
			DVec4 zxzz() const;
			DVec4 zxzw() const;
			DVec4 zxwx() const;
			DVec4 zxwy() const;
			DVec4 zxwz() const;
			DVec4 zxww() const;
			DVec4 zyxx() const;
			DVec4 zyxy() const;
			DVec4 zyxz() const;
			DVec4 zyxw() const;
			DVec4 zyyx() const;
			DVec4 zyyy() const;
			DVec4 zyyz() const;
			DVec4 zyyw() const;
			DVec4 zyzx() const;
			DVec4 zyzy() const;
			DVec4 zyzz() const;
			DVec4 zyzw() const;
			DVec4 zywx() const;
			DVec4 zywy() const;
			DVec4 zywz() const;
			DVec4 zyww() const;
			DVec4 zzxx() const;
			DVec4 zzxy() const;
			DVec4 zzxz() const;
			DVec4 zzxw() const;
			DVec4 zzyx() const;
			DVec4 zzyy() const;
			DVec4 zzyz() const;
			DVec4 zzyw() const;
			DVec4 zzzx() const;
			DVec4 zzzy() const;
			DVec4 zzzz() const;
			DVec4 zzzw() const;
			DVec4 zzwx() const;
			DVec4 zzwy() const;
			DVec4 zzwz() const;
			DVec4 zzww() const;
			DVec4 zwxx() const;
			DVec4 zwxy() const;
			DVec4 zwxz() const;
			DVec4 zwxw() const;
			DVec4 zwyx() const;
			DVec4 zwyy() const;
			DVec4 zwyz() const;
			DVec4 zwyw() const;
			DVec4 zwzx() const;
			DVec4 zwzy() const;
			DVec4 zwzz() const;
			DVec4 zwzw() const;
			DVec4 zwwx() const;
			DVec4 zwwy() const;
			DVec4 zwwz() const;
			DVec4 zwww() const;
			DVec4 wxxx() const;
			DVec4 wxxy() const;
			DVec4 wxxz() const;
			DVec4 wxxw() const;
			DVec4 wxyx() const;
			DVec4 wxyy() const;
			DVec4 wxyz() const;
			DVec4 wxyw() const;
			DVec4 wxzx() const;
			DVec4 wxzy() const;
			DVec4 wxzz() const;
			DVec4 wxzw() const;
			DVec4 wxwx() const;
			DVec4 wxwy() const;
			DVec4 wxwz() const;
			DVec4 wxww() const;
			DVec4 wyxx() const;
			DVec4 wyxy() const;
			DVec4 wyxz() const;
			DVec4 wyxw() const;
			DVec4 wyyx() const;
			DVec4 wyyy() const;
			DVec4 wyyz() const;
			DVec4 wyyw() const;
			DVec4 wyzx() const;
			DVec4 wyzy() const;
			DVec4 wyzz() const;
			DVec4 wyzw() const;
			DVec4 wywx() const;
			DVec4 wywy() const;
			DVec4 wywz() const;
			DVec4 wyww() const;
			DVec4 wzxx() const;
			DVec4 wzxy() const;
			DVec4 wzxz() const;
			DVec4 wzxw() const;
			DVec4 wzyx() const;
			DVec4 wzyy() const;
			DVec4 wzyz() const;
			DVec4 wzyw() const;
			DVec4 wzzx() const;
			DVec4 wzzy() const;
			DVec4 wzzz() const;
			DVec4 wzzw() const;
			DVec4 wzwx() const;
			DVec4 wzwy() const;
			DVec4 wzwz() const;
			DVec4 wzww() const;
			DVec4 wwxx() const;
			DVec4 wwxy() const;
			DVec4 wwxz() const;
			DVec4 wwxw() const;
			DVec4 wwyx() const;
			DVec4 wwyy() const;
			DVec4 wwyz() const;
			DVec4 wwyw() const;
			DVec4 wwzx() const;
			DVec4 wwzy() const;
			DVec4 wwzz() const;
			DVec4 wwzw() const;
			DVec4 wwwx() const;
			DVec4 wwwy() const;
			DVec4 wwwz() const;
			DVec4 wwww() const;

			double getX() const;
			double getY() const;
			double getZ() const;
			double getW() const;
			const glm::dvec4& getMVec() const;
			DVec4 getNormalized() const;
			void set(double x, double y, double z, double w);
			void setMagnitude(double magnitude);

			void setX(double x);
			void setY(double y);
			void setZ(double z);
			void setW(double w);

			friend double Dot(const DVec4& vec1, const DVec4& vec2);

			friend bool operator==(const DVec4& vec1, const DVec4& vec2);
			friend bool operator!=(const DVec4& vec1, const DVec4& vec2);

			double operator[](int index) const;

			void operator=(const DVec4& vec);
			DVec4 operator+(const DVec4& vec) const;
			void operator+=(const DVec4& vec);
			DVec4 operator-() const;
			DVec4 operator-(const DVec4& vec) const;
			void operator-=(const DVec4& vec);
			DVec4 operator*(const double& scalar) const;
			void operator*=(const double& scalar);

		private:
			glm::dvec4 m_vec;
		};

		DVec2 Rotate(const DVec2& vec, double angle);
		DVec3 Rotate(const DVec3& vec, double angle, const DVec3& mask);
		DVec3 Rotate(const DVec3& vec, const DVec3& angles);

		DVec2 Reflect(const DVec2& vec, const DVec2& normal);
		DVec3 Reflect(const DVec3& vec, const DVec3& normal);
		DVec4 Reflect(const DVec4& vec, const DVec4& normal);

		/*
			@brief A parent class for integer vectors.
		 */
		class IVec : public Vec {};

		/*
			@brief An integer vector with two components.
		 */
		class IVec2 : public IVec
		{
		public:
			IVec2();
			IVec2(int xy);
			IVec2(int x, int y);
			IVec2(const Vec2& vec);
			IVec2(const DVec2& vec);
			IVec2(const UVec2& vec);
			IVec2(const glm::ivec2& vec);

			const int* data() const;
			bool isZero() const;
			std::string toString() const;

			IVec2 xx() const;
			IVec2 xy() const;
			IVec2 yx() const;
			IVec2 yy() const;

			int getX() const;
			int getY() const;
			const glm::ivec2& getMVec() const;

			void setX(int x);
			void setY(int y);
			void set(int x, int y);

			friend bool operator==(const IVec2& vec1, const IVec2& vec2);
			friend bool operator!=(const IVec2& vec1, const IVec2& vec2);

			int operator[](int index) const;

			void operator=(const IVec2& vec);
			IVec2 operator+(const IVec2& vec) const;
			void operator+=(const IVec2& vec);
			IVec2 operator-() const;
			IVec2 operator-(const IVec2& vec) const;
			void operator-=(const IVec2& vec);
			IVec2 operator*(const int& scalar) const;
			void operator*=(const int& scalar);

		private:
			glm::ivec2 m_vec;
		};

		/*
			@brief An integer vector with three components.
		 */
		class IVec3 : public IVec
		{
		public:
			IVec3();
			IVec3(int xyz);
			IVec3(int x, int y, int z);
			IVec3(const IVec2& vec, int z);
			IVec3(int x, const IVec2& vec);
			IVec3(const Vec3& vec);
			IVec3(const DVec3& vec);
			IVec3(const UVec3& vec);
			IVec3(const glm::ivec3& vec);

			const int* data() const;
			bool isZero() const;
			std::string toString() const;

			IVec2 xx() const;
			IVec2 xy() const;
			IVec2 xz() const;
			IVec2 yx() const;
			IVec2 yy() const;
			IVec2 yz() const;
			IVec2 zx() const;
			IVec2 zy() const;
			IVec2 zz() const;

			IVec3 xxx() const;
			IVec3 xxy() const;
			IVec3 xxz() const;
			IVec3 xyx() const;
			IVec3 xyy() const;
			IVec3 xyz() const;
			IVec3 xzx() const;
			IVec3 xzy() const;
			IVec3 xzz() const;
			IVec3 yxx() const;
			IVec3 yxy() const;
			IVec3 yxz() const;
			IVec3 yyx() const;
			IVec3 yyy() const;
			IVec3 yyz() const;
			IVec3 yzx() const;
			IVec3 yzy() const;
			IVec3 yzz() const;
			IVec3 zxx() const;
			IVec3 zxy() const;
			IVec3 zxz() const;
			IVec3 zyx() const;
			IVec3 zyy() const;
			IVec3 zyz() const;
			IVec3 zzx() const;
			IVec3 zzy() const;
			IVec3 zzz() const;

			int getX() const;
			int getY() const;
			int getZ() const;
			const glm::ivec3& getMVec() const;

			void setX(int x);
			void setY(int y);
			void setZ(int z);
			void set(int x, int y, int z);

			friend bool operator==(const IVec3& vec1, const IVec3& vec2);
			friend bool operator!=(const IVec3& vec1, const IVec3& vec2);

			int operator[](int index) const;

			void operator=(const IVec3& vec);
			IVec3 operator+(const IVec3& vec) const;
			void operator+=(const IVec3& vec);
			IVec3 operator-() const;
			IVec3 operator-(const IVec3& vec) const;
			void operator-=(const IVec3& vec);
			IVec3 operator*(const int& scalar) const;
			void operator*=(const int& scalar);

		private:
			glm::ivec3 m_vec;
		};

		/*
			@brief An integer vector with four components.
		 */
		class IVec4 : public IVec
		{
		public:
			IVec4();
			IVec4(int xyzw);
			IVec4(int x, int y, int z, int w);
			IVec4(const IVec2& vec, int z, int w);
			IVec4(int x, const IVec2& vec, int w);
			IVec4(int x, int y, const IVec2& vec);
			IVec4(const IVec3& vec, int w);
			IVec4(int x, const IVec3& vec);
			IVec4(const IVec2& vec1, const IVec2& vec2);
			IVec4(const Vec4& vec);
			IVec4(const DVec4& vec);
			IVec4(const UVec4& vec);
			IVec4(const glm::ivec4& vec);

			const int* data() const;
			bool isZero() const;
			std::string toString() const;

			IVec2 xx() const;
			IVec2 xy() const;
			IVec2 xz() const;
			IVec2 xw() const;
			IVec2 yx() const;
			IVec2 yy() const;
			IVec2 yz() const;
			IVec2 yw() const;
			IVec2 zx() const;
			IVec2 zy() const;
			IVec2 zz() const;
			IVec2 zw() const;
			IVec2 wx() const;
			IVec2 wy() const;
			IVec2 wz() const;
			IVec2 ww() const;

			IVec3 xxx() const;
			IVec3 xxy() const;
			IVec3 xxz() const;
			IVec3 xxw() const;
			IVec3 xyx() const;
			IVec3 xyy() const;
			IVec3 xyz() const;
			IVec3 xyw() const;
			IVec3 xzx() const;
			IVec3 xzy() const;
			IVec3 xzz() const;
			IVec3 xzw() const;
			IVec3 xwx() const;
			IVec3 xwy() const;
			IVec3 xwz() const;
			IVec3 xww() const;
			IVec3 yxx() const;
			IVec3 yxy() const;
			IVec3 yxz() const;
			IVec3 yxw() const;
			IVec3 yyx() const;
			IVec3 yyy() const;
			IVec3 yyz() const;
			IVec3 yyw() const;
			IVec3 yzx() const;
			IVec3 yzy() const;
			IVec3 yzz() const;
			IVec3 yzw() const;
			IVec3 ywx() const;
			IVec3 ywy() const;
			IVec3 ywz() const;
			IVec3 yww() const;
			IVec3 zxx() const;
			IVec3 zxy() const;
			IVec3 zxz() const;
			IVec3 zxw() const;
			IVec3 zyx() const;
			IVec3 zyy() const;
			IVec3 zyz() const;
			IVec3 zyw() const;
			IVec3 zzx() const;
			IVec3 zzy() const;
			IVec3 zzz() const;
			IVec3 zzw() const;
			IVec3 zwx() const;
			IVec3 zwy() const;
			IVec3 zwz() const;
			IVec3 zww() const;
			IVec3 wxx() const;
			IVec3 wxy() const;
			IVec3 wxz() const;
			IVec3 wxw() const;
			IVec3 wyx() const;
			IVec3 wyy() const;
			IVec3 wyz() const;
			IVec3 wyw() const;
			IVec3 wzx() const;
			IVec3 wzy() const;
			IVec3 wzz() const;
			IVec3 wzw() const;
			IVec3 wwx() const;
			IVec3 wwy() const;
			IVec3 wwz() const;
			IVec3 www() const;

			IVec4 xxxx() const;
			IVec4 xxxy() const;
			IVec4 xxxz() const;
			IVec4 xxxw() const;
			IVec4 xxyx() const;
			IVec4 xxyy() const;
			IVec4 xxyz() const;
			IVec4 xxyw() const;
			IVec4 xxzx() const;
			IVec4 xxzy() const;
			IVec4 xxzz() const;
			IVec4 xxzw() const;
			IVec4 xxwx() const;
			IVec4 xxwy() const;
			IVec4 xxwz() const;
			IVec4 xxww() const;
			IVec4 xyxx() const;
			IVec4 xyxy() const;
			IVec4 xyxz() const;
			IVec4 xyxw() const;
			IVec4 xyyx() const;
			IVec4 xyyy() const;
			IVec4 xyyz() const;
			IVec4 xyyw() const;
			IVec4 xyzx() const;
			IVec4 xyzy() const;
			IVec4 xyzz() const;
			IVec4 xyzw() const;
			IVec4 xywx() const;
			IVec4 xywy() const;
			IVec4 xywz() const;
			IVec4 xyww() const;
			IVec4 xzxx() const;
			IVec4 xzxy() const;
			IVec4 xzxz() const;
			IVec4 xzxw() const;
			IVec4 xzyx() const;
			IVec4 xzyy() const;
			IVec4 xzyz() const;
			IVec4 xzyw() const;
			IVec4 xzzx() const;
			IVec4 xzzy() const;
			IVec4 xzzz() const;
			IVec4 xzzw() const;
			IVec4 xzwx() const;
			IVec4 xzwy() const;
			IVec4 xzwz() const;
			IVec4 xzww() const;
			IVec4 xwxx() const;
			IVec4 xwxy() const;
			IVec4 xwxz() const;
			IVec4 xwxw() const;
			IVec4 xwyx() const;
			IVec4 xwyy() const;
			IVec4 xwyz() const;
			IVec4 xwyw() const;
			IVec4 xwzx() const;
			IVec4 xwzy() const;
			IVec4 xwzz() const;
			IVec4 xwzw() const;
			IVec4 xwwx() const;
			IVec4 xwwy() const;
			IVec4 xwwz() const;
			IVec4 xwww() const;
			IVec4 yxxx() const;
			IVec4 yxxy() const;
			IVec4 yxxz() const;
			IVec4 yxxw() const;
			IVec4 yxyx() const;
			IVec4 yxyy() const;
			IVec4 yxyz() const;
			IVec4 yxyw() const;
			IVec4 yxzx() const;
			IVec4 yxzy() const;
			IVec4 yxzz() const;
			IVec4 yxzw() const;
			IVec4 yxwx() const;
			IVec4 yxwy() const;
			IVec4 yxwz() const;
			IVec4 yxww() const;
			IVec4 yyxx() const;
			IVec4 yyxy() const;
			IVec4 yyxz() const;
			IVec4 yyxw() const;
			IVec4 yyyx() const;
			IVec4 yyyy() const;
			IVec4 yyyz() const;
			IVec4 yyyw() const;
			IVec4 yyzx() const;
			IVec4 yyzy() const;
			IVec4 yyzz() const;
			IVec4 yyzw() const;
			IVec4 yywx() const;
			IVec4 yywy() const;
			IVec4 yywz() const;
			IVec4 yyww() const;
			IVec4 yzxx() const;
			IVec4 yzxy() const;
			IVec4 yzxz() const;
			IVec4 yzxw() const;
			IVec4 yzyx() const;
			IVec4 yzyy() const;
			IVec4 yzyz() const;
			IVec4 yzyw() const;
			IVec4 yzzx() const;
			IVec4 yzzy() const;
			IVec4 yzzz() const;
			IVec4 yzzw() const;
			IVec4 yzwx() const;
			IVec4 yzwy() const;
			IVec4 yzwz() const;
			IVec4 yzww() const;
			IVec4 ywxx() const;
			IVec4 ywxy() const;
			IVec4 ywxz() const;
			IVec4 ywxw() const;
			IVec4 ywyx() const;
			IVec4 ywyy() const;
			IVec4 ywyz() const;
			IVec4 ywyw() const;
			IVec4 ywzx() const;
			IVec4 ywzy() const;
			IVec4 ywzz() const;
			IVec4 ywzw() const;
			IVec4 ywwx() const;
			IVec4 ywwy() const;
			IVec4 ywwz() const;
			IVec4 ywww() const;
			IVec4 zxxx() const;
			IVec4 zxxy() const;
			IVec4 zxxz() const;
			IVec4 zxxw() const;
			IVec4 zxyx() const;
			IVec4 zxyy() const;
			IVec4 zxyz() const;
			IVec4 zxyw() const;
			IVec4 zxzx() const;
			IVec4 zxzy() const;
			IVec4 zxzz() const;
			IVec4 zxzw() const;
			IVec4 zxwx() const;
			IVec4 zxwy() const;
			IVec4 zxwz() const;
			IVec4 zxww() const;
			IVec4 zyxx() const;
			IVec4 zyxy() const;
			IVec4 zyxz() const;
			IVec4 zyxw() const;
			IVec4 zyyx() const;
			IVec4 zyyy() const;
			IVec4 zyyz() const;
			IVec4 zyyw() const;
			IVec4 zyzx() const;
			IVec4 zyzy() const;
			IVec4 zyzz() const;
			IVec4 zyzw() const;
			IVec4 zywx() const;
			IVec4 zywy() const;
			IVec4 zywz() const;
			IVec4 zyww() const;
			IVec4 zzxx() const;
			IVec4 zzxy() const;
			IVec4 zzxz() const;
			IVec4 zzxw() const;
			IVec4 zzyx() const;
			IVec4 zzyy() const;
			IVec4 zzyz() const;
			IVec4 zzyw() const;
			IVec4 zzzx() const;
			IVec4 zzzy() const;
			IVec4 zzzz() const;
			IVec4 zzzw() const;
			IVec4 zzwx() const;
			IVec4 zzwy() const;
			IVec4 zzwz() const;
			IVec4 zzww() const;
			IVec4 zwxx() const;
			IVec4 zwxy() const;
			IVec4 zwxz() const;
			IVec4 zwxw() const;
			IVec4 zwyx() const;
			IVec4 zwyy() const;
			IVec4 zwyz() const;
			IVec4 zwyw() const;
			IVec4 zwzx() const;
			IVec4 zwzy() const;
			IVec4 zwzz() const;
			IVec4 zwzw() const;
			IVec4 zwwx() const;
			IVec4 zwwy() const;
			IVec4 zwwz() const;
			IVec4 zwww() const;
			IVec4 wxxx() const;
			IVec4 wxxy() const;
			IVec4 wxxz() const;
			IVec4 wxxw() const;
			IVec4 wxyx() const;
			IVec4 wxyy() const;
			IVec4 wxyz() const;
			IVec4 wxyw() const;
			IVec4 wxzx() const;
			IVec4 wxzy() const;
			IVec4 wxzz() const;
			IVec4 wxzw() const;
			IVec4 wxwx() const;
			IVec4 wxwy() const;
			IVec4 wxwz() const;
			IVec4 wxww() const;
			IVec4 wyxx() const;
			IVec4 wyxy() const;
			IVec4 wyxz() const;
			IVec4 wyxw() const;
			IVec4 wyyx() const;
			IVec4 wyyy() const;
			IVec4 wyyz() const;
			IVec4 wyyw() const;
			IVec4 wyzx() const;
			IVec4 wyzy() const;
			IVec4 wyzz() const;
			IVec4 wyzw() const;
			IVec4 wywx() const;
			IVec4 wywy() const;
			IVec4 wywz() const;
			IVec4 wyww() const;
			IVec4 wzxx() const;
			IVec4 wzxy() const;
			IVec4 wzxz() const;
			IVec4 wzxw() const;
			IVec4 wzyx() const;
			IVec4 wzyy() const;
			IVec4 wzyz() const;
			IVec4 wzyw() const;
			IVec4 wzzx() const;
			IVec4 wzzy() const;
			IVec4 wzzz() const;
			IVec4 wzzw() const;
			IVec4 wzwx() const;
			IVec4 wzwy() const;
			IVec4 wzwz() const;
			IVec4 wzww() const;
			IVec4 wwxx() const;
			IVec4 wwxy() const;
			IVec4 wwxz() const;
			IVec4 wwxw() const;
			IVec4 wwyx() const;
			IVec4 wwyy() const;
			IVec4 wwyz() const;
			IVec4 wwyw() const;
			IVec4 wwzx() const;
			IVec4 wwzy() const;
			IVec4 wwzz() const;
			IVec4 wwzw() const;
			IVec4 wwwx() const;
			IVec4 wwwy() const;
			IVec4 wwwz() const;
			IVec4 wwww() const;

			int getX() const;
			int getY() const;
			int getZ() const;
			int getW() const;
			const glm::ivec4& getMVec() const;

			void setX(int x);
			void setY(int y);
			void setZ(int z);
			void setW(int w);
			void set(int x, int y, int z, int w);

			friend bool operator==(const IVec4& vec1, const IVec4& vec2);
			friend bool operator!=(const IVec4& vec1, const IVec4& vec2);

			int operator[](int index) const;

			void operator=(const IVec4& vec);
			IVec4 operator+(const IVec4& vec) const;
			void operator+=(const IVec4& vec);
			IVec4 operator-() const;
			IVec4 operator-(const IVec4& vec) const;
			void operator-=(const IVec4& vec);
			IVec4 operator*(const int& scalar) const;
			void operator*=(const int& scalar);

		private:
			glm::ivec4 m_vec;
		};

		class UVec : public Vec {};

		class UVec2 : public UVec
		{
		public:
			UVec2();
			UVec2(uint xy);
			UVec2(uint x, uint y);
			UVec2(const glm::uvec2& vec);

			const uint* data() const;
			bool isZero() const;
			std::string toString() const;

			UVec2 xx() const;
			UVec2 xy() const;
			UVec2 yx() const;
			UVec2 yy() const;

			uint getX() const;
			uint getY() const;
			const glm::uvec2& getMVec() const;

			void setX(uint x);
			void setY(uint y);
			void set(uint x, uint y);

			friend bool operator==(const UVec2& vec1, const UVec2& vec2);
			friend bool operator!=(const UVec2& vec1, const UVec2& vec2);

			uint operator[](int index) const;

			void operator=(const UVec2& vec);
			UVec2 operator+(const UVec2& vec) const;
			void operator+=(const UVec2& vec);
			UVec2 operator-(const UVec2& vec) const;
			void operator-=(const UVec2& vec);
			UVec2 operator*(const uint& scalar) const;
			void operator*=(const uint& scalar);

		private:
			glm::uvec2 m_vec;
		};

		class UVec3 : public UVec
		{
		public:
			UVec3();
			UVec3(uint xyz);
			UVec3(uint x, uint y, uint z);
			UVec3(const UVec2& vec, uint z);
			UVec3(uint x, const UVec2& vec);
			UVec3(const glm::uvec3& vec);

			const uint* data() const;
			bool isZero() const;
			std::string toString() const;

			UVec2 xx() const;
			UVec2 xy() const;
			UVec2 xz() const;
			UVec2 yx() const;
			UVec2 yy() const;
			UVec2 yz() const;
			UVec2 zx() const;
			UVec2 zy() const;
			UVec2 zz() const;

			UVec3 xxx() const;
			UVec3 xxy() const;
			UVec3 xxz() const;
			UVec3 xyx() const;
			UVec3 xyy() const;
			UVec3 xyz() const;
			UVec3 xzx() const;
			UVec3 xzy() const;
			UVec3 xzz() const;
			UVec3 yxx() const;
			UVec3 yxy() const;
			UVec3 yxz() const;
			UVec3 yyx() const;
			UVec3 yyy() const;
			UVec3 yyz() const;
			UVec3 yzx() const;
			UVec3 yzy() const;
			UVec3 yzz() const;
			UVec3 zxx() const;
			UVec3 zxy() const;
			UVec3 zxz() const;
			UVec3 zyx() const;
			UVec3 zyy() const;
			UVec3 zyz() const;
			UVec3 zzx() const;
			UVec3 zzy() const;
			UVec3 zzz() const;

			uint getX() const;
			uint getY() const;
			uint getZ() const;
			const glm::uvec3& getMVec() const;

			void setX(uint x);
			void setY(uint y);
			void setZ(uint z);
			void set(uint x, uint y, uint z);

			friend bool operator==(const UVec3& vec1, const UVec3& vec2);
			friend bool operator!=(const UVec3& vec1, const UVec3& vec2);

			uint operator[](int index) const;

			void operator=(const UVec3& vec);
			UVec3 operator+(const UVec3& vec) const;
			void operator+=(const UVec3& vec);
			UVec3 operator-(const UVec3& vec) const;
			void operator-=(const UVec3& vec);
			UVec3 operator*(const uint& scalar) const;
			void operator*=(const uint& scalar);

		private:
			glm::uvec3 m_vec;
		};

		class UVec4 : public UVec
		{
		public:
			UVec4();
			UVec4(uint xyzw);
			UVec4(uint x, uint y, uint z, uint w);
			UVec4(const UVec2& vec, uint z, uint w);
			UVec4(uint x, const UVec2& vec, uint w);
			UVec4(uint x, uint y, const UVec2& vec);
			UVec4(const UVec3& vec, uint w);
			UVec4(uint x, const UVec3& vec);
			UVec4(const UVec2& vec1, const UVec2& vec2);
			UVec4(const glm::uvec4& vec);

			const uint* data() const;
			bool isZero() const;
			std::string toString() const;

			UVec2 xx() const;
			UVec2 xy() const;
			UVec2 xz() const;
			UVec2 xw() const;
			UVec2 yx() const;
			UVec2 yy() const;
			UVec2 yz() const;
			UVec2 yw() const;
			UVec2 zx() const;
			UVec2 zy() const;
			UVec2 zz() const;
			UVec2 zw() const;
			UVec2 wx() const;
			UVec2 wy() const;
			UVec2 wz() const;
			UVec2 ww() const;

			UVec3 xxx() const;
			UVec3 xxy() const;
			UVec3 xxz() const;
			UVec3 xxw() const;
			UVec3 xyx() const;
			UVec3 xyy() const;
			UVec3 xyz() const;
			UVec3 xyw() const;
			UVec3 xzx() const;
			UVec3 xzy() const;
			UVec3 xzz() const;
			UVec3 xzw() const;
			UVec3 xwx() const;
			UVec3 xwy() const;
			UVec3 xwz() const;
			UVec3 xww() const;
			UVec3 yxx() const;
			UVec3 yxy() const;
			UVec3 yxz() const;
			UVec3 yxw() const;
			UVec3 yyx() const;
			UVec3 yyy() const;
			UVec3 yyz() const;
			UVec3 yyw() const;
			UVec3 yzx() const;
			UVec3 yzy() const;
			UVec3 yzz() const;
			UVec3 yzw() const;
			UVec3 ywx() const;
			UVec3 ywy() const;
			UVec3 ywz() const;
			UVec3 yww() const;
			UVec3 zxx() const;
			UVec3 zxy() const;
			UVec3 zxz() const;
			UVec3 zxw() const;
			UVec3 zyx() const;
			UVec3 zyy() const;
			UVec3 zyz() const;
			UVec3 zyw() const;
			UVec3 zzx() const;
			UVec3 zzy() const;
			UVec3 zzz() const;
			UVec3 zzw() const;
			UVec3 zwx() const;
			UVec3 zwy() const;
			UVec3 zwz() const;
			UVec3 zww() const;
			UVec3 wxx() const;
			UVec3 wxy() const;
			UVec3 wxz() const;
			UVec3 wxw() const;
			UVec3 wyx() const;
			UVec3 wyy() const;
			UVec3 wyz() const;
			UVec3 wyw() const;
			UVec3 wzx() const;
			UVec3 wzy() const;
			UVec3 wzz() const;
			UVec3 wzw() const;
			UVec3 wwx() const;
			UVec3 wwy() const;
			UVec3 wwz() const;
			UVec3 www() const;

			UVec4 xxxx() const;
			UVec4 xxxy() const;
			UVec4 xxxz() const;
			UVec4 xxxw() const;
			UVec4 xxyx() const;
			UVec4 xxyy() const;
			UVec4 xxyz() const;
			UVec4 xxyw() const;
			UVec4 xxzx() const;
			UVec4 xxzy() const;
			UVec4 xxzz() const;
			UVec4 xxzw() const;
			UVec4 xxwx() const;
			UVec4 xxwy() const;
			UVec4 xxwz() const;
			UVec4 xxww() const;
			UVec4 xyxx() const;
			UVec4 xyxy() const;
			UVec4 xyxz() const;
			UVec4 xyxw() const;
			UVec4 xyyx() const;
			UVec4 xyyy() const;
			UVec4 xyyz() const;
			UVec4 xyyw() const;
			UVec4 xyzx() const;
			UVec4 xyzy() const;
			UVec4 xyzz() const;
			UVec4 xyzw() const;
			UVec4 xywx() const;
			UVec4 xywy() const;
			UVec4 xywz() const;
			UVec4 xyww() const;
			UVec4 xzxx() const;
			UVec4 xzxy() const;
			UVec4 xzxz() const;
			UVec4 xzxw() const;
			UVec4 xzyx() const;
			UVec4 xzyy() const;
			UVec4 xzyz() const;
			UVec4 xzyw() const;
			UVec4 xzzx() const;
			UVec4 xzzy() const;
			UVec4 xzzz() const;
			UVec4 xzzw() const;
			UVec4 xzwx() const;
			UVec4 xzwy() const;
			UVec4 xzwz() const;
			UVec4 xzww() const;
			UVec4 xwxx() const;
			UVec4 xwxy() const;
			UVec4 xwxz() const;
			UVec4 xwxw() const;
			UVec4 xwyx() const;
			UVec4 xwyy() const;
			UVec4 xwyz() const;
			UVec4 xwyw() const;
			UVec4 xwzx() const;
			UVec4 xwzy() const;
			UVec4 xwzz() const;
			UVec4 xwzw() const;
			UVec4 xwwx() const;
			UVec4 xwwy() const;
			UVec4 xwwz() const;
			UVec4 xwww() const;
			UVec4 yxxx() const;
			UVec4 yxxy() const;
			UVec4 yxxz() const;
			UVec4 yxxw() const;
			UVec4 yxyx() const;
			UVec4 yxyy() const;
			UVec4 yxyz() const;
			UVec4 yxyw() const;
			UVec4 yxzx() const;
			UVec4 yxzy() const;
			UVec4 yxzz() const;
			UVec4 yxzw() const;
			UVec4 yxwx() const;
			UVec4 yxwy() const;
			UVec4 yxwz() const;
			UVec4 yxww() const;
			UVec4 yyxx() const;
			UVec4 yyxy() const;
			UVec4 yyxz() const;
			UVec4 yyxw() const;
			UVec4 yyyx() const;
			UVec4 yyyy() const;
			UVec4 yyyz() const;
			UVec4 yyyw() const;
			UVec4 yyzx() const;
			UVec4 yyzy() const;
			UVec4 yyzz() const;
			UVec4 yyzw() const;
			UVec4 yywx() const;
			UVec4 yywy() const;
			UVec4 yywz() const;
			UVec4 yyww() const;
			UVec4 yzxx() const;
			UVec4 yzxy() const;
			UVec4 yzxz() const;
			UVec4 yzxw() const;
			UVec4 yzyx() const;
			UVec4 yzyy() const;
			UVec4 yzyz() const;
			UVec4 yzyw() const;
			UVec4 yzzx() const;
			UVec4 yzzy() const;
			UVec4 yzzz() const;
			UVec4 yzzw() const;
			UVec4 yzwx() const;
			UVec4 yzwy() const;
			UVec4 yzwz() const;
			UVec4 yzww() const;
			UVec4 ywxx() const;
			UVec4 ywxy() const;
			UVec4 ywxz() const;
			UVec4 ywxw() const;
			UVec4 ywyx() const;
			UVec4 ywyy() const;
			UVec4 ywyz() const;
			UVec4 ywyw() const;
			UVec4 ywzx() const;
			UVec4 ywzy() const;
			UVec4 ywzz() const;
			UVec4 ywzw() const;
			UVec4 ywwx() const;
			UVec4 ywwy() const;
			UVec4 ywwz() const;
			UVec4 ywww() const;
			UVec4 zxxx() const;
			UVec4 zxxy() const;
			UVec4 zxxz() const;
			UVec4 zxxw() const;
			UVec4 zxyx() const;
			UVec4 zxyy() const;
			UVec4 zxyz() const;
			UVec4 zxyw() const;
			UVec4 zxzx() const;
			UVec4 zxzy() const;
			UVec4 zxzz() const;
			UVec4 zxzw() const;
			UVec4 zxwx() const;
			UVec4 zxwy() const;
			UVec4 zxwz() const;
			UVec4 zxww() const;
			UVec4 zyxx() const;
			UVec4 zyxy() const;
			UVec4 zyxz() const;
			UVec4 zyxw() const;
			UVec4 zyyx() const;
			UVec4 zyyy() const;
			UVec4 zyyz() const;
			UVec4 zyyw() const;
			UVec4 zyzx() const;
			UVec4 zyzy() const;
			UVec4 zyzz() const;
			UVec4 zyzw() const;
			UVec4 zywx() const;
			UVec4 zywy() const;
			UVec4 zywz() const;
			UVec4 zyww() const;
			UVec4 zzxx() const;
			UVec4 zzxy() const;
			UVec4 zzxz() const;
			UVec4 zzxw() const;
			UVec4 zzyx() const;
			UVec4 zzyy() const;
			UVec4 zzyz() const;
			UVec4 zzyw() const;
			UVec4 zzzx() const;
			UVec4 zzzy() const;
			UVec4 zzzz() const;
			UVec4 zzzw() const;
			UVec4 zzwx() const;
			UVec4 zzwy() const;
			UVec4 zzwz() const;
			UVec4 zzww() const;
			UVec4 zwxx() const;
			UVec4 zwxy() const;
			UVec4 zwxz() const;
			UVec4 zwxw() const;
			UVec4 zwyx() const;
			UVec4 zwyy() const;
			UVec4 zwyz() const;
			UVec4 zwyw() const;
			UVec4 zwzx() const;
			UVec4 zwzy() const;
			UVec4 zwzz() const;
			UVec4 zwzw() const;
			UVec4 zwwx() const;
			UVec4 zwwy() const;
			UVec4 zwwz() const;
			UVec4 zwww() const;
			UVec4 wxxx() const;
			UVec4 wxxy() const;
			UVec4 wxxz() const;
			UVec4 wxxw() const;
			UVec4 wxyx() const;
			UVec4 wxyy() const;
			UVec4 wxyz() const;
			UVec4 wxyw() const;
			UVec4 wxzx() const;
			UVec4 wxzy() const;
			UVec4 wxzz() const;
			UVec4 wxzw() const;
			UVec4 wxwx() const;
			UVec4 wxwy() const;
			UVec4 wxwz() const;
			UVec4 wxww() const;
			UVec4 wyxx() const;
			UVec4 wyxy() const;
			UVec4 wyxz() const;
			UVec4 wyxw() const;
			UVec4 wyyx() const;
			UVec4 wyyy() const;
			UVec4 wyyz() const;
			UVec4 wyyw() const;
			UVec4 wyzx() const;
			UVec4 wyzy() const;
			UVec4 wyzz() const;
			UVec4 wyzw() const;
			UVec4 wywx() const;
			UVec4 wywy() const;
			UVec4 wywz() const;
			UVec4 wyww() const;
			UVec4 wzxx() const;
			UVec4 wzxy() const;
			UVec4 wzxz() const;
			UVec4 wzxw() const;
			UVec4 wzyx() const;
			UVec4 wzyy() const;
			UVec4 wzyz() const;
			UVec4 wzyw() const;
			UVec4 wzzx() const;
			UVec4 wzzy() const;
			UVec4 wzzz() const;
			UVec4 wzzw() const;
			UVec4 wzwx() const;
			UVec4 wzwy() const;
			UVec4 wzwz() const;
			UVec4 wzww() const;
			UVec4 wwxx() const;
			UVec4 wwxy() const;
			UVec4 wwxz() const;
			UVec4 wwxw() const;
			UVec4 wwyx() const;
			UVec4 wwyy() const;
			UVec4 wwyz() const;
			UVec4 wwyw() const;
			UVec4 wwzx() const;
			UVec4 wwzy() const;
			UVec4 wwzz() const;
			UVec4 wwzw() const;
			UVec4 wwwx() const;
			UVec4 wwwy() const;
			UVec4 wwwz() const;
			UVec4 wwww() const;

			uint getX() const;
			uint getY() const;
			uint getZ() const;
			uint getW() const;
			const glm::uvec4& getMVec() const;

			void setX(uint x);
			void setY(uint y);
			void setZ(uint z);
			void setW(uint w);
			void set(uint x, uint y, uint z, uint w);

			friend bool operator==(const UVec4& vec1, const UVec4& vec2);
			friend bool operator!=(const UVec4& vec1, const UVec4& vec2);

			uint operator[](int index) const;

			void operator=(const UVec4& vec);
			UVec4 operator+(const UVec4& vec) const;
			void operator+=(const UVec4& vec);
			UVec4 operator-(const UVec4& vec) const;
			void operator-=(const UVec4& vec);
			UVec4 operator*(const uint& scalar) const;
			void operator*=(const uint& scalar);

		private:
			glm::uvec4 m_vec;
		};

		/*
			@brief The cross product vector operation between 3D vectors.
			@return The resulting vector.
		 */
		Vec3 Cross(const Vec3& vec1, const Vec3& vec2);

		/*
			@brief The dot product vector operation between 2D vectors.
			@return The resulting scalar value.
		 */
		float Dot(const Vec2& vec1, const Vec2& vec2);

		/*
			@brief The dot product vector operation between 3D vectors.
			@return The resulting scalar value.
		 */
		float Dot(const Vec3& vec1, const Vec3& vec2);

		/*
			@brief The dot product vector operation between 4D vectors.
			@return The resulting scalar value.
		 */
		float Dot(const Vec4& vec1, const Vec4& vec2);

		/*
			@brief The cross product vector operation between 3D double vectors.
			@return The resulting vector.
		 */
		DVec3 Cross(const DVec3& vec1, const DVec3& vec2);

		/*
			@brief The dot product vector operation between 2D double vectors.
			@return The resulting scalar value.
		 */
		double Dot(const DVec2& vec1, const DVec2& vec2);

		/*
			@brief The dot product vector operation between 3D double vectors.
			@return The resulting scalar value.
		 */
		double Dot(const DVec3& vec1, const DVec3& vec2);

		/*
			@brief The dot product vector operation between 4D double vectors.
			@return The resulting scalar value.
		 */
		double Dot(const DVec4& vec1, const DVec4& vec2);


		bool operator==(const Vec2& vec1, const Vec2& vec2);
		bool operator!=(const Vec2& vec1, const Vec2& vec2);

		bool operator==(const Vec3& vec1, const Vec3& vec2);
		bool operator!=(const Vec3& vec1, const Vec3& vec2);

		bool operator==(const Vec4& vec1, const Vec4& vec2);
		bool operator!=(const Vec4& vec1, const Vec4& vec2);

		bool operator==(const DVec2& vec1, const DVec2& vec2);
		bool operator!=(const DVec2& vec1, const DVec2& vec2);

		bool operator==(const DVec3& vec1, const DVec3& vec2);
		bool operator!=(const DVec3& vec1, const DVec3& vec2);

		bool operator==(const DVec4& vec1, const DVec4& vec2);
		bool operator!=(const DVec4& vec1, const DVec4& vec2);

		bool operator==(const IVec2& vec1, const IVec2& vec2);
		bool operator!=(const IVec2& vec1, const IVec2& vec2);

		bool operator==(const IVec3& vec1, const IVec3& vec2);
		bool operator!=(const IVec3& vec1, const IVec3& vec2);

		bool operator==(const IVec4& vec1, const IVec4& vec2);
		bool operator!=(const IVec4& vec1, const IVec4& vec2);

		bool operator==(const UVec2& vec1, const UVec2& vec2);
		bool operator!=(const UVec2& vec1, const UVec2& vec2);

		bool operator==(const UVec3& vec1, const UVec3& vec2);
		bool operator!=(const UVec3& vec1, const UVec3& vec2);

		bool operator==(const UVec4& vec1, const UVec4& vec2);
		bool operator!=(const UVec4& vec1, const UVec4& vec2);

		/*
			@brief A parent class for matrices.
		 */
		class Mat {};

		/*
			@brief A matrix with dimensions 2x2
		 */
		class Mat2x2 : public Mat
		{
		public:
			Mat2x2();
			Mat2x2(float scalar);
			Mat2x2(glm::mat2x2 mat);

			glm::mat2x2 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec2 operator[](int index) const;

			void operator=(const Mat2x2& mat);
			Mat2x2 operator+(const Mat2x2& mat) const;
			void operator+=(const Mat2x2& mat);
			Mat2x2 operator-() const;
			Mat2x2 operator-(const Mat2x2& mat) const;
			void operator-=(const Mat2x2& mat);

			static Mat2x2 Identity();

		private:
			glm::mat2x2 m_mat;
		};

		/*
			@brief A matrix with dimensions 2x3
		 */
		class Mat2x3 : public Mat
		{
		public:
			Mat2x3();
			Mat2x3(float scalar);
			Mat2x3(glm::mat2x3 mat);

			glm::mat2x3 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec3 operator[](int index) const;

			void operator=(const Mat2x3& mat);
			Mat2x3 operator+(const Mat2x3& mat) const;
			void operator+=(const Mat2x3& mat);
			Mat2x3 operator-() const;
			Mat2x3 operator-(const Mat2x3& mat) const;
			void operator-=(const Mat2x3& mat);

			static Mat2x3 Identity();

		private:
			glm::mat2x3 m_mat;
		};

		/*
			@brief A matrix with dimensions 2x4
		 */
		class Mat2x4 : public Mat
		{
		public:
			Mat2x4();
			Mat2x4(float scalar);
			Mat2x4(glm::mat2x4 mat);

			glm::mat2x4 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec4 operator[](int index) const;

			void operator=(const Mat2x4& mat);
			Mat2x4 operator+(const Mat2x4& mat) const;
			void operator+=(const Mat2x4& mat);
			Mat2x4 operator-() const;
			Mat2x4 operator-(const Mat2x4& mat) const;
			void operator-=(const Mat2x4& mat);

			static Mat2x4 Identity();

		private:
			glm::mat2x4 m_mat;
		};

		/*
			@brief A matrix with dimensions 3x2
		 */
		class Mat3x2 : public Mat
		{
		public:
			Mat3x2();
			Mat3x2(float scalar);
			Mat3x2(glm::mat3x2 mat);

			glm::mat3x2 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec2 operator[](int index) const;

			void operator=(const Mat3x2& mat);
			Mat3x2 operator+(const Mat3x2& mat) const;
			void operator+=(const Mat3x2& mat);
			Mat3x2 operator-() const;
			Mat3x2 operator-(const Mat3x2& mat) const;
			void operator-=(const Mat3x2& mat);

			static Mat3x2 Identity();

		private:
			glm::mat3x2 m_mat;
		};

		/*
			@brief A matrix with dimensions 3x3
		 */
		class Mat3x3 : public Mat
		{
		public:
			Mat3x3();
			Mat3x3(float scalar);
			Mat3x3(glm::mat3x3 mat);

			glm::mat3x3 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec3 operator[](int index) const;

			void operator=(const Mat3x3& mat);
			Mat3x3 operator+(const Mat3x3& mat) const;
			void operator+=(const Mat3x3& mat);
			Mat3x3 operator-() const;
			Mat3x3 operator-(const Mat3x3& mat) const;
			void operator-=(const Mat3x3& mat);

			static Mat3x3 Identity();

		private:
			glm::mat3x3 m_mat;
		};

		/*
			@brief A matrix with dimensions 3x4
		 */
		class Mat3x4 : public Mat
		{
		public:
			Mat3x4();
			Mat3x4(float scalar);
			Mat3x4(glm::mat3x4 mat);

			glm::mat3x4 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec4 operator[](int index) const;

			void operator=(const Mat3x4& mat);
			Mat3x4 operator+(const Mat3x4& mat) const;
			void operator+=(const Mat3x4& mat);
			Mat3x4 operator-() const;
			Mat3x4 operator-(const Mat3x4& mat) const;
			void operator-=(const Mat3x4& mat);

			static Mat3x4 Identity();

		private:
			glm::mat3x4 m_mat;
		};

		/*
			@brief A matrix with dimensions 4x2
		 */
		class Mat4x2 : public Mat
		{
		public:
			Mat4x2();
			Mat4x2(float scalar);
			Mat4x2(glm::mat4x2 mat);

			glm::mat4x2 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec2 operator[](int index) const;

			void operator=(const Mat4x2& mat);
			Mat4x2 operator+(const Mat4x2& mat) const;
			void operator+=(const Mat4x2& mat);
			Mat4x2 operator-() const;
			Mat4x2 operator-(const Mat4x2& mat) const;
			void operator-=(const Mat4x2& mat);

			static Mat4x2 Identity();

		private:
			glm::mat4x2 m_mat;
		};

		/*
			@brief A matrix with dimensions 4x3
		 */
		class Mat4x3 : public Mat
		{
		public:
			Mat4x3();
			Mat4x3(float scalar);
			Mat4x3(glm::mat4x3 mat);

			glm::mat4x3 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec3 operator[](int index) const;

			void operator=(const Mat4x3& mat);
			Mat4x3 operator+(const Mat4x3& mat) const;
			void operator+=(const Mat4x3& mat);
			Mat4x3 operator-() const;
			Mat4x3 operator-(const Mat4x3& mat) const;
			void operator-=(const Mat4x3& mat);

			static Mat4x3 Identity();

		private:
			glm::mat4x3 m_mat;
		};

		/*
			@brief A matrix with dimensions 4x4
		 */
		class Mat4x4 : public Mat
		{
		public:
			Mat4x4();
			Mat4x4(float scalar);
			Mat4x4(glm::mat4x4 mat);

			void translate(const Vec3& xyz);
			void rotate(float degrees, const Vec3& mask);
			void scale(const Vec3& xyzMultiplier);

			glm::mat4x4 getMMat() const;

			const float* data() const;
			std::string toString() const;

			Vec4 operator[](int index) const;

			void operator=(const Mat4x4& mat);
			Mat4x4 operator+(const Mat4x4& mat) const;
			void operator+=(const Mat4x4& mat);
			Mat4x4 operator-() const;
			Mat4x4 operator-(const Mat4x4& mat) const;
			void operator-=(const Mat4x4& mat);

			static Mat4x4 Identity();

		private:
			glm::mat4x4 m_mat;
		};

		Mat2x2 operator*(const Mat2x2& mat1, const Mat2x2& mat2);
		Mat2x2 operator*(const Mat2x3& mat1, const Mat3x2& mat2);
		Mat2x2 operator*(const Mat2x4& mat1, const Mat4x2& mat2);

		Mat3x3 operator*(const Mat3x2& mat1, const Mat2x3& mat2);
		Mat3x3 operator*(const Mat3x3& mat1, const Mat3x3& mat2);
		Mat3x3 operator*(const Mat3x4& mat1, const Mat4x3& mat2);

		Mat4x4 operator*(const Mat4x2& mat1, const Mat2x4& mat2);
		Mat4x4 operator*(const Mat4x3& mat1, const Mat3x4& mat2);
		Mat4x4 operator*(const Mat4x4& mat1, const Mat4x4& mat2);


		Vec2 operator*(const Mat2x2& mat, const Vec2& vec);
		Vec2 operator*(const Mat2x3& mat, const Vec3& vec);
		Vec2 operator*(const Mat2x4& mat, const Vec4& vec);

		Vec3 operator*(const Mat3x3& mat, const Vec3& vec);
		Vec3 operator*(const Mat3x4& mat, const Vec4& vec);

		Vec4 operator*(const Mat4x4& mat, const Vec4& vec);


		Mat2x2 Transpose(const Mat2x2& mat);
		Mat2x3 Transpose(const Mat3x2& mat);
		Mat2x4 Transpose(const Mat4x2& mat);

		Mat3x2 Transpose(const Mat2x3& mat);
		Mat3x3 Transpose(const Mat3x3& mat);
		Mat3x4 Transpose(const Mat4x3& mat);
		
		Mat4x2 Transpose(const Mat2x4& mat);
		Mat4x3 Transpose(const Mat3x4& mat);
		Mat4x4 Transpose(const Mat4x4& mat);


		Mat2x2 Inverse(const Mat2x2& mat);
		Mat3x3 Inverse(const Mat3x3& mat);
		Mat4x4 Inverse(const Mat4x4& mat);

		float Det(const Mat2x2& mat);
		float Det(const Mat3x3& mat);
		float Det(const Mat4x4& mat);

		Mat4x4 LookAt(const Vec3& pos, const Vec3& target, const Vec3& up);

		Mat4x4 OrthographicProjection(float left, float right, float top, float bottom);
		Mat4x4 PerspectiveProjection(float fov, float aspectRatio, float nearPlane, float farPlane);

		/*
			@brief A matrix with dimensions 2x2
		 */
		typedef Mat2x2 Mat2;

		/*
			@brief A matrix with dimensions 3x3
		 */
		typedef Mat3x3 Mat3;

		/*
			@brief A matrix with dimensions 4x4
		 */
		typedef Mat4x4 Mat4;
	}
}
