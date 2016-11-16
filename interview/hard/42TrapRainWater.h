#include"Header.h"
int trap(vector<int>& height)
{
	int n = height.size(), left = 0, right = n - 1,res=0;
	if (n < 2)return 0;
	int leftMaxHeight = height[0], rightMaxHeight = height[n - 1];
	while (left < right)
	{
		if (height[left] < height[right])
		{
			leftMaxHeight = max(leftMaxHeight, height[left]);
			res +=leftMaxHeight - height[left++];
		}
		else
		{
			rightMaxHeight = max(rightMaxHeight, height[right]);
			res += max(rightMaxHeight - height[right--], 0);
		}
	}
	return res;
}


int trap(vector<int>& height)
{
	int n = height.size(), left = 0, right = n - 1, res = 0;
	if (n < 2)return 0;
	int leftMaxHeight = height[0], rightMaxHeight = height[n - 1];
	while (left < right)
	{
		if (height[left] < height[right])
		{
			leftMaxHeight = max(leftMaxHeight, height[left]);
			res += leftMaxHeight - height[left++];
		}
		else
		{
			rightMaxHeight = max(rightMaxHeight, height[right]);
			res += max(rightMaxHeight - height[right--], 0);
		}
	}
	return res;
}




int trap(vector<int>& height)
{
	int n = height.size();
	vector<int>left(n, 0);
	vector<int>right(n, 0);
	for (int i = 1, j = n - 2; i < n; ++i,--j)
	{
		left[i] = max(left[i - 1], height[i - 1]);
		right[j] = max(right[j + 1], height[j + 1]);
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		int minValue = min(left[i], right[i]);
		if (minValue>height[i])res += minValue - height[i];
	}
	return res;
}


// trap

int trap(vector<int>& height)
{
	int n = height.size();
	vector<int>left(n, 0);
	vector<int>right(n, 0);
	for (int i = 1, j = n - 2; i < n; ++i, --j)
	{
		left[i] = max(left[i - 1], height[i - 1]);
		right[j] = max(right[j + 1], height[j + 1]);
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		int minValue = min(left[i], right[i]);
		if (minValue>height[i])res += minValue - height[i];
	}
	return res;
}