#include"Header.h"
string largestNumber(vector<int>& nums) {
	// should push string to the vector and then sort, which would be faster
	// pay attention to the index, you should return the frist not '0'
	sort(nums.begin(), nums.end(), [](int a, int b){return (to_string(a) + to_string(b)) >( to_string(b) + to_string(a)); });
	string res;
	for (int x : nums)res += to_string(x);
	return res;
}