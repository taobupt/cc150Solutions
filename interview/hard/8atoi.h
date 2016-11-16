#include"Header.h"
int myAtoi(string str) {
	int n = str.size(), i = 0;
	long long res = 0;
	int sign = 1;
	while (i<n && isspace(str[i]))i++;
	if (i < n && (str[i] == '+' || str[i] == '-'))
	{
		sign = str[i++] == '+' ? 1 : -1;
	}
	while (i<n && isdigit(str[i]))
	{
		res = 10 * res + (str[i++] - '0');
		if (res > INT_MAX)break;
	}
	res = sign*res;
	if (res > INT_MAX)return INT_MAX;
	else if (res < INT_MIN)return INT_MIN;
	return res;
}