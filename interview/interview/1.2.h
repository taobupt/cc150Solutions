#include"Header.h"


//first solution
string reverseString(string x)
{
	reverse(x.begin(), x.end());
	return x;
}


//second solution
//
string reverseString2(string x)
{
	int n = x.size();
	for (int i = 0; i<n / 2; i++)
	{
		swap(x[i], x[n - i - 1]);
	}
	return x;
}