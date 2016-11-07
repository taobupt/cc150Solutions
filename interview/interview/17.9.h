#include"Header.h"
#include"struct.h"

unordered_map<string,int>getFrequency(vector<string>s)
{
	unordered_map<string, int>mp;
	for (string x : s)
	{
		mp[x]++;
	}
	for (unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
	return mp;
}