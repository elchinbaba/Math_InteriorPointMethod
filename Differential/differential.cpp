#include "differential.h"

namespace InteriorPointMethod
{
	VALUE derivative(Function*& function, POINT& x, PARTIALS partials)
	{
		SIZE size = partials.size();
		if (size == 0)
		{
			return function->call(x);
		}

		UNSIGNED_INT deriving = partials[size - 1];
		partials.pop_back();

		POINT backward, forward;
		for (int i = 0; i < x.size(); i++)
		{
			if (i == deriving - 1)
			{
				forward.push_back(x[i] + EPS);
				backward.push_back(x[i] - EPS);
			}
			else
			{
				forward.push_back(x[i]);
				backward.push_back(x[i]);
			}
		}

		return (derivative(function, forward, partials) - derivative(function, backward, partials)) / (2 * EPS);
	}

	VALUE derivative_forward(Function*& function, POINT& x, PARTIALS partials)
	{
		if (partials.size() == 0)
		{
			return function->call(x);
		}

		UNSIGNED_INT deriving = partials[partials.size() - 1];
		partials.pop_back();

		POINT forward;
		for (int i = 0; i < x.size(); i++)
		{
			if (i == deriving - 1)
			{
				forward.push_back(x[i] + EPS);
			}
			else
			{
				forward.push_back(x[i]);
			}
		}

		return (derivative_forward(function, forward, partials) - derivative_forward(function, x, partials)) / EPS;
	}
}