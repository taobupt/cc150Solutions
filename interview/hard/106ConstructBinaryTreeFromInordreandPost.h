#include"struct.h"

TreeNode* makeTree(vector<int>& inorder, int begin1,int end1,vector<int>& postorder, int begin2, int end2)
{
	if (begin2 > end2)return NULL;
	else if (begin2 == end2)return new TreeNode(postorder[begin2]);
	else
	{
		TreeNode* root = new TreeNode(postorder[end2]);
		int index = begin1;
		while (index <= end1)
		{
			if (inorder[index] == postorder[end2])break;
			index++;
		}
		root->left = makeTree(inorder, begin1, index - 1, postorder, begin2, index-1-begin1+begin2);
		root->right = makeTree(inorder, index + 1, end1,postorder,index+begin2-begin1,end2-1 );
		return root;
	}
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	int n = postorder.size();
	return makeTree(inorder, 0, n - 1, postorder, 0, n - 1);
}