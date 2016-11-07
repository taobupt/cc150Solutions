#include"Header.h"
bool isNumber(string s)
{
	int i = 0;
	while (isspace(s[i]))i++;//skip the whitespace;
	if (s[i] == '+' || s[i] == '-')i++;//skip the sign if exist
	int n_nm, n_pt;// number of points and number of 
	for (n_nm, n_pt = 0; isdigit(s[i]) || s[i] == '.'; ++i)
	{
		s[i] == '.' ? n_pt++ : n_nm++;
	}
	if (n_pt > 1 || n_nm < 1)return false;
	if (s[i] == 'e')
	{
		i++;
		if (s[i] == '+' || s[i] == '-')i++;//skip the sign
		int n_nm = 0;
		for (; isdigit(s[i]); i++, n_nm++){}
		if (n_nm < 1)return false;
	}
	while (isspace(s[i]))i++;
	return s[i] == 0;// must reach the eding 0 of the string;
}