#include"Header.h"
vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int>back(n,1);
	vector<int>forward(n,1);
	for (int i = 1; i < n; ++i)
	{
		forward[i] = forward[i - 1] * nums[i - 1];
		back[n - i - 1] = back[n - i] * nums[n - i];
	}
	for (int i = 0; i < n; ++i)
	{
		nums[i] = forward[i] * back[i];
	}
	return nums;
}
// follow up

vector<int> productExceptSelf1(vector<int>& nums) {
	int n = nums.size(),right=1;
	vector<int>res(n, 1);
	for(int i = 1; i < n; ++i)res[i] = nums[i - 1] * res[i - 1];
	for (int i = n - 1; i >= 0; --i)
	{
		res[i] *= right;
		right *= nums[i];
	}
	return nums;
}