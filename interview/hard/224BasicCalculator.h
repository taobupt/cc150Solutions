#include"Header.h"
int calculate(string s) {
	int n = s.size(), sign = 1, res = 0,i=0;
	stack<int>stk;
	while (i < n)
	{
		int cur = 0;
		while (isspace(s[i]))i++;
		while(isdigit(s[i]))
		{
			cur = 10 * res + s[i++] - '0';
			if (i == n || !isdigit(s[i]))
			{
				res += cur*sign;
				break;
			}
		}
		if (s[i] == '+')sign = 1;
		else if (s[i] == '-')sign = -1;
		else if (s[i] == '(')
		{
			stk.push(res);
			res = 0;
			stk.push(sign);
			sign = 1;
		}
		else if (s[i] == ')')
		{
			res *= stk.top();
			stk.pop();
			res += stk.top();
			stk.pop();
			sign = 1;
		}
		i++;
	}
	return res;

}

int calculate(string s)
{
	int n = s.size(), sign = 1, res = 0, i = 0;
	stack<int>stk;
	while (i < n)
	{
		int cur = 0;
		while (isspace(s[i]))i++;
		while (isdigit(s[i]))
		{
			cur = 10 * cur + s[i++] - '0';
			if (i == n || !isdigit(s[i]))
			{
				res += cur*sign;
				break;
			}
		}
		if (s[i] == '+')sign = 1;
		else if (s[i] == '-')sign = -1;
		else if (s[i] == '(')
		{
			stk.push(res);
			res = 0;
			stk.push(sign);
			sign = 1;
		}
		else if (s[i] == ')')
		{
			res *= stk.top();
			stk.pop();
			res += stk.top();
			stk.pop();
			sign = 1;
		}
		i++;
	}
	return res;
}