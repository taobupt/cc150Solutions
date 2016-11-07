#include"Header.h"
bool isIsomorphic(string s, string t) {
	/*if (s.size() != t.size())return false;
	int n = s.size();
	unordered_map<char, char>mp1;
	unordered_map<char, char>mp2;
	for (int i = 0; i<n; ++i)
	{
		mp1[s[i]] = t[i];
		mp2[t[i]] = s[i];
	}
	for (int i = 0; i<n; ++i)
	{
		if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])return false;
	}
	return true;*/
	int m1[256] = { 0 }, m2[256] = { 0 };
	int count = 1;
	for (int i = 0; i<s.length(); i++) {
		if (m1[s[i]] != m2[t[i]]) return false;
		if (m1[s[i]] == 0) {
			m1[s[i]] = count;
			m2[t[i]] = count;
			count++;
		}
	}
	return true;
}

// improvement

bool isIsomorphic(string s, string t)
{
	int m1[126] = { 0 }, m2[126] = { 0 };
	int count = 1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (m1[s[i]] != m2[t[i]])return false;
		if (m1[s[i]] == 0)
		{
			m1[s[i]] = count;
			m2[t[i]] = count;
			count++;
		}
	}
	return true;
}

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

void inorderTraversal(TreeNode* root)
{
	if (root == NULL)return;
	stack<TreeNode*>stk;
	TreeNode* node = root;
	while (node)
	{
		stk.push(node);
		node = node->left;
	}
	while (!stk.empty())
	{
		node = stk.top();
		stk.pop();
		printf("%d\n", node->val);
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