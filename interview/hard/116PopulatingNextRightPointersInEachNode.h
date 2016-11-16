#include"Header.h"

struct TreeLinkNode{
	TreeLinkNode *left;
	TreeLinkNode* right;
	TreeLinkNode* next;
};
void connect(TreeLinkNode *root) {
	if (root == NULL)return;
	queue<TreeLinkNode*>q;
	q.push(root);
	TreeLinkNode* node = NULL;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			node = q.front();
			q.pop();
			if (size == 0)node->next = NULL;
			else node->next = q.front();
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
	}
}