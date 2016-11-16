#include"Header.h"

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):val(val), left(NULL), right(NULL){}
};

TreeNode* pre = NULL;
bool isValidBST(TreeNode* root)
{
	if (root == NULL)return true;
	if (!isValidBST(root->left))return false;
	//if (pre == NULL)pre = root;
	if (pre && pre->val >= root->val)return false;
	pre = root;
	if (!isValidBST(root->right))return false;
	return true;
}