#include"Header.h"
#include"struct.h"

//explain what the following code does:((n&(n-1)))==0  : it checks that whether n has only one '1' in its binary expression

bool isPowerOfFour(int num)
{
	return num > 0 && num&(num - 1) == 0 && num&(0x55555555) != 0;//one '1' only occurs in odd digits
}

bool isPowerOfTwo(int  num)
{
	return num > 0 && num&(num - 1) == 0;
}