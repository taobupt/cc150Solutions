#include<stdio.h>  
#include<vector>  
#include<string.h>  
using namespace std;
#define Size 11111  //�ڵ����  

vector<int> node[Size], que[Size];
int n, pare[Size], anse[Size], in[Size], rak[Size];// indgree ,rank,parent,ancestor

int vis[Size];
void init()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		node[i].clear();
		que[i].clear();
		rak[i] = 1;
		pare[i] = i;///   
	}
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
	memset(anse, 0, sizeof(anse));

}

int find(int nd)//���鼯����  ������  
{
	return pare[nd] == nd ? nd : pare[nd] = find(pare[nd]);
}
int Union(int nd1, int nd2)//���鼯����  ������  
{
	int a = find(nd1);
	int b = find(nd2);
	if (a == b) return 0;
	else if (rak[a] <= rak[b])
	{
		pare[a] = b;
		rak[b] += rak[a];
	}
	else
	{
		pare[b] = a;
		rak[a] += rak[b];
	}
	return 1;

}

void LCA(int root)
{
	int i, sz;
	anse[root] = root;//�����Գ�һ������  
	sz = node[root].size();
	for (i = 0; i<sz; i++)
	{
		LCA(node[root][i]);//�ݹ�����  
		Union(root, node[root][i]);//��������root����һ��   
		anse[find(node[root][i])] = root;//�޸�����������Ҳָ��root  
	}
	vis[root] = 1;
	sz = que[root].size();
	for (i = 0; i<sz; i++)
	{
		if (vis[que[root][i]])
		{
			printf("%d\n", anse[find(que[root][i])]);///root��que[root][i]����ʾ��ֵ�������������  
			return;
		}
	}
	return;
}

int main()
{
	int cas, i;
	scanf("%d", &cas);
	while (cas--)
	{
		int s, e;
		scanf("%d", &n);
		init();
		for (i = 0; i<n - 1; i++)
		{
			scanf("%d %d", &s, &e);
			if (s != e)
			{
				node[s].push_back(e);
				// node[e].push_back(s);  
				in[e]++;
			}
		}
		scanf("%d %d", &s, &e);
		que[s].push_back(e);
		que[e].push_back(s);
		for (i = 1; i <= n; i++)  if (in[i] == 0) break;//Ѱ�Ҹ��ڵ�  
		//  printf("root=%d\n",i);  
		LCA(i);
	}
	return 0;
}