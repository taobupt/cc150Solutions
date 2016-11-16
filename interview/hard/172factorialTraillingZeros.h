#include"Header.h"
int trailingZeroes(int n) {
	if (n < 5)return 0;
	else if (n == 5)return 1;
	else return trailingZeroes(n / 5) + n / 5;
}