#include"Header.h"
int maxProduct(vector<int>& nums) {
	int n = nums.size(), res = INT_MIN;
	if (n == 0)return 0;
	vector<int>maximum(n + 1, 1);
	vector<int>minimum(n + 1, 1);
	for (int i = 1; i <= n; ++i)
	{
		maximum[i] = max(max(maximum[i - 1] * nums[i - 1], minimum[i - 1] * nums[i - 1]), nums[i - 1]);
		minimum[i] = min(min(minimum[i - 1] * nums[i - 1], maximum[i - 1] * nums[i - 1]), nums[i - 1]);
		res = max(maximum[i], res);
	}
	return res;
}