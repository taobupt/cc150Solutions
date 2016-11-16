#include"Header.h"
bool containsDuplicate(vector<int>& nums) {
	unordered_map<int, int>mp;
	for (int x : nums)
	{
		if (mp[x]++ == 1)return true;
	}
	return false;
}