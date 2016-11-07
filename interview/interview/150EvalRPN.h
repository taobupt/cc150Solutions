#include"Header.h"
int evalRPN(vector<string>& tokens) {
	int n = tokens.size();
	stack<int>stk;
	int a = 0, b = 0;
	for (string str : tokens)
	{
		if (str == "+")
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(a + b);
		}
		else if (str == "-")
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(b - a);
		}
		else if (str == "*")
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(b*a);
		}
		else if (str == "/")
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(b / a);
		}
		else stk.push(stoi(str));
	}
	return stk.empty() ? 0 : stk.top();
}