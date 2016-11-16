#include"Header.h"
int romanToInt(string s)
{
	unordered_map<char, int>mp = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
	int res =mp[s.back()];
	int n = s.size();
	for (int i = n - 2; i >= 0; --i)
	{
		res += mp[s[i]] < mp[s[i + 1]] ? -mp[s[i]] : mp[s[i]];
	}
	return res;
}