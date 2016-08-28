#include"Header.h"
#include"struct.h"


int dfs(TreeNode* root)
{
	if (root == NULL)return 0;
	int l = dfs(root->left);
	int r = dfs(root->right);
	if (l < 0 || r < 0 || abs(l - r)>1)return -1;
	else return max(l, r) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (root == NULL)return true;
	int l = dfs(root->left);
	int r = dfs(root->right);
	if (l < 0 || r < 0 || abs(l - r)>1)return false;
	else return true;
}