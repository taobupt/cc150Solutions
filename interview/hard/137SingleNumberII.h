#include"Header.h"
int singleNumber(vector<int>& nums) {
	int n = nums.size(), res = 0;
	int bit[32] = { 0 };
	for (int i = 0; i<32; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			bit[i] += (nums[j] >> i) & 0x1;
		}
		if (bit[i] % 3 != 0)res += (1 << i);
	}
	return res;
}