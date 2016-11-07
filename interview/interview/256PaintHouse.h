#include"Header.h"
int minCost(vector<vector<int>>& cost) {
	int n = cost.size();
	vector<vector<int>>dp(n + 1, vector<int>(3, 0));
	for (int i = 1; i <= n; ++i)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i - 1][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i - 1][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i - 1][2];
	}
	return min(dp[n][0], min(dp[n][1], dp[n][2]));
}
// optimalize
int minCost(vector<vector<int>>& cost) {
	int n = cost.size();

	//vector<vector<int>>dp(n + 1, vector<int>(3, 0));
	for (int i = 1; i < n; ++i)
	{
		cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
		cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
		cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
	}
	return min(cost[n-1][0], min(cost[n-1][1], cost[n-1][2]));
}