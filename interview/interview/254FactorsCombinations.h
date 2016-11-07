#include"Header.h"
void backtracking(vector<vector<int>>& res, vector<int>& path, vector<int> factors, int cur, int n)
{
	if (cur>factors.size() || n<1)return;
	if (n == 1)
	{
		res.push_back(path);
		return;
	}
	for (int i = cur; i<factors.size(); ++i)
	{
		if (n >= factors[i] && n%factors[i] == 0)
		{
			path.push_back(factors[i]);
			backtracking(res, path, factors, i, n / factors[i]);
			path.pop_back();
		}
	}
}
vector<vector<int>> getFactors(int n) {
	vector<vector<int>>res;
	if (n <= 3)return res;
	vector<int>path;
	set<int>factors;
	int mid = (int)sqrt(n) + 1;
	for (int i = 2; i <= mid; ++i)
	{
		if (n%i == 0)
		{
			factors.insert(i);
			factors.insert(n / i);
		}
	}
	if (factors.empty())return res;
	vector<int>factor(factors.begin(), factors.end());
	sort(factor.begin(), factor.end());
	backtracking(res, path, factor, 0, n);
	return res;
}