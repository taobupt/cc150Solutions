#include"Header.h"



// judge the cornner case
int strStr(string haystack, string needle)
{
	// you can use kmp;
	int m = haystack.size(), n = needle.size(),j=0;
	for (int i = 0; i < m - n + 1; ++i)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			int index = i;
			while (j < m && haystack[index] == needle[j])
			{
				index++;
				j++;
			}
			if (j == m)return i;
		}
	}
	return -1;
}