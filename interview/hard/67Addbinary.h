#include"Header.h"
string addBinary(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string res;
	int m = a.size(), n = b.size();
	int extra = 0, i = 0, j = 0;
	while (i < m || j < n || extra)
	{
		int sum1 = (i < m ? a[i] : '0') - '0' + ((j < n ? b[j] : '0') - '0') + extra;
		res=char(sum1 % 2 + '0')+res;
		extra = sum1 >= 2 ? 1 : 0;
		if (i < m)i++;
		if (j < n)j++;
	}
	//reverse(res.begin(), res.end());
	return res;
}