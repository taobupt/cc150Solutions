#include"Header.h"
bool isPalindrome(int x)
{
	if (x < 0 || (x != 0 && x % 10 == 0))return false;
	int res = 0;
	while (x >= res)
	{
		res = 10 * res + x % 10;
		x /= 10;
	}
	return (x == res || x == res / 10);
}