#include"Header.h"
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size(), res = 0, remaing = 0,start=0;
	for (int i = 0; i < n; ++i)
	{
		res += gas[i] - cost[i];
		remaing += gas[i] - cost[i];
		if (remaing < 0)
		{
			remaing = 0;
			start = i + 1;
		}
	}
	return res >= 0 ? start : -1;
}