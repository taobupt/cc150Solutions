#include"Header.h"
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.empty())return 0;
	int m = triangle.size();
	for (int i = m - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}