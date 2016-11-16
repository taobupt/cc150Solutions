#include"struct.h"
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL)return NULL;
	if (root->val > max(p->val, q->val))return lowestCommonAncestor(root->left, p, q);
	else if (root->val < min(p->val, q->val))return lowestCommonAncestor(root->right, p, q);
	else return root;
}