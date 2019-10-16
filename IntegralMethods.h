/*!
* file: IntegralMethods.h
* synopsis: Common declarations for IntegralMethods
* variant: 15
* created by Mykola Ozerov KV-53
*/
#pragma once
#include <cmath>

using namespace std;

class IntegralMethods 
{
public:
	IntegralMethods() {};
	double F(double x);
	double f(double x);
	double d4f(double x);
	double SimpsonMethod(double a, double b, double eps, double &h);
	double RefinedCalculation(double a, double b, double eps, double &h);
	~IntegralMethods() {};
};