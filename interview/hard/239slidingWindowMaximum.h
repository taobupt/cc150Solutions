#include"Header.h"
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int>res;
	deque<int>q;
	int n = nums.size();
	if (n == 0 || k == 0 || n < k)return res;
	for (int i = 0; i < n; ++i)
	{
		if (!q.empty() && q.front() < i - k + 1)q.pop_front();
		while (!q.empty() && nums[q.back()] < nums[i])q.pop_back();
		q.push_back(i);
		if (i >= k - 1)res.push_back(nums[q.front()]);
	}
	return res;
}

//
vector<int>maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int>res;
	deque<int>q;
	int n = nums.size();
	if (n == 0 || k == 0 || n < k)return res;
	for (int i = 0; i < n; ++i)
	{
		if (!q.empty() && q.front() < i - k + 1)q.pop_front();
		while (!q.empty() && nums[q.back()] < nums[i])q.pop_back();
		q.push_back(i);
		if (i >= k - 1)res.push_back(nums[q.front()]);
	}
	return res;
}