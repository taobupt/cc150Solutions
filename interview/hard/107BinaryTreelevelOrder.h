#include"Header.h"

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>>res;
	vector<int>inner;
	if (root == NULL)return res;
	queue<TreeNode*>q;
	q.push(root);
	TreeNode* node=NULL;
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
	reverse(res.begin(), res.end());
	return res;
}