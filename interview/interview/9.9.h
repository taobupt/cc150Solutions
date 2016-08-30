#include"Header.h"
#include"struct.h"

inline bool check(int* places, int cur)
{
	for (int j = 0; j < cur; ++j)
	{
		if (places[cur] == places[j] || abs(places[cur] - places[j]) == cur - j)return false;
	}
	return true;
}

void solve52(int cur,int n,int* places,int &cnt)
{
	if (cur == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		places[cur] = i;
		if (check(places, cur))solve52(cur + 1, n, places, cnt);
	}
}

int totalNQueens(int n)
{
	int ans = 0;
	int* places = new int[n];
	solve52(0, n, places, ans);
	delete[]places;
	return ans;
}


//leetcode 51 Nqueen
//@taobupt

void solve51(int cur, int n, int* places, vector<vector<string>>& ans)
{
	if (cur == n)
	{
		string x = "";
		vector<string>res;
		for (int i = 0; i < n; ++i)
		{
			x.clear();
			for (int j = 0; j < n; ++j)
			{
				x.push_back(j == places[i] ? 'Q' : '.');
			}
			res.push_back(x);
		}
		ans.push_back(res);
		return;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			places[cur] = i;
			if (check(places, cur))solve51(cur + 1, n, places, ans);
		}
	}
}

vector<vector<string>> sloveNQueens(int n)
{
	vector<vector<string>>ans;
	int* places = new int[n];
	solve51(0, n, places, ans);
	delete[] places;
	return ans;
}

