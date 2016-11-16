//#include"Header.h"
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<functional>
#include<fstream>
#include<limits>
#include<cctype>
#include<set>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<numeric>
#include<cstdint>
#include<assert.h>
using namespace std;
#define MAXN 100005
vector<int>G[MAXN];
int dfn[MAXN], low[MAXN], num[MAXN], Belong[MAXN];// num every scc contains how many of nodes, Belong: index belong to which scc. dfn: the discover time
int scc,times;//scc: the number of scc. 
int Instack[MAXN];//whether it is in stack
stack<int>stk;
set<int>vertex;
void tarjan(int u)
{
	dfn[u] = low[u] = ++times;
	Instack[u] = 1;
	stk.push(u);
	int v;
	int len = G[u].size();
	for (int i = 0; i < len; i++)
	{
		 v = G[u][i];
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		if (Instack[v] == 1)
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		scc++;
		do
		{
			v = stk.top();
			stk.pop();
			Belong[v] = scc;
			printf("%d ", v);
			num[scc]++;
			Instack[v] = 0;
		} while (v != u);
		printf("\n");
	}
}

void slove()
{
	freopen("input.txt", "r", stdin);
	int src = 0, des = 0;
	while (scanf("%d%d", &src, &des) == 2)
	{
		G[src].push_back(des);
		vertex.insert(src);
		vertex.insert(des);
	}
	memset(dfn, 0, sizeof(dfn));
	for (int x : vertex)
	{
		if (!dfn[x])tarjan(x);
	}
}
