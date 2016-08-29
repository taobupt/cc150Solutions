#include"Header.h"
#include"struct.h"

int findMissing(vector<int> num)
{
	int size = num.size();
	int ans = 0;
	for (int i = 0; i < size; ++i)
	{
		ans ^= i;
		ans ^= num[i];
	}
	return ans^size;
}

int fetchBit(int bit, int no)
{
	return (no >>= bit) & 1;
}

int findMissingUtils(vector<int>A, int n, int col)
{
	if (n < 2)return 0;
	vector<int>b0((n / 2) + 1,0), b1((n / 2) + 1,0);
	int count0 = 0, count1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (fetchBit(col, A[i]))b1[count1++] = A[i];
		else b0[count0++] = A[i];
	}
	int v;
	if (count0 <= count1)
	{
		v = findMissingUtils(b0, count0, col + 1);
		return (v <<1)|0;
	}
	else
	{
		v = findMissingUtils(b1, count1, col + 1);
		return (v << 1) | 1;
	}


}

