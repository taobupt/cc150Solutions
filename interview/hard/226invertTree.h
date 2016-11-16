#include"struct.h"
TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)return NULL;
	TreeNode* left = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(left);
	return root;
}