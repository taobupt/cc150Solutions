#include"Header.h"

// array is much faster than unordered_map
int firstUniqChar(string s) {
	int n = s.size();
	int cnt[128] = {};
	for (int i = 0; i < n; ++i)
	{
		cnt[s[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (cnt[s[i]] == 1)return i;
	}
	return -1;
}