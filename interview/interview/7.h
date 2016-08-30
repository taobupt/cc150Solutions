#include"Header.h"
#include"struct.h"

bool isPrime(int n)
{
	if (n < 2)return false;
	int mid = int(sqrt(n));
	for (int i = 2; i <= mid; ++i)
	{
		if (n%i == 0)return false;
	}
	return true;
}

const int maxn = 1000010;
bool notprime[maxn];
void init()
{
	memset(notprime, false, sizeof(notprime));
	notprime[0] = notprime[1] = true;
	for (int i = 2; i < maxn; ++i)
	{
		if (!notprime[i])
		{
			if (i>maxn / i)continue;
			for (int j = i*i; j < maxn; j += i)
			{
				notprime[j] = true;
			}
		}
	}
}


