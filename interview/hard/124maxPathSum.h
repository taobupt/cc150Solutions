#include"struct.h"

int dfs(TreeNode* root, int &res)
{
	if (root == NULL)return 0;
	int l = dfs(root->left, res);
	int r = dfs(root->right, res);
	int ans = max(root->val, max(l, r) + root->val); 
	res = max(res, max(ans, root->val + l + r));
	return ans;
}

int maxPathSum(TreeNode* root) {
	if (root == NULL)return 0;
	int res = 0;
	dfs(root,res);
	return res;
}