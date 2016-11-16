#include"struct.h"
void preorder(TreeNode* root, vector<int>& res)
{
	if (root == NULL)return;
	res.push_back(root->val);
	preorder(root->left, res);
	preorder(root->right, res);
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int>res;
	if (root == NULL)return res;
	preorder(root, res);
	return res;
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int>res;
	if (root == NULL)return res;
	stack<TreeNode*>stk;
	TreeNode* node = NULL;
	stk.push(root);
	while (!stk.empty())
	{
		node = stk.top();
		stk.pop();
		res.push_back(node->val);
		if (node->right)stk.push(node->right);
		if (node->left)stk.push(node->left);
	}
	return res;
}