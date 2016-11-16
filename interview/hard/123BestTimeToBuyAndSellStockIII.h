#include"Header.h"
int maxProfit(vector<int>& prices) {
	int n = prices.size(), minValue = INT_MAX, maxValue = INT_MIN, res = 0;
	if (n<2)return 0;
	vector<int>first(n + 1, 0);
	vector<int>second(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		minValue = min(minValue, prices[i - 1]);
		first[i] = max(first[i - 1], prices[i - 1] - minValue);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		maxValue = max(maxValue, prices[i]);
		second[i] = max(second[i + 1], maxValue - prices[i]);
		res = max(res, first[i] + second[i]);
	}
	return res;
}

int maxProfit(vector<int>& prices)
{
	int n = prices.size(), minValue = INT_MAX, maxValue = INT_MIN, res = 0;
	if (n < 2)return 0;
	vector<int>first(n + 1, 0);
	vector<int>second(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		minValue = min(minValue, prices[i - 1]);
		first[i] = max(first[i - 1], prices[i - 1] - minValue);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		maxValue = max(maxValue, prices[i]);
		second[i] = max(second[i + 1], maxValue - prices[i]);
		res = max(res, first[i] + second[i]);
	}
	return res;
}