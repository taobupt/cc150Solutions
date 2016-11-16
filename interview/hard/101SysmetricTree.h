#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

bool isSame(TreeNode* p, TreeNode* q)
{
	if (p == NULL || q == NULL)return p == q;
	return (p->val==q->val) && isSame(p->left, q->right) && isSame(p->right, q->left);
}
bool isSymmetric(TreeNode* root) {
	if (root == NULL)return true;
	return isSame(root->left, root->right);
}