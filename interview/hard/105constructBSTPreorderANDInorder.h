#include"struct.h"




TreeNode* makeTrees(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2)
{
	if (begin1 > end1)return NULL;
	else if (begin1 == end1)return new TreeNode(preorder[begin1]);
	else
	{
		TreeNode* root = new TreeNode(preorder[begin1]);
		int index = begin2;
		while (index <= end2)
		{
			if (inorder[index] == preorder[begin1])break;
			index++;////////attention this
		}
		root->left = makeTrees(preorder, begin1 + 1, index+begin1-begin2, inorder, begin2, index - 1);
		root->right = makeTrees(preorder, index+begin1-begin2+1, end1, inorder, index + 1, end2);
		return root;
	}
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int n = preorder.size();
	return makeTrees(preorder, 0, n - 1, inorder, 0, n - 1);
}