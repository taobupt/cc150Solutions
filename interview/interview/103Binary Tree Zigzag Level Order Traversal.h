#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	queue<TreeNode*>q;
	vector<vector<int>>res;
	if (root == NULL)return res;
	vector<int>inner;
	TreeNode* node = NULL;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		inner.clear();
		while (size--)
		{
			node = q.front();
			q.pop();
			inner.push_back(node->val);
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
		if (res.size() & 0x1)reverse(inner.begin(), inner.end());
		res.push_back(inner);
	}
	return res;
}


int maxHeight(TreeNode* root)
{
	if (root == NULL)return 0;
	else return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}


void dfs(TreeNode* root, vector<vector<int>>& res, int level)
{
	if (root == NULL)return;
	res[level].push_back(root->val);
	dfs(root->left, res, level + 1);
	dfs(root->right, res, level + 1);
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	int level = maxHeight(root);
	vector<vector<int>>res(level);
	dfs(root, res,0);
	for (int i = 0; i < (int)res.size(); ++i)
	{
		if (i & 0x1)reverse(res[i].begin(), res[i].end());
	}
	return res;
}