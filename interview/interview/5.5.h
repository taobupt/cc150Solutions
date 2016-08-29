#include"Header.h"
#include"struct.h"

int convert(int A, int B)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		count += ((A >> i) & 1) ^ ((B >> i) & 1);
	}
	return count;
}