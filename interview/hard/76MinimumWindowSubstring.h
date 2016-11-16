#include"Header.h"
string minWindow(string s, string t) {
	int m[128] = { 0 };
	for (auto c : t)m[c]++;
	int start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX, n = s.size();
	while (end < n)
	{
		if (m[s[end]] > 0)counter--;
		m[s[end]]--;
		end++;
		while (counter == 0)
		{
			if (end - start < minLen)
			{
				minStart = start;
				minLen = end - start;
			}
			m[s[start]]++;
			if (m[s[start]] > 0)counter++;
			start++;
		}
	}
	return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}


//
string minWindow1(string s, string t)
{
	int m[128] = { 0 };
	for (auto c : t)m[c]++;
	int start = 0, end = 0, counter = t.size(), minstart = 0, minLen = INT_MAX, n = s.size();
	while (end < n)
	{
		if (m[s[end]] > 0)counter--;
		m[s[end]]--;
		end++;
		while (counter == 0)
		{
			if (end - start < minLen)
			{
				minstart = start;
				minLen = end - start;
			}
			m[s[start]]++;
			if (m[s[start]] > 0)counter++;
			start++;
		}
	}
	return minLen == INT_MAX ? "" : s.substr(minstart, minLen);
}

int legnthOfLongestSubstring(string s)
{
	int m[128] = { 0 };
	int counter = 0, begin = 0, end = 0, d = 0;
	while (end < s.size())
	{
		if (m[s[end++]]++ > 0)counter++;//number of repeat;
		while (counter > 0)if (m[s[begin++]]-- > 1)counter--;
		d = max(d, end - begin);
	}
	return d;
}