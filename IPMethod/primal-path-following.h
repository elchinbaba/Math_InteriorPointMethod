#pragma once

#include <function.h>
#include <ipm-struct.h>
#include "ipmethod.h"

#ifndef PRIMAL_PATH_FOLLOWING_H
#define PRIMAL_PATH_FOLLOWING_H

namespace InteriorPointMethod
{
	class PrimalPathFollowing : public IPMethod
	{
	public:
		IPM ipm;
		OMEGA omega;
		Q q;
		START_POINT x;

	public:
		PrimalPathFollowing(IPM, bool);

	public:
		VALUE O_nL(IPM);
		VALUE detmax(ARRAY_VALUE);

	public:
		void initializeOmega();
		void initializeQ();
		void initializeX(VALUE);
		void initializeX(POINT);
		POINT initialize(IPM, VALUE);

	public:
		POINT calculate(bool);
	};
}

#endif // !PRIMAL_PATH_FOLLOWING_H