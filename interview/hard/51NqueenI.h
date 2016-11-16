#include"Header.h"
bool check(int* places, int k)
{
	for (int i = 0; i < k; ++i)
	{
		if (places[i] == places[k] || abs(places[i] - places[k]) == k - i)return false;
	}
	return true;
}

void dfs(int* places, vector<vector<string>>&res, int cur, int n)
{
	if (cur == n)
	{
		vector<string>ans;
		string x;
		for (int i = 0; i < n; ++i)
		{
			x.clear();
			for (int j = 0; j < n; ++j)
			{
				x.push_back(places[i] == j ? 'Q' : '.');
			}
			ans.push_back(x);
		}
		res.push_back(ans);
		return;
	}
	else if (cur > n)return;
	for (int i = 0; i < n; ++i)
	{
		places[cur] = i;
		if (check(places, cur))dfs(places, res, cur + 1, n);
	}
}

vector<vector<string>> solveNQueens(int n) {
	int* places = new int[n];
	vector<vector<string>>res;
	dfs(places, res, 0, n);
	//delete[]places;
	return res;
}