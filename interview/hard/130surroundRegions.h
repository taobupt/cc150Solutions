#include"Header.h"
void solve(vector<vector<char>>& board) {
	if (board.empty() || board[0].empty())return;
	int m = board.size(), n = board[0].size();
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	//unordered_map
	vector<vector<bool>>vis(m, vector<bool> (n, false));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == 'O' &&!vis[i][j])
			{
				queue<pair<int, int>>q1;
				queue < pair<int, int>>q2;
				int flag = true;
				q1.push(make_pair(i, j));
				q2.push(make_pair(i, j));
				vis[i][j] = true;
				while (!q1.empty())
				{
					int  curx = q1.front().first, cury = q1.front().second;
					q1.pop();
					for (int k = 0; k < 4; ++k)
					{
						int nx = curx + dx[k], ny = cury + dy[k];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n)
						{
							flag = false;
							continue;
						}
						if (vis[nx][ny] || board[nx][ny] == 'X')continue;
						vis[nx][ny] = true;
						q1.push(make_pair(nx, ny));
						q2.push(make_pair(nx, ny));
					}
				}
				if (flag)
				{
					while (!q2.empty())
					{
						int xx = q2.front().first, yy = q2.front().second;
						board[xx][yy] = 'X';
						q2.pop();
					}
				}
			}
		}
	}
}