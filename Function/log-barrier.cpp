#include "log-barrier.h"

namespace InteriorPointMethod
{
	LogBarrier::LogBarrier(IPM ipm, OMEGA omega)
	{
		LogBarrier::ipm = ipm;
		LogBarrier::omega = omega;
	}

	VALUE LogBarrier::call(POINT x)
	{
		VALUE sum = 0, value = INFINITY, old_value;
		for (int i = 0; i < ipm.A.size(); i++)
		{
			old_value = value;
			value = linearFunction(ipm.A[i], x) - ipm.b[i];
			if (value == -old_value && value < 0)
			{
				sum -= log(-value);
			}
			else if (value == 0 || (value + 0.2 > 0 && value < 0))
			{
				continue;
			}
			else
			{
				sum -= log(value);
			}
		}

		return omega * linearFunction(ipm.c, x) + sum;
	}
}