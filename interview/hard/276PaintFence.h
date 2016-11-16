#include"Header.h"
int numWays(int n, int k)
{
	if (n == 0 || k == 0 || (k == 1 && n > 2))return 0;
	int same = 0, diff = k, total = k;
	for (int i = 2; i <= n; ++i)
	{
		same = diff, diff = (k - 1)*total;
		total = same + diff;
	}
	return total;
}