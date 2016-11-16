#include"Header.h"

int change(int n)
{
	int res = 0;
	while (n)
	{
		int x = n % 10;
		res += x*x;
		n /= 10;
	}
	return res;
}

bool isHappy(int n) {
	int fast = n;
	int slow = n;
	do
	{
		fast = change(change(fast));
		slow = change(slow);
	} while (fast != slow);
	return fast == 1;
}