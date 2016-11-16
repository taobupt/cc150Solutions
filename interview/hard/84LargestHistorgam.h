#include"Header.h"
int largestRectangleArea(vector<int>& heights) {
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

