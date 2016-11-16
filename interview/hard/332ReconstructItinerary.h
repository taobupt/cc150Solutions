#include"Header.h"

bool dfs(const string& cur, vector<string>& ans, const int& n, unordered_map<string, map<string, int>>& m)
{
	if (ans.size() == n)return true;
	for (auto ticket = m[cur].begin(); ticket != m[cur].end(); ++ticket)
	{
		if (ticket->second != 0)
		{
			ticket->second--;
			ans.push_back(ticket->first);
			if (dfs(ticket->first, ans, n, m))return true;
			ans.pop_back();
			ticket->second++;
		}
	}
	return false;
}

//void dfs(const string& cur, vector<string>& ans, const int& n, unordered_map<string, map<string, int>>& m, vector<string>& path)
//{
//	if (ans.size() == n)
//	{
//		if (path.empty())path = ans;
//		return;
//	}
//	if (!path.empty())return;
//	for (auto ticket = m[cur].begin(); ticket != m[cur].end(); ++ticket)
//	{
//		if (ticket->second != 0)
//		{
//			ticket->second--;
//			ans.push_back(ticket->first);
//			dfs(ticket->first, ans, n, m,path);//)return true;
//			ans.pop_back();
//			ticket->second++;
//		}
//	}
//	//return false;
//}
vector<string> findItinerary(vector<pair<string, string>> tickets)
{
	unordered_map<string, map<string, int>>m;
	for (const auto &p : tickets)
	{
		m[p.first][p.second]++;
	}
	string start = "JFK";
	vector<string>ans;
	ans.push_back(start);
	//vector<string>path;
	//dfs(start, ans, tickets.size() + 1, m,path);
	//return path;
	dfs(start, ans, tickets.size() + 1, m);
	return ans;
}
