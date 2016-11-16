#include"Header.h"
bool isPalindrome(string ss)
{
	int n = ss.size();
	if (n <= 1)return true;
	for (int i = 0; i<n / 2; ++i)
	{
		if (ss[i] != ss[n - 1 - i])return false;
	}
	return true;
}

void backtrack(vector<vector<string>> &res, vector<string> &path, string &s, int cur)
{
	if (cur == s.size())
	{
		res.push_back(path);
		return;
	}
	if (cur>s.size())return;
	for (int i = cur; i<s.size(); ++i)
	{
		string sub = s.substr(cur, i - cur + 1);
		if (isPalindrome(sub))
		{
			path.push_back(sub);
			backtrack(res, path, s, i + 1);
			path.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>>res;
	vector<string>path;
	backtrack(res, path, s, 0);
	return res;
}