#include"Header.h"
#include"struct.h"


bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL || q == NULL)return p == q;
	return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSubTree(TreeNode* T1, TreeNode* T2)
{
	if (T1 == NULL && T2 == NULL)return true;
	if (T1 == NULL || T2 == NULL)return false;
	return isSameTree(T1, T2) || isSubTree(T1->left, T2) || isSubTree(T1->right,T2);
}

