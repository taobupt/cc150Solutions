#include"Header.h"
struct Interval{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};

vector<Interval>merge(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start != b.start ? a.start < b.start : a.end < b.end; });
	int n = intervals.size();
	vector<Interval>res;
	if (n == 0)return res;
	res.push_back(intervals[0]);
	for (int i = 1; i < n; ++i)
	{
		if (res.back().end < intervals[i].start)res.push_back(intervals[i]);
		else res.back().end = max(res.back().end, intervals[i].end);
	}
	return res;
}