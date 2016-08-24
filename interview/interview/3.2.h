#include"Header.h"

class Minstack{
	void push(int x)
	{
		s1.push(x);
		if (minstack.empty() || minstack.top() >= x)minstack.push(x);
		else minstack.push(minstack.top());
	}

	void pop()
	{
		s1.pop();
		minstack.pop();
	}

	int top()
	{
		return s1.top();
	}

	bool empty()
	{
		return s1.empty();
	}

	int getMin()
	{
		return minstack.top();
	}

private:
	stack<int>minstack;
	stack<int>s1;
};