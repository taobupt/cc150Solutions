#include"Header.h"

class NestedInteger {
	public:
		     // Return true if this NestedInteger holds a single integer, rather than a nested list.
			     bool isInteger() const;
		
			    // Return the single integer that this NestedInteger holds, if it holds a single integer
			     // The result is undefined if this NestedInteger holds a nested list
			     int getInteger() const;
		
			     // Return the nested list that this NestedInteger holds, if it holds a nested list
			     // The result is undefined if this NestedInteger holds a single integer
			     const vector<NestedInteger> &getList() const;

};
void dfs(NestedInteger it, int level, int &res)
{
	if (it.isInteger())res += level*it.getInteger();
	else
	{
		vector<NestedInteger>kk = it.getList();
		for (int i = 0; i<kk.size(); ++i)
		{
			dfs(kk[i], level + 1, res);
		}
	}
}
int depthSum(vector<NestedInteger>& nestedList) {
	int res = 0, level = 1, n = nestedList.size();
	for (int i = 0; i<n; ++i)
	{
		dfs(nestedList[i], level, res);
	}
	return res;
}


class Solution {
private:
	int DFS(vector<NestedInteger>& nestedList, int depth){
		int n = (int)nestedList.size();
		int sum = 0;
		for (int i = 0; i<n; i++){
			if (nestedList[i].isInteger()){
				sum += nestedList[i].getInteger()*depth;
			}
			else{
				sum += DFS(nestedList[i].getList(), depth + 1);
			}
		}
		return sum;
	}
public:
	int depthSum(vector<NestedInteger>& nestedList) {
		return DFS(nestedList, 1);
	}
};