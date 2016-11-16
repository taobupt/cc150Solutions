#include"Header.h"
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stk.push(x);
		if (minstack.empty() || minstack.top() >x)minstack.push(x);
		else minstack.push(minstack.top());
	}

	void pop() {
		stk.pop();
		minstack.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minstack.top();
	}
private:
	stack<int>stk;
	stack<int>minstack;
};
