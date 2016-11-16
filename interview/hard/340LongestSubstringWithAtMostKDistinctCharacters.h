#include"Header.h"
int lengthOfLongestSubstringKDistinct(string s, int k) {
	int n = s.size(), d = 0, begin = 0, end = 0,counter=0;
	int mp[128] = { 0 };
	while (end < n)
	{
		if (++mp[s[end++]] == 1)counter++;
		while (counter > k)
		{
			if (--mp[s[begin++]] == 0)counter--;
		}
		d = max(d, end - begin);
	}
	return d;
}