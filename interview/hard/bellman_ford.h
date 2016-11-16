#include"Header.h"
const int INF = 0x3f3f3f3f;
const int MAXN = 550;
int dist[MAXN];
int parent[MAXN];// print path
int nodenum, edgenum, startnode;// nodes number,edges numeber,start node;


// ACM ICPC TAMU tarining
struct Edge{
	int src;
	int des;
	int cost;
	Edge(int src = 0,int des = 0,int  cost = 0) :src(src), des(des), cost(cost){}
};




vector<Edge>E;
bool bellman_ford(int start, int n)
{
	for (int i = 1; i <= n; ++i)dist[i] = INF;
	dist[start] = 0;
	for (int i = 1; i < n; ++i)
	{
		bool flag = false;
		for (int j = 0; j < E.size(); ++j)
		{
			int src = E[j].src;
			int des = E[j].des;
			int cost = E[j].cost;
			if (dist[des]>dist[src] + cost)
			{
				dist[des] = dist[src] + cost;
				parent[des] = src;
				flag = true;
			}
		}
		if (!flag)return true;//no negative cycle
	}
	for (int j = 0; j < E.size(); ++j)
	{
		if (dist[E[j].des] > dist[E[j].src] + E[j].cost)return false;//has negative;
	}
	return true;
}

void printPath(int root)
{
	while (root != parent[root])
	{
		printf("%d--->", root);
		root = parent[root];
	}
	if (root == parent[root])printf("%d\n", root);
}

void solveBellman()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &nodenum, &edgenum, &startnode);
	vector<int>items(nodenum+1, 0);
	int item,i=1;
	while (i <= nodenum){ scanf("%d", &item); items[i] = item; }
	parent[startnode] = startnode;
	while (edgenum-- > 0)
	{
		int src, des, cost;
		scanf("%d%d%d", &src, &des, &cost);
		E.push_back(Edge(src, des, cost));
	}
	if (bellman_ford(startnode, nodenum))
	{
		for (int i = 1; i <= nodenum; ++i)
		{
			printf("%d\n", dist[nodenum]);
			printf("Path");
			printPath(nodenum);
		}
	}
}








//#include"Header.h"
//const int INF = 0x3f3f3f3f;
//const int MAXN = 550;
//int nodenum, edgenum, startnode;// nodes number,edges numeber,start node;
//
//
//// ACM ICPC TAMU tarining
//struct node
//{
//	int distance;
//	int id;
//	int item;
//	node(int id = 0, int item = 0, int number = MAXN) :id(id), distance(number), item(item){}
//}dist[MAXN];
//struct Edge{
//	node src;
//	node des;
//	int cost;
//	Edge(node src, node des, int  cost = 0) :src(src), des(des), cost(cost){}
//};
//
//
//
//
//vector<Edge>E;
//bool bellman_ford(int start, int n,vector<int>& items)
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		dist[i].distance = INF;
//		dist[i].item = items[i];
//		dist[i].id = i;
//	}
//	dist[start].distance = 0;
//	for (int i = 1; i < n; ++i)
//	{
//		bool flag = false;
//		for (int j = 0; j < E.size(); ++j)
//		{
//			int src = E[j].src.id;
//			int des = E[j].des.id;
//			int item1 = dist[src].item;
//			int item2 = dist[des].item;
//			int cost = E[j].cost;
//			if ((dist[des].distance>dist[src].distance + cost) || ((dist[des].distance==dist[src].distance + cost) && item2<item1+items[E[j].des.id]))
//			{
//				dist[des].distance = dist[src].distance + cost;
//				dist[des].item = item1 + items[E[j].des.id];
//				flag = true;
//			}
//		}
//		if (!flag)return true;//no negative cycle
//	}
//	for (int j = 0; j < E.size(); ++j)
//	{
//		if (dist[E[j].des.id].distance > dist[E[j].src.id].distance + E[j].cost)return false;//has negative;
//	}
//	return true;
//}
//
//
//void solveBellman()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	scanf("%d%d%d", &nodenum, &edgenum, &startnode);
//	vector<int>items(nodenum + 1, 0);
//	int item, i = 1;
//	while (i <= nodenum){ scanf("%d", &item); items[i++] = item; }
//	//parent[startnode] = startnode;
//	while (edgenum-- > 0)
//	{
//		int src, des, cost;
//		scanf("%d%d%d", &src, &des, &cost);
//		E.push_back(Edge(node(src,items[src]), node(des,items[src]), cost));
//	}
//	if (bellman_ford(startnode, nodenum,items))
//	{
//		//for (int i = 1; i <= nodenum; ++i)
//		//{
//		if (dist[nodenum].distance == INF)printf("impossible");
//		else printf("%d  %d\n", dist[nodenum].distance,dist[nodenum].item);
//		//printf("Path");
//		//printPath(nodenum);
//		//}
//	}
//	else printf("impossible");
//}