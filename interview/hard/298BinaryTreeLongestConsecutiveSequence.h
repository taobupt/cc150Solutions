#include"struct.h"

int res = 0;
void dfs(TreeNode* root, int cur, int target)
{
	if (root == NULL)return;
	if (root->val == target)cur++;
	else cur = 1;
	res = max(res, cur);
	dfs(root->left, cur, root->val + 1);
	dfs(root->right, cur, root->val + 1);
}
int longestConsecutive(TreeNode* root)
{
	if (root == NULL)return 0;
	dfs(root, 0, root->val);
	return res;
}