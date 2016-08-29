#include"Header.h"
#include"struct.h"
bool getBit(int num, int i)
{
	return (num &(1 << i)) != 0;
}

int setBit(int num, int i)
{
	return(num | (1 << i));
}

int clearBit(int num, int i)
{
	int mask = ~(1 << i);
	return num & mask;
}

int clearBitsMSBthroughI(int num, int i)
{
	int mask = (1 <<i) - 1;
	return num&mask;
}

int clearBitsthrough0(int num, int i)
{
	int mask = ~((1 << (i + 1)) - 1);
	return num & mask;
}