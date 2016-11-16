#include"Header.h"
bool isPalindrome(string s) {
	string res;
	for (char c : s)
	{
		if (isalnum(c))res.push_back(tolower(c));
	}
	string reversestr = res;
	reverse(res.begin(), res.end());
	return res == reversestr;
}