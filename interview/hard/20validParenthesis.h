#include"Header.h"
bool isValid(string s)
{
	stack<char>stk;
	//int n = s.size();
	for (char c : s)
	{
		switch (c)
		{
		case '{': case '[': case '(' :
			stk.push(c);
			break;
		case '}':
			if (stk.empty() || stk.top() != '{')return false; else stk.pop(); break;
		case ')':
			if (stk.empty() || stk.top() != '(')return false; else stk.pop(); break;
		case ']':
			if (stk.empty() || stk.top() != '{')return false; else stk.pop(); break;
		}
	}
	return stk.empty();
}