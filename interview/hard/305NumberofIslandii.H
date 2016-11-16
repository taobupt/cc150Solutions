#include"Header.h"


int findIsland(int* roots, int id)
{
	while (id != roots[id])
	{
		roots[id] = roots[roots[id]];
		id = roots[id];
	}
	return id;
}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
	vector<int>res;
	if (m <= 0 || n <= 0)return res;
	int count = 0;
	int* roots = new int[m*n];
	memset(roots, -1, sizeof(roots));
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	for (auto it : positions)
	{
		int root = it.first*n + it.second;
		roots[root] = root;
		count++;
		for (int k = 0; k < 4; ++k)
		{
			int nx = it.first + dx[k];
			int ny = it.second + dy[k];
			int nb = nx*n + ny;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || roots[nb] == -1)continue;
			int rootNb = findIsland(roots, nb);
			if (root != rootNb)
			{
				roots[root] = rootNb;
				root = rootNb;
				count--;
			}
		}
		res.push_back(count);
		
	}
	return res;
}