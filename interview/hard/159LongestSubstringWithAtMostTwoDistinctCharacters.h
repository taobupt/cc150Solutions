-#include"Header.h"
int lengthOfLongestSubstringTwoDistinct(string s) {
	int m[128] = { 0 };
	int counter = 0, begin = 0, end = 0, d = 0, n = s.size();
	while (end<n)
	{
		if (++m[s[end++]] == 1)counter++;
		while (counter>2)
		{
			if (--m[s[begin++]] == 0)counter--;
		}
		d = max(d, end - begin);
	}
	return d;
}