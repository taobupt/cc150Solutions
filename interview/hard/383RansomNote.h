#include"Header.h"
bool canConstruct(string ransomNote, string magazine) {
	int cnt[128] = { 0 };
	if (ransomNote.size() > magazine.size())return false;
	int n = magazine.size(),m=ransomNote.size();
	for (int i = 0; i < n; ++i)
	{
		if (i < m)cnt[ransomNote[i]]--;
		cnt[magazine[i]]++;
	}
	for (int i = 0; i < 128; ++i)
	{
		if (cnt[i] < 0)return false;
	}
	return true;
}