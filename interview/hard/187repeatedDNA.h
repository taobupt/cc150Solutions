#include"Header.h"
vector<string> findRepeatedDnaSequences(string s) {
	int n = s.size();
	vector<string>res;
	if (n < 10)return res;
	unordered_map<string, int>mp;
	for (int i = 0; i < n - 9; ++i)
	{
		string sub = s.substr(i, 10);
		if (mp[sub]++ == 1)res.push_back(sub);
	}
	return res;
}