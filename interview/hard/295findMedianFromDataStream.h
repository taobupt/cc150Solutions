#include"Header.h"
priority_queue<int, vector<int>, greater<int>>q1;//small
priority_queue<int, vector<int>, less<int>>q2;
void addNum(int num)
{
	if (q1.empty())
	{
		q1.push(num);
		return;
	}
	if (num > q1.top())q1.push(num);
	else q2.push(num);
	while (q1.size() < q2.size())
	{
		q1.push(q2.top());
		q2.pop();
	}
	while (q1.size() > q2.size() + 1)
	{
		q2.push(q1.top());
		q1.pop();
	}
}

double findMedian()
{
	return q1.size() == q2.size() ? (q1.top() + q2.top()) / 2.0 : q1.top();
}