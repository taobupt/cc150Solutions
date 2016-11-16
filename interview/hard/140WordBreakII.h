#include"Header.h"



bool canBreak(string s, unordered_set<string>& wordDict)
{
	int n = s.size();
	vector<int>dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
			{
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n];
}

void dfs(vector<string>&res, string path, string s, unordered_set<string>& wordDict, int cur)
{
	if (cur == s.size())
	{
		res.push_back(path);
		return;
	}
	else
	{
		for (int i = cur; i < s.size(); ++i)
		{
			string tmp = s.substr(cur, i + 1 - cur);
			if (wordDict.find(tmp) != wordDict.end() && canBreak(s.substr(i + 1), wordDict))
			{
				if (!path.empty())
				{
					dfs(res, path + " " + tmp, s, wordDict, i + 1);//I recommend this way, which can save much time
				}
				else
				{
					dfs(res, tmp, s, wordDict, i + 1);
				}
			}
		}
	}

}


vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<string>res;
	string path = "";
	if (canBreak(s, wordDict))
	{
		dfs(res, path, s, wordDict, 0);
	}
	return res;
}