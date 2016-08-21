#include"Header.h"
void setZeroes(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)return;
	int m = matrix.size(), n = matrix[0].size();
	set<int>rows; set<int>cols;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	for (int row:rows)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[row][j] = 0;
		}
	}
	for (int col : cols)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[j][col] = 0;
		}
	}
}

void setZeroes1(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)return;
	int m = matrix.size(), n = matrix[0].size();
	bool flag = false;
	//set<int>rows; set<int>cols;
	for (int i = 0; i < m; ++i)
	{
		if (!matrix[i][0])flag = true;
		for (int j = 1; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}

	for (int i = m-1; i >= 0; --i)
	{
		for (int j = n-1; j >=1; --j)
		{
			if (matrix[0][j] == 0||matrix[i][0]==0)
			{
				matrix[i][j]= 0;
			}
		}
		if (flag)matrix[i][0] = 0;
	}
	
}