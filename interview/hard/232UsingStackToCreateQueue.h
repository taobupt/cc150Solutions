#include"Header.h"
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!s1.empty())s1.pop();
		else
		{
			while (!s.empty())
			{
				s1.push(s.top());
				s.pop();
			}
			s1.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if (!s1.empty())return s1.top();
		else
		{
			while (!s.empty())
			{
				s1.push(s.top());
				s.pop();
			}
			return s1.top();
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s1.empty() && s.empty();
	}
private:
	stack<int>s;
	stack<int>s1;
};