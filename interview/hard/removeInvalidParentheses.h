#include"Header.h"

bool isValid(string s)
{
	int cnt = 0;
	for (char c : s)
	{
		if (c == '(')cnt++;
		else if (c == ')')
		{
			if (cnt == 0)return false;
			cnt--;
		}
	}
	return cnt == 0;
}
vector<string> removeInvalidParentheses(string s) {
	vector<string>res;
	if (s.empty())return res;
	queue<string>q;
	unordered_map<string, bool>mp;
	q.push(s);
	bool found = false;
	string cur;
	mp[s] = true;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (isValid(cur))
		{
			found = true;
			res.push_back(cur);
		}
		else if (!found)
		{
			for (int i = 0; i < cur.size(); ++i)
			{
				if (cur[i] == ')' || cur[i] == '(')
				{
					string sub = cur.substr(0, i) + cur.substr(i + 1);
					if (!mp[sub])
					{
						q.push(sub);
						mp[sub] = true;
					}
				}
			}
		}
	}
	return res;
}