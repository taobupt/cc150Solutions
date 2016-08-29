#include"Header.h"
#include"struct.h"

class Codec{
public:
	vector<string>serialize(TreeNode* root)
	{
		vector<string>res;
		queue<TreeNode*>q;
		q.push(root);
		TreeNode* node;
		while (!q.empty())
		{
			node = q.front();
			q.pop();
			if (node)
			{
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

	TreeNode* deserialize(vector<string> data)
	{
		if (data.empty() || data[0] == "#")return NULL;
		queue<TreeNode*>q;
		TreeNode* root = new TreeNode(stoi(data[0]));
		TreeNode* cur = root;
		for (int i = 1; i < data.size(); ++i)
		{
			if (data[i] == "#")
			{
				if (i % 2 == 0 && !q.empty())
				{
					cur = q.front();
					q.pop();
				}
				continue;
			}
			TreeNode* newNode = new TreeNode(stoi(data[i]));
			q.push(newNode);
			if (i % 2 == 1)cur->left = newNode;
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