#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

bool hasPathSum(TreeNode* root, int sum) {
	if (root == NULL)return false;
	//if (root->val == sum)return true;// wrong answer;
	if (root->val == sum && root->left == NULL && root->right == NULL)return true;
	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}