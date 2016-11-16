#include"Header.h"
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	if (beginWord == endWord)return 1;
	int ans = 2, n = beginWord.size();
	queue<string>q;
	q.push(beginWord);
	string res;
	unordered_map<string, bool>mp;
	mp[beginWord] = true;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			res = q.front();
			q.pop();
			for (int i = 0; i < n; ++i)
			{
				char letter = res[i];
				for (char c = 'a'; c <= 'z'; ++c)
				{
					res[i] = c;
					if (res == endWord)
					{
						return ans;
					}
					if (wordList.find(res) != wordList.end() && !mp[res])
					{
						q.push(res);
						mp[res] = true;
					}
				}
				res[i] = letter;
			}
		}
		ans++;
	}
	return 0;
}

int ladderLength1(string beginWord, string endWord, unordered_set<string>& wordList) {
	if (beginWord == endWord)return 1;
	int ans = 2;
	int n = beginWord.size();
	unordered_map<string, bool>vis;
	queue<string>q;
	q.push(beginWord);
	vis[beginWord] = true;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			string str = q.front();
			q.pop();
			for (int i = 0; i<n; ++i)
			{
				char letter = str[i];
				for (char c = 'a'; c <= 'z'; ++c)
				{
					str[i] = c;
					if (str == endWord)return ans;
					else if (!vis[str] && wordList.find(str) != wordList.end())
					{
						q.push(str);
						vis[str] = true;
					}
				}
				str[i] = letter;
			}
		}
		ans++;
	}
	return 0;
}