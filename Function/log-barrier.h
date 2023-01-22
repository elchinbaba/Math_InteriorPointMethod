#pragma once

#include "barrier-function.h"
#include "ipm-struct.h"

#ifndef LogBarrier_H
#define LogBarrier_H

namespace InteriorPointMethod
{
	class LogBarrier : public BarrierFunction
	{
	public:
		IPM ipm;
		OMEGA omega;

	public:
		LogBarrier(IPM, OMEGA);

	public:
		VALUE call(POINT);
	};
}

#endif // !LogBarrier_H
