#include"Header.h"
#include<iostream>
#include <list>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

/************************类声明************************/
class Graph
{
	int V;             // 顶点个数
	list<int> *adj;    // 邻接表
	queue<int> q;      // 维护一个入度为0的顶点的集合
	vector<int> indegree;     // 记录每个顶点的入度
public:
	Graph(int V);                   // 构造函数
	~Graph();                       // 析构函数
	void addEdge(int v, int w);     // 添加边
	bool topological_sort();        // 拓扑排序
};

/************************类定义************************/
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	indegree.resize(V, 0);
}

Graph::~Graph()
{
	delete[] adj;
	//delete[] indegree;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	++indegree[w];
}

bool Graph::topological_sort()
{
	rep(i, V)if (indegree[i] == 0)q.push(i);
	int count = 0;             // 计数，记录当前已经输出的顶点数 
	while (!q.empty())
	{
		int v = q.front();      // 从队列中取出一个顶点
		q.pop();

		cout << v << " ";      // 输出该顶点
		++count;
		// 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
		for (auto beg=adj[v].begin(); beg != adj[v].end(); ++beg)
			if (!(--indegree[*beg]))
				q.push(*beg);   // 若入度为0，则入栈
	}

	return count < V;
}