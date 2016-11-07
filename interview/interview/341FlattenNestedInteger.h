#include"Header.h"
// at first glance, this can be solved by vector;
// stack


class NestedInteger{
public:
	int getInteger();
	bool isInteger();
	vector<NestedInteger> &getList() const;
};
class NestedIterator{
	stack<NestedInteger>stk;
	NestedIterator(vector<NestedInteger>& nestedList)
	{
		for (int i = nestedList.size() - 1; i >= 0; --i)stk.push(nestedList[i]);
	}
	int next()
	{
		int val = stk.top().getInteger();
		stk.pop();
		return val;
	}

	bool hasNext()
	{
		while (!stk.empty())
		{
			NestedInteger curr = stk.top();
			if (curr.isInteger())return true;
			stk.pop();
			vector<NestedInteger>res = curr.getList();
			for (int i = res.size() - 1; i >= 0; --i)
			{
				stk.push(res[i]);
			}
		}
		return false;
	}
};