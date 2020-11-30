
#pragma once

#include "EngineBaseGlobals/EngineBaseApiPrefix.h"


    

#define GLM_FORCE_RADIANS
#define GLM_FORECE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_SILENT_WARNINGS

/*
Inception Engine use a left-hand coordinate system. positive-x is to the right,
positive-y is to the up, and positive-z goes into the screen.
*/
#define GLM_FORCE_RIGHT_HANDED

#include "External/glm/glm.hpp"
#include "External/glm/gtc/matrix_transform.hpp"
#include "External/glm/gtx/string_cast.hpp"
#include "External/glm/gtx/quaternion.hpp"
#include "External/glm/gtx/rotate_vector.hpp"
#include "External/glm/gtx/matrix_decompose.hpp"

#include <vector>
#include <random>

namespace inceptionengine
{
	using Vec4f = glm::vec4;
	using Vec3f = glm::vec3;
	using Vec4ui = glm::uvec4;

	using Matrix4x4f = glm::mat4x4;
	using Quaternion4f = glm::quat;


	inline Matrix4x4f LookAt(Vec3f const& pos, Vec3f const& forward, Vec3f const& up)
	{
		return glm::lookAt(pos, forward, up);
	}

	inline Matrix4x4f Perspective(float degrees, float aspect, float near, float far)
	{
		return glm::perspective(glm::radians(degrees), aspect, near, far);
	}

	inline Matrix4x4f Inverse(Matrix4x4f const& mat)
	{
		return glm::inverse(mat);
	}

	inline Vec3f NormalizeVec(Vec3f const& vec)
	{
		return glm::normalize(vec);
	}

	inline Vec4f NormalizeVec(Vec4f const& vec)
	{
		return glm::normalize(vec);
	}

	inline float VecLength(Vec4f const& vec)
	{
		return glm::length(vec);
	}

	inline float VecLength(Vec3f const& vec)
	{
		return glm::length(vec);
	}

	inline Vec3f CrossProduct(Vec3f const& u, Vec3f const& v)
	{
		return glm::cross(u, v);
	}

	inline Vec4f Rotate(Vec4f const& point, float degree, Vec3f const& axis)
	{
		return glm::rotate(point, glm::radians(degree), axis);
	}


	inline Matrix4x4f Scale(float x, float y, float z)
	{
		return glm::scale(Vec3f(x, y, z));
	}

	inline Matrix4x4f Translate(float x, float y, float z)
	{
		return glm::translate(Vec3f(x, y, z));
	}

	inline std::vector<Matrix4x4f> GetIdentityTransfromVector(size_t num)
	{
		std::vector<Matrix4x4f> res;
		res.resize(num);
		return res;
	}

	inline float DotProduct(Vec3f const& x, Vec3f const& y)
	{
		return glm::dot(x, y);
	}

	inline Matrix4x4f FromToRotation(Vec3f x, Vec3f y)
	{
		x = NormalizeVec(x);
		y = NormalizeVec(y);
		auto axis = CrossProduct(x, y);
		float cosAngle = DotProduct(x, y);
		float angle = glm::acos(cosAngle);
		return glm::rotate(angle, axis);
	}
	
	inline Matrix4x4f Translation(Vec4f const& vec)
	{
		return glm::translate(Vec3f(vec));

	}
	inline Matrix4x4f Translation(Vec3f const& vec)
	{
		return glm::translate(vec);
	}

	
	inline std::string VecToString(Vec3f const& vec)
	{
		return glm::to_string(vec);
	}

	inline std::string VecToString(Vec4f const& vec)
	{
		return glm::to_string(vec);
	}

	inline void Decompose(Matrix4x4f const& matrix)
	{
		//TODO
	}

	inline Matrix4x4f Compose(Vec3f const& T, Quaternion4f const& R, Vec3f const& S)
	{
		return glm::translate(T) * glm::toMat4(R) * glm::scale(S);
	}

	inline Matrix4x4f Compose(Vec4f const& T, Quaternion4f const& R, Vec4f const& S)
	{
		return glm::translate(Vec3f(T.x, T.y, T.z)) * glm::toMat4(R) * glm::scale(Vec3f(S.x, S.y, S.z));
	}


	float Adder(float a, float b);

	inline float RandFloat(float min, float max)
	{
		return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	}

	inline int RandInt(int min, int max)
	{
		return 0;
	}

	inline float Distance2(Matrix4x4f const& mat1, Matrix4x4f const& mat2)
	{
		return glm::distance2(mat1[0], mat2[0]) + glm::distance2(mat1[1], mat2[1]) + glm::distance2(mat1[2], mat2[2]) + glm::distance2(mat1[3], mat2[3]);
	}

	inline float Distance(Matrix4x4f const& mat1, Matrix4x4f const& mat2)
	{
		return glm::sqrt(Distance2(mat1, mat2));
	}
}
