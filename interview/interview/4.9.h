#include"struct.h"
#include"Header.h"

void print(TreeNode* root, int sum, int* path, int level)
{
	if (root == NULL)return;
	path[level] = root->val;
	int s = 0;
	for (int i = level; i >= 0; --i)
	{
		s += path[i];
		if (s == sum)
		{
			for (int j = level; j >= i; --j)
			{
				printf("%d ", path[j]);
			}
			printf("\n");
		}
	}
	if (root->left)print(root->left, sum, path, level + 1);
	if (root->right)print(root->right, sum, path, level + 1);
}

