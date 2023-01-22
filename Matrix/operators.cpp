#include "Matrix.h"

namespace InteriorPointMethod
{
	MATRIX Matrix::operator+(const MATRIX& matrix)
	{
		return this->add(matrix);
	}

	MATRIX Matrix::operator-()
	{
		return -1 * *this;
	}

	MATRIX Matrix::operator-(MATRIX& matrix)
	{
		return this->add(-matrix);
	}

	MATRIX Matrix::operator*(const MATRIX& matrix)
	{
		return this->multiply(matrix);
	}
}