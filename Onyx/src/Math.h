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
			Vec2(DVec2 vec);
			Vec2(IVec2 vec);
			Vec2(UVec2 vec);
			Vec2(glm::vec2 vec);

			float magnitude() const;
			void normalize();
			float* data() const;
			bool isZero() const;
			std::string toString() const;

			float getX() const;
			float getY() const;
			glm::vec2 getMVec() const;
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
			Vec3(Vec2 vec, float z);
			Vec3(float x, Vec2 vec);
			Vec3(DVec3 vec);
			Vec3(IVec3 vec);
			Vec3(UVec3 vec);
			Vec3(glm::vec3 vec);

			float magnitude() const;
			void normalize();
			float* data() const;
			bool isZero() const;
			std::string toString() const;

			float getX() const;
			float getY() const;
			float getZ() const;
			glm::vec3 getMVec() const;
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
			Vec4(Vec2 vec, float z, float w);
			Vec4(float x, Vec2 vec, float w);
			Vec4(float x, float y, Vec2 vec);
			Vec4(Vec3 vec, float w);
			Vec4(float x, Vec3 vec);
			Vec4(Vec2 vec1, Vec2 vec2);
			Vec4(DVec4 vec);
			Vec4(IVec4 vec);
			Vec4(UVec4 vec);
			Vec4(glm::vec4 vec);

			float magnitude() const;
			void normalize();
			float* data() const;
			bool isZero() const;
			std::string toString() const;

			float getX() const;
			float getY() const;
			float getZ() const;
			float getW() const;
			glm::vec4 getMVec() const;
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
			DVec2(Vec2 vec);
			DVec2(IVec2 vec);
			DVec2(UVec2 vec);
			DVec2(glm::dvec2 vec);

			double magnitude() const;
			void normalize();
			double* data() const;
			bool isZero() const;
			std::string toString() const;

			double getX() const;
			double getY() const;
			glm::dvec2 getMVec() const;
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
			DVec3(DVec2 vec, double z);
			DVec3(double x, DVec2 vec);
			DVec3(Vec3 vec);
			DVec3(IVec3 vec);
			DVec3(UVec3 vec);
			DVec3(glm::dvec3 vec);

			double magnitude() const;
			void normalize();
			double* data() const;
			bool isZero() const;
			std::string toString() const;

			double getX() const;
			double getY() const;
			double getZ() const;
			glm::dvec3 getMVec() const;
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
			@brief A double vector with four components.
		 */
		class DVec4 : public DVec
		{
		public:
			DVec4();
			DVec4(double xyzw);
			DVec4(double x, double y, double z, double w);
			DVec4(DVec2 vec, double z, double w);
			DVec4(double x, DVec2 vec, double w);
			DVec4(double x, double y, DVec2 vec);
			DVec4(DVec3 vec, double w);
			DVec4(double x, DVec3 vec);
			DVec4(DVec2 vec1, DVec2 vec2);
			DVec4(Vec4 vec);
			DVec4(IVec4 vec);
			DVec4(UVec4 vec);
			DVec4(glm::dvec4 vec);

			double magnitude() const;
			void normalize();
			double* data() const;
			bool isZero() const;
			std::string toString() const;

			double getX() const;
			double getY() const;
			double getZ() const;
			double getW() const;
			glm::dvec4 getMVec() const;
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
			IVec2(Vec2 vec);
			IVec2(DVec2 vec);
			IVec2(UVec2 vec);
			IVec2(glm::ivec2 vec);

			int* data() const;
			bool isZero() const;
			std::string toString() const;

			int getX() const;
			int getY() const;
			glm::ivec2 getMVec() const;

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
			IVec3(IVec2 vec, int z);
			IVec3(int x, IVec2 vec);
			IVec3(Vec3 vec);
			IVec3(DVec3 vec);
			IVec3(UVec3 vec);
			IVec3(glm::ivec3 vec);

			int* data() const;
			bool isZero() const;
			std::string toString() const;

			int getX() const;
			int getY() const;
			int getZ() const;
			glm::ivec3 getMVec() const;

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
			IVec4(IVec2 vec, int z, int w);
			IVec4(int x, IVec2 vec, int w);
			IVec4(int x, int y, IVec2 vec);
			IVec4(IVec3 vec, int w);
			IVec4(int x, IVec3 vec);
			IVec4(IVec2 vec1, IVec2 vec2);
			IVec4(Vec4 vec);
			IVec4(DVec4 vec);
			IVec4(UVec4 vec);
			IVec4(glm::ivec4 vec);

			int* data() const;
			bool isZero() const;
			std::string toString() const;

			int getX() const;
			int getY() const;
			int getZ() const;
			int getW() const;
			glm::ivec4 getMVec() const;

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
			UVec2(glm::uvec2 vec);

			uint* data() const;
			bool isZero() const;
			std::string toString() const;

			uint getX() const;
			uint getY() const;
			glm::uvec2 getMVec() const;

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
			UVec3(UVec2 vec, uint z);
			UVec3(uint x, UVec2 vec);
			UVec3(glm::uvec3 vec);

			uint* data() const;
			bool isZero() const;
			std::string toString() const;

			uint getX() const;
			uint getY() const;
			uint getZ() const;
			glm::uvec3 getMVec() const;

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
			UVec4(UVec2 vec, uint z, uint w);
			UVec4(uint x, UVec2 vec, uint w);
			UVec4(uint x, uint y, UVec2 vec);
			UVec4(UVec3 vec, uint w);
			UVec4(uint x, UVec3 vec);
			UVec4(UVec2 vec1, UVec2 vec2);
			UVec4(glm::uvec4 vec);

			uint* data() const;
			bool isZero() const;
			std::string toString() const;

			uint getX() const;
			uint getY() const;
			uint getZ() const;
			uint getW() const;
			glm::uvec4 getMVec() const;

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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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

			float* data() const;
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
