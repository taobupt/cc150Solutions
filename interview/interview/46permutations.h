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
		int flag = false;
		for (int j = 0; j < path.size(); ++j)
		{
			if (nums[i] == path[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			path.push_back(nums[i]);
			dfs(res, path, nums);
			path.pop_back();
		}
	}
}

void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>nums)
{
	if (nums.size() == path.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		int flag = false;
		for (int j = 0; j < path.size(); ++j)
		{
			if (nums[i] == path[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			path.push_back(nums[i]);
			dfs(res, path, nums);
			path.pop_back();
		}
	}
}

vector <vector<int>>permute(vector<int>& nums)
{
	vector<vector<int>>res;
	vector<int>path;
	dfs(res, path, nums);
	return res;
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	dfs(res, path, nums);
	return res;
}

void perm(vector < vector<int>>&res, vector<int> nums, int k)
{
	if (k == nums.size())
	{
		res.push_back(nums);
		return;
	}
	if (k > nums.size())return;
	else
	{
		for (int i = k; i <nums.size(); ++i)
		{
			swap(nums[i], nums[k]);
			perm(res, nums, k + 1);
			//swap(nums[i], nums[k]);
		}
	}
}

vector<vector<int>> permute1(vector<int>& nums)
{
	vector <vector<int>>res;
	if (nums.size() == 0)return res;
	perm(res, nums, 0);
	//sort(res.begin(), res.end());
	return res;

}

void perm(vector<vector<int>>& res, vector<int> num, int k)
{
	if (k == num.size())
	{
		res.push_back(num);
		return;
	}
	else if (k > num.size())return;
	for (int i = k; i < num.size(); ++i)
	{
		swap(num[i], num[k]);
		perm(res, num, k + 1);
	}

}