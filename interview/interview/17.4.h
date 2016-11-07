#include"Header.h"
#include"struct.h"

int getMax(int a,int b)
{
	int c = a - b;
	int k = (c >> 31) & 0x1;
	return (a - k*c);
}