#include"Header.h"
string convertToTitle(int n) {
	string res;
	while (n>=1)
	{
		res = char((n - 1) % 26 + 'A') + res;
		n = (n - 1) / 26;
	}
	return res;
}