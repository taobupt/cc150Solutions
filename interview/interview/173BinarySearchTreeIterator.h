#include"Header.h"

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		findLeft(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = stk.top();
		stk.pop();
		int top = node->val;
		if (node->right)findLeft(node->right);
		return top;
	}

	void findLeft(TreeNode* root)
	{
		if (root == NULL)return;
		TreeNode* node = root;
		while (node)
		{
			stk.push(node);
			node = node->left;
		}
	}
private:
	stack<TreeNode*>stk;
};