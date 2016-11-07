#include"Header.h"

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

bool isSymmetricbacktracking(TreeNode* p, TreeNode* q)
{
	if (p == NULL || q == NULL)return p == q;
	return (p->val == q->val) && isSymmetricbacktracking(p->left, q->right) && isSymmetricbacktracking(p->right, q->left);
}
bool isSymmetric(TreeNode* root) {
	if (root == NULL)return true;
	return isSymmetricbacktracking(root->left, root->right);
}