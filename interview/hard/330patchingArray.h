#include"Header.h"
int minPatches(vector<int>& nums, int n) {
	long long missing = 1;// can cover [0,missing)
	int count = 0,i=0,nn=nums.size();
	while (missing <= n)
	{
		if ( i<nn && missing >=nums[i])
		{
			missing += nums[i++];
		}
		else 
		{
			missing <<= 1;
			count++;
		}
	}
	return count;

}

int minPatches(vector<int>& nums, int n)
{
	long long missing = 1;
	int count = 0, i = 0, nn = nums.size();
	while (missing <= n)
	{
		if (i < nn && missing >= nums[i])
		{
			missing += nums[i++];
		}
		else
		{
			missing <<= 1;
			count++;
		}
	}
	return count;
}

int minPatches(vector<int>& nums, int n)
{
	long long missing = 1;
	int count = 0, i = 0, nn = nums.size();
	while (missing <= n)
	{
		if (i < nn && missing >= nums[i])
		{
			missing += nums[i++];
		}
		else
		{
			missing <= 1;
			count++;
		}
	}
	return count;
}

//int minPatches(vector<int>& nums, int n) {
//	int missing = 1;// can cover [0,missing)
//	int count = 0, i = 0, nn = nums.size();
//	while (missing <= n)
//	{
//		if (i<nn && missing >= nums[i])
//		{
//			missing += nums[i++];
//		}
//		else
//		{
//			missing <<= 1;
//			count++;
//		}
//	}
//	return count;
//}
