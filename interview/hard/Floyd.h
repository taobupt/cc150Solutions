#include"Header.h"
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
int nodenum, edgenum;// nodes number,edges numeber,start node;
vector<vector<int>>weight(MAXN, vector<int>(MAXN, INF));// weight[i][j]
vector<vector<int>>path(MAXN, vector<int>(MAXN, -1));//path[i][j]=k shows that i,j's parent is k

void floyd()
{
	for (int k = 1; k <= nodenum; ++k)
	{
		for (int i = 1; i <= nodenum; ++i)
		{
			for (int j = 1; j <= nodenum; ++j)
			{
				if (weight[i][k] > 0 && weight[k][j] > 0 && weight[i][k] < INF && weight[k][j] < INF && (weight[i][k] + weight[k][j] < weight[i][j]))
				{
					weight[i][j] = weight[i][k] + weight[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

void printPath(int src, int des)
{
	while (src != des)
	{
		printf("%d--->", des);
		des = path[src][des];
	}
	if (des == src)printf("%d\n", src);
}
void slove()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &nodenum, &edgenum);
	for (int i = 1; i <= edgenum; ++i)
	{
		int src, des, value;
		scanf("%d%d%d", &src, &des, &value);
		weight[src][des] = value;
		weight[src][src] = 0;
		weight[des][des] = 0;
		path[src][des] = src;
		path[src][src] = src;
		path[des][des] = des;
	}
	floyd();
	printPath(1, 3);
}