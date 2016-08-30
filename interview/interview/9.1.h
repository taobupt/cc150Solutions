#include"Header.h"
#include"struct.h"

int StepsToUpstaris(int n)
{
	int* dp = new int[n + 1];
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}