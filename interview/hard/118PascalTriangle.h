#include"Header.h"
vector<vector<int>> generate(int num) {
	vector<vector<int>>res;
	if (num < 1)return res;
	res.push_back({ 1 });
	if (num < 2)return res;
	res.push_back({ 1, 1 });
	vector<int>inner;
	for (int i = 2; i < num; ++i)
	{
		inner.push_back(1);
		for (int j = 1; j <=i - 1; ++j)
		{
			inner.push_back(res[i - 1][j - 1] + res[i - 1][j]);
		}
		inner.push_back(1);
		res.push_back(inner);
		inner.clear();
	}
	return res;
}