#include"Header.h"
vector<string>findMissingRanges(vector<int>& nums, int lower1, int upper)
{
	vector<string>res;
	long long lower = (long long)lower1;
	for (int x : nums)
	{
		long long justbelow = (long long)x - 1;
		if (justbelow == lower)res.push_back(to_string(lower));
		else if (lower < justbelow)res.push_back(to_string(lower) + "->" + to_string(justbelow));
		lower = x + 1;
	}
	if (lower == upper)res.push_back(to_string(lower));
	else if (lower < upper)res.push_back(to_string(lower) + "->" + to_string(upper));
	return res;
}