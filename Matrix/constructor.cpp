#include "Matrix.h"

namespace InteriorPointMethod
{
	Matrix::Matrix()
	{
		Matrix::row = 0;
		Matrix::column = 0;
	}

	Matrix::Matrix(ROW row, COLUMN column)
	{
		Matrix::row = row;
		Matrix::column = column;

		Matrix::arr.resize(row);
		for (int i = 0; i < Matrix::row; i++)
		{
			Matrix::arr[i].resize(column);
		}
	}

	Matrix::Matrix(ROW row, COLUMN column, VALUE value)
	{
		Matrix::row = row;
		Matrix::column = column;

		Matrix::arr.resize(row);
		for (int i = 0; i < Matrix::row; i++)
		{
			for (int j = 0; j < Matrix::column; j++)
			{
				Matrix::arr[i].push_back(value);
			}
		}
	}

	Matrix::Matrix(VECTOR_VALUE vector)
	{
		ROW row = vector.size();
		COLUMN column = 1;

		Matrix::row = row;
		Matrix::column = column;

		Matrix::arr.resize(Matrix::row);
		for (int i = 0; i < Matrix::row; i++)
		{
			Matrix::arr[i].push_back(vector[i]);
		}
	}

	Matrix::Matrix(ARRAY_VALUE arr)
	{
		ROW row = arr.size();
		COLUMN column = arr[0].size();

		Matrix::row = row;
		Matrix::column = column;

		Matrix::arr.resize(Matrix::row);
		for (int i = 0; i < row; i++)
		{
			Matrix::arr[i].resize(Matrix::column);
			for (int j = 0; j < Matrix::column; j++)
			{
				Matrix::arr[i][j] = arr[i][j];
			}
		}
	}
}