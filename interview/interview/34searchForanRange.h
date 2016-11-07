#include"Header.h"

int lower(vector<int>nums, int target)
{
	if (nums.empty())return 0;
	if (target > nums.back())return nums.size();
	int pos = 0, left = 0, right = nums.size() - 1, mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] >=target)
		{
			right = mid;
			pos = right;
		}
		else
		{
			left = mid + 1;
			pos = left;
		}
	}
	return pos;
}



int upper(vector<int>nums, int target)
{
	if (nums.empty())return 0;
	if (target >=nums.back())return nums.size();
	int pos = 0, left = 0, right = nums.size() - 1, mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] >target)
		{
			right = mid;
			pos = right;
		}
		else
		{
			left = mid + 1;
			pos = left;
		}
	}
	return pos;
}
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int>res;
	int index1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	if (nums[index1] != target)return{ -1, -1 };
	//int index2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
	return{ index1, index2 - 1 };
}