#include"Header.h"
int shortestDistance(vector<string>& words, string word1, string word2) {
	int index1 = -1, index2 = -1, n = words.size(),dist=INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (words[i] == word1)index1 = i;
		else if (words[i] == word2)index2 = i;
		if (index1 != -1 && index2 != -1)
		{
			dist = min(dist, abs(index1 - index2));
		}
	}
	return dist;
}

int shortestDistance(vector<string>& words, string word1, string word2) {
	int shortest = INT_MAX, n = words.size();
	vector<int>index1;
	vector<int>index2;
	for (int i = 0; i<n; ++i)
	{
		if (words[i] == word1)index1.push_back(i);
		if (words[i] == word2)index2.push_back(i);
	}
	for (int i = 0; i<index1.size(); ++i)
	{
		for (int j = 0; j<index2.size(); ++j)
		{
			if (index1[i] != index2[j])
			{
				shortest = min(shortest, abs(index1[i] - index2[j]));
				if (shortest == 1)return 1;
			}
		}
	}
	return shortest;
}