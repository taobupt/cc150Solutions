#include"Header.h"
bool dp[5005];

//memory limited 抽风了
//直觉没错，应该用back做，可以尝试下，我最后是用python做出来的。python就没有限制

bool backtrack(vector<int>& nums, int sum, int start)
{
	if (sum <= 0)return sum == 0;
	for (int i = start; i < nums.size(); ++i)
	{
		if (backtrack(nums, sum - nums[i], i + 1))return true;
	}
	return false;
}

bool canPartition(vector<int>& nums)
{
	int res=accumulate(nums.begin(), nums.end(), 0);
	return !(res & 0x1) && backtrack(nums,res>>1,0)
}


bool canPartition(vector<int>& nums) {
	int res = 0, n = nums.size();
	unordered_map<int, unordered_set<int>>mp;
	for (int x : nums)
	{
		res += x;
	}
	if (res % 2 != 0)return false;
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	sort(nums.begin(), nums.end());
	for (int i = 1; i <= res / 2; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			if (i >= nums[j] && mp[i - nums[j]].find(j) == mp[i - nums[j]].end())
			{
				dp[i] = dp[i - nums[j]];
				mp[i].insert(j);
				if (dp[i])break;
			}
			if (i < nums[j])break;
		}
	}
	return dp[res / 2];

}