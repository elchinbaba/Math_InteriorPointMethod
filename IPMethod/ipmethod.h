#pragma once

#ifndef IPMETHOD_H
#define IPMETHOD_H

namespace InteriorPointMethod
{
	class IPMethod
	{
	protected:
		struct IPM ipm;
		START_POINT x;

	protected:
		virtual POINT calculate() = 0;
	};
}

#endif // !IPMETHOD_H