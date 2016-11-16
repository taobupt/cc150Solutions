#include"Header.h"
#define MaxInt 0x3f3f3f3f
#define N 110
//创建map二维数组储存图表，low数组记录每2个点间最小权值，visited数组标记某点是否已访问
int weight[N][N], low[N], visited[N];
int n,edges;

//return the node with smallest weight and its name;


void update(int node)
{
	for (int j = 1; j <= n; ++j)
	{
		if (!visited[j] && low[j] > weight[node][j])low[j] = weight[node][j];
	}
}
int findMinNode()
{
	int minNode=0, smallestWeight =INT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i] && low[i] < smallestWeight)
		{
			minNode = i;
			smallestWeight = low[i];
		}
	}
	update(minNode);// update the low array
	visited[minNode] = 1;
	return smallestWeight;
}

int prim()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &edges);
	int src, dst,weightValue;
	memset(weight, MaxInt, sizeof(weight));
	memset(visited, 0, sizeof(visited));
	while (edges-- > 0)
	{
		scanf("%d%d%d", &src, &dst,&weightValue);
		weight[src][dst] = weightValue;
		weight[dst][src] = weightValue;
	}

	
	int dis = 0;
	int pos = 1;// pick random node;
	visited[pos] = 1;
	for (int i = 1; i <= n; i++)
		if (i !=pos) low[i] = weight[pos][i];
	for (int i =2; i <= n; ++i)
	{
		int res=findMinNode();
		dis += res == INT_MAX ? 0 : res;
		printf("%d\n", res);
	}
	return dis;
}

//test data

//9 14
//1 2 4
//2 3 8
//3 4 7
//4 5 9
//5 6 10
//6 7 2
//7 8 1
//8 9 7
//1 8 8
//9 3 2
//9 7 6
//4 6 14
//3 6 4
//2 8 11