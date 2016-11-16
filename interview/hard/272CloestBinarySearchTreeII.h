#include"struct.h"

void inorder(TreeNode* root, stack<int>& stk, bool reverse, double target)
{
	if (root == NULL)return;
	reverse ? inorder(root->right, stk, reverse, target) : inorder(root->left, stk, reverse, target);
	if (reverse && root->val <= target || !reverse&& root->val > target)return;
	stk.push(root->val);
	reverse ? inorder(root->left, stk, reverse, target) : inorder(root->right, stk, reverse, target);
}
vector<int> cloestKValues(TreeNode* root, double target, int k)
{
	vector<int>res;
	stack<int>predecessor;
	stack<int>successor;
	inorder(root, predecessor, false, target);
	inorder(root, successor, true, target);
	while (k--)
	{
		if (predecessor.empty())
		{
			res.push_back(successor.top());
			successor.pop();

		}
		else if (successor.empty())
		{
			res.push_back(predecessor.top());
			predecessor.pop();
		}
		else if (fabs(target - predecessor.top()) > fabs(target - successor.top()))
		{
			res.push_back(successor.top());
			successor.pop();
		}
		else
		{
			res.push_back(predecessor.top());
			predecessor.pop();
		}
	}
	return res;
}