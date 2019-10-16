/*!
* file: IntegralSolution.cpp
* synopsis: IntegralMethods test drive
* variant: 15
* created by Mykola Ozerov KV-53
*/
#include <vector>
#include "IntegralMethods.h"

int main()
{
	IntegralMethods MyMethods;
	double h, xk, error, a = 2, b = 10;
	vector<double> approx_errors;
	double exact_val = MyMethods.F(b) - MyMethods.F(a);

	printf("eps\t\th\t\texact_value\tapprox_error\n");
	for (double starteps = 1e-2; starteps > 1e-14; starteps *= 1e-3)
	{
		xk = MyMethods.SimpsonMethod(a, b, starteps, h);
		error = abs(xk - exact_val);
		approx_errors.push_back(error);
		printf("%.2e\t%.2e\t%lf\t%e\n", starteps, h, exact_val, error);
	}

	printf("\neps\t\th\t\tapprox_error\n");
	for (size_t i = 0; i < approx_errors.size(); i++)
	{
		xk = MyMethods.RefinedCalculation(a, b, approx_errors[i], h);
		error = abs(xk - exact_val);
		printf("%.2e\t%.2e\t%e\n", approx_errors[i], h, error);
	}
	return 0;
}