#include"Header.h"
int removeElement(vector<int>&nums, int val)
{
	int n = nums.size(), i = 0,j=0;
	while (i < n)
	{
		if (nums[i] != val)nums[j++] = nums[i];
		i++;
	}
	return j;
}