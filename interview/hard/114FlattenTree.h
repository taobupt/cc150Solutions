#include"struct.h"

void flatten(TreeNode* root) {
	if (root == NULL)return;
	TreeNode* save_head = root->right;
	flatten(root->left);
	flatten(save_head);
	root->right = root->left;
	TreeNode* p = root;
	while (p->right)p = p->right;
	p->right = save_head;
}