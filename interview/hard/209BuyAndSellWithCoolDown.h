#include"Header.h"
int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)return 0;
	int len = prices.size();
	vector<int>sell(len);
	vector<int>buy(len);
	sell[0] = 0;
	buy[0] = 0;
	for (int i = 1; i < len; ++i)
	{
		sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		buy[i] = max(buy[i - 1], (i>=2?sell[i - 2]:0) - prices[i]);
	}
	return sell[len - 1];
}