#include"Header.h"


//wrong sequence would result wa


//two queue has no priority ,the equal

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if(q.empty())
		{
			while (q1.size() > 1)
			{
				q.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
		else
		{
			while (q.size() > 1)
			{
				q1.push(q.front());
				q.pop();
			}
			q.pop();
		}
	}

	// Get the top element.
	int top() {
		if (q.empty())
		{
			while (q1.size() > 1)
			{
				q.push(q1.front());
				q1.pop();
			}
			int top=q1.front();
			q.push(top);
			q1.pop();
			return top;
		}
		else
		{
			while (q.size() > 1)
			{
				q1.push(q.front());
				q.pop();
			}
			int top=q.front();
			q1.push(top);
			q.pop();
			return top;
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty() && q1.empty();
	}
private:
	queue<int>q;
	queue<int>q1;
};