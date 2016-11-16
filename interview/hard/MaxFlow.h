#include"Header.h"

#define MAXN 201
const int INF = 0x7fffffff;
int capacity[MAXN][MAXN]; //��¼�������������
int pre[MAXN];                 //���������·���ϵ�ǰ�ڵ��ǰ��,ͬʱ��Ǹýڵ��Ƿ��ڶ�����
int nodenum, edgenum;
bool EK_BFS(int start,int end)
{
	bool flag[MAXN] = { false };
	memset(pre, -1, sizeof(pre));
	flag[start] = true;
	queue<int>q;
	q.push(start);
	while (!q.empty())
	{
		int top = q.front();
		if (top == end)return true;//find the augmenting path
		q.pop();
		for (int i = 1; i <= nodenum; ++i)
		{
			if (capacity[top][i] && !flag[i])
			{
				flag[i] = true;
				q.push(i);
				pre[i] = top;
			}
		}
	}
	return false;
}

int E_K()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int u, maxflow = 0, mn;
	scanf("%d%d", &nodenum, &edgenum);
	memset(capacity, 0, sizeof(capacity));
	for (int i = 1; i <= edgenum; ++i)
	{
		int start, end, value;
		scanf("%d%d%d", &start, &end, &value);
		if (start == end)continue;
		capacity[start][end] += value;
	}
	while (EK_BFS(1, nodenum))// start end
	{
		mn = 100000;
		u = nodenum;
		while (pre[u] != -1)
		{
			mn = min(mn, capacity[pre[u]][u]);
			u = pre[u];
		}
		maxflow+=mn;
		u = nodenum;
		while (pre[u] != -1)
		{
			capacity[pre[u]][u] -= mn;
			capacity[u][pre[u]] += mn;
			u = pre[u];
		}
	}
	printf("maxflow:%d", maxflow);
	return maxflow;
}

//test data
//6 9
//1 2 16
//2 3 12
//3 4 20
//5 4 4
//5 3 7
//6 5 14
//3 6 9
//6 2 4
//1 6 13