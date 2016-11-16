#include"Header.h"

bool isBadVersion(int mid)
{
	return false;
}
int firstBadVersion(int n) {
	int begin = 1, end = n, mid = 0;
	while (begin<end)
	{
		mid = begin + (end - begin) / 2;
		if (isBadVersion(mid))end = mid;
		else begin = mid + 1;
	}
	return begin;
}