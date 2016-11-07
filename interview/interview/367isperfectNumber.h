#include"Header.h"
bool isPerfectSquare(int num) {
	if (num<0)return false;
	if (num == 0 || num == 1)return true;
	int left = 0, right = num, mid = 0;
	while (left<right)
	{
		mid = left + (right - left) / 2;
		if (mid>46340)
		{
			right = mid;
			continue;
		}
		int res = mid*mid;
		if (res == num)return true;
		else if (res>num)right = mid;
		else left = mid + 1;
	}
	return false;
}


// newton 
//long x = num;
//while (x * x > num) {
//	x = (x + num / x) >> 1;
//}3
//return x * x == num;