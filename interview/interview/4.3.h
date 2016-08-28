#include"struct.h"
#include"Header.h"


TreeNode* makeTrees(vector<int>& nums, int begin, int end)
{
	if (begin > end)return NULL;
	else if (begin == end)return new TreeNode(nums[begin]);
	else
	{
		int mid = (begin + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = makeTrees(nums, begin, mid - 1);
		root->right = makeTrees(nums, mid + 1, end);
		return root;
	}
}

TreeNode* constructTrees(vector<int>nums)
{
	int begin = 0, end = int(nums.size()) - 1;
	return makeTrees(nums, begin, end);
}