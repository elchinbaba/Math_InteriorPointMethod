#pragma once

#ifndef NEWTON_METHOD_H
#define NEWTON_METHOD_H

namespace InteriorPointMethod
{
	class NewtonMethod
	{
	public:
		Function* function;
		MATRIX hessian;
		MATRIX gradient;

	public:
		IPM ipm;
		OMEGA omega;
		VALUE alfa = 0.85;


	public:
		NewtonMethod();
		NewtonMethod(Function*, SIZE);

	public:
		MATRIX getHessian();
		void setHessian(MATRIX);
		MATRIX getGradient();
		void setGradient(MATRIX);

	public:
		void evaluateHessian(Function*&, POINT&);
		void evaluateGradient(Function*&, POINT&);
		void findHessian(Function*&, POINT&);
		MATRIX findGradient(Function*&, POINT&);

	public:
		MATRIX iterate(POINT);
	};
}

#endif // !NEWTON_METHOD_H