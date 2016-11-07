#include"Header.h"
#include<list>
bool recrusive(list<int>candidates, int target)
{
	if (candidates.back() >= target)return true;
	for (list<int>::iterator it = candidates.begin(); it != candidates.end(); ++it)
	{
		int removed = *it;
		candidates.erase(it);
		if (!recrusive(candidates, target - removed))
		{
			candidates.insert(it, removed);
			return true;
		}
		candidates.insert(it, removed);
	}
	return false;
}

bool canWin(int maxValue, int target)
{
	list<int>candidates;
	for (int i = 1; i <= maxValue; ++i)candidates.push_back(i);
	return recrusive(candidates, target);
}
