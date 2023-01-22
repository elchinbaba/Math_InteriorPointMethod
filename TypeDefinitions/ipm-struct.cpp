#include "ipm-struct.h"

namespace InteriorPointMethod
{
	IPM::IPM()
	{
		this->c = COEFFICIENTS();
		this->A = INEQUALITY_ARRAY();
		this->b = INEQUALITY_VECTOR();
	}

	IPM::IPM(COEFFICIENTS c, INEQUALITY_ARRAY A, INEQUALITY_VECTOR b)
	{
		this->c = c;
		this->A = A;
		this->b = b;
	}
}