/*
 * @file A header file containing wrapper classes for vector and matrix math.
 */

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Onyx
{

	/*
	 * @brief A namespace providing access to classes for vector and matrix math.
	 * These classes are wrapper classes that use GLM for the underlying mathematics.
	 */
	namespace Math
	{
		/*
		 * @brief Converts a degree angle measure to radians.
		 * @param degrees The degree angle measure.
		 * @return The resulting radian angle measure.
		 */
		float Radians(float degrees);

		/*
		 * @brief Converts a radian angle measure to degrees.
		 * @param radians The radian angle measure.
		 * @return The resulting degree angle measure.
		 */
		float Degrees(float radians);

		/*
		 * @brief A parent class for vectors.
		 */
		class Vec {};

		/*
		 * @brief A vector with two components.
		 */
		class Vec2 : public Vec
		{
		public:
			Vec2();
			Vec2(float xy);
			Vec2(float x, float y);
			Vec2(glm::vec2 vec);

			float magnitude();
			void normalize();
			float* data();

			float getX();
			float getY();
			glm::vec2 getMVec();
			Vec2 getNormalized();

			void setX(float x);
			void setY(float y);

			friend float Dot(const Vec2& vec1, const Vec2& vec2);

			Vec2 operator+(const Vec2& vec);
			Vec2 operator-();
			Vec2 operator-(const Vec2& vec);
			Vec2 operator*(const float& scalar);

		private:
			glm::vec2 m_vec;
		};

		/*
		 * @brief A vector with three components.
		 */
		class Vec3 : public Vec
		{
		public:
			Vec3();
			Vec3(float xyz);
			Vec3(float x, float y, float z);
			Vec3(glm::vec3 vec);

			float magnitude();
			void normalize();
			float* data();

			float getX();
			float getY();
			float getZ();
			glm::vec3 getMVec();
			Vec3 getNormalized();

			void setX(float x);
			void setY(float y);
			void setZ(float z);

			friend Vec3 Cross(const Vec3& vec1, const Vec3& vec2);
			friend float Dot(const Vec3& vec1, const Vec3& vec2);

			Vec3 operator+(const Vec3& vec);
			Vec3 operator-();
			Vec3 operator-(const Vec3& vec);
			Vec3 operator*(const float& scalar);

		private:
			glm::vec3 m_vec;
		};

		/*
		 * @brief A vector with four components.
		 */
		class Vec4 : public Vec
		{
		public:
			Vec4();
			Vec4(float xyzw);
			Vec4(float x, float y, float z, float w);
			Vec4(glm::vec4 vec);

			float magnitude();
			void normalize();
			float* data();

			float getX();
			float getY();
			float getZ();
			float getW();
			glm::vec4 getMVec();
			Vec4 getNormalized();

			void setX(float x);
			void setY(float y);
			void setZ(float z);
			void setW(float w);

			friend float Dot(const Vec4& vec1, const Vec4& vec2);

			Vec4 operator+(const Vec4& vec);
			Vec4 operator-();
			Vec4 operator-(const Vec4& vec);
			Vec4 operator*(const float& scalar);

		private:
			glm::vec4 m_vec;
		};

		/*
		 * @brief The cross product vector operation between 3D vectors.
		 * @return The resulting vector.
		 */
		Vec3 Cross(const Vec3& vec1, const Vec3& vec2);

		/*
		 * @brief The dot product vector operation between 2D vectors.
		 * @return The resulting scalar value.
		 */
		float Dot(const Vec2& vec1, const Vec2& vec2);

		/*
		 * @brief The dot product vector operation between 3D vectors.
		 * @return The resulting scalar value.
		 */
		float Dot(const Vec3& vec1, const Vec3& vec2);

		/*
		 * @brief The dot product vector operation between 4D vectors.
		 * @return The resulting scalar value.
		 */
		float Dot(const Vec4& vec1, const Vec4& vec2);

		/*
		 * @brief A parent class for double vectors.
		 */
		class DVec : public Vec {};

		/*
		 * @brief A double vector with two components.
		 */
		class DVec2 : public DVec
		{
		public:
			DVec2();
			DVec2(double xy);
			DVec2(double x, double y);
			DVec2(glm::dvec2 vec);

			double magnitude();
			void normalize();
			double* data();

			double getX();
			double getY();
			glm::dvec2 getMVec();
			DVec2 getNormalized();

			void setX(double x);
			void setY(double y);

		private:
			glm::dvec2 m_vec;
		};

		/*
		 * @brief A double vector with three components.
		 */
		class DVec3 : public DVec
		{
		public:
			DVec3();
			DVec3(double xyz);
			DVec3(double x, double y, double z);
			DVec3(glm::dvec3 vec);

			double magnitude();
			void normalize();
			double* data();

			double getX();
			double getY();
			double getZ();
			glm::dvec3 getMVec();
			DVec3 getNormalized();

			void setX(double x);
			void setY(double y);
			void setZ(double z);

		private:
			glm::dvec3 m_vec;
		};

		/*
		 * @brief A double vector with four components.
		 */
		class DVec4 : public DVec
		{
		public:
			DVec4();
			DVec4(double xyzw);
			DVec4(double x, double y, double z, double w);
			DVec4(glm::dvec4 vec);

			double magnitude();
			void normalize();
			double* data();

			double getX();
			double getY();
			double getZ();
			double getW();
			glm::dvec4 getMVec();
			DVec4 getNormalized();

			void setX(double x);
			void setY(double y);
			void setZ(double z);
			void setW(double w);

		private:
			glm::dvec4 m_vec;
		};

		/*
		 * @brief A parent class for integer vectors.
		 */
		class IVec : public Vec {};

		/*
		 * @brief An integer vector with two components.
		 */
		class IVec2 : public IVec
		{
		public:
			IVec2();
			IVec2(int xy);
			IVec2(int x, int y);
			IVec2(glm::ivec2 vec);

			int* data();

			int getX();
			int getY();
			glm::ivec2 getMVec();

			void setX(int x);
			void setY(int y);

		private:
			glm::ivec2 m_vec;
		};

		/*
		 * @brief An integer vector with three components.
		 */
		class IVec3 : public IVec
		{
		public:
			IVec3();
			IVec3(int xyz);
			IVec3(int x, int y, int z);
			IVec3(glm::ivec3 vec);

			int* data();

			int getX();
			int getY();
			int getZ();
			glm::ivec3 getMVec();

			void setX(int x);
			void setY(int y);
			void setZ(int z);

		private:
			glm::ivec3 m_vec;
		};

		/*
		 * @brief An integer vector with four components.
		 */
		class IVec4 : public IVec
		{
		public:
			IVec4();
			IVec4(int xyzw);
			IVec4(int x, int y, int z, int w);
			IVec4(glm::ivec4 vec);

			int* data();

			int getX();
			int getY();
			int getZ();
			int getW();
			glm::ivec4 getMVec();

			void setX(int x);
			void setY(int y);
			void setZ(int z);
			void setW(int w);

		private:
			glm::ivec4 m_vec;
		};

		/*
		 * @brief A parent class for matrices.
		 */
		class Mat
		{
			virtual float* data() = 0;
		};

		/*
		 * @brief A matrix with dimensions 2x2
		 */
		class Mat2x2 : public Mat
		{
		public:
			Mat2x2();
			Mat2x2(float scalar);
			Mat2x2(glm::mat2x2 mat);

			glm::mat2x2 getMMat();

			float* data();

			Mat2x2 operator+(const Mat2x2& mat);
			Mat2x2 operator-(const Mat2x2& mat);

			static Mat2x2 Identity();

		private:
			glm::mat2x2 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 2x3
		 */
		class Mat2x3 : public Mat
		{
		public:
			Mat2x3();
			Mat2x3(float scalar);
			Mat2x3(glm::mat2x3 mat);

			glm::mat2x3 getMMat();

			float* data();

			Mat2x3 operator+(const Mat2x3& mat);
			Mat2x3 operator-(const Mat2x3& mat);

			static Mat2x3 Identity();

		private:
			glm::mat2x3 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 2x4
		 */
		class Mat2x4 : public Mat
		{
		public:
			Mat2x4();
			Mat2x4(float scalar);
			Mat2x4(glm::mat2x4 mat);

			glm::mat2x4 getMMat();

			float* data();

			Mat2x4 operator+(const Mat2x4& mat);
			Mat2x4 operator-(const Mat2x4& mat);

			static Mat2x4 Identity();

		private:
			glm::mat2x4 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 3x2
		 */
		class Mat3x2 : public Mat
		{
		public:
			Mat3x2();
			Mat3x2(float scalar);
			Mat3x2(glm::mat3x2 mat);

			glm::mat3x2 getMMat();

			float* data();

			Mat3x2 operator+(const Mat3x2& mat);
			Mat3x2 operator-(const Mat3x2& mat);

			static Mat3x2 Identity();

		private:
			glm::mat3x2 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 3x3
		 */
		class Mat3x3 : public Mat
		{
		public:
			Mat3x3();
			Mat3x3(float scalar);
			Mat3x3(glm::mat3x3 mat);

			glm::mat3x3 getMMat();

			float* data();

			Mat3x3 operator+(const Mat3x3& mat);
			Mat3x3 operator-(const Mat3x3& mat);

			static Mat3x3 Identity();

		private:
			glm::mat3x3 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 3x4
		 */
		class Mat3x4 : public Mat
		{
		public:
			Mat3x4();
			Mat3x4(float scalar);
			Mat3x4(glm::mat3x4 mat);

			glm::mat3x4 getMMat();

			float* data();

			Mat3x4 operator+(const Mat3x4& mat);
			Mat3x4 operator-(const Mat3x4& mat);

			static Mat3x4 Identity();

		private:
			glm::mat3x4 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 4x2
		 */
		class Mat4x2 : public Mat
		{
		public:
			Mat4x2();
			Mat4x2(float scalar);
			Mat4x2(glm::mat4x2 mat);

			glm::mat4x2 getMMat();

			float* data();

			Mat4x2 operator+(const Mat4x2& mat);
			Mat4x2 operator-(const Mat4x2& mat);

			static Mat4x2 Identity();

		private:
			glm::mat4x2 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 4x3
		 */
		class Mat4x3 : public Mat
		{
		public:
			Mat4x3();
			Mat4x3(float scalar);
			Mat4x3(glm::mat4x3 mat);

			glm::mat4x3 getMMat();

			float* data();

			Mat4x3 operator+(const Mat4x3& mat);
			Mat4x3 operator-(const Mat4x3& mat);

			static Mat4x3 Identity();

		private:
			glm::mat4x3 m_mat;
		};

		/*
		 * @brief A matrix with dimensions 4x4
		 */
		class Mat4x4 : public Mat
		{
		public:
			Mat4x4();
			Mat4x4(float scalar);
			Mat4x4(glm::mat4x4 mat);

			void translate(Vec3 xyz);
			void rotate(float degrees, Vec3 xyzMultiplier);
			void scale(Vec3 xyzMultiplier);

			glm::mat4x4 getMMat();

			float* data();

			Mat4x4 operator+(const Mat4x4& mat);
			Mat4x4 operator-(const Mat4x4& mat);

			static Mat4x4 Identity();

		private:
			glm::mat4x4 m_mat;
		};

		Mat2x2 operator*(Mat2x2& mat1, Mat2x2& mat2);
		Mat2x2 operator*(Mat2x3& mat1, Mat3x2& mat2);
		Mat2x2 operator*(Mat2x4& mat1, Mat4x2& mat2);

		Mat3x3 operator*(Mat3x2& mat1, Mat2x3& mat2);
		Mat3x3 operator*(Mat3x3& mat1, Mat3x3& mat2);
		Mat3x3 operator*(Mat3x4& mat1, Mat4x3& mat2);

		Mat4x4 operator*(Mat4x2& mat1, Mat2x4& mat2);
		Mat4x4 operator*(Mat4x3& mat1, Mat3x4& mat2);
		Mat4x4 operator*(Mat4x4& mat1, Mat4x4& mat2);


		Vec2 operator*(Mat2x2& mat, Vec2& vec);
		Vec2 operator*(Mat2x3& mat, Vec3& vec);
		Vec2 operator*(Mat2x4& mat, Vec4& vec);

		Vec3 operator*(Mat3x3& mat, Vec3& vec);
		Vec3 operator*(Mat3x4& mat, Vec4& vec);

		Vec4 operator*(Mat4x4& mat, Vec4& vec);

		/*
		 * @brief A matrix with dimensions 2x2
		 */
		typedef Mat2x2 Mat2;

		/*
		 * @brief A matrix with dimensions 3x3
		 */
		typedef Mat3x3 Mat3;

		/*
		 * @brief A matrix with dimensions 4x4
		 */
		typedef Mat4x4 Mat4;

		Mat4x4 LookAt(Vec3 pos, Vec3 target, Vec3 up);
		Mat4x4 OrthographicProjection(float left, float right, float top, float bottom);
		Mat4x4 PerspectiveProjection(float fov, float aspectRatio, float nearPlane, float farPlane);
	}
}
