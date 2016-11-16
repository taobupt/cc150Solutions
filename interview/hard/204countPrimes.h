#include"Header.h"
int countPrimes(int n) {
	if (n < 2)return 0;
	n -= 1;
	vector<int>prime(n + 1, 0);
	for (int i = 2; i <=n; ++i)
	{
		if (!prime[i])prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && prime[j] <= n / i; ++j)
		{
			prime[i*prime[j]] = 1;
			if (i%prime[j] == 0)break;
		}
	}
	return prime[0];
}