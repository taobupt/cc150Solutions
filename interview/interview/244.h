#include"Header.h"
class WordDistance {
public:

	WordDistance(vector<string>& words) {
		for (int i = 0; i<words.size(); ++i)mp[words[i]].push_back(i);
	}

	int shortest(string word1, string word2) {
		int m = mp[word1].size(), n = mp[word2].size();
		int i = 0, j = 0, dist = INT_MAX;
		while (i<m && j<n)
		{
			dist = min(dist, abs(mp[word1][i] - mp[word2][j]));
			mp[word1][i]<mp[word2][j] ? i++: j++;
		}
		return dist;
	}
private:
	unordered_map<string, vector<int>>mp;
};