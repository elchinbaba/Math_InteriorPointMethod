#pragma once

#include <vector>
#include <functional>

#ifndef TYPEDEF_H
#define TYPEDEF_H

namespace InteriorPointMethod
{
	typedef long double VALUE;

	typedef unsigned int UNSIGNED_INT;
	typedef UNSIGNED_INT SIZE;
	typedef SIZE ROW, COLUMN;

	typedef std::vector<VALUE> VECTOR_VALUE;

	typedef std::vector<VECTOR_VALUE> ARRAY_VALUE;
	typedef ARRAY_VALUE CONSTRAINT_ARRAY;
	typedef CONSTRAINT_ARRAY INEQUALITY_ARRAY;
	typedef CONSTRAINT_ARRAY EQUALITY_ARRAY;

	typedef std::vector<UNSIGNED_INT> PARTIALS;

	typedef VECTOR_VALUE POINT;
	typedef POINT START_POINT;

	typedef VECTOR_VALUE COEFFICIENTS;

	typedef VECTOR_VALUE CONSTRAINT_VECTOR;
	typedef CONSTRAINT_VECTOR INEQUALITY_VECTOR;
	typedef CONSTRAINT_VECTOR EQUALITY_VECTOR;

	typedef VALUE OMEGA;
	typedef VALUE Q;
	typedef VALUE X;

	typedef class Matrix MATRIX;
}

#endif //!TYPEDEF_H