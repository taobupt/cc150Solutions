#include"Header.h"
string convert(string s, int numRows)
{
	string res;
	vector<string>v(numRows,"");
	int n = s.size(), i = 0;
	while (i < n)
	{
		for (int j = 0; j < numRows; ++j)
		{
			if(i<n)v[j].push_back(s[i++]);
			else break;
		}
		for (int j = numRows - 2; j > 0; --j)
		{
			if(i<n)v[j].push_back(s[i++]);
			else break;
		}
	}
	for (string strs : v)res += strs;
	return res;
}