#include"Header.h"

struct TreeLinkNode{
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int val) :val(val), left(NULL), right(NULL),next(NULL){}
};


struct DoubleListNode{
	int val;
	DoubleListNode* pre;
	DoubleListNode* next;
	DoubleListNode(int val) :val(val), next(NULL), pre(NULL){}
};

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
class Codec{
public:
	vector<string>serialize(TreeNode* root)
	{
		vector<string>res;
		queue<TreeNode*>q;
		if (root == NULL)return res;
		TreeNode* node = NULL;
		q.push(root);
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
			else res.push_back("#");
		}
		return res;
	}

	TreeNode* deserialize(vector<string> data)
	{
		if (data.empty() || data[0] == "#")return NULL;
		TreeNode* root = new TreeNode(stoi(data[0]));
		TreeNode* cur = root;
		queue<TreeNode*>q;
		for (int i = 1; i<(int)data.size(); ++i)
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
