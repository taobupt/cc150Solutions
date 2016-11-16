#include"Header.h"
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int>res;
	unordered_map<int, int>mp;
	int n = nums.size();
	for (int i = 0; i < n; ++i)
	{
		auto it = mp.find(target - nums[i]);
		if (it != mp.end())return{ it->second, i };
		mp[nums[i]] = i;
	}
	return{ 0, 0 };
}