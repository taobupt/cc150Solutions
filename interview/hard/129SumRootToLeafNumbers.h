#include"struct.h"


void dfs(TreeNode* root, vector<int>& path, int& res)
{
	if (root->left == NULL && root->right == NULL)
	{
		int x = 0;
		for (int cc : path)x = 10 * x + cc;
		res += x;
		return;
	}
	if (root->left)
	{
		path.push_back(root->left->val);
		dfs(root->left , path, res);
		path.pop_back();
	}
	if (root->right)
	{
		path.push_back(root->right->val);
		dfs(root->right, path, res);
		path.pop_back();
	}
}
int sumNumbers(TreeNode* root) {
	if (root == NULL)return 0;
	int res = 0;
	vector<int>path;
	path.push_back(root->val); 
	dfs(root, path, res);
	return res;
}