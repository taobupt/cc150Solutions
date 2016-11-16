#include"Header.h"
string fractionToDecimal(int numerator, int denominator) {
	int flag = (numerator > 0) ^ (denominator > 0);
	long long numera = llabs((long long)numerator);
	long long denom = llabs((long long)denominator);
	long long res = numera / denom;
	long long rmd = numera%denom;
	if (rmd == 0)return to_string(flag == 0 ? res : -res);
	string ans = to_string(flag == 0 ? res : -res) + ".";
	unordered_map<long long, int>mp;
	rmd = 10 * rmd;
	while (rmd)
	{
		long long quotient = rmd / denom;
		if (mp.find(rmd) != mp.end())
		{
			ans.insert(mp[rmd], 1, '(');
			res += ')';
			break;
		}
		mp[rmd] = ans.size();
		ans += to_string(quotient);
		rmd = (rmd%denom)%10;
	}
	return ans;
}