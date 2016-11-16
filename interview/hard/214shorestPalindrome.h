#include"Header.h"

string shorestPalindrome(string s)
{
	string s2 = s;
	reverse(s2.begin(), s2.end());
	string ss = s + "#" + s2;
	int n = ss.size();
	vector<int>next(n, 0);
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		while (k>0 && ss[i] != ss[k])k = next[k - 1];
		if (ss[i] == ss[k])k++;
		next[i] = k;
	}
	int m = s.size() - next[n - 1];
	string res = s2.substr(0, m) + s;
	return res;
}

string shortestPalindrome(string s)
{
	string s2 = s;
	reverse(s2.begin(), s2.end());
	string ss = s + "#" + s2;
	int n = ss.size();
	vector<int>next(n, 0);
	int k = 0;
	for (int i = 1; i < n; ++i)
	{
		while (k>0 && ss[i] != ss[k])k = next[k - 1];
		if (ss[i] == ss[k])k++;
		next[i] = k;
	}
	int m = s.size() - next[n - 1];
	string res = s2.substr(0, m) + s;
	return res;
}

//
string shoretstPalindrome(string s)
{
	string s2 = s;
	reverse(s2.begin(), s2.end());
	string ss = s + '#' + s2;
	int n = ss.size();
	vector<int> next(n, 0);
	int k = 0;
	for (int i = 1; i < n; i++) {
		while (k > 0 && ss[i] != ss[k])
			k = next[k - 1];
		if (ss[i] == ss[k])
			k++;
		next[i] = k;
	}
	int m = s.size() - next[n - 1];
	string res = s2.substr(0, m) + s;
	return res;
}

