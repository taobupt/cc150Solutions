#include"Header.h"
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int nodenum, edgenum, startnode;// nodes number,edges numeber,start node;
vector<vector<int>>cost(MAXN,vector<int>(MAXN,INF));
vector<int>lowcost(MAXN, 0);
void printPath(int root)
{
	while (root!=pre[root])
	{
		printf("%d--->", root);
		root = pre[root];
	}
	if (root == pre[root])printf("%d\n", root);

}
void Dijkstra(int n, int beg)
{
	for (int i =1; i <=n; ++i)
	{
		lowcost[i] = INF; vis[i] = false; pre[i] =i;
	}
	lowcost[beg] = 0;
	for (int j = 1; j <=n; ++j)
	{
		int k = -1;
		int Min =INF;
		for (int i =1; i <=n; ++i)
		{
			if (!vis[i] && lowcost[i] < Min)
			{
				Min = lowcost[i];
				k = i;
			}
		}
		if (k == -1)break;
		vis[k] = true;
		for (int i =1; i <=n; ++i)
		{
			if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i])
			{
				lowcost[i]= lowcost[k] + cost[k][i];
				pre[i] = k;
			}
		}
	}
}
void solve()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &nodenum, &edgenum, &startnode);
	while (edgenum-- > 0)
	{
		int src, des, value;
		scanf("%d%d%d", &src, &des, &value);
		cost[src][des] = value;
	}
	Dijkstra(nodenum, startnode);
	for (int i = 1; i <= nodenum; ++i)
	{
		if (i != startnode)
		{
			printf("%d\n", lowcost[i]);
			printf("Path:");
			printPath(i);
		}
	}
}

//test data
//7 12 1
//1 2 2
//3 1 4
//1 4 1
//2 4 3
//2 5 10
//4 3 2
//4 5 2
//3 6 5
//4 6 8
//4 7 4
//7 6 1
//5 7 6