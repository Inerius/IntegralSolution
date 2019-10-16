/*!
* file: Function.cpp
* synopsis: Func definitions for IntegralMethods
* variant: 15
* created by Mykola Ozerov KV-53
*/
#include "IntegralMethods.h"

double IntegralMethods::F(double x)
{
	return x * x * x * sin(3 * x) / 10;
}

double IntegralMethods::f(double x)
{
	return 3 * x * x / 10 * (sin(3 * x) + x * cos(3 * x));
}

double IntegralMethods::d4f(double x)
{
	return 3 / 10 * x * x * (189 * sin(3 * x) + 81 * cos (3 * x)) + 12 / 5 * x * (27 * x * sin(3 * x) - 54 * cos(3 * x)) - 18 / 5 * (15 * sin(3 * x) + 9 * x * cos(3 * x));
}

double IntegralMethods::SimpsonMethod(double a, double b, double eps, double &h)
{
	double Integral = f(a) + f(b);
	h = sqrt(sqrt(180 * eps / (b - a) / abs(d4f(b))));
	int N = (int)((b - a) / h) + 1;
	if (N % 2)
		N++;
	h = (b - a) / N;

	for (int i = 1; i < N; i += 2)
		Integral += 4 * f(a + h * i);

	for (int i = 2; i < N; i += 2)
		Integral += 2 * f(a + h * i);

	return Integral * h / 3;
}

double IntegralMethods::RefinedCalculation(double a, double b, double eps, double &h)
{
	double Integral, tmpIntegral, initValue = f(a) + f(b);
	int N = (int) 1 / sqrt(sqrt(eps)) + 1;
	if (N % 2)
		N++;
	h = (b - a) / N;
	Integral = initValue;

	for (int i = 1; i < N; i += 2)
		Integral += 4 * f(a + h * i);

	for (int i = 2; i < N; i += 2)
		Integral += 2 * f(a + h * i);

	Integral *= h;

	do
	{
		N *= 2;
		h /= 2;
		tmpIntegral = Integral;
		Integral = initValue;

		for (int i = 1; i < N; i += 2)
			Integral += 4 * f(a + h * i);

		for (int i = 2; i < N; i += 2)
			Integral += 2 * f(a + h * i);

		Integral *= h;
	} while (abs(Integral - tmpIntegral) / 15 > eps);

	return Integral / 3;
}