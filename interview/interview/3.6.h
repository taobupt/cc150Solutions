#include"Header.h"
stack<int> sortStack(stack<int>s)
{
	stack<int>sorted;
	while (!s.empty())
	{
		int val = s.top();
		s.pop();
		if (sorted.empty() || sorted.top() < val)sorted.push(val);
		else
		{
			while (!sorted.empty() && sorted.top() > val)
			{
				s.push(sorted.top());
				sorted.pop();
			}
			sorted.push(val);
		}
	}
	return sorted;
}