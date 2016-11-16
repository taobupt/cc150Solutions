#include"Header.h"
string getHint(string secret, string guess) {
	int n = secret.size(),bulls=0,cows=0;
	int cnt1[10] = { 0 };
	int cnt2[10] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		if (secret[i] == guess[i])bulls++;
		else
		{
			cnt1[secret[i] - '0']++;
			cnt2[guess[i] - '0']++;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		cows += min(cnt1[i], cnt2[i]);
	}
	string res = (bulls>0 ? to_string(bulls) + "A" : "" )+ (cows > 0 ? to_string(cows) + "B" : "0");
	return res;
}