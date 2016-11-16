#include"struct.h"
class Codec {
public:

	// Encodes a tree to a single string.
	vector<string> serialize(TreeNode* root) {
		vector<string>res;
		if (root == NULL)return res;
		queue<TreeNode*>q;
		q.push(root);
		TreeNode* node = NULL;
		while (!q.empty())
		{
			node = q.front();
			q.pop();
			if (node){
				res.push_back(to_string(node->val));
				q.push(node->left);
				q.push(node->right);
			}
			else
			{
				res.push_back("#");
			}
		}
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(vector<string> data) {
		if (data.empty() || data[0] == "#")return NULL;
		queue<TreeNode*>q;
		TreeNode* root = new TreeNode(stoi(data[0]));
		TreeNode* cur = root;
		int n = data.size();
		for (int i = 1; i < n; ++i)
		{
			if (data[i] == "#")
			{
				if (!q.empty() && i % 2 == 0)
				{
					cur = q.front();
					q.pop();
				}
				continue;
			}
			TreeNode* newNode = new TreeNode(stoi(data[i]));
			q.push(newNode);
			if (i % 2)cur->left = newNode;
			else
			{
				cur->right = newNode;
				cur = q.front();
				q.pop();
			}
		}
		return root;
	}
};


void inorder(TreeNode* root)
{
	if (root == NULL)return;
	stack<TreeNode*>stk;
	TreeNode* node = NULL;
	while (root)
	{
		stk.push(root);
		root = root->left;
	}
	while (!stk.empty())
	{
		node = stk.top();
		printf("%d ", node->val);
		stk.pop();
		if (node->right)
		{
			node = node->right;
			while (node)
			{
				stk.push(node);
				node = node->left;
			}
		}
	}
}