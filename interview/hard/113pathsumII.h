#include"struct.h"


void dfs(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum)
{
	if (root->left == NULL && root->right == NULL && sum == 0)
	{
		res.push_back(path);
		return;
	}
	if (root->left)
	{
		path.push_back(root->left->val);
		dfs(res, path, root->left, sum - root->left->val);
		path.pop_back();
	}
	if (root->right)
	{
		path.push_back(root->right->val);
		dfs(res, path, root->right, sum - root->right->val);
		path.pop_back();
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>>res;
	vector<int>path;
	if (root == NULL)return res;
	path.push_back(root->val);
	dfs(res,path,root,sum-root->val);
	return res;
}