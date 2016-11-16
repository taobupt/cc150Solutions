#include"struct.h"


TreeNode* makeTree(vector<int>& nums, int begin, int end)
{
	if (begin > end)return NULL;
	else if (begin == end)return new TreeNode(nums[begin]);
	else
	{
		int mid = begin + (end - begin) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = makeTree(nums, begin, mid - 1);
		root->right = makeTree(nums, mid + 1, end);
		return root;
	}
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	int n = nums.size();
	return makeTree(nums, 0, n - 1);
}