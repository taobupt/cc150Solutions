#include"Header.h"
double myPow(double x, int n)
{
	bool negative = n >= 0 ? false : true;
	if (n == 0)return 1.0;
	unsigned nn = n > 0 ? n : -n;
	double res = 1.0;
	while (nn)
	{
		if (nn & 0x1)res *= x;
		nn >>= 1;
		x *= x;
	}
	return negative?1.0/res:res;
}


//recrusive
double mypow(double x, int n)
{
	if (n == 0)return 1;
	if (n < 0)
	{
		n = -n;
		x = 1.0 / x;
	}
	return (n % 2 == 0) ? mypow(x*x, n / 2) : x*mypow(x*x, n / 2);
}