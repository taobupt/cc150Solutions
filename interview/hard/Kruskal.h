#include"Header.h"
const int maxz = 1000;
struct Edge{
	int st, ed, len;
}edge[maxz];

#define rep(i,n) for(int i=0;i<n;++i)

const int mx = 100000 + 1;
int n;
int father[mx];
int rnk[mx];

void makeSet()
{
	rep(i, n)father[i] = i, rnk[i] = 0;
}

int find(int x)// iterative compress path
{
	int root = x;
	while (root != father[root])root = father[root];
	int tmp = x;
	while (tmp !=root)
	{
		int tmpFather = father[tmp];
		father[tmp] = root;
		tmp = tmpFather;
	}
	return root;

}

int unionSet(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y)return 0;
	if (rnk[x] > rnk[y])father[y] = x;
	else father[x] = y, rnk[y] += rnk[x] == rnk[y];
	return 1;
}




bool cmp(const Edge& a, const Edge &b){ return a.len < b.len; }

void Krusal()
{
	int nodeNum, edgeNum;
	scanf("%d%d", &nodeNum, &edgeNum);
	for (int i = 0; i < edgeNum; ++i)
	{
		int st, ed, len;
		scanf("%d%d%d", &st, &ed, &len);
		edge[i].st = st, edge[i].ed = ed, edge[i].len = len;
	}
	sort(edge, edge + edgeNum, cmp);
	n = nodeNum;
	makeSet();
	int weight = 0;
	for (int i = 0; i < edgeNum; ++i)
	{
		if (unionSet(edge[i].st, edge[i].ed) == 1)weight += edge[i].len;
	}
	printf("the min spanning tree: %d\n", weight);
}