#include"Header.h"

void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>nums)
{
	if (nums.size() == path.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (!i || nums[i] != nums[i - 1])
		{
			int cnt1 = 0, cnt2 = 0;
			for (int j = 0; j < nums.size(); ++j)if (nums[j] == nums[i])cnt1++;
			for (int j = 0; j < path.size(); ++j)if (path[j] == nums[i])cnt2++;
			if (cnt2 < cnt1)
			{
				path.push_back(nums[i]);
				dfs(res, path, nums);
				path.pop_back();
			}
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	dfs(res, path, nums);
	return res;
}


void dfs(vector<vector<int>> &res, vector<int>& path, vector<int>nums)
{
	if (nums.size() == path.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (!i || nums[i] != nums[i - 1])
		{
			int cnt1 = 0, cnt2 = 0;
			for (int j = 0; j < nums.size(); ++j)if (nums[j] == nums[i])cnt1++;
			for (int j = 0; j < path.size(); ++j)if (path[j] == nums[i])cnt2++;
			if (cnt1 < cnt2)
			{
				path.push_back(nums[i]);
				dfs(res, path, nums);
				path.pop_back();
			}
		}
	}
}
vector<vector<int>>permuteUnique(vector<int>& nums)
{
	vector<vector<int>>res;
	vector<int>path;
	dfs(res, path, nums);
	return res;
}


void recrusive(vector<int>num, int i, int n, vector<vector<int>>& res)
{
	if (i == n)
	{
		res.push_back(num);
	}
	else if (i > n)return;
	for (int k = i; k < n; ++k)
	{
		if (i == k || num[k] != num[k - 1])
		{
			swap(num[k], num[i]);
			recrusive(num, i + 1, n, res);
		}
	}
}