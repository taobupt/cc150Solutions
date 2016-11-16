#include"Header.h"
class FenwickTree{
	vector<int>sum_array;
	int n;
	inline int lowbit(int x)
	{
		return x&(-x);
	}
public:
	FenwickTree(int n) :n(n), sum_array(n + 1, 0){}
	void add(int x, int val)
	{
		while (x <= n)
		{
			sum_array[x] += val;
			x += lowbit(x);
		}
	}

	int sum(int x)
	{
		int res = 0;
		while (x > 0)
		{
			res += sum_array[x];
			x -= lowbit(x);
		}
		return res;
	}
};

vector<int> countSmaller(vector<int>& nums)
{
	vector<int>tmp = nums;
	sort(tmp.begin(), tmp.end());
	unordered_map<int, int>dic;
	for (int i = 0; i < tmp.size(); ++i)dic[tmp[i]] = i + 1;
	FenwickTree tree(nums.size());
	vector<int>ans(nums.size(), 0);
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		ans[i] = tree.sum(dic[nums[i]] - 1);
		tree.add(dic[nums[i]], 1);
	}
	return ans;
}