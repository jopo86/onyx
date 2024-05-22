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

			Vec2 xx();
			Vec2 xy();
			Vec2 yx();
			Vec2 yy();

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

			Vec2 xx();
			Vec2 xy();
			Vec2 xz();
			Vec2 yx();
			Vec2 yy();
			Vec2 yz();
			Vec2 zx();
			Vec2 zy();
			Vec2 zz();

			Vec3 xxx();
			Vec3 xxy();
			Vec3 xxz();
			Vec3 xyx();
			Vec3 xyy();
			Vec3 xyz();
			Vec3 xzx();
			Vec3 xzy();
			Vec3 xzz();
			Vec3 yxx();
			Vec3 yxy();
			Vec3 yxz();
			Vec3 yyx();
			Vec3 yyy();
			Vec3 yyz();
			Vec3 yzx();
			Vec3 yzy();
			Vec3 yzz();
			Vec3 zxx();
			Vec3 zxy();
			Vec3 zxz();
			Vec3 zyx();
			Vec3 zyy();
			Vec3 zyz();
			Vec3 zzx();
			Vec3 zzy();
			Vec3 zzz();

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

			Vec2 xx();
			Vec2 xy();
			Vec2 xz();
			Vec2 xw();
			Vec2 yx();
			Vec2 yy();
			Vec2 yz();
			Vec2 yw();
			Vec2 zx();
			Vec2 zy();
			Vec2 zz();
			Vec2 zw();
			Vec2 wx();
			Vec2 wy();
			Vec2 wz();
			Vec2 ww();

			Vec3 xxx();
			Vec3 xxy();
			Vec3 xxz();
			Vec3 xxw();
			Vec3 xyx();
			Vec3 xyy();
			Vec3 xyz();
			Vec3 xyw();
			Vec3 xzx();
			Vec3 xzy();
			Vec3 xzz();
			Vec3 xzw();
			Vec3 xwx();
			Vec3 xwy();
			Vec3 xwz();
			Vec3 xww();
			Vec3 yxx();
			Vec3 yxy();
			Vec3 yxz();
			Vec3 yxw();
			Vec3 yyx();
			Vec3 yyy();
			Vec3 yyz();
			Vec3 yyw();
			Vec3 yzx();
			Vec3 yzy();
			Vec3 yzz();
			Vec3 yzw();
			Vec3 ywx();
			Vec3 ywy();
			Vec3 ywz();
			Vec3 yww();
			Vec3 zxx();
			Vec3 zxy();
			Vec3 zxz();
			Vec3 zxw();
			Vec3 zyx();
			Vec3 zyy();
			Vec3 zyz();
			Vec3 zyw();
			Vec3 zzx();
			Vec3 zzy();
			Vec3 zzz();
			Vec3 zzw();
			Vec3 zwx();
			Vec3 zwy();
			Vec3 zwz();
			Vec3 zww();
			Vec3 wxx();
			Vec3 wxy();
			Vec3 wxz();
			Vec3 wxw();
			Vec3 wyx();
			Vec3 wyy();
			Vec3 wyz();
			Vec3 wyw();
			Vec3 wzx();
			Vec3 wzy();
			Vec3 wzz();
			Vec3 wzw();
			Vec3 wwx();
			Vec3 wwy();
			Vec3 wwz();
			Vec3 www();

			Vec4 xxxx();
			Vec4 xxxy();
			Vec4 xxxz();
			Vec4 xxxw();
			Vec4 xxyx();
			Vec4 xxyy();
			Vec4 xxyz();
			Vec4 xxyw();
			Vec4 xxzx();
			Vec4 xxzy();
			Vec4 xxzz();
			Vec4 xxzw();
			Vec4 xxwx();
			Vec4 xxwy();
			Vec4 xxwz();
			Vec4 xxww();
			Vec4 xyxx();
			Vec4 xyxy();
			Vec4 xyxz();
			Vec4 xyxw();
			Vec4 xyyx();
			Vec4 xyyy();
			Vec4 xyyz();
			Vec4 xyyw();
			Vec4 xyzx();
			Vec4 xyzy();
			Vec4 xyzz();
			Vec4 xyzw();
			Vec4 xywx();
			Vec4 xywy();
			Vec4 xywz();
			Vec4 xyww();
			Vec4 xzxx();
			Vec4 xzxy();
			Vec4 xzxz();
			Vec4 xzxw();
			Vec4 xzyx();
			Vec4 xzyy();
			Vec4 xzyz();
			Vec4 xzyw();
			Vec4 xzzx();
			Vec4 xzzy();
			Vec4 xzzz();
			Vec4 xzzw();
			Vec4 xzwx();
			Vec4 xzwy();
			Vec4 xzwz();
			Vec4 xzww();
			Vec4 xwxx();
			Vec4 xwxy();
			Vec4 xwxz();
			Vec4 xwxw();
			Vec4 xwyx();
			Vec4 xwyy();
			Vec4 xwyz();
			Vec4 xwyw();
			Vec4 xwzx();
			Vec4 xwzy();
			Vec4 xwzz();
			Vec4 xwzw();
			Vec4 xwwx();
			Vec4 xwwy();
			Vec4 xwwz();
			Vec4 xwww();
			Vec4 yxxx();
			Vec4 yxxy();
			Vec4 yxxz();
			Vec4 yxxw();
			Vec4 yxyx();
			Vec4 yxyy();
			Vec4 yxyz();
			Vec4 yxyw();
			Vec4 yxzx();
			Vec4 yxzy();
			Vec4 yxzz();
			Vec4 yxzw();
			Vec4 yxwx();
			Vec4 yxwy();
			Vec4 yxwz();
			Vec4 yxww();
			Vec4 yyxx();
			Vec4 yyxy();
			Vec4 yyxz();
			Vec4 yyxw();
			Vec4 yyyx();
			Vec4 yyyy();
			Vec4 yyyz();
			Vec4 yyyw();
			Vec4 yyzx();
			Vec4 yyzy();
			Vec4 yyzz();
			Vec4 yyzw();
			Vec4 yywx();
			Vec4 yywy();
			Vec4 yywz();
			Vec4 yyww();
			Vec4 yzxx();
			Vec4 yzxy();
			Vec4 yzxz();
			Vec4 yzxw();
			Vec4 yzyx();
			Vec4 yzyy();
			Vec4 yzyz();
			Vec4 yzyw();
			Vec4 yzzx();
			Vec4 yzzy();
			Vec4 yzzz();
			Vec4 yzzw();
			Vec4 yzwx();
			Vec4 yzwy();
			Vec4 yzwz();
			Vec4 yzww();
			Vec4 ywxx();
			Vec4 ywxy();
			Vec4 ywxz();
			Vec4 ywxw();
			Vec4 ywyx();
			Vec4 ywyy();
			Vec4 ywyz();
			Vec4 ywyw();
			Vec4 ywzx();
			Vec4 ywzy();
			Vec4 ywzz();
			Vec4 ywzw();
			Vec4 ywwx();
			Vec4 ywwy();
			Vec4 ywwz();
			Vec4 ywww();
			Vec4 zxxx();
			Vec4 zxxy();
			Vec4 zxxz();
			Vec4 zxxw();
			Vec4 zxyx();
			Vec4 zxyy();
			Vec4 zxyz();
			Vec4 zxyw();
			Vec4 zxzx();
			Vec4 zxzy();
			Vec4 zxzz();
			Vec4 zxzw();
			Vec4 zxwx();
			Vec4 zxwy();
			Vec4 zxwz();
			Vec4 zxww();
			Vec4 zyxx();
			Vec4 zyxy();
			Vec4 zyxz();
			Vec4 zyxw();
			Vec4 zyyx();
			Vec4 zyyy();
			Vec4 zyyz();
			Vec4 zyyw();
			Vec4 zyzx();
			Vec4 zyzy();
			Vec4 zyzz();
			Vec4 zyzw();
			Vec4 zywx();
			Vec4 zywy();
			Vec4 zywz();
			Vec4 zyww();
			Vec4 zzxx();
			Vec4 zzxy();
			Vec4 zzxz();
			Vec4 zzxw();
			Vec4 zzyx();
			Vec4 zzyy();
			Vec4 zzyz();
			Vec4 zzyw();
			Vec4 zzzx();
			Vec4 zzzy();
			Vec4 zzzz();
			Vec4 zzzw();
			Vec4 zzwx();
			Vec4 zzwy();
			Vec4 zzwz();
			Vec4 zzww();
			Vec4 zwxx();
			Vec4 zwxy();
			Vec4 zwxz();
			Vec4 zwxw();
			Vec4 zwyx();
			Vec4 zwyy();
			Vec4 zwyz();
			Vec4 zwyw();
			Vec4 zwzx();
			Vec4 zwzy();
			Vec4 zwzz();
			Vec4 zwzw();
			Vec4 zwwx();
			Vec4 zwwy();
			Vec4 zwwz();
			Vec4 zwww();
			Vec4 wxxx();
			Vec4 wxxy();
			Vec4 wxxz();
			Vec4 wxxw();
			Vec4 wxyx();
			Vec4 wxyy();
			Vec4 wxyz();
			Vec4 wxyw();
			Vec4 wxzx();
			Vec4 wxzy();
			Vec4 wxzz();
			Vec4 wxzw();
			Vec4 wxwx();
			Vec4 wxwy();
			Vec4 wxwz();
			Vec4 wxww();
			Vec4 wyxx();
			Vec4 wyxy();
			Vec4 wyxz();
			Vec4 wyxw();
			Vec4 wyyx();
			Vec4 wyyy();
			Vec4 wyyz();
			Vec4 wyyw();
			Vec4 wyzx();
			Vec4 wyzy();
			Vec4 wyzz();
			Vec4 wyzw();
			Vec4 wywx();
			Vec4 wywy();
			Vec4 wywz();
			Vec4 wyww();
			Vec4 wzxx();
			Vec4 wzxy();
			Vec4 wzxz();
			Vec4 wzxw();
			Vec4 wzyx();
			Vec4 wzyy();
			Vec4 wzyz();
			Vec4 wzyw();
			Vec4 wzzx();
			Vec4 wzzy();
			Vec4 wzzz();
			Vec4 wzzw();
			Vec4 wzwx();
			Vec4 wzwy();
			Vec4 wzwz();
			Vec4 wzww();
			Vec4 wwxx();
			Vec4 wwxy();
			Vec4 wwxz();
			Vec4 wwxw();
			Vec4 wwyx();
			Vec4 wwyy();
			Vec4 wwyz();
			Vec4 wwyw();
			Vec4 wwzx();
			Vec4 wwzy();
			Vec4 wwzz();
			Vec4 wwzw();
			Vec4 wwwx();
			Vec4 wwwy();
			Vec4 wwwz();
			Vec4 wwww();

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

			DVec2 xx();
			DVec2 xy();
			DVec2 yx();
			DVec2 yy();

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

			DVec2 xx();
			DVec2 xy();
			DVec2 xz();
			DVec2 yx();
			DVec2 yy();
			DVec2 yz();
			DVec2 zx();
			DVec2 zy();
			DVec2 zz();

			DVec3 xxx();
			DVec3 xxy();
			DVec3 xxz();
			DVec3 xyx();
			DVec3 xyy();
			DVec3 xyz();
			DVec3 xzx();
			DVec3 xzy();
			DVec3 xzz();
			DVec3 yxx();
			DVec3 yxy();
			DVec3 yxz();
			DVec3 yyx();
			DVec3 yyy();
			DVec3 yyz();
			DVec3 yzx();
			DVec3 yzy();
			DVec3 yzz();
			DVec3 zxx();
			DVec3 zxy();
			DVec3 zxz();
			DVec3 zyx();
			DVec3 zyy();
			DVec3 zyz();
			DVec3 zzx();
			DVec3 zzy();
			DVec3 zzz();

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

			DVec2 xx();
			DVec2 xy();
			DVec2 xz();
			DVec2 xw();
			DVec2 yx();
			DVec2 yy();
			DVec2 yz();
			DVec2 yw();
			DVec2 zx();
			DVec2 zy();
			DVec2 zz();
			DVec2 zw();
			DVec2 wx();
			DVec2 wy();
			DVec2 wz();
			DVec2 ww();

			DVec3 xxx();
			DVec3 xxy();
			DVec3 xxz();
			DVec3 xxw();
			DVec3 xyx();
			DVec3 xyy();
			DVec3 xyz();
			DVec3 xyw();
			DVec3 xzx();
			DVec3 xzy();
			DVec3 xzz();
			DVec3 xzw();
			DVec3 xwx();
			DVec3 xwy();
			DVec3 xwz();
			DVec3 xww();
			DVec3 yxx();
			DVec3 yxy();
			DVec3 yxz();
			DVec3 yxw();
			DVec3 yyx();
			DVec3 yyy();
			DVec3 yyz();
			DVec3 yyw();
			DVec3 yzx();
			DVec3 yzy();
			DVec3 yzz();
			DVec3 yzw();
			DVec3 ywx();
			DVec3 ywy();
			DVec3 ywz();
			DVec3 yww();
			DVec3 zxx();
			DVec3 zxy();
			DVec3 zxz();
			DVec3 zxw();
			DVec3 zyx();
			DVec3 zyy();
			DVec3 zyz();
			DVec3 zyw();
			DVec3 zzx();
			DVec3 zzy();
			DVec3 zzz();
			DVec3 zzw();
			DVec3 zwx();
			DVec3 zwy();
			DVec3 zwz();
			DVec3 zww();
			DVec3 wxx();
			DVec3 wxy();
			DVec3 wxz();
			DVec3 wxw();
			DVec3 wyx();
			DVec3 wyy();
			DVec3 wyz();
			DVec3 wyw();
			DVec3 wzx();
			DVec3 wzy();
			DVec3 wzz();
			DVec3 wzw();
			DVec3 wwx();
			DVec3 wwy();
			DVec3 wwz();
			DVec3 www();

			DVec4 xxxx();
			DVec4 xxxy();
			DVec4 xxxz();
			DVec4 xxxw();
			DVec4 xxyx();
			DVec4 xxyy();
			DVec4 xxyz();
			DVec4 xxyw();
			DVec4 xxzx();
			DVec4 xxzy();
			DVec4 xxzz();
			DVec4 xxzw();
			DVec4 xxwx();
			DVec4 xxwy();
			DVec4 xxwz();
			DVec4 xxww();
			DVec4 xyxx();
			DVec4 xyxy();
			DVec4 xyxz();
			DVec4 xyxw();
			DVec4 xyyx();
			DVec4 xyyy();
			DVec4 xyyz();
			DVec4 xyyw();
			DVec4 xyzx();
			DVec4 xyzy();
			DVec4 xyzz();
			DVec4 xyzw();
			DVec4 xywx();
			DVec4 xywy();
			DVec4 xywz();
			DVec4 xyww();
			DVec4 xzxx();
			DVec4 xzxy();
			DVec4 xzxz();
			DVec4 xzxw();
			DVec4 xzyx();
			DVec4 xzyy();
			DVec4 xzyz();
			DVec4 xzyw();
			DVec4 xzzx();
			DVec4 xzzy();
			DVec4 xzzz();
			DVec4 xzzw();
			DVec4 xzwx();
			DVec4 xzwy();
			DVec4 xzwz();
			DVec4 xzww();
			DVec4 xwxx();
			DVec4 xwxy();
			DVec4 xwxz();
			DVec4 xwxw();
			DVec4 xwyx();
			DVec4 xwyy();
			DVec4 xwyz();
			DVec4 xwyw();
			DVec4 xwzx();
			DVec4 xwzy();
			DVec4 xwzz();
			DVec4 xwzw();
			DVec4 xwwx();
			DVec4 xwwy();
			DVec4 xwwz();
			DVec4 xwww();
			DVec4 yxxx();
			DVec4 yxxy();
			DVec4 yxxz();
			DVec4 yxxw();
			DVec4 yxyx();
			DVec4 yxyy();
			DVec4 yxyz();
			DVec4 yxyw();
			DVec4 yxzx();
			DVec4 yxzy();
			DVec4 yxzz();
			DVec4 yxzw();
			DVec4 yxwx();
			DVec4 yxwy();
			DVec4 yxwz();
			DVec4 yxww();
			DVec4 yyxx();
			DVec4 yyxy();
			DVec4 yyxz();
			DVec4 yyxw();
			DVec4 yyyx();
			DVec4 yyyy();
			DVec4 yyyz();
			DVec4 yyyw();
			DVec4 yyzx();
			DVec4 yyzy();
			DVec4 yyzz();
			DVec4 yyzw();
			DVec4 yywx();
			DVec4 yywy();
			DVec4 yywz();
			DVec4 yyww();
			DVec4 yzxx();
			DVec4 yzxy();
			DVec4 yzxz();
			DVec4 yzxw();
			DVec4 yzyx();
			DVec4 yzyy();
			DVec4 yzyz();
			DVec4 yzyw();
			DVec4 yzzx();
			DVec4 yzzy();
			DVec4 yzzz();
			DVec4 yzzw();
			DVec4 yzwx();
			DVec4 yzwy();
			DVec4 yzwz();
			DVec4 yzww();
			DVec4 ywxx();
			DVec4 ywxy();
			DVec4 ywxz();
			DVec4 ywxw();
			DVec4 ywyx();
			DVec4 ywyy();
			DVec4 ywyz();
			DVec4 ywyw();
			DVec4 ywzx();
			DVec4 ywzy();
			DVec4 ywzz();
			DVec4 ywzw();
			DVec4 ywwx();
			DVec4 ywwy();
			DVec4 ywwz();
			DVec4 ywww();
			DVec4 zxxx();
			DVec4 zxxy();
			DVec4 zxxz();
			DVec4 zxxw();
			DVec4 zxyx();
			DVec4 zxyy();
			DVec4 zxyz();
			DVec4 zxyw();
			DVec4 zxzx();
			DVec4 zxzy();
			DVec4 zxzz();
			DVec4 zxzw();
			DVec4 zxwx();
			DVec4 zxwy();
			DVec4 zxwz();
			DVec4 zxww();
			DVec4 zyxx();
			DVec4 zyxy();
			DVec4 zyxz();
			DVec4 zyxw();
			DVec4 zyyx();
			DVec4 zyyy();
			DVec4 zyyz();
			DVec4 zyyw();
			DVec4 zyzx();
			DVec4 zyzy();
			DVec4 zyzz();
			DVec4 zyzw();
			DVec4 zywx();
			DVec4 zywy();
			DVec4 zywz();
			DVec4 zyww();
			DVec4 zzxx();
			DVec4 zzxy();
			DVec4 zzxz();
			DVec4 zzxw();
			DVec4 zzyx();
			DVec4 zzyy();
			DVec4 zzyz();
			DVec4 zzyw();
			DVec4 zzzx();
			DVec4 zzzy();
			DVec4 zzzz();
			DVec4 zzzw();
			DVec4 zzwx();
			DVec4 zzwy();
			DVec4 zzwz();
			DVec4 zzww();
			DVec4 zwxx();
			DVec4 zwxy();
			DVec4 zwxz();
			DVec4 zwxw();
			DVec4 zwyx();
			DVec4 zwyy();
			DVec4 zwyz();
			DVec4 zwyw();
			DVec4 zwzx();
			DVec4 zwzy();
			DVec4 zwzz();
			DVec4 zwzw();
			DVec4 zwwx();
			DVec4 zwwy();
			DVec4 zwwz();
			DVec4 zwww();
			DVec4 wxxx();
			DVec4 wxxy();
			DVec4 wxxz();
			DVec4 wxxw();
			DVec4 wxyx();
			DVec4 wxyy();
			DVec4 wxyz();
			DVec4 wxyw();
			DVec4 wxzx();
			DVec4 wxzy();
			DVec4 wxzz();
			DVec4 wxzw();
			DVec4 wxwx();
			DVec4 wxwy();
			DVec4 wxwz();
			DVec4 wxww();
			DVec4 wyxx();
			DVec4 wyxy();
			DVec4 wyxz();
			DVec4 wyxw();
			DVec4 wyyx();
			DVec4 wyyy();
			DVec4 wyyz();
			DVec4 wyyw();
			DVec4 wyzx();
			DVec4 wyzy();
			DVec4 wyzz();
			DVec4 wyzw();
			DVec4 wywx();
			DVec4 wywy();
			DVec4 wywz();
			DVec4 wyww();
			DVec4 wzxx();
			DVec4 wzxy();
			DVec4 wzxz();
			DVec4 wzxw();
			DVec4 wzyx();
			DVec4 wzyy();
			DVec4 wzyz();
			DVec4 wzyw();
			DVec4 wzzx();
			DVec4 wzzy();
			DVec4 wzzz();
			DVec4 wzzw();
			DVec4 wzwx();
			DVec4 wzwy();
			DVec4 wzwz();
			DVec4 wzww();
			DVec4 wwxx();
			DVec4 wwxy();
			DVec4 wwxz();
			DVec4 wwxw();
			DVec4 wwyx();
			DVec4 wwyy();
			DVec4 wwyz();
			DVec4 wwyw();
			DVec4 wwzx();
			DVec4 wwzy();
			DVec4 wwzz();
			DVec4 wwzw();
			DVec4 wwwx();
			DVec4 wwwy();
			DVec4 wwwz();
			DVec4 wwww();

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

			IVec2 xx();
			IVec2 xy();
			IVec2 yx();
			IVec2 yy();

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

			IVec2 xx();
			IVec2 xy();
			IVec2 xz();
			IVec2 yx();
			IVec2 yy();
			IVec2 yz();
			IVec2 zx();
			IVec2 zy();
			IVec2 zz();

			IVec3 xxx();
			IVec3 xxy();
			IVec3 xxz();
			IVec3 xyx();
			IVec3 xyy();
			IVec3 xyz();
			IVec3 xzx();
			IVec3 xzy();
			IVec3 xzz();
			IVec3 yxx();
			IVec3 yxy();
			IVec3 yxz();
			IVec3 yyx();
			IVec3 yyy();
			IVec3 yyz();
			IVec3 yzx();
			IVec3 yzy();
			IVec3 yzz();
			IVec3 zxx();
			IVec3 zxy();
			IVec3 zxz();
			IVec3 zyx();
			IVec3 zyy();
			IVec3 zyz();
			IVec3 zzx();
			IVec3 zzy();
			IVec3 zzz();

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

			IVec2 xx();
			IVec2 xy();
			IVec2 xz();
			IVec2 xw();
			IVec2 yx();
			IVec2 yy();
			IVec2 yz();
			IVec2 yw();
			IVec2 zx();
			IVec2 zy();
			IVec2 zz();
			IVec2 zw();
			IVec2 wx();
			IVec2 wy();
			IVec2 wz();
			IVec2 ww();

			IVec3 xxx();
			IVec3 xxy();
			IVec3 xxz();
			IVec3 xxw();
			IVec3 xyx();
			IVec3 xyy();
			IVec3 xyz();
			IVec3 xyw();
			IVec3 xzx();
			IVec3 xzy();
			IVec3 xzz();
			IVec3 xzw();
			IVec3 xwx();
			IVec3 xwy();
			IVec3 xwz();
			IVec3 xww();
			IVec3 yxx();
			IVec3 yxy();
			IVec3 yxz();
			IVec3 yxw();
			IVec3 yyx();
			IVec3 yyy();
			IVec3 yyz();
			IVec3 yyw();
			IVec3 yzx();
			IVec3 yzy();
			IVec3 yzz();
			IVec3 yzw();
			IVec3 ywx();
			IVec3 ywy();
			IVec3 ywz();
			IVec3 yww();
			IVec3 zxx();
			IVec3 zxy();
			IVec3 zxz();
			IVec3 zxw();
			IVec3 zyx();
			IVec3 zyy();
			IVec3 zyz();
			IVec3 zyw();
			IVec3 zzx();
			IVec3 zzy();
			IVec3 zzz();
			IVec3 zzw();
			IVec3 zwx();
			IVec3 zwy();
			IVec3 zwz();
			IVec3 zww();
			IVec3 wxx();
			IVec3 wxy();
			IVec3 wxz();
			IVec3 wxw();
			IVec3 wyx();
			IVec3 wyy();
			IVec3 wyz();
			IVec3 wyw();
			IVec3 wzx();
			IVec3 wzy();
			IVec3 wzz();
			IVec3 wzw();
			IVec3 wwx();
			IVec3 wwy();
			IVec3 wwz();
			IVec3 www();

			IVec4 xxxx();
			IVec4 xxxy();
			IVec4 xxxz();
			IVec4 xxxw();
			IVec4 xxyx();
			IVec4 xxyy();
			IVec4 xxyz();
			IVec4 xxyw();
			IVec4 xxzx();
			IVec4 xxzy();
			IVec4 xxzz();
			IVec4 xxzw();
			IVec4 xxwx();
			IVec4 xxwy();
			IVec4 xxwz();
			IVec4 xxww();
			IVec4 xyxx();
			IVec4 xyxy();
			IVec4 xyxz();
			IVec4 xyxw();
			IVec4 xyyx();
			IVec4 xyyy();
			IVec4 xyyz();
			IVec4 xyyw();
			IVec4 xyzx();
			IVec4 xyzy();
			IVec4 xyzz();
			IVec4 xyzw();
			IVec4 xywx();
			IVec4 xywy();
			IVec4 xywz();
			IVec4 xyww();
			IVec4 xzxx();
			IVec4 xzxy();
			IVec4 xzxz();
			IVec4 xzxw();
			IVec4 xzyx();
			IVec4 xzyy();
			IVec4 xzyz();
			IVec4 xzyw();
			IVec4 xzzx();
			IVec4 xzzy();
			IVec4 xzzz();
			IVec4 xzzw();
			IVec4 xzwx();
			IVec4 xzwy();
			IVec4 xzwz();
			IVec4 xzww();
			IVec4 xwxx();
			IVec4 xwxy();
			IVec4 xwxz();
			IVec4 xwxw();
			IVec4 xwyx();
			IVec4 xwyy();
			IVec4 xwyz();
			IVec4 xwyw();
			IVec4 xwzx();
			IVec4 xwzy();
			IVec4 xwzz();
			IVec4 xwzw();
			IVec4 xwwx();
			IVec4 xwwy();
			IVec4 xwwz();
			IVec4 xwww();
			IVec4 yxxx();
			IVec4 yxxy();
			IVec4 yxxz();
			IVec4 yxxw();
			IVec4 yxyx();
			IVec4 yxyy();
			IVec4 yxyz();
			IVec4 yxyw();
			IVec4 yxzx();
			IVec4 yxzy();
			IVec4 yxzz();
			IVec4 yxzw();
			IVec4 yxwx();
			IVec4 yxwy();
			IVec4 yxwz();
			IVec4 yxww();
			IVec4 yyxx();
			IVec4 yyxy();
			IVec4 yyxz();
			IVec4 yyxw();
			IVec4 yyyx();
			IVec4 yyyy();
			IVec4 yyyz();
			IVec4 yyyw();
			IVec4 yyzx();
			IVec4 yyzy();
			IVec4 yyzz();
			IVec4 yyzw();
			IVec4 yywx();
			IVec4 yywy();
			IVec4 yywz();
			IVec4 yyww();
			IVec4 yzxx();
			IVec4 yzxy();
			IVec4 yzxz();
			IVec4 yzxw();
			IVec4 yzyx();
			IVec4 yzyy();
			IVec4 yzyz();
			IVec4 yzyw();
			IVec4 yzzx();
			IVec4 yzzy();
			IVec4 yzzz();
			IVec4 yzzw();
			IVec4 yzwx();
			IVec4 yzwy();
			IVec4 yzwz();
			IVec4 yzww();
			IVec4 ywxx();
			IVec4 ywxy();
			IVec4 ywxz();
			IVec4 ywxw();
			IVec4 ywyx();
			IVec4 ywyy();
			IVec4 ywyz();
			IVec4 ywyw();
			IVec4 ywzx();
			IVec4 ywzy();
			IVec4 ywzz();
			IVec4 ywzw();
			IVec4 ywwx();
			IVec4 ywwy();
			IVec4 ywwz();
			IVec4 ywww();
			IVec4 zxxx();
			IVec4 zxxy();
			IVec4 zxxz();
			IVec4 zxxw();
			IVec4 zxyx();
			IVec4 zxyy();
			IVec4 zxyz();
			IVec4 zxyw();
			IVec4 zxzx();
			IVec4 zxzy();
			IVec4 zxzz();
			IVec4 zxzw();
			IVec4 zxwx();
			IVec4 zxwy();
			IVec4 zxwz();
			IVec4 zxww();
			IVec4 zyxx();
			IVec4 zyxy();
			IVec4 zyxz();
			IVec4 zyxw();
			IVec4 zyyx();
			IVec4 zyyy();
			IVec4 zyyz();
			IVec4 zyyw();
			IVec4 zyzx();
			IVec4 zyzy();
			IVec4 zyzz();
			IVec4 zyzw();
			IVec4 zywx();
			IVec4 zywy();
			IVec4 zywz();
			IVec4 zyww();
			IVec4 zzxx();
			IVec4 zzxy();
			IVec4 zzxz();
			IVec4 zzxw();
			IVec4 zzyx();
			IVec4 zzyy();
			IVec4 zzyz();
			IVec4 zzyw();
			IVec4 zzzx();
			IVec4 zzzy();
			IVec4 zzzz();
			IVec4 zzzw();
			IVec4 zzwx();
			IVec4 zzwy();
			IVec4 zzwz();
			IVec4 zzww();
			IVec4 zwxx();
			IVec4 zwxy();
			IVec4 zwxz();
			IVec4 zwxw();
			IVec4 zwyx();
			IVec4 zwyy();
			IVec4 zwyz();
			IVec4 zwyw();
			IVec4 zwzx();
			IVec4 zwzy();
			IVec4 zwzz();
			IVec4 zwzw();
			IVec4 zwwx();
			IVec4 zwwy();
			IVec4 zwwz();
			IVec4 zwww();
			IVec4 wxxx();
			IVec4 wxxy();
			IVec4 wxxz();
			IVec4 wxxw();
			IVec4 wxyx();
			IVec4 wxyy();
			IVec4 wxyz();
			IVec4 wxyw();
			IVec4 wxzx();
			IVec4 wxzy();
			IVec4 wxzz();
			IVec4 wxzw();
			IVec4 wxwx();
			IVec4 wxwy();
			IVec4 wxwz();
			IVec4 wxww();
			IVec4 wyxx();
			IVec4 wyxy();
			IVec4 wyxz();
			IVec4 wyxw();
			IVec4 wyyx();
			IVec4 wyyy();
			IVec4 wyyz();
			IVec4 wyyw();
			IVec4 wyzx();
			IVec4 wyzy();
			IVec4 wyzz();
			IVec4 wyzw();
			IVec4 wywx();
			IVec4 wywy();
			IVec4 wywz();
			IVec4 wyww();
			IVec4 wzxx();
			IVec4 wzxy();
			IVec4 wzxz();
			IVec4 wzxw();
			IVec4 wzyx();
			IVec4 wzyy();
			IVec4 wzyz();
			IVec4 wzyw();
			IVec4 wzzx();
			IVec4 wzzy();
			IVec4 wzzz();
			IVec4 wzzw();
			IVec4 wzwx();
			IVec4 wzwy();
			IVec4 wzwz();
			IVec4 wzww();
			IVec4 wwxx();
			IVec4 wwxy();
			IVec4 wwxz();
			IVec4 wwxw();
			IVec4 wwyx();
			IVec4 wwyy();
			IVec4 wwyz();
			IVec4 wwyw();
			IVec4 wwzx();
			IVec4 wwzy();
			IVec4 wwzz();
			IVec4 wwzw();
			IVec4 wwwx();
			IVec4 wwwy();
			IVec4 wwwz();
			IVec4 wwww();

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

			UVec2 xx();
			UVec2 xy();
			UVec2 yx();
			UVec2 yy();

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

			UVec2 xx();
			UVec2 xy();
			UVec2 xz();
			UVec2 yx();
			UVec2 yy();
			UVec2 yz();
			UVec2 zx();
			UVec2 zy();
			UVec2 zz();

			UVec3 xxx();
			UVec3 xxy();
			UVec3 xxz();
			UVec3 xyx();
			UVec3 xyy();
			UVec3 xyz();
			UVec3 xzx();
			UVec3 xzy();
			UVec3 xzz();
			UVec3 yxx();
			UVec3 yxy();
			UVec3 yxz();
			UVec3 yyx();
			UVec3 yyy();
			UVec3 yyz();
			UVec3 yzx();
			UVec3 yzy();
			UVec3 yzz();
			UVec3 zxx();
			UVec3 zxy();
			UVec3 zxz();
			UVec3 zyx();
			UVec3 zyy();
			UVec3 zyz();
			UVec3 zzx();
			UVec3 zzy();
			UVec3 zzz();

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

			UVec2 xx();
			UVec2 xy();
			UVec2 xz();
			UVec2 xw();
			UVec2 yx();
			UVec2 yy();
			UVec2 yz();
			UVec2 yw();
			UVec2 zx();
			UVec2 zy();
			UVec2 zz();
			UVec2 zw();
			UVec2 wx();
			UVec2 wy();
			UVec2 wz();
			UVec2 ww();

			UVec3 xxx();
			UVec3 xxy();
			UVec3 xxz();
			UVec3 xxw();
			UVec3 xyx();
			UVec3 xyy();
			UVec3 xyz();
			UVec3 xyw();
			UVec3 xzx();
			UVec3 xzy();
			UVec3 xzz();
			UVec3 xzw();
			UVec3 xwx();
			UVec3 xwy();
			UVec3 xwz();
			UVec3 xww();
			UVec3 yxx();
			UVec3 yxy();
			UVec3 yxz();
			UVec3 yxw();
			UVec3 yyx();
			UVec3 yyy();
			UVec3 yyz();
			UVec3 yyw();
			UVec3 yzx();
			UVec3 yzy();
			UVec3 yzz();
			UVec3 yzw();
			UVec3 ywx();
			UVec3 ywy();
			UVec3 ywz();
			UVec3 yww();
			UVec3 zxx();
			UVec3 zxy();
			UVec3 zxz();
			UVec3 zxw();
			UVec3 zyx();
			UVec3 zyy();
			UVec3 zyz();
			UVec3 zyw();
			UVec3 zzx();
			UVec3 zzy();
			UVec3 zzz();
			UVec3 zzw();
			UVec3 zwx();
			UVec3 zwy();
			UVec3 zwz();
			UVec3 zww();
			UVec3 wxx();
			UVec3 wxy();
			UVec3 wxz();
			UVec3 wxw();
			UVec3 wyx();
			UVec3 wyy();
			UVec3 wyz();
			UVec3 wyw();
			UVec3 wzx();
			UVec3 wzy();
			UVec3 wzz();
			UVec3 wzw();
			UVec3 wwx();
			UVec3 wwy();
			UVec3 wwz();
			UVec3 www();

			UVec4 xxxx();
			UVec4 xxxy();
			UVec4 xxxz();
			UVec4 xxxw();
			UVec4 xxyx();
			UVec4 xxyy();
			UVec4 xxyz();
			UVec4 xxyw();
			UVec4 xxzx();
			UVec4 xxzy();
			UVec4 xxzz();
			UVec4 xxzw();
			UVec4 xxwx();
			UVec4 xxwy();
			UVec4 xxwz();
			UVec4 xxww();
			UVec4 xyxx();
			UVec4 xyxy();
			UVec4 xyxz();
			UVec4 xyxw();
			UVec4 xyyx();
			UVec4 xyyy();
			UVec4 xyyz();
			UVec4 xyyw();
			UVec4 xyzx();
			UVec4 xyzy();
			UVec4 xyzz();
			UVec4 xyzw();
			UVec4 xywx();
			UVec4 xywy();
			UVec4 xywz();
			UVec4 xyww();
			UVec4 xzxx();
			UVec4 xzxy();
			UVec4 xzxz();
			UVec4 xzxw();
			UVec4 xzyx();
			UVec4 xzyy();
			UVec4 xzyz();
			UVec4 xzyw();
			UVec4 xzzx();
			UVec4 xzzy();
			UVec4 xzzz();
			UVec4 xzzw();
			UVec4 xzwx();
			UVec4 xzwy();
			UVec4 xzwz();
			UVec4 xzww();
			UVec4 xwxx();
			UVec4 xwxy();
			UVec4 xwxz();
			UVec4 xwxw();
			UVec4 xwyx();
			UVec4 xwyy();
			UVec4 xwyz();
			UVec4 xwyw();
			UVec4 xwzx();
			UVec4 xwzy();
			UVec4 xwzz();
			UVec4 xwzw();
			UVec4 xwwx();
			UVec4 xwwy();
			UVec4 xwwz();
			UVec4 xwww();
			UVec4 yxxx();
			UVec4 yxxy();
			UVec4 yxxz();
			UVec4 yxxw();
			UVec4 yxyx();
			UVec4 yxyy();
			UVec4 yxyz();
			UVec4 yxyw();
			UVec4 yxzx();
			UVec4 yxzy();
			UVec4 yxzz();
			UVec4 yxzw();
			UVec4 yxwx();
			UVec4 yxwy();
			UVec4 yxwz();
			UVec4 yxww();
			UVec4 yyxx();
			UVec4 yyxy();
			UVec4 yyxz();
			UVec4 yyxw();
			UVec4 yyyx();
			UVec4 yyyy();
			UVec4 yyyz();
			UVec4 yyyw();
			UVec4 yyzx();
			UVec4 yyzy();
			UVec4 yyzz();
			UVec4 yyzw();
			UVec4 yywx();
			UVec4 yywy();
			UVec4 yywz();
			UVec4 yyww();
			UVec4 yzxx();
			UVec4 yzxy();
			UVec4 yzxz();
			UVec4 yzxw();
			UVec4 yzyx();
			UVec4 yzyy();
			UVec4 yzyz();
			UVec4 yzyw();
			UVec4 yzzx();
			UVec4 yzzy();
			UVec4 yzzz();
			UVec4 yzzw();
			UVec4 yzwx();
			UVec4 yzwy();
			UVec4 yzwz();
			UVec4 yzww();
			UVec4 ywxx();
			UVec4 ywxy();
			UVec4 ywxz();
			UVec4 ywxw();
			UVec4 ywyx();
			UVec4 ywyy();
			UVec4 ywyz();
			UVec4 ywyw();
			UVec4 ywzx();
			UVec4 ywzy();
			UVec4 ywzz();
			UVec4 ywzw();
			UVec4 ywwx();
			UVec4 ywwy();
			UVec4 ywwz();
			UVec4 ywww();
			UVec4 zxxx();
			UVec4 zxxy();
			UVec4 zxxz();
			UVec4 zxxw();
			UVec4 zxyx();
			UVec4 zxyy();
			UVec4 zxyz();
			UVec4 zxyw();
			UVec4 zxzx();
			UVec4 zxzy();
			UVec4 zxzz();
			UVec4 zxzw();
			UVec4 zxwx();
			UVec4 zxwy();
			UVec4 zxwz();
			UVec4 zxww();
			UVec4 zyxx();
			UVec4 zyxy();
			UVec4 zyxz();
			UVec4 zyxw();
			UVec4 zyyx();
			UVec4 zyyy();
			UVec4 zyyz();
			UVec4 zyyw();
			UVec4 zyzx();
			UVec4 zyzy();
			UVec4 zyzz();
			UVec4 zyzw();
			UVec4 zywx();
			UVec4 zywy();
			UVec4 zywz();
			UVec4 zyww();
			UVec4 zzxx();
			UVec4 zzxy();
			UVec4 zzxz();
			UVec4 zzxw();
			UVec4 zzyx();
			UVec4 zzyy();
			UVec4 zzyz();
			UVec4 zzyw();
			UVec4 zzzx();
			UVec4 zzzy();
			UVec4 zzzz();
			UVec4 zzzw();
			UVec4 zzwx();
			UVec4 zzwy();
			UVec4 zzwz();
			UVec4 zzww();
			UVec4 zwxx();
			UVec4 zwxy();
			UVec4 zwxz();
			UVec4 zwxw();
			UVec4 zwyx();
			UVec4 zwyy();
			UVec4 zwyz();
			UVec4 zwyw();
			UVec4 zwzx();
			UVec4 zwzy();
			UVec4 zwzz();
			UVec4 zwzw();
			UVec4 zwwx();
			UVec4 zwwy();
			UVec4 zwwz();
			UVec4 zwww();
			UVec4 wxxx();
			UVec4 wxxy();
			UVec4 wxxz();
			UVec4 wxxw();
			UVec4 wxyx();
			UVec4 wxyy();
			UVec4 wxyz();
			UVec4 wxyw();
			UVec4 wxzx();
			UVec4 wxzy();
			UVec4 wxzz();
			UVec4 wxzw();
			UVec4 wxwx();
			UVec4 wxwy();
			UVec4 wxwz();
			UVec4 wxww();
			UVec4 wyxx();
			UVec4 wyxy();
			UVec4 wyxz();
			UVec4 wyxw();
			UVec4 wyyx();
			UVec4 wyyy();
			UVec4 wyyz();
			UVec4 wyyw();
			UVec4 wyzx();
			UVec4 wyzy();
			UVec4 wyzz();
			UVec4 wyzw();
			UVec4 wywx();
			UVec4 wywy();
			UVec4 wywz();
			UVec4 wyww();
			UVec4 wzxx();
			UVec4 wzxy();
			UVec4 wzxz();
			UVec4 wzxw();
			UVec4 wzyx();
			UVec4 wzyy();
			UVec4 wzyz();
			UVec4 wzyw();
			UVec4 wzzx();
			UVec4 wzzy();
			UVec4 wzzz();
			UVec4 wzzw();
			UVec4 wzwx();
			UVec4 wzwy();
			UVec4 wzwz();
			UVec4 wzww();
			UVec4 wwxx();
			UVec4 wwxy();
			UVec4 wwxz();
			UVec4 wwxw();
			UVec4 wwyx();
			UVec4 wwyy();
			UVec4 wwyz();
			UVec4 wwyw();
			UVec4 wwzx();
			UVec4 wwzy();
			UVec4 wwzz();
			UVec4 wwzw();
			UVec4 wwwx();
			UVec4 wwwy();
			UVec4 wwwz();
			UVec4 wwww();

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
