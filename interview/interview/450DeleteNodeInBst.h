#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
int minValue(TreeNode* root)
{
	while (root->left)root = root->left;
	return root->val;
}
TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL)return root;
	if (root->val>key)root->left = deleteNode(root->left, key);
	else if (root->val<key)root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL && root->right == NULL)root = NULL;
		else if (root->left == NULL || root->right == NULL)root = root->left ? root->left : root->right;
		else
		{
			root->val = minValue(root->right);
			root->right = deleteNode(root->right, root->val);
		}
	}
	return root;
}