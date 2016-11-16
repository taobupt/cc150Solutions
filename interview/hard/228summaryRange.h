#include"Header.h"
vector<string> summaryRanges(vector<int>& nums) {
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string>res;
		if (nums.empty())return res;
		//	nums.push_back(nums[0]);
		int i = 1, n = nums.size(), start = nums[0];

		while (i < n)
		{
			if (nums[i] != nums[i - 1] + 1)
			{
				if (start == nums[i - 1])res.push_back(to_string(start));
				else res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
				start = nums[i];
			}
			i++;
		}
		if (start == nums[i - 1])res.push_back(to_string(start));////////donot forget this
		else res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
		return res;
	}
}