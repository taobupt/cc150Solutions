#include"Header.h"


//Kahn algorithms

bool canFinish(int num, vector<pair<int, int>>& prerequisites) {
	vector<int>indegree(num, 0);
	queue<int>q;
	list<int>* adj = new list<int>[num];
	for (int i = 0; i < (int)prerequisites.size(); ++i)
	{
		adj[prerequisites[i].second].push_back(prerequisites[i].first);
		++indegree[prerequisites[i].first];
	}
	for (int i = 0; i < num; ++i)if (indegree[i] == 0)q.push(i);
	int count = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		count++;
		for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
		{
			if (--indegree[*it] == 0)q.push(*it);
		}
	}
	delete []adj;
	return count == num;
}