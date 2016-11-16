#include"Header.h"
#include<iostream>
#include <list>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

/************************������************************/
class Graph
{
	int V;             // �������
	list<int> *adj;    // �ڽӱ�
	queue<int> q;      // ά��һ�����Ϊ0�Ķ���ļ���
	vector<int> indegree;     // ��¼ÿ����������
public:
	Graph(int V);                   // ���캯��
	~Graph();                       // ��������
	void addEdge(int v, int w);     // ��ӱ�
	bool topological_sort();        // ��������
};

/************************�ඨ��************************/
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
	int count = 0;             // ��������¼��ǰ�Ѿ�����Ķ����� 
	while (!q.empty())
	{
		int v = q.front();      // �Ӷ�����ȡ��һ������
		q.pop();

		cout << v << " ";      // ����ö���
		++count;
		// ������vָ��Ķ������ȼ�1��������ȼ�Ϊ0�Ķ�����ջ
		for (auto beg=adj[v].begin(); beg != adj[v].end(); ++beg)
			if (!(--indegree[*beg]))
				q.push(*beg);   // �����Ϊ0������ջ
	}

	return count < V;
}