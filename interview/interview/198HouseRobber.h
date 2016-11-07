#include"Header.h"
#define max(a,b) ((a)>(b)?(a):(b))

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)return 0;
	else if (n == 1)return nums[0];
	else if (n == 2)return  max(nums[0], nums[1]);
	vector<int>dp(n + 1, 0);
	dp[1] = nums[0];
	dp[2] = max(nums[0], nums[1]);
	for (int i = 2; i < n; ++i)
	{
		dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
	}
	return dp[n];
}

int rob(vector<int>& nums)
{
	int a = 0, b = 0,n=nums.size();// even index,odd index
	for (int i = 0; i < n; ++i)
	{
		if (i & 0x1)
		{
			b = max(a, b + nums[i]);
		}
		else
		{
			a = max(a + nums[i], b);
		}
	}
	return max(a, b);

}