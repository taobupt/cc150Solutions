#include"Header.h"
vector<int> findOrder(int num, vector<pair<int, int>>& prerequisites) {
	queue<int>q;//store these vertex whose indgree is zero
	list<int>* adj = new list<int>[num];
	vector<int>indgree(num, 0);
	for (int i = 0; i < (int)prerequisites.size(); ++i)
	{
		adj[prerequisites[i].second].push_back(prerequisites[i].first);
		++indgree[prerequisites[i].first];
	}
	for (int i = 0; i < num; ++i)if (indgree[i] == 0)q.push(i);
	int cnt = 0, node = 0;
	vector<int>res;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		cnt++;
		res.push_back(node);
		for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
		{
			if (--indgree[*it] == 0)q.push(*it);
		}
	}
	return res;
}