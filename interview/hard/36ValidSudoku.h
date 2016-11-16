#include"Header.h"

bool isvalid(vector<char>& v)
{
	unordered_map<char, int>mp;
	for (char c : v)
	{
		if (c != '.' && mp[c]++ == 1)return false;
	}
	return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
	for (int i = 0; i < 9; ++i)
	{
		if (!isvalid(board[i]))return false;
	}
	vector<char>tmp;
	for (int j = 0; j < 9; ++j)
	{
		tmp.clear();
		for (int i = 0; i < 9; ++i)
		{
			tmp.push_back(board[i][j]);
		}
		if (!isvalid(tmp))return false;
	}
	for (int i = 0; i < 9; i+=3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			tmp.clear();
			for (int m = i; m < i + 3; ++m)
			{
				for (int n = j; n < j + 3; ++n)
				{
					tmp.push_back(board[m][n]);
				}
			}
			if (!isvalid(tmp))return false;
		}
	}
	return true;
}