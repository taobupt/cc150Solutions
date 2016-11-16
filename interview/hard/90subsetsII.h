#include"Header.h"


void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>&nums, int cur)
{
	res.push_back(path);
	for (int i = cur; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		dfs(res, path, nums, i + 1);
		while (i<int(nums.size()) - 1 && nums[i] == nums[i + 1])i++;
		path.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	sort(nums.begin(), nums.end());////must sort first, otherwise it wil fail
	dfs(res, path, nums,0);
	return res;
}

void dfs1(string& path, string nums, int cur,set<string>& res)
{
	if (!path.empty())res.insert(path);
	for (int i = cur; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		dfs1( path, nums, i + 1,res);
		while (i<int(nums.size()) - 1 && nums[i] == nums[i + 1])i++;
		path.pop_back();
	}
}
void subsetsWithDup1(string nums) {
	//vector<vector<int>>res;
	string path;
	set<string>res;
	//sort(nums.begin(), nums.end());////must sort first, otherwise it wil fail
	dfs1(path, nums, 0,res);
	for (auto it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << endl;
	}
}