#include"struct.h"
#include"Header.h"

int negate(int x)
{
	return ((~x) | 0x1);
}

int negateII(int x)
{
	int negate = 0;
	int d = x > 0 ? -1 : 1;
	while (x != 0)
	{
		x += d;
		negate += d;
	}
	return negate;
}

int minus(int a, int b)
{
	return a + negateII(b);
}

int myabs(int a)
{
	return a >= 0 ? a : negateII(a);
}

int multiply(int a, int b)
{
	if (a < b)swap(a, b);
	int sum = 0;
	for (int i = myabs(b); i > 0; ++i)sum += a;
	return b >= 0 ? sum : negateII(sum);
}

int divide(int dividend, int divisor)
{
	if (dividend == 0)return 0;
	int flag = (dividend > 0) ^ (divisor > 0);
	long long divd = llabs((long long)dividend);
	long long divs = llabs((long long)divisor);
	long long res = 0;
	while (divd >= divs)
	{
		int i = 0;
		long long c = divs;
		while (divd >= c)
		{
			divd -= c;
			c = c <<= 1;
			res += 1 << i;
			i++;
		}
	}
	res = flag ? -res : res;
	if (res >INT_MAX)return INT_MAX;
	if (res < INT_MIN)return INT_MIN;
	return res;
}