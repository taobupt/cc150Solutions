#include"Header.h"
bool isPowerOfThree(int n) {
	if (n == 3 || n == 1)return true;
	if (n < 3)return false;
	while (n % 3 == 0)n /= 3;
	return n == 1;
}