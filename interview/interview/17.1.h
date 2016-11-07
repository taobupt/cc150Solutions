#include"Header.h"
#include"struct.h"

void Myswap(int &a,int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}