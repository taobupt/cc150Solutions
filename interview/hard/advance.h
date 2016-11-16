#include"Header.h"
double mysqrt_newton(int x)
{
	double first = (double)x, last = 1.0;
	do{
		last = first;
		first = (first + x / first) / 2;
	} while (abs(first - last) > 1e-5);
	return first;
}