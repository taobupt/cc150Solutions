#include"Header.h"
int calculate(string s) {
	int i = 0, n = s.size(), res = 0, sign = 1;
	stack<int>stk;
	while (i < n)
	{
		res = 0;
		while (isspace(s[i]))i++;
		while (isdigit(s[i]))
		{
			res = 10 * res + s[i++] - '0';
			if (i == n || !isdigit(s[i]))
			{
				stk.push(sign*res);
				break;
			}
		}
		if (s[i] == '+')
		{
			sign = 1;
		}
		else if (s[i] == '-')sign = -1;
		else if (s[i] == '*')
		{
			i++;
			int cur = 0;
			while (isspace(s[i]))i++;
			while (isdigit(s[i]))
			{
				cur = 10 * cur + s[i++] - '0';
				if (i == n || !isdigit(s[i]))
				{
					break;
				}
			}
			int x = cur*stk.top();
			stk.pop();
			stk.push(x);
			i--;
		}
		else if (s[i] == '/')
		{
			i++;
			int cur = 0;
			while (isspace(s[i]))i++;
			while (isdigit(s[i]))
			{
				cur = 10 * cur + s[i++] - '0';
				if (i == n || !isdigit(s[i]))
				{
					break;
				}
			}
			int x = stk.top()/cur;
			stk.pop();
			stk.push(x);
			i--;
		}
		i++;
	}
	int sum = 0;
	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}
	return sum;
}