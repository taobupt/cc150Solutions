#include"struct.h"

vector<vector<int>> verticalOrder(TreeNode* root)
{
	vector<vector<int>>output;
	if (root == NULL)return output;
	map<int, vector<int>>m;
	queue<pair<int, TreeNode*>>q;
	q.push(make_pair(0, root));
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			TreeNode* node = q.front().second;
			int tmp = q.front().first;
			q.pop();
			m[tmp].push_back(node->val);
			if (node->left)
			{
				q.push(make_pair(tmp - 1, node->left));

			}
			if (node->right)
			{
				q.push(make_pair(tmp + 1, node->right));
			}
		}
	}
	for (auto& v : m)output.push_back(v.second);
	return output;
}