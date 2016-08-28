#include"struct.h"
#include"Header.h"

vector<ListNode*>EachDepth(TreeNode* root)
{
	vector<ListNode*>res;
	queue<TreeNode*>q;
	TreeNode* node;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		ListNode* first = new ListNode(0);
		ListNode* head = first;
		while (size--)
		{
			node = q.front();
			q.pop();
			first->next = new ListNode(node->val);
			first = first;
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
		res.push_back(head->next);
	}
	return res;

}