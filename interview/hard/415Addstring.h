#include"Header.h"
string addStrings(string num1, string num2) {
	int n = num1.size(), m = num2.size();
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int i = 0, j = 0, extra = 0;
	string res;
	while (i<n || j<m || extra)
	{
		int sum = ((i<n ? num1[i++] : '0') - '0') + ((j<m ? num2[j++] : '0') - '0') + extra;
		res = char((sum % 10) + '0') + res;
		extra = sum / 10;

	}
	return res;
}