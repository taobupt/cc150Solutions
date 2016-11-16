#include"Header.h"
int maxProduct(vector<string>& words) {
	vector<int>flag;
	int fla = 0, res = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		fla = 0;
		for (int j = 0; j < words[i].size(); ++j)
		{
			fla |= 1 << (words[i][j] - 'a');
		}
		flag.push_back(fla);
	}
	for (int i = 0; i < flag.size(); ++i)
	{
		for (int j = i + 1; j < flag.size(); ++j)
		{
			if ((flag[i] && flag[j]) == 0)res = max(res, int(words[i].size()*words[j].size()));
		}
	}
	return res;
}