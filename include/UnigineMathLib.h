/* Copyright (C) 2005-2025, UNIGINE. All rights reserved.
*
* This file is a part of the UNIGINE 2 SDK.
*
* Your use and / or redistribution of this software in source and / or
* binary form, with or without modification, is subject to: (i) your
* ongoing acceptance of and compliance with the terms and conditions of
* the UNIGINE License Agreement; and (ii) your inclusion of this notice
* in any version of this software that you use or redistribute.
* A copy of the UNIGINE License Agreement is available by contacting
* UNIGINE. at http://unigine.com/
*/

#pragma once
#include "UnigineMathLibCommon.h"

#include "UnigineMathLibVec2.h"
#include "UnigineMathLibVec3.h"
#include "UnigineMathLibVec4.h"

#include "UnigineMathLibDVec2.h"
#include "UnigineMathLibDVec3.h"
#include "UnigineMathLibDVec4.h"

#include "UnigineMathLibHVec2.h"
#include "UnigineMathLibHVec3.h"
#include "UnigineMathLibHVec4.h"

#include "UnigineMathLibIVec2.h"
#include "UnigineMathLibIVec3.h"
#include "UnigineMathLibIVec4.h"

#include "UnigineMathLibSVec4.h"
#include "UnigineMathLibBVec4.h"

#include "UnigineMathLibMat2.h"
#include "UnigineMathLibMat3.h"
#include "UnigineMathLibMat4.h"

#include "UnigineMathLibDMat4.h"

#include "UnigineMathLibQuat.h"

#include "UnigineMathLibSimd.h"
#include "UnigineMathLibGeometry.h"
#include "UnigineMathLibNumerical.h"
#include "UnigineMathLibRandom.h"
#include "UnigineMathLibNoise.h"
#include "UnigineMathLibSHBasis.h"
#include "UnigineMathLibColorSpaces.h"

namespace Unigine
{
namespace Math
{

static_assert(sizeof(vec2) == 2 * sizeof(float), "struct size must remain unchanged");
static_assert(sizeof(vec3) == 4 * sizeof(float), "struct size must remain unchanged");
static_assert(sizeof(vec4) == 4 * sizeof(float), "struct size must remain unchanged");
static_assert(sizeof(dvec2) == 2 * sizeof(double), "struct size must remain unchanged");
static_assert(sizeof(dvec3) == 4 * sizeof(double), "struct size must remain unchanged");
static_assert(sizeof(dvec4) == 4 * sizeof(double), "struct size must remain unchanged");
static_assert(sizeof(hvec2) == 2 * sizeof(half), "struct size must remain unchanged");
static_assert(sizeof(hvec3) == 4 * sizeof(half), "struct size must remain unchanged");
static_assert(sizeof(hvec4) == 4 * sizeof(half), "struct size must remain unchanged");
static_assert(sizeof(ivec2) == 2 * sizeof(int), "struct size must remain unchanged");
static_assert(sizeof(ivec3) == 4 * sizeof(int), "struct size must remain unchanged");
static_assert(sizeof(ivec4) == 4 * sizeof(int), "struct size must remain unchanged");
static_assert(sizeof(bvec4) == 4 * sizeof(unsigned char), "struct size must remain unchanged");
static_assert(sizeof(svec4) == 4 * sizeof(unsigned short), "struct size must remain unchanged");
static_assert(sizeof(mat2) == 4 * sizeof(float), "struct size must remain unchanged");
static_assert(sizeof(mat3) == 12 * sizeof(float), "struct size must remain unchanged");
static_assert(sizeof(mat4) == 16 * sizeof(float), "struct size must remain unchanged");
static_assert(sizeof(dmat4) == 12 * sizeof(double), "struct size must remain unchanged");
static_assert(sizeof(quat) == 4 * sizeof(float), "struct size must remain unchanged");

//////////////////////////////////////////////////////////////////////////
// vec2
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given three-component vec3 source vector: x=v.x, y=v.y.</summary>
UNIGINE_INLINE vec2::vec2(const vec3 &v)
	: x(v.x)
	, y(v.y)
{
	UNIGINE_ASSERT_ALIGNED8(this);
}
/// <summary>Constructor. Initializes the vector using a given four-component vec4 source vector: x=v.x, y=v.y.</summary>
UNIGINE_INLINE vec2::vec2(const vec4 &v)
	: x(v.x)
	, y(v.y)
{
	UNIGINE_ASSERT_ALIGNED8(this);
}
/// <summary>Constructor. Initializes the vector using a given dvec2 source vector.</summary>
UNIGINE_INLINE vec2::vec2(const dvec2 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
{
	UNIGINE_ASSERT_ALIGNED8(this);
}
/// <summary>Constructor. Initializes the vector using a given ivec2 source vector.</summary>
UNIGINE_INLINE vec2::vec2(const ivec2 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
{
	UNIGINE_ASSERT_ALIGNED8(this);
}
/// <summary>Constructor. Initializes the vector using a given hvec2 source vector.</summary>
UNIGINE_INLINE vec2::vec2(const hvec2 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
{
	UNIGINE_ASSERT_ALIGNED8(this);
}

/// <summary>Performs componentwise division of vectors.</summary>
UNIGINE_INLINE vec2 operator/(const vec2 &v0, const ivec2 &v1) { return vec2(v0.x / v1.x, v0.y / v1.y); }
/// <summary>Returns the result of division of the vector by the value of the specified arguments.</summary>
UNIGINE_INLINE vec2 &vec2::operator/=(const ivec2 &val) { x /= val.x; y /= val.y; return *this; }

/// <summary>Returns a vector containing the largest integral values each being less than or equal to the corresponding vector component.</summary>
UNIGINE_INLINE ivec2 vec2::floor() const
{
	return ivec2(toInt(Math::floor(x)), toInt(Math::floor(y)));
}
/// <summary>Returns a vector containing the smallest integral values each being greater than or equal to the corresponding vector component.</summary>
UNIGINE_INLINE ivec2 vec2::ceil() const
{
	return ivec2(toInt(Math::ceil(x)), toInt(Math::ceil(y)));
}

//////////////////////////////////////////////////////////////////////////
// vec3
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given four-component vec4 source vector: x=v.x, y=v.y, z=v.z.</summary>
UNIGINE_INLINE vec3::vec3(const vec4 &v)
{
	UNIGINE_ASSERT_ALIGNED16(this);
	#ifdef USE_SSE
		vec = v.vec;
	#else
		x = v.x;
		y = v.y;
		z = v.z;
		w = 0.0f;
	#endif
}
/// <summary>Constructor. Initializes the vector using a given hvec3 source vector.</summary>
UNIGINE_INLINE vec3::vec3(const hvec3 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
	, z(toFloat(v.z))
	, align(0.0f)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given dvec3 source vector.</summary>
UNIGINE_INLINE vec3::vec3(const dvec3 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
	, z(toFloat(v.z))
	, align(0.0f)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

#ifdef USE_SSE
	UNIGINE_INLINE vec3::vec3(const ivec3 &v)
	{
		UNIGINE_ASSERT_ALIGNED16(this);
		vec = _mm_cvtepi32_ps(v.vec);
	}
#else
	UNIGINE_INLINE vec3::vec3(const ivec3 &v)
		: x(toFloat(v.x))
		, y(toFloat(v.y))
		, z(toFloat(v.z))
		, align(0.0f)
	{
	}
#endif

/// <summary>Sets the vector using a vec4 source vector: x=v.x, y=v.y, z=v.z.</summary>
UNIGINE_INLINE void vec3::set(const vec4 &v)
{
	#ifdef USE_SSE
		vec = v.vec;
	#else
		x = v.x;
		y = v.y;
		z = v.z;
		w = 0.0f;
	#endif
}

//////////////////////////////////////////////////////////////////////////
// vec4
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given dvec4 source vector.</summary>
UNIGINE_INLINE vec4::vec4(const dvec4 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
	, z(toFloat(v.z))
	, w(toFloat(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using given two dvec2 source vectors.</summary>
UNIGINE_INLINE vec4::vec4(const dvec2 &v0, const dvec2 & v1)
	: x(toFloat(v0.x))
	, y(toFloat(v0.y))
	, z(toFloat(v1.x))
	, w(toFloat(v1.y))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given hvec4 source vector.</summary>
UNIGINE_INLINE vec4::vec4(const hvec4 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
	, z(toFloat(v.z))
	, w(toFloat(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given svec4 source vector.</summary>
UNIGINE_INLINE vec4::vec4(const svec4 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
	, z(toFloat(v.z))
	, w(toFloat(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given bvec4 source vector.</summary>
UNIGINE_INLINE vec4::vec4(const bvec4 &v)
	: x(toFloat(v.x))
	, y(toFloat(v.y))
	, z(toFloat(v.z))
	, w(toFloat(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

#ifdef USE_SSE
	UNIGINE_INLINE vec4::vec4(const ivec4 &v)
	{
		UNIGINE_ASSERT_ALIGNED16(this);
		vec = _mm_cvtepi32_ps(v.vec);
	}
#else
	UNIGINE_INLINE vec4::vec4(const ivec4 &v)
		: x(toFloat(v.x))
		, y(toFloat(v.y))
		, z(toFloat(v.z))
		, w(toFloat(v.w))
	{}
#endif

/// <summary>Sets the vector using a quaternion.</summary>
UNIGINE_INLINE void vec4::set(const quat &q)
{
	#ifdef USE_SSE
		vec = q.vec;
	#else
		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;
	#endif
}

/// <summary>Converts a color string in the Web format (RRGGBB / #RRGGBB or RRGGBBAA / #RRGGBBAA) into its vec4 equivalent.</summary>
UNIGINE_INLINE vec4 vec4::parseColor(const char *str)
{
	int length = (int)strlen(str);
	ivec4 c = ivec4(255);
	if (length == 6 && String::sscanf(str, "%02x%02x%02x", &c.x, &c.y, &c.z) == 3)
		return vec4(c) / 255.0f;
	else if (length == 7 && String::sscanf(str, "#%02x%02x%02x", &c.x, &c.y, &c.z) == 3)
		return vec4(c) / 255.0f;
	else if (length == 8 && String::sscanf(str, "%02x%02x%02x%02x", &c.x, &c.y, &c.z, &c.w) == 4)
		return vec4(c) / 255.0f;
	else if (length == 9 && String::sscanf(str, "#%02x%02x%02x%02x", &c.x, &c.y, &c.z, &c.w) == 4)
		return vec4(c) / 255.0f;
	else
		Log::error("vec4::parseColor(): bad color format \"%s\"\n", str);
	return vec4(1.0f, 0.0f, 0.0f, 1.0f);
}

//////////////////////////////////////////////////////////////////////////
// dvec2
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given three-component vec3 vector: x=v.x, y=v.y.</summary>
UNIGINE_INLINE dvec2::dvec2(const dvec3 &v)
	: x(v.x)
	, y(v.y)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given four-component vec4 source vector: x=v.x, y=v.y.</summary>
UNIGINE_INLINE dvec2::dvec2(const dvec4 &v)
	: x(v.x)
	, y(v.y)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given ivec2 source vector.</summary>
UNIGINE_INLINE dvec2::dvec2(const ivec2 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given hvec2 source vector.</summary>
UNIGINE_INLINE dvec2::dvec2(const hvec2 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

/// <summary>Returns a vector containing the largest integral values each being less than or equal to the corresponding vector component.</summary>
UNIGINE_INLINE ivec2 dvec2::floor() const
{
	return ivec2(toInt(Math::floor(x)), toInt(Math::floor(y)));
}
/// <summary>Returns a vector containing the smallest integral values each being greater than or equal to the corresponding vector component.</summary>
UNIGINE_INLINE ivec2 dvec2::ceil() const
{
	return ivec2(toInt(Math::ceil(x)), toInt(Math::ceil(y)));
}

//////////////////////////////////////////////////////////////////////////
// dvec3
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given four-component dvec4 source vector: x=v.x, y=v.y, z=v.z.</summary>
UNIGINE_INLINE dvec3::dvec3(const dvec4 &v): x(v.x), y(v.y), z(v.z), align(0) {}
UNIGINE_INLINE dvec3::dvec3(const hvec3 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
	, z(toDouble(v.z))
	, align(0)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given ivec3 source vector.</summary>
UNIGINE_INLINE dvec3::dvec3(const ivec3 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
	, z(toDouble(v.z))
	, align(0)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

//////////////////////////////////////////////////////////////////////////
// dvec4
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given hvec4 source vector.</summary>
UNIGINE_INLINE dvec4::dvec4(const hvec4 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
	, z(toDouble(v.z))
	, w(toDouble(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given ivec4 source vector.</summary>
UNIGINE_INLINE dvec4::dvec4(const ivec4 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
	, z(toDouble(v.z))
	, w(toDouble(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given svec4 source vector.</summary>
UNIGINE_INLINE dvec4::dvec4(const svec4 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
	, z(toDouble(v.z))
	, w(toDouble(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given bvec4 source vector.</summary>
UNIGINE_INLINE dvec4::dvec4(const bvec4 &v)
	: x(toDouble(v.x))
	, y(toDouble(v.y))
	, z(toDouble(v.z))
	, w(toDouble(v.w))
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

//////////////////////////////////////////////////////////////////////////
// ivec3
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given ivec4 source vector.</summary>
UNIGINE_INLINE ivec3::ivec3(const ivec4 &v)
	: x(v.x)
	, y(v.y)
	, z(v.z)
	, align(0)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

//////////////////////////////////////////////////////////////////////////
// ivec4
//////////////////////////////////////////////////////////////////////////
/// <summary>Constructor. Initializes the vector using a given svec4 source vector.</summary>
UNIGINE_INLINE ivec4::ivec4(const svec4 &v)
	: x(v.x)
	, y(v.y)
	, z(v.z)
	, w(v.w)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}
/// <summary>Constructor. Initializes the vector using a given bvec4 source vector.</summary>
UNIGINE_INLINE ivec4::ivec4(const bvec4 & v)
	: x(v.x)
	, y(v.y)
	, z(v.z)
	, w(v.w)
{
	UNIGINE_ASSERT_ALIGNED16(this);
}

//////////////////////////////////////////////////////////////////////////
// mat2
//////////////////////////////////////////////////////////////////////////
/// <summary>Sets the matrix using a given mat3 source matrix (3x3). Values m00, m01, m10, m11 from the source matrix are used.</summary>
UNIGINE_INLINE void mat2::set(const mat3 &m)
{
	m00 = m.m00;
	m01 = m.m01;
	m10 = m.m10;
	m11 = m.m11;
}
/// <summary>Sets the matrix using a given mat4 source matrix (4x4). Values m00, m01, m10, m11 from the source matrix are used.</summary>
UNIGINE_INLINE void mat2::set(const mat4 &m)
{
	m00 = m.m00;
	m01 = m.m01;
	m10 = m.m10;
	m11 = m.m11;
}
/// <summary>Sets the matrix using a given dmat4 source matrix (3x4). Values m00, m01, m10, m11 from the source matrix are used.</summary>
UNIGINE_INLINE void mat2::set(const dmat4 &m)
{
	m00 = toFloat(m.m00);
	m01 = toFloat(m.m01);
	m10 = toFloat(m.m10);
	m11 = toFloat(m.m11);
}

//////////////////////////////////////////////////////////////////////////
// mat3
//////////////////////////////////////////////////////////////////////////
/// <summary>Sets the matrix using a given mat4 source matrix (4x4). The matrix elements are set equal to corresponding elements of the source matrix.</summary>
UNIGINE_INLINE void mat3::set(const mat4 &m)
{
	#ifdef USE_SSE
		sse.v0 = m.sse.v0;
		sse.v1 = m.sse.v1;
		sse.v2 = m.sse.v2;
	#else
		m00 = m.m00;
		m01 = m.m01;
		m02 = m.m02;
		m10 = m.m10;
		m11 = m.m11;
		m12 = m.m12;
		m20 = m.m20;
		m21 = m.m21;
		m22 = m.m22;
	#endif
}
/// <summary>Sets the matrix using a given dmat4 source matrix (3x4). The matrix elements are set equal to corresponding elements of the source matrix.</summary>
UNIGINE_INLINE void mat3::set(const dmat4 &m)
{
	m00 = toFloat(m.m00);
	m01 = toFloat(m.m01);
	m02 = toFloat(m.m02);
	m10 = toFloat(m.m10);
	m11 = toFloat(m.m11);
	m12 = toFloat(m.m12);
	m20 = toFloat(m.m20);
	m21 = toFloat(m.m21);
	m22 = toFloat(m.m22);
}
/// <summary>Sets the matrix using a given source quaternion.</summary>
UNIGINE_INLINE void mat3::set(const quat &q)
{
	*this = q.getMat3();
}
/// <summary>Returns the quaternion of the matrix values.</summary>
UNIGINE_INLINE quat mat3::getQuat() const
{
	quat ret;
	float trace = m00 + m11 + m22;
	if (trace > 0.0f)
	{
		float s = Math::fsqrt(trace + 1.0f);
		ret.w = s * 0.5f;
		s = Math::rcp(s) * 0.5f;
		ret.x = (m21 - m12) * s;
		ret.y = (m02 - m20) * s;
		ret.z = (m10 - m01) * s;
	} else if (m00 > m11 && m00 > m22)
	{
		float s = Math::fsqrt(m00 - m11 - m22 + 1.0f);
		ret.x = s * 0.5f;
		s = Math::rcp(s) * 0.5f;
		ret.y = (m10 + m01) * s;
		ret.z = (m02 + m20) * s;
		ret.w = (m21 - m12) * s;
	} else if (m11 > m22)
	{
		float s = Math::fsqrt(m11 - m00 - m22 + 1.0f);
		ret.y = s * 0.5f;
		s = Math::rcp(s) * 0.5f;
		ret.z = (m21 + m12) * s;
		ret.x = (m10 + m01) * s;
		ret.w = (m02 - m20) * s;
	} else
	{
		float s = Math::fsqrt(m22 - m00 - m11 + 1.0f);
		ret.z = s * 0.5f;
		s = Math::rcp(s) * 0.5f;
		ret.x = (m02 + m20) * s;
		ret.y = (m21 + m12) * s;
		ret.w = (m10 - m01) * s;
	}
	return ret;
}

//////////////////////////////////////////////////////////////////////////
// mat4
//////////////////////////////////////////////////////////////////////////
/// <summary>Sets new matrix values using a given dmat4 source matrix (3x4). The matrix elements are filled using corresponding elements of the source matrix.</summary>
UNIGINE_INLINE void mat4::set(const dmat4 &m)
{
	m00 = toFloat(m.m00);
	m01 = toFloat(m.m01);
	m02 = toFloat(m.m02);
	m03 = toFloat(m.m03);
	m10 = toFloat(m.m10);
	m11 = toFloat(m.m11);
	m12 = toFloat(m.m12);
	m13 = toFloat(m.m13);
	m20 = toFloat(m.m20);
	m21 = toFloat(m.m21);
	m22 = toFloat(m.m22);
	m23 = toFloat(m.m23);
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}
/// <summary>Sets new matrix values using a given source quaternion.</summary>
UNIGINE_INLINE void mat4::set(const quat &q)
{
	mat3 m = q.getMat3();
	m00 = m.m00;
	m01 = m.m01;
	m02 = m.m02;
	m03 = 0.0f;
	m10 = m.m10;
	m11 = m.m11;
	m12 = m.m12;
	m13 = 0.0f;
	m20 = m.m20;
	m21 = m.m21;
	m22 = m.m22;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}
/// <summary>Sets new matrix values using a given quaternion for rotation and scale values and a vec3 vector for translation values.</summary>
UNIGINE_INLINE void mat4::set(const quat &q, const vec3 &v)
{
	mat3 m = q.getMat3();
	m00 = m.m00;
	m01 = m.m01;
	m02 = m.m02;
	m03 = v.x;
	m10 = m.m10;
	m11 = m.m11;
	m12 = m.m12;
	m13 = v.y;
	m20 = m.m20;
	m21 = m.m21;
	m22 = m.m22;
	m23 = v.z;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}
/// <summary>Returns the quaternion, representing the rotation part of the matrix.</summary>
UNIGINE_INLINE quat mat4::getRotate() const
{
	mat3 rotate;
	orthonormalize(rotate, mat3(*this));
	return rotate.getQuat();
}

/// <summary>Composes a rotation matrix from the corresponding Euler angles. The Euler angles are specified in the axis rotation sequence - XYZ (in UNIGINE: x - pitch, y - roll, z - yaw). It is an order of the rings in the three-axis gimbal set: X axis used as the outer ring (independent ring), while Z axis as the inner one (its rotation depends on other 2 rings).</summary>
UNIGINE_INLINE mat4 composeRotationXYZ(const vec3 &r)
{
	return mat4(quat(r.x, r.y, r.z));
}
/// <summary>Composes a rotation matrix from the corresponding Euler angles. The Euler angles are specified in the axis rotation sequence - XZY (in UNIGINE: x - pitch, z - yaw, y - roll). It is an order of the rings in the three-axis gimbal set: X axis used as the outer ring (independent ring), while Y axis as the inner one (its rotation depends on other 2 rings).</summary>
UNIGINE_INLINE mat4 composeRotationXZY(const vec3 &r)
{
	return mat4(quat(1.0f, 0.0f, 0.0f, r.x) * quat(0.0f, 0.0f, 1.0f, r.z) * quat(0.0f, 1.0f, 0.0f, r.y));
}
/// <summary>Composes a rotation matrix from the corresponding Euler angles. The Euler angles are specified in the axis rotation sequence - YXZ (in UNIGINE: y - roll, x - pitch, z - yaw). It is an order of the rings in the three-axis gimbal set: Y axis used as the outer ring (independent ring), while Z axis as the inner one (its rotation depends on other 2 rings).</summary>
UNIGINE_INLINE mat4 composeRotationYXZ(const vec3 &r)
{
	return mat4(quat(0.0f, 1.0f, 0.0f, r.y) * (quat(1.0f, 0.0f, 0.0f, r.x) * quat(0.0f, 0.0f, 1.0f, r.z)));
}
/// <summary>Composes a rotation matrix from the corresponding Euler angles. The Euler angles are specified in the axis rotation sequence - YZX (in UNIGINE: y - roll, z - yaw, x - pitch). It is an order of the rings in the three-axis gimbal set: Y axis used as the outer ring (independent ring), while X axis as the inner one (its rotation depends on other 2 rings).</summary>
UNIGINE_INLINE mat4 composeRotationYZX(const vec3 &r)
{
	return mat4(quat(0.0f, 1.0f, 0.0f, r.y) * (quat(0.0f, 0.0f, 1.0f, r.z) * quat(1.0f, 0.0f, 0.0f, r.x)));
}
/// <summary>Composes a rotation matrix from the corresponding Euler angles. The Euler angles are specified in the axis rotation sequence - ZXY (in UNIGINE: z - yaw, x - pitch, y - roll). It is an order of the rings in the three-axis gimbal set: Z axis used as the outer ring (independent ring), while Y axis as the inner one (its rotation depends on other 2 rings).</summary>
UNIGINE_INLINE mat4 composeRotationZXY(const vec3 &r)
{
	return mat4(quat(0.0f, 0.0f, 1.0f, r.z) * (quat(1.0f, 0.0f, 0.0f, r.x) * quat(0.0f, 1.0f, 0.0f, r.y)));
}
/// <summary>Composes a rotation matrix from the corresponding Euler angles. The Euler angles are specified in the axis rotation sequence - ZYX (in UNIGINE: z - yaw, y - roll, x - pitch). It is an order of the rings in the three-axis gimbal set: Z axis used as the outer ring (independent ring), while X axis as the inner one (its rotation depends on other 2 rings). </summary>
UNIGINE_INLINE mat4 composeRotationZYX(const vec3 &r)
{
	return mat4(quat(0.0f, 0.0f, 1.0f, r.z) * (quat(0.0f, 1.0f, 0.0f, r.y) * quat(1.0f, 0.0f, 0.0f, r.x)));
}

/// <summary>Decomposes a given transformation matrix into a dual quaternion (representing both translation and rotation) and a scale vector. The dual-quaternion model is an accurate, computationally efficient, robust, and flexible method of representing rigid transforms and it is used in skeletal animation.</summary>
UNIGINE_INLINE void decomposeTransform(const mat4 &m, quat &q0, quat &q1, vec3 &scale)
{
	mat3 rotate, rotation = mat3(m);
	orthonormalize(rotate, rotation);
	q0 = rotate.getQuat();
	q1.x = (m.m03 * q0.w + m.m13 * q0.z - m.m23 * q0.y) * 0.5f;
	q1.y = (-m.m03 * q0.z + m.m13 * q0.w + m.m23 * q0.x) * 0.5f;
	q1.z = (m.m03 * q0.y - m.m13 * q0.x + m.m23 * q0.w) * 0.5f;
	q1.w = (m.m03 * q0.x + m.m13 * q0.y + m.m23 * q0.z) * 0.5f;
	scale.x = rotate.m00 * rotation.m00 + rotate.m10 * rotation.m10 + rotate.m20 * rotation.m20;
	scale.y = rotate.m01 * rotation.m01 + rotate.m11 * rotation.m11 + rotate.m21 * rotation.m21;
	scale.z = rotate.m02 * rotation.m02 + rotate.m12 * rotation.m12 + rotate.m22 * rotation.m22;
}
/// <summary>Decomposes a given transformation matrix into translation, rotation and scale components.</summary>
UNIGINE_INLINE void decomposeTransform(const mat4 &m, vec3 &position, quat &rot, vec3 &scale)
{
	mat3 rotate, rotation = mat3(m);
	orthonormalize(rotate, rotation);
	position.x = m.m03;
	position.y = m.m13;
	position.z = m.m23;
	rot = rotate.getQuat();
	scale.x = rotate.m00 * rotation.m00 + rotate.m10 * rotation.m10 + rotate.m20 * rotation.m20;
	scale.y = rotate.m01 * rotation.m01 + rotate.m11 * rotation.m11 + rotate.m21 * rotation.m21;
	scale.z = rotate.m02 * rotation.m02 + rotate.m12 * rotation.m12 + rotate.m22 * rotation.m22;
}
/// <summary>Decomposes a given transformation matrix into a vector representing translation and uniform scale and a quaternion representing rotation.</summary>
UNIGINE_INLINE void decomposeTransform(const mat4 &m, vec4 &position, quat &rot)
{
	mat3 rotate, rotation = mat3(m);
	orthonormalize(rotate, rotation);
	float sx = rotate.m00 * rotation.m00 + rotate.m10 * rotation.m10 + rotate.m20 * rotation.m20;
	float sy = rotate.m01 * rotation.m01 + rotate.m11 * rotation.m11 + rotate.m21 * rotation.m21;
	float sz = rotate.m02 * rotation.m02 + rotate.m12 * rotation.m12 + rotate.m22 * rotation.m22;
	position.x = m.m03;
	position.y = m.m13;
	position.z = m.m23;
	position.w = (sx + sy + sz) * (1.0f / 3.0f);
	rot = rotate.getQuat();
}

/// <summary>Returns the transformation matrix for the specified position, rotation and scale.</summary>
UNIGINE_INLINE mat4 &composeTransform(mat4 &ret, const quat &q0, const quat &q1, const vec3 &scale)
{
	float ilength = Math::rcp(dot(q0, q1)) * 2.0f;
	float sx = scale.x;
	float sy = scale.y;
	float sz = scale.z;
	float nx = q0.x * ilength;
	float ny = q0.y * ilength;
	float nz = q0.z * ilength;
	float nw = q0.w * ilength;
	float xx = q0.x * nx;
	float yy = q0.y * ny;
	float zz = q0.z * nz;
	float ww = q0.w * nw;
	float xy = q0.x * ny;
	float xz = q0.x * nz;
	float xw = q0.x * nw;
	float yz = q0.y * nz;
	float yw = q0.y * nw;
	float zw = q0.z * nw;
	ret.m00 = (ww + xx - yy - zz) * sx * 0.5f;
	ret.m10 = (xy + zw) * sx;
	ret.m20 = (xz - yw) * sx;
	ret.m30 = 0.0f;
	ret.m01 = (xy - zw) * sy;
	ret.m11 = (ww + yy - xx - zz) * sy * 0.5f;
	ret.m21 = (yz + xw) * sy;
	ret.m31 = 0.0f;
	ret.m02 = (xz + yw) * sz;
	ret.m12 = (yz - xw) * sz;
	ret.m22 = (ww + zz - xx - yy) * sz * 0.5f;
	ret.m32 = 0.0f;
	ret.m03 = q1.w * nx + q1.x * nw + q1.z * ny - q1.y * nz;
	ret.m13 = q1.w * ny + q1.x * nz + q1.y * nw - q1.z * nx;
	ret.m23 = q1.w * nz + q1.y * nx + q1.z * nw - q1.x * ny;
	ret.m33 = 1.0f;
	return ret;
}
/// <summary>Returns the transformation matrix for the specified position, rotation and scale.</summary>
UNIGINE_INLINE mat4 &composeTransform(mat4 &ret, const vec3 &position, const quat &rot, const vec3 &scale)
{
	float sx = scale.x;
	float sy = scale.y;
	float sz = scale.z;
	float x2 = rot.x + rot.x;
	float y2 = rot.y + rot.y;
	float z2 = rot.z + rot.z;
	float xx2 = rot.x * x2;
	float yy2 = rot.y * y2;
	float zz2 = rot.z * z2;
	float zx2 = rot.z * x2;
	float xy2 = rot.x * y2;
	float yz2 = rot.y * z2;
	float wx2 = rot.w * x2;
	float wy2 = rot.w * y2;
	float wz2 = rot.w * z2;
	ret.m00 = (1.0f - yy2 - zz2) * sx;
	ret.m10 = (xy2 + wz2) * sx;
	ret.m20 = (zx2 - wy2) * sx;
	ret.m30 = 0.0f;
	ret.m01 = (xy2 - wz2) * sy;
	ret.m11 = (1.0f - xx2 - zz2) * sy;
	ret.m21 = (yz2 + wx2) * sy;
	ret.m31 = 0.0f;
	ret.m02 = (zx2 + wy2) * sz;
	ret.m12 = (yz2 - wx2) * sz;
	ret.m22 = (1.0f - xx2 - yy2) * sz;
	ret.m32 = 0.0f;
	ret.m03 = position.x;
	ret.m13 = position.y;
	ret.m23 = position.z;
	ret.m33 = 1.0f;
	return ret;
}
/// <summary>Returns the transformation matrix for the specified position and rotation.</summary>
UNIGINE_INLINE mat4 &composeTransform(mat4 &ret, const vec4 &position, const quat &rot)
{
	float x2 = (rot.x + rot.x) * position.w;
	float y2 = (rot.y + rot.y) * position.w;
	float z2 = (rot.z + rot.z) * position.w;
	float xx2 = rot.x * x2;
	float yy2 = rot.y * y2;
	float zz2 = rot.z * z2;
	float zx2 = rot.z * x2;
	float xy2 = rot.x * y2;
	float yz2 = rot.y * z2;
	float wx2 = rot.w * x2;
	float wy2 = rot.w * y2;
	float wz2 = rot.w * z2;
	ret.m00 = position.w - yy2 - zz2;
	ret.m10 = xy2 + wz2;
	ret.m20 = zx2 - wy2;
	ret.m30 = 0.0f;
	ret.m01 = xy2 - wz2;
	ret.m11 = position.w - xx2 - zz2;
	ret.m21 = yz2 + wx2;
	ret.m31 = 0.0f;
	ret.m02 = zx2 + wy2;
	ret.m12 = yz2 - wx2;
	ret.m22 = position.w - xx2 - yy2;
	ret.m32 = 0.0f;
	ret.m03 = position.x;
	ret.m13 = position.y;
	ret.m23 = position.z;
	ret.m33 = 1.0f;
	return ret;
}

/// <summary>Resets the transformation scale by replacing the scale component of the transformation matrix with a vec3_one (vector filled with ones). The original scale is stored in the vector argument.</summary>
UNIGINE_INLINE mat4 &removeScale(mat4 &ret, vec3 &scale)
{
	vec3 pos;
	quat rot;
	decomposeTransform(ret, pos, rot, scale);
	composeTransform(ret, pos, rot, vec3_one);
	return ret;
}

/// <summary>Resets the transformation scale by replacing the scale component of the transformation matrix with a vec3_one (vector filled with ones).</summary>
UNIGINE_INLINE mat4 &removeScale(mat4 &ret)
{
	vec3 scale;
	removeScale(ret, scale);
	return ret;
}

/// <summary>Returns the interpolated matrix according to the following formula: m0 + (m 1 - m 0) * k .</summary>
UNIGINE_INLINE mat4 &lerp(mat4 &ret, const mat4 &m0, const mat4 &m1, float k)
{
	vec3 positions[3];
	quat rotations[3];
	vec3 scales[3];
	decomposeTransform(m0, positions[0], rotations[0], scales[0]);
	decomposeTransform(m1, positions[1], rotations[1], scales[1]);
	lerp(positions[2], positions[0], positions[1], k);
	slerp(rotations[2], rotations[0], rotations[1], k);
	lerp(scales[2], scales[0], scales[1], k);
	return composeTransform(ret, positions[2], rotations[2], scales[2]);
}

//////////////////////////////////////////////////////////////////////////
// dmat4
//////////////////////////////////////////////////////////////////////////
/// <summary>Sets new matrix values using a given source quaternion.</summary>
UNIGINE_INLINE void dmat4::set(const quat &q)
{
	mat3 m = q.getMat3();
	m00 = m.m00;
	m01 = m.m01;
	m02 = m.m02;
	m03 = 0.0;
	m10 = m.m10;
	m11 = m.m11;
	m12 = m.m12;
	m13 = 0.0;
	m20 = m.m20;
	m21 = m.m21;
	m22 = m.m22;
	m23 = 0.0;
}
/// <summary>Sets new matrix values using a given quaternion and a dvec3 vector.</summary>
UNIGINE_INLINE void dmat4::set(const quat &q, const dvec3 &v)
{
	mat3 m = q.getMat3();
	m00 = m.m00;
	m01 = m.m01;
	m02 = m.m02;
	m03 = v.x;
	m10 = m.m10;
	m11 = m.m11;
	m12 = m.m12;
	m13 = v.y;
	m20 = m.m20;
	m21 = m.m21;
	m22 = m.m22;
	m23 = v.z;
}
/// <summary>Returns the quaternion, representing the rotation part of the matrix.</summary>
UNIGINE_INLINE quat dmat4::getRotate() const
{
	mat3 rotate;
	orthonormalize(rotate, mat3(*this));
	return rotate.getQuat();
}

/// <summary>Resets the transformation scale by replacing the scale component of the transformation matrix with a vec3_one (vector filled with ones). The original scale is stored in the vector argument.</summary>
UNIGINE_INLINE dmat4 &removeScale(dmat4 &ret, vec3 &scale)
{
	dvec3 pos;
	quat rot;
	decomposeTransform(ret, pos, rot, scale);
	composeTransform(ret, pos, rot, vec3_one);
	return ret;
}

/// <summary>Resets the transformation scale by replacing the scale component of the transformation matrix with a vec3_one (vector filled with ones).</summary>
UNIGINE_INLINE dmat4 &removeScale(dmat4 &ret)
{
	vec3 scale;
	removeScale(ret, scale);
	return ret;
}

/// <summary>Returns the interpolated matrix according to the following formula: m0 + (m 1 - m 0) * k .</summary>
UNIGINE_INLINE dmat4 &lerp(dmat4 &ret, const dmat4 &m0, const dmat4 &m1, double k)
{
	dvec3 positions[3];
	quat rotations[3];
	vec3 scales[3];
	decomposeTransform(m0, positions[0], rotations[0], scales[0]);
	decomposeTransform(m1, positions[1], rotations[1], scales[1]);
	lerp(positions[2], positions[0], positions[1], k);
	slerp(rotations[2], rotations[0], rotations[1], (float)k);
	lerp(scales[2], scales[0], scales[1], (float)k);
	return composeTransform(ret, positions[2], rotations[2], scales[2]);
}

/// <summary>Decomposes a given transformation matrix into translation, rotation and scale components.</summary>
UNIGINE_INLINE void decomposeTransform(const dmat4 &m, dvec3 &position, quat &rot, vec3 &scale)
{
	mat3 rotate, rotation = mat3(m);
	orthonormalize(rotate, rotation);
	position.x = m.m03;
	position.y = m.m13;
	position.z = m.m23;
	rot = rotate.getQuat();
	scale.x = rotate.m00 * rotation.m00 + rotate.m10 * rotation.m10 + rotate.m20 * rotation.m20;
	scale.y = rotate.m01 * rotation.m01 + rotate.m11 * rotation.m11 + rotate.m21 * rotation.m21;
	scale.z = rotate.m02 * rotation.m02 + rotate.m12 * rotation.m12 + rotate.m22 * rotation.m22;
}
/// <summary>Returns the transformation matrix for the specified position, rotation and scale.</summary>
UNIGINE_INLINE dmat4 &composeTransform(dmat4 &ret, const dvec3 &position, const quat &rot, const vec3 &scale)
{
	float sx = scale.x;
	float sy = scale.y;
	float sz = scale.z;
	float x2 = rot.x + rot.x;
	float y2 = rot.y + rot.y;
	float z2 = rot.z + rot.z;
	float xx2 = rot.x * x2;
	float yy2 = rot.y * y2;
	float zz2 = rot.z * z2;
	float zx2 = rot.z * x2;
	float xy2 = rot.x * y2;
	float yz2 = rot.y * z2;
	float wx2 = rot.w * x2;
	float wy2 = rot.w * y2;
	float wz2 = rot.w * z2;
	ret.m00 = (1.0f - yy2 - zz2) * sx;
	ret.m10 = (xy2 + wz2) * sx;
	ret.m20 = (zx2 - wy2) * sx;
	ret.m01 = (xy2 - wz2) * sy;
	ret.m11 = (1.0f - xx2 - zz2) * sy;
	ret.m21 = (yz2 + wx2) * sy;
	ret.m02 = (zx2 + wy2) * sz;
	ret.m12 = (yz2 - wx2) * sz;
	ret.m22 = (1.0f - xx2 - yy2) * sz;
	ret.m03 = position.x;
	ret.m13 = position.y;
	ret.m23 = position.z;
	return ret;
}


//////////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////////
constexpr Vec2 Vec2_zero(0.0f, ConstexprTag{});
constexpr Vec2 Vec2_one(1.0f, ConstexprTag{});
constexpr Vec2 Vec2_half(0.5f, ConstexprTag{});
constexpr Vec2 Vec2_eps(Consts::EPS, ConstexprTag{});
constexpr Vec2 Vec2_inf(Consts::INF, ConstexprTag{});

constexpr Vec3 Vec3_zero(0.0f, ConstexprTag{});
constexpr Vec3 Vec3_one(1.0f, ConstexprTag{});
constexpr Vec3 Vec3_eps(Consts::EPS, ConstexprTag{});
constexpr Vec3 Vec3_inf(Consts::INF, ConstexprTag{});
constexpr Vec3 Vec3_up(0.0f, 0.0f, 1.0f, ConstexprTag{});
constexpr Vec3 Vec3_down(0.0f, 0.0f, -1.0f, ConstexprTag{});
constexpr Vec3 Vec3_forward(0.0f, 1.0f, 0.0f, ConstexprTag{});
constexpr Vec3 Vec3_back(0.0f, -1.0f, 0.0f, ConstexprTag{});
constexpr Vec3 Vec3_right(1.0f, 0.0f, 0.0f, ConstexprTag{});
constexpr Vec3 Vec3_left(-1.0f, 0.0f, 0.0f, ConstexprTag{});

constexpr Vec4 Vec4_zero(0.0f, ConstexprTag{});
constexpr Vec4 Vec4_one(1.0f, ConstexprTag{});
constexpr Vec4 Vec4_eps(Consts::EPS, ConstexprTag{});
constexpr Vec4 Vec4_inf(Consts::INF, ConstexprTag{});

#if defined(USE_DOUBLE) || defined(UNIGINE_DOUBLE)
	constexpr Mat4 Mat4_zero(0.0, ConstexprTag{});
	constexpr Mat4 Mat4_one(1.0, ConstexprTag{});
	constexpr Mat4 Mat4_identity(1.0, 0.0, 0.0,
								 0.0, 1.0, 0.0,
								 0.0, 0.0, 1.0,
								 0.0, 0.0, 0.0, ConstexprTag{});
#else
	constexpr Mat4 Mat4_zero(0.0f, ConstexprTag{});
	constexpr Mat4 Mat4_one(1.0f, ConstexprTag{});
	constexpr Mat4 Mat4_identity(1.0f, 0.0f, 0.0f, 0.0f,
								 0.0f, 1.0f, 0.0f, 0.0f,
								 0.0f, 0.0f, 1.0f, 0.0f,
								 0.0f, 0.0f, 0.0f, 1.0f, ConstexprTag{});
#endif

//////////////////////////////////////////////////////////////////////////
// Utils
//////////////////////////////////////////////////////////////////////////
/// <summary>Rotates the source quaternion towards the target quaternion by an angular step of max_angle (note, that the rotation will not overshoot).</summary>
/// <param name="source">Source quaternion.</param>
/// <param name="target">Target quaternion.</param>
/// <param name="max_angle">Angular step, in degrees. If a negative value is specified, 0 will be used instead.</param>
UNIGINE_INLINE quat rotateTowards(const quat &source, const quat &target, float max_angle)
{
	if (max_angle <= 0.0f)
		return source;

	float angle = getAngle(source, target);
	if (angle < max_angle)
		return target;
	return slerp(source, target, max_angle / angle);
}
/// <summary>Rotates the source vector towards the target vector by an angular step of max_angle (note, that the rotation will not overshoot).</summary>
/// <param name="source">Source vector.</param>
/// <param name="target">Target vector.</param>
/// <param name="max_angle">Angular step, in degrees. If a negative value is specified, 0 will be used instead.</param>
UNIGINE_INLINE vec3 rotateTowards(const vec3 &source, const vec3 &target, float max_angle)
{
	if (compare(max_angle, 0.0f))
		return source;

	vec3 real_target = target * sign(max_angle);
	max_angle = abs(max_angle);

	vec3 n = cross(source, real_target);
	if (compare(length(n), 0.0f)) // vectors are colinear
	{
		n = cross(source, vec3_up);
		if (compare(length(n), 0.0f)) // both vectors are colinear with Z
			n = cross(source, vec3_back);
	}

	float angle = getAngle(source, real_target, n);
	if (angle < max_angle)
		return real_target;

	return quat(n, max_angle) * source;
}

/// <summary>Returns the rotation quaternion for the specified "forward" and "up" directions.</summary>
UNIGINE_INLINE quat rotationFromDir(const vec3 &forward, const vec3 &up)
{
	vec3 x, y, z;
	y = normalize(forward);
	cross(x, y, up).normalize();
	cross(z, x, y).normalize();

	mat3 rotation{x, y, z};
	return rotation.getQuat();
}
/// <summary>Returns the rotation quaternion for the specified "forward" direction (the default "up" vector is used).</summary>
UNIGINE_INLINE quat rotationFromDir(const vec3 &forward)
{
	return rotationFromDir(forward, vec3_up);
}

/// <summary>Returns the rotation quaternion for the specified source and target directions.</summary>
UNIGINE_INLINE quat rotationFromTo(const vec3 &from_dir, const vec3 &to_dir)
{
	float d = dot(from_dir, to_dir);
	if (compare(d, 1.0f))
		return quat_identity;

	if (compare(d, -1.0f))
	{
		vec3 axis = cross(from_dir, vec3_forward);
		if (compare(axis.length2(), 0.0f))
			axis = cross(from_dir, vec3_right);
		return quat(axis, 180.0f);
	}

	quat ret;
	vec3 axis = cross(from_dir, to_dir);
	ret.x = axis.x;
	ret.y = axis.y;
	ret.z = axis.z;
	ret.w = 1.0f + d;
	ret.normalize();
	return ret;
}

/// <summary>Returns a blue noise value for the given pixel coordinates.</summary>
UNIGINE_INLINE vec4 blueNoise(int x, int y)
{
	static constexpr vec4 blue_noise_16x16[] =
	{
		{0.086275f, 0.149020f, 0.031373f, 0.847059f, ConstexprTag{}}, {0.894118f, 0.807843f, 0.835294f, 0.713726f, ConstexprTag{}}, {0.356863f, 0.717647f, 0.529412f, 0.956863f, ConstexprTag{}}, {0.819608f, 0.090196f, 0.184314f, 0.556863f, ConstexprTag{}}, {0.098039f, 0.180392f, 0.003922f, 0.207843f, ConstexprTag{}}, {0.254902f, 0.682353f, 0.776471f, 0.294118f, ConstexprTag{}}, {0.635294f, 0.341176f, 0.458824f, 0.592157f, ConstexprTag{}}, {0.047059f, 0.874510f, 0.992157f, 0.156863f, ConstexprTag{}}, {0.160784f, 0.756863f, 0.839216f, 0.976471f, ConstexprTag{}}, {0.588235f, 0.247059f, 0.129412f, 0.274510f, ConstexprTag{}}, {0.070588f, 0.435294f, 0.698039f, 0.807843f, ConstexprTag{}}, {0.756863f, 0.078431f, 0.333333f, 0.368627f, ConstexprTag{}}, {0.615686f, 0.623529f, 0.219608f, 0.600000f, ConstexprTag{}}, {0.705882f, 0.011765f, 0.980392f, 0.098039f, ConstexprTag{}}, {0.121569f, 0.521569f, 0.423529f, 0.690196f, ConstexprTag{}}, {0.803922f, 0.658824f, 0.662745f, 0.921569f, ConstexprTag{}},
		{0.403922f, 0.466667f, 0.603922f, 0.517647f, ConstexprTag{}}, {0.035294f, 0.298039f, 0.227451f, 0.105882f, ConstexprTag{}}, {0.682353f, 0.937255f, 0.396078f, 0.435294f, ConstexprTag{}}, {0.447059f, 0.494118f, 0.874510f, 0.800000f, ConstexprTag{}}, {0.552941f, 0.003922f, 0.278431f, 0.066667f, ConstexprTag{}}, {0.964706f, 0.749020f, 0.501961f, 0.929412f, ConstexprTag{}}, {0.345098f, 0.278431f, 0.090196f, 0.407843f, ConstexprTag{}}, {0.847059f, 0.403922f, 0.650980f, 0.819608f, ConstexprTag{}}, {0.396078f, 0.047059f, 0.035294f, 0.333333f, ConstexprTag{}}, {0.788235f, 0.501961f, 0.517647f, 0.639216f, ConstexprTag{}}, {0.537255f, 0.800000f, 0.427451f, 0.709804f, ConstexprTag{}}, {0.266667f, 0.549020f, 0.623529f, 0.545098f, ConstexprTag{}}, {0.423529f, 0.286275f, 0.756863f, 0.141176f, ConstexprTag{}}, {0.968628f, 0.823529f, 0.294118f, 0.301961f, ConstexprTag{}}, {0.517647f, 0.407843f, 0.505882f, 0.462745f, ConstexprTag{}}, {0.658824f, 1.000000f, 0.905882f, 0.031373f, ConstexprTag{}},
		{0.780392f, 0.207843f, 0.454902f, 0.176471f, ConstexprTag{}}, {0.592157f, 0.380392f, 0.121569f, 0.243137f, ConstexprTag{}}, {0.282353f, 0.850980f, 0.701961f, 0.317647f, ConstexprTag{}}, {0.184314f, 0.607843f, 0.572549f, 0.611765f, ConstexprTag{}}, {0.760784f, 0.431373f, 0.807843f, 0.490196f, ConstexprTag{}}, {0.129412f, 0.909804f, 0.913726f, 0.733333f, ConstexprTag{}}, {0.698039f, 0.541176f, 0.717647f, 0.666667f, ConstexprTag{}}, {0.466667f, 0.152941f, 0.552941f, 0.109804f, ConstexprTag{}}, {0.219608f, 0.933333f, 0.309804f, 0.470588f, ConstexprTag{}}, {0.976471f, 0.701961f, 0.254902f, 0.050980f, ConstexprTag{}}, {0.105882f, 0.352941f, 0.952941f, 0.211765f, ConstexprTag{}}, {0.368627f, 0.964706f, 0.886275f, 0.878431f, ConstexprTag{}}, {0.858824f, 0.164706f, 0.007843f, 0.933333f, ConstexprTag{}}, {0.039216f, 0.898039f, 0.160784f, 0.772549f, ConstexprTag{}}, {0.203922f, 0.105882f, 0.800000f, 0.396078f, ConstexprTag{}}, {0.313726f, 0.705882f, 0.082353f, 0.811765f, ConstexprTag{}},
		{0.141176f, 0.031373f, 0.741176f, 0.882353f, ConstexprTag{}}, {0.972549f, 0.643137f, 0.305882f, 0.678431f, ConstexprTag{}}, {0.854902f, 0.121569f, 0.960784f, 0.972549f, ConstexprTag{}}, {0.490196f, 0.258824f, 0.047059f, 0.007843f, ConstexprTag{}}, {0.909804f, 0.792157f, 0.356863f, 0.850980f, ConstexprTag{}}, {0.007843f, 0.203922f, 0.223529f, 0.258824f, ConstexprTag{}}, {0.580392f, 0.639216f, 0.113725f, 0.188235f, ConstexprTag{}}, {0.290196f, 0.839216f, 0.392157f, 0.890196f, ConstexprTag{}}, {0.886275f, 0.596078f, 0.858824f, 0.572549f, ConstexprTag{}}, {0.721569f, 0.219608f, 0.737255f, 0.952941f, ConstexprTag{}}, {0.501961f, 0.117647f, 0.192157f, 0.419608f, ConstexprTag{}}, {0.149020f, 0.662745f, 0.478431f, 0.501961f, ConstexprTag{}}, {0.925490f, 0.450980f, 0.576471f, 0.000000f, ConstexprTag{}}, {0.568627f, 0.745098f, 0.690196f, 0.254902f, ConstexprTag{}}, {0.827451f, 0.325490f, 0.349020f, 0.631373f, ConstexprTag{}}, {0.478431f, 0.572549f, 0.937255f, 0.552941f, ConstexprTag{}},
		{0.701961f, 0.780392f, 0.176471f, 0.372549f, ConstexprTag{}}, {0.223529f, 0.882353f, 0.784314f, 0.756863f, ConstexprTag{}}, {0.062745f, 0.533333f, 0.486275f, 0.454902f, ConstexprTag{}}, {0.627451f, 0.329412f, 0.635294f, 0.160784f, ConstexprTag{}}, {0.329412f, 0.980392f, 0.156863f, 0.352941f, ConstexprTag{}}, {0.411765f, 0.101961f, 0.439216f, 0.529412f, ConstexprTag{}}, {0.807843f, 0.364706f, 0.972549f, 0.780392f, ConstexprTag{}}, {0.176471f, 0.058824f, 0.592157f, 0.376471f, ConstexprTag{}}, {0.058824f, 0.423529f, 0.788235f, 0.239216f, ConstexprTag{}}, {0.611765f, 0.305882f, 0.141176f, 0.752941f, ConstexprTag{}}, {0.317647f, 0.878431f, 0.364706f, 0.090196f, ConstexprTag{}}, {0.662745f, 0.019608f, 0.070588f, 0.670588f, ConstexprTag{}}, {0.733333f, 0.584314f, 0.823529f, 0.345098f, ConstexprTag{}}, {0.250980f, 0.231373f, 0.403922f, 0.721569f, ConstexprTag{}}, {0.349020f, 0.505882f, 0.247059f, 0.984314f, ConstexprTag{}}, {0.901961f, 0.956863f, 0.545098f, 0.058824f, ConstexprTag{}},
		{0.427451f, 0.415686f, 0.058824f, 0.298039f, ConstexprTag{}}, {0.556863f, 0.184314f, 0.388235f, 0.121569f, ConstexprTag{}}, {0.376471f, 0.725490f, 0.258824f, 0.584314f, ConstexprTag{}}, {0.737255f, 0.043137f, 0.925490f, 0.901961f, ConstexprTag{}}, {0.239216f, 0.462745f, 0.764706f, 0.647059f, ConstexprTag{}}, {0.996078f, 0.698039f, 0.686275f, 0.094118f, ConstexprTag{}}, {0.670588f, 0.517647f, 0.282353f, 0.996078f, ConstexprTag{}}, {0.533333f, 0.776471f, 0.474510f, 0.027451f, ConstexprTag{}}, {0.949020f, 0.996078f, 0.019608f, 0.615686f, ConstexprTag{}}, {0.431373f, 0.737255f, 0.941177f, 0.858824f, ConstexprTag{}}, {0.019608f, 0.478431f, 0.678431f, 0.282353f, ConstexprTag{}}, {0.800000f, 0.788235f, 0.611765f, 0.815686f, ConstexprTag{}}, {0.458824f, 0.376471f, 0.996078f, 0.580392f, ConstexprTag{}}, {0.090196f, 0.843137f, 0.109804f, 0.152941f, ConstexprTag{}}, {0.639216f, 0.074510f, 0.878431f, 0.203922f, ConstexprTag{}}, {0.000000f, 0.274510f, 0.647059f, 0.486275f, ConstexprTag{}},
		{0.294118f, 0.674510f, 0.968628f, 0.937255f, ConstexprTag{}}, {0.952941f, 0.482353f, 0.827451f, 0.835294f, ConstexprTag{}}, {0.109804f, 0.925490f, 0.588235f, 0.223529f, ConstexprTag{}}, {0.843137f, 0.615686f, 0.011765f, 0.725490f, ConstexprTag{}}, {0.152941f, 0.827451f, 0.537255f, 0.423529f, ConstexprTag{}}, {0.462745f, 0.290196f, 0.890196f, 0.290196f, ConstexprTag{}}, {0.082353f, 0.894118f, 0.066667f, 0.701961f, ConstexprTag{}}, {0.360784f, 0.250980f, 0.643137f, 0.458824f, ConstexprTag{}}, {0.776471f, 0.168627f, 0.239216f, 0.509804f, ConstexprTag{}}, {0.235294f, 0.552941f, 0.533333f, 0.172549f, ConstexprTag{}}, {0.850980f, 0.066667f, 0.317647f, 0.400000f, ConstexprTag{}}, {0.380392f, 0.952941f, 0.447059f, 0.117647f, ConstexprTag{}}, {0.192157f, 0.188235f, 0.211765f, 0.917647f, ConstexprTag{}}, {0.941177f, 0.619608f, 0.290196f, 0.443137f, ConstexprTag{}}, {0.525490f, 0.921569f, 0.713726f, 0.866667f, ConstexprTag{}}, {0.772549f, 0.133333f, 0.498039f, 0.619608f, ConstexprTag{}},
		{0.180392f, 0.360784f, 0.321569f, 0.082353f, ConstexprTag{}}, {0.654902f, 0.062745f, 0.207843f, 0.392157f, ConstexprTag{}}, {0.784314f, 0.235294f, 0.125490f, 0.513726f, ConstexprTag{}}, {0.513726f, 0.388235f, 0.419608f, 0.035294f, ConstexprTag{}}, {0.603922f, 0.160784f, 0.329412f, 0.925490f, ConstexprTag{}}, {0.709804f, 0.576471f, 0.196078f, 0.560784f, ConstexprTag{}}, {0.874510f, 0.015686f, 0.831373f, 0.137255f, ConstexprTag{}}, {0.270588f, 0.670588f, 0.384314f, 0.803922f, ConstexprTag{}}, {0.117647f, 0.392157f, 0.909804f, 0.321569f, ConstexprTag{}}, {0.647059f, 0.631373f, 0.172549f, 0.686275f, ConstexprTag{}}, {0.549020f, 0.333333f, 0.847059f, 0.964706f, ConstexprTag{}}, {0.988235f, 0.262745f, 0.749020f, 0.533333f, ConstexprTag{}}, {0.286275f, 0.529412f, 0.556863f, 0.737255f, ConstexprTag{}}, {0.596078f, 0.694118f, 0.792157f, 0.313726f, ConstexprTag{}}, {0.125490f, 0.313726f, 0.027451f, 0.039216f, ConstexprTag{}}, {0.866667f, 0.803922f, 0.443137f, 0.776471f, ConstexprTag{}},
		{0.470588f, 0.968628f, 0.898039f, 0.694118f, ConstexprTag{}}, {0.258824f, 0.556863f, 0.752941f, 0.270588f, ConstexprTag{}}, {0.043137f, 0.866667f, 0.666667f, 0.792157f, ConstexprTag{}}, {0.905882f, 0.764706f, 0.870588f, 0.192157f, ConstexprTag{}}, {0.305882f, 0.109804f, 0.725490f, 0.337255f, ConstexprTag{}}, {0.015686f, 0.945098f, 0.094118f, 0.843137f, ConstexprTag{}}, {0.400000f, 0.447059f, 0.509804f, 0.227451f, ConstexprTag{}}, {0.572549f, 0.811765f, 0.780392f, 0.949020f, ConstexprTag{}}, {0.921569f, 0.125490f, 0.694118f, 0.078431f, ConstexprTag{}}, {0.474510f, 0.913726f, 0.415686f, 0.874510f, ConstexprTag{}}, {0.156863f, 0.721569f, 0.098039f, 0.219608f, ConstexprTag{}}, {0.074510f, 0.094118f, 0.050980f, 0.019608f, ConstexprTag{}}, {0.690196f, 0.870588f, 0.929412f, 0.650980f, ConstexprTag{}}, {0.831373f, 0.443137f, 0.376471f, 0.235294f, ConstexprTag{}}, {0.392157f, 0.027451f, 0.152941f, 0.415686f, ConstexprTag{}}, {0.717647f, 0.592157f, 0.615686f, 0.541176f, ConstexprTag{}},
		{0.984314f, 0.709804f, 0.086275f, 0.341176f, ConstexprTag{}}, {0.584314f, 0.439216f, 0.270588f, 0.658824f, ConstexprTag{}}, {0.364706f, 0.282353f, 0.549020f, 0.960784f, ConstexprTag{}}, {0.435294f, 0.666667f, 0.470588f, 0.596078f, ConstexprTag{}}, {0.211765f, 0.345098f, 1.000000f, 0.450980f, ConstexprTag{}}, {0.956863f, 0.509804f, 0.607843f, 0.745098f, ConstexprTag{}}, {0.811765f, 0.741176f, 0.298039f, 0.011765f, ConstexprTag{}}, {0.188235f, 0.317647f, 0.137255f, 0.635294f, ConstexprTag{}}, {0.729412f, 0.227451f, 0.580392f, 0.411765f, ConstexprTag{}}, {0.309804f, 0.486275f, 0.976471f, 0.588235f, ConstexprTag{}}, {0.898039f, 0.831373f, 0.266667f, 0.764706f, ConstexprTag{}}, {0.749020f, 0.411765f, 0.482353f, 0.349020f, ConstexprTag{}}, {0.494118f, 0.156863f, 0.654902f, 0.498039f, ConstexprTag{}}, {0.227451f, 0.760784f, 0.200000f, 0.823529f, ConstexprTag{}}, {0.027451f, 0.498039f, 0.843137f, 0.988235f, ConstexprTag{}}, {0.333333f, 0.211765f, 0.525490f, 0.164706f, ConstexprTag{}},
		{0.094118f, 0.835294f, 0.407843f, 0.909804f, ConstexprTag{}}, {0.823529f, 0.145098f, 0.945098f, 0.478431f, ConstexprTag{}}, {0.164706f, 0.007843f, 0.023529f, 0.129412f, ConstexprTag{}}, {0.694118f, 0.992157f, 0.164706f, 0.054902f, ConstexprTag{}}, {0.752941f, 0.603922f, 0.368627f, 0.886275f, ConstexprTag{}}, {0.631373f, 0.192157f, 0.250980f, 0.674510f, ConstexprTag{}}, {0.498039f, 0.862745f, 0.917647f, 0.364706f, ConstexprTag{}}, {0.050980f, 0.054902f, 0.462745f, 0.537255f, ConstexprTag{}}, {0.678431f, 0.972549f, 0.015686f, 0.262745f, ConstexprTag{}}, {0.415686f, 0.600000f, 0.352941f, 0.149020f, ConstexprTag{}}, {0.031373f, 0.000000f, 0.733333f, 0.466667f, ConstexprTag{}}, {0.352941f, 0.654902f, 0.866667f, 0.070588f, ConstexprTag{}}, {0.623529f, 0.988235f, 0.596078f, 0.898039f, ConstexprTag{}}, {0.439216f, 0.243137f, 0.337255f, 0.603922f, ConstexprTag{}}, {0.890196f, 0.901961f, 0.988235f, 0.101961f, ConstexprTag{}}, {0.541176f, 0.086275f, 0.705882f, 0.749020f, ConstexprTag{}},
		{0.247059f, 0.337255f, 0.231373f, 0.003922f, ConstexprTag{}}, {0.643137f, 0.537255f, 0.345098f, 0.231373f, ConstexprTag{}}, {0.929412f, 0.796079f, 0.803922f, 0.827451f, ConstexprTag{}}, {0.066667f, 0.474510f, 0.639216f, 0.403922f, ConstexprTag{}}, {0.545098f, 0.254902f, 0.768628f, 0.278431f, ConstexprTag{}}, {0.113725f, 0.082353f, 0.062745f, 0.168627f, ConstexprTag{}}, {0.341176f, 0.690196f, 0.854902f, 0.494118f, ConstexprTag{}}, {0.243137f, 0.545098f, 0.658824f, 0.913726f, ConstexprTag{}}, {0.945098f, 0.427451f, 0.215686f, 0.717647f, ConstexprTag{}}, {0.607843f, 0.768628f, 0.811765f, 0.980392f, ConstexprTag{}}, {0.862745f, 0.200000f, 0.541176f, 0.796079f, ConstexprTag{}}, {0.200000f, 0.356863f, 0.117647f, 0.662745f, ConstexprTag{}}, {0.796079f, 0.568627f, 0.431373f, 0.286275f, ConstexprTag{}}, {0.960784f, 0.301961f, 0.000000f, 0.196078f, ConstexprTag{}}, {0.145098f, 0.635294f, 0.760784f, 0.380392f, ConstexprTag{}}, {0.764706f, 0.396078f, 0.133333f, 0.568627f, ConstexprTag{}},
		{0.509804f, 0.686275f, 0.584314f, 0.305882f, ConstexprTag{}}, {0.407843f, 0.196078f, 0.682353f, 0.627451f, ConstexprTag{}}, {0.870588f, 0.890196f, 0.862745f, 0.729412f, ConstexprTag{}}, {0.482353f, 0.733333f, 0.203922f, 0.549020f, ConstexprTag{}}, {0.274510f, 0.400000f, 0.513726f, 0.992157f, ConstexprTag{}}, {0.980392f, 0.929412f, 0.411765f, 0.784314f, ConstexprTag{}}, {0.839216f, 0.627451f, 0.709804f, 0.113725f, ConstexprTag{}}, {0.454902f, 0.372549f, 0.313726f, 0.831373f, ConstexprTag{}}, {0.768628f, 0.141176f, 0.964706f, 0.047059f, ConstexprTag{}}, {0.137255f, 0.266667f, 0.627451f, 0.309804f, ConstexprTag{}}, {0.529412f, 0.886275f, 0.168627f, 0.388235f, ConstexprTag{}}, {0.278431f, 0.513726f, 0.901961f, 0.125490f, ConstexprTag{}}, {0.101961f, 0.815686f, 0.243137f, 0.945098f, ConstexprTag{}}, {0.576471f, 0.035294f, 0.301961f, 0.705882f, ConstexprTag{}}, {0.301961f, 0.752941f, 0.819608f, 0.447059f, ConstexprTag{}}, {0.674510f, 0.960784f, 0.450980f, 0.870588f, ConstexprTag{}},
		{0.196078f, 0.098039f, 0.933333f, 0.968628f, ConstexprTag{}}, {0.011765f, 0.611765f, 0.490196f, 0.505882f, ConstexprTag{}}, {0.325490f, 0.309804f, 0.074510f, 0.184314f, ConstexprTag{}}, {0.792157f, 0.039216f, 0.286275f, 0.329412f, ConstexprTag{}}, {0.384314f, 0.137255f, 0.949020f, 0.074510f, ConstexprTag{}}, {0.172549f, 0.784314f, 0.560784f, 0.607843f, ConstexprTag{}}, {0.666667f, 0.294118f, 0.149020f, 0.250980f, ConstexprTag{}}, {0.564706f, 0.819608f, 0.039216f, 0.439216f, ConstexprTag{}}, {0.078431f, 0.917647f, 0.494118f, 0.200000f, ConstexprTag{}}, {0.372549f, 0.713726f, 0.400000f, 0.623529f, ConstexprTag{}}, {1.000000f, 0.070588f, 0.078431f, 0.564706f, ConstexprTag{}}, {0.650980f, 0.678431f, 0.674510f, 0.854902f, ConstexprTag{}}, {0.725490f, 0.129412f, 0.956863f, 0.247059f, ConstexprTag{}}, {0.388235f, 0.454902f, 0.521569f, 0.525490f, ConstexprTag{}}, {0.054902f, 0.172549f, 0.631373f, 0.062745f, ConstexprTag{}}, {0.937255f, 0.490196f, 0.054902f, 0.788235f, ConstexprTag{}},
		{0.741176f, 0.858824f, 0.372549f, 0.427451f, ConstexprTag{}}, {0.619608f, 0.419608f, 0.145098f, 0.043137f, ConstexprTag{}}, {0.133333f, 0.949020f, 0.729412f, 0.894118f, ConstexprTag{}}, {0.713726f, 0.650980f, 0.435294f, 0.768628f, ConstexprTag{}}, {0.600000f, 0.525490f, 0.105882f, 0.474510f, ConstexprTag{}}, {0.023529f, 0.458824f, 0.894118f, 0.698039f, ConstexprTag{}}, {0.878431f, 0.215686f, 0.815686f, 0.941177f, ConstexprTag{}}, {0.298039f, 0.023529f, 0.600000f, 0.356863f, ConstexprTag{}}, {0.207843f, 0.470588f, 0.745098f, 0.682353f, ConstexprTag{}}, {0.815686f, 0.560784f, 0.274510f, 0.905882f, ConstexprTag{}}, {0.443137f, 0.321569f, 0.796079f, 0.482353f, ConstexprTag{}}, {0.003922f, 0.384314f, 0.466667f, 0.023529f, ConstexprTag{}}, {0.486275f, 0.941177f, 0.360784f, 0.741176f, ConstexprTag{}}, {0.882353f, 0.588235f, 0.721569f, 0.325490f, ConstexprTag{}}, {0.835294f, 0.905882f, 0.180392f, 0.643137f, ConstexprTag{}}, {0.450980f, 0.270588f, 0.882353f, 0.145098f, ConstexprTag{}},
		{0.262745f, 0.050980f, 0.772549f, 0.360784f, ConstexprTag{}}, {0.992157f, 0.564706f, 0.325490f, 0.266667f, ConstexprTag{}}, {0.521569f, 0.239216f, 0.984314f, 0.654902f, ConstexprTag{}}, {0.215686f, 0.368627f, 0.619608f, 0.133333f, ConstexprTag{}}, {0.917647f, 0.847059f, 0.670588f, 0.384314f, ConstexprTag{}}, {0.419608f, 0.976471f, 0.341176f, 0.862745f, ConstexprTag{}}, {0.745098f, 0.580392f, 0.235294f, 0.015686f, ConstexprTag{}}, {0.505882f, 0.113725f, 0.380392f, 0.521569f, ConstexprTag{}}, {0.933333f, 0.647059f, 0.188235f, 0.760784f, ConstexprTag{}}, {0.686275f, 0.984314f, 0.921569f, 0.086275f, ConstexprTag{}}, {0.321569f, 0.176471f, 0.568627f, 0.180392f, ConstexprTag{}}, {0.913726f, 0.854902f, 0.043137f, 0.431373f, ConstexprTag{}}, {0.231373f, 0.729412f, 0.850980f, 1.000000f, ConstexprTag{}}, {0.168627f, 0.223529f, 0.101961f, 0.839216f, ConstexprTag{}}, {0.337255f, 0.349020f, 0.564706f, 0.215686f, ConstexprTag{}}, {0.560784f, 0.772549f, 0.262745f, 0.576471f, ConstexprTag{}}
	};

	ivec2 coord(x, y);
	ivec2 coord_noise = coord % 15;
	coord = (coord / 15) % 64;
	vec4 noise = blue_noise_16x16[coord_noise.x * 16 + coord_noise.y];

	if ((coord.x * coord.y) % 3 == 1)
	{
		vec4 noise_temp = noise;
		noise.x = noise_temp.y;
		noise.y = noise_temp.x;
		noise.z = noise_temp.w;
		noise.w = noise_temp.z;
	}
	if ((coord.x + coord.y) % 2 == 1)
	{
		vec4 noise_temp = noise;
		noise.x = noise_temp.w;
		noise.y = noise_temp.z;
		noise.z = noise_temp.y;
		noise.w = noise_temp.x;
	}

	return frac(noise + vec4(itof(coord.x * 64 + coord.y) * Consts::GOLDEN_RATIO));
}

/// <summary>Returns a generated set of points with X and Y coordinates in the [-1; 1] range that describe a circle with uniform distribution of samples inside. This method is suitable for getting uniform distribution of coordinates for a circle. For example you can use it is a loop to generate UV coordinates offset for making the uniform circular blur effect. You can use the current loop iteration index as the i argument and the maximum number of iterations — as count.</summary>
/// <param name="i">Index of the current point for the disk.</param>
/// <param name="count">Number of points.</param>
/// <param name="noise">Normalized noise.</param>
UNIGINE_INLINE vec2 vogelDisk(const unsigned int i, const unsigned int count, float noise)
{
	const float r = sqrtf(float(i) + 0.5f) / sqrtf(float(count));
	float theta = 2.4f * float(i) + noise * Consts::PI;

	vec2 ret = vec2_zero;
	sincos(theta, ret.x, ret.y);
	return ret * r;
}
/// <summary>Returns a generated set of points with X and Y coordinates in the [-1; 1] range that describe a circle with uniform distribution of samples inside. This method is suitable for getting uniform distribution of coordinates for a circle. For example you can use it is a loop to generate UV coordinates offset for making the uniform circular blur effect. You can use the current loop iteration index as the i argument and the maximum number of iterations — as count.</summary>
/// <param name="i">Index of the current point for the disk.</param>
/// <param name="count">Number of points.</param>
UNIGINE_INLINE vec2 vogelDisk(const unsigned int i, const unsigned int count)
{
	vec2 ret = vec2_zero;
	sincos(2.4f * float(i), ret.x, ret.y);
	return ret * sqrtf(float(i) + 0.5f) / sqrtf(float(count));
}

UNIGINE_INLINE mat4 hardwareProjection(const mat4 &projection)
{
	mat4 ret;
	const mat4 offset = translate(0.0f, 0.0f, 0.5f) * scale(1.0f, 1.0f, 0.5f);
	return mul(ret, offset, projection);
}

/// <summary>Returns the value with the reversed order of the bits.</summary>
UNIGINE_INLINE unsigned int reverseBits(unsigned int value)
{
	unsigned int retval = 0;
	for (int i = 31; i >= 0; i--)
	{
		retval |= (value & 1) << i;
		value >>= 1;
	}
	return retval;
}

} // end namespace Math

} // end namespace Unigine

#include "UnigineMathLibBounds.h"
#include "UnigineMathLib2d.h"
#include "UnigineMathLibPolygon.h"
#include "UnigineMathLibConvex.h"
#include "UnigineMathLibConcave.h"

#ifdef NDEBUG
	#define UNIGINE_ASSERT_MATH(VALUE) VALUE
#else
	UNIGINE_INLINE Unigine::Math::vec2 &unigine_assert_math(Unigine::Math::vec2 &v) { UNIGINE_ASSERT_ALIGNED8(&v); return v; }
	UNIGINE_INLINE Unigine::Math::vec3 &unigine_assert_math(Unigine::Math::vec3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::vec4 &unigine_assert_math(Unigine::Math::vec4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::dvec2 &unigine_assert_math(Unigine::Math::dvec2 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::dvec3 &unigine_assert_math(Unigine::Math::dvec3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::dvec4 &unigine_assert_math(Unigine::Math::dvec4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::ivec2 &unigine_assert_math(Unigine::Math::ivec2 &v) { UNIGINE_ASSERT_ALIGNED8(&v); return v; }
	UNIGINE_INLINE Unigine::Math::ivec3 &unigine_assert_math(Unigine::Math::ivec3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::ivec4 &unigine_assert_math(Unigine::Math::ivec4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::quat &unigine_assert_math(Unigine::Math::quat &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::mat2 &unigine_assert_math(Unigine::Math::mat2 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::mat3 &unigine_assert_math(Unigine::Math::mat3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::mat4 &unigine_assert_math(Unigine::Math::mat4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::dmat4 &unigine_assert_math(Unigine::Math::dmat4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::BoundSphere &unigine_assert_math(Unigine::Math::BoundSphere &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::BoundBox &unigine_assert_math(Unigine::Math::BoundBox &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE Unigine::Math::BoundFrustum &unigine_assert_math(Unigine::Math::BoundFrustum &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	#if defined(USE_DOUBLE) || defined(UNIGINE_DOUBLE)
		UNIGINE_INLINE Unigine::Math::WorldBoundSphere &unigine_assert_math(Unigine::Math::WorldBoundSphere &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
		UNIGINE_INLINE Unigine::Math::WorldBoundBox &unigine_assert_math(Unigine::Math::WorldBoundBox &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
		UNIGINE_INLINE Unigine::Math::WorldBoundFrustum &unigine_assert_math(Unigine::Math::WorldBoundFrustum &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	#endif

	UNIGINE_INLINE const Unigine::Math::vec2 &unigine_assert_math(const Unigine::Math::vec2 &v) { UNIGINE_ASSERT_ALIGNED8(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::vec3 &unigine_assert_math(const Unigine::Math::vec3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::vec4 &unigine_assert_math(const Unigine::Math::vec4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::dvec2 &unigine_assert_math(const Unigine::Math::dvec2 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::dvec3 &unigine_assert_math(const Unigine::Math::dvec3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::dvec4 &unigine_assert_math(const Unigine::Math::dvec4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::ivec2 &unigine_assert_math(const Unigine::Math::ivec2 &v) { UNIGINE_ASSERT_ALIGNED8(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::ivec3 &unigine_assert_math(const Unigine::Math::ivec3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::ivec4 &unigine_assert_math(const Unigine::Math::ivec4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::quat &unigine_assert_math(const Unigine::Math::quat &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::mat2 &unigine_assert_math(const Unigine::Math::mat2 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::mat3 &unigine_assert_math(const Unigine::Math::mat3 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::mat4 &unigine_assert_math(const Unigine::Math::mat4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::dmat4 &unigine_assert_math(const Unigine::Math::dmat4 &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::BoundSphere &unigine_assert_math(const Unigine::Math::BoundSphere &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::BoundBox &unigine_assert_math(const Unigine::Math::BoundBox &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	UNIGINE_INLINE const Unigine::Math::BoundFrustum &unigine_assert_math(const Unigine::Math::BoundFrustum &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	#if defined(USE_DOUBLE) || defined(UNIGINE_DOUBLE)
		UNIGINE_INLINE const Unigine::Math::WorldBoundSphere &unigine_assert_math(const Unigine::Math::WorldBoundSphere &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
		UNIGINE_INLINE const Unigine::Math::WorldBoundBox &unigine_assert_math(const Unigine::Math::WorldBoundBox &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
		UNIGINE_INLINE const Unigine::Math::WorldBoundFrustum &unigine_assert_math(const Unigine::Math::WorldBoundFrustum &v) { UNIGINE_ASSERT_ALIGNED16(&v); return v; }
	#endif

	UNIGINE_INLINE Unigine::Math::vec2 *unigine_assert_math(Unigine::Math::vec2 *v) { UNIGINE_ASSERT_ALIGNED8(v); return v; }
	UNIGINE_INLINE Unigine::Math::vec3 *unigine_assert_math(Unigine::Math::vec3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::vec4 *unigine_assert_math(Unigine::Math::vec4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::dvec3 *unigine_assert_math(Unigine::Math::dvec3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::dvec2 *unigine_assert_math(Unigine::Math::dvec2 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::dvec4 *unigine_assert_math(Unigine::Math::dvec4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::ivec2 *unigine_assert_math(Unigine::Math::ivec2 *v) { UNIGINE_ASSERT_ALIGNED8(v); return v; }
	UNIGINE_INLINE Unigine::Math::ivec3 *unigine_assert_math(Unigine::Math::ivec3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::ivec4 *unigine_assert_math(Unigine::Math::ivec4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::quat *unigine_assert_math(Unigine::Math::quat *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::mat2 *unigine_assert_math(Unigine::Math::mat2 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::mat3 *unigine_assert_math(Unigine::Math::mat3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::mat4 *unigine_assert_math(Unigine::Math::mat4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::dmat4 *unigine_assert_math(Unigine::Math::dmat4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::BoundSphere *unigine_assert_math(Unigine::Math::BoundSphere *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::BoundBox *unigine_assert_math(Unigine::Math::BoundBox *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE Unigine::Math::BoundFrustum *unigine_assert_math(Unigine::Math::BoundFrustum *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	#if defined(USE_DOUBLE) || defined(UNIGINE_DOUBLE)
		UNIGINE_INLINE Unigine::Math::WorldBoundSphere *unigine_assert_math(Unigine::Math::WorldBoundSphere *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
		UNIGINE_INLINE Unigine::Math::WorldBoundBox *unigine_assert_math(Unigine::Math::WorldBoundBox *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
		UNIGINE_INLINE Unigine::Math::WorldBoundFrustum *unigine_assert_math(Unigine::Math::WorldBoundFrustum *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	#endif

	UNIGINE_INLINE const Unigine::Math::vec2 *unigine_assert_math(const Unigine::Math::vec2 *v) { UNIGINE_ASSERT_ALIGNED8(v); return v; }
	UNIGINE_INLINE const Unigine::Math::vec3 *unigine_assert_math(const Unigine::Math::vec3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::vec4 *unigine_assert_math(const Unigine::Math::vec4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::dvec3 *unigine_assert_math(const Unigine::Math::dvec3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::dvec2 *unigine_assert_math(const Unigine::Math::dvec2 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::dvec4 *unigine_assert_math(const Unigine::Math::dvec4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::ivec2 *unigine_assert_math(const Unigine::Math::ivec2 *v) { UNIGINE_ASSERT_ALIGNED8(v); return v; }
	UNIGINE_INLINE const Unigine::Math::ivec3 *unigine_assert_math(const Unigine::Math::ivec3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::ivec4 *unigine_assert_math(const Unigine::Math::ivec4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::quat *unigine_assert_math(const Unigine::Math::quat *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::mat2 *unigine_assert_math(const Unigine::Math::mat2 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::mat3 *unigine_assert_math(const Unigine::Math::mat3 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::mat4 *unigine_assert_math(const Unigine::Math::mat4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::dmat4 *unigine_assert_math(const Unigine::Math::dmat4 *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::BoundSphere *unigine_assert_math(const Unigine::Math::BoundSphere *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::BoundBox *unigine_assert_math(const Unigine::Math::BoundBox *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	UNIGINE_INLINE const Unigine::Math::BoundFrustum *unigine_assert_math(const Unigine::Math::BoundFrustum *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	#if defined(USE_DOUBLE) || defined(UNIGINE_DOUBLE)
		UNIGINE_INLINE const Unigine::Math::WorldBoundSphere *unigine_assert_math(const Unigine::Math::WorldBoundSphere *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
		UNIGINE_INLINE const Unigine::Math::WorldBoundBox *unigine_assert_math(const Unigine::Math::WorldBoundBox *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
		UNIGINE_INLINE const Unigine::Math::WorldBoundFrustum *unigine_assert_math(const Unigine::Math::WorldBoundFrustum *v) { UNIGINE_ASSERT_ALIGNED16(v); return v; }
	#endif

	#define UNIGINE_ASSERT_MATH(VALUE) unigine_assert_math(VALUE)
#endif

namespace Unigine
{
template<typename Type>
struct Hasher;

template<>
struct Hasher<Math::ivec2> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::ivec2 &v) { return v.hash(); } };
template<>
struct Hasher<Math::ivec3> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::ivec3 &v) { return v.hash(); } };
template<>
struct Hasher<Math::ivec4> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::ivec3 &v) { return v.hash(); } };

template<>
struct Hasher<Math::vec2> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::vec2 &v) { return v.hash(); } };
template<>
struct Hasher<Math::vec3> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::vec3 &v) { return v.hash(); } };
template<>
struct Hasher<Math::vec4> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::vec3 &v) { return v.hash(); } };
template<>
struct Hasher<Math::quat> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::quat &v) { return v.hash(); } };

template<>
struct Hasher<Math::dvec2> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::dvec2 &v) { return v.hash(); } };
template<>
struct Hasher<Math::dvec3> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::dvec3 &v) { return v.hash(); } };
template<>
struct Hasher<Math::dvec4> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::dvec3 &v) { return v.hash(); } };

template<>
struct Hasher<Math::dmat4> { using HashType = unsigned int; UNIGINE_INLINE static HashType create(const Math::dmat4 &v) { return v.hash(); } };
}
