#include"struct.h"


void dfs(TreeNode* root, vector<string>& res, vector<string>& path)
{
	if (root->left == NULL && root->right == NULL)
	{
		string tmp;
		for (string x : path)tmp += x + "->";
		tmp.pop_back();
		tmp.pop_back();
		res.push_back(tmp);
		return;
	}
	if (root->left)
	{
		path.push_back(to_string(root->left->val));
		dfs(root->left, res, path);
		path.pop_back();
	}
	if (root->right)
	{
		path.push_back(to_string(root->right->val));
		dfs(root->right, res, path);
		path.pop_back();
	}
}
vector<string> binaryTreePaths(TreeNode* root) {
	vector<string>res;
	vector<string>path;
	//path.push_back(to_string(root->val));
	if (root == NULL)return res;
	path.push_back(to_string(root->val));
	dfs(root, res, path);
	return res;
}