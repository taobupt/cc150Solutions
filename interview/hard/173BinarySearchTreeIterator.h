#include"struct.h"

class BSTIterator{
	stack<TreeNode*>stk;
public:
	BSTIterator(TreeNode* root)
	{
		find_left(root);
	}
	bool hasNext()
	{
		return !stk.empty();
	}
	int next()
	{
		TreeNode* top = stk.top();
		stk.pop();
		if (top->right)find_left(top->right);
		return top->val;
	}

	void find_left(TreeNode* root)
	{
		TreeNode* p = root;
		while (p)
		{
			stk.push(p);
			p = p->left;
		}
	}
};