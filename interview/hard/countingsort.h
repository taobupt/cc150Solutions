#include"Header.h"
vector<int> count_sort(vector<int>& nums)
{
	int maxValue = *max_element(nums.begin(), nums.end());
	vector<int>C(maxValue + 1,0);
	//memset(C, 0, sizeof(C));
	int n = nums.size();
	for (int i = 0; i < n; ++i)C[nums[i]]++;
	for (int i = 1; i <=maxValue; ++i)C[i] += C[i - 1];
	vector<int>res(n, 0);
	for (int i = n-1; i>=0; --i)
	{
		res[--C[nums[i]]] = nums[i];// this is important
		//C[nums[i]]--;
	}
	return res;
}