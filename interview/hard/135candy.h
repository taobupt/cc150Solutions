#include"Header.h"
int candy(vector<int>& ratings) {
	int n = ratings.size();
	vector<int>res(n, 1);
	for (int i = 1; i < n; ++i)
	{
		if (ratings[i]>ratings[i - 1])res[i] = res[i - 1] + 1;
	}
	for (int j = n - 2; j >= 0; --j)
	{
		if (ratings[j] > ratings[j + 1] && res[j] < res[j+1] + 1)res[j] = res[j + 1] + 1;
	}
	int sum = accumulate(res.begin(), res.end(), 0);
	return sum;
}
