#include"Header.h"
int maxProfit(vector<int>& prices) {
	int minValue = INT_MAX, maxProfit = 0;//INT_MIN is wrong
	for (int x : prices)
	{
		minValue = min(minValue, x);
		maxProfit = max(maxProfit, x - minValue);
	}
	return maxProfit;
}