#include <iostream>
#include "Matrix.h"

namespace InteriorPointMethod
{
	void Matrix::show()
	{
		for (SIZE i = 0; i < Matrix::row; i++)
		{
			for (SIZE j = 0; j < Matrix::column; j++)
			{
				std::cout << Matrix::arr[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	MATRIX Matrix::transpose()
	{
		ROW row = Matrix::column;
		COLUMN column = Matrix::row;

		MATRIX transposedMatrix = Matrix(row, column);
		for (SIZE i = 0; i < row; i++)
		{
			for (SIZE j = 0; j < column; j++)
			{
				transposedMatrix.arr[i][j] = Matrix::arr[j][i];
			}
		}

		return transposedMatrix;
	}

	VALUE Matrix::determinant()
	{
		SIZE N = Matrix::row;
		MATRIX massiv = Matrix(Matrix::arr);
		SIZE i, j;
		SIZE r = 0, n = 0;
		SIZE k;
		VALUE a_ii, a_ki;
		for (int i = 0; i < N - 1; i++)
		{
			if (massiv.arr[i][i] != 0)
			{
				a_ii = massiv.arr[i][i];
				for (k = i + 1; k < N; k++)
				{
					a_ki = -massiv.arr[k][i];
					for (j = 0; j < N; j++)
					{
						massiv.arr[k][j] += massiv.arr[i][j] * (a_ki / a_ii);
					}
				}
			}
			else
			{
				SIZE t;
				for (t = i + 1; t < N; t++)
				{
					if (massiv.arr[i][t] != 0)
					{
						break;
					}
				}

				if (t != N)
				{
					n++;
					VALUE c;
					for (j = 0; j < N; j++)
					{
						c = massiv.arr[j][i];
						massiv.arr[j][i] = massiv.arr[j][t];
						massiv.arr[j][t] = c;
					}
					i = i - 1;
					continue;
				}
				else
				{
					r = 1; break;
				}
			}
		}
		VALUE D;
		switch (r)
		{
		case 0:
			D = pow(-1, n);
			for (i = 0; i < N; i++)
				D *= massiv.arr[i][i];
			break;
		case 1:
			D = 0; break;
		}

		return D;
	}

	MATRIX Matrix::inverse()
	{
		SIZE N = Matrix::row;
		MATRIX massiv = Matrix(N, 2 * N);
		SIZE i, j;
		VALUE D = Matrix::determinant();

		if (D == 0) throw std::exception("Inverse matrix does not exist!");

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				massiv.arr[i][j] = Matrix::arr[i][j];
			}
			for (j = N; j < 2 * N; j++)
			{
				if (j - N == i) massiv.arr[i][j] = 1;
				else massiv.arr[i][j] = 0;
			}
		}

		MATRIX inverseMatrix = Matrix(N, N);
		SIZE k, t;
		VALUE a_ii, a_ki;
		for (i = 0; i < N; i++)
		{
			if (massiv.arr[i][i] != 0)
			{
				a_ii = massiv.arr[i][i];
				for (j = 0; j < 2 * N; j++)
				{
					massiv.arr[i][j] /= a_ii;
				}
				for (k = 0; k < N; k++)
				{
					if (k != i)
					{
						a_ki = -massiv.arr[k][i];
						for (j = 0; j < 2 * N; j++)
						{
							massiv.arr[k][j] += massiv.arr[i][j] * a_ki;
						}
					}
				}
			}
			else
			{
				for (t = i + 1; t < N; t++)
				{
					if (massiv.arr[i][t] != 0)
					{
						break;
					}
				}
				if (t == N) throw std::exception("Inverse matrix does not exist!");
				VALUE c;
				for (j = 0; j < N; j++)
				{
					try
					{
						c = massiv.arr[j][i];
						massiv.arr[j][i] = massiv.arr[j][t];
						massiv.arr[j][t] = c;
					}
					catch (std::exception ex)
					{
						throw std::exception("Inverse matrix not found.");
					}
				}
				i = i - 1;
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				inverseMatrix.arr[i][j] = massiv.arr[i][j + N];
			}
		}

		return inverseMatrix;
	}

	VECTOR_VALUE Matrix::convertToVector()
	{
		VECTOR_VALUE vector;
		for (int i = 0; i < Matrix::row; i++)
		{
			vector.push_back(Matrix::arr[i][0]);
		}
		return vector;
	}
}