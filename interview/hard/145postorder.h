#include"struct.h"

//vector<int>postorTraversal(TreeNode* root)
//{
//	stack<TreeNode*>stk;
//	vector<int>res;
//	if (root == NULL)return res;
//	stk.push(root);
//	TreeNode* prev = NULL;
//	while (!stk.empty())
//	{
//		TreeNode* node = stk.top();
//		if (prev==NULL||prev->left==node||prev->right==node)
//		{ 
//			if (node->left)stk.push(node->left);
//			else if (node->right)stk.push(node->right);
//			else
//			{
//				stk.pop();
//				res.push_back(node->val);
//			}
//		}
//		else if (node->left == prev)
//		{
//			if (node->right)stk.push(node->right);
//			else
//			{
//				stk.pop();
//				res.push_back(node->val);
//			}
//		}
//		else if (node->right == prev)
//		{
//			stk.pop();
//			res.push_back(node->val);
//		}
//		prev = node;
//	}
//	return res;
//}


vector<int>postorer(TreeNode* root)
{
	stack<TreeNode*>stk;
	vector<int>res;
	if (root == NULL)return res;
	stk.push(root);
	TreeNode* prev = NULL;
	while (!stk.empty())
	{
		TreeNode* node = stk.top();
		if (prev == NULL || prev->left == node || prev->right == node)
		{
			if (node->left)stk.push(node->left);
			else if (node->right)stk.push(node->right);
			else
			{
				stk.pop();
				res.push_back(node->val);
			}
		}
		else if (node->left == prev)
		{
			if (node->right)stk.push(node->right);
			else
			{
				stk.pop();
				res.push_back(node->val);
			}
		}
		else if (node->right == prev)
		{
			stk.pop();
			res.push_back(node->val);
		}
		prev = root;
	}
	return res;
}




bool verifyPreorder(vector<int>& nums)
{
	int min_value = INT_MIN, index = -1;
	for (int x : nums)
	{
		if (x < min_value)return false;
		while (index >= 0 && x > nums[index])
		{
			min_value = nums[index--];
		}
		nums[++index] = x;
	}
	return true;
}

bool verifyPostorder(vector<int>& nums)
{
	int max_value = INT_MAX, index = -1;
	reverse(nums.begin(), nums.end());
	for (int x : nums)
	{
		if (x > max_value)return false;
		while (index >= 0 && x < nums[index])
		{
			max_value = nums[index--];
		}
		nums[++index] = x;
	}
	return true;
}