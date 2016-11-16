#include"Header.h"
vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
	queue<vector<string>>q;
	vector<vector<string>>res;
	vector<string>curPath;
	q.push({ beginWord });
	wordList.insert(beginWord);
	wordList.insert(endWord);
	unordered_map<string, vector<string>>edge;
	int n = beginWord.size(), size = 0;
	for (auto cur : wordList)
	{
		for (int j = 0; j < n; ++j)
		{
			string xx = cur;
			for (char c = cur[j] + 1; c <= 'z'; ++c)
			{
				xx[j] = c;
				if (wordList.find(xx) != wordList.end())
				{
					edge[cur].push_back(xx);
					edge[xx].push_back(cur);
				}
			}
		}
	}
	string cur;
	unordered_map<string, bool>mp;
	mp[beginWord] = true;
	vector<string>allow_word;
	bool flag = true;
	while (flag &!q.empty())
	{
		allow_word.clear();
		int size = q.size();
		while (size--)
		{
			curPath = q.front();
			q.pop();
			cur = curPath.back();
			for (auto it : edge[cur])
			{
				if (it == endWord)
				{
					curPath.push_back(it);
					res.push_back(curPath);// why it is unnecessary to curpath.pop_back? when you get next anwert, currpath is different
					flag = false;
				}
				else if (!mp[it])
				{
					curPath.push_back(it);
					allow_word.push_back(it);
					q.push(curPath);
					curPath.pop_back();// delete this would cause wrong answer. 
				}
			}
		}
		for (auto ele : allow_word)mp[ele] = true;
	}
	return res;
}