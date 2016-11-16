#include"Header.h"
int lengthOfLastWord(string s)
{
	stringstream ss(s);
	string tmp,res;
	while (getline(ss, tmp, ' '))
	{
		if (tmp != "" && tmp != " ")res = tmp;
	}
	return res.size();
}

//
int legnthOfLastWord1(string s)
{
	int len = 0, tail = s.size() - 1;
	while (tail >= 0 && s[tail] == ' ')--tail;
	while (tail >= 0 && s[tail] != ' ')
	{
		tail--;
		len++;
	}
	return len;
}
