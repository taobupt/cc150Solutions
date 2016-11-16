#include"Header.h"

int largestRectInHistorgram(vector<int> heights)
{
	vector<int>index;
	heights.push_back(0);
	int n = heights.size(), res = 0;
	for (int i = 0; i < n; ++i)
	{
		while (!index.empty() && heights[index.back()] >= heights[i])
		{
			int h = heights[index.back()];
			index.pop_back();
			int length = index.empty() ? -1 : index.back();
			res = max(res, h*(i - length - 1));
		}
		index.push_back(i);
	}
	return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int res = 0;
	if (matrix.empty() || matrix[0].empty())return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>>dp(m, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)dp[0][i] = (matrix[0][i] == '0' ? 0 : 1);
	res = max(res, largestRectInHistorgram(dp[0]));
	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j]=matrix[i][j] == '0' ? 0 : 1 + dp[i-1][j];
		}
		res = max(res, largestRectInHistorgram(dp[i]));
	}
	return res;
}