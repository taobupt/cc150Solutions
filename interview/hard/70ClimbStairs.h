#include"Header.h"
int climbStairs(int n) {
	if (n <= 2)return n;
	int g = 1, h = 2;
	for (int i = 3; i <= n; ++i)
	{
		h += g;
		g = h - g;
	}
	return h;
}