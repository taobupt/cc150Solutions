#include"Header.h"

//dp[start][end] is defined as the maximum coins we can get by bursting balloons between "start" and "end" (exclusively, means "start" and "end" won't burst).
int maxCoins(vector<int>& nums) {
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	int n = nums.size();
	vector<vector<int>>dp(n, vector<int>(n, 0));
	for (int len = 1; len < n - 1; ++len)
	{
		for (int start = 0; start < n - 1 - len; ++start)
		{
			int end = start + len + 1;
			for (int k = start + 1; k < end; ++k)
			{
				dp[start][end] = max(dp[start][end], dp[start][k] + dp[k][end] + nums[start] * nums[k] * nums[end]);
			}
		}
	}
	return dp[0][n - 1];
}