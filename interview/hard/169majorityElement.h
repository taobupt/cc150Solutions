#include"Header.h"
int majorityElement(vector<int>& nums) {
	unordered_map<int, int>mp;
	int n = nums.size();
	for (int x : nums)
	{
		mp[x]++;
		if (mp[x] > n / 2)return x;
	}
	return 0;

}

//mo er vote

int majorityElement1(vector<int>& nums)
{
	int n = nums.size();
	int a = nums[0], count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (count == 0)
		{
			a = nums[i];
			count = 1;
		}
		else if (a == nums[i])count++;
		else count--;
	}
	return a;
}