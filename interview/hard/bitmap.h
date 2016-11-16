#include"Header.h"
int add(int a, int b)
{
	if (a == 0 || b == 0)return a == 0 ? b:a;
	return add(a^b, (a&b) << 1);
}


int Neg(int a)
{
	return add(~a, 1);
}
int Minus(int a, int b)
{
	return add(a, Neg(b));
}

int Mulptily(int a, int b)
{
	int ans = 0;
	bool isNeg = (a > 0) ^ (b > 0);
	unsigned int x = a > 0 ? a : Neg(a), y = b > 0 ? b : Neg(b);
	while (y)
	{
		if (y & 0x01)ans=add(ans,x);
		y >>=1;
		x <<=1;
	}
	return isNeg ? Neg(ans) : ans;
}


// divide is the leetcode 