#include"Header.h"


int dfs(vector<vector<int>>& dis, vector<vector<int>>& matrix, int i, int j, int dx[], int dy[])
{
	if (dis[i][j])return dis[i][j];
	for (int k = 0; k < 4; ++k)
	{
		int nx = i + dx[k], ny = j + dy[k];
		if (nx >= 0 && nx < (int)matrix.size() && ny >= 0 && ny < (int)matrix[0].size() && matrix[i][j] < matrix[nx][ny])
		{
			dis[i][j] = max(dis[i][j], dfs(dis, matrix, nx, ny, dx, dy)+1);
		}
	}
	dis[i][j]=max(dis[i][j],1);
	return dis[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	if (matrix.empty() || matrix[0].empty())return 0;
	int m = matrix.size(), n = matrix[0].size();
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	vector<vector<int>>dis(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dfs(dis, matrix, i, j, dx, dy);
		}
	}
	int res = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)res = max(res, dis[i][j]);
	}
	return res;
}

