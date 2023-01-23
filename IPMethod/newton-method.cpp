#include <differential.h>
#include <ipm-struct.h>
#include "newton-method.h"

namespace InteriorPointMethod
{
	static MATRIX evaluateHessian(MATRIX hessian, Function* function, POINT point)
	{
		ROW row = hessian.row;
		COLUMN column = hessian.column;
		ARRAY_VALUE arr = hessian.arr;

		for (SIZE i = 0; i < row; i++)
		{
			for (SIZE j = 0; j < column; j++)
			{
				arr[i][j] = derivative(function, point, { i + 1, j + 1 });
			}
		}

		return Matrix(arr);
	}

	static MATRIX evaluateGradient(MATRIX gradient, Function* function, POINT point)
	{
		ROW row = gradient.row;
		ARRAY_VALUE arr = gradient.arr;

		for (SIZE i = 0; i < row; i++)
		{
			arr[i][0] = derivative(function, point, { i + 1 });
		}

		return Matrix(arr);
	}

	NewtonMethod::NewtonMethod()
	{
		NewtonMethod::function = NULL;
		NewtonMethod::hessian = Matrix();
		NewtonMethod::gradient = Matrix();
	}

	NewtonMethod::NewtonMethod(Function* function, SIZE n)
	{
		NewtonMethod::function = function;
		NewtonMethod::gradient = Matrix(n, 1);
		NewtonMethod::hessian = Matrix(n, n);
	}

	NewtonMethod::NewtonMethod(Function* function, ARRAY_SIZE n, POINT x)
	{
		NewtonMethod::function = function;
		NewtonMethod::gradient = Matrix(n, 1);
		NewtonMethod::hessian = Matrix(n, n);
		NewtonMethod::x_old = x;
		NewtonMethod::gradient_old = findGradient(function, x_old);
	}

	MATRIX NewtonMethod::getHessian()
	{
		return NewtonMethod::hessian;
	}

	void NewtonMethod::setHessian(MATRIX hessian)
	{
		NewtonMethod::hessian = hessian;
	}

	MATRIX NewtonMethod::getGradient()
	{
		return NewtonMethod::gradient;
	}

	void NewtonMethod::setGradient(MATRIX gradient)
	{
		NewtonMethod::gradient = gradient;
	}

	void NewtonMethod::evaluateHessian(Function*& function, POINT& point)
	{
		for (SIZE i = 0; i < hessian.row; i++)
		{
			for (SIZE j = 0; j < hessian.column; j++)
			{
				hessian.arr[i][j] = derivative(function, point, { i + 1, j + 1 });
			}
		}
	}
	void NewtonMethod::evaluateGradient(Function*& function, POINT& point)
	{
		for (SIZE i = 0; i < gradient.row; i++)
		{
			gradient.arr[i][0] = derivative(function, point, { i + 1 });
		}
	}
	void NewtonMethod::findHessian(Function*& function, POINT& point)
	{
		MATRIX h = Matrix(hessian.row, hessian.column, 0);
		for (int i = 0; i < ipm.b.size(); i++)
		{
			h = h + (1 / pow(linearFunction(ipm.A[i], point) - ipm.b[i], 2)) * Matrix(ipm.A[i]).multiply(Matrix(ipm.A[i]).transpose());
		}
		hessian = h;
	}
	MATRIX NewtonMethod::findGradient(Function*& function, POINT& point)
	{
		MATRIX g = Matrix(gradient.row, gradient.column, 0);
		for (int i = 0; i < ipm.b.size(); i++)
		{
			g = g + (1 / (linearFunction(ipm.A[i], point) - ipm.b[i])) * Matrix(ipm.A[i]);
		}
		return g + omega * Matrix(ipm.c);
	}

	MATRIX NewtonMethod::iterate(POINT x)
	{
		//evaluateHessian(function, x);
		//evaluateGradient(function, x);

		gradient = findGradient(function, x);
		findHessian(function, x);

		MATRIX inverse;
		MATRIX subtract;
		try
		{
			inverse = hessian.inverse();
		}
		catch (std::exception ex)
		{
			throw ex;
		}

		subtract = inverse * gradient;
		for (int i = 0; i < subtract.row; i++)
		{
			for (int j = 0; j < subtract.column; j++)
			{
				if (subtract.arr[i][j] != subtract.arr[i][j])
				{
					throw std::exception("NaN found");
				}
			}
		}

		return Matrix(x) - alfa * subtract;
	}
}