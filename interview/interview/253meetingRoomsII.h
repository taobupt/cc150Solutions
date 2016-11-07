#include"Header.h"


struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0){}
	Interval(int start, int end) : start(start), end(end){}
};


struct cmp{
	bool operator()(Interval a, Interval b)
	{
		return a.end > b.end;
	}
};
int minMeetingRooms(vector<Interval>& intervals) {
	if (intervals.empty())return 0;
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start; });
	priority_queue<Interval, vector<Interval>, cmp>pq;
	pq.push(intervals[0]);
	for (int i = 1; i < intervals.size(); ++i)
	{
		Interval it = pq.top();
		pq.pop();
		if (it.end <= intervals[i].start)
		{
			it.end = intervals[i].end;
		}
		else
		{
			pq.push(intervals[i]);
		}
		pq.push(it);
	}
	return pq.size();
}