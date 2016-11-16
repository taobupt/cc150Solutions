#include"Header.h"
int addDigits(int num) {
	int res = 0;
	while (num >= 10)
	{
		res = num;
		int res1 = 0;
		while (res)
		{
			res1 += res % 10;
			res /= 10;
		}
		num = res1;
	}
	return num;
}

//digits root;
//1 + (n - 1) % 9;