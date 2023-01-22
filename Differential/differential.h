#pragma once

#include <function.h>

#ifndef DIFFERENTIAL_H
#define DIFFERENTIAL_H

#define EPS 0.01

namespace InteriorPointMethod
{
	VALUE derivative(Function*&, POINT&, PARTIALS);
	VALUE derivative_forward(Function*&, POINT&, PARTIALS);
}

#endif