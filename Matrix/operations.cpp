#include "Matrix.h"

namespace InteriorPointMethod
{
	MATRIX Matrix::add(const Matrix& matrix)
	{
		ROW row = matrix.row;
		COLUMN column = matrix.column;

		MATRIX addedMatrix = Matrix(row, column);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				addedMatrix.arr[i][j] = Matrix::arr[i][j] + matrix.arr[i][j];
			}
		}

		return addedMatrix;
	}

	MATRIX Matrix::multiply(const Matrix& matrix)
	{
		if (Matrix::column != matrix.row)
		{
			throw std::exception("ValueError: matrices are not aligned");
		}

		ROW row = Matrix::row;
		SIZE mid = Matrix::column; //matrix.row
		COLUMN column = matrix.column;

		MATRIX multipliedMatrix = Matrix(row, column);
		VALUE sum;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				sum = 0;
				for (int k = 0; k < mid; k++)
				{
					sum += Matrix::arr[i][k] * matrix.arr[k][j];
				}
				multipliedMatrix.arr[i][j] = sum;
			}
		}

		return multipliedMatrix;
	}
}