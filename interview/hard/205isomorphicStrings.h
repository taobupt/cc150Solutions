#include"Header.h"


//two directions
bool isIsomorphic(string s, string t) {
	if (s.size() != t.size())return false;
	int n = s.size();
	unordered_map<char, char>mp;
	unordered_map<char, char>mp1;
	string ss = s;
	string tt = t;
	for (int i = 0; i < n; ++i)
	{
		auto it = mp.find(s[i]);
		auto it1 = mp1.find(tt[i]);
		if (it == mp.end())
		{
			mp[s[i]] = t[i];
			s[i] = t[i];
		}
		else if (it != mp.end())
		{
			s[i] = mp[s[i]];
		}

		if (it1 == mp1.end())
		{
			mp1[tt[i]] = ss[i];
			tt[i] = ss[i];
		}
		else if (it1 != mp1.end())
		{
			tt[i] = mp1[tt[i]];
		}
	}

	return s == t && tt == ss;
}

}