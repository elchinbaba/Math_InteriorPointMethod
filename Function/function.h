#pragma once

#include <Matrix.h>

#ifndef FUNCTION_H
#define FUNCTION_H

namespace InteriorPointMethod
{
	VALUE linearFunction(COEFFICIENTS, POINT);

	class Function
	{
	public:
		virtual VALUE call(POINT) = 0;
	};
}

#endif FUNCTION_H