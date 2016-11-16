#include"Header.h"
int minCut(string s) {
	int n = s.size();
	if (n == 0)return 0;
	vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));
	vector<int>min(n + 1, -1);
	for (int i = 0; i < n; ++i)
	{
		isPalindrome[i][i] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		min[i + 1] = min[i] + 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (s[j] == s[i])
			{
				if (j == i - 1 || isPalindrome[j + 1][i - 1])
				{
					isPalindrome[j][i] = true;
					if (j == 0)min[i + 1] = 0;
					else if (min[i + 1] > min[j] + 1)min[i + 1] = min[j] + 1;
				}
			}
		}
	}
	return min[n];
}


int mincut(string s)
{
	int n = s.size();
	if (n == 0)return 0;
	vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));
	vector<int>min(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		isPalindrome[i][i] = true;
	}
	for (int i = 1; i < n; ++i)
	{
		min[i + 1] = min[i] + 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (s[j] == s[i])
			{
				if (j == i - 1 || isPalindrome[j + 1][i - 1])
				{
					isPalindrome[j][i] = true;
					if (j == 0)min[i + 1] = 0;
					else if (min[i + 1] > min[j] + 1)min[i + 1] = min[j]+1;
				}
			}
		}
	}
	return min[n];
}