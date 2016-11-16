#include"Header.h"
int longestConsecutive(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1)return n;
	sort(nums.begin(), nums.end());
	int i = 1, j = 1;
	while (i<n)
	{
		if (nums[i] != nums[i - 1])nums[j++] = nums[i];
		i++;
	}
	int res = 1, start = 0;
	for (int i = 1; i < j; ++i)
	{
		if (nums[i] - nums[i - 1] != 1)
		{
			res = max(res, i - start);
			start = i;
		}
	}
	res = max(res, j - start);
	return res;
}


//
int longestConsecutive(vector<int>& nums)
{
	unordered_set<int>record(nums.begin(), nums.end());
	int res = 1;
	for (int n : nums)
	{
		if (record.find(n) == record.end())continue;
		record.erase(n);
		int prev = n - 1, next = n + 1;
		while (record.find(prev) != record.end())record.erase(prev--);
		while(record.find(next) != record.end())record.erase(next++);
		res = max(res, next - prev - 1);
	}
	return res;
}

// 

int longestConsecutive(vector<int>& nums)
{
	unordered_set<int>record(nums.begin(), nums.end());
	int res = 1;
	for (int n : nums)
	{
		if (record.find(n) == record.end())continue;
		record.erase(n);
		int prev = n - 1, next = n + 1;
		while (record.find(prev) != record.end())record.erase(prev--);
		while (record.find(next) != record.end())record.erase(next++);
		res = max(res, next - prev - 1);
	}
	return res;
}