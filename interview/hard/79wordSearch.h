#include"Header.h"

bool dfs(vector<vector<char>>& board, string word, int cur, int dx[], int dy[], vector<vector<bool>>& vis,int i,int j)
{
	if (cur == word.size())
	{
		return true;
	}
	else if (cur > word.size())return false;
	for (int k = 0; k < 4; ++k)
	{
		int nx = i + dx[k], ny = j + dy[k];
		if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || vis[nx][ny] || board[nx][ny] != word[cur])continue;
		vis[nx][ny] = true;
		if (dfs(board, word, cur+1, dx, dy, vis, nx, ny))return true;
		vis[nx][ny] = false;
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty()||word.empty())return false;
	int m = board.size(), n = board[0].size();
	vector<vector<bool>>vis(m, vector<bool>(n, false));
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] == word[0] && !vis[i][j])
			{
				vis[i][j] = true;
				if (dfs(board,word,1,dx,dy,vis,i,j))return true;
				vis[i][j] = false;
			}
		}
	}
	return false;
}