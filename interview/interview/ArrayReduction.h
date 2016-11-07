#include"Header.h"
int reaductionCost(vector<int>& nums)
{
	if (nums.empty())return -1;
	priority_queue<int, vector<int>, greater<int>>pq;
	int total = 0;
	for (int x : nums)pq.push(x);
	while (pq.size() > 1)
	{
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();
		total += (num1 + num2);
		pq.push(total);
	}
	return total;
}