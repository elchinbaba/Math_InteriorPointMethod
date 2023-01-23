#include <algorithm>
#include <log-barrier.h>
#include "primal-path-following.h"
#include "newton-method.h"

namespace InteriorPointMethod
{
	PrimalPathFollowing::PrimalPathFollowing(IPM ipm, bool doesStart)
	{
		if (doesStart)
		{
			this->ipm = ipm;
			initializeOmega();
			initializeQ();
		}
		else
		{
			VALUE t = 0;
			for (int i = 0; i < ipm.b.size(); i++)
			{
				t += abs(ipm.b[i]);
			}
			t += 1;

			this->ipm = ipm;
			initializeOmega();
			initializeQ();
			initializeX(initialize(ipm, t));
		}
	}

	VALUE PrimalPathFollowing::O_nL(IPM ipm)
	{
		VALUE L = 0, sizeof_value = sizeof(VALUE);
		ROW n = ipm.c.size();
		L += ipm.c.size();
		L += ipm.A.size() * ipm.A[0].size();
		L += ipm.b.size();
		L *= 8 * sizeof_value;

		VALUE O = n * L;

		while (O >= 10)
		{
			O /= 10;
		}

		//VALUE alfa = 0.0001;
		//VALUE O = alfa * n * L;

		return O;
	}

	VALUE PrimalPathFollowing::detmax(ARRAY_VALUE arr)
	{
		return exp(0);
	}

	POINT PrimalPathFollowing::calculate(bool stopAtNegative)
	{
		LogBarrier* lbf = new LogBarrier(ipm, omega);
		NewtonMethod* nm = new NewtonMethod(lbf, ipm.c.size(), x);
		nm->ipm = ipm;
		VALUE O = O_nL(ipm);

		for (int i = 1; i < 1000; i++)
		{
			try
			{
				if (stopAtNegative)
				{
					//std::cout << "init" << "\n";
				}

				x = nm->iterate(ipm, x).convertToVector();

				//Matrix(m_x).show();
				if (stopAtNegative && x[x.size() - 1] <= -exp(-O))
				{
					//std::cout << x[x.size() - 1] << " " << - exp(-O) << "\n";
					break;
				}
			}
			catch (std::exception e)
			{
				//std::cout << e.what() << " at iteration " << i << " \n";
				break;
			}
			lbf->omega = (1 + q) * lbf->omega;
			nm->omega = lbf->omega;
		}

		return x;
	}
}