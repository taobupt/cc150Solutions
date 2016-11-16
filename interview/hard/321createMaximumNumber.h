#include"Header.h"
vector<int>GetMaxSubArray(vector<int>nums, int k)
{
	vector<int>res(k, 0);
	int n = nums.size(), le = 0;
	for (int i = 0; i < n; ++i)
	{
		while (le && le + n - i > k && nums[i] > res[le - 1])le--;
		if (le < k)res[le++] = nums[i];
	}
	return res;
}
bool greater1(vector<int> &a, int start1, vector<int> &b, int start2)
{
	for (; start1 < a.size() && start2 < b.size(); ++start1, ++start2)
	{
		if (a[start1]>b[start2])return true;
		else if (a[start1] < b[start2])return false;
	}
	return start1 != a.size();
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& num2, int k)
{
	vector<int>ans(k, 0);
	for (int i = max(0, k - (int)num2.size()); i < min(k, (int)nums1.size()); i++)
	{
		vector<int>res1 = GetMaxSubArray(nums1, i);
		vector<int>res2 = GetMaxSubArray(num2, k - i);
		vector<int>res(k, 0);
		int pos1 = 0, pos2 = 0, tpos = 0;
		while (pos1 < res1.size() || pos2 < res2.size())
		{
			res[tpos++] = greater1(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
		}
		if (!greater1(ans, 0, res, 0))ans = res;
	}
	return ans;
}