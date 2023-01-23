#include <algorithm>
#include "primal-path-following.h"

namespace InteriorPointMethod
{
	void PrimalPathFollowing::initializeOmega()
	{
		VECTOR_VALUE b_abs;
		for (int i = 0; i < ipm.b.size(); i++)
		{
			b_abs.push_back(abs(ipm.b[i]));
		}
		VECTOR_VALUE c_abs;
		for (int i = 0; i < ipm.c.size(); i++)
		{
			c_abs.push_back(abs(ipm.c[i]));
		}
		VALUE b_max = *std::max_element(std::begin(b_abs), std::end(b_abs));
		VALUE c_max = *std::max_element(std::begin(c_abs), std::end(c_abs));
		VALUE A_detmax = detmax(ipm.A);

		VECTOR_VALUE maxes = { log(b_max), log(c_max), log(A_detmax) };

		VALUE L = 1 + *std::max_element(std::begin(maxes), std::end(maxes));
		VALUE c = 5;

		PrimalPathFollowing::omega = exp(-c * L);
	}
	void PrimalPathFollowing::initializeQ()
	{
		PrimalPathFollowing::q = 1 / (sqrt(ipm.b.size()));
	}
	void PrimalPathFollowing::initializeX(VALUE t)
	{
		for (int i = 0; i < ipm.c.size() - 1; i++)
		{
			PrimalPathFollowing::x.push_back(0);
		}
		PrimalPathFollowing::x.push_back(t);
	}
	void PrimalPathFollowing::initializeX(POINT a)
	{
		PrimalPathFollowing::x = a;
	}
	POINT PrimalPathFollowing::initialize(IPM ipm, VALUE v)
	{
		IPM ipm_for_init = IPM(ipm.c, ipm.A, ipm.b);

		for (int i = 0; i < ipm_for_init.c.size(); i++)
		{
			ipm_for_init.c[i] = 0;
		}
		ipm_for_init.c.push_back(1);

		for (int i = 0; i < ipm_for_init.A.size(); i++)
		{
			ipm_for_init.A[i].push_back(v);
		}
		VECTOR_VALUE a;
		for (int i = 0; i < ipm_for_init.c.size(); i++)
		{
			a.push_back(0);
		}
		a[a.size() - 1] = 1;
		ipm_for_init.A.push_back(a);
		a[a.size() - 1] = -1;
		ipm_for_init.A.push_back(a);

		VALUE O = O_nL(ipm);
		//std::cout << O << "\n";
		ipm_for_init.b.push_back(-exp(O));
		ipm_for_init.b.push_back(-exp(O));

		PrimalPathFollowing ppf = PrimalPathFollowing(ipm_for_init, true);
		ppf.initializeX(v);

		POINT x = ppf.calculate(true);
		POINT x_for_init;
		for (int i = 0; i < x.size() - 1; i++)
		{
			x_for_init.push_back(x[i]);
		}
		return x_for_init;
	}
}