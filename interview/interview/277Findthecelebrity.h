#include"Header.h"
bool knows(int a, int b);
int findCelebrity(int n)
{
	int c = 0;
	for (int i = 1; i < n; ++i)
	{
		if (knows(c, i))c = i;
	}
	for (int i = 0; i < n; ++i)
	{
		if ((i != c) && knows(c, i) || !knows(i, c))return -1;
	}
	return c;
}

//
//bad solution
int findCelebrity(int n)
{
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		for (; j < n; ++j)
		{
			if (i != j && (knows(i, j) || !knows(j, i)))break;
		}
		if (j == n)return i;
	}
	return -1;
}



int findCelebrity(int n)
{
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		for (; j < n; ++j)
		{
			if (i != j && (knows(i, j) || !knows(j, i)))break;
		}
		if (j == n)return true;
	}
	return -1;
}