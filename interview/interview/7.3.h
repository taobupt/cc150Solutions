#include"struct.h"
#include"Header.h"
#define eps 1e-6
bool IsIntersect(Point& a, Point& b, Point& c, Point& d)
{
	double slope1 = (b.y - a.y) / (b.x - a.x);
	double slope2 = (d.y - c.y) / (d.x - c.x);
	return abs(slope1 - slope2) > eps;
}