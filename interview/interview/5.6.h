#include"struct.h"
#include"Header.h"

int swapOddEven(int a)
{
	int even = a &(0x55555555);
	int odd = a &(0xaaaaaaaa);
	even <<= 1;
	odd >>= 1;
	return (even || odd);
}