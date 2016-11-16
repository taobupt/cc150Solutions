#include"Header.h"
int longestPalindrome(string s) {
	unordered_map<char, int>mp;
	for (char c : s)mp[c]++;
	int count = 0;
	int flag = -1;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->second % 2 == 1)flag = 1;
		if (it->second >= 2)count += it->second / 2;
	}
	count *= 2;
	if (flag == 1)count += 1;
	return count;
}