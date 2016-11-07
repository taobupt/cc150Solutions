#include"Header.h"

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};


// 
//void dfs(TreeNode* &root, vector<int>& inner)
//{
//	if (root->left == NULL && root->right == NULL)
//	{
//		inner.push_back(root->val);
//		root = NULL;
//		return;
//	}
//	if (root->left)dfs(root->left, inner);
//	if (root->right)dfs(root->right, inner);
//}
//
//vector<vector<int>>findLeaves(TreeNode* root)
//{
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	vector<int>inner;
//	while (root)
//	{
//		inner.clear();
//		dfs(root, inner);
//		res.push_back(inner);
//	}
//	return res;
//}


void dfs(TreeNode* &root, vector<int>& inner)
{
	if (root->left == NULL&& root->right == NULL)
	{
		inner.push_back(root->val);
		root = NULL;
		return;
	}
	if (root->left)dfs(root->left, inner);
	if (root->right)dfs(root->right, inner);
}
vector<vector<int>> findLeaves(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == NULL)return res;
	vector<int>inner;
	while (root)
	{
		inner.clear();
		dfs(root, inner);
		res.push_back(inner);
	}
	return res;
}


// height method

int height(TreeNode* root, vector<vector<int>>& res)
{
	if (root == NULL)return -1;
	int level = 1 + max(height(root->left, res), height(root->right, res));
	if (res.size() < level + 1)res.push_back({});
	res[level].push_back(root->val);
	return level;
}

vector<vector<int>>findleaves(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == NULL)return res;
	height(root, res);
	return res;
}

//int height(TreeNode* root, vector<vector<int>>& res)
//{
//	if (root == NULL)return -1;
//	int level = 1 + max(height(root->left, res), height(root->right, res));
//	if (res.size() < level + 1)res.push_back({});
//	res[level].push_back(root->val);
//	return level;
//}
//vector<vector<int>> findLeaves1(TreeNode* root)
//{
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	height(root, res);
//	return res;
//}
