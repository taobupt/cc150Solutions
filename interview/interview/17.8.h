#include"Header.h"
#include"struct.h"

int maxSubArray(vector<int>& nums)
{
	int ans = INT_MIN;
	int sum1 = 0;
	for (int x : nums)
	{
		if (sum1 >= 0)
		{
			sum1 += x;
		}
		else
		{
			sum1 = x;
		}
		ans = max(ans, sum1);
	}
	return ans;
}