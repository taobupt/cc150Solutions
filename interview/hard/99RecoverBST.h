#include"struct.h"




TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev1= NULL;
void inorder(TreeNode* root)
{
	if (root == NULL)return;
	inorder(root->left);
	if (prev1)
	{
		if (prev1->val > root->val)
		{
			if (first == NULL)first = prev1;
			second = root;
		}
	}
	prev1 = root;
	inorder(root->right);
}
void recoverTree(TreeNode* root) {
	inorder(root);
	swap(first->val, second->val);
}