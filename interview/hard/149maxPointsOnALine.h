#include"Header.h"

struct Point{
	int x;
	int y;
	Point() :x(0), y(0){}
	Point(int a, int b) :x(a), y(b){}
};



//enumerate
int maxPoints(vector<Point>& points) {
	int n = points.size(), res = 0;
	if (n <= 2)return n;
	unordered_map<double, int>mp;// slope and its count
	for (int i = 0; i < n; ++i)
	{
		int same = 1,predencular=0;
		mp.clear();
		for (int j = i + 1; j < n; ++j)
		{
			if (points[j].x == points[i].x && points[j].y == points[i].y)same++;
			else if (points[j].x == points[i].x)predencular++;
			else{
				double slope = double(points[j].y - points[i].y) / double(points[j].x - points[i].x);
				mp[slope]++;
			}
		}
		res = max(res, predencular+same);
		for (auto it = mp.begin(); it != mp.end(); ++it)res = max(res, it->second + same);
	}
	return res;
}

int maxPoints(vector<Point>& points)
{
	int n = points.size(), res = 0;
	if (n <= 2)return n;
	unordered_map<double, int>mp;
	for (int i = 0; i < n; ++i)
	{
		int same = 1, predencular = 0;
		mp.clear();
		for (int j = i + 1; j < n; ++j)
		{
			if (points[j].x == points[i].x && points[j].y == points[i].y)same++;
			else if (points[j].x == points[i].x)predencular++;
			else
			{
				double slope = double(points[j].y - points[i].y) / double(points[j].x - points[i].x);
				mp[slope]++;
			}
		}
		res = max(res, predencular + same);
		for (auto it = mp.begin(); it != mp.end(); ++it)res = max(res, it->second + same);
	}
	return res;
}