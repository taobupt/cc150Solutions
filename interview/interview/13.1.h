#include"Header.h"
#include"struct.h"

void printKlines(int k)
{
	vector<string>res;
	string s = "";
	while (getline(cin, s))
	{
		res.push_back(s);
	}
	int n = res.size();
	for (int i = n - k; i < n; ++i)
	{
		cout << res[i] << endl;
	}
}
