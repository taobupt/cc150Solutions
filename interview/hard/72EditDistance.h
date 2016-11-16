#include"Header.h"
int minDistance(string word1, string word2) {
	int m = word1.size(), n = word2.size();
	if (m == 0 || n == 0)return m == 0 ? n : m;
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i)dp[i][0] = i;
	for (int j = 0; j <= n; ++j)dp[0][j] = j;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + word1[i - 1] == word2[j - 1] ? 0 : 1);
		}
	}
	return dp[m][n];
}

int minDistance(string word1, string word2)
{
	int m = word1.size(), n = word2.size();
	if (m == 0 || n == 0)return m == 0 ? n : m;
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; ++i)dp[i][0] = i;
	for (int j = 0; j <= n; ++j)dp[0][j] = j;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + word1[i - 1] == word2[j - 1] ? 0 : 1);
		}
	}
	return dp[m][n];
}