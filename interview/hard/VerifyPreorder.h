#include"struct.h"


bool verifyPreorder(vector<int>& nums)
{
	int minValue = INT_MIN, n = nums.size(),index=-1;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] < minValue)return false;
		while (index >= 0 && nums[i] > nums[index])
		{
			minValue = nums[index--];
		}
		nums[++index]=nums[i];
	}
	return true;

}