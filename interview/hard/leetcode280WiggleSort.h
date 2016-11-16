#include"Header.h"
void wiggleSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n-1; ++i)
	{
		if (i & 0x1 == 1)
		{
			if (nums[i] < nums[i + 1])swap(nums[i], nums[i + 1]);
		}
		else if (nums[i] > nums[i + 1])swap(nums[i], nums[i + 1]);
	}
}