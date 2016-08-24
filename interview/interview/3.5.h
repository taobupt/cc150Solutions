#include"Header.h"
class myqueue{
public:
	void push(int x)
	{
		s1.push(x);
	}

	void pop()
	{
		if (!s2.empty())s2.pop();
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			s2.pop();
		}
	}

	int top()
	{
		if (!s2.empty())return s2.top();
		else
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
		
	}



	bool empty()
	{
		return s1.empty() && s2.empty();
	}


private:
	stack<int>s1;
	stack<int>s2;
};