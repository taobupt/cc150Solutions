#include"Header.h"

bool isPermutaiton(string x, string y)
{
	sort(x.begin(), x.end());
	sort(y.begin(), x.end());
	return x == y;
}