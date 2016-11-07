#include"Header.h"
int maxProduct(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)return 0;
	vector<int>maximum(n, nums[0]);
	vector<int>minimum(n, nums[0]);
	int res = nums[0];
	for (int i = 1; i < n; ++i)
	{
		maximum[i] = max(maximum[i - 1] * nums[i], max(nums[i], minimum[i - 1] * nums[i]));
		minimum[i] = min(maximum[i - 1] * nums[i], min(nums[i], minimum[i - 1] * nums[i]));
		res = max(maximum[i], res);
	}
	return res;
}