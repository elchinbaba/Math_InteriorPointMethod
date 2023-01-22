#include "Matrix.h"

namespace InteriorPointMethod
{
	MATRIX operator* (const VALUE& c, const MATRIX& matrix)
	{
		ROW row = matrix.row;
		COLUMN column = matrix.column;

		MATRIX multipliedMatrix = Matrix(row, column);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				multipliedMatrix.arr[i][j] = c * matrix.arr[i][j];
			}
		}

		return multipliedMatrix;
	}
	MATRIX operator* (const MATRIX& matrix1, const MATRIX& matrix2)
	{
		if (matrix1.column != matrix2.row)
		{
			throw std::exception("ValueError: matrices are not aligned");
		}

		ROW row = matrix1.row;
		SIZE mid = matrix1.column;
		COLUMN column = matrix2.column;

		MATRIX multipliedMatrix = Matrix(row, column);
		VALUE sum;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				sum = 0;
				for (int k = 0; k < mid; k++)
				{
					sum += matrix1.arr[i][k] * matrix2.arr[k][j];
				}
				multipliedMatrix.arr[i][j] = sum;
			}
		}

		return multipliedMatrix;
	}
	MATRIX operator+ (const MATRIX& matrix1, const MATRIX& matrix2)
	{
		MATRIX addedMatrix = Matrix(matrix1.row, matrix2.column);

		for (int i = 0; i < matrix1.row; i++)
		{
			for (int j = 0; j < matrix2.column; j++)
			{
				addedMatrix.arr[i][j] = matrix1.arr[i][j] + matrix2.arr[i][j];
			}
		}

		return addedMatrix;
	}
	MATRIX operator- (const MATRIX& matrix1, const MATRIX& matrix2)
	{
		MATRIX subtractedMatrix = Matrix(matrix1.row, matrix2.column);

		for (int i = 0; i < matrix1.row; i++)
		{
			for (int j = 0; j < matrix2.column; j++)
			{
				subtractedMatrix.arr[i][j] = matrix1.arr[i][j] - matrix2.arr[i][j];
			}
		}

		return subtractedMatrix;
	}
}