#include"Header.h"

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
TreeNode* upsideDownBinaryTree(TreeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL))return root;
	TreeNode* res = upsideDownBinaryTree(root->left);
	TreeNode* p = res;
	while (p->right)p = p->right;
	p->right = root;
	p->left = root->right;
	root->left = NULL;
	root->right = NULL;
	return res;
}

TreeNode* upside(TreeNode* root)
{
	if (root == NULL || root->left == NULL && root->right == NULL)return root;
	TreeNode* newRoot = upside(root->left);
	root->left->left = root->right;
	root->left->right = root;
	root->left = NULL;
	root->right = NULL;
	return newRoot;
}
TreeNode* upsideIterative(TreeNode* root)
{
	TreeNode* curr = root;
	TreeNode* next = NULL;
	TreeNode* tmp = NULL;
	TreeNode* prev = NULL;
	while (curr != NULL)
	{
		next = curr->left;

		// swapping
		curr->left = tmp;
		tmp = curr->right;
		curr->right = prev;

		prev = curr;
		curr = next;
	}
	return prev;
}