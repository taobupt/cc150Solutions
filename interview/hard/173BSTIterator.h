#include"struct.h"




//space O(n)
class BSTIterator {
public:

	void inorder(TreeNode* root)
	{
		if (root == NULL)return;
		inorder(root->left);
		nums.push(root->val);
		inorder(root->right);
	}
	BSTIterator(TreeNode *root) {
		inorder(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !nums.empty();
	}

	/** @return the next smallest number */
	int next() {
		int top = nums.front();
		nums.pop();
		return top;
	}
private:
	queue<int>nums;
};


//
class BSTIterator1 {
public:

	BSTIterator1(TreeNode *root) {
		pushALL(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* tmpnode = stk.top();
		stk.pop();
		pushALL(tmpnode->right);
		return tmpnode->val;
	}
private:
	stack<TreeNode*>stk;
	void pushALL(TreeNode* node)
	{
		for (; node != NULL; stk.push(node), node = node->left);
	}
};
