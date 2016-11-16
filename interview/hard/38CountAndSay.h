#include"Header.h"
string countAndSay(int n) {
	if (n < 1)return "";
	if (n == 1)return "1";
	if (n == 2)return "11";
	string res="11";
	for (int i = 3; i <= n; ++i)
	{
		string ans;
		int count =1, m = res.size();
		for (int j = 1; j < m; ++j)
		{
			if (res[j] != res[j - 1])
			{
				//ans.resize(ans.size() + count, res[j - 1]);
				ans += to_string(count);
				ans.push_back(res[j - 1]);
				count = 1;
			}
			else count++;
		}
		ans += to_string(count);
		ans.push_back(res[m - 1]);
		res = ans;
	}
	return res;
}