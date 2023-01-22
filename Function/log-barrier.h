#pragma once

#include "barrier-function.h"

#ifndef LogBarrier_H
#define LogBarrier_H

namespace InteriorPointMethod
{
	class LogBarrier : public BarrierFunction
	{
	public:
		OMEGA omega;
	public:
		VALUE call(POINT);
	};
}

#endif // !LogBarrier_H
