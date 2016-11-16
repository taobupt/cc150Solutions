#include"Header.h"
int maximumGap(vector<int>& nums)
{
	if (nums.empty() || nums.size() < 2)return 0;
	int maxValue = *max_element(nums.begin(), nums.end());
	int exp = 1, n = nums.size();
	int R = 10;
	vector<int>aux(n, 0);
	while (maxValue / exp > 0)
	{
		vector<int>count(R, 0);
		for (int i = 0; i < n; ++i)count[(nums[i] / exp) % 10]++;
		for (int i = 1; i < R; ++i)count[i] += count[i - 1];
		for (int i = n - 1; i >= 0; --i)aux[--count[(nums[i] / exp) % 10]] = nums[i];
		for (int i = 0; i < n; ++i)nums[i] = aux[i];
		exp *= 10;
	}
	int maxGap = 0;
	for (int i = 1; i < n; ++i)maxGap = max(maxGap, aux[i] - aux[i - 1]);
	return maxGap;
}