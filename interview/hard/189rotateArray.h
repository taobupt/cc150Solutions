#include"Header.h"
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	k = n - k%n;
	if (n <= 1 || k == 0 || k == n)return;
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
	reverse(nums.begin(), nums.end());
}