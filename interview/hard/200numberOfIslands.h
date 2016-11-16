#include"Header.h"


void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int dx[], int dy[], int x, int y)
{
	for (int k = 0; k < 4; ++k)
	{
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || vis[nx][ny]||grid[nx][ny]=='0')continue;
		vis[nx][ny] = true;
		dfs(grid, vis, dx, dy, nx, ny);
	}
}
int numIslands(vector<vector<char>>& grid) {
	if (grid.empty() || grid[0].empty())return 0;
	int m = grid.size(), n = grid[0].size();
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	vector<vector<bool>>vis(m, vector<bool>(n, false));
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == '1' && !vis[i][j])
			{
				vis[i][j] = true;
				dfs(grid,vis,dx,dy,i,j);
					ans++;
			}

		}
	}
	return ans;
}