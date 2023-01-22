#include "function.h"

namespace InteriorPointMethod
{
	VALUE linearFunction(COEFFICIENTS c, POINT p)
	{
		MATRIX point(p);
		return Matrix(c).transpose().multiply(point).arr[0][0];
	}
}