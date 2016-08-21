#include"Header.h"

//clockwise
void rotate(vector<vector<int>>&matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)return;
	int m = matrix.size(), n = matrix[0].size();
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}


//anticlockwise rotate
void anti_rotate(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)return;
	int m = matrix.size(), n = matrix[0].size();
	for (auto v : matrix)reverse(v.begin(), v.end());
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}