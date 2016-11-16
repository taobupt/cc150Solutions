#include"Header.h"
int findPeakElement(vector<int>& nums) {
	int n = nums.size(), left = 0, right = n - 1,mid=0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < nums[mid + 1])left = mid + 1;
		else right = mid;
	}
	return left;
}