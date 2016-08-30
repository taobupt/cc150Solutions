#include"Header.h"
#include"struct.h"

int combinationsSum(int target)
{
	int coins[4] = { 1, 5, 10, 25 };
	vector<int>dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= target; ++i)
	{
		for (int j = 0; j <4; ++j)
		{
			if (i >= coins[j])dp[i] += dp[i - coins[j]];
		}
	}
	return dp[target];
}