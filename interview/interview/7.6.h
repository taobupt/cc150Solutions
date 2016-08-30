#include"Header.h"
#include"struct.h"



/*
@taobupt

1. some other point is the same as pointA
2.Some other point has the same x cordinates as pointA, which will result to a postive infinite slope
3. general case
*/
int maxPoints(vector<Point>& points)
{
	int result = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		int samePoints = 1;
		unordered_map<double, int>mp;
		for (int j = i + 1; j < points.size(); ++j)
		{
			if (points[i].x == points[j].x && points[i].y == points[j].y)
			{
				samePoints++;
			}
			else if (points[i].x == points[j].x)
			{
				mp[INT_MAX]++;
			}
			else
			{
				double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
				mp[slope]++;
			}
		}
		int localMax = 0;
		for (auto it = mp.begin(); it != mp.end(); ++it)
		{
			localMax = max(localMax, it->second);
		}
		localMax += samePoints;
		result = max(result, localMax);
	}
	return result;
}