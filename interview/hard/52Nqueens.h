#include"Header.h"



inline bool check(int k, int* dp)
{
	for (int i = 0; i < k; ++i)
	{
		if (dp[i] == dp[k] || abs(dp[k] - dp[i]) == abs(k - i))return false;
	}
	return true;
}
void dfs(int* places, int& ans, int cur, int n)
{
	if (cur == n)
	{
		ans++;
		return;
	}
	if (cur > n)return;
	for (int i = 0; i < n; ++i)
	{
		places[cur] = i;
		if (check(cur, places))dfs(places, ans, cur + 1, n);
	}
}
bool totalNqueens(int n)
{
	if (n == 0)return 0;
	int* places = new int[n];
	int ans = 0;
	dfs(places, ans, 0, n);
}
bool check(int k, int *dp)
{
	for (int i = 0; i < k; ++i)
	{
		if (dp[i] == dp[k] || abs(dp[k] - dp[i]) == abs(k - i))return false;
	}
	return true;
}


void dfs(int* dp, int &ans, int cur, int n)
{
	if (cur == n)
	{
		ans++;
		return;
	}
	if (cur>n)return;
	for (int i = 0; i < n; ++i)
	{
		dp[cur] = i;
		if (check(cur, dp))
		{
			dfs(dp, ans, cur + 1, n);
		}
	}
}
int totalNQueens(int n) {
	if (n == 0)return 0;
	int *dp = new int[n];
	int ans = 0;
	dfs(dp, ans, 0, n);
	delete[]dp;
	return ans;
}