#include"Header.h"
struct TreeNode{
	int val; 
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};


int getHeight(TreeNode* root)
{
	if (root == NULL)return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if (left < 0 || right < 0 || abs(left - right)>1)return -1;
	else return (left>right?left:right) + 1;
}
bool isBalanced(TreeNode* root) {
	if (root == NULL)return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if (left < 0 || right < 0 || abs(left - right)>1)return false;
	else return true;
}