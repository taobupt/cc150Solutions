#include"Header.h"
vector<int> getRow(int row) {
	if (row == 0)return{ 1 };
	if (row == 1)return{ 1,1 };
	vector<int>pre{ 1, 1 };
	vector<int>res;
	for (int i = 2; i <= row; ++i)
	{
		res.push_back(1);
		for (int j = 1; j < pre.size(); ++j)
		{
			res.push_back(pre[j] + pre[j - 1]);
		}
		res.push_back(1);
		pre = res;
		res.clear();
	}
	return pre;

}