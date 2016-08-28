#include"Header.h"
#include"struct.h"

TreeNode* nextBSTNode(TreeNode* node)
{
	if (node->right)
	{
		node = node->right;
		while (node->left)node = node->left;
		return node;
	}
	else
	{
		TreeNode* father = node->father;
		while (father && father->right == node)
		{
			node = father;
			father = father->father;
		}
		return father
	}
}