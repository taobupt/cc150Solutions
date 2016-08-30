#include"Header.h"
#include"struct.h"

int nthUglyNumber(int n) {
	vector<int>dp(n + 1, 1);
	int a = 1, b = 1, c = 1,back=1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = min(min(dp[a] * 3, dp[b] * 5), dp[c] * 7);
		if (dp[i] >= dp[a] * 3)a++;
		if (dp[i] >= dp[b] * 5)b++;
		if (dp[i] >= dp[c] * 7)c++;
	}
	return dp[n];
}

int min3(int a, int b, int c)
{
	return a<b ? a<c ? a : c : b<c ? b : c;
}
int nthUglyNumberII(int n) {

	int a = 1, b = 1, c = 1;
	int last = n;
	vector<int>v(n + 1, 1);
	int begin = 1;
	while (--n>0)
	{

		v[++begin] = min3(v[a] * 3, v[b] * 5, v[c] * 7);
		if (v[begin] >= v[a] * 3)a++;
		if (v[begin] >= v[b] * 5)b++;
		if (v[begin] >= v[c] * 7)c++;
	}
	return v[last];
}