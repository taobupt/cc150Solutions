#include"Header.h"
#include"struct.h"


//without data structor
TreeNode* commonAncestor(TreeNode* root,TreeNode* p, TreeNode* q)
{
	if (root == NULL || root == p || root == q)return root;
	TreeNode* left = commonAncestor(root->left, p, q);
	TreeNode* right = commonAncestor(root->right, p, q);
	if (left && right)return root;
	return left ? left : right;
}

void dfs236(TreeNode* root, TreeNode* p, vector<TreeNode*>& v, vector<TreeNode*>&res)
{
	if (root == p)
	{
		//v.push_back(root);
		for (auto node : v)res.push_back(node);
		return;
	}
	else
	{
		if (root->left)
		{
			v.push_back(root->left);
			dfs236(root->left, p, v, res);
			v.pop_back();
		}
		if (root->right)
		{
			v.push_back(root->right);
			dfs236(root->right, p, v, res);
			v.pop_back();
		}
	}
}

TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || root == p || root == q)return root;
	vector<TreeNode*>pNode;
	vector<TreeNode*>qNode;
	vector<TreeNode*>path;
	path.push_back(root);
	dfs236(root, p, path, pNode);
	path.clear();
	path.push_back(root);
	dfs236(root, q, path, qNode);
	int i = 0;
	for (i = 0; i < pNode.size() && i < qNode.size(); ++i)
	{
		if (pNode[i] != qNode[i])break;
	}
	return pNode[i - 1];
}