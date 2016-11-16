#include"Header.h"
bool search(vector<int>& nums, int target) {
	int begin = 0, n = nums.size(), end = n - 1,mid=0;
	while (begin < end)
	{
		mid = begin + (end - begin) / 2;
		if (nums[mid] == target)return true;
		if (nums[mid] > nums[end])
		{
			if (nums[mid] > target && nums[begin] <= target)end = mid;
			else begin = mid + 1;
		}
		else if (nums[mid] < nums[end])
		{
			if (nums[mid] < target && nums[end] >= target)begin = mid + 1;
			else end = mid;
		}
		else end--;
	}
	return nums[begin] == target;
}