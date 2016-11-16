#include"Header.h"
int getSum(int a, int b) {
	if (a == 0 || b == 0)return a == 0 ? b : a;
	return getSum(a^b, (a&b) << 1);
}

int gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a%b);
}