#pragma once

#include "typedef.h"

#ifndef IPM_STRUCT_H
#define IPM_STRUCT_H

namespace InteriorPointMethod
{
	struct IPM
	{
		COEFFICIENTS c;
		INEQUALITY_ARRAY A;
		INEQUALITY_VECTOR b;

		IPM();
		IPM(COEFFICIENTS, INEQUALITY_ARRAY, INEQUALITY_VECTOR);
	};
}

#endif // !IPM_STRUCT_H
