#include"Header.h"



// has no order
vector<int> twoSum(vector<int>& numbers, int target) {
	unordered_map<int, int>mp;
	int n = numbers.size();
	for (int i = 0; i < n; ++i)
	{
		if (mp.find(target - numbers[i]) != mp.end())return{ mp[target - numbers[i]] + 1, i + 1 };
		mp[numbers[i]] = i;
	}
	return{ 0, 0 };

}


// withou hasmap is faster
vector<int> twoSum1(vector<int>& numbers, int target) {
	int n = numbers.size(), left = 0, right = n - 1;
	while (left < right)
	{
		int sum = numbers[left] + numbers[right];
		if (sum == target)return{ left + 1, right + 1 };
		else if (sum < target) left++;
		else right--;
	}
	return{ 0, 0 };

}