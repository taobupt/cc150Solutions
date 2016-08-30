#include"Header.h"
#include"struct.h"

int findMagicIndex(vector<int>& num)
{
	int start = 0, end = num.size() - 1, mid = 0;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (num[mid] == mid)return mid;
		if (num[mid] > mid)end = mid;
		else start = mid + 1;
	}
	return -1;
}