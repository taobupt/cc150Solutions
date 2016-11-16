#include"Header.h"


#define rep(i,n) for(int i=0;i<n;++i)
string removeDuplicateLetters(string s) {
	int cnt[26] = { 0 };
	int vis[26] = { 0 };
	int n = s.size();
	rep(i, n)cnt[s[i] - 'a']++;
	string res;
	for (int i = 0; i < n; ++i)
	{
		cnt[s[i] - 'a']--;
		if (vis[s[i] - 'a'])continue;
		while (!res.empty() && res.back() > s[i] && cnt[res.back() - 'a'])
		{
			vis[res.back() - 'a'] = 0;
			res.pop_back();
		}
		res.push_back(s[i]);
		vis[s[i] - 'a'] = 1;
	}
	return res;
}