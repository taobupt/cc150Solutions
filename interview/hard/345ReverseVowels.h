#include"Header.h"
string reverseVowels(string s) {
	unordered_set<char>sset { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	int n = s.size(), i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && sset.find(s[j]) == sset.end())j--;
		while (i < j && sset.find(s[i]) == sset.end())i++;
		if (i < j)swap(s[i], s[j]);
	}
	return s;
}