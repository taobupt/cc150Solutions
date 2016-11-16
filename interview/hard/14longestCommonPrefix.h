#include"Header.h"
string longestCommonPrefix(vector<string>& strs) {
	int n = strs.size();
	string res;
	if (n < 1||strs[0].empty())return res;
	for (int i = 0; i < strs[0].size();++i)
	{
		res.push_back(strs[0][i]);
		for (int j = 1; j < n; ++j)
		{
			if (strs[i].substr(0, i) != res)
			{
				res.pop_back();
				return res;
			}
		}
	}
	return res;
}