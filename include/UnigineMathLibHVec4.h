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
#include "UnigineMathLibVec4.h"
#include "UnigineMathLibDVec4.h"

namespace Unigine
{
namespace Math
{

struct hvec4
{
	/// <summary>Default constructor. Produces a zero vector.</summary>
	UNIGINE_INLINE constexpr hvec4(): x(0), y(0), z(0), w(0) {}
	/// <summary>Constructor. Initializes the vector using the given values.</summary>
	UNIGINE_INLINE hvec4(const hvec4 &v): x(v.x), y(v.y), z(v.z), w(v.w) {}
	/// <summary>Constructor. Initializes the vector using the given values.</summary>
	UNIGINE_INLINE constexpr hvec4(half x, half y, half z, half w): x(x), y(y), z(z), w(w) {}
	/// <summary>Constructor. Initializes the vector using a given value: x=v, y=v, z=v, w=v.</summary>
	UNIGINE_INLINE constexpr explicit hvec4(half v): x(v), y(v), z(v), w(v) {}
	/// <summary>Constructor. Initializes the vector using a given value: x=v, y=v, z=v, w=v.</summary>
	UNIGINE_INLINE explicit hvec4(float v): x(v), y(v), z(v), w(v) {}
	/// <summary>Constructor. Initializes the vector using a given source vector.</summary>
	UNIGINE_INLINE explicit hvec4(const vec4 &v): x(v.x), y(v.y), z(v.z), w(v.w) {}
	/// <summary>Constructor. Initializes the vector using a given source vector.</summary>
	UNIGINE_INLINE explicit hvec4(const dvec4 &v)
		: x(toFloat(v.x))
		, y(toFloat(v.y))
		, z(toFloat(v.z))
		, w(toFloat(v.w))
	{}
	/// <summary>Constructor. Initializes the vector using a given pointer to the array of elements: x=v[0], y=v[1], z=v[2], w=v[3].</summary>
	UNIGINE_INLINE explicit hvec4(const float *v) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) {}

	/// <summary>Performs vector assignment. Destination vector = Source vector.</summary>
	UNIGINE_INLINE hvec4 &operator=(const hvec4 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}

	/// <summary>Performs type conversion to half *.</summary>
	UNIGINE_INLINE operator half *() { return &x; }
	/// <summary>Performs type conversion to const half *.</summary>
	UNIGINE_INLINE operator const half *() const { return &x; }
	/// <summary>Performs type conversion to void *.</summary>
	UNIGINE_INLINE operator void *() { return &x; }
	/// <summary>Performs type conversion to const void *.</summary>
	UNIGINE_INLINE operator const void *() const { return &x; }

	/// <summary>Performs array access to the vector item reference by using given item index.</summary>
	UNIGINE_INLINE half &operator[](int i)
	{
		assert((unsigned int)i < 4 && "hvec4::operator[](): bad index");
		return (&x)[i];
	}
	/// <summary>Performs array access to the vector item by using given item index.</summary>
	UNIGINE_INLINE half operator[](int i) const
	{
		assert((unsigned int)i < 4 && "hvec4::operator[](): bad index");
		return (&x)[i];
	}

	/// <summary>Returns the pointer to the vector.</summary>
	UNIGINE_INLINE half *get() { return &x; }
	/// <summary>Returns the constant pointer to the vector.</summary>
	UNIGINE_INLINE const half *get() const { return &x; }

	//TODO. Add v[4] array. When I tried to add array the compiler returned an error 'compiler is out of heap space'.
	half x, y, z, w;
};

constexpr hvec4 hvec4_zero(half(0x0000));
constexpr hvec4 hvec4_one(half(0x3c00));

}
}
