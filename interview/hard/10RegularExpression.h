#include"Header.h"
bool matchFrist(const char* s, const char* p)
{
	return (*p == *s || (*p == '.' && *s != '\0'));
}

bool isMatch(const char* s, const char* p)
{
	if (*p == '\0')return *s == '\0';
	if (*(p + 1) != '*')
	{
		if (!matchFrist(s, p))return false;
		return isMatch(s + 1, p + 1);
	}
	else
	{
		if (isMatch(s, p + 2))return true;//try the length of 0
		while (matchFrist(s, p))if (isMatch(++s, p + 2))return true;//try all the length
	}
}



// this is just recrusive way, you could do this by dynamic programming
bool isMatch(string s, string p)
{
	if (p.empty())return s.empty();
	if (p[1] == '*')return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
	else return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
}

bool isMatch(string s, string p)
{
	int m = s.size(), n = p.size();
	vector<vector<bool>>f(m + 1, vector<bool>(n + 1, false));
	f[0][0] = true;
	for (int j = 1; j <= n; ++j)f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] != '*')f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
			else f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
		}
	}
	return f[m][n];
}