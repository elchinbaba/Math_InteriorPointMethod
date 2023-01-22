#pragma once

#include <typedef.h>

#ifndef MATRIX_H
#define MATRIX_H

namespace InteriorPointMethod
{
	class Matrix
	{
	public:
		ROW row;
		COLUMN column;
		ARRAY_VALUE arr;

	public:
		void setRow(ROW n);
		void setColumn(COLUMN m);
		void setArray(ARRAY_VALUE);

	public:
		Matrix();
		Matrix(ROW, COLUMN);
		Matrix(ROW, COLUMN, VALUE);
		Matrix(VECTOR_VALUE);
		Matrix(ARRAY_VALUE);

	public:
		MATRIX add(const MATRIX&);
		MATRIX multiply(const MATRIX&);

	public:
		void show();
		MATRIX transpose();
		VALUE determinant();
		MATRIX inverse();
		VECTOR_VALUE convertToVector();

	public:
		MATRIX operator+ (const MATRIX&);
		MATRIX operator- ();
		MATRIX operator- (MATRIX&);
		MATRIX operator* (const MATRIX&);

	public:
		friend MATRIX operator* (const MATRIX&, const MATRIX&);
		friend MATRIX operator* (const VALUE&, const MATRIX&);
		friend MATRIX operator+ (const MATRIX&, const MATRIX&);
		friend MATRIX operator- (const MATRIX&, const MATRIX&);
	};
}

#endif // !MATRIX_H
