#include"Header.h"

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};


struct Interval{
	int start;
	int end;
	Interval(int s = 0, int e = 0) :start(s), end(e){}
};
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

class NestedInteger{
public:
	bool isInteger() const;
	int getInteger();
	const vector<NestedInteger>& getList()const;
};
//-- easy---
//lt 28
//@taobupt

//Implement strStr().
//Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.

//you can also use the kmp algorithms
int strStr(string haystack, string needle) {
	int m = haystack.size(), n = needle.size();
	string sub;
	for (int i = 0; i < m - n + 1; ++i)
	{
		sub = haystack.substr(i, n);
		if (sub == needle)return i;
	}
	return -1;
}

//252 meeting rooms
//@taobupt

//Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), determine if a person could attend all meetings.

//	For example,
//	Given[[0, 30], [5, 10], [15, 20]],
//	return false.
bool canAttendMeetings(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start==b.start?a.end<b.end:a.start<b.start; });
	int n = intervals.size();
	for (int i = 1; i < n; ++i)
	{
		if (intervals[i].start < intervals[i - 1].end)return false;
	}
	return true;
}

//13 lt roman to integer
//@taobupt
// given a roman numeral,convert it to an integer

// you can use array whihc is faster
//
//int romanToInt(string s) {
//	if (s.empty())return 0;
//	//unordered_map<char, int>mp = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
//	int a[26] = { 0 };
//	a['I' - 'A'] = 1;
//	a['V' - 'A'] = 5;
//	a['X' - 'A'] = 10;
//	a['L' - 'A'] = 50;
//	a['C' - 'A'] = 100;
//	a['D' - 'A'] = 500;
//	a['M' - 'A'] = 1000;
//	int n = s.size();
//	int sum = a[s.back() - 'A'];
//	for (int i = n - 2; i >= 0; --i)
//	{
//		sum += a[s[i] - 'A'] < a[s[i + 1] - 'A'] ? -a[s[i] - 'A'] : a[s[i] - 'A'];
//	}
//	return sum;
//}
int romanToInt(string s) {
	if (s.empty())return 0;
	unordered_map<char, int>mp = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
	int n = s.size();
	int sum = mp[s.back()];
	for (int i = n - 2; i >= 0; --i)
	{
		sum += mp[s[i]] < mp[s[i + 1]] ? -mp[s[i]] : mp[s[i]];
	}
	return sum;
}

// leetocde 121 best time to buy and sell stock
//@taobupt

/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input : [7, 1, 5, 3, 6, 4]
Output : 5

		 max.difference = 6 - 1 = 5 (not 7 - 1 = 6, as selling price needs to be larger than buying price)
		 Example 2 :
	 Input : [7, 6, 4, 3, 1]
		 Output : 0

				  In this case, no transaction is done, i.e.max profit = 0.
*/
int maxProfit(vector<int>& prices) {
	int minPrice = INT_MAX;
	int profit = 0;
	for (int x : prices)
	{
		minPrice = min(minPrice, x);
		profit = max(profit, x - minPrice);
	}
	return profit;
}

// 235 lowest common ancestor of a binary serach tree
//@taobupt
/*Given a binary search tree(BST), find the lowest common ancestor(LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).”

_______6______
/ \
___2__          ___8__
/ \ / \
0      _4       7       9
/ \
3   5
For example, the lowest common ancestor(LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL)return NULL;
	if (root->val > max(p->val, q->val))return lowestCommonAncestor(root->left, p, q);
	else if (root->val < min(p->val, q->val))return lowestCommonAncestor(root->right, p, q);
	return root;
}

//follow up iterative
TreeNode* lowestCommonAncestorIterative(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL)return NULL;
	while (root)
	{
		if (root->val > max(p->val, q->val))root = root->left;// pay attention here, we should judge left and right first, else we can return root directly;
		else if (root->val < min(p->val, q->val))root = root->right;
		else return root;
	}
	return NULL;
}


//102 level order traversal
//@taobupt

/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example :
Given binary tree[3, 9, 20, null, null, 15, 7],
3
/ \
9  20
/ \
15   7
return its level order traversal as :
[
	[3],
	[9, 20],
	[15, 7]
]
*/
//by bfs
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>res;
	if (root == NULL)return res;
	queue<TreeNode*>q;
	TreeNode*node = NULL;
	q.push(root);
	vector<int>inner;
	while (!q.empty())
	{
		int size = q.size();
		inner.clear();
		while (size--)
		{
			node = q.front();
			q.pop();
			inner.push_back(node->val);
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
		res.push_back(inner);
	}
	return res;
}

//by dfs  faster

int maxDepth(TreeNode* root){
	if (root == NULL)return 0;
	else return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

void dfsLevelOrder(TreeNode* root, vector<vector<int>>& res, int level)
{
	if (root == NULL)return;
	res[level].push_back(root->val);
	dfsLevelOrder(root->left, res, level+1);
	dfsLevelOrder(root->right, res, level + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
	int depth = maxDepth(root);
	vector<vector<int>>res(depth);
	if (res.empty())return res;
	dfsLevelOrder(root, res, 0);
	return res;
}

//lt 26 removeDuplicates from sorted array
//@taobupt
int removeDuplicates(vector<int>& nums) {
	int i = 1, j = 1, n = nums.size();
	if (n < 2)return n;
	while (i < n)
	{
		if (nums[i] != nums[i - 1])nums[j++] = nums[i];
		i++;
	}
	return j;
}


/*For example,
Given sorted array nums = [1, 1, 1, 2, 2, 3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/
//lt 80 at most twice
int removeDuplicatesII(vector<int>& nums) {
	int n = nums.size();
	if (n <= 2)return n;
	int i = 2, j = 2;
	int pre1 = nums[0];
	int pre2 = nums[1];
	while (i<n)
	{
		if (pre1 == pre2 &&pre2 == nums[i])
		{
			while (i<n && pre2 == nums[i])i++;
			if (i<n)
			{
				pre2 = nums[i];
				nums[j++] = nums[i++];
			}
		}
		else
		{
			pre1 = nums[i - 1];
			pre2 = nums[i];
			nums[j++] = nums[i++];
		}
	}
	return j;
}

int removeDuplicatesII1(vector<int>& nums) {
	int i = 0;
	for (int n : nums)
		if (i < 2 || n != nums[i - 2])
			nums[i++] = n;
	return i;
}

int removeDuplicatesII2(vector<int>& nums) {
	int n = nums.size(), i = 0, j = 0;
	unordered_map<int, int>mp;
	while (i < n)
	{
		if (++mp[nums[i]] < 3)nums[j++] = nums[i];
		i++;
	}
	return j;
}

//lt 257 binary tree paths
//@taobupt


/*Given a binary tree, return all root - to - leaf paths.

For example, given the following binary tree :

1
/ \
2     3
\
5
All root - to - leaf paths are :

["1->2->5", "1->3"]
*/

//dfs can solve this

void dfsBinaryTreePaths(TreeNode* root, vector<string>& res, string path)
{
	if (root->left == NULL && root->right == NULL)
	{
		path+=to_string(root->val);
		res.push_back(path);
		return;
	}
	if (root->left)dfsBinaryTreePaths(root, res, path + to_string(root->val) + "->");
	if (root->right)dfsBinaryTreePaths(root, res, path + to_string(root->val) + "->");
}
vector<string> binaryTreePaths(TreeNode* root) {
	vector<string>res;
	string path;
	if (root == NULL)return res;
	dfsBinaryTreePaths(root, res, path);
	return res;
}


//20 valid parentheses only solved by stack
//@taobupt

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
bool isValid(string s) {
	stack<char>stk;
	for (char c : s)
	{
		switch (c){
		case '(':
			stk.push(c);
			break;
		case '[':
			stk.push(c);
			break;
		case '{':
			stk.push(c);
			break;
		case')':
			if (stk.empty() || stk.top() != '(')return false; else stk.pop(); break;
		case'}':
			if (stk.empty() || stk.top() != '{')return false; else stk.pop(); break;
		case']':
			if (stk.empty() || stk.top() != '[')return false; else stk.pop(); break;
		}
	}
	return stk.empty();
}

//88 merged sorted array;
// @taobupt

//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

//Note:
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.The number of elements initialized in nums1 and nums2 are m and n respectively.

//save space;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int k = m + n - 1;
	int i = m-1;
	int j = n-1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] >= nums2[j])nums1[k--] = nums1[i--];
		else nums1[k--] = nums2[j--];
	}
	while (j >= 0)nums1[k--] = nums2[j--];

}


// lt 168 excel sheet column title
//@taobupt
string convertToTitle(int n) {
	string res;
	if (n < 1)return res;
	while (n)
	{
		res =char((n-1)%26+'A')+res;
		n = (n - 1) / 26;
	}
	return res;
}

// recrusive way
string convertToTitle(int n)
{
	return n < 1 ? "" : convertToTitle((n - 1) / 26) + char((n - 1) % 26 + 'A');
}


// 278 first bad version
//@taobupt
/*
You are a product manager and currently leading a team to develop a new product.Unfortunately, the latest version of your product fails the quality check.Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad.Implement a function to find the first bad version.You should minimize the number of calls to the API.
*/
bool isBadVersion(int version);
int firstBadVersion(int n) {
	int begin = 1, end = n, mid = 0;
	while (begin<end)
	{
		mid = begin + (end - begin) / 2;
		if (isBadVersion(mid))end = mid;
		else begin = mid + 1;
	}
	return begin;
}



// lt 283 move zeroes

//@taobupt

//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].

//Note:
//You must do this in - place without making a copy of the array.
//Minimize the total number of operations.
void moveZeroes(vector<int>& nums) {
	int i = 0, n = nums.size(), j = 0;
	while (i < n)
	{
		if (nums[i] != 0)nums[j++] = nums[i];
		i++;
	}
	while (j < n)nums[j++] = 0;
}

// facebook interviewer require
//
int moveZeroesWithMinimumSetps(vector<int>& nums)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		while (left < right && nums[left] != 0)left++;
		while (left < right && nums[right] == 0)right--;
		if (left < right)nums[left++] = nums[right--];
	}
	return left;
}

// 67 add binary 
//@taobupt

//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

string addBinary(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0, j = 0, m = a.size(), n = b.size();
	int extra = 0;
	string res;
	while (i < m || j < n || extra)
	{
		int sum = (i<m ? (a[i++] - '0') : 0) + (j<n ? b[j++] - '0' : 0) + extra;
		res = char(sum % 2 + '0') + res;
		extra = sum / 2;
	}
	return res;
}

// better , merge carry and sum to a variable

string addBinaryBetter(string a, string b)
{
	string s;
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || c)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? b[j--] - '0' : 0;
		s = char(c % 2 + '0') + s;
		c /= 2;
	}
	return s;
}

//125 valid parlindrome
//@taobupt

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

bool isPalindrome(string s) {
	string res;
	for (char c : s)if (isalnum(c))res.push_back(tolower(c));
	int n = res.size();
	for (int i = 0; i < n / 2; ++i)
	{
		if (res[i] != res[n - 1 - i])return false;
	}
	return true;
}

// lt 157 157. Read N Characters Given Read4
/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
*/

int read4(char *buf);
int read(char *buf, int n) {
	int x = 0, res = 0;
	x = read4(buf + res);
	while (x == 4)
	{
		res += x;
		x = read4(buf + res);
	}
	return min(n, res + x);
}



//count and say

// medium ----


//@taobupt

//Implement pow(x, n).
double myPow(double x, int n) {
	bool negative = n < 0 ? true : false;
	unsigned nn = n < 0 ? -n : n;
	if (n == 0)return 1.0;//accerlate this process
	double res = 1.0;
	while (nn)
	{
		if (nn & 0x1)res *= x;
		nn >>= 1;
		x *= x;
	}
	return negative?1.0/res:res;
}

double mypowRecrusive(double x, int n)
{
	if (n == 0)return 1.0;
	if (n < 0)
	{
		n = -n;
		x = 1.0 / x;
	}
	return n % 2 == 0 ? mypowRecrusive(x*x, n / 2) : x*mypowRecrusive(x*x, n / 2);
}


//leetcode 173 binary serach tREE iterator
//@taobupt

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/


//inorder traversal
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		findleft(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = stk.top();
		stk.pop();
		int val = node->val;
		if (node->right)findleft(node->right);
		return val;

	}
	void findleft(TreeNode* root)
	{
		if (root == NULL)return;
		TreeNode* node = root;
		while (node)
		{
			stk.push(node);
			node = node->left;
		}
	}
private:
	stack<TreeNode*>stk;
};

class BinaryPreorderIterator{
public:
	BinaryPreorderIterator(TreeNode* root)
	{
		if (root != NULL)stk.push(root);
	}
	bool hasNext()
	{
		return !stk.empty();
	}

	int Next()
	{
		TreeNode* node = stk.top();
		stk.pop();
		int val = node->val;
		if (node->right)stk.push(node->right);
		if (node->left)stk.push(node->left);
		return val;
	}

private:
	stack<TreeNode*>stk;
};


class BinaryPostorderIterator{
public:
	BinaryPostorderIterator(TreeNode* root)
	{
		findNextLeaf(root);
	}
	bool hasNext()
	{
		return !stk.empty();
	}

	int Next()
	{
		TreeNode* res = stk.top();
		stk.pop();
		if (!stk.empty())
		{
			TreeNode* top = stk.top();
			if (res == top->left)findNextLeaf(top->right);
		}
		return res->val;
	}

	void findNextLeaf(TreeNode* cur)
	{
		while (cur)
		{
			stk.push(cur);
			if (cur->left)cur = cur->left;
			else cur = cur->right;
		}
	}

private:
	stack<TreeNode*>stk;
};




vector<int> postorderTraversal(TreeNode* root) {
	vector<int>res;
	stack<TreeNode*>stk;
	if (root == NULL)return res;
	TreeNode* pre = NULL;
	TreeNode* node = NULL;
	stk.push(root);
	while (!stk.empty())
	{
		node = stk.top();
		if (pre == NULL || pre->left == node || pre->right == node)
		{
			if (node->left)stk.push(node->left);
			else if (node->right)stk.push(node->right);
			else
			{
				stk.pop();
				res.push_back(node->val);
			}
		}
		else if (node->left == pre)
		{
			if (node->right)stk.push(node->right);
			else
			{
				stk.pop();
				res.push_back(node->val);
			}

		}
		else if (node->right == pre)
		{
			stk.pop();
			res.push_back(node->val);
		}
		pre = node;
	}
	return res;
}

// ltcode 91 decodes ways
//@taobupt
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

int numDecodings(string s) {
	int n = s.size();
	if (s.empty()||s[0]=='0')return 0;// attention here, otherwise wa;
	vector<int>dp(n + 1, 0);
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] > '2'))return 0;
		else if (s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2'))dp[i + 1] = dp[i - 1];
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' &&s[i] <= '6'))dp[i + 1] = dp[i] + dp[i - 1];
		else dp[i+1] = dp[i];
	}
	return dp[n];
}

// actually you can change it into O(1) space;

int numDecodingsSaveSpace(string s)
{
	if (s.empty() || s[0] == '0')return 0;
	int n = s.size();
	int r1 = 1, r2 = 1;// r2:decode ways of s[i-2],r1:decodes ways of s[i-1];
	for (int i = 2; i < n; ++i)
	{
		if (s[i] == '0')r1 = 0;
		if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
		{
			r1 = r1 + r2;
			r2 = r1 - r2;
		}
		else
		{
			r2 = r1;
		}
	}
	return r1;
}

//lt 75 sort colors
// @taobupt

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/
void sortColors(vector<int>& nums) {
	int begin = 0, right = nums.size()-1, cur = 0;
	while (cur <=right)//very important, compare it with binary search
	{
		if (nums[cur] == 0)swap(nums[cur++], nums[begin++]);
		else if (nums[cur] == 2)swap(nums[cur], nums[right--]);
		else cur++;
	}
}

void countSort(vector<int>nums)
{
	int maxValue = 0;
	for (int x : nums)maxValue = max(maxValue, x);
	vector<int>B(nums.size(), 0);
	vector<int>C(maxValue + 1, 0);
	for (int x : nums)C[nums[x]]++;
	for (int i = 1; i <= maxValue; ++i)C[i] += C[i - 1];
	for (int i =nums.size()-1; i >= 0; --i)
	{
		B[--C[nums[i]]] = nums[i];
	}
	for (int x : B)cout << x << endl;
}

//139 word break
// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
/*
For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
bool wordBreak(string s, unordered_set<string>& wordDict) {
	int n = s.size();
	vector<bool>dp(n + 1, false);
	dp[0] = true;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end())
			{
				dp[i] = true;// rember to break to acclerate
				break;
			}
		}
	}
	return dp[n];
}

// use bfs

bool wordBreak(string s, unordered_set<string>& wordDict) {
	unordered_map<int, bool>visit;
	queue<int>q;
	q.push(0);
	while (!q.empty())
	{
		int start = q.front();
		q.pop();
		if (!visit[start])
		{
			visit[start] = true;
			for (int j = start; j < s.size(); ++j)
			{
				string substr = s.substr(start, j - start + 1);
				if (wordDict.find(substr) != wordDict.end())
				{
					q.push(j + 1);
					if (j + 1 == s.size())return true;
				}
			}
		}
	}
	return false;
}


//lt 15 3sum
//@taobupt
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>>res;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < n; ++i)
	{
		if (i>0 && nums[i] == nums[i - 1])continue;
		int begin = i + 1, end = n - 1;
		while (begin < end)
		{
			int sum = nums[i] + nums[begin] + nums[end];
			if (sum == 0)
			{
				res.push_back({ nums[i], nums[begin++], nums[end--] });
				while (begin < end && nums[begin] == nums[begin - 1])begin++;
				while (begin < end && nums[end] == nums[end + 1])end--;
			}
			else if (sum < 0)begin++;
			else end--;
		}
	}
	return res;
}

// 341 flatten nested list iterator
//@taobupt

/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

// you can also use the vector to sotre all the data first, but it is space-comsuming

class NestedIterator{
public:
	NestedIterator(vector<NestedInteger>& nestedList)
	{
		int n = nestedList.size();
		for (int i = n - 1; i >= 0; --i)stk.push(nestedList[i]);
	}

	int next()
	{
		int val = stk.top().getInteger();
		stk.pop();
		return val;
	}
	bool hasNext()
	{
		while (!stk.empty())
		{
			NestedInteger cur = stk.top();
			if (cur.isInteger())return true;
			stk.pop();
			vector<NestedInteger>res = cur.getList();
			for (int i = res.size() - 1; i >= 0; --i)
			{
				stk.push(res[i]);
			}
		}
		return false;
	}

private:
	stack<NestedInteger>stk;
};


//98 validate bst
//@taobupt


/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
2
/ \
1   3
Binary tree [2,1,3], return true.
Example 2:
1
/ \
2   3
Binary tree [1,2,3], return false.
*/

TreeNode* pre = NULL;
bool isValidBST(TreeNode* root)
{
	if (root == NULL)return true;
	if (!isValidBST(root->left))return false;
	//if (pre == NULL)pre = root;
	if (pre && pre->val >= root->val)return false;
	pre = root;
	if (!isValidBST(root->right))return false;
	return true;
}


// none global variable
bool inorderBST(TreeNode* root, TreeNode*& pre)
{
	if (root == NULL)return true;
	if (!inorderBST(root->left, pre))return false;
	if (pre && pre->val >= root->val)return false;
	pre = root;
	return inorderBST(root->right, pre);
}
bool isValidBST1(TreeNode* root) {
	// the naive way is to store all of the number into vector,and check whether the 
	//vector is ordered;
	TreeNode* pre = NULL;
	return inorderBST(root, pre);
}


// 43 multiply strings

/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/

string multiply(string num1, string num2) {
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int  m = num1.size(), n = num2.size();
	vector<int>res(m+n,0);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0, idx = i; j < n; ++j)
		{
			res[idx++] += (num1[i] - '0')*(num2[j] - '0');
		}
	}
	int extra = 0;
	for (int i = 0; i < m + n; ++i)
	{
		extra += res[i];
		res[i] = extra % 10;
		extra /= 10;
	}
	string ans;
	for (int x : res)ans=to_string(x)+ans;// pay attention to the order;
	return ans;
}


//lt 133 clone graph

/*Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph{ 0, 1, 2#1, 2#2, 2 }.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
Visually, the graph looks like the following :

1
/ \
/ \
0 -- - 2
/ \
\_ /
*/

//@taobupt
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>mp;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL)return NULL;
	if (mp.find(node) == mp.end())
	{
		mp[node] = new UndirectedGraphNode(node->label);
		for (auto n : node->neighbors)
		{
			mp[node]->neighbors.push_back(cloneGraph(n));
		}
	}
	return mp[node];
}


// 78 subsets
/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
-*/
//@taobupt

void backtrackingSubsets(vector<vector<int>>&res, vector<int>& path, vector<int> nums,int cur)
{
	res.push_back(path);
	for (int i = cur; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		backtrackingSubsets(res, path, nums,i+1);
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	backtrackingSubsets(res, path, nums,0);
	return res;
}


// bitmap solution

vector<vector<int>> subsets(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int num_subset = pow(2, nums.size());
	vector<vector<int>>res(num_subset, vector<int>());
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < num_subset; ++j)
		{
			if ((j >> i) & 0x1)
			{
				res[j].push_back(nums[i]);
			}
		}
	}
	return res;
}


//iterative
vector<vector<int>> subsets(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>>subs(1, vector<int>());
	for (int i = 0; i < nums.size(); ++i)
	{
		int n = subs.size();
		for (int j = 0; j < n; ++j)
		{
			subs.push_back(subs[j]);
			subs.back().push_back(nums[i]);
		}
	}
	return subs;

}




//lt 90 subsetsII
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.
*/

//@taobupt


void backtrackingSubsetsWithDup(vector<vector<int>>&res, vector<int>& path, vector<int> nums, int cur)
{
	res.push_back(path);
	for (int i = cur; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		backtrackingSubsetsWithDup(res, path, nums, i + 1);
		while (i<(int)nums.size()-1 && nums[i] == nums[i + 1])i++;// vector<vector<int>> subsets(vector<int>& nums) is a usually way to handle this
		path.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	sort(nums.begin(), nums.end());
	backtrackingSubsetsWithDup(res, path, nums, 0);
	return res;
}

//iterative
vector<vector<int>> subsetsWithDupIterative(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>subs(1, vector<int>());
	int startIndex = 0, n = 0;;
	for (int i = 0; i < nums.size(); ++i)
	{
		startIndex = i >= 1 && nums[i] == nums[i - 1] ? n : 0;
		n = subs.size();
		for (int j = startIndex; j < n; ++j)
		{
			subs.push_back(subs[j]);
			subs.back().push_back(nums[i]);
		}
	}
	return subs;
}

//277 lt find the celebrity

bool knows(int a, int b);
int findCelebrity(int n)
{
	int c = 0;
	for (int i = 1; i < n; ++i)
	{
		if (knows(c, i))c = i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (i != c && (knows(c, i) || !knows(i, c)))return -1;
	}
	return c;
}


// lt 236 lowest Comon Ancestor of a binary tree
//@ taobupt

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

_______3______
/              \
___5__          ___1__
/      \        /      \
6      _2       0       8
/  \
7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == root || q == root)return root;
	TreeNode* left = lowestCommonAncestorBT(root->left, p, q);
	TreeNode* right = lowestCommonAncestorBT(root->right, p, q);
	if (left && right)return root;
	return left ? left : right;
}

//dfs

void dfs236(TreeNode* root, TreeNode* p, vector<TreeNode*>& v, vector<TreeNode*>& res)
{
	if (root == p)
	{
		for (auto node : v)res.push_back(node);// why? because v will always change, so we should use another vector to store.
		return;
	}
	else
	{
		if (root->left)
		{
			v.push_back(root->left);
			dfs236(root->left, p, v, res);
			v.pop_back();
		}
		if (root->right)
		{
			v.push_back(root->right);
			dfs236(root->right, p, v, res);
			v.pop_back();
		}
	}
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL || root == p || root == q)return root;
	vector<TreeNode*>pNode;
	vector<TreeNode*>qNode;
	vector<TreeNode*>path;
	path.push_back(root);
	dfs236(root, p, path, pNode);
	path.clear();
	path.push_back(root);
	dfs236(root, q, path, qNode);
	int i = 0; 
	for (int i = 0; i < pNode.size() && i < qNode.size();++i)
	{
		if (pNode[i] != qNode[i])break;
	}
	return pNode[i - 1];
}


//bfs

vector<TreeNode*>stkToVector(stack<TreeNode*>stk)
{
	vector<TreeNode*>res;
	while (!stk.empty())
	{
		res.push_back(stk.top());
		stk.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

TreeNode* lowestCommonAncestorBTIterative(TreeNode* root, TreeNode* p, TreeNode* q)
{
	stack<TreeNode*>stk;
	vector<TreeNode*>pv;
	vector<TreeNode*>qv;
	if (root == NULL)return NULL;
	unordered_map<TreeNode*, bool>vis;
	stk.push(root);
	vis[root] = true;
	TreeNode* node = NULL;
	while (!stk.empty())
	{
		node = stk.top();
		if (node->left && !vis[node->left])
		{
			vis[node->left] = true;
			stk.push(node->left);
			if (node->left == p)
			{
				pv = stkToVector(stk);
				if (!qv.empty())break;
			}
			if (node->left == q)
			{
				qv = stkToVector(stk);
				if (!pv.empty())break;
			}
			continue;
		}
		if (node->right && !vis[node->right])
		{
			vis[node->right] = true;
			stk.push(node->right);
			if (node->right == p)
			{
				pv = stkToVector(stk);
				if (!qv.empty())break;
			}
			if (node->right == q)
			{
				qv = stkToVector(stk);
				if (!pv.empty())break;
			}
		}
		stk.pop();// beaceus it is a tree, is you pop_back() right now,then you can not reach the right child;
	}
	int i = 0;
	int n = min(pv.size(), qv.size());
	for (; i < n; ++i)
	{
		if (pv[i] != qv[i])break;
	}
	return i >= 1 ? pv[i - 1] : NULL;
}

// 49 group anagrams
// @taobupt

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>res;
	unordered_map<string, int>mp;
	string sub;
	vector<string>inner;
	for (string s : strs)
	{
		sub = s;
		sort(sub.begin(), sub.end());
		if (mp.find(sub) == mp.end())
		{
			inner.clear();
			inner.push_back(s);
			mp[sub] = res.size();
			res.push_back(inner);
		}
		else res[mp[sub]].push_back(s);
	}
	return res;
}

// you can use multiset
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string, multiset<string>>mp;
	for (string s : strs)
	{
		string t = s;
		sort(t.begin(), t.end());
		mp[t].insert(s);
	}
	vector<vector<string>>anagrams;
	for (auto m : mp)
	{
		vector<string>anagram(m.second.begin(), m.second.end());
		anagrams.push_back(anagram);
	}
	return anagrams;
}


//238 product of array except self
//@taobupt

/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int>forwa(n,1);
	vector<int>back(n, 1);
	for (int i = 1; i < n; ++i)
	{
		forwa[i] = forwa[i - 1] * nums[i-1];
		back[n - 1 - i] = back[n - i] * nums[n - i];
	}
	for (int i = 0; i < n; ++i)
	{
		nums[i] = forwa[i] * back[i];
	}
	return nums;
}

//follow up

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int>res(n, 1);
	for (int i = 1; i < n; ++i)
	{
		res[i] = res[i - 1] * nums[i - 1];
	}
	int right = 1;
	for (int i = n-1; i >=0; --i)
	{
		res[i]*=right;// do not knwo how to do. I want to pratce as much as possible
		right *= nums[i];
	}
	return res;
}

// 69 sqrt(x)
// implement int sqrt(int x)
int mySqrt(int x) {
	if ( x==1||x==0)return x;
	int left = 0, right = x,mid=0;
	while (left < right)
	{
		mid = left + (right - left) / 2;//46340 is the largest;
		if (mid > 46340)
		{
			right = mid;
			continue;
		}
		long long sum = mid*mid;
		if (sum <= x && x < (sum + 2 * mid + 1))return mid;
		else if (sum>x)right = mid;
		else if (sum < x)left=mid + 1;
	}
	return INT_MIN;
}
// instead of long long
int mySqrt(int x) {
	if (x == 1 || x == 0)return x;
	int left = 0, right = x, mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;//46340 is the largest;
		if (mid > 46340)
		{
			right =46341;// can acclerate ,46340 would lead error
			continue;
		}
		if ( mid<= x/mid && x/(mid+1)<mid+1)return mid;
		else if (mid>x/mid)right = mid;
		else if (mid<x/mid)left = mid + 1;
	}
	return INT_MIN;
}


//newton
int sqrt(int x) {
	double ans = x;
	double delta = 0.0001;
	while (fabs(ans*ans - x) > delta) {
		ans = (ans + x / ans) / 2;
	}
	return ans;
}


//207 course schedule
//@taobupt
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

bool canFinish(int num, vector<pair<int, int>>& prerequisites) {
	vector<int>indegree(num, 0);
	queue<int>q;
	list<int>* adj = new list<int>[num];
	for (int i = 0; i < (int)prerequisites.size(); ++i)
	{
		adj[prerequisites[i].second].push_back(prerequisites[i].first);
		++indegree[prerequisites[i].first];
	}
	for (int i = 0; i < num; ++i)if (indegree[i] == 0)q.push(i);
	int count = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		count++;
		for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
		{
			if (--indegree[*it] == 0)q.push(*it);
		}
	}
	delete []adj;
	return count == num;
}


// 210 course scheule II
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
*/

//@taobupt

vector<int> findOrder(int num, vector<pair<int, int>>& prerequisites)
{
	queue<int>q;
	list<int>* adj = new list<int>[num];
	vector<int>indgree(num, 0);
	for (int i = 0; i < (int)prerequisites.size(); ++i)
	{
		adj[prerequisites[i].second].push_back(prerequisites[i].first);
		++indgree[prerequisites[i].first];
	}
	for (int i = 0; i < num; ++i)if (indgree[i] == 0)q.push(i);
	int cnt = 0, node = 0;
	vector<int>res;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		cnt++;
		res.push_back(node);
		for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
		{
			if (--indgree[*it] == 0)q.push(*it);
		}
	}
	if (cnt == num)return res;
	else return{};
}


//dfs way


//lt 274 H-index
/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/


//@taobupt

int hIndex(vector<int>& citations)
{
	int n = citations.size();
	vector<int>res(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		if (citations[i] >= n)res[n]++;
		else res[citations[i]]++;
	}
	int sum = 0;
	for (int i = n; i >= 0; --i)// it is possible that it would be n
	{
		sum += res[i];
		if (sum >= i)return i;
	}
	return 0;
}



//Just binary search, each time check citations[mid]
//case 1: citations[mid] == len - mid, then it means there are citations[mid] papers that have at least citations[mid] citations.
//case 2: citations[mid] > len - mid, then it means there are citations[mid] papers that have moret than citations[mid] citations, so we should continue searching in the left half
//case 3: citations[mid] < len - mid, we should continue searching in the right side
//After iteration, it is guaranteed that right + 1 is the one we need to find(i.e.len - (right + 1) papars have at least len - (righ + 1) citations)
//follow up
int hIndexII(vector<int>& citations)
{
	int left = 0, len = citations.size(), right = len - 1,mid = 0;
	while (left <=right)
	{
		mid = left + (right - left) / 2;
		if (citations[mid] >= (len - mid))right = mid - 1;
		else left = mid + 1;
	}
	return len - left;
}




