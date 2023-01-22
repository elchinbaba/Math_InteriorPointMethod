#include "Matrix.h"

namespace InteriorPointMethod
{
	void Matrix::setRow(ROW n)
	{
		Matrix::row = n;
		Matrix::arr.resize(n);
	}

	void Matrix::setColumn(COLUMN m)
	{
		Matrix::column = m;
		for (int i = 0; i < Matrix::arr.size(); i++)
		{
			Matrix::arr[i].resize(m);
		}
	}

	void Matrix::setArray(ARRAY_VALUE arr)
	{
		Matrix::arr = arr;
	}
}