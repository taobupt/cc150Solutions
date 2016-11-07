#include"Header.h"
vector<string>findRepeateDnaSequnece(string s)
{
	unordered_map<string, int>mp;
	vector<string>res;
	int n = s.size();
	for (int i = 0; i < n - 9; ++i)
	{
		if (++mp[s.substr(i, 10)] == 2)res.push_back(s.substr(i, 10));
	}
	return res;
}


// octal A 0101, C 0103, g 0107 t 0124
vector<string> findRepeatedDnaSequences1(string s) {
	unordered_map<int, int>mp;
	vector<string>res;
	int t = 0, i = 0, n = s.size();
	while (i < 9)
	{
		t = t << 3 |s[i++] & 7;
	}
	while (i < n)
	{
		if (mp[t = t << 3 & 0x3fffffff | s[i++] & 7]++ == 1)res.push_back(s.substr(i - 10, 10));
	}
	return res;
}