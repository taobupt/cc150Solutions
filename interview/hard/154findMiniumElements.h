#include"Header.h"
int findMin(vector<int>& nums) {
	int n = nums.size(), left = 0, right = n - 1, middle = 0;
	while (left < right)
	{
		if (nums[left] < nums[right])return nums[left];
		middle = left + (right - left) / 2;
		if (nums[middle] > nums[right])left = middle + 1;
		else if (nums[middle]<nums[right]) right = middle;
		else right--;
	}
	return nums[left];
}

int findMin(vector<int>& nums)
{
	int n = nums.size(), left = 0, right = n - 1, middle = 0;
	while (left < right)
	{
		if (nums[left] < nums[right])return nums[left];
		middle = left + (right - left) / 2;
		if (nums[middle] > nums[right])left = middle + 1;
		else if (nums[middle] < nums[right])right = middle;
		else right--;
	}
	return nums[left];
}