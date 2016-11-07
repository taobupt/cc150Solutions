#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == root || q == root)return root;
	TreeNode* l = lowestCommonAncestor(root->left, p, q);
	TreeNode* r = lowestCommonAncestor(root->right, p, q);
	if (l&&r)return root;
	return l ? l : r;
}