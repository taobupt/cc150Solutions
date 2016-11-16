#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string>
#include<string.h>
#include <algorithm>
using namespace std;
#define BUFFSIZE 25
#define N 1005
#include<unordered_map>

int slove() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	char buffer[N][BUFFSIZE];
	unordered_map<char*, int>mp;
	int T = 0, q = 0;
	scanf("%d", &T);
	int i = 0;
	while (i<T)
	{
		fgets(buffer[i++], BUFFSIZE, stdin);
	}
	for (int i = 0; i<1005; ++i)
	{
		if (buffer[i] == NULL || strlen(buffer[i])<1)break;
		mp[buffer[i]]++;
	}
	scanf("%d", &q);
	while (q--)
	{
		char s[BUFFSIZE];
		fgets(s, BUFFSIZE, stdin);
		printf("%d\n", mp[s]);
	}

	return 0;
}