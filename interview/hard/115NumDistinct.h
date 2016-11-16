#include"Header.h"

int numDistinct(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i)dp[i][0] = 1;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] += dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
		}
	}
	return dp[m][n];
}

int numDistinct(string s, string t)
{
	int m = s.size(), n = t.size();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i)dp[i][0] = 1;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)dp[i][j] += dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
	}
	return dp[m][n];
}