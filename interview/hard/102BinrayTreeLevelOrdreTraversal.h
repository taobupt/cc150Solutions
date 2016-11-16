#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>res;
	vector<int>inner;
	queue<TreeNode*>q;
	if (root == NULL)return res;
	q.push(root);
	TreeNode* node = NULL;
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
		res.push_back(inner);
	}
	return res;
}

//version2

int maxDepth(TreeNode* root) {
	if (root == NULL)return 0;
	else return  max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void dfs(vector<vector<int>>&res, TreeNode* root, int level)
{
	if (root == NULL)return;
	res[level].push_back(root->val);
	dfs(res, root->left, level + 1);
	dfs(res, root->right, level + 1);
}
vector<vector<int>> levelOrder2(TreeNode* root) {
	int depth = maxDepth(root);
	vector<vector<int>>res(depth);
	dfs(res, root, 0);
	return res;
}