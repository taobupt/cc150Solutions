#include"Header.h"


//low efficiency
bool wordPattern(string pattern, string str) {
	int n = pattern.size();
	vector<string>res;
	stringstream ss(str);
	string tmp;
	while (getline(ss, tmp, ' '))
	{
		res.push_back(tmp);
	}
	if (n != res.size())return false;
	unordered_map<char, string>mp1;
	unordered_map<string, char>mp2;
	for (int i = 0; i < n; ++i)
	{
		if (mp1.find(pattern[i]) == mp1.end())
		{
			mp1[pattern[i]] = res[i];
		}
		else if (mp1.find(pattern[i]) != mp1.end())
		{
			if (mp1[pattern[i]] != res[i])return false;
		}
		if (mp2.find(res[i]) == mp2.end())
		{
			mp2[res[i]] = pattern[i];
		}
		else if (mp2.find(res[i]) != mp2.end())
		{
			if (mp2[res[i]] != pattern[i])return false;
		}
	}
	return true;
}


//high efficiency
bool wordPattern1(string pattern, string str) {
	istringstream strcin(str);
	string s;
	vector<string> vs;
	while (strcin >> s) vs.push_back(s);
	if (pattern.size() != vs.size()) return false;
	map<string, char> s2c;
	map<char, string> c2s;
	for (int i = 0; i < vs.size(); ++i) {
		if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") {
			s2c[vs[i]] = pattern[i];
			c2s[pattern[i]] = vs[i];
			continue;
		}
		if (s2c[vs[i]] != pattern[i]) return false;
	}
	return true;
}