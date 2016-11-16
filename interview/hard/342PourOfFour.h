#include"Header.h"
bool isPowerOfFour(int n) {
	return !(n&(n - 1)) && (n & 0x55555555);
}