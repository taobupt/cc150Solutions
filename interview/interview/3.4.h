#include"Header.h"

void move(char begin, char to, int n)
{
	printf("move %d disk from %c to %c \n", n, begin, to);
}

void Hanoi(int n, char from, char by, char to)
{
	if (n == 1)move(from, to, 1);
	else
	{
		Hanoi(n - 1, from,to,by);
		move(from, to, 1);
		Hanoi(n - 1, by, from, to);
	}
}


void towerOfHanoi(stack<int>& a, stack<int>& buff, stack<int>& dest, int n)
{
	if (n == 0)return;
	towerOfHanoi(a, dest, buff, n - 1);
	dest.push(a.top());
	a.pop();
	towerOfHanoi(buff, a, dest, n - 1);
}