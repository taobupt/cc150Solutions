#include"Header.h"
class NumArray {
public:
	NumArray(vector<int> &nums) {
		int n = nums.size();
		sum = nums;
		num = nums;
		for (int i = 1; i < n; ++i)sum[i] += sum[i - 1];
	}

	int sumRange(int i, int j) {
		return sum[j] - sum[i] + num[i];
	}

private:
	vector<int>sum;
	vector<int>num;
};