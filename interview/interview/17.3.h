#include"Header.h"
#include"struct.h"

int trailingZeros(int n)
{
	if (n < 5)return 0;
	if (n == 5)return 1;//optional
	else return n / 5 + trailingZeros(n / 5);
}