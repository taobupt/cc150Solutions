#include"Header.h"
char findTheDifference(string s, string t) {
	int cnt[128] = { 0 };
	int n = t.size(), m = n - 1;
	for (int i = 0; i < n; ++i)
	{
		if (i < m)cnt[s[i]]--;
		cnt[t[i]]++;
	}
	int i = 0;
	for (; i < n; ++i)
	{
		if (cnt[t[i]] == 1)break;
	}
	return  t[i];
}

//xor is ok too

char findTheDifference1(string s, string t) {
	int ans = 0, n = s.size();
	for (int i = 0; i<n; ++i)
	{
		ans ^= (s[i] - 'a');
		ans ^= (t[i] - 'a');
	}
	ans ^= (t[n] - 'a');
	return char(ans + 'a');
}