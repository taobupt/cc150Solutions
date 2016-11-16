#include"Header.h"
class ZigzagIterator{
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2)
	{
		if (!v1.empty())q.push(make_pair(v1.begin(), v1.end()));
		if (!v2.empty())q.push(make_pair(v2.begin(), v2.end()));
	}
	int next()
	{
		vector<int>::iterator it = q.front().first;
		vector<int>::iterator end = q.front().second;
		q.pop();
		if (it + 1 != end)q.push(make_pair(it + 1, end));
		return *it;
	}
	bool hasNext()
	{
		return !q.empty();
	}
private:
	queue < pair < vector<int>::iterator, vector<int>::iterator> >q ;
};


struct cmp{
	bool operator()(pair<vector<int>::iterator, vector<int>::iterator> it1, pair<vector<int>::iterator, vector<int>::iterator> it2)
	{
		return *(it1.first) > *(it2.first);
	}
};

int kthsmallest(vector<vector<int>>res,int k)
{
	priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, cmp>pq;
	for (int i = 0; i < res.size();++i)if (!res[i].empty())pq.push(make_pair(res[i].begin(), res[i].end()));
	int count = 0,ans=0;
	while (!pq.empty())
	{
		vector<int>::iterator it = pq.top().first;
		vector<int>::iterator end = pq.top().second;
		pq.pop();
		count++;
		ans = (*it);
		if (count == k)return ans;
		if (it + 1 != end)pq.push(make_pair(it + 1, end));
	}
	return 0;
}