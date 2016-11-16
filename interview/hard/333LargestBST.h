#include"Header.h"

struct info{
	bool isbst;
	int size, min, max;
	info() :size(0), min(INT_MAX), max(INT_MIN), isbst(true){}
};

class Solution {
public:

	info* findLargest(TreeNode* root)
	{
		if (root == NULL)return new info();
		info* left = findLargest(root->left);
		info* right = findLargest(root->right);
		info* m = new info();
		if (!left->isbst || !right->isbst || left->max >= root->val || right->min <= root->val)
		{
			m->isbst = false;
			m->size = max(left->size, right->size);
			return m;
		}
		m->size = left->size + right->size + 1;
		m->isbst = true;
		m->min = root->left ? left->min : root->val;
		m->max = root->right ? right->max : root->val;
		return m;
	}
	int largestBSTSubtree(TreeNode* root) {
		return findLargest(root)->size;
	}
};