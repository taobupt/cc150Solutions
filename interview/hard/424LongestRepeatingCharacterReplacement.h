#include"Header.h"
int characterReplacement(string s, int k) {
	int n = s.size(), start = 0, d = 0, end = 0, MaxCharcounter = 0, result = 0;
	int mp[128] = { 0 };
	while (end<n)
	{
		MaxCharcounter = max(MaxCharcounter, ++mp[s[end++]]);
		while (end - start - MaxCharcounter>k)// this is the most important
		{
			mp[s[start++]]--;
			for (int i = 65; i <= 90; ++i)
			{
				MaxCharcounter = max(MaxCharcounter, mp[i]);
			}
		}
		result = max(result, end - start);
	}
	return result;
}