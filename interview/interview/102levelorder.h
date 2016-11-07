#include"Header.h"
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>res;
	if (root == NULL)return res;
	vector<int>inner;
	queue<TreeNode*>q;
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


//more efficient
int maxHeight(TreeNode* root)
{
	if (root == NULL)return 0;
	else return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

int maxHeightBFS(TreeNode* root)
{
	if (root == NULL)return 0;
	queue<TreeNode*>q;
	q.push(root);
	int res = 0;
	TreeNode* node = NULL;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			node = q.front();
			q.pop();
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
		res++;
	}
}

void dfs(TreeNode* root, int height,vector<vector<int>>& res)
{
	if (root == NULL)return;
	res[height].push_back(root->val);
	dfs(root->left, height + 1, res);
	dfs(root->right, height, res);
	
}
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>res;
	if (root == NULL)return res;
	int level = maxHeight(root);
	res.resize(level);
	dfs(root, 0,res);
}
