#include"Header.h"
class NestedInteger{
public:
	bool isInteger();
	int getInteger();
	vector<NestedInteger>getList();
};

void dfs(NestedInteger &ni, int depth, vector<int>& result)
{
	if (result.size() < depth + 1)result.resize(depth + 1);
	if (ni.isInteger()){
		result[depth] += ni.getInteger();
	}
	else
	{
		for (auto it : ni.getList())
		{
			dfs(it, depth + 1, result);
		}
	}
}
int depthSumInverse(vector<NestedInteger>& nestedList)
{
	vector<int>result;
	for (auto ni : nestedList)
	{
		dfs(ni, 0, result);
	}
	int sum = 0;
	for (int i = result.size() - 1, level = 1; i >= 0; --i, level++)
	{
		sum += result[i] * level;
	}
	return sum;
}

//BFS
int depthSumInverse(vector<NestedInteger>& nestedList)
{
	if (nestedList.empty())return 0;
	queue<NestedInteger>q;
	for (NestedInteger it : nestedList)q.push(it);
	int prev = 0, total = 0;
	while (!q.empty())
	{
		int size = q.size();
		int levelSum = 0;
		while (size--)
		{
			NestedInteger cur = q.front();
			q.pop();
			if (cur.isInteger())levelSum += cur.getInteger();
			else
			{
				vector<NestedInteger>vv = cur.getList();
				for (NestedInteger it : vv)q.push(it);
			}
		}
		prev += levelSum;
		total += prev;
	}
	return total;
}