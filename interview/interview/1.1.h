#include"Header.h"
bool isunique(string s)
{
	unordered_map<char, int>mp;
	for (auto it : s)
	{
		if (mp[it]++ == 1)return false;
	}
	return true;
}