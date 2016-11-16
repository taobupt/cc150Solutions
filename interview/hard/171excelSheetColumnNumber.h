#include"Header.h"
int titleToNumber(string s) {
	int res = 0, n = s.size();
	for (int i = n - 1; i >= 0; --i)
	{
		res = 26 * res+int(s[i] - 'A' + 1);
	}
	return res;
}