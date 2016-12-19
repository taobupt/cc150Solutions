#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<cctype>
#include<cmath>
#include<stdio.h>
#include<map>
#include<functional>
#include<stack>
#include<sstream>
#include<string>
#include<cassert>
#include<regex>
#include<functional>
using namespace std;

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

int strStr(string haystack, string needle) {
	int m = haystack.length(), n = needle.length();
	if (!n) return 0;
	for (int i = 0; i < m - n + 1; i++) {
		int j = 0;
		for (; j < n; j++)
			if (haystack[i + j] != needle[j])
				break;
		if (j == n) return i;
	}
	return -1;
}



//kmp algorithms 
//O(m + n)
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (!n) return 0;
		vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < m;) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			if (j == n) return i - j;
			if (i < m && haystack[i] != needle[j]) {
				if (j) j = lps[j - 1];
				else i++;
			}
		}
		return -1;
	}
private:
	vector<int> kmpProcess(string& needle) {
		int n = needle.length();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n;) {
			if (needle[i] == needle[len])
				lps[i++] = ++len;
			else if (len) len = lps[len - 1];
			else lps[i++] = 0;
		}
		return lps;
	}
};


//follow up
//anagrams
//strstrpermutation
//stsrstr permutation
vector<int> findAnagrams(string haystack, string needle) {
	vector<int>res;
	if (haystack.empty() || needle.empty())return res;
	int m[256] = { 0 };
	for (char c : needle)m[c]++;
	int left = 0, right = 0, count = needle.size();
	while (right < haystack.size())
	{
		if (m[haystack[right++]]-- >0)count--;
		if (count == 0)res.push_back(left);
		if (right - left == needle.size() && ++m[haystack[left++]]>0)count++;
	}
	return res;
}

// if you want to find the first index just return when count=0
int findAnagrams(string haystack, string needle) {
	int res;
	if (haystack.empty() || needle.empty())return res;
	int m[256] = { 0 };
	for (char c : needle)m[c]++;
	int left = 0, right = 0, count = needle.size();
	while (right < haystack.size())
	{
		if (m[haystack[right++]]-- >0)count--;
		if (count == 0)
		{
			res = left;
			break;
		}
		if (right - left == needle.size() && ++m[haystack[left++]]>0)count++;
	}
	return res;
}


//using hashmap
// use different methods with window
int strstrPermutation(string haystack, string needle)
{
	unordered_map<char, int>letterTocount;
	for (char letter : needle)letterTocount[letter]++;
	for (int i = 0; i < haystack.size(); ++i)
	{
		if (letterTocount.find(haystack[i]) != letterTocount.end())
		{
			unordered_map<char, int>tmp = letterTocount;
			int j = i;
			while (j < haystack.size())
			{
				char letter = haystack[j];
				if (tmp.count(letter))
				{
					tmp[letter]--;
				}
				else break;
				if (tmp[letter] == 0)tmp.erase(letter);
				if (tmp.empty())return i;
				j++;
			}
			if (j == haystack.size())return -1;//interseting
		}
	}
	return -1;
}
// follow up
//two dimension array

int strStr(vector<vector<char>>& haystack, string needle)
{
	int total = 0;
	int m = haystack.size(), n = haystack[0].size();
	for (int row = 0; row < m; ++row)
	{
		for (int col = 0; col < haystack[row].size(); ++col)
		{
			int k = 0;// the match length of needle
			int posRow = row;
			int posCol = col;
			while ((posRow < m && posCol <haystack[row].size()) && k < needle.size() && haystack[posRow][posCol] == needle[k])
			{
				k++;
				posCol++;
				if (posCol == haystack[row].size())
				{
					posCol = 0;
					posRow++;
				}
			}
			if (k == needle.size())return total + col - 1;
		}
		total += haystack[row].size();
	}
	return -1;
}
//41 First Missing Positive
////each num is at most visited twice, so O(n) time

//most optimal
//
//Put each number in its right place.

//For example :

//When we find 5, then swap it with A[4].

//At last, the first place where its number is not right, return the place + 1
//We visit each number once, and each number will be put in its right place at most once, so it is O(n) + O(n).
int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i<n; ++i)
	{
		while (nums[i]>0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])swap(nums[nums[i] - 1], nums[i]);
	}
	for (int i = 0; i<n; ++i)
	{
		if (nums[i] != i + 1)return i + 1;
	}
	return n + 1;
}

//my self solution, but extra space
int firstMissingPositive(vector<int>& nums) {
	int le = INT_MIN;
	if (nums.size() == 0)return 1;
	for (int kk = 0; kk<nums.size(); ++kk)
	{
		le = max(le, nums[kk]);
	}
	vector<int>v(le + 1, INT_MIN);
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] <= 0)v[0] = 0;
		else v[nums[i]] = nums[i];
	}
	for (int i = 1; i <= nums.size(); ++i)
	{
		//if (nums[i]<0)continue;
		if (v[i] != i)return i;// find the first positive 
	}
	return nums.size() + 1;
}

// you can also use sort and then binary search

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

// iterative
// O(smallest depth of a and b) time, instead of O(num of nodes in tree)
// O(1) space, instead of O(height of tree)

// recursive O(smallest depth of a and b) space
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
	dfsLevelOrder(root->left, res, level + 1);
	dfsLevelOrder(root->right, res, level + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
	int depth = maxDepth(root);
	vector<vector<int>>res(depth);
	if (res.empty())return res;
	dfsLevelOrder(root, res, 0);
	return res;
}

//dfs(pre order) O(n) time and O(h) space
void dfs(vector<vector<int>>& res, int level, TreeNode* root)
{
	if (root == NULL)return;
	if (res.size() == level)res.push_back({});
	res[level].push_back(root->val);
	dfs(res, level + 1, root->left);
	dfs(res, level + 1, root->right);
}
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>>res;
	if (root == NULL)return res;
	dfs(res, 0, root);
	return res;
}



//lt 26 removeDuplicates from sorted array
//@taobupt
//remove duplicates

/*
Given an integer array which has the property that all the elements having same value are adjacent to each other.
e,g,  {2, 2, 2, 1, 5, 6, 6, ,7, ,7}
*/
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


//
//The time complexity for the problem should be O(n), since we are basically visiting each node in the tree.Yet an interviewer might ask you for further 
//optimization when he or she saw a string concatenation.A string concatenation is just too costly.A StringBuilder can be used although a bit tricky since it is not immutable like string is.
//When using StringBuilder, We can just keep track of the length of the StringBuilder before we append anything to it before recursion and afterwards set the length back.Another trick is when to append the "->", 
//since we don't need the last arrow at the end of the string, we only append it before recurse to the next level of the tree. Hope the solution helps!
void dfsBinaryTreePaths(TreeNode* root, vector<string>& res, string path)
{
	if (root->left == NULL && root->right == NULL)
	{
		path += to_string(root->val);
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


// itreative
//visit all nodes; you can also use a hash map to store its parent node;// or print path
vector<string>findPath(TreeNode* root)
{
	vector<string>result;
	if (root == NULL)return result;
	stack<pair<TreeNode*, string>>stk;
	stk.push(make_pair(root, ""));
	while (!stk.empty())
	{
		TreeNode* node = stk.top().first;
		string path = stk.top().second + "->" + to_string(node->val);
		stk.pop();
		if (node->left == NULL && node->right == NULL)
		{
			result.push_back(path.substr(2));
		}
		if (node->left)stk.push(make_pair(node->left, path));
		if (node->right)stk.push(make_pair(node->right, path));
	}
	return result;
}

// if we cannot use dfs(which is easy for printing paths), then use bfs, use hashmap to store parent-to-children paths
public class Solution {
	public void binaryTreePaths(TreeNode root) {
		List<String> res = new ArrayList<>();
		if (root == null) {
			return res;
		}
		HashMap<TreeNode, TreeNode> map = new HashMap<>();
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		map.put(root, null);
		while (!queue.isEmpty()) {
			TreeNode curr = queue.poll();
			if (curr.left == null && curr.right == null) {
				String path = getPath(map, curr);//if you only want to print paths, we can use recursion here
				res.add(path);
			}
			if (curr.left != null) {
				map.put(curr.left, curr);
				queue.offer(curr.left);
			}
			if (curr.right != null) {
				map.put(curr.right, curr);
				queue.offer(curr.right);
			}
		}
		return res;
	}

	private String getPath(HashMap<TreeNode, TreeNode> map, TreeNode node) {
		StringBuilder sb = new StringBuilder();
		while (node != null) {//from leaf to root
			sb.append(node.val + ">-");
			node = map.get(node);
		}
		return sb.reverse().toString().substring(2);
	}
}


// iterative (bfs), use queue to store ArrayList<TreeNode>, which is the path
public class Solution {
	public List<String> binaryTreePaths(TreeNode root) {
		List<String> res = new ArrayList<>();
		if (root == null) {
			return res;
		}
		Queue<ArrayList<TreeNode>> queue = new LinkedList<>();
		queue.offer(new ArrayList<>(Arrays.asList(root)));
		while (!queue.isEmpty()) {
			ArrayList<TreeNode> path = queue.poll();
			TreeNode curr = path.get(path.size() - 1);
			if (curr.left == null && curr.right == null) {
				StringBuilder sb = new StringBuilder();
				for (TreeNode node : path) {
					sb.append(node.val + "->");
				}
				sb.setLength(sb.length() - 2);//it's void type !!!
				res.add(sb.toString());
				continue;
			}
			if (curr.left != null) {
				ArrayList<TreeNode> newPath = new ArrayList<>(path);
				newPath.add(curr.left);
				queue.offer(newPath);
			}
			if (curr.right != null) {
				ArrayList<TreeNode> newPath = new ArrayList<>(path);
				newPath.add(curr.right);
				queue.offer(newPath);
			}
		}
		return res;
	}
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

//88 merge sorted array;
// @taobupt

//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

//Note:
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.The number of elements initialized in nums1 and nums2 are m and n respectively.

//save space;
//o(M+N)

//waste space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int>nums(nums1.begin(), nums1.begin() + m);// we first copy first m nums1's data to a new array
	int i = 0, k = 0, j = 0;
	while (i<m && j<n)
	{
		if (nums[i] <= nums2[j])nums1[k++] = nums[i++];
		else nums1[k++] = nums2[j++];
	}
	if (i == m)while (j < n)nums1[k++] = nums2[j++];
	else while (i < m)nums1[k++] = nums[i++];
}


//better solution
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int k = m + n - 1;
	int i = m - 1;
	int j = n - 1;
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
		res = char((n - 1) % 26 + 'A') + res;
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

// moveZero to front, moveOne to back, maintain the order of other non-zero and non-one elements
public class Solution {
	public void moveZeroes(int[] nums) {
		if (nums == null || nums.length == 0) {
			return;
		}

		int insert = 0;
		for (int i = 0; i < nums.length; i++) {//move all non-one to front
			if (nums[i] != 1) {
				nums[insert++] = nums[i];
			}
		}
		int temp = insert - 1;//save the position before all one
		while (insert < nums.length) {//fill one to back
			nums[insert++] = 1;
		}

		insert = temp;//skip all one at the back
		for (int i = insert; i >= 0; i--) {//move all non-zero to center (start from index before all one)
			if (nums[i] != 0) {
				nums[insert--] = nums[i];
			}
		}
		while (insert >= 0) {//fill zero to front
			nums[insert--] = 0;
		}
	}
}

// 67 add binary 
//@taobupt

//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".


//O(a.size()+b.size())
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

//follow up
string addbinaryK(vector<string>res)
{
	while (res.size() >= 2)
	{
		string a = res.back();
		res.pop_back();
		string b = res.back();
		res.pop_back();
		res.push_back(addBinaryBetter(a, b));
	}
	return res.size() == 1 ? res[0] : "";
}

// not using +-*/.just bit manipulation
string addBinary(string a, string b) {
	string s;
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || c)
	{
		int num1 = i >= 0 ? a[i--] - '0' : 0;
		int num2 = j >= 0 ? b[j--] - '0' : 0;
		int sum = c^num1^num2;//current digits
		s = char(sum + '0') + s;
		c = (num1&num2) | (num1&c) | (num2&c);
	}
	return s;
}

// 16 jinzhi
string addBinaryBetter(string a, string b)
{
	string s;
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	unordered_map<int, char>mp = { { 10, 'A' }, { 11, 'B' }, { 12, 'C' }, { 13, 'D' }, { 14, 'E' }, { 15, 'F' } };
	while (i >= 0 || j >= 0 || c)
	{
		c += i >= 0 ? a[i] <= '9' ? a[i] - '0' : a[i] - 'A' + 10 : 0;
		c += j >= 0 ? b[j] <= '9' ? b[j] - '0' : b[j] - 'A' + 10 : 0;
		i--;
		j--;
		s = (c % 16<10 ? char(c % 16 + '0') : mp[c % 16]) + s;
		c /= 16;
	}
	return s;
}


//125 valid palindrome
//@taobupt

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/


bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i<j)
	{
		while (i<j && !isalnum(s[i]))i++;
		while (i<j && !isalnum(s[j]))j--;
		if (tolower(s[i++]) != tolower(s[j--]))return false;
	}
	return true;
}
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
bool isPalindrome(string s)
{
	int n = s.size();
	for (int i = 0, j = n - 1; i < j; i++, j--)
	{
		while (!isalnum(s[i]) && i < j)i++;
		while (!isalnum(s[j]) && i < j)j--;
		if(tolower(s[i]) != tolower(s[j]))return false;
	}
	return true;
}


// lt 157 157. Read N Characters Given Read4
/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
*/

//No, you don't have to take care of this.
//The only thing is when you call read4() which reads 4 bytes into your buffer you might read more than you need, 
//so you want to store those bytes in the structure, and next time you call read will start from those stored bytes, then read more from the file.

//Think that you have 4 chars "a, b, c, d" in the file, and you want to call your function twice like this:

//read(buf, 1); // should return 'a'
//read(buf, 3); // should return 'b, c, d'
//All the 4 chars will be consumed in the first call.So the tricky part of this question is how can you preserve the remaining 'b, c, d' to the second call.



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

class Solution{
public:
	Solution() :buffCnt(0), buffPtr(0){}
	int read(char* buf, int n)
	{
		int cnt = 0;
		while (cnt < n)
		{
			if (buffPtr == 0)buffCnt = read4(buff);
			if(buffCnt == 0)break;
			while (cnt < n && buffPtr < buffCnt)
			{
				buf[cnt++] = buff[buffPtr++];
			}
			if (buffPtr == buffCnt)buffPtr = 0;
		}
		return cnt;
	}
private:
	char buff[5];
	int buffCnt;
	int buffPtr;
};


int read4k(char* buf);
int read(char *buf, int n)
{
	char content[4096];
	int count = 0;
	bool hasNext = true;
	while (hasNext && count < n)
	{
		int readLength = read4k(content);
		if (readLength < 4096)hasNext = false;
		for (int i = 0; i < readLength && count < n; ++i)
		{
			buf[count++] = content[i];
		}
	}
	return count;
}

char content[4096];
int haveRead = 0;
int index = 0;
int read(char* buf, int n)
{
	int count = 0;
	bool hasNext = true;
	while (hasNext && count < n)
	{
		if (index == 0)haveRead = read4k(content);
		if (haveRead < 4096)hasNext = false;
		while (count < n && index < haveRead)
		{
			buf[count] = content[index];
			count++;
			index++;
		}
		if (index == haveRead)index = 0;
	}
	return count;
}




// medium ----


//@taobupt

//50 Implement pow(x, n).

//explaination
2 ^ 10
= (2 * 2) * (2 * 2) * (2 * 2) * (2 * 2) * (2 * 2)
= 4 ^ 5    // here power has become odd, so lets take out one 4 out of five 4's & multiply it with 'result' & store back in 'result' & hence we are left with four 4's

So result = 4 and we are left with 4 ^ 4

4 ^ 4
= (4 * 4) * (4 * 4)
= 16 ^ 2 // since power is even no need to mess up our result variable

16 ^ 2
= 256 ^ 1 // here power has become odd, so lets take out one 256 & multiply it with 'result' & store back in 'result' hence we are left with zero 256's
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
	return negative ? 1.0 / res : res;
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

//In bit format and for a unsigned number, the number is represented as 
//k0 * 2 ^ 0 + k1 * 2 ^ 1 + ... + k31 * 2 ^ 31. Therefore, once we know the pow(x, 2 ^ 0), pow(x, 2 ^ 1),
//..., pow(x, 2 ^ 31), we can get pow(x, n).And pow(x, 2 ^ m) can be constructed easily as pow(x, 2 ^ m)
//= pow(x, 2 ^ (m - 1)*pow(x, 2 ^ (m - 1).

double pow(double x, int n) {
	if (n<0){
		x = 1.0 / x;
		n = -n;
	}
	int unsigned m = n;
	double tbl[32] = { 0 };
	double result = 1;
	tbl[0] = x;
	for (int i = 1; i<32; i++){
		tbl[i] = tbl[i - 1] * tbl[i - 1];
	}
	for (int i = 0; i<32; i++){
		if (m & (0x1 << i))
			result *= tbl[i];
	}
	return result;
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

//if have to implement the all(),then we 'd better write the below code
class BSTIterator{
private:
	stack<TreeNode*>stk;//O(h) space
	TreeNode* cur;
public:
	BSTIterator(TreeNode* root)
	{
		cur = root;
	}

	bool hasNext()
	{
		if (cur != nullptr || !stk.empty())return true;
		else return false;
	}

	int next()//amortized O(1) time
	{
		while (cur)
		{
			stk.push(cur);
			cur = cur->left;
		}
		cur= stk.top();
		stk.pop();
		int val = cur->val;
		cur = cur->right;//remember this
		return val;
	}

	vector<int>all()
	{
		vector<int>res;
		while (cur != nullptr || !stk.empty())
		{
			while (cur != nullptr)
			{
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}
		return res;
	}
}


// bsts iterator
struct cmp{
	bool operator()(BSTIterator  it1, BSTIterator it2)
	{
		return it1.next() > it2.next();
	}
};

class BSTIterators{
public:
	BSTIterators(vector<BSTIterator>vv)
	{
		for (int i = 0; i < vv.size(); ++i)
		{
			if (vv[i].hasNext())pq.push(vv[i]);
		}
	}
	bool hasnext()
	{
		return !pq.empty();
	}
	int next()
	{
		BSTIterator it = pq.top();
		pq.pop();
		int val = it.next();
		if (it.hasNext())pq.push(it);
		return val;
	}
private:
	priority_queue<BSTIterator, vector<BSTIterator>, cmp>pq;
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
	vector<int>all()
	{
		vector<int>res;
		while (!stk.empty())
		{
			TreeNode* node = stk.top();
			stk.pop();
			res.push_back(node->val);
			if (node->right)stk.push(node->right);
			if (node->left)stk.push(node->left);
		}
		return res;
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
	vector<int>all()
	{
		vector<int>res;
		while (!stk.empty())
		{
			TreeNode* curr = stk.top();
			stk.pop();
			if (!stk.empty())
			{
				TreeNode* top = stk.top();
				if (curr == top->left)findNextLeaf(top->right);
			}
			res.push_back(curr->val);
		}
		return res;
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
// decodeways 91
//decode way
//interesting ,http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=146032&fromuid=109727

//O(n sapce)
int numDecodings(string s) {
	int n = s.size();
	if (s.empty() || s[0] == '0')return 0;// attention here, otherwise wa;
	vector<int>dp(n + 1, 0);
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] > '2'))return 0;
		else if (s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2'))dp[i + 1] = dp[i - 1];
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' &&s[i] <= '6'))dp[i + 1] = dp[i] + dp[i - 1];
		else dp[i + 1] = dp[i];
	}
	return dp[n];
}

// actually you can change it into O(1) space;

int numDecodingsSaveSpace(string s)
{
	if (s.empty() || s[0] == '0')return 0;
	int n = s.size();
	int r1 = 1, r2 = 1;// r2:decode ways of s[i-2],r1:decodes ways of s[i-1];
	for (int i = 1; i < n; ++i)
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
// dfs O(n) time O(n) stack space
// check every 1 or 2 chars, if can be a double, skip 1 or 2 chars and solve the rest; else,skip 1 char and solve the rest
// if string the first char is '0', directly return 0
public class Solution {
	public int numDecodings(String s) {
		if (s == null || s.length() == 0) {//if the initial string is empty, return 0 !!! not 1 !!!
			return 0;
		}
		return helper(s, 0);
	}

	private int helper(String s, int index) {
		if (s.length() == index) {//if the whole string has been decoded, return 1
			return 1;
		}
		if (s.charAt(index) == '0') {
			return 0;
		}
		if (s.length() - 1 > index && isValidDouble(s.substring(index, index + 2))) {//if it can, there will be two ways of decoding curr substring
			return helper(s, index + 1) + helper(s, index + 2);
		}
		else {//there is only one way to decode
			return helper(s, index + 1);
		}
	}

	private boolean isValidDouble(String s) {//check whether the 2 chars can form a valid two digit number
		return s.charAt(0) == '1' || (s.charAt(0) == '2' && s.charAt(1) <= '6' && s.charAt(1) >= '0');
	}
}

// get all possible solutions
bool isValidDouble(string s)
{
	return s[0] == '1' || (s[0] == '2' && s[1] <= '6' && s[1] >= '0');
}
void numDecoding(vector<string>&res, string s, string path, int pos)
{
	if (pos == s.size())
	{
		res.push_back(path);
		return;
	}
	if (s[pos] == '0')return;
	//first way of decoding by 1-digit num
	int num1 = stoi(s.substr(pos, 1));
	numDecoding(res, s, path + char('A' + num1 - 1), pos + 1);
	if (s.size() - 1 > pos && isValidDouble(s.substr(pos, 2)))
	{
		int num2 = stoi(s.substr(pos, 2));
		numDecoding(res, s, path + char('A' + num2 - 1), pos + 2);
	}
}
vector<string>numDecodings(string s)
{
	vector<string>res;
	if (s.empty() || s[0] == '0')return res;
	string path;
	numDecoding(res, s, path, 0);
	return res;
}

// if A to Z should be can decoded by 0 to 25? then we don't need to separately consider the case 0
// O(1) space dp solution
public class Solution {
	public int numDecodings(String s) {
		if (s == null || s.length() == 0 || s.charAt(0) == '0') {//remember to add s.charAt(0)=='0' !!!eg."0" should return 0
			return 0;
		}
		int c1 = 1;//decode ways of s[i-1]
		int c2 = 1;//decode ways of s[i-2]
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) <= '5')) {
				c1 = c1 + c2;//if s.charAt(i) and s.charAt(i-1) can work together as a digit, update c1 to c1+c2
				c2 = c1 - c2;//update c2 to previous c1
			}
			else {//if s.charAt(i) can only work as a single digit,no new decode ways are added,eg.12 has 2 ways,123 is same
				c2 = c1;//c1 = c1 is omitted, update c2 = c1
			}
		}
		return c1;
	}
}
// O(n) space dp solution
public class Solution {
	public int numDecodings(String s) {
		if (s == null || s.length() == 0) {
			return 0;
		}
		int n = s.length();
		int[] dp = new int[n + 1];//num of ways of decoding s.substring(0, i)
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			int first = Integer.valueOf(s.substring(i - 1, i));
			int second = Integer.valueOf(s.substring(i - 2, i));
			if (first >= 0 && first <= 9) {//can form a one-digit num
				dp[i] += dp[i - 1];
			}
			if (second >= 10 && second <= 25) {//can form a two-digit num
				dp[i] += dp[i - 2];
			}
		}
		return dp[n];
	}
}

// dfs O(n) time O(n) stack space
// check every 1 or 2 chars, if can be a double, skip 1 or 2 chars and solve the rest; else,skip 1 char and solve the rest
public class Solution {
	public int numDecodings(String s) {
		if (s == null || s.length() == 0) {//if the initial string is empty, return 0 !!! not 1 !!!
			return 0;
		}
		return helper(s, 0);
	}

	private int helper(String s, int index) {
		if (s.length() == index) {//if the whole string has been decoded, return 1
			return 1;
		}
		if (s.length() - 1 > index && isValidDouble(s.substring(index, index + 2))) {//if it can, there will be two ways of decoding curr substring
			return helper(s, index + 1) + helper(s, index + 2);
		}
		else {//there is only one way to decode
			return helper(s, index + 1);
		}
	}

	private boolean isValidDouble(String s) {//check whether the 2 chars can form a valid two digit number
		return s.charAt(0) == '1' || (s.charAt(0) == '2' && s.charAt(1) <= '5' && s.charAt(1) >= '0');
	}
}

//return all decode ways:
public class Solution {
	public List<String> numDecodings(String s) {
		List<String> res = new ArrayList<>();
		if (s == null || s.length() == 0) {//if the initial string is empty, return 0 !!! not 1 !!!
			return res;
		}
		helper(res, s, new StringBuilder(), 0);
		return res;
	}

	private void helper(List<String> res, String s, StringBuilder path, int index) {
		if (s.length() == index) {//if the whole string has been decoded, return 1
			res.add(path.toString());
			return;
		}
		int length = path.length();
		int num1 = Integer.valueOf(s.substring(index, index + 1));
		path.append((char)('A' + num1 - 1));
		helper(res, s, path, index + 1);
		path.setLength(length);
		if (s.length() - 1 > index && isValidDouble(s.substring(index, index + 2))) {//if it can, there will be another way of decoding curr substring
			int num2 = Integer.valueOf(s.substring(index, index + 2));
			path.append((char)('A' + num2 - 1));
			helper(res, s, path, index + 2);
			path.setLength(length);
		}
	}

	private boolean isValidDouble(String s) {//check whether the 2 chars can form a valid two digit number
		return s.charAt(0) == '1' || (s.charAt(0) == '2' && s.charAt(1) <= '6' && s.charAt(1) >= '0');
	}
}

//lt 75 sort colors
// @taobupt

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/
void sortColors(vector<int>& nums) {
	int begin = 0, right = nums.size() - 1, cur = 0;
	while (cur <= right)//very important, compare it with binary search
	{
		if (nums[cur] == 0)swap(nums[cur++], nums[begin++]);
		else if (nums[cur] == 2)swap(nums[cur], nums[right--]);
		else cur++;
	}
}


// sortKcolor

void sortKcolor(vector<int>colors, int k)
{
	int left = 0;
	int right = colors.size() - 1;
	while (k)
	{
		int min1 = INT_MAX;
		int max1 = INT_MIN;
		for (int i = left; i <= right; ++i)
		{
			min1 = min(min1, colors[i]);
			max1 = max(max1, colors[i]);
		}
		int index = left;
		int minIndex = left;
		int maxIndex = right;
		while (minIndex < maxIndex && index <= maxIndex)
		{
			if (colors[index] == min1)
			{
				swap(colors[minIndex++], colors[index++]);
			}
			else if (colors[index] == max1)
			{
				swap(colors[index], colors[maxIndex--]);
			}
			else index++;
		}
		left = minIndex;
		right = maxIndex;
		k -= 2;
	}
	
}

//Solution 1:
//Count sort, 扫两遍即可，需要O(k)的空间
class Solution {
	public void sortColors2(int[] colors, int k) {
		int[] count = new int[k];
		for (int color : colors) {
			count[color - 1]++;
		}
		int index = 0;
		for (int i = 0; i < k; i++) {
			while (count[i]>0) {
				colors[index++] = i + 1;
				count[i]--;
			}
		}
	}
}

//用two pointers办法，每次只能sort出两端的两个数字，因此复杂度比较高O(k/2*n)
class Solution {
	public void sortColors2(int[] colors, int k) {
		int start = -1;
		int end = colors.length;
		for (int round = 1; round * 2 <= k; round++) {
			int leftColor = round;
			int rightColor = k - round + 1;
			for (int index = start + 1; index < end; index++) {
				if (colors[index] == leftColor) {
					colors[index] = colors[++start];
					colors[start] = leftColor;
				}
				else if (colors[index] == rightColor) {
					colors[index] = colors[--end];
					colors[end] = rightColor;
					index--;
				}
			}
		}
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
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		B[--C[nums[i]]] = nums[i];
	}
	for (int x : B)cout << x << endl;
}

//int getCategory(int n), outputs the category(1 to k) of given n
//sort k categories in descending order
public void sortKColors(int[] nums, int k) {//we assume input left is 0 and right is nums.length - 1
	if (nums == null || nums.length <= 1 || k <= 1) {
		return;
	}
	int left = 0;
	int right = nums.length - 1;
	int min = 1;
	int max = k;
	while (left < right) {
		int i = left;
		while (i <= right) {
			if (getCategory(nums[i]) == min) {
				swap(nums, i, left);
				left++;
				i++;
			}
			else if (getCategory(nums[i]) > min && getCategory(nums[i]) < max) {
				i++;
			}
			else {
				swap(nums, i, right);
				right--;
			}
		}
		min++;
		max--;
	}
}

//139 word break
// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
/*
For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

// recrusive way

bool wordBreak(string s, unordered_set<string>& wordDict) {
	if (s.empty())return true;
	for (int i = 1; i <= s.size(); ++i)
	{
		string sub = s.substr(0, i);
		if (wordDict.find(sub) != wordDict.end() && wordBreak(s.substr(i), wordDict))return true;
	}
	return false;
}

// iterative way
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


//output one path
//in this way , you can make dfs return true or false;
// or you can use parent array to record possible 

//O(C^K)=O((lengthOfString/dictWordLength)^lengthOfString)=O(dictWordLength^lengthOfString) time,O(lengthOfString) stack space
bool dfs(vector<string>& path,unordered_set<string>& dict,string input,int pos)
{
	if(index==input.size())
	{
		return true;
	}
	for(int i=pos;i<input.size();++i)
	{
		string word=input.substr(pos,i-pos+1);
		if(dict.find(word)!=dict.end())
		{
			path.push_back(word);
			if(dfs(path,dict,input,i+1))return true;
			path.pop_back();
		}
	}
	return false;
}
string wordBreakOnePath(unordered_set<string>& dict,string input)
{
	vector<string>path;
	dfs(path,dict,input,0);
	string res;
	for(string str:path)res+=str+" ";
	if(!res.empty())res.pop_back();
return res;
}

// all path  ,should use wordbreakI to acclerate this process
bool wordBreak1(string s, unordered_set<string>& wordDict) {
	//dp[i] stands s[0..i-1] in can be fomred by wordDict;
	int n = s.size();
	vector<int>dp(n+1,0);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (dp[j] && wordDict.find(s.substr(j,i-j)) != wordDict.end())
			{
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n];

}

    void dfs140(vector<string>&res, string path, string s, unordered_set<string>& wordDict, int cur)
{
	if (cur == s.size())
	{
		res.push_back(path);
		return;
	}
	else
	{
		for (int i = cur; i < s.size(); ++i)
		{
			string tmp = s.substr(cur, i + 1 - cur);
			if (wordDict.find(tmp) != wordDict.end() && wordBreak1(s.substr(i+1), wordDict))
			{
				if (!path.empty())
				{
					dfs140(res, path + " " + tmp, s, wordDict, i + 1);
				}
				else
				{
					dfs140(res, tmp, s, wordDict, i + 1);
				}
			}
		}
	}
}



vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<string>res;
	string path = "";
	if (wordBreak1(s, wordDict))
	{
		dfs140(res, path, s, wordDict, 0);
	}
	return res;
}


// better solution; from back to forward
class Solution {
	unordered_map<string, vector<string>> m;
	vector<string> combine(string word, vector<string> prev){
		for (int i = 0; i<prev.size(); ++i){
			prev[i] += " " + word;
		}
		return prev;
	}

public:
	vector<string> wordBreak(string s, unordered_set<string>& dict) {
		if (m.count(s)) return m[s]; //take from memory
		vector<string> result;
		if (dict.count(s)){ //a whole string is a word
			result.push_back(s);
		}
		for (int i = 1; i<s.size(); ++i){
			string word = s.substr(i);
			if (dict.count(word)){
				string rem = s.substr(0, i);
				vector<string> prev = combine(word, wordBreak(rem, dict));
				result.insert(result.end(), prev.begin(), prev.end());// insert all prev vector to result vector
			}
		}
		m[s] = result; //memorize
		return result;
	}
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
// sort and two pointers: O(n^2) time, O(1) space if not consider sorting's stack usage
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>>res;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < n-2; ++i)//i < nums.length if each num can be used for any times
	{
		if (i>0 && nums[i] == nums[i - 1])continue;////can be skipped if return boolean
		int begin = i + 1, end = n - 1;//start from i if each num can be used for any times
		while (begin < end)//left <= right if each num can be used for any times
		{
			int sum = nums[i] + nums[begin] + nums[end];
			if (sum == 0)//just return true below if return boolean
			{
				res.push_back({ nums[i], nums[begin++], nums[end--] });
				while (begin < end && nums[begin] == nums[begin - 1])begin++;//remember to skip dups after adding result
				while (begin < end && nums[end] == nums[end + 1])end--;//can be skipped if return boolean
			}
			else if (sum < 0)begin++;
			else end--;
		}
	}
	return res;
}


// hasmap
// hashtables without sort ): O(n^2) time, O(n) space
vector<vector<int>>threeSum(vector<int>input, int target)
{
	vector<vector<int>>result;
	unordered_set<vector<int>>visited;//use this to store keys of combinations of 3nums that have been added to res
	unordered_map<int, int>valueToIndex;
	for (int i = 0; i < input.size(); ++i)valueToIndex[input[i]] = i;
	for (int i = 0; i < input.size()-1; ++i)
	{
		int newTarget = target - input[i];
		for (int j = i + 1; j < input.size(); ++j)
		{
			if (valueToIndex.find(newTarget - input[j]) != valueToIndex.end())
			{
				int index = valueToIndex[newTarget - input[j]];
				if (index != j && index != i)
				{
					vector<int>pa{ input[i], input[j], input[index] };
					sort(pa.begin(), pa.end());
					if (visited.find(pa) != visited.end())
					{
						result.push_back(pa);
						visited.insert(pa);
					}
				}
			}
		}
	}
	return result;
}

//4sum O(N3)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>res;
	int n = nums.size();
	if (n<3)return res;
	for (int i = 0; i < n - 3; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])continue;
		if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3]<target)continue;
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]>target)break;
		for (int j = i + 1; j < n - 2; ++j)
		{
			if (j>i + 1 && nums[j] == nums[j - 1])continue;
			int begin = j + 1, end = n - 1;
			while (begin < end)
			{
				int sum = nums[i] + +nums[j] + nums[begin] + nums[end];
				if (sum == target)
				{
					res.push_back({ nums[i], nums[j], nums[begin], nums[end] });
					begin++;
					end--;
					while (begin < end && nums[begin] == nums[begin - 1])begin++;
					while (begin < end && nums[end] == nums[end + 1])end--;
				}
				else if (sum>target)
				{
					end--;
				}
				else begin++;
			}
		}
	}
	return res;
}
//hash table//depends(ON(3))

vector<vector<int> > fourSum(vector<int> &num, int target) {
	sort(num.begin(), num.end());
	unordered_map<int, set<pair<int, int>>> hash;
	set<vector<int>> ans;
	int n = num.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int a = num[i] + num[j];
			if (hash.count(target - a)) {
				for (auto &p : hash[target - a]) {
					vector<int> b = { p.first, p.second, num[i], num[j] };
					ans.insert(b);
				}
			}
		}
		for (int j = 0; j < i; j++) {
			int a = num[j], b = num[i];
			hash[a + b].insert(make_pair(a, b));
		}
	}
	return vector<vector<int>>(ans.begin(), ans.end());
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
////flatten the list while calling hasNext(), using stack; O(n) time, O(n) space
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



// you can write the recrusive way

vector<int>flat;
int size;
void flatten(NestedInteger& nest)
{
	if (nest.isInteger())flat.push_back(nest.getInteger());
	else
	{
		int k = 0;
		vector<NestedInteger> li = nest.getList();
		while (k<li.size())
		{
			flatten(li[k]);
			k++;
		}
	}
}

NestedIterator(vector<NestedInteger> &nestedList) {
	size = 0;
	for (int i = 0; i<nestedList.size(); ++i)flatten(nestedList[i]);
}

vector<int>flatten(vector<NestedInteger>nestedList)
{
		//     you can use a stack
	vector<int>res;
	if (nestedList.empty())return res;
	stack<NestedInteger>stk;
	for (int i = nestedList.size() - 1; i >= 0; --i)
	{
		stk.push(nestedList[i]);
	}
	while (!stk.empty())
	{
		NestedInteger curNest = stk.top();
		stk.pop();
		if (curNest.isInteger())
		{
			res.push_back(curNest.getInteger());
		}
		else
		{
			for (int i = curNest.getList().size() - 1; i >= 0; --i)
			{
				stk.push(curNest.getList()[i]);
			}
		}
	}

}

//251 flatten 2d vector
class Vector2D {
	vector<vector<int>>::iterator i, iEnd;
	int j = 0;
public:
	Vector2D(vector<vector<int>>& vec2d) {
		i = vec2d.begin();
		iEnd = vec2d.end();
	}

	int next() {
		hasNext();
		return (*i)[j++];
	}

	bool hasNext() {
		while (i != iEnd && j == (*i).size())
			i++, j = 0;
		return i != iEnd;
	}
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

//interesting, better than me
public List<Integer> inorderTraversal(TreeNode root) {
	List<Integer> list = new ArrayList<>();
	if (root == null) return list;
	Stack<TreeNode> stack = new Stack<>();
	while (root != null || !stack.empty()){
		while (root != null){
			stack.push(root);
			root = root.left;
		}
		root = stack.pop();
		list.add(root.val);
		root = root.right;

	}
	return list;
}

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

// dfs recursive solution: O(n) time O(h) space
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

// iterative
//iterative: O(n) time O(n) space
public boolean isValidBST(TreeNode root) {
	if (root == null) return true;
	Stack<TreeNode> stack = new Stack<>();
	TreeNode pre = null;
	while (root != null || !stack.isEmpty()) {
		while (root != null) {
			stack.push(root);
			root = root.left;
		}
		root = stack.pop();
		if (pre != null && root.val <= pre.val) return false;
		pre = root;
		root = root.right;
	}
	return true;
}


//ksmallest
// Kth Smallest Element in a BST
//inorder traversal
public int kthSmallest(TreeNode root, int k) {
	Stack<TreeNode> stack = new Stack<>();
	while (root != null || !stack.isEmpty()) {
		while (root != null) {
			stack.push(root);
			root = root.left;
		}
		root = stack.pop();
		if (--k == 0) break;
		root = root.right;
	}
	return root.val;
}


//klargest
//k smallest,, just modify the sequeence
void kthLargestUtil(TreeNode *root, int k, int &c)
{

	if (root == NULL || c >= k)return;
	kthLargestUtil(root->right, k, c);
	c++;
	if (c <= k)
	{
		printf("the first %d the largest element is %d \n", c, root->val);
	}
	kthLargestUtil(root->left, k, c);
}


void kthLargest(TreeNode*root, int k)
{
	int c = 0;
	kthLargestUtil(root, k, c);
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
	vector<int>res(m + n, 0);
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
	for (int x : res)ans = to_string(x) + ans;// pay attention to the order;
	return ans;
}

string multiply(string num1, string num2)
{
	int m = num1.size(), n = num2.size();
	//vector<int>pos = vector<int>(m + n, 0);
	string sum(m + n, '0');
	for (int i = m - 1; i >= 0; --i)
	{
		int carry = 0;
		for (int j = n - 1; j >= 0; --j)
		{
			int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0') + carry;
			sum[i + j + 1] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		sum[i] +=carry;
	}
	int startpos = sum.find_first_not_of("0");
	return startpos != sum.npos ? sum.substr(startpos) : "0";
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
// since it's a graph, so dfs and bfs O(m+n)
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

//bfs

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
{
	if (!node)return NULL;
	UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
	mp[node] = copy;
	queue<UndirectedGraphNode*>q;
	q.push(node);
	while (!q.empty())
	{
		UndirectedGraphNode* cur = q.front();
		q.pop();
		for (UndirectedGraphNode* neigh : cur->neighbors)
		{
			if (mp.find(neigh) == mp.end())
			{
				UndirectedGraphNode* neig = new UndirectedGraphNode(neight->label);
				mp[neigh] = neig;
				q.push(neig);
			}
			mp[cur]->neighbors.push_back(mp[neigh]);
		}
	}
	return copy;
}


//138 copy list with random pointer
RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)return head;
	unordered_map<RandomListNode*, RandomListNode*>mp;
	RandomListNode* save_head = head;
	while (head)
	{
		mp[head] = new RandomListNode(head->label);
		head = head->next;
	}
	head = save_head;
	RandomListNode* newHead = NULL;
	RandomListNode* newTail = NULL;
	while (head)
	{
		RandomListNode* Node = mp[head];
		Node->next = mp[head->next];
		Node->random = mp[head->random];
		if (newHead == NULL)
		{
			newHead = newTail = Node;
		}
		else
		{
			newTail->next = Node;
			newTail = newTail->next;
		}
		head = head->next;
	}
	return newHead;
}


unordered_map<RandomListNode*, RandomListNode*>mp;
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)return head;
		if (mp.find(head) == mp.end())
		{
			mp[head] = new RandomListNode(head->label);
			mp[head]->next = copyRandomList(head->next);
			mp[head]->random = copyRandomList(head->random);
		}
		return mp[head];
	}
};


An intuitive solution is to keep a hash table for each node in the list, via which we just need to iterate the list in 2 rounds respectively to create nodes and assign the values for their random pointers.As a result, the space complexity of this solution is O(N), although with a linear time complexity.

As an optimised solution, we could reduce the space complexity into constant.The idea is to associate the original node with its copy node in a single linked list.In this way, we don't need extra space to keep track of the new nodes.

The algorithm is composed of the follow three steps which are also 3 iteration rounds.

Iterate the original list and duplicate each node.The duplicate
of each node follows its original immediately.
Iterate the new list and assign the random pointer for each
duplicated node.
Restore the original list and extract the duplicated nodes.
The algorithm is implemented as follows :
// no extra space
public RandomListNode copyRandomList(RandomListNode head) {
	RandomListNode iter = head, next;

	// First round: make copy of each node,
	// and link them together side-by-side in a single list.
	while (iter != null) {
		next = iter.next;

		RandomListNode copy = new RandomListNode(iter.label);
		iter.next = copy;
		copy.next = next;

		iter = next;
	}

	// Second round: assign random pointers for the copy nodes.
	iter = head;
	while (iter != null) {
		if (iter.random != null) {
			iter.next.random = iter.random.next;
		}
		iter = iter.next.next;
	}

	// Third round: restore the original list, and extract the copy list.
	iter = head;
	RandomListNode pseudoHead = new RandomListNode(0);
	RandomListNode copy, copyIter = pseudoHead;

	while (iter != null) {
		next = iter.next.next;

		// extract the copy
		copy = iter.next;
		copyIter.next = copy;
		copyIter = copy;

		// restore the original list
		iter.next = next;

		iter = next;
	}

	return pseudoHead.next;
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

void backtrackingSubsets(vector<vector<int>>&res, vector<int>& path, vector<int> nums, int cur)
{
	res.push_back(path);
	for (int i = cur; i < nums.size(); ++i)
	{
		path.push_back(nums[i]);
		backtrackingSubsets(res, path, nums, i + 1);
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	backtrackingSubsets(res, path, nums, 0);
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
		while (i<(int)nums.size() - 1 && nums[i] == nums[i + 1])i++;// vector<vector<int>> subsets(vector<int>& nums) is a usually way to handle this
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

// without parent pointer: 
// O(num of nodes in tree) time
// O(height of tree) space
TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == root || q == root)return root;
	TreeNode* left = lowestCommonAncestorBT(root->left, p, q);
	TreeNode* right = lowestCommonAncestorBT(root->right, p, q);
	if (left && right)return root;
	return left ? left : right;
}


//parent node
int depth(Node *node)
{
	int d = -1;
	while (node)
	{
		++d;
		node = node->parent;
	}
	return d;
}

// To find LCA of nodes n1 and n2 in Binary Tree
Node *LCA(Node *n1, Node *n2)
{
	// Find depths of two nodes and differences
	int d1 = depth(n1), d2 = depth(n2);
	int diff = d1 - d2;

	// If n2 is deeper, swap n1 and n2
	if (diff < 0)
	{
		Node * temp = n1;
		n1 = n2;
		n2 = temp;
		diff = -diff;
	}

	// Move n1 up until it reaches the same level as n2
	while (diff--)
		n1 = n1->parent;

	// Now n1 and n2 are at same levels
	while (n1 && n2)
	{
		if (n1 == n2)
			return n1;
		n1 = n1->parent;
		n2 = n2->parent;
	}

	return NULL;
}

/**
* Definition of ParentTreeNode:
*
* class ParentTreeNode {
*     public ParentTreeNode parent, left, right;
* }
*/
// with parent node
// if nodes can be not in same tree, this solution can still be used
// O(deepest depth of a and b) time, instead of O(num of nodes in tree)
// O(1) space, instead of O(height of tree)
public class Solution {
	/**
	* @param root: The root of the tree
	* @param A, B: Two node in the tree
	* @return: The lowest common ancestor of A and B
	*/
	public ParentTreeNode lowestCommonAncestorII(ParentTreeNode root,
		ParentTreeNode a,
		ParentTreeNode b) {
		int pathA = getPathToRoot(a);//get depth
		int pathB = getPathToRoot(b);
		if (pathA > pathB) {//move up to the same level with the other node
			a = upToSameLevel(a, pathA - pathB);
		}
		if (pathB > pathA) {
			b = upToSameLevel(b, pathB - pathA);
		}
		int pathLength = Math.min(pathA, pathB);
		ParentTreeNode res = null;
		while (pathLength > 0) {//move up from a&b to root
			if (a == b) {
				res = a;
				break;//the first same node is the LCA
			}
			a = a.parent;
			b = b.parent;
			pathLength--;
		}
		return res;
	}

	private int getPathToRoot(ParentTreeNode node) {
		int path = 0;
		while (node != null) {//move up to the root with parent node
			path++;
			node = node.parent;
		}
		return path;
	}

	private ParentTreeNode upToSameLevel(ParentTreeNode node, int step) {
		while (step > 0) {//move up to the same level with the other node
			node = node.parent;
			step--;
		}
		return node;
	}
}



class ResultType {
	public boolean exist_a;//should be public cuz this class is not in the other
	public boolean exist_b;
	public TreeNode node;
	public ResultType(boolean a, boolean b, TreeNode root) {
		exist_a = a;
		exist_b = b;
		node = root;
	}
}

public class Solution {
	/**
	* @param root The root of the binary tree.
	* @param A and B two nodes
	* @return: Return the LCA of the two nodes.
	*/
	public TreeNode lowestCommonAncestor3(TreeNode root, TreeNode a, TreeNode b) {
		ResultType res = helper(root, a, b);
		if (res.exist_a && res.exist_b) {//return node only when two nodes found
			return res.node;
		}
		return null;//one/both of a/b does not exist
	}

	private ResultType helper(TreeNode root, TreeNode a, TreeNode b) {
		if (root == null) {
			return new ResultType(false, false, null);
		}
		ResultType left = helper(root.left, a, b);
		ResultType right = helper(root.right, a, b);
		boolean exist_a = left.exist_a || right.exist_a || root == a;//found a
		boolean exist_b = left.exist_b || right.exist_b || root == b;//found b
		if (root == a || root == b || (left.node != null && right.node != null)) {
			return new ResultType(exist_a, exist_b, root);
		}//if root is a or b, or both a and b have been found from subtrees
		if (left.node != null) {
			return new ResultType(exist_a, exist_b, left.node);
		}//if only left subtree found a node
		if (right.node != null) {
			return new ResultType(exist_a, exist_b, right.node);
		}//if only right subtree found a node
		return new ResultType(false, false, null);//if none of them found
	}
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
	for (int i = 0; i < pNode.size() && i < qNode.size(); ++i)
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
// hash+sort solution: O(mnlogn) time, O(m) space, m is the num of strs, n is the length of strs
// map store the sorted string and its index
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
// use the first
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

//using counting sort
// hash+counting sort: O(mn) time, O(m) space, m is the num of strs, n is the length of strs
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		for (string s : strs) {
			string t = strSort(s);
			mp[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : mp) {
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}
private:
	string strSort(string& s) {
		int count[26] = { 0 }, n = s.length();
		for (int i = 0; i < n; i++)
			count[s[i] - 'a']++;
		int p = 0;
		string t(n, 'a');
		for (int j = 0; j < 26; j++)
			for (int i = 0; i < count[j]; i++)
				t[p++] += j;
		return t;
	}
};

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
	vector<int>forwa(n, 1);
	vector<int>back(n, 1);
	for (int i = 1; i < n; ++i)
	{
		forwa[i] = forwa[i - 1] * nums[i - 1];
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
	for (int i = n - 1; i >= 0; --i)
	{
		res[i] *= right;// do not knwo how to do. I want to pratce as much as possible
		right *= nums[i];
	}
	return res;
}

// 69 sqrt(x)
// implement int sqrt(int x)
int mySqrt(int x) {
	if (x == 1 || x == 0)return x;
	int left = 0, right = x, mid = 0;
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
		else if (sum < x)left = mid + 1;
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
			right = 46341;// can acclerate ,46340 would lead error
			continue;
		}
		if (mid <= x / mid && x / (mid + 1)<mid + 1)return mid;
		else if (mid>x / mid)right = mid;
		else if (mid<x / mid)left = mid + 1;
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
	delete[]adj;
	return count == num;
}


//dfs
//For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor... and so on.
//If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false.
//Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited.Note that you should make two records :
//one is to record all the visited nodes and the other is to record the visited nodes in the current DFS visit.
//The code is as follows.We use a vector<bool> visited to record all the visited nodes and another vector<bool> onpath to record the visited nodes of the current DFS visit.Once the current visit is finished, we reset the onpath value of the starting node to false
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<bool> onpath(numCourses, false), visited(numCourses, false);
		for (int i = 0; i < numCourses; i++)
			if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
				return false;
		return true;
	}
private:
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}
	bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
		if (visited[node]) return false;
		onpath[node] = visited[node] = true;
		for (int neigh : graph[node])
			if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
				return true;
		return onpath[node] = false;
	}
};


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
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<int> toposort;
		vector<bool> onpath(numCourses, false), visited(numCourses, false);
		for (int i = 0; i < numCourses; i++)
			if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
				return{};
		reverse(toposort.begin(), toposort.end());// yuo should reverse
		return toposort;
	}
private:
	vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses);
		for (auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}
	bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) {
		if (visited[node]) return false;
		onpath[node] = visited[node] = true;
		for (int neigh : graph[node])
			if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
				return true;
		toposort.push_back(node);
		return onpath[node] = false;
	}
};

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
	vector<int>res(n + 1, 0);//count[i] is the num of papers that has i citations (note:count[l] means >= l citations)
	for (int i = 0; i < n; ++i)
	{
		if (citations[i] >= n)res[n]++;
		else res[citations[i]]++;
	}
	int sum = 0;////use res to record the num of papers that has at least i citations, if res>=i, it means i is the hIndex
	for (int i = n; i >= 0; --i)// it is possible that it would be n
	{
		sum += res[i];
		if (sum >= i)return i;////no need to check if other l−i papers have no more than i citations each,cuz they must be
	}
	return 0;
}


//// O(logn) time
//Just binary search, each time check citations[mid]
//case 1: citations[mid] == len - mid, then it means there are citations[mid] papers that have at least citations[mid] citations.
//case 2: citations[mid] > len - mid, then it means there are citations[mid] papers that have moret than citations[mid] citations, so we should continue searching in the left half
//case 3: citations[mid] < len - mid, we should continue searching in the right side
//After iteration, it is guaranteed that right + 1 is the one we need to find(i.e.len - (right + 1) papars have at least len - (righ + 1) citations)
//follow up
int hIndexII(vector<int>& citations)
{
	int left = 0, len = citations.size(), right = len - 1, mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (citations[mid] >= (len - mid))right = mid - 1;//kind of like l - i, which means how many nums are from mid to l;,  
		//means l - mid papers have at least l - mid citations;use end = mid to find the largest(leftmost) l, si we must decrease mid to get more large index
		else left = mid + 1;
	}
	return len - left;
}

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// hard part

// lt 84
//@taobupt

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

//first you can use stack
// O(mn) time, O(n) space, stack solution
//calculate area of rectangle expanding from curr j col to left&right bounds,from curr row to top "0"/top boundary
public class Solution {
	public int maximalRectangle(char[][] matrix) {
		if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
			return 0;
		}
		int m = matrix.length;
		int n = matrix[0].length;
		int max = 0;
		int[] heights = new int[n + 1];//height[j]:the num of "1" in j col from currRow to the top "0"/top boundary
		for (int i = 0; i < m; i++) {
			Stack<Integer> stack = new Stack<>();
			for (int j = 0; j < n + 1; j++) {
				if (j < n && matrix[i][j] == '1') {
					heights[j] += 1;//update the height that expand from curr row to the top '1'
				}
				else {//which means the last num(heights[n]) is always 0; and if j < n but it's not '1', it should be 0 too
					heights[j] = 0;
				}

				//each loops we calculate the area of rectangle that ends at curr j, loops until the top is less than curr j
				//each num only goes in&out stack once,so this is O(1) time
				//if curr height <= peek(),calculate the max area, and update left bound by poping out the top
				while (!stack.empty() && heights[j] <= heights[stack.peek()]) {
					int height = heights[stack.pop()];
					int width = j;//if stack is empty,it means the width of curr rectangle starts from leftmost(0) to curr j
					if (!stack.empty()) {//if stack isn't empty,it means the width of curr rectangle starts from peek() to j
						width = width - stack.peek() - 1;
					}
					max = Math.max(max, height * width);//update the max rectangle
				}
				stack.push(j);//remember to push j !!!
			}
		}
		return max;
	}
}



int largestRectangleArea(vector<int>& heights) {
	heights.push_back(0);//sentineal;
	int res = 0, n = heights.size();
	stack<int>dq;
	for (int i = 0; i < n; ++i)
	{
		while (!dq.empty() && heights[dq.top()]>heights[i])
		{
			int h = heights[dq.top()];
			dq.pop();
			int index = dq.empty() ? -1 : dq.top();
			res = max(res, h*(i - 1 - index));
		}
		dq.push(i);
	}
	return res;
}

//lt 316 remove duplicate letters

/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/
//@taobupt
string removeDuplicateLetters(string s) {
	string res;
	int cnt[26] = { 0 };
	bool vis[26] = { false };
	for (char c : s)cnt[c - 'a']++;
	for (char c : s)
	{
		cnt[c - 'a']--;
		if (vis[c - 'a'])continue;
		while (!res.empty() && cnt[res.back() - 'a'] && res.back() > c)
		{
			vis[res.back() - 'a'] = false;
			res.pop_back();
		}
		res.push_back(c);
		vis[c - 'a'] = true;
	}
	return res;
}

//lt 85 maximal rectangle in matrix
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

//@taobupt

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty())return false;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>>dp(m, vector<int>(n, 0));
	int res = 0;
	for (int i = 0; i < n; ++i)dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
	for (int i = 1; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dp[i][j] = matrix[i][j] == '0' ? 0 : dp[i - 1][j] + 1;
		}
		res = max(res, largestRectangleArea(dp[i]));
	}
	res = max(res, largestRectangleArea(dp[0]));
	return res;
}

//LT 116&&117
/*
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
1
/  \
2    3
/ \  / \
4  5  6  7
After calling your function, the tree should look like:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
*/

//@taobupt
void connect(TreeLinkNode *root) {
	if (root == NULL)return;
	queue<TreeLinkNode*>q;
	TreeLinkNode* node = NULL;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			node = q.front();
			q.pop();
			if (size != 0)node->next = q.front();
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
	}
}
// perfect tree
void connect116(TreeLinkNode *root) {
	if (root == NULL)return;
	TreeLinkNode* pre = root;
	TreeLinkNode* cur = NULL;
	while (pre->left)
	{
		cur = pre;
		while (cur)
		{
			cur->left->next = cur->right;
			if (cur->next)cur->right->next = cur->next->left;
			cur = cur->next;
		}
		pre = pre->left;
	}
}


// more readable


void connect117(TreeLinkNode* root)
{
	TreeLinkNode* head = root;// the left most node in the lower level
	TreeLinkNode* prev = nullptr;// the prevous node in the lower level
	TreeLinkNode* curr = nullptr;// the current node in the upper level
	while (head)
	{
		curr = head;
		prev = nullptr;
		head = nullptr;
		while (curr)
		{
			if (curr->left)
			{
				if (prev)prev->next = curr->left;
				else head = curr->left;
				prev = curr->left;
			}
			if (curr->right)
			{
				if (prev)prev->next = curr->right;
				else head = curr->right;
				prev = curr->right;
			}
			curr = curr->next;
		}
	}
}
void connect117(TreeLinkNode* root)
{
	TreeLinkNode* nextHead = new TreeLinkNode(0);
	nextHead->next = root;
	while (nextHead->next)
	{
		TreeLinkNode* tail = nextHead;
		TreeLinkNode* n = nextHead->next;
		nextHead->next = NULL;
		for (; n != NULL; n = n->next)
		{
			if (n->left)
			{
				tail->next = n->left;
				tail = tail->next;
			}
			if (n->right)
			{
				tail->next = n->right;
				tail = tail->next;
			}
		}
	}
}

// lt 33 search in a sorted array
// search sorted array
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
//taobupt
int search(vector<int>& nums, int target) {
	int begin = 0, n = nums.size(), end = n - 1, mid = 0;
	while (begin<end)
	{
		mid = begin + (end - begin) / 2;
		if (nums[mid] == target)return mid;
		if (nums[mid]>nums[end])
		{
			if (nums[mid]>target && target >= nums[begin])end = mid;
			else begin = mid + 1;
		}
		else if (nums[mid]<nums[end])
		{
			if (nums[mid]<target && target <= nums[end])begin = mid + 1;
			else end = mid;
		}
	}
	return nums[begin] == target ? begin : -1;
}

//56 merge interval
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
//@taobupt

vector<Interval>merge(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
	int n = intervals.size();
	vector<Interval>res;
	if (n == 0)return res;
	int totaltime = 0;
	res.push_back(intervals[0]);
	for (int i = 1; i < n; ++i)
	{
		if (res.back().end < intervals[i].start)
		{
			res.push_back(intervals[i]);
		}
		else
		{
			res.back().end = max(res.back().end, intervals[i].end);
		}
	}
	return res;
}

//cal the total time
public class Solution {
	public int totalTime(List<Interval> intervals) {
		if (intervals == null || intervals.size() <= 1) {//size(), not length !!!
			return intervals;
		}
		Collections.sort(intervals, new Comparator<Interval>(){
			public int compare(Interval a, Interval b) {
				return a.start - b.start;
			}
		});
		//you can also merge intervals before calculating,which makes calculation easier,but takes some memory(new arraylist)
		int total = 0;
		Interval prev = new Interval(0, 0);
		for (Interval curr : intervals) {
			if (prev.end < curr.start) {
				total += curr.end - curr.start;//add the whole part(non-overlapping)
				prev = curr;
			}
			else if (curr.end > prev.end) {
				total += curr.end - prev.end;//only add the non overlapping part after prev.end
				prev = curr;
			}
			//else curr.end<=prev.end(curr inside prev),don't calculate anything,and prev isn't updated(prev.end is bigger)
		}
		return total;
	}
}





// lt 57 insert interval
//@taobupt
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]
*/

// input: unsorted, no overlaps; output: can be unsorted, return total time; O(n) time, O(n) space
public class Solution {
	public int insert(List<Interval> intervals, Interval newInterval) {
		if (newInterval == null) {
			return 0;
		}
		int totalTime = 0;
		//if you need to insert intervals while calculating time,add:
		//List<Interval> res = new ArrayList<>();
		for (int i = 0; i < intervals.size(); i++) {
			if (intervals.get(i).start <= newInterval.end || intervals.get(i).end >= newInterval.start) {//merge overlaps
				newInterval.start = Math.min(newInterval.start, intervals.get(i).start);//remember to update the start!!!
				newInterval.end = Math.max(newInterval.end, intervals.get(i).end);
			}
			else {
				totalTime += intervals.get(i).end - intervals.get(i).start;
				//res.add(intervals.get(i));//add all non-overlapping intervals
			}
		}
		totalTime += newInterval.end - newInterval.start;//we add the time of merged newInterval here
		//if you need to insert intervals while calculating time,add:
		//res.add(newInterval);//add the newInterval when all intervals have been checked so that no overlap exists
		return totalTime;
	}
}

// input: unsorted, no overlaps; output: can be unsorted; O(n) time, O(1) space
public class Solution {
	public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
		if (newInterval == null) {
			return intervals;
		}
		List<Interval> res = new ArrayList<>();
		for (int i = 0; i < intervals.size(); i++) {
			if (intervals.get(i).start <= newInterval.end || intervals.get(i).end >= newInterval.start) {//merge overlaps
				newInterval.start = Math.min(newInterval.start, intervals.get(i).start);//remember to update the start too!!!
				newInterval.end = Math.max(newInterval.end, intervals.get(i).end);
			}
			else {
				res.add(intervals.get(i));//add all non-overlapping intervals
			}
		}
		res.add(newInterval);//add the newInterval when all intervals have been checked so that no overlap exists
		return res;
	}
}


//leetcode
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval>res;
	int n = intervals.size(), i = 0;
	while (i < n && intervals[i].end < newInterval.start)res.push_back(intervals[i++]);
	while (i < n && intervals[i].start <= newInterval.end)
	{
		newInterval.start = min(intervals[i].start, newInterval.start);
		newInterval.end = max(intervals[i++].end, newInterval.end);
	}
	res.push_back(newInterval);
	while (i < n)res.push_back(intervals[i++]);
	return res;
}


// if the format of intervals are "March, 2014" etc, first convert it to "201403" by "2014" + "03"(hashmap:March->03)
// or first convert it to 2014 * 12 + 3, if the output is num of months
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=160738&fromuid=109727

// input is unsorted and has some overlapping intervals, output should be sorted: O(nlogn) time, O(1) space(res doesn't count)
public class Solution {
	public List<Interval> merge(List<Interval> intervals) {
		if (intervals == null || intervals.size() <= 1) {//size(), not length !!!
			return intervals;
		}
		Collections.sort(intervals, new Comparator<Interval>(){
			public int compare(Interval a, Interval b) {
				return a.start - b.start;
			}
		});
		int start = intervals.get(0).start;//remember to add .start !!!
		int end = intervals.get(0).end;//remember to add .end !!!
		List<Interval> res = new ArrayList<>();
		for (Interval i : intervals) {
			if (i.start <= end) {//if overlap, update end, which is needed to create a new interval
				end = Math.max(end, i.end);
			}
			else {
				res.add(new Interval(start, end));//if not overlapped, we can create a new interval
				start = i.start;
				end = i.end;
			}
		}
		res.add(new Interval(start, end));//remember to add the last interval
		return res;
	}
}

//lt 76 minimum window substring
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/
//@taobupt

// if it is a unordered_set, we cound use this to solve again
//for set
public String minWindow(String s, HashSet<Character> thash) {
	if (s == null || t == null || s.length() < t.size()) {
		return "";
	}
	String res = "";
	int[] shash = new int[256];//shash records num of all chars appeared in dict that are in curr window
	int count = 0;//num of |effective| chars in curr window,while it equals t.length(), we will try to shink the window
	int min = s.length() + 1;
	for (int left = 0, right = 0; right < s.length();) {
		char r = s.charAt(right++);
		if (thash.contains(r)) {//if it's in the dict
			shash[r]++;//num of |valid| chars in curr window increases
			if (shash[r] == 1) {//if the num of valid char is <= what target needed
				count++;
			}
			while (count == thash.size()) {
				if (right - left < min) {//first try to update the min length and res
					min = right - left;
					res = s.substring(left, right);
				}
				char l = s.charAt(left++);
				if (thash.contains(l)) {//if it's in the dict
					shash[l]--;//num of |valid| chars in curr window decreses
					if (shash[l] == 0) {//if the num of valid char is < what target needed
						count--;
					}
				}
			}
		}
	}
	return res;
}

string minWindow(string s, string t) {
	int left = 0, right = 0, minStart = 0, minLength = INT_MAX, count = t.size(), n = s.size();
	//unordered_map<char, int>mp;
	int mp[128] = { 0 };
	for (char c : t)mp[c]++;
	while (right<n)
	{
		if (mp[s[right]]>0)count--;
		mp[s[right]]--;
		right++;
		while (count == 0)
		{
			if (minLength < right - left)// because the end has already increased by 1, so , it should be right-left
			{
				minStart = left;
				minLength = right - left;
			}
			mp[s[left]]++;
			if (mp[s[left]]>0)count++;
			left++;
		}
	}
	return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
}


//297 serialize and deserize binary tree
//@taobupt

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

1
/ \
2   3
/ \
4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

class Codec1 {
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

	// Decodes your encoded data to tree.
	TreeNode* deserialize(vector<string> data) {
		if (data.empty() || data[0] == "#")return NULL;
		TreeNode* root = new TreeNode(stoi(data[0]));
		TreeNode* cur = root;
		queue<TreeNode*>q;
		int n = data.size();
		for (int i = 1; i < n; ++i)
		{
			if (data[i] == "#")
			{
				if (!q.empty() && (i % 2 == 0))
				{
					cur = q.front();
					q.pop();
				}
				continue;
			}
			TreeNode* newNode = new TreeNode(stoi(data[i]));
			q.push(newNode);
			if (i & 0x1)cur->left = newNode;
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

//recrusive way to do this
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}


	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize(in);
	}
private:
	void serialize(TreeNode* root, ostringstream& out)
	{
		if (root)
		{
			out << root->val << ' ';
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else out << "# ";
	}
	TreeNode* deserialize(istringstream& in)
	{
		string val;
		in >> val;
		if (val == "#")return nullptr;
		TreeNode* root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};


// use linkedlist to store data
struct Node{
	string val;
	Node* next;
	Node(string val) :val(val), next(nullptr){}
};
class Codec {
public:

	Node* serialize(TreeNode* root) {
		Node* first = new Node(" ");
		Node* p = first;
		if (root == NULL)return nullptr;
		queue<TreeNode*>q;
		q.push(root);
		TreeNode* node = NULL;
		while (!q.empty())
		{
			node = q.front();
			q.pop();
			if (node)
			{
				p->next = new Node(to_string(node->val));
				q.push(node->left);
				q.push(node->right);
			}
			else p->next = new Node("#");
			p = p->next;
		}
		return first->next;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(Node* head) {
		if (head == nullptr || head->val == "#")return NULL;
		TreeNode* root = new TreeNode(stoi(head->val));
		TreeNode* cur = root;
		queue<TreeNode*>q;
		int i = 1;
		head = head->next;
		while (head)
		{

			if (head->val == "#")
			{
				if (!q.empty() && (i % 2 == 0))
				{
					cur = q.front();
					q.pop();
				}
				head = head->next;
				i++;
				continue;
			}
			TreeNode* newNode = new TreeNode(stoi(head->val));
			q.push(newNode);
			if (i % 2 == 1)cur->left = newNode;
			else
			{
				cur->right = newNode;
				cur = q.front();
				q.pop();
			}
			head = head->next;
			i++;
		}
		return root;
	}

};
//380 insert delete getRandom O(1)
/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
*/
//@taobupt


// followup multiset
class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (mp.find(val) != mp.end())return false;
		else
		{
			mp[val] = res.size();
			res.push_back(val);
			return true;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (mp.find(val) == mp.end())return false;
		else
		{
			res[mp[val]] = res.back();
			mp[res.back()] = mp[val];
			res.pop_back();
			mp.erase(val);
			return true;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		return res[rand() % res.size()];
	}
private:
	vector<int>res;
	unordered_map<int, int>mp;
};
//follow up

class RandomizedCollection {
private:
	unordered_map<int, unordered_set<int>> index;
	vector<int> output;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool return_val = index.find(val) == index.end();
		index[val].insert(output.size());
		output.push_back(val);
		return return_val;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (index.find(val) == index.end()) return false;
		int last = output.back(); output.pop_back();
		index[last].erase(output.size());
		if (last != val) {
			int _id = *index[val].begin(); index[val].erase(_id);
			index[last].insert(_id);
			output[_id] = last;
		}
		//delete dummy 
		if (index[val].empty())
			index.erase(val);
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return output[rand() % output.size()];
	}
};


//273 integer to english words
//@taobupt
/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

string digits[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string tens[10] = { "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

string int2string(int n)
{
	if (n >= 1000000000)
	{
		return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
	}
	else if (n >= 1000000)
	{
		return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
	}
	else if (n >= 1000)
	{
		return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
	}
	else if (n >= 100)
	{
		return int2string(n / 100) + " Hundred" + int2string(n % 100);
	}
	else if (n >= 20)
	{
		return " " + tens[n / 10] + int2string(n % 10);
	}
	else if (n >= 1)
	{
		return " " + digits[n];
	}
	else return "";
}
string numberToWords(int num)
{
	if (num == 0)return "Zero";
	else
	{
		string ret = int2string(num);
		return ret.substr(1);
	}
}

// 269 alien dictionary

/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
"wrt",
"wrf",
"er",
"ett",
"rftt"
]
The correct order is: "wertf".
*/
//@taobupt

//toplogical sort
//complexity is O(m*n) ?

// if building graph is not included, you may assume  O(V+E)
string alienOrder(vector<string>& words) {
	unordered_map<char, int>indegree;
	unordered_map<char, unordered_set<char>>adj;
	string res;
	if (words.empty())return res;
	int n = words.size();
	for (string str : words)
	{
		for (char c : str)indegree[c] = 0;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		string cur = words[i];
		string next = words[i + 1];
		int length = min(cur.size(), next.size());
		for (int j = 0; j < length; ++j)
		{
			if (cur[j] != next[j])
			{
				if (adj[cur[j]].find(next[j]) == adj[cur[j]].end())
				{
					adj[cur[j]].insert(next[j]);
					indegree[next[j]]++;
				}
				break;
			}
			if (j == next.size() - 1 && cur.size() > next.size()) { // "abcd" -> "ab"
				return "";
			}
		}

	}
	queue<char>q;
	for (unordered_map<char, int>::iterator it = indegree.begin(); it != indegree.end(); ++it)if (it->second == 0)q.push(it->first);
	int count = 0;
	char c = ' ';
	while (!q.empty())
	{
		c = q.front();
		res.push_back(c);
		q.pop();
		count++;
		for (char it : adj[c])
		{
			--indegree[it];
			if (indegree[it] == 0)q.push(it);
		}
	}

	return count == indegree.size() ? res : "";
}

//A topological ordering is possible if and only if the graph has no directed cycles
//Let's build a graph and perform a DFS. The following states made things easier.
//
//visited[i] = -1. Not even exist.
//visited[i] = 0. Exist.Non - visited.
//visited[i] = 1. Visiting.
//visited[i] = 2. Visited.
private final int N = 26;
public String alienOrder(String[] words) {
	boolean[][] adj = new boolean[N][N];
	int[] visited = new int[N];
	buildGraph(words, adj, visited);

	StringBuilder sb = new StringBuilder();
	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {                 // unvisited
			if (!dfs(adj, visited, sb, i)) return "";
		}
	}
	return sb.reverse().toString();
}

public boolean dfs(boolean[][] adj, int[] visited, StringBuilder sb, int i) {
	visited[i] = 1;                            // 1 = visiting
	for (int j = 0; j < N; j++) {
		if (adj[i][j]) {                        // connected
			if (visited[j] == 1) return false;  // 1 => 1, cycle   
			if (visited[j] == 0) {              // 0 = unvisited
				if (!dfs(adj, visited, sb, j)) return false;
			}
		}
	}
	visited[i] = 2;                           // 2 = visited
	sb.append((char)(i + 'a'));
	return true;
}

public void buildGraph(String[] words, boolean[][] adj, int[] visited) {
	Arrays.fill(visited, -1);                 // -1 = not even existed
	for (int i = 0; i < words.length; i++) {
		for (char c : words[i].toCharArray()) visited[c - 'a'] = 0;
		if (i > 0) {
			String w1 = words[i - 1], w2 = words[i];
			int len = Math.min(w1.length(), w2.length());
			for (int j = 0; j < len; j++) {
				char c1 = w1.charAt(j), c2 = w2.charAt(j);
				if (c1 != c2) {
					adj[c1 - 'a'][c2 - 'a'] = true;
					break;
				}
			}
		}
	}
}

//282 expression add operator
/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/
//taobupt

void dfs282(vector<string>& res, string path, string num, int target, long pv, long cv, char oper, int pos)
{
	if (cv == target && pos == num.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = pos + 1; i <= num.size(); ++i)
	{
		string sub = num.substr(pos, i - pos);
		long now = stol(sub);
		if (to_string(now) != sub)continue;
		dfs282(res, path + "+" + sub, num, target, now, cv + now, '+', i);
		dfs282(res, path + "-" + sub, num, target, now, cv - now, '-', i);
		dfs282(res, path + "*" + sub, num, target, pv*now, (oper == '-') ? cv + pv - pv*now : ((oper == '+') ? cv - pv + pv*now : pv*now), oper, i);
	}
}
vector<string>addOperator(string num, int target)
{
	vector<string>res;
	string path;
	int n = num.size();
	if (num.empty())return res;
	for (int i = 1; i <= n; ++i)
	{
		string sub = num.substr(0, i);
		long cur = stol(sub);
		if (to_string(cur) != sub)continue;
		dfs282(res, path + sub, num, target, cur, cur, '#', i);
	}
}

void backtracking(vector<string>&res, string path, string num, int target, int pos, long eval, long multi)
{
	if (pos == num.size() && target == eval)
	{
		res.push_back(path);
		return;
	}
	for (int i = pos + 1; i <= num.size(); ++i)
	{
		if (i != pos + 1 && num[pos] == '0')continue;
		string curstr = num.substr(pos, i - pos);
		long cur = stol(curstr);
		if (pos == 0)backtracking(res, path + curstr, num, target, i, cur, cur);
		else
		{
			backtracking(res, path + "+" + curstr, num, target, i, eval + cur, cur);
			backtracking(res, path + "-" + curstr, num, target, i, eval - cur, -cur);
			backtracking(res, path + "*" + curstr, num, target, i, eval - multi + multi*cur, multi*cur);
		}
	}
}

vector<string> addOperators(string num, int target)
{
	vector<string>res;
	if (num.empty())return res;
	string path;
	backtracking(res, path, num, target, 0, 0, 0);
	return res;
}


//only add and sub


void backtracking1(vector<string>&res, string path, string num, int target, int pos, long eval, long cur)
{
	if (pos == num.size() && target == eval)
	{
		if (!path.empty() && path[0] == '+')path = path.substr(1);
		res.push_back(path);
		return;
	}
	for (int i = pos + 1; i <= num.size(); ++i)
	{
		if (i != pos + 1 && num[pos] == '0')continue;
		string curstr = num.substr(pos, i - pos);
		long cur = stol(curstr);
		backtracking1(res, path + "+" + curstr, num, target, i, eval + cur, cur);
		backtracking1(res, path + "-" + curstr, num, target, i, eval - cur, -cur);

	}
}

vector<string> addOperators1(string num, int target)
{
	vector<string>res;
	if (num.empty())return res;
	string path;
	backtracking1(res, path, num, target, 0, 0, 0);
	return res;
}


// 79 word search
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
*/
//@taobupt

bool dfs79(vector<vector<char>>& board, string word, int pos, int dx[], int dy[], int x, int y, vector<vector<bool>>& vis)
{
	if (pos == word.size())return true;
	for (int k = 0; k < 4; ++k)
	{
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= board.size() || ny<0 || ny >= board[0].size() || vis[nx][ny] || word[pos] != board[nx][ny])continue;
		vis[nx][ny] = true;
		if (dfs79(board, word, pos + 1, dx, dy, nx, ny, vis))return true;
		vis[nx][ny] = false;
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty())return false;
	if (word.empty())return true;
	int m = board.size(), n = board[0].size();
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	vector<vector<bool>>vis(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (word[0] == board[i][j] && !vis[i][j])
			{
				vis[i][j] = true;
				if (dfs79(board, word, 1, dx, dy, i, j, vis))return true;
				vis[i][j] = false;
			}
		}
	}
	return false;
}

bool exist(vector<vector<char>>& board, int i, int j, string word, int pos)
{
	if (pos == word.size())return true;
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())return false;
	if (board[i][j] != word[pos])return false;
	board[i][j] = '*';
	bool exist1 = exist(board, i, j + 1, word, pos + 1) || exist(board, i + 1, j, word, pos + 1) || exist(board, i, j - 1, word, pos + 1) || exist(board, i - 1, j, word, pos + 1);
	board[i][j] = word[pos];
	return exist1;
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty())return false;
	int m = board.size(), n = board[0].size();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (exist(board, i, j, word, 0))return true;
		}
	}
	return false;
}

//208 implement trie Prefix tree
/*
Implement a trie with insert, search, and startsWith methods.

*/

//@taobupt

class TrieNode {
public:
	// Initialize your data structure here.
	bool isEnd;
	char content;
	vector<TrieNode*>subNode;
	TrieNode* getSubNode(char c)
	{
		if (!subNode.empty())
		{
			for (auto it : subNode)
			{
				if (it->content == c)return it;
			}
		}return nullptr;
	}
	TrieNode(char c = ' ') :content(c), isEnd(false) {}
	~TrieNode()
	{
		for (auto ptr : subNode)delete ptr;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		if (search(word))return;
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* node = cur->getSubNode(c);
			if (node == nullptr)
			{
				node = new TrieNode(c);
				cur->subNode.push_back(node);
			}
			cur = node;
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* node = cur->getSubNode(c);
			if (node == nullptr)return false;
			cur = node;
		}
		return cur->isEnd;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (char c : prefix)
		{
			TrieNode* node = cur->getSubNode(c);
			if (node == nullptr)return false;
			cur = node;
		}
		return true;
	}
	TrieNode* getRoot()
	{
		return root;
	}
private:
	TrieNode* root;
};


class TrieNode {
public:
	// Initialize your data structure here.
	bool isEnd;
	TrieNode* subNode[26];
	TrieNode() {
		isEnd = false;
		memset(subNode, NULL, 26 * sizeof(TrieNode*));
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* &newNode = cur->subNode[c - 'a'];
			if (newNode == nullptr)
			{
				newNode = new TrieNode();
			}
			cur = newNode;
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* newNode = cur->subNode[c - 'a'];
			if (newNode == nullptr)return false;
			cur = newNode;
		}
		return cur->isEnd;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (char c : prefix)
		{
			TrieNode* newNode = cur->subNode[c - 'a'];
			if (newNode == nullptr)return false;
			cur = newNode;
		}
		return true;
	}

private:
	TrieNode* root;
};

// add / search: O(wordLength) time; O(numOfTrieNode * 26) = O(numOfWords * wordLength * 26) space
//211 add and search word-data structure design
// word search
//addsearch
class TrieNode{
public:
	bool isEnd;
	TrieNode* subNode[26];
	TrieNode()
	{
		isEnd = false;
		memset(subNode, NULL, 26 * sizeof(TrieNode*));
	}
};

class WordDictionary {
public:

	WordDictionary()
	{
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* &newNode = cur->subNode[c - 'a'];
			if (newNode == nullptr)
			{
				newNode = new TrieNode();
			}
			cur = newNode;
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return find(word, 0, root);
	}

private:
	bool find(string word, int pos, TrieNode* node)
	{
		if (pos == word.size())return node->isEnd;////return node.isWord, not true !!!!
		if (word[pos] == '.')//if whatever char can be matched
		{
			for (auto ptr : node->subNode)
			{
				if (ptr &&find(word, pos + 1, ptr))return true;//if word found, return true
			}
			return false;
		}
		else return node->subNode[word[pos] - 'a'] ? find(word, pos + 1, node->subNode[word[pos] - 'a']) : false;
	}
	TrieNode* root;
};

//212 word search II
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
Return ["eat","oath"].
*/

//@taobupt

void dfs212(vector<vector<char>>& board, TrieNode* root, int dx[], int dy[], int i, int j, vector<vector<bool>> &vis, set<string>& result_set, string word)
{
	if (root->isEnd)
	{
		result_set.insert(word);
		//return;
	}
	for (int k = 0; k < 4; ++k)
	{
		int nx = dx[k] + i, ny = dy[k] + j;
		if (nx < 0 || nx >= (int)board.size() || ny < 0 || ny >= (int)board[0].size() || vis[nx][ny] || root->getNode(board[nx][ny]) == nullptr)continue;
		vis[nx][ny] = true;
		word.push_back(board[nx][ny]);
		dfs212(board, root->getSubNode(board[nx][ny]), dx, dy, nx, ny, vis, result_set, word);
		word.pop_back();
		vis[nx][ny] = false;
	}

}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	vector<string>res;
	if (board.empty() || board[0].empty() | words.empty())return res;
	int m = board.size(), n = board[0].size();
	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
	vector<vector<bool>>vis(m, vector<bool>(n, 0));
	set<string>result_set;
	string word;
	Trie t;
	for (string word : words)t.insert(word);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (t.getRoot()->getSubNode(board[i][j]) != nullptr && !vis[i][j])
			{
				vis[i][j] = true;
				dfs212(board, t.getRoot()->getSubNode(board[i][j]), dx, dy, i, j, vis, result_set, word + board[i][j]);
				vis[i][j] = false;
			}
		}
	}
	for (string x : result_set)res.push_back(x);
	return res;
}

class TrieNode{
public:
	TrieNode* nodes[26];
	string word;
};

TrieNode* buildTrie(vector<string>words)
{
	TrieNode* root = new TrieNode();
	for (string str : words)
	{
		TrieNode*p = root;
		for (char c : str)
		{
			int i = c - 'a';
			if (p->nodes[i] == nullptr)p->nodes[i] = new TrieNode();
			p = p->nodes[i];
		}
		p->word = str;
	}
	return root;
}


void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res)
{
	char c = board[i][j];
	if (c == '#' || p->nodes[c - 'a'] == nullptr)return;
	p = p->nodes[c - 'a'];
	if (!p->word.empty())
	{
		res.push_back(p->word);
		p->word.clear();
	}
	board[i][j] = '#';
	if (i > 0)dfs(board, i - 1, j, p, res);
	if (j > 0)dfs(board, i, j - 1, p, res);
	if (i < board.size() - 1)dfs(board, i + 1, j, p, res);
	if (j < board[0].size() - 1)dfs(board, i, j + 1, p, res);
	board[i][j] = c;
}
vector<string>findWords(vector<vector<char>>board, vector<string>& words)
{
	vector<string>res;
	TrieNode* root = buildTrie(words);
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			dfs(board, i, j, root, res);
		}
	}
	return res;
}


// 398  random pick index
/*
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

*/

class Solution {
public:
	vector<int>num;
	Solution(vector<int> nums) {
		num = nums;
		srand(time(NULL));
	}

	int pick(int target) {
		int cnt = 0;
		int index = -1;
		for (int i = 0; i<num.size(); ++i)
		{
			if (num[i] == target)
			{
				cnt++;
				if (index == -1)index = i;
				else
				{
					if (rand() % cnt == 0)index = i;
				}
			}
		}
		return index;
	}
};


//find random maximum
//reservoir sampling
//randomly return the index of maximal elements in the array
// {1,2,3,3,3} with target 3, you want to select the 3 on index 2,3,4 with a probability of 1/3 each.
// 2:probability of selection is 1* (1/2)(probability of 2nd 3 not getting 0) * (2/3)(probability of 3rd 3 not getting 0) =1/3
// 3:Its probability of selection is (1/2) * (2/3) = 1/3
// 4:Its probability of selection is just 1/3
// So they are each randomly selected.
//刚开始装，说两次，第一次求最大值，第二次再求index
class Solution {
public:
	vector<int>num;
	Solution(vector<int> nums) {
		num = nums;
		srand(time(NULL));
	}

	int pick(int target) {
		int maxValue = INT_MIN;
		int res = -1;
		int count = 0;
		for (int i = 0; i < num.size(); ++i)
		{
			if (maxValue == INT_MIN || num[i] > maxValue)
			{
				maxValue = num[i];
				res = i;
				count = 1;
			}
			else if (num[i] == maxValue)
			{
				count++;
				if (rand() % count == 0)res = i;
			}
		}
		return res;
	}
};

//random return number according to weight
// in case of -1 from findindex
// Utility function to find ceiling of r in arr[l..h]
Before we go to the implementation part, let us have quick look at the algorithm with an example :
arr[] : {10, 20, 30}
freq[] : {2, 3, 1}
Prefix[] : {2, 5, 6}
Since last entry in prefix is 6, all possible values of r are[1, 2, 3, 4, 5, 6]
1 : Ceil is 2. Random number generated is 10.
2 : Ceil is 2. Random number generated is 10.
3 : Ceil is 5. Random number generated is 20.
4 : Ceil is 5. Random number generated is 20.
5 : Ceil is 5. Random number generated is 20.
6. Ceil is 6. Random number generated is 30.
In the above example
10 is generated with probability 2 / 6.
20 is generated with probability 3 / 6.
30 is generated with probability 1 / 6.

int findindex(vector<int>& prefix, int r, int left, int right)
{
	int mid = 0;
	while (left<right)
	{
		mid = left + (right - left) / 2;
		r>prefix[mid] ? left = mid + 1 : right = mid;
	}
	return prefix[left] >= r ? left : -1;
}

int myrand(vector<int>&nums, vector<int>& frequency)
{
	int n = nums.size();
	if (n == 0)return -1;
	vector<int>prefix(n, frequency[0]);
	for (int i = 1; i<n; ++i)prefix[i] = prefix[i - 1] + frequency[i];
	int r = (rand() % prefix[n - 1]) + 1;
	int index = findindex(prefix, r, 0, n - 1);
	return nums[index];
}



// 71 simplify path
/*
given an absolute path for a file ,simplify it
*/

//@taobupt

string simplifyPath(string path)
{
	vector<string>res;
	stringstream ss(path);
	string tmp;
	while (getline(ss, tmp, '/'))
	{
		if (tmp == "" || tmp == ".")continue;
		else if (!res.empty() && tmp == "..")res.pop_back();
		else if (tmp != "..")res.push_back(tmp);
	}
	string ans;
	for (string str : res)ans += "/" + str;
	return ans.empty() ? "/" : ans;
}


//200 number of islands
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

//@taobupt

void dfs200(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& vis)
{
	for (int k = 0; k < 4; ++k)
	{
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || vis[nx][ny] || grid[nx][ny] == '0')continue;
		vis[nx][ny] = true;
		dfs200(grid, nx, ny, vis);
	}
}
int numIslands(vector<vector<char>>& grid) {
	if (grid.empty() || grid[0].empty())return 0;
	int m = grid.size(), n = grid[0].size();
	int res = 0;
	vector<vector<bool>>vis(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == '1' && !vis[i][j])
			{
				vis[i][j] = true;
				dfs200(grid, i, j, vis);
				res++;
			}
		}
	}
	return res;
}

//bfs solution
// bfs solution
public class Solution {
	private int[][] move = new int[][]{{1, 0}, { -1, 0 }, { 0, 1 }, { 0, -1 }};

	public int numIslands(char[][] grid) {
		if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
			return 0;
		}
		int m = grid.length;
		int n = grid[0].length;
		int res = 0;
		boolean[][] visited = new boolean[m][n];//O(1) space: directly modify the '1' to '2' to mark grid[i][j] visited
		Queue<Integer> queue = new LinkedList<>();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					bfs(grid, visited, queue, m, n, i, j);
					res++;
				}
			}
		}
		return res;
	}

	private void bfs(char[][] grid, boolean[][] visited, Queue<Integer> queue, int m, int n, int i, int j) {
		queue.offer(i * n + j);
		visited[i][j] = true;
		while (!queue.isEmpty()) {
			int key = queue.poll();
			i = key / n;
			j = key % n;
			for (int k = 0; k < move.length; k++) {
				int nextI = i + move[k][0];
				int nextJ = j + move[k][1];
				if (isValid(grid, visited, m, n, nextI, nextJ)) {
					queue.offer(nextI * n + nextJ);
					visited[nextI][nextJ] = true;
				}
			}
		}
	}

	private boolean isValid(char[][] grid, boolean[][] visited, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1' || visited[i][j]) {
			return false;
		}
		return true;
	}
}

// largest size of island
public class Solution {
	public int numIslands(char[][] grid) {
		if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
			return 0;
		}
		int m = grid.length;
		int n = grid[0].length;
		int max = 0;
		boolean[][] visited = new boolean[m][n];//O(1) space: directly modify the '1' to '2' to mark grid[i][j] visited
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					max = Math.max(max, dfs(grid, visited, m, n, i, j));
				}
			}
		}
		return max;
	}

	private int dfs(char[][] grid, boolean[][] visited, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1' || visited[i][j]) {//remember to add grid[i][j]!= '1' !!!
			return 0;
		}
		visited[i][j] = true;
		return 1 + dfs(grid, visited, m, n, i + 1, j) + dfs(grid, visited, m, n, i - 1, j)
			+ dfs(grid, visited, m, n, i, j + 1) + dfs(grid, visited, m, n, i, j - 1);
	}
}
//test cases:
char[][] grid = new char[][]{
	{'1', '1', '1', '0'},
	{ '1', '0', '1', '1' },
	{ '0', '1', '0', '0' },
	{ '1', '1', '0', '1' }};
// bfs solution
public class Solution {
	private int[][] move = new int[][]{{1, 0}, { -1, 0 }, { 0, 1 }, { 0, -1 }};

	public int numIslands(char[][] grid) {
		if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
			return 0;
		}
		int m = grid.length;
		int n = grid[0].length;
		int max = 0;
		boolean[][] visited = new boolean[m][n];//O(1) space: directly modify the '1' to '2' to mark grid[i][j] visited
		Queue<Integer> queue = new LinkedList<>();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					max = Math.max(bfs(grid, visited, queue, m, n, i, j));
				}
			}
		}
		return res;
	}

	private int bfs(char[][] grid, boolean[][] visited, Queue<Integer> queue, int m, int n, int i, int j) {
		int size = 0;
		queue.offer(i * n + j);
		visited[i][j] = true;
		while (!queue.isEmpty()) {
			int key = queue.poll();
			size++;
			i = key / n;
			j = key % n;
			for (int k = 0; k < move.length; k++) {
				int nextI = i + move[k][0];
				int nextJ = j + move[k][1];
				if (isValid(grid, visited, m, n, nextI, nextJ)) {
					queue.offer(nextI * n + nextJ);
					visited[nextI][nextJ] = true;
				}
			}
		}
		return size;
	}

	private boolean isValid(char[][] grid, boolean[][] visited, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1' || visited[i][j]) {
			return false;
		}
		return true;
	}
}


//perimeter of given land
//perimeter of given island
// dfs solution
public class Solution {
	public int numIslands(char[][] grid, int i, int j) {
		if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
			return 0;
		}
		int m = grid.length;
		int n = grid[0].length;
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {//if the given point is oob, or is not on a island
			return 0;
		}
		boolean[][] visited = new boolean[m][n];//O(1) space: directly modify the '1' to '2' to mark grid[i][j] visited
		return dfs(grid, visited, m, n, i, j);
	}

	private int dfs(char[][] grid, boolean[][] visited, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
			return 1;
		}
		if (visited[i][j]) {
			return 0;
		}
		visited[i][j] = true;
		return dfs(grid, visited, m, n, i + 1, j) + dfs(grid, visited, m, n, i - 1, j)
			+ dfs(grid, visited, m, n, i, j + 1) + dfs(grid, visited, m, n, i, j - 1);
	}
}
// bfs solution
public class Solution {
	private int[][] move = new int[][]{{1, 0}, { -1, 0 }, { 0, 1 }, { 0, -1 }};

	public int numIslands(char[][] grid, int i, int j) {
		if (grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
			return 0;
		}
		int m = grid.length;
		int n = grid[0].length;
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {//if the given point is oob, or is not on a island
			return 0;
		}
		boolean[][] visited = new boolean[m][n];//O(1) space: directly modify the '1' to '2' to mark grid[i][j] visited
		Queue<Integer> queue = new LinkedList<>();
		return bfs(grid, visited, queue, m, n, i, j);
	}

	private int bfs(char[][] grid, boolean[][] visited, Queue<Integer> queue, int m, int n, int i, int j) {
		int perimeter = 0;
		queue.offer(i * n + j);
		visited[i][j] = true;
		while (!queue.isEmpty()) {
			int key = queue.poll();
			i = key / n;
			j = key % n;
			for (int k = 0; k < move.length; k++) {
				int nextI = i + move[k][0];
				int nextJ = j + move[k][1];
				if (isIsland(grid, visited, m, n, nextI, nextJ) && !visited[nextI][nextJ]) {//if it's unvisited land
					queue.offer(nextI * n + nextJ);
					visited[nextI][nextJ] = true;
				}
				else if (!isIsland(grid, visited, m, n, nextI, nextJ)) {//if it's oob,or not an island
					perimeter++;
				}
			}
		}
		return perimeter;
	}

	private boolean isIsland(char[][] grid, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
			return false;
		}
		return true;
	}
}







//flood fill
public class Solution {
	private row = 0; 
		private col = 0;
		public void fillBlack(int[][] a, int x, int y) {
		if (a == null || x == null || y == null) {
				return;
		}

		row = a.length;
		col = a[0].length; 
			dfs(a, x, y);
	}
		public void dfs(int[][] a, int i, int j) {
		if (i < 0 || i >= row || j < 0 || j >= col || a[i][j] != 0) {
			return;
		}
		a[i][j] = 1;
		dfs(a, i - 1, j);
		dfs(a, i + 1, j);
		dfs(a, i, j + 1);
		dfs(a, i, j - 1);

	}
}

//221 maximal square

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
//taobupt
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty())return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>>dp(m, vector<int>(n, 0));
	int edge = 0;
	for (int i = 0; i < n; ++i)
	{
		if (matrix[0][i] == '1')
		{
			dp[0][i] = 1;
			edge = 1;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if (matrix[i][0] == '1')
		{
			dp[i][0] = 1;
			edge = 1;
		}
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = matrix[i][j] == '0' ? 0 : min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			edge = max(edge, dp[i][j]);
		}
	}
	return edge*edge;

}

//O(n) space
//As can be seen, each time when we update size[i][j], 
//we only need size[i][j - 1], size[i - 1][j - 1] (at the previous left column) 
//and size[i - 1][j] (at the current column). 
//So we do not need to maintain the full m*n matrix. 
//In fact, keeping two columns is enough. 
//Now we have the following optimized solution.
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty())return 0;
	int m = matrix.size(), n = matrix[0].size();
	vector<int>pre(m, 0);
	vector<int>cur(m, 0);
	int edge = 0;
	for (int i = 0; i < m; ++i)
	{
		pre[i] = matrix[i][0] - '0';// left column, pre[i-1]:left corner column
		edge = max(edge, pre[i]);
	}
	for (int j = 1; j < n; ++j)
	{
		cur[0] = matrix[0][j] - '0';
		edge = max(edge, cur[0]);
		for (int i = 1; i < m; ++i)
		{
			if (matrix[i][j] == '1')
			{
				cur[i] = min(cur[i - 1], min(pre[i], pre[i - 1])) + 1;
				edge = max(cur[i], edge);
			}
		}
		swap(pre, cur);
		fill(cur.begin(), cur.end(), 0);
	}
	return edge*edge;
}


//most optimal 
// below is the O(mn) time and O(m) space dp solution, only need to store one col
public class Solution {
	public int maximalSquare(char[][] matrix) {
		if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
			return 0;
		}
		int m = matrix.length;
		int n = matrix[0].length;
		int[] dp = new int[m + 1];//use dp[0] to represent the out of boundary value of every col's top row
		int max = 0;
		int prev = 0;//use this to store dp[i - 1][j - 1]
		for (int j = 0; j < n; j++) {
			for (int i = 1; i <= m; i++) {
				int temp = dp[i];//store the value of last col before updating it, which is dp[i - 1][j - 1]
				if (matrix[i - 1][j] == '1') {//cuz here our i starts from 1, so matrix[i-1][j] is the original matrix[i][j]
					dp[i] = Math.min(Math.min(dp[i - 1], dp[i]), prev) + 1;
					max = Math.max(max, dp[i]);
				}
				else {
					dp[i] = 0;//remember to add this !! 
				}
				prev = temp;//update prev, which becomes next row's dp[i - 1][j - 1]
			}
		}
		return max * max;//max*max, not max !!! cuz max is the length of the side of the max square
	}
}

//Let me explain the three values in the Math.min(Math.min(dp[i - 1], dp[i][j - 1]), prev) + 1:
//prev means dp[i - 1][j - 1] (cuz we save prev before we update last row's dp[i] value)
//dp[i] means dp[i][j - 1] (cuz it's last col's value before we updating it)
//dp[i - 1] means dp[i - 1][j] (when we use dp[i - 1], it has already been updated, so it's curr col's value of last row)
//btw, we don't need to update prev to 0 for every col's top row cuz dp[i-1=1-1=0] must be 0,
//so dp[1] must be 1 if matrix[i-1][j]=='1',no matter what value prev is


//17 letter combinations of a phone number
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
*/


//discuss is interesting
void dfs17(vector<string>& res, string& path, string digits, unordered_map<char, string>& mp, int pos)
{
	if (pos == digits.size() && digits.size() == path.size())
	{
		res.push_back(path);
		return;
	}
	else if (pos > digits.size() || path.size() > digits.size())return;
	for (int i = pos; i < digits.size(); ++i)
	{
		for (int j = 0; j < mp[digits[i]].size(); ++j)
		{
			path.push_back(mp[digits[i]][j]);
			dfs17(res, path, digits, mp, pos + 1);
			path.pop_back();
		}
	}
}
vector<string> letterCombinations(string digits) {
	//array is faster
	unordered_map<char, string>mp = { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
	vector<string>res;
	string path;
	dfs17(res, path, digits, mp, 0);
	return res;
}




/// better solution
string mp[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
	void backtracking(vector<string>& res, string digits, string path, int pos)
	{
		if (path.size() == digits.size() && pos == digits.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i<mp[digits[pos] - '2'].size(); ++i)
		{
			backtracking(res, digits, path + mp[digits[pos] - '2'][i], pos + 1);
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string>res;
		string path;
		if (digits.empty())return res;
		backtracking(res, digits, path, 0);
		return res;
	}
};


//iterative way

string mp[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string>res;
		if (digits.empty())return res;
		int n = digits.size();
		queue<string>q;
		q.push("");
		for (int i = 0; i<n; ++i)
		{
			while (q.front().size() == i)
			{
				string cur = q.front();
				q.pop();
				for (char c : mp[digits[i] - '2'])q.push(cur + c);
			}
		}
		while (!q.empty())
		{
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}
};
//bianzhong
void backtracking(vector<string>& res, string digits, string path, int pos, unordered_map<char, string>& mp)
{
	if (path.size() == digits.size() && pos == digits.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = 0; i<mp[digits[pos]].size(); ++i)
	{
		backtracking(res, digits, path + mp[digits[pos]][i], pos + 1, mp);
	}
}
vector<string> letterCombinations(string digits) {
	vector<string>res;
	string path;
	unordered_map<char, string>mp = { { 'A', "@$" }, { 'B', "&" }, { 'C', "*" } };
	if (digits.empty())return res;
	backtracking(res, digits, path, 0, mp);
	return res;
}


/*
40. 某白人，一半谈career/resume，一半问算法。题目：破解密码，提供了一个函数，isPassword(String str)，如果pass in的是正确的密码，return true。又给定了每个字母可以变形的集合（例如，字母a可以变形为a或者A或者B或者*, 字母b可以变形为B或者F或者&...，需要自己设计一个data structure来存这个mapping），设计并实现一个函数，在给定一个字符串的情况下，对字符串进行变形，最后找到正确的密码。
public List<String> letterCombinations(String digits) {
List<String> result = new ArrayList<>();
if (digits.length() == 0) {
return result;
}
char[][] chs = {{},{},{'a','b','c'}, {'d','e','f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
StringBuilder path = new StringBuilder();
helper(result, path, 0, digits, chs);
return result;
}

private void helper(List<String> result, StringBuilder path, int pos, String digits, char[][] phoneNumber) {
if (pos == digits.length()) {
result.add(new StringBuilder(path).toString());
return;
}
int digit = Integer.parseInt(digits.substring(pos, pos + 1));
for (int i = 0; i < phoneNumber[digit].length; i++) {
path.append(phoneNumber[digit][i]);
helper(result, path, pos + 1, digits, phoneNumber);
path.delete(path.length() - 1, path.length());
}
}

*/

//iterative way

vector<string> letterCombinations(string digits) {
	vector<string>res;
	if (digits.empty())return res;
	int n = digits.size();
	queue<string>q;
	q.push("");
	for (int i = 0; i<n; ++i)
	{
		while (q.front().size() == i)
		{
			string cur = q.front();
			q.pop();
			for (char c : mp[digits[i] - '2'])q.push(cur + c);
		}
	}
	while (!q.empty())
	{
		res.push_back(q.front());
		q.pop();
	}
	return res;
}

//215 Kth largest element in an array
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

//@taobupt

//quick select     O(N^2)when always pick the most right one 
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>>pq;
	int i = 0, n = nums.size();
	while (i < k)
	{
		pq.push(nums[i++]);
	}
	while (i < n)
	{
		if (pq.top() < nums[i])
		{
			pq.pop();
			pq.push(nums[i]);
		}
		i++;
	}
	return pq.top();
}


int partition(vector<int>&nums, int left, int right)
{
	int begin = left, end = right, key = nums[left];
	while (begin < end)
	{
		while (begin < end && nums[end] >= key)--end;
		nums[begin] = nums[end];
		while (begin < end && nums[begin] <= key)begin++;
		nums[end] = nums[begin];
	}
	nums[begin] = key;
	return begin;
}

int findKthMin(vector<int> A, int start, int end, int k){
	int i = partition(A, start, end);
	if (i + 1 == k){
		return A[i];
	}
	else if (i + 1<k){
		return findKthMin(A, i + 1, end, k);
	}
	else{
		return findKthMin(A, start, i - 1, k);
	}
}
// see the discuss
int findKthLargest(vector<int>& nums, int k)
{
	int n = nums.size();
	return findKthMin(nums, 0, n - 1, n - k + 1);
}

//334 increasing triple subsequence
/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

//@taobupt
bool increasingTriplet(vector<int>& nums) {
	int a = INT_MAX, b = INT_MAX;
	int n = nums.size();
	if (n < 3)return false;
	for (int x : nums)
	{
		if (x <= a)a = x;
		else if (x <= b)b = x;// equal is important
		else return true;
	}
	return false;
}





//285 inorder successor in BST
//inorder next
//inordernext
/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
*/

//@TAOBUPT
// if you have parent node

TreeNode* successor(TreeNode* p)
{
	if (root == NULL || p == NULL)return NULL;
	TreeNode* succsor = NULL;
	if (p->right)
	{
		succsor = p->right;
		while (succsor->left)succsor = succsor->left;
		return succsor;
	}
	succsor = p->parent;
	while (succsor && succsor->right == p)
	{
		p = succsor;
		succsor = succsor.parent;
	}
	return succsor;
}


//without parent node
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	if (root == NULL || p == NULL)return NULL;
	TreeNode* succsor = NULL;
	if (p->right)
	{
		succsor = p->right;
		while (succsor->left)succsor = succsor->left;
		return succsor;
	}
	TreeNode* node = root;
	while (node)
	{
		if (node->val > p->val)
		{
			succsor = node;
			node = node->left;
		}
		else if (node->val < p->val)node = node->right;
		else break;
	}
	return succsor;
}

// O(h) time and O(1) space
public class Solution {
	public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
		TreeNode successor = null;
		while (root != null) {
			if (root.val <= p.val) {//<=, not <
				root = root.right;
			}
			else {
				successor = root;
				root = root.left;
			}
		}
		return successor;
	}
}

//recrusive way
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
	if (root == NULL || p == NULL)return NULL;
	if (root->val <= p->val)return inorderSuccessor(root->right, p);
	else
	{
		TreeNode* left = inorderSuccessor(root->left, p);
		return left ? left : root;
	}
}

//predecessor
TreeNode* predecessor(TreeNode* root, TreeNode* p)
{
	if (root == NULL || p == NULL)return NULL;
	if (root->val >= p->val)return predecessor(root->left, p);
	else
	{
		TreeNode* right = predecessor(root->right, p);
		return right ? right : root;
	}
}


//311 sparse matrix multiplication
/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
[ 1, 0, 0],
[-1, 0, 3]
]

B = [
[ 7, 0, 0 ],
[ 0, 0, 0 ],
[ 0, 0, 1 ]
]


|  1 0 0|   | 7 0 0 |   |  7 0 0 |
AB =| -1 0 3| x | 0 0 0 | = | -7 0 3 |
| 0 0 1 |
*/
//taobupt

//brute force
public int[][] multiply_bruteForce(int[][] A, int[][] B) {
	int m = A.length, n = A[0].length;
	int nB = B[0].length;
	int[][] C = new int[m][nB];
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<nB; j++){
			C[i][j] = 0;
			for (int k = 0; k<n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}
	return C;
}

//better solution
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	int m = A.size(), n = A[0].size(), k = B[0].size();
	vector<vector<int>>res(m, vector<int>(k, 0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (A[i][j] != 0)
			{
				for (int z = 0; z < k; ++z)
				{
					res[i][z] += A[i][j] * B[j][z];
				}
			}
		}
	}
	return res;
}


//252 meeting rooms
//@taobupt

//Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), determine if a person could attend all meetings.

//	For example,
//	Given[[0, 30], [5, 10], [15, 20]],
//	return false.
bool canAttendMeetings(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start == b.start ? a.end<b.end : a.start<b.start; });
	int n = intervals.size();
	for (int i = 1; i < n; ++i)
	{
		if (intervals[i].start < intervals[i - 1].end)return false;
	}
	return true;
}

// 253 meeting rooms II
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
*/

//@taobupt

//interesting

int minMeetingRooms(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start; });
	priority_queue<int, vector<int>, greater<int>>pq;
	int res = 0, n = intervals.size();
	if (intervals.empty())return res;
	pq.push(intervals[0].end);
	for (int i = 1; i<n; ++i)
	{
		int top = pq.top();
		pq.pop();
		if (top <= intervals[i].start)
		{
			top = max(top, intervals[i].end);
		}
		else pq.push(intervals[i].end);
		pq.push(top);
	}
	return pq.size();
}

//some times , priority_queue is not allowed

public int minMeetingRooms(Interval[] intervals) {
	int[] starts = new int[intervals.length];
	int[] ends = new int[intervals.length];
	for (int i = 0; i<intervals.length; i++) {
		starts[i] = intervals[i].start;
		ends[i] = intervals[i].end;
	}
	Arrays.sort(starts);
	Arrays.sort(ends);
	int rooms = 0;
	int endsItr = 0;
	for (int i = 0; i<starts.length; i++) {
		if (starts[i]<ends[endsItr])
			rooms++;
		else
			endsItr++;
	}
	return rooms;
}


//priority queue, just store the smallest end time, greater<int>
public int findoverlap(Interval[] intervals) {
	if (intervals == null || intervals.length == 0) {
		return 0;
	}
	Arrays.sort(intervals, new Comparator<Interval>(){
		public int compare(Interval a, Interval b) {
			return a.start - b.start;
		}
	});
	Queue<Integer> heap = new PriorityQueue<>();//no need to store interval, we can just store the end time
	heap.offer(intervals[0].end);
	int overlapStart = -1;
	int overlapEnd = -1;
	for (int i = 1; i < intervals.length; i++) {
		if (intervals[i].start >= heap.peek()) {//if can use room that ends earliest,poll that end time,add curr end time
			heap.poll();
		}
		else {
			overlapStart = intervals[i].start;
			overlapEnd = Math.min(heap.peek(), intervals[i].end);//should be min of these two
		}
		heap.offer(intervals[i].end);//add curr end time
	}
	return overlapStart;//you can return any time between overlapStart and overlapEnd
}

// startTime stopTime
// interval


//if (p1.time == p2.time) {
//	return p1.isStart ? 1 : 0;
//}
//return p1.time - p2.time;
//p1.time<p2.time
struct Point {
	int time;
	bool isStart;
	Point(int time, bool isStart) :time(time), isStart(isStart){}
};

struct Interval{
	int start;
	int end;
	Interval(int s, int e) :start(s), end(e){}
};
vector<int> findMaxOverLapTime(vector<Interval> intervals) {
	vector<int> result;
	if (intervals.empty()) {
		return result;
	}
	vector<Point> points;
	for (Interval interval : intervals) {
		points.push_back(Point(interval.start, true));
		points.push_back(Point(interval.end, false));
	}
	sort(points.begin(), points.end(), [](Point a, Point b){return a.time != b.time ? a.time < b.time : a.isStart; });
	int max = 0;
	int number = 0;
	int start = 0;
	int end = 0;
	for (Point point : points) {
		if (point.isStart) {
			number++;
			if (number > max) {
				max = number;
				start = point.time;
				end = point.time;
			}
		}
		else {
			if (number == max) {
				end = point.time;
			}
			number--;
		}
	}
	for (int i = start; i < end; i++) {
		result.push_back(i);
	}
	return result;
}



int findMaxOverLapTime1(vector<Interval> intervals) {
	int res = INT_MAX;
	if (intervals.empty()) {
		return res;
	}
	vector<Point> points;
	for (Interval interval : intervals) {
		points.push_back(Point(interval.start, true));
		points.push_back(Point(interval.end, false));
	}
	sort(points.begin(), points.end(), [](Point a, Point b){return a.time != b.time ? a.time < b.time : a.isStart; });
	int max = 0;
	int number = 0;
	int start = 0;
	//int end = 0;
	for (Point point : points) {
		if (point.isStart) {
			number++;
			if (number > max) {
				max = number;
				start = point.time;
				//end = point.time;
			}
		}
		else number--;
	}
	return start;
}

struct Point{
int time;
bool isStart;
Point(int time,bool isStart):time(time),isStart(isStart){}
};

public class TimeSlot {
	int time;
	boolean isStart;
	public TimeSlot(int t, boolean i) {
		time = t;
		isStart = i;
	}
}

//return the num of romm used/employee of each non-overlapping time range
//O(nlogn) time, O(n) space
public List<String> meetingRooms(Interval[] intervals) {
	List<String> res = new ArrayList<>();
	if (intervals == null || intervals.length == 0) {
		return res;
	}
	List<TimeSlot> times = new ArrayList<>();
	for (Interval i : intervals) {//spilt the start time and end time, then sort them
		times.add(new TimeSlot(i.start, true));//use the boolean to regconize if it's a start or end time
		times.add(new TimeSlot(i.end, false));
	}
	Collections.sort(times, new Comparator<TimeSlot>(){
		public int compare(TimeSlot a, TimeSlot b) {
			return a.time - b.time;
		}
	});
	int count = 1;
	int begin = 0;//it's the index of begin time, not the time itself
	for (int i = 1; i < times.size(); i++) {
		if (times.get(i).time != times.get(i - 1).time) {//only add time range to res when there is a diff between two times, if you don't want to 2008-2008, you should add .time
			res.add(times.get(begin).time + "-" + times.get(i).time + ": " + count);//add to res before count is gonna be changed
			begin = i;//update begintime's index
		}
		if (times.get(i).isStart) {//count curr num of people/rooms
			count++;
		}
		else {
			count--;
		}
	}
	return res;
}


// return the time ranges of free time between startTime and endTime (time ranges that have no meetings):
// O(nlogn) time, O(1) space
public class Solution {
	public List<String> minMeetingRooms(Interval[] intervals, int start, int end) {
		List<String> res = new ArrayList<>();
		if (intervals == null || intervals.length == 0) {
			return res;
		}
		Collections.sort(intervals, new Comparator<Interval>(){
			public int compare(Interval a, Interval b) {
				return a.start - b.start;
			}
		});
		int begin = start;//the beginTime of freeTime (end of last meeting)
		for (Interval i : intervals) {
			if (begin >= end) {//if the start of free time is out of range(exceeds end), break the loop
				break;
			}
			if (i.start > begin) {//only add time range to res when there is a diff(free time) between two times
				res.add(begin + "-" + Math.min(i.start, end));//if the i.start exceeds end, we pick end to be the boundary
			}
			begin = Math.max(begin, i.end);//update begintime
		}
		return res;
	}
}

//261 graph valid tree
//valid graph tree
/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
*/
// we can use union find to detect if there is cycle;
// undirected graph can use union find to detect circle
//directed graph can use topological sort to detect circle
////union-find solution, O(edges * nodes) times
int findParent(vector<int>& parent, int x)
{
	while (parent[x] != x)
	{
		parent[x] = parent[parent[x]];// path compress;
		x = parent[x];
	}
	return x;
}

bool mix(int x, int y, vector<int>& parent)
{

	int yy = findParent(parent, y);
	int xx = findParent(parent, x);
	if (xx != yy)
	{
		parent[xx] = y;
		return true;
	}
	return false;
}
bool validTree(int n, vector<pair<int, int>>& edges) {
	vector<int>parent(n);
	for (int i = 0; i < n; ++i)parent[i] = i;
	int nn = edges.size();
	for (int i = 0; i < nn; ++i)
	{
		if (!mix(edges[i].first, edges[i].second, parent))return false;
	}
	return edges.size() == n - 1;
}


bool validTree(int n, vector<pair<int, int>>& edges) {
	vector<int> nodes(n, 0);
	for (int i = 0; i<n; i++) nodes[i] = i;
	for (int i = 0; i<edges.size(); i++){
		int f = edges[i].first;
		int s = edges[i].second;
		while (nodes[f] != f) f = nodes[f];
		while (nodes[s] != s) s = nodes[s];
		if (nodes[f] == nodes[s]) return false;
		nodes[s] = f;
	}
	return edges.size() == n - 1;
}





//161 one edit distance
/*
Given two strings S and T, determine if they are both one edit distance apart.
*/
//my solutuion 

//@taobupt redundant
bool isOneEditDistance(string s, string t)
{
	//abs(s.size()-t.size()) is wrong
	int m = s.size(), n = t.size();
	if (abs(m - n) > 1)return false;
	if (m == n)
	{
		for (int i = 0; i < m; ++i)
		{
			if (s[i] != t[i])
			{
				s[i] = t[i];
				return s == t;
			}
		}
		return false;// in this situation, s==t, the edit distance is 0
	}
	else if (m < n)
	{
		for (int i = 0; i < m; ++i)
		{
			if (s[i] != t[i])
			{
				s = s.substr(0, i) + t[i] + s.substr(i);
				return s == t;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			if (s[i] != t[i])
			{
				t = t.substr(0, i) + s[i] + t.substr(i);
				return s == t;
			}
		}
		return true;
	}
}
// optimal
bool isOneEditDistanceConcise(string s, string t)
{
	int m = s.size(), n = t.size();
	if (m > n)return isOneEditDistanceConcise(t, s);
	if (n - m > 1)return false;
	bool mismatch = false;
	for (int i = 0; i < m; ++i)
	{
		if (s[i] != t[i])
		{
			if (m == n)s[i] = t[i];
			else s.insert(i, 1, t[i]);
			mismatch = true;
			break;
		}
	}
	return (!mismatch && n - m == 1) || (mismatch && s == t);// if the diff of the lenght is 1 and the other part is the same. the mismatch would be false;
}

// binary tree vertical order traversal
/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.
*/
//@taobupt



//double linkedlist

struct doubleList{
	int sum;
	vector<int> val;
	doubleList *left;
	doubleList *right;
};
class Solution {
public:
	vector<vector<int>> verticalOrder(TreeNode* root) {
		//Double Linked List. Fastest

		vector<vector<int> > res;
		if (!root)
			return res;
		doubleList *mid = new doubleList();
		queue<pair<TreeNode *, doubleList *> > Q;
		Q.push({ root, mid });
		doubleList *leftbound = mid;
		while (!Q.empty())
		{
			auto node = Q.front();
			Q.pop();
			node.second->val.push_back(node.first->val);
			node.second->sum += node.first->val;
			if (node.first->left)
			{
				if (node.second->left == NULL)
				{
					node.second->left = new doubleList();
					node.second->left->right = node.second;
					leftbound = node.second->left;
				}
				Q.push({ node.first->left, node.second->left });
			}
			if (node.first->right)
			{
				if (node.second->right == NULL)
				{
					node.second->right = new doubleList();
					node.second->right->left = node.second;
				}
				Q.push({ node.first->right, node.second->right });
			}
		}
		while (leftbound)
		{
			cout << leftbound->sum << endl;
			res.push_back(leftbound->val);
			leftbound = leftbound->right;
		}
		return res;
	}
}

// key collison; 
//Separate chaining:Separate chaining with linked lists,head cells
//open addressing
//best solution O(N)
//HashMap + bfs solution with O(n) time and space
////If you wanna avoid using hashmap cuz of key conflicts,you can use doubly-linked list,each node stores a Arraylist of vals,
vector<vector<int>> verticalOrder(TreeNode* root) {
	vector<vector<int>>res;
	if (root == nullptr)return res;
	unordered_map<int, vector<int>>mp;
	queue<pair<int, TreeNode*>>q;
	q.push({ 0, root });
	int minValue = 0, maxValue = 0;
	while (!q.empty())
	{
		int tmp = q.front().first;
		TreeNode* node = q.front().second;
		q.pop();
		mp[tmp].push_back(node->val);
		minValue = min(minValue, tmp);
		maxValue = max(maxValue, tmp);
		if (node->left)q.push({ tmp - 1, node->left });
		if (node->right)q.push({ tmp + 1, node->right });
	}
	for (int i = minValue; i <= maxValue; ++i)res.push_back(mp[i]);
	return res;
}

//using map to store. O(NLOGN)
vector<vector<int>> verticalOrder(TreeNode* root) {
	vector<vector<int>>res;
	if (root == NULL)return res;
	queue<pair<TreeNode*, int>>q;
	map<int, vector<int>>mp;
	q.push(make_pair(root, 0));
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			TreeNode* node = q.front().first;
			int tmp = q.front().second;
			q.pop();
			mp[tmp].push_back(node->val);
			if (node->left)q.push(make_pair(node->left, tmp - 1));
			if (node->right)q.push(make_pair(node->right, tmp + 1));
		}
	}
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		res.push_back(it->second);
	}
	return res;
}


// there is no need to calculate first
void getRange(TreeNode* root, int width[], int depth)
{
	if (root == NULL)return;
	width[0] = min(depth, width[0]);
	width[1] = max(depth, width[1]);
	getRange(root->left, width, depth - 1);
	getRange(root->right, width, depth + 1);
}
vector<vector<int>> verticalOrder(TreeNode* root) {
	int width[2] = { 0, 0 };
	getRange(root, width, 0);
	vector<vector<int>>res;
	if (root == NULL)return res;
	res.resize(width[1] - width[0] + 1);
	queue<pair<TreeNode*, int>>q;
	q.push(make_pair(root, -width[0]));
	while (!q.empty())
	{
		TreeNode* node = q.front().first;
		int index = q.front().second;
		q.pop();
		res[index].push_back(node->val);
		if (node->left)q.push(make_pair(node->left, index - 1));
		if (node->right)q.push(make_pair(node->right, index + 1));
	}
	return res;
}
// 286 walls and gates
/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
0  -1 INF INF
After running your function, the 2D grid should be:
3  -1   0   1
2   2   1  -1
1  -1   2  -1
0  -1   3   4
*/
//@taobupt
#ifndef INF
#define INF 2147483647
#endif // !INF

void wallsAndGates(vector<vector<int>>& rooms) {
	if (rooms.empty() || rooms[0].empty())return;
	int m = rooms.size(), n = rooms[0].size();
	queue<pair<int, int>>q;
	for (int i = 0; i<m; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			if (rooms[i][j] == 0)q.push(make_pair(i, j));
		}
	}
	while (!q.empty())
	{
		int row = q.front().first, col = q.front().second;
		q.pop();
		if (row>0 && rooms[row - 1][col] == INF)
		{
			rooms[row - 1][col] = rooms[row][col] + 1;
			q.push(make_pair(row - 1, col));
		}
		if (row<m - 1 && rooms[row + 1][col] == INF)
		{
			rooms[row + 1][col] = rooms[row][col] + 1;
			q.push(make_pair(row + 1, col));
		}
		if (col>0 && rooms[row][col - 1] == INF)
		{
			rooms[row][col - 1] = rooms[row][col] + 1;
			q.push(make_pair(row, col - 1));
		}
		if (col<n - 1 && rooms[row][col + 1] == INF)
		{
			rooms[row][col + 1] = rooms[row][col] + 1;
			q.push(make_pair(row, col + 1));
		}
	}

}

//dfs way
//dfs solution
public class Solution {
	public void wallsAndGates(int[][] rooms) {
		if (rooms == null || rooms.length == 0 || rooms[0] == null || rooms[0].length == 0) {
			return;
		}
		int m = rooms.length;
		int n = rooms[0].length;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (rooms[i][j] == 0) {
					dfs(rooms, i, j, 0);
				}
			}
		}
	}

	private void dfs(int[][] rooms, int x, int y, int val) {//val means the curr distance from gate
		if (x < 0 || x >= rooms.length || y < 0 || y >= rooms[0].length || rooms[x][y] < val) {//skip -1 and longer distance
			return;//should be rooms[x][y] < val, not rooms[x][y] <= val because this will skip the 0 (gate)
		}
		rooms[x][y] = val;//if intended val <= curr val, we will change the curr val
		dfs(rooms, x + 1, y, val + 1);
		dfs(rooms, x - 1, y, val + 1);
		dfs(rooms, x, y + 1, val + 1);
		dfs(rooms, x, y - 1, val + 1);
	}
}


//281 zigzag iterator
/*
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/

//taobupt

class ZigzagIterator {
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		if (!v1.empty())q.push(make_pair(v1.begin(), v1.end()));
		if (!v2.empty())q.push(make_pair(v2.begin(), v2.end()));
	}

	int next() {
		vector<int>::iterator it = q.front().first;
		vector<int>::iterator end = q.front().second;
		q.pop();
		int val = *it;
		if (it + 1 != end)q.push(make_pair(it + 1, end));
		return val;
	}

	bool hasNext() {
		return !q.empty();
	}
private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>>q;
};

//146 LRU Cache
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

//LTE because each time I when I delete the element , the time complexity is O(n);// oops
class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())return -1;
		setRecentlyUsed(key);
		return mp[key];
	}

	void set(int key, int value) {
		if (mp.find(key) == mp.end())
		{
			if (mp.size() >= _capacity)
			{
				mp.erase(l.front());
				l.pop_front();
			}
			mp[key] = value;
			l.push_back(key);
		}
		else
		{
			setRecentlyUsed(key);
			mp[key] = value;
		}
	}
	void setRecentlyUsed(int key)// the end part of the list is high priority
	{
		l.remove(key);
		l.push_back(key);
	}
private:
	list<int>l;
	unordered_map<int, int>mp;
	int _capacity;
};

// the right version, we should erase the iterator of the list, so we should store the iterator of the value into map, so that when we want to delete the key, we can delete it fron the list in constant time.
class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		if (mp.find(key) == mp.end())return -1;
		setRecentlyUsed(key);
		return mp[key].first;
	}

	void set(int key, int value) {
		if (mp.find(key) == mp.end())
		{
			if (mp.size() >= _capacity)
			{
				mp.erase(l.back());
				l.pop_back();
			}
			l.push_front(key);
		}
		else setRecentlyUsed(key);
		mp[key] = make_pair(value, l.begin());
	}
private:
	list<int>l;
	unordered_map<int, pair<int, list<int>::iterator>>mp;
	int _capacity;
	void setRecentlyUsed(int key)// the begin part of the list is high priority
	{
		l.erase(mp[key].second);
		l.push_front(key);
		mp[key].second = l.begin();
	}
};

class keyValueStore {
public:
	KeyValueStore(int capacity) {
	}

	int get(int key) {
		if (mp.find(key) == mp.end())return -1;
		setRecentlyUsed(key);
		return mp[key].first;
	}

	void add(int key, int value) {
		if (mp.find(key) == mp.end())
		{ 
			l.push_front(key);
		}
		else setRecentlyUsed(key);
		mp[key] = make_pair(value, l.begin());
	}

	bool remove(int key)
	{
		if (mp.find(key) == mp.end())return false;
		else
		{
			l.pop_front();
			mp.erase(key);
			return true;
		}
	}

	int getLastKey()
	{
		return l.front();
	}
private:
	list<int>l;
	unordered_map<int, pair<int, list<int>::iterator>>mp;
	int _capacity;
	void setRecentlyUsed(int key)// the begin part of the list is high priority
	{
		l.erase(mp[key].second);
		l.push_front(key);
		mp[key].second = l.begin();
	}
};



//lt 128 longest consecutive sequence
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
// my solution O(nlogn)
//@taobupt we should sort it first and then we should remove the duplicate 

int longestConsecutive(vector<int>& nums)
{
	if (nums.empty())return 0;
	int n = nums.size(), maxLength = 1, start = 0;
	sort(nums.begin(), nums.end());
	int k = 1, j = 1;
	while (k < n)//remove duplicate;
	{
		if (nums[k] != nums[k - 1])nums[j++] = nums[k];
		k++;
	}
	for (int i = 1; i < j; ++i)
	{
		if (nums[i] != nums[i - 1] + 1)
		{
			maxLength = max(i - start, maxLength);
			start = i;
		}
		else
		{
			maxLength = max(i - start + 1, maxLength);
		}
	}
	return maxLength;
}


//set usage
int longestConsecutive(vector<int> &num)
{
	unordered_set<int>record(num.begin(), num.end());
	int res = 1;
	for (int n : num)
	{
		if (record.find(n) == record.end())continue;
		record.erase(n);
		int prev = n - 1, next = n + 1;
		while (record.find(prev) != record.end())record.erase(prev--);
		while (record.find(next) != record.end())record.erase(next++);
		res = max(res, next - prev - 1);
	}
	return res;
}










//256 paint house
/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

//@taobupt  //O(n) spaces;//
int minCost(vector<vector<int>>& costs) {
	int m = costs.size();
	if (m == 0)return 0;
	for (int i = 1; i<m; ++i)
	{
		costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
		costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
		costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
	}
	return min(costs[m - 1][0], min(costs[m - 1][1], costs[m - 1][2]));
}


//276 paint fence
/*
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.
*/

//taobupt

// idea, you can start from 1,2;;;;; when the last two color are the same



// 1 2 3->>> (1,1),(2,2),(3,3), (1,2),(2,3),(1,3),(3,2),(3,1),(2,1) 
// go to next step, (1,1,1) is not alloweed, so only diff can be allowed ,so same=diff, and diff=(diff+same)*(k-1)
int numWays(int n, int k)
{
	if (n == 0)return 0;
	else if (n == 1)return k;
	int diff = k*(k - 1), same = k;
	for (int i = 2; i < n; ++i)
	{
		int tmp = diff;
		diff = (same + diff)*(k - 1);
		same = tmp;
	}
	return same + diff;//
}


// paint house II 265
/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
*/

// time complexity O(NK), space O(1)

// the first though
int minCostII(vector<vector<int>>& costs) {
	if (costs.size() == 0 || costs[0].size() == 0)return 0;
	int m = costs.size(), n = costs[0].size(), ans = INT_MAX;
	vector<vector<int>>dp(m + 1, vector<int>(n, 0));//dp[i][j] i is the house,j is the color;
	for (int i = 0; i<n; ++i)dp[1][i] = costs[0][i];
	for (int i = 2; i <= m; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			ans = INT_MAX;
			for (int k = 0; k<n; ++k)
			{
				if (k != j)
				{
					ans = min(ans, dp[i - 1][k] + costs[i - 1][j]);
				}
			}
			dp[i][j] = ans;
			// dp[i][0]=min(dp[i-1][1]+costs[i-1][0],dp[i-1][2]+costs[i-1][0]);
			// dp[i][1]=min(dp[i-1][0]+costs[i-1][1],dp[i-1][2]+costs[i-1][1]);
			// dp[i][2]=min(dp[i-1][1]+costs[i-1][2],dp[i-1][0]+costs[i-1][2]);
		}
	}
	ans = INT_MAX;
	for (int x : dp[m])ans = min(ans, x);
	return ans;
}

//save space
int minCostII(vector<vector<int>>& costs)
{
	if (costs.empty() || costs[0].empty())return 0;
	int m = costs.size(), n = costs[0].size(), res = INT_MAX;
	for (int i = 1; i < m; ++i)
	{
		int firstMin = INT_MAX, secondMin = INT_MAX;
		//we can store the first MAX and second max first
		for (int x : costs[i - 1])
		{
			if (x < firstMin)
			{
				secondMin = firstMin;
				firstMin = x;
			}
			else if (x < secondMin)
			{
				secondMin = x;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			costs[i][j] += costs[i - 1][j] == firstMin ? secondMin : firstMin;// a little tricky
		}
	}
	for (int x : costs[m - 1])res = min(res, x);
	return res;
}


// better
//wonderful
int minCostII(vector<vector<int>>& costs)
{
	if (costs.empty() || costs[0].empty())return 0;
	int m = costs.size(), n = costs[0].size(), res = INT_MAX;
	int min1 = -1;// min1 is the index of the 1-st smallest cost till previous house
	int min2 = -1;// min2 is the index of the 2nd smallest cost till previous house
	for (int i = 0; i < m; ++i)
	{
		int last1 = min1, last2 = min2;
		min1 = -1, min2 = -2;
		for (int j = 0; j < n; ++j)
		{
			if (j != last1)
			{
				costs[i][j] += last1 < 0 ? 0 : costs[i - 1][last1];
			}
			else costs[i][j] += last2 < 0 ? 0 : costs[i - 1][last2];
			if (min1 < 0 || costs[i][j] < costs[i][min1])
			{
				min2 = min1;
				min1 = j;
			}
			else if (min2 < 0 || costs[i][j] < costs[i][min2])min2 = j;
		}
	}
	return costs[m - 1][min1];

}


//10 regular expression matching
/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

//O(2 ^ n) time, O(n) space, n is length of p(each part can be matched or not matched)
bool isMatch(string s, string p)
{
	if (p.empty())return s.empty();
	if ('*' == p[1])return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
	else return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
}

//dynamic programming
// dp, O(mn) time, O(mn) space:
bool isMatch(string s, string p)
{
	int m = s.size(), n = p.size();
	vector<vector<bool>>f(m + 1, vector<bool>(n + 1, false));
	f[0][0] = true;
	for (int i = 1; i <= m; ++i)f[i][0] = false;
	for (int j = 1; j <= n; ++j)
		f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] != '*')f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
			else f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
		}
	}
	return f[m][n];
}

// save space
bool isMatch(string s, string p) {
	int m = s.size();
	int n = p.size();
	vector<bool> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++){
		dp[i] = i>1 && ('*' == p[i - 1]) && dp[i - 2];
	}

	bool left_up;
	for (int i = 0; i < m; i++){
		left_up = dp[0];
		dp[0] = 0;
		for (int j = 0; j < n; j++){
			int up = dp[j + 1];
			if (p[j] != '*') dp[j + 1] = (s[i] == p[j] || '.' == p[j]) && left_up;
			else dp[j + 1] = dp[j - 1] || dp[j + 1] && (s[i] == p[j - 1] || '.' == p[j - 1]);
			left_up = up;
		}
	}
	return dp[n];
}

//TLE
//44 wildcard matching

/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
bool isMatch44(string s, string p) {
	if (p.empty())return s.empty();
	if (s.empty())
	{
		if (p.empty())return true;
		for (char c : p)if (c != '*')return false;
		return true;
	}
	if ('*' == p[0])return (isMatch44(s, p.substr(1)) || isMatch44(s.substr(1), p));
	else return !s.empty() && (s[0] == p[0] || '?' == p[0]) && isMatch44(s.substr(1), p.substr(1));
}

//dynamic programming , although it is slow, but it is eligible
bool isMatch(string s, string p)
{
	int m = s.size(), n = p.size();
	vector<vector<bool>>f(m + 1, vector<bool>(n + 1, false));
	f[0][0] = true;
	for (int i = 1; i <= m; ++i)f[i][0] = false;
	for (int j = 1; j <= n; ++j)
		f[0][j] = f[0][j - 1] && p[j - 1] == '*';
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] != '*')f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '?' == p[j - 1]);
			else f[i][j] = f[i][j - 1] || f[i - 1][j];
		}
	}
	return f[m][n];
}

//53 maximum subarray sum
int maxSubArray(vector<int>& nums) {
	int sum1 = 0, res = INT_MIN;;
	for (int x : nums)
	{
		if (sum1 >= 0)sum1 += x;
		else sum1 = x;
		res = max(res, sum1);
	}
	return res;
}


public class MaxSumRectangleIn2DMatrix {

	public static void main(String[] args) {
		int[][] M = { { 1, 2, -1, -4, -20 },
		{ -8, -3, 4, 2, 1 },
		{ 3, 8, 10, 1, 3 },
		{ -4, -1, 1, 7, -6 }
		};
		findMaxSum(M);
	}

	// Time Complexity: O(n^3)  
	public static void findMaxSum(int[][] M){
		int maxSum = Integer.MIN_VALUE;
		int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;
		int ROW = M.length, COL = M[0].length;
		int[] temp = new int[ROW];
		int[] startFinnish = { 0, 0 };        // [0]:start值，[1]:finnish值  

		// Set the left column  
		for (int left = 0; left<COL; left++){       // 从左边开始的列号  
			Arrays.fill(temp, 0);                       // 每次重新开始计算时必须清空temp  
			// Set the right column for the left column set by outer loop  
			for (int right = left; right<COL; right++){ // 到右边结束的列号  
				// Calculate sum between current left and right for every row 'i'  
				for (int i = 0; i<ROW; i++){            // 把当前检测的那“一列”放在temp数组中(temp[i] = M[i][right];)  
					temp[i] += M[i][right];         // 那“一列”随着右边结束行号的扩大而不断横向累加(temp[i] += M[i][right];)  
				}

				// Find the maximum sum subarray in temp[]. The kadane() function  
				// also sets values of start and finish.  So 'sum' is sum of  
				// rectangle between (start, left) and (finish, right) which is the  
				//  maximum sum with boundary columns strictly as left and right.  
				int sum = kadane(temp, startFinnish, ROW);      // 计算temp中的最大连续数组  

				// Compare sum with maximum sum so far. If sum is more, then update  
				// maxSum and other output values  
				if (sum > maxSum){        // 保存全局最优值  
					maxSum = sum;
					finalLeft = left;
					finalRight = right;
					finalTop = startFinnish[0];
					finalBottom = startFinnish[1];
				}
			}
		}

		System.out.format("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
		System.out.format("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
		System.out.format("Max sum is: %d\n", maxSum);
	}

	// Implementation of Kadane's algorithm for 1D array. The function returns the  
	// maximum sum and stores starting and ending indexes of the maximum sum subarray  
	// at addresses pointed by start and finish pointers respectively.  
	private static int kadane(int[] A, int[] startFinnish, int n) {
		int sum = 0, maxSum = Integer.MIN_VALUE;
		startFinnish[1] = -1;       // Just some initial value to check for all negative values case  
		int localStart = 0;

		for (int i = 0; i<n; i++){
			sum += A[i];
			if (sum < 0){
				sum = 0;
				localStart = i + 1;
			}
			else if (sum > maxSum){
				maxSum = sum;
				startFinnish[0] = localStart;
				startFinnish[1] = i;
			}
		}

		if (startFinnish[1] != -1){      // There is at-least one non-negative number  
			return maxSum;
		}

		maxSum = A[0];      // Special Case: When all numbers in arr[] are negative  
		startFinnish[0] = startFinnish[1] = 0;
		for (int i = 1; i<n; i++){       // Find the maximum element in array  
			if (A[i] > maxSum){
				maxSum = A[i];
				startFinnish[0] = startFinnish[1] = i;
			}
		}
		return maxSum;
	}

}

//very important
//follow up 
//Maximum sum rectangle in a 2D matrix
//leetcode 363 363. Max Sum of Rectangle No Larger Than K
// actually you can solve maximum sum rectangle in 2d arrays, dynamic programming
//The naive solution is brute-force, which is O((mn)^2)




//lt 410 split array largest sum
/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/
//taobupt

bool doable(vector<int>& nums, int cuts, long long maxi)
{
	int acc = 0;
	for (int num : nums)
	{
		if (num + acc <= maxi)acc+=num;
		else
		{
			--cuts;
			acc = num;
			if (cuts < 0)return false;
		}
	}
	return true;
}

int splitArray(vector<int>& nums, int m)
{
	long long left = 0, right = 0, mid = 0;
	for (int num : nums)
	{
		left = max(left, (long long)num);
		right+=num;
	}
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (doable(nums, m - 1, mid))right = mid;
		else left = mid + 1;
	}
	return left;
}



//68 text justication
/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
*/

//@taobupt

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string>res;
	if (words.empty() || maxWidth == 0)return{ "" };
	int n = words.size();
	for (int i = 0, w; i < n; i = w)
	{
		int len = -1;
		for (w = i; w < n && len + words[w].size() + 1 <= maxWidth; ++w)
		{
			len += words[w].size() + 1;
		}
		int evenlyDistributedSpace = 1;
		int extraSpace = 0;
		int numOfGapsBwWords = w - i - 1;
		if (w != i + 1 && w != n)
		{
			evenlyDistributedSpace = ((maxWidth - len) / numOfGapsBwWords) + 1;
			extraSpace = (maxWidth - len) / numOfGapsBwWords;
		}
		string str = words[i];
		for (int j = i + 1; j < w; ++j)
		{
			for (int s = 0; s < evenlyDistributedSpace; ++s)str.push_back(' ');
			if (extraSpace > 0)
			{
				str.push_back(' ');
				extraSpace--;
			}
			str+=words[j];
		}
		int remaining = maxWidth - str.size();
		while (remaining > 0)
		{
			str.push_back(' ');
			remaining--;
		}
		res.push_back(str);
	}
	return res;
}

//leetcode 206 reverseLinkedList

//print linkedlist reversely, recursive (print linked list, no reverse)

void reverseList(ListNode* head)
{
	if (head == nullptr)return;
	reverseList(head->next);
	cout << head->val << " ";
}

//print linkedlist iteative, you can use string to store first
void reverseList(ListNode* head)
{
	if (head == nullptr)return;
	ListNode* prev = nullptr;
	while (head)
	{
		ListNode* tmp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	while (prev)
	{
		cout << prev->val << "  ";
		prev = prev->next;
	}
}

//if we need to use O(logn) space ? we can use recursion to print the right part, and then the left part
//O(nlogn) time, O(logn) space


void helper(ListNode* head, int length)
{
	if (length == 1)
	{
		cout << head->val << " ";
		return;
	}
	ListNode* curr = head;
	int count = 0;
	while (count < length / 2)
	{
		curr = curr->next;
		count++;
	}
	helper(curr, length - length / 2);
	helper(head, length / 2);
}
void reverseList(ListNode* head)
{
	if (head == nullptr)return;
	ListNode* cur = head;
	int length = 0;
	while (curr)
	{
		curr = curr->next;
		length++;
	}
	helper(head, length);
}



ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* after = head->next;
	while (after)
	{
		cur->next = prev;
		prev = cur;
		cur = after;
		after = after->next;
	}
	cur->next = prev;
	return cur;
}

ListNode* reverseList(ListNode* head) {
	ListNode* newHead = NULL;
	while (head)
	{
		ListNode* next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}


//recursive way
ListNode* reverseList(ListNode* head) {
	if(head==NULL||head->next==NULL)return head;
	ListNode* node=reverseList(head->next);
	head->next->next=head;
	head->next=NULL;
	return node;
}




//28 count and say
string countAndSay(int n)
{
	if (n == 0)return "";
	string res = "1";
	while (--n)
	{
		string cur = "";
		for (int i = 0; i < res.size(); ++i)
		{
			int count = 1;
			while (i + 1 < res.size() && (res[i] == res[i + 1]))
			{
				count++;
				i++;
			}
			cur += to_string(count) + res[i];
		}
		res = cur;
	}
	return res;
}

//127 word ladder
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
	if (beginWord == endWord)return 1;
	int ans = 2;
	int n = beginWord.size();
	queue<string>q;
	q.push(beginWord);
	if (wordList.find(beginWord) != wordList.end())wordList.erase(beginWord);
	string cur;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			cur = q.front();
			q.pop();
			for (int i = 0; i<n; ++i)
			{
				char letter = cur[i];
				for (char c = 'a'; c <= 'z'; ++c)
				{
					cur[i] = c;
					if (cur == endWord)return ans;
					if (wordList.find(cur) != wordList.end())
					{
						wordList.erase(cur);
						q.push(cur);
					}
				}
				cur[i] = letter;
			}
		}
		ans++;
	}
	return 0;
}


//one path
public List<String> findLadder(String start, String end, Set<String> dict) {
	Queue<String> queue = new LinkedList<>();
	HashMap<String, String> path = new HashMap<>();
	List<String> result = new ArrayList<>();
	queue.offer(start);
	path.put(start, "");
	while (!queue.isEmpty()) {
		String word = queue.poll();
		for (int i = 0; i < word.length(); i++) {
			for (char c = 'a'; c <= 'z'; c++) {
				if (word.charAt(i) == c) {
					continue;
				}
				String newWord = word.substring(0, i) + c + word.substring(i + 1);
				if (newWord.equals(end)) {
					path.put(end, word);
					break;
				}
				if (dict.contains(newWord) && !path.containsKey(newWord)) {
					path.put(newWord, word);
					queue.offer(newWord);
				}
			}
		}
	}
	if (!path.containsKey(end)) {
		return result;
	}
	String mover = end;
	while (!path.get(mover).equals("")) {
		result.add(mover);
		mover = path.get(mover);
	}
	result.add(start);
	Collections.reverse(result);
	return result;
}

//lt 234
//Palindrome Linked List
//Given a singly linked list, determine if it is a palindrome.
// that easy, actually, you can push all node to vector, and then you change it into
//verify whether the vector is palindrome, but it is space wasting
ListNode* reverseList(ListNode* head) {
	ListNode* newHead = NULL;
	while (head)
	{
		ListNode* next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}

bool isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL)return true;
	ListNode* part1 = head;
	ListNode* part2 = head->next;
	while (part2 && part2->next)
	{
		part1 = part1->next;
		part2 = part2->next->next;
	}
	part2 = part1->next;
	part1->next = NULL;
	part1 = head;
	part2 = reverseList(part2);
	while (part2)
	{
		if (part1->val != part2->val)return false;
		part1 = part1->next;
		part2 = part2->next;
	}
	return true;
}

//25 reverse Node in K-group




//beeter
//recurisive O(N)time and O(n/k) space
ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* curr = head;
	int count = 0;
	while (curr&&count != k)
	{
		curr = curr->next;
		count++;
	}
	if (count == k)
	{
		curr = reverseKGroup(curr, k);
		while (count-->0)
		{
			ListNode* tmp = head->next;
			head->next = curr;
			curr = head;
			head = tmp;
		}
		head = curr;
	}
	return head;
}
//iterative way
//// iterative: O(n) time O(1) space
ListNode* reverse(ListNode* head, int k)
{
	ListNode* prev = nullptr;
	for (int i = 0; i<k; ++i)
	{
		ListNode* tmp = head->next;
		head->next = prev;
		prev = head;
		head = tmp;
	}
	return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == nullptr || k<0)return head;
	ListNode* dummy = new ListNode(0);
	ListNode* prev = dummy;
	ListNode* tail = head;
	dummy->next = head;
	while (true)
	{
		ListNode* tmp = head;
		int i = 0;
		while (i<k && head != nullptr)
		{
			head = head->next;
			i++;
		}
		if (i != k && head == nullptr)break;
		prev->next = reverse(tmp, k);
		tail->next = head;//the next group of nodes;// k+1 nodes
		prev = tail;
		tail = head;
	}
	return dummy->next;
}






//404  sum of left leaves;
void dfsLeafLeaves(TreeNode* root, int &res)
{
	if (root == NULL || root->left == NULL && root->right == NULL)return;
	if (root->left && root->left->left == NULL && root->left->right == NULL)
	{
		res += root->left->val;
	}
	if (root->left)
	{
		dfsLeafLeaves(root->left, res);
	}
	if (root->right)
	{
		dfsLeafLeaves(root->right, res);
	}
}
int sumOfLeftLeaves(TreeNode* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL))return 0;
	int res = 0;
	dfsLeafLeaves(root, res);
	return res;
}

int sumOfLeftLeaves(TreeNode* root) {
	if (root == NULL)return 0;
	int ans = 0;
	if (root->left)
	{
		if (root->left->left == NULL && root->left->right == NULL)ans += root->left->val;
		else ans += sumOfLeftLeaves(root->left);
	}
	ans += sumOfLeftLeaves(root->right);
	return ans;
}

//// iterative: O(n) time, O(n) space
int sumOfLeftLeaves(TreeNode* root) {
	if (root == NULL)return 0;
	int ans = 0;
	stack<TreeNode*>stk;
	stk.push(root);
	while (!stk.empty())
	{
		TreeNode* node = stk.top();
		stk.pop();
		if (node->left)
		{
			if (node->left->left == NULL && node->left->right == NULL)ans += node->left->val;
			else stk.push(node->left);
		}
		if (node->right)stk.push(node->right);
	}
	return ans;
}

//410 split array largest sum
bool doable(vector<int>& nums, int cuts, long long maximum)
{
	int acc = 0;// one part of the subarray
	for (int num : nums)
	{
		if (acc + num <= maximum)acc += num;// if acc is still smaller than , then we can add
		else {
			cuts--;
			acc = num;
			if (cuts < 0)return false;// else we should cut it into two split two array
		}
	}
	return true;
}
int splitArray(vector<int>& nums, int m) {
	long long left = 0, right = 0, middle = 0;
	for (int num : nums)// left is the smallest element we can do ,and right is the largest we can do
	{
		left = max(left, (long long)num);
		right += num;
	}
	while (left < right)
	{
		middle = left + (right - left) / 2;
		if (doable(nums, m - 1, middle))right = middle;//m-1 cuts
		else left = middle + 1;
	}
	return left;
}

//255 verify oreorder sequence
bool verifyPreorder(vector<int>& preorder) {
	int index = -1, minValue = INT_MIN;
	for (int x : preorder)
	{
		if (x<minValue)return false;
		while (index >= 0 && preorder[index] <= x)
		{
			minValue = preorder[index--];
		}
		preorder[++index] = x;
	}
	return true;
}
//331 verify preordere serialize of a binary tere
/*
Some used stack. Some used the depth of a stack. Here I use a different perspective. In a binary tree, if we consider null as leaves, then

all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
Suppose we try to build this tree. During building, we record the difference between out degree and in degree diff = outdegree - indegree. When the next node comes, we then decrease diff by 1, because the node provides an in degree. If the node is not null, we increase diff by 2, because it provides two out degrees. If a serialization is correct, diff should never be negative and diff will be zero when finished.

public boolean isValidSerialization(String preorder) {
String[] nodes = preorder.split(",");
int diff = 1;
for (String node: nodes) {
if (--diff < 0) return false;
if (!node.equals("#")) diff += 2;
}
return diff == 0;
}
*/

//morrisTraversalPreorder
// Preorder traversal without recursion and without stack
void morrisTraversalPreorder(TreeNode* root)
{
	while (root)
	{
		// If left child is null, print the current node data. Move to
		// right child.
		if (root->left == NULL)
		{
			printf("%d ", root->val);
			root = root->right;
		}
		else
		{
			// Find inorder predecessor
			 TreeNode* current = root->left;
			while (current->right && current->right != root)
				current = current->right;

			// If the right child of inorder predecessor already points to
			// this node
			if (current->right == root)
			{
				current->right = NULL;
				root = root->right;
			}

			// If right child doesn't point to this node, then print this
			// node and make right child point to this node
			else
			{
				printf("%d ", root->data);
				current->right = root;
				root = root->left;
			}
		}
	}
}

//intersection of unsorted two arrays I
// sort and use two pointers
//hash table
//sort one and use binary serach; binary search is easy

//sort first, but still need to set to remove duplicate
public int[] intersection(int[] nums1, int[] nums2) {
	Set<Integer> set = new HashSet<>();
	Arrays.sort(nums1);
	Arrays.sort(nums2);
	int i = 0;
	int j = 0;
	while (i < nums1.length && j < nums2.length) {
		if (nums1[i] < nums2[j]) {
			i++;
		}
		else if (nums1[i] > nums2[j]) {
			j++;
		}
		else {
			set.add(nums1[i]);
			i++;
			j++;
		}
	}
	int[] result = new int[set.size()];
	int k = 0;
	for (Integer num : set) {
		result[k++] = num;
	}
	return result;
}

//two hashset O(n) time and O(n) space
// just use one set to remove depulicate
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> m(nums1.begin(), nums1.end());
	vector<int> res;
	for (auto a : nums2)
		if (m.count(a)) {
			res.push_back(a);
			m.erase(a);
		}
	return res;
}




//intersection of two  arrayII
//high vote algorithms
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> dict;
	vector<int> res;
	for (int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
	// count the times of the elements
	for (int i = 0; i < (int)nums2.size(); i++)
		if (dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);
	return res;
}

//use two pointers
//we can also do binary search if the two array length difference is significant 

//Sort and two pointers Solution :
//Time : O(max(m, n) log(max(m, n))) Space : O(m + n)

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int n1 = (int)nums1.size(), n2 = (int)nums2.size();
		int i1 = 0, i2 = 0;
		vector<int> res;
		while (i1 < n1 && i2 < n2){
			if (nums1[i1] == nums2[i2]) {
				res.push_back(nums1[i1]);
				i1++;
				i2++;
			}
			else if (nums1[i1] > nums2[i2]){
				i2++;
			}
			else{
				i1++;
			}
		}
		return res;
	}
};


int printUnion(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			printf(" %d ", arr1[i++]);
		else if (arr2[j] < arr1[i])
			printf(" %d ", arr2[j++]);
		else
		{
			printf(" %d ", arr2[j++]);
			i++;
		}
	}

	/* Print remaining elements of the larger array */
	while (i < m)
		printf(" %d ", arr1[i++]);
	while (j < n)
		printf(" %d ", arr2[j++]);
}


/* Function prints Intersection of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
int printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			printf(" %d ", arr2[j++]);
			i++;
		}
	}
}




// 各种follow up

// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// Use hash on nums1 and scan nums2, less space but more time
// Use hash on nums2 and scan nums1, less time but more space
// Or maybe use binary search on nums2(if sorted)

// What if elements of nums2 are stored on disk, and memory is limited so that you can't load all elements into memory at once?
// Maybe use binary search on nums1(sort it first)
// Or maybe use hash on nums1(need space)
// Binary search如果找到了一个元素index，那就用这次的index作为下次binary search的开始。可以节约掉之前的东西，不用search了。
// 然后问，如果找不到呢，如何优化。说如果找不到，也返回上次search结束的index，然后下次接着search。
// 就是上一次找到了，就用这个index继续找这次的；如果找不到，也有一个ending index，就用那个index当starting index。
// 比如[1, 89，100]，去找90；如果不存在，那么binary search的ending index应该是89，所以下次就从那个index开始。
// 如果找不到，会返回要插入的位置index + 1，index是要插入的位置，我写的就是返回要插入的index的。
// 但是不管返回89还是100的index都无所谓，反正只差一个，对performance没有明显影响的。

// Sort one array & Binary Search it, O(mlogn) time and O(n) space
public class Solution {
	public int[] intersection(int[] nums1, int[] nums2) {
		if (nums1 == null || nums2 == null) {
			return new int[]{};
		}
		HashSet<Integer> set = new HashSet<>();//you can use ArrayList here as well
		Arrays.sort(nums1);
		for (int i : nums2) {
			if (!set.contains(i) && binarySearch(nums1, i)) {
				set.add(i);
			}
		}
		int[] res = new int[set.size()];
		int i = 0;
		for (int num : set) {
			res[i++] = num;//remember to i++ !!!
		}
		return res;
	}

	private boolean binarySearch(int[] a, int target) {
		if (a == null || a.length == 0) {//remember to check whether a is null or empty !!!
			return false;
		}
		int start = 0;
		int end = a.length - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (a[mid] == target) {
				return true;
			}
			else if (a[mid] > target) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		if (a[start] == target || a[end] == target) {
			return true;
		}
		return false;
	}
}

//longest common subsequence problem
// dp[i][j]=s1[i-1]==s2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1))]
//

/* A Naive recursive implementation of LCS problem */


int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs(X, Y, m - 1, n - 1);
	else
		return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b) ? a : b;
}


//queen
bool check(int* places, int k)
{
	for (int i = 0; i < k; ++i)
	{
		if (places[i] == places[k] || abs(places[i] - places[k]) == k - i)return false;
	}
	return true;
}

void dfs(int* places, vector<vector<string>>&res, int cur, int n)
{
	if (cur == n)
	{
		vector<string>ans;
		string x;
		for (int i = 0; i < n; ++i)
		{
			x.clear();
			for (int j = 0; j < n; ++j)
			{
				x.push_back(places[i] == j ? 'Q' : '.');
			}
			ans.push_back(x);
		}
		res.push_back(ans);
		return;
	}
	else if (cur > n)return;
	for (int i = 0; i < n; ++i)
	{
		places[cur] = i;
		if (check(places, cur))dfs(places, res, cur + 1, n);
	}
}

vector<vector<string>> solveNQueens(int n) {
	int* places = new int[n];
	vector<vector<string>>res;
	dfs(places, res, 0, n);
	//delete[]places;
	return res;
}

//124 bianry tree maximum path sum
int dfs(TreeNode* root, int &res)
{
	if (root == NULL)return 0;
	int l = dfs(root->left, res);
	int r = dfs(root->right, res);
	int ans = max(root->val, max(l, r) + root->val);
	res = max(res, max(ans, root->val + l + r));
	return ans;
}

int maxPathSum(TreeNode* root) {
	if (root == NULL)return 0;
	int res = INT_MIN;
	dfs(root, res);
	return res;
}

// tree diameter
int diameter(Node root)
{
	/* base case if tree is empty */
	if (root == null)
		return 0;

	/* get the height of left and right sub trees */
	int lheight = height(root.left);
	int rheight = height(root.right);

	/* get the diameter of left and right subtrees */
	int ldiameter = diameter(root.left);
	int rdiameter = diameter(root.right);

	/* Return max of following three
	1) Diameter of left subtree
	2) Diameter of right subtree
	3) Height of left subtree + height of right subtree + 1 */
	return Math.max(lheight + rheight + 1,
		Math.max(ldiameter, rdiameter));

}

/* A wrapper over diameter(Node root) */
int diameter()
{
	return diameter(root);
}

/*The function Compute the "height" of a tree. Height is the
number f nodes along the longest path from the root node
down to the farthest leaf node.*/
static int height(Node node)
{
	/* base case tree is empty */
	if (node == null)
		return 0;

	/* If tree is not empty then height = 1 + max of left
	height and right heights */
	return (1 + Math.max(height(node.left), height(node.right)));
}

//optimal
//Time Complexity : O(n)

int diameter(TreeNode* root, int& height)
{
	int lh = 0, rh = 0;
	int ldimater = 0, rdiamter = 0;
	if (root == NULL)
	{
		height = 0;
		return 0;
	}
	ldimater = diameter(root, lh);
	rdiamter = diameter(root, rh);
	height = max(lh, rh) + 1;
	return max(lh + rh + 1, max(ldimater, rdiamter));
}


//max path sum


//DFS, 设dfs(root)返回的是包括root这个结点的单一路径上的最大值
int dfs(TreeNode* root, int &res)
{
	if (root == NULL)return 0;
	int l = dfs(root->left, res);
	int r = dfs(root->right, res);
	int ans = max(root->val, max(l, r) + root->val);
	res = max(res, max(ans, root->val + l + r));
	return ans;
}

int maxPathSum(TreeNode* root) {
	if (root == NULL)return 0;
	int res = INT_MIN;
	dfs(root, res);
	return res;
}


//tonight focuse
//394 decode string
string decodeString(string s) {
		int pos = 0;
		return helper(pos, s);
	}
	string helper(int& pos, string s) {
		int num = 0;
		string word = "";
		for (; pos<s.size(); pos++) {
			char cur = s[pos];
			if (cur == '[') {
				string curStr = helper(++pos, s);
				for (; num>0; num--) word += curStr;// we have number curstr, so we should do a loop;
			}
			else if (cur >= '0' && cur <= '9') {
				num = num * 10 + cur - '0';
			}
			else if (cur == ']') {
				return word;
			}
			else {    // Normal characters
				word += cur;
			}
		}
		return word;
	}

//better way, easy to understand
string decodeString(string s)
{
	string res = "";
	stack<int>cntStack;
	stack<string>resStk;
	int idx = 0, n = s.size();
	while (idx < n)
	{
		if (isdigit(s[idx]))
		{
			int count = 0;
			while (isdigit(s[idx]))
			{
				count = 10 * count + (s[idx] - '0');
				idx++;
			}
			cntStack.push(count);
		}
		else if (s[idx] == '[')
		{
			resStk.push(res);
			res = "";
			idx++;
		}
		else if (s[idx] == ']')
		{
			string tmp = resStk.top();
			resStk.pop();
			int repeatTimes = cntStack.top();
			cntStack.pop();
			for (int i = 0; i < repeatTimes; ++i)tmp += res;
			res = tmp;
			idx++;
		}
		else
		{
			res += s[idx++];
		}
	}
	return res;
}


// this is my way
string decodeString(string s) {
	stack<string>res;
	int n = s.size(), sum = 0, i = 0;
	string tmp = "", strs = "";
	while (i<n)
	{
		if (isdigit(s[i]))
		{
			while (i<n && isdigit(s[i]))
			{
				sum = 10 * sum + s[i] - '0';
				i++;
			}
			res.push(to_string(sum));
			sum = 0;
		}
		if (i<n && isalpha(s[i]))
		{
			while (i<n && isalpha(s[i]))
			{
				tmp.push_back(s[i]);
				i++;
			}
			res.push(tmp);
			tmp = "";
		}
		if (i<n && s[i] == '[')
		{
			res.push("[");
			i++;
			continue;
		}
		if (i<n && s[i] == ']')
		{
			string x = res.top();
			res.pop();
			while (!res.empty() && res.top() != "[") { x = res.top() + x; res.pop(); }
			res.pop();
			int xx = stoi(res.top());
			string xxx = x;
			while (xx-->1)
			{
				x += xxx;
			}
			res.pop();
			while (!res.empty() && res.top() != "[") { x = res.top() + x; res.pop(); }
			res.push(x);
			i++;
		}
	}
	string str = "";
	while (!res.empty())
	{
		str = res.top();
		res.pop();
		strs = str + strs;;
	}
	return strs;
}
// tonight;/ t convert binary tree to double linkedlist

//3 sum hash

//sample revisoring http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=210154&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3090%5D%5Bvalue%5D%3D2%26searchoption%5B3090%5D%5Btype%5D%3Dradio%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

// amazing number   Define amazing number as

// 
//Q1 ：移0，秒了Q2 : 给个正整数target和数组找是否有subarray sum等于target。。双指针秒，follow up有负数怎么办。。。我卡了半天。。最后10min想到hashset

//binary tree ancestor of deepest leaf;
//'Time complexity: O(n), Space complexity: O(h), height of the tree'
struct info{
	int depth;
	TreeNode* node;
	info() :depth(0),node(NULL){}
};

//deepest leaf
info* findLca(TreeNode* root)
{
	if (root == NULL)return new info();
	info* left = findLca(root->left);
	info* right = findLca(root->right);
	info* res = new info();
	if (left->depth == right->depth)
	{
		res->node = root;
		res->depth = left->depth+1;
	}
	else if (left->depth > right->depth)
	{
		res->node = left->node;
		res->depth = left->depth + 1;
	}
	else
	{
		res->node = right->node;
		res->depth = right->depth+1;
	}
	return res;
}

TreeNode* findLcaRucrusive(TreeNode* root)
{
	return findLca(root)->node;
}

//iterative way
TreeNode* findLcaIterative(TreeNode* root)
{
	if (root == NULL)return NULL;
	unordered_map<TreeNode*, TreeNode*>parent;
	queue < TreeNode* >q;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			TreeNode* node = q.front();
			q.pop();
			if (size == q.size() - 1)left = node;
			if (size == 0)right = node;
			if (node->left)
			{
				q.push(node->left);
				parent[node->left] = node;
			}
			if (node->right)
			{
				q.push(node->right);
				parent[node->right] = node;
			}
		}
		while (left != right)
		{
			left = parent[left];
			right = parent[right];
		}
		return left;
	}
}


//multiple children

struct TreeNodeMulti
{
	int val;
	vector<TreeNodeMulti*>children;
	TreeNodeMulti(int val) :val(val){}
};

struct result{
	TreeNodeMulti* node;
	int depth;
	result(int depth, TreeNodeMulti*node)
	{
		depth = depth;
		node = node;
	}
};


result* dfs(TreeNodeMulti* root)
{
	if (root == NULL)return new result(0, NULL);
	int depth = 0;
	vector<result*>next;
	for (auto child : root->children)
	{
		next.push_back(dfs(child));
	}
	result* deepest = new result(0, NULL);
	result* deepest2 = new result(0, NULL);
	for (auto res : next)
	{
		if (res->depth >= deepest->depth)
		{
			deepest2->node = deepest->node;
			deepest2->depth = deepest->depth;
			deepest->node = res->node;
			deepest->depth = res->depth;
		}
	}
	depth = 1 + deepest->depth;
	if (deepest->depth == deepest2->depth)return new result(depth, root);
	else return new result(depth, deepest->node);
}
TreeNodeMulti* findLca(TreeNodeMulti* root)
{
	return dfs(root)->node;
}


// sliding window maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	//monotonic deque;
	vector<int>res;
	deque<int>q;
	int n = nums.size();
	if (n == 0 || k == 0 || n<k)return res;
	for (int i = 0; i<n; ++i)
	{
		if (!q.empty() && q.front()<i - k + 1)q.pop_front();
		while (!q.empty() && nums[q.back()]<nums[i])q.pop_back();
		q.push_back(i);
		if (i >= k - 1)res.push_back(nums[q.front()]);
	}
	return res;
}

vector<int> minSlidingWindow(vector<int>& nums, int k) {
	//monotonic deque;
	vector<int>res;
	deque<int>q;
	int n = nums.size();
	if (n == 0 || k == 0 || n<k)return res;
	for (int i = 0; i<n; ++i)
	{
		if (!q.empty() && q.front()<i - k + 1)q.pop_front();
		while (!q.empty() && nums[q.back()]<nums[i])q.pop_back();
		q.push_back(i);
		if (i >= k - 1)res.push_back(nums[q.front()]);
	}
	return res;
}

// balance parentheses in a string 

//first, you can use stack
//has bug

// remove invalid parentheses
//can not use
// you can say that you can do thi by bfs delete

// it was my mistake. BFS is always slow
bool valid(string s)
{
	int count = 0;
	for (char c : s)
	{
		if (c == '(')count++;
		else if (c == ')')
		{
			if (count <= 0)return false;
			count--;
		}
	}
	return count == 0;
}//http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=145680&fromuid=109727
vector<string> removeInvalidParentheses(string s) {
	vector<string>res;
	if (valid(s))return{ s };
	queue<string>q;
	q.push(s);
	string str;
	int flag = true;
	unordered_map<string, bool>mp;
	mp[s] = true;//  it was my mistake, I forget to use this, as a result, many substrs are pushed into queue, so we should check whether it has been visited 
	while (flag && !q.empty())
	{
		int size = q.size();
		while (size--)
		{
			str = q.front();
			q.pop();
			int n = str.size();
			for (int i = 0; i<n; ++i)
			{
				if (str[i] != '(' && str[i] != ')')continue;
				string substr = str.substr(0, i) + str.substr(i + 1);
				if (valid(substr) && !mp[substr])
				{
					flag = false;
					mp[substr] = true;
					res.push_back(substr);
				}
				if (!mp[substr])
				{
					q.push(substr);
					mp[substr] = true;
				}
			}
		}
	}
	return res;
}

//dfs way

Key Points :

Generate unique answer once and only once, do not rely on Set.
Do not need preprocess.
Runtime 3 ms.
Explanation :
			We all know how to check a string of parentheses is valid using a stack.Or even simpler use a counter.
			The counter will increase when it is ‘(‘ and decrease when it is ‘)’.Whenever the counter is negative, we have more ‘)’ than ‘(‘ in the prefix.

			To make the prefix valid, we need to remove a ‘)’.The problem is : which one ? The answer is any one in the prefix.However, if we remove any one, we will generate duplicate results, for example : s = ()), we can remove s[1] or s[2] but the result is the same().Thus, we restrict ourself to remove the first ) in a series of concecutive )s.

			After the removal, the prefix is then valid.We then call the function recursively to solve the rest of the string.However, we need to keep another information : the last removal position.If we do not have this position, we will generate duplicate by removing two ‘)’ in two steps only with a different order.
			For this, we keep tracking the last removal position and only remove ‘)’ after that.

			Now one may ask.What about ‘(‘ ? What if s = ‘(()(()’ in which we need remove ‘(‘ ?
			The answer is : do the same from right to left.
			However a cleverer idea is : reverse the string and reuse the code!
			Here is the final implement in Java.

			Java

	public List<String> removeInvalidParentheses(String s) {
	List<String> ans = new ArrayList<>();
	remove(s, ans, 0, 0, new char[]{'(', ')'});
	return ans;
}

public void remove(String s, List<String> ans, int last_i, int last_j, char[] par) {
	for (int stack = 0, i = last_i; i < s.length(); ++i) {
		if (s.charAt(i) == par[0]) stack++;
		if (s.charAt(i) == par[1]) stack--;
		if (stack >= 0) continue;
		for (int j = last_j; j <= i; ++j)
			if (s.charAt(j) == par[1] && (j == last_j || s.charAt(j - 1) != par[1]))
				remove(s.substring(0, j) + s.substring(j + 1, s.length()), ans, i, j, par);
		return;
	}
	String reversed = new StringBuilder(s).reverse().toString();
	if (par[0] == '(') // finished left to right
		remove(reversed, ans, 0, 0, new char[]{')', '('});
	else // finished right to left
		ans.add(reversed);
}

// only need one of the result? 
// O(n) time; if consider the space that sb uses, O(n) space
// add all character first , then check if it is valid. otherwise you can delete ')'
string deleteCloseParenthese(string input)
{
	int count = 0;
	string result;
	for (char letter : input)
	{
		result.push_back(letter);
		if (letter == '(')count++;
		else if (letter == ')')
		{
			if (count > 0)count--;
			else result.pop_back();
		}
	}
	return result;
}
string deleteOpenParenthese(string input)
{
	int count = 0,n=input.size();
	string result;
	for (int i = n - 1; i >= 0;--i)
	{
		result.push_back(input[i]);
		if (input[i] == ')')count++;
		else if (input[i] == '(')
		{
			if (count > 0)count--;
			else result.pop_back();
		}
	}
	reverse(result.begin(), result.end());
	return result;
}

string balanceParenthese(string input)
{
	string result = deleteCloseParenthese(input);
	result = deleteOpenParenthese(result);
	return result;
}

// also you can write in the one function
string balancedParentheses(string s)
{
	string res;
	int left = 0;
	int right = 0, n = s.size();
	for (int i = 0; i < n; ++i)
	{
		char c = s[i];
		if (c == '(')
		{
			left++;
			res.push_back(c);
		}
		else if (c == ')' && left > right)
		{
			right++;
			res.push_back(c);
		}
		else if (c != ')')
		{
			res.push_back(c);
		}
	}
	s = res;
	n = s.size();
	left = 0, right = 0;
	res.clear();
	for (int i = n - 1; i >= 0; --i)
	{
		char c = s[i];
		if (c == ')')
		{
			right++;
			res.push_back(c);
		}
		else if (c == '(' && right > left)
		{
			left++;
			res.push_back(c);
		}
		else if (c != '(')
		{
			res.push_back(c);
		}
	}
	reverse(res.begin(), res.end());// need to flip
	return res;
}

//Find k nearest points of a target point java
// k points nearest k points
//// Use quickSelect to find the kth nearest point to the origin point
//'Time complexity: average O(n), worst O(n^2) when always pick the most right one -- the time complexity of quick select'
struct Point{
	int x, y;
	Point(int x = 0, int y = 0) :x(x), y(y){}
};


int distance(Point point)
{
	return point.x*point.x + point.y*point.y;
}

int partition(vector<Point>&points, int left, int right)
{
	int begin = left, end = right;
	Point key = points[begin];
	int keydist = distance(key);
	while (begin < end)
	{
		while (begin < end && distance(points[end]) >= keydist)end--;
		points[begin] = points[end];
		while (begin < end && distance(points[begin]) <= keydist)begin++;
		points[end] = points[begin];
	}
	points[begin] = key;
	return begin;
}

Point quickSelect(vector<Point>points, int left, int right, int k)
{
	int index = partition(points, left,  right);
	if (index == k - 1)return points[k - 1];
	else if (index > k)return quickSelect(points, left, index - 1, k);
	else return quickSelect(points, index + 1, right, k);
}
Point findNearestKthPoint(vector<Point>points, int k)
{
	int left = 0, right = points.size() - 1;
	return quickSelect(points, left, right, k);
}

// you can also use priority;

struct cmp{
	bool operator()(Point a, Point b)
	{
		return distance(a) < distance(b);
	}
};

vector<Point>findNearEstKPoint(vector<Point>& points, int k)
{
	priority_queue<Point, vector<Point>, cmp>pq;
	for (Point p : points)
	{
		if (pq.size() < k)pq.push(p);
		else if (distance(pq.top()) > distance(p))
		{
			pq.pop();
			pq.push(p);
		}
	}
	vector<Point>res;
	while (!pq.empty())
	{
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}


//22 generate parentheses
void generateBacktracing(vector<string>& res, string path, int left, int right, int n)
{
	if (left == n && right == n)
	{
		res.push_back(path);
		return;
	}
	if (left < n)
	{

		generateBacktracing(res, path + "(", left + 1, right, n);
	}
	if (right < left)
	{
		generateBacktracing(res, path + ")", left, right + 1, n);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string>res;
	string path;
	generateBacktracing(res, path, 0, 0, n);
	return res;
}


void backtracking(vector<string>& res, string& path, stack<int>& input, stack<int>& stk, int n)
{
	if (input.empty() && stk.empty() && path.size() == 2 * n)
	{
		res.push_back(path);
		return;
	}
	if (!input.empty())
	{
		int top = input.top();
		input.pop();
		stk.push(top);
		path.push_back('(');
		backtracking(res, path, input, stk, n);
		stk.pop();
		path.pop_back();
		input.push(top);
	}
	if (!stk.empty())
	{
		int top = stk.top();
		stk.pop();
		path.push_back(')');
		backtracking(res, path, input, stk, n);
		path.pop_back();
		stk.push(top);
	}

}
vector<string> generateParenthesis(int n) {
	vector<string>res;
	string path;
	stack<int>input;
	stack<int>stk;
	for (int i = 1; i <= n; ++i)
	{
		input.push(i);
	}
	backtracking(res, path, input, stk, n);
	return res;
}






////reconstruct BST from pre-prder sequence 

//'Time complexity: O(NlgN)'
TreeNode* constructTreeFromPreorder(vector<int>& preorder, int begin, int end)
{
	if (begin > end)return NULL;
	else if (begin == end)return new TreeNode(preorder[begin]);
	int rightIndex = begin + 1;
	TreeNode* root = new TreeNode(preorder[begin]);
	while (rightIndex <= end && preorder[rightIndex] < root->val)rightIndex++;
	root->left = constructTreeFromPreorder(preorder, begin + 1, rightIndex-1);// find the first larget one than root
	root->right = constructTreeFromPreorder(preorder, rightIndex, end);
	return root;
}

TreeNode* constructFromPreorder(vector<int>& preorder)
{
	if (preorder.empty())return NULL;
	return constructTreeFromPreorder(preorder, 0, preorder.size() - 1);

}

//move char
// move zero like
// traverse the string and put the non-target character into the 
// char array one by one, and put the target character at the end
class MoveChar {
	public String removeChar(char[] input, char k) {
		int fast = 0;
		int slow = 0;
		while (fast < input.length) {
			while (slow < input.length && input[slow] != k) {
				slow++;
			}
			fast = slow;
			while (fast < input.length && input[fast] == k) {
				fast++;
			}
			while (fast < input.length && input[fast] != k) {
				input[slow] = input[fast];
				input[fast] = k;
				fast++;
				slow++;
			}
		}
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < slow; i++) {
			result.append(input[i]);
		}
		return result.toString();
	}
}

// subarrayEqualsK( consecutive sequence sum equals to k)
// subarray sum equals k
bool findSubarray(vector<int>input, int k)
{
	set<int>sums;
	int sum = 0;
	for (int number : input)
	{
		sum += number;
		if (sums.find(sum - k))return true;
		sums.insert(sum);
	}
	return false;
}

//104 maximum depth tree
////recursive O(n) time, O(h) space
//top down
int maxDepth(TreeNode* root) {
	if (root == NULL)return 0;
	else return  max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//bottom up
public class Solution {
	public int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		int left = maxDepth(root.left);
		int right = maxDepth(root.right);
		return Math.max(left, right) + 1;
	}
}

//bfs
////iterative O(n) time, O(n) space
int maxDepth(TreeNode *root)
{
	if (root == NULL)
		return 0;

	int res = 0;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		++res;
		for (int i = 0, n = q.size(); i < n; ++i)
		{
			TreeNode *p = q.front();
			q.pop();

			if (p->left != NULL)
				q.push(p->left);
			if (p->right != NULL)
				q.push(p->right);
		}
	}
	return res;
}


// min depth
//bfs
//iterative O(n) time, O(n) space
int minDepth(TreeNode* root) {
	if (root == NULL)return 0;
	int ans = 1;
	queue<TreeNode*>q;

	q.push(root);
	TreeNode* node = NULL;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			node = q.front();
			q.pop();
			if (node->left == NULL&&node->right == NULL)return ans;
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
		ans++;
	}
	return ans;
}
////recursive O(n) time, O(h) space
//top down
int minDepth(TreeNode* root) {
	if (root == NULL)return 0;
	if (root->left == NULL)return minDepth(root->right) + 1;
	else if (root->right == NULL)return minDepth(root->left) + 1;
	else return min(minDepth(root->left), minDepth(root->right)) + 1;
}




// subarray sum equal k
// window 
//two pointers
// maximum can not use the window, but minimum can use the window
// first brute force

//can handle negative number
bool subarraysum(int k, vector<int>& nums)
{
	int sum = 0;
	unordered_set<int>sets;
	for (int x : nums)
	{
		sum += x;
		if (sets.find(sum - k) != sets.end())return true;
		sets.insert(x);
	}
	return false;
}
//can only handle positive number
bool SubArrayLen(int s, vector<int>nums)
{
	if (s < 1 || nums.empty())return false;
	int begin = 0, end = 0, n = nums.size(), sum = 0;
	while (end < n)
	{
		sum += nums[end++];
		while (sum > s)
		{
			sum -= nums[begin++];
		}
		if (sum == s)return true;
	}
	return false;
}


//follow up
//compress the row or col to let it become a one-dimensional problem, so that we can use the algo above to solve it
//the code below uses O(m^2 * n) time and O(n) space,if m is larger than n,switch them in loops, so the real complexity is
//O(min(m^2*n, n^2*m)) time, O(n or m) space
public class Solution {
	public boolean subMatrixSum(int[][] nums, int k) {
		if (nums == null || nums.length == 0 || nums[0] == null || nums[0].length == 0) {
			return false;
		}
		int m = nums.length;
		int n = nums[0].length;
		for (int i = 0; i < m; i++) {//O(m), i to m are rows that we want to compress
			int[] row = new int[n];//O(n) space, store the compressed rows
			for (int j = i; j < m; j++) {//O(m)
				for (int k = 0; k < n; k++) {//O(n)
					row[k] += nums[j][k];
				}
				if (subArraySum(row, k)) {//O(n)
					return true;
				}
			}
		}
		return false;
	}
}
//the process of algo above:
Loop1: Row1 : 1, 2, 3->Row1 + Row2 : 5, 7, 9->Row1 + Row2 + Row3 : 12, 15, 18
Loop2 : Row2 : 4, 5, 6->Row2 + Row3 : 11, 13, 15
	Loop3 : Row3 : 7, 8, 9

			1 2 3
			4 5 6
			7 8 9

			3 * 3 matrix, if we compress by rows, then it can be
			compress 1 row
		Row1 : 1, 2, 3
		   Row2 : 4, 5, 6
			  Row3 : 7, 8, 9

					 compress 2 rows
					 Row1 + Row2 : 5, 7, 9
					 Row2 + Row3 : 11, 13, 15

					 compress 3 rows
					 Row1 + Row2 + Row3 : 12, 15, 18

					 For each m * n matrix, if we compress it by rows, it can be compressed by 1 row, 2 rows, 3 rows, ..., m - 1 rows, m rows.That is to say, there are  m + m - 1 + m - 2 + ... + 2 + 1 = m * (m + 1) / 2 = O(m ^ 2) ways.For each way, we can reuse the linear solution of previous problem.Therefore, the time complexity is O(m ^ 2 * n).Or compressed by columns, it should be O(n ^ 2 * m).It depends which one is smaller...

					 // if all nums are positive nums, we can use two pointer(silding window, corner case is i==a.length && sum<target ->break)
					 // if the array has negative nums, we have to use extra space (hashmap)


// 209 minimum size subarray sum
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

//@taobupt

// two pointer
//O(n) time complexity
int minSubArrayLen(int s, vector<int>& nums) {
	int begin = 0, end = 0, n = nums.size(), res = 0, minLength = INT_MAX;
	while (end < n)
	{
		res += nums[end++];
		while (res >= s)
		{
			if (end - begin<minLength)
			{
				minLength = end - begin;
			}
			res -= nums[begin++];
		}
	}
	return minLength == INT_MAX ? 0 : minLength;
}





//O(nlogn) you can add all number to the sum vector, and then you can use the binary search
int upper_bound(vector<int>& nums, int left, int right, int target)
{
	int l = left;
	int r = right;
	while (l<r)
	{
		int m = l + (r - l) / 2;
		if (nums[m] <= target)l = m + 1;
		else r = m;
	}
	return nums[r]>target ? r : -1;



}

int minSubarrayLen(vector<int>&nums, int s)
{
	int n = nums.size(), minlen = INT_MAX;
	vector<int>sums(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		sums[i] = sums[i - 1] + nums[i - 1];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (sums[i] >= s)
		{
			int p = upper_bound(sums, 0, i, sums[i] - s);
			if (p != -1)minlen = min(minlen, i - p + 1);
		}
	}
	return minlen == INT_MAX ? 0 : minlen;

}

//325 maximum size subarray sum equal k

//@taobupt

int maxSubArrayLen(vector<int>& nums, int k) {
	int n = nums.size(), maxLength = 0;
	if (n == 0)return 0;
	vector<unsigned>sum(n, nums[0]);
	for (int i = 1; i<n; ++i)sum[i] = sum[i - 1] + nums[i];
	unordered_map<int, int>mp;
	for (int i = 0; i<n; ++i)
	{
		if (sum[i] == k || mp.find(sum[i] - k) != mp.end())
		{
			if (sum[i] == k)maxLength = max(maxLength, i + 1);
			else maxLength = max(maxLength, i - mp[sum[i] - k]);
		}
		if (mp.find(sum[i]) == mp.end())mp[sum[i]] = i;// this is important ,if there is a duplicate , we should take care of this.
	}
	return maxLength;
}

// more concise
// interesting ,can reduce the space
////if there are positive and negative nums, we need to use a hashmap, O(n) time and space
int maxSubArrayLen(vector<int>& nums, int k)
{
	unordered_map<int, int>sums;
	unsigned cur_sum = 0;
	int max_len = 0, n = nums.size();
	for (int i = 0; i < n; ++i)
	{
		cur_sum += nums[i];
		if (cur_sum == k)
		{
			max_len = max(i + 1, max_len);
		}
		else if (sums.find(cur_sum - k) != sums.end())
		{
			max_len = max(max_len, i - sums[cur_sum - k]);
		}
		if (sums.find(cur_sum) == sums.end())
		{
			sums[cur_sum] = i;
		}
	}
	return max_len;
}


//follow up matrix, O(N3)
public class Solution {
	public int[][] submatrixSum(int[][] matrix) {
		int m = matrix.length, n = matrix[0].length;
		int[][] sum = new int[m + 1][n + 1];
		int[][] res = new int[2][2];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				sum[i + 1][j + 1] = matrix[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
			}
		}
		for (int i1 = 0; i1 < m; i1++) {
			for (int i2 = i1 + 1; i2 <= m; i2++) {
				Map<Integer, Integer> map = new HashMap<Integer, Integer>();
				for (int j = 0; j <= n; j++) {
					int diff = sum[i2][j] - sum[i1][j];
					if (map.containsKey(diff)) {
						res[0][0] = i1; res[0][1] = map.get(diff);
						res[1][0] = i2 - 1; res[1][1] = j - 1;
						return res;
					}
					else map.put(diff, j);
				}
			}
		}
		return res;
	}




// insert node to sorted linkedlist
// two nodes
ListNode* insert(ListNode* head, ListNode* node)
{
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* p = head;
	ListNode* pre = first;
	while (p && p->val < node->val)
	{
		p = p->next;
		pre = pre->next;
	}
	pre->next = node;
	node->next = p;
	return first->next;
}

//read4

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

//transaction with fee
public int maxProfit(int[] prices, int[] transFee) {
	if (prices == null || prices.length == 0) {
		return 0;
	}
	int maxProfit = 0;
	for (int i = 1; i < prices.length; i++) {
		int buy = prices[i - 1] + transFee[i - 1];
		int sell = prices[i - 1] - transFee[i - 1];
		if (sell > buy) {
			maxProfit += sell - buy;
		}
	}
	return maxProfit;
}

//stock
// do the transction every day

// each time we meet prices[i] that is larger than last day's prices[i - 1]
//we will choose to buy stock on i - 1 day and sell stock on i day
int maxProfit(vector<int>& prices)
{
	int profit = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		profit += max(prices[i] - prices[i - 1], 0);
	}
	return profit;
}


// best time to buy stock 3


// use an array to record the max profit we can make before today
// use anothter array to record the max profit we can make after doday
// so max profit we can make =max(before[i]+after[i]) 0<=i<=lenght
//O(N) sapce, actually you can save space
int profit(vector<int>& prices)
{
	if (prices.empty())return 0;
	int n = prices.size();
	vector<int>first(n);//max profit from 0(starting boundary) to i day if at most buy&sell once
	vector<int>second(n);//max profit from length-1(starting boundary) to i day if at most buy&sell once
	int min1 = prices[0];
	int maxProfit = 0;
	for (int i = 0; i < n; ++i)
	{
		min1 = min(min1, prices[i]);
		maxProfit = max(maxProfit, prices[i] - min1);
		first[i] = maxProfit;
	}
	int max1 = prices[n - 1];
	maxProfit = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		max1 = max(max1, prices[i]);
		maxProfit = max(max1 - prices[i], maxProfit);
		second[i] = maxProfit;
	}
	maxProfit = 0;
	for (int i = 0; i < n; ++i)
	{
		maxProfit = max(first[i] + second[i], maxProfit);
	}
	return maxProfit;
}


//save space
//O(1)
// best time to buy stock 3

public int maxProfit(int[] prices) {
	int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
	int release1 = 0, release2 = 0;
	for (int i : prices){                              // Assume we only have 0 money at first
		release2 = Math.max(release2, hold2 + i);     // The maximum if we've just sold 2nd stock so far.
		hold2 = Math.max(hold2, release1 - i);  // The maximum if we've just buy  2nd stock so far.
		release1 = Math.max(release1, hold1 + i);     // The maximum if we've just sold 1nd stock so far.
		hold1 = Math.max(hold1, -i);          // The maximum if we've just buy  1st stock so far. 
	}
	return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
}


//with cool down
int maxProit1(vector<int>& prices)
{
	if (prices.empty())return 0;
	int n = prices.size();
	vector<int>sell(n, 0);
	vector<int>buy(n, 0);
	sell[0] = 0;
	buy[0] = -prices[0];
	for (int i = 1; i < n; ++i)
	{
		sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);// sell or not sell
		if (i == 1)buy[i] = max(buy[0], 0 - prices[i]);
		else buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);// buy 
	}
	return sell[n - 1];
}

//save space with cool down

int maxProfit(vector<int>& prices)
{
	int sell = 0, prev_sell = 0, buy = INT_MIN, prev_buy = 0;
	for (int price : prices)
	{
		prev_buy = buy;
		buy = max(prev_sell - price, prev_buy);
		prev_sell = sell;
		sell = max(prev_buy + price, prev_sell);
	}
	return sell;
}

//buy stock IV
//with most transaction
public class Solution {
	public int maxProfit(int k, int[] prices) {
		if (prices == null || prices.length == 0 || k < 1) {
			return 0;
		}
		int n = prices.length;
		if (k >= n / 2) {//this means we can have have enough transaction times to buy and sell for every two days
			return getMaxProfit(prices);//just like prob 2
		}
		int[][] local = new int[n][k + 1];//local[i][j] means the max profit, and there must be a transaction sold on day i
		int[][] global = new int[n][k + 1];//global[i][j] means the max profit from day 0 to i, with k transactions
		for (int i = 1; i < n; i++) {
			int diff = prices[i] - prices[i - 1];
			for (int j = 1; j <= k; j++) {
				//why global[i-1][j-1]+Math.max(diff,0)?cuz local[i][j] means 1 transaction that must be sold on day i
				//we can't guarantee we have a transaction that was sold on day i-1,so we need 1 transaction time left,so j-1
				//if diff>0 we may use it to buy on i-1 day and sell on i day to earn positive profit
				//if diff<=0 we may use it to buy&sell on i day to earn zero profit

				//but why local[i-1][j]?why not j-1?cuz we know that local[i-1][j] must have a
				//transaction that was sold on day i-1,we can merge that transaction with the one that was sold on day i
				//so that we don't waste a transaction time, cuz "sell on day i-1" and "buy on day i-1 and sell on day i"
				//these two transactions can be merged into a transaction that sell on day i

				//why +diff?why not max(diff,0)?cuz we merge the last transaction of day i-1,so no matter profitable or not,
				//we have to sell the stock, which we bought before day i-1, on day i

				//global[i-1][j] means we don't buy or sell on day i, local[i][j] means we have a transaction sold on day i
				local[i][j] = Math.max(global[i - 1][j - 1] + Math.max(diff, 0)//i-1 day, has no transaction,so yo can choose buy or not buy, local[i - 1][j] + diff//has transaction, so merge "sell on day i-1" and "buy on day i-1 and sell on day i, these two transactions can be merged into a transaction that sell on day i");
					global[i][j] = Math.max(global[i - 1][j], local[i][j]);
			}
		}
		return global[n - 1][k];//k, not k + 1 !!!
	}

	private int getMaxProfit(int[] prices) {
		int profit = 0;
		for (int i = 1; i < prices.length; i++) {
			if (prices[i] > prices[i - 1]) {
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
}



// each day can buy one share of stocks, each sell will sell all the shares
public class Solution {
	public int maxProfit(int[] prices) {
		if (prices == null || prices.length < 2) {
			return 0;
		}
		int max = prices[prices.length - 1];
		int profit = 0;
		for (int i = prices.length - 2; i >= 0; i--) {
			max = Math.max(max, prices[i]);//we will choose to buy one share on days that have prices[i] < max
			profit += max - prices[i];
		}
		return profit;
	}
}


// with most
// print by column
//class PrintByColumn {
//	private int mostLeft = 0;
//	public void print(TreeNode root) {
//		List<List<Pair>> paths = new ArrayList<>();
//		helper(root, 0, new ArrayList<Pair>(), paths);
//		for (List<Pair> path : paths) {
//			for (Pair pair : path) {
//				int gap = -mostLeft - (-pair.col);
//				while (gap > 0) {
//					System.out.print("*");
//					gap--;
//				}
//				System.out.print(pair.val);
//			}
//			System.out.println();
//		}
//	}
//	private void helper(TreeNode root, int col, List<Pair> list, List<List<Pair>> paths) {
//		list.add(new Pair(root.val, col));
//		mostLeft = Math.min(mostLeft, col);
//		if (root.left == null && root.right == null) {
//			paths.add(new ArrayList<Pair>(list));
//		}
//		if (root.left != null) {
//			helper(root.left, col - 1, list, paths);
//		}
//		if (root.right != null) {
//			helper(root.right, col + 1, list, paths);
//		}
//		list.remove(list.size() - 1);
//	}
//	class Pair {
//		int col;
//		int val;
//		public Pair(int val, int col) {
//			this.val = val;
//			this.col = col;
//		}
//	}
//}

// check duplicate numbers in window k
// my answer, not verified


//Contains Duplicate II
//Given an array of integers and an integer k, 
//find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
bool containsNearbyDuplicate(vector<int>nums, int k)
{
	unordered_set<int>window;
	int low = 0;
	int high = 0;
	while (high < nums.size())
	{
		if (window.size() > k)
		{
			window.erase(nums[low]);
			low++;
		}
		if (window.find(nums[high])!=window.end())return true;
		else
		{
			window.insert(nums[high++]);
		}
	}
	return false;
}

//concise
public boolean containsNearbyDuplicate(int[] nums, int k) {
	Set<Integer> set = new HashSet<Integer>();
	for (int i = 0; i < nums.length; i++){
		if (i > k) set.remove(nums[i - k - 1]);
		if (!set.add(nums[i])) return true;
	}
	return false;
}


/*

public boolean containsNearbyDuplicate(int[] nums, int k) {
HashMap<Integer, Integer> map = new HashMap<>();
for (int i = 0; i < nums.length; i++) {
if (map.containsKey(nums[i]) && Math.abs(map.get(nums[i]) - i) <= k) {
return true;
}
else {
map.put(nums[i], i);
}
}
return false;
}
*/

// find anagrams
//string permutation
vector<int> findAnagrams(string haystack, string needle) {
	vector<int>res;
	if (haystack.empty() || needle.empty())return res;
	int m[256] = { 0 };
	for (char c : needle)m[c]++;
	int left = 0, right = 0, count = needle.size();
	while (right < haystack.size())
	{
		if (m[haystack[right++]]-- >0)count--;
		if (count == 0)res.push_back(left);
		if (right - left == needle.size() && ++m[haystack[left++]]>0)count++;
	}
	return res;
}

//leetcode 30 substring with concatenation of all words
vector<int> findSubstring(string S, vector<string>& L) {
	vector<int> ans;
	int n = S.size(), cnt = L.size();
	if (n <= 0 || cnt <= 0) return ans;

	// init word occurence
	unordered_map<string, int> dict;
	for (int i = 0; i < cnt; ++i) dict[L[i]]++;

	// travel all sub string combinations
	int wl = L[0].size();
	for (int i = 0; i < wl; ++i) {
		int left = i, count = 0;
		unordered_map<string, int> tdict;
		for (int j = i; j <= n - wl; j += wl) {
			string str = S.substr(j, wl);
			// a valid word, accumulate results
			if (dict.count(str)) {
				tdict[str]++;
				if (tdict[str] <= dict[str])
					count++;
				else {
					// a more word, advance the window left side possiablly
					while (tdict[str] > dict[str]) {
						string str1 = S.substr(left, wl);
						tdict[str1]--;
						if (tdict[str1] < dict[str1]) count--;
						left += wl;
					}
				}
				// come to a result
				if (count == cnt) {
					ans.push_back(left);
					// advance one word
					tdict[S.substr(left, wl)]--;
					count--;
					left += wl;
				}
			}
			// not a valid word, reset all vars
			else {
				tdict.clear();
				count = 0;
				left = j + wl;
			}
		}
	}

	return ans;
}


//kmp algorithms

vector<int> buildnext(string p)
{
	int n = p.size();
	vector<int>f(n + 1, 0);
	for (int i = 1; i<n; ++i)
	{
		int j = f[i];
		while (j && p[j] != p[i])j = f[j];
		f[j + 1] = p[j] == p[i] ? j + 1 : j;
	}
	return f;
}

void kmp(string t, string p)
{
	int n = t.size(), m = p.size();
	vector<int>next = buildnext(p);
	for (int i = 0, j = 0; i<n; ++i)
	{
		while (j && t[i] != p[j])j = next[j];
		if (p[j] == t[i])j++;
		if (j == m)
		{
			printf("Pattern occurs with shift:%d \n", (i - m + 1));
		}
	}
}


//dot product
// you can use unordred_map
// you can also use the vector<pair<int,int>>;


//time complexity O(max(LenA, LenB);
int dotProduct(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int sum = 0;
	int indexA = 0;
	int indexB = 0;
	while (indexA < A.size() && indexB < B.size())
	{
		if (A[indexA][0] == B[indexB][0])
		{
			sum += A[index][1] * B[indexB][1];
			indexA++;
			indexB++;
		}
		else if (A[indexA][0]>B[indexB][0])indexB++;
		else indexA++;
	}
	return sum;
}


// binary search

int binarySearch(vector<vector<int>>&B, int index)
{
	int low = 0, high = B.size() - 1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (B[mid][0] == index)return mid;
		else if (B[mid][0] > index)high = mid;
		else low = mid + 1;
	}
	return B[low][0] == index ? low : -1;
}
int dotProduct(vector<vector<int>>A, vector<vector<int>>B)
{
	int sum = 0;
	for (vector<int>pair : A)
	{
		int index = pair[0];
		int indexB = binarySearch(B, index);
		if (indexB != -1)sum += pair[1] * B[indexB][1];
	}
	return sum;
}


//amazing number
public static int amazingNumber(int[] nums) {
	int n = nums.length;
		// Keeps track of all the intervals that after right-shifting index, some numbers become amazing number.
		int[] shifts = new int[n];
	for (int i = 0; i < n; i++) {
		// If the current number is negative or larger than the biggest index, it won't affect the final result.. visit 1point3acres.com for more.
		if (nums[i] >= n || nums[i] <= 0) continue;

		if (nums[i] > i) {
			// Right shift index i + 1 --> the current index would be n-1 after shifting
			shifts[i + 1] += 1;
			if (nums[i] > i + 1) shifts[i + 1 + n - nums[i]] -= 1;
		}
		else {
			// There would be two intervals for each nums[i] <= i
			shifts[0] += 1;
			shifts[i - nums[i] + 1] -= 1;

			if (i != n - 1) shifts[i + 1] += 1;
		}
	}

	int sum = 0, max = 0, index = 0;
	for (int i = 0; i < shifts.length; i++) {
		sum += shifts[i];
		if (sum > max) {
			max = sum;
			index = i;
		}
	}

	return index;
}

//413 && 446 
//Arithmetic Slices
//Arithmetic Slices II - Subsequence

A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence :

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
int numberOfArithmeticSlices(vector<int>& nums) {
	int n = nums.size();
	if (n<3)return 0;
	vector<int>dp(n + 1, 0);
	for (int i = 3; i <= n; ++i)
	{
		int j = i;
		int count = 0;
		while (j >= 3 && 2 * nums[j - 2] == nums[j - 1] + nums[j - 3]){ j--; count++; }
		dp[i] = dp[i - 1] + count;
	}
	return dp[n];
}
// better solution 
int numberOfArithmeticSlices(vector<int>& nums)
{
	int curr = 0, sum = 0,n=nums.size();
	for (int i = 2; i < n; ++i)
	{
		if (nums[i] + nums[i - 2] == 2 * nums[i - 1])
		{
			curr++;
			sum += curr;
		}
		else curr = 0;
	}
	return sum;
}

// 446 Arithmetic Slices II - Subsequence
//Both time and space complexity are O(n ^ 2)
int numberOfArithmeticSlices(vector<int>& nums) {
	//dynamic programming
	int ans = 0, n = nums.size();
	if (nums.empty())return ans;
	vector<unordered_map<int, int>>dp(n);
	for (int i = 1; i < n; ++i)
	{
		long long diff = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			diff = (long long)nums[i] - (long long)nums[j];
			if (dp[j].count(diff) > 0)
			{
				ans += dp[j][diff];// this is 数列，3个数是一个数列，不仅仅是差值了。
				dp[i][diff] += dp[j][diff];//这只是存的差值
			}
			++dp[i][diff];
		}
	}
	return ans;
}

//longest Arithmetic sequence
// the idea is to maintain a 2d array, called length[input.length][input.length]
// length[i][j] means the length of the arithmetic that ends with input[i] and input[j]
//and a hashamp to record the index of every nunber
// we traverse the input from index 1 to the end
//everytime we meet a number, fix this as the end of sequence
// then traverse back tand try to make every number as the second number 
// when we fix one as the second last one number ,we calculate the gap as input[last]-input[secondlast]
//look into hashmap to  find is there a number in the input equals to input[secondlast]-gap;
// and check its index whether it is samller than secondlast;
//if it is, then this is the thrid last number, and we should alreay have length[thirdLast][secondLast]
//then the length[secondlst][last]=length[thirdlast][secondlast]+1;
//if it is not ,we make length[second][last]=2--- those two number are the only number int the arithmetic


//time O(N2) SPACE COMPLEXITY: O(N2) for only return length
int findLongest(vector<int>input)
{
	if (input.size() < 2)return 2;
	int maxLen = 2,n=input.size();
	vector<vector<int>>length(n, vector<int>(n, 0));
	unordered_map<int, vector<int>>valueToIndex;
	for (int i = 0; i < n; ++i)valueToIndex[input[i]].push_back(i);
	for (int index = 1; index < n; ++index)
	{
		for (int secondLast = index - 1; secondLast >= 0; --secondLast)
		{
			int gap = input[index] - input[secondLast];
			int next = input[secondLast] - gap;
			if (valueToIndex.find(next) != valueToIndex.end())
			{
				int nextIndex = -1;
				for (int j = valueToIndex[next].size() - 1; j >= 0; --j)
				{
					if (valueToIndex[next][j] < secondLast)
					{
						nextIndex = valueToIndex[next][j];
						break;
					}
				}
				if (nextIndex != -1)
				{
					length[secondLast][index] = length[nextIndex][secondLast] + 1;
					maxLen = max(maxLen, length[secondLast][index]);
				}
			}
			if (length[secondLast][index] == 0)length[secondLast][index] = 2;
		}
	}
	return maxLen;

}




// print out the sequence

//'Time complexity: O(n^2), space complexity: O(n^2 * m) --m is the average length of all the arithmetic sequence'
vector<int>printLongest(vector<int>input)
{
	vector<int>res;
	if (input.size() <= 2)return input;
	int maxLen = 0,n=input.size();
	vector<vector<vector<int>>>length(n, vector<vector<int>>(n, vector<int>()));
	unordered_map<int, vector<int>>valueToIndex;
	for (int i = 0; i < n; ++i)valueToIndex[input[i]].push_back(i);
	for (int index = 1; index < n; ++index)
	{
		for (int secondLast = index - 1; secondLast >= 0; --secondLast)
		{
			int gap = input[index] - input[secondLast];
			int next = input[secondLast] - gap;
			if (valueToIndex.find(next) != valueToIndex.end())
			{
				int nextIndex = -1;
				for (int j = valueToIndex[next].size() - 1; j >= 0; --j)
				{
					if (valueToIndex[next][j] < secondLast)
					{
						nextIndex = valueToIndex[next][j];
						break;
					}
				}
				if (nextIndex != -1)
				{
					length[secondLast][index].push_back(input[index]);
					if (maxLen < length[secondLast][index].size())
					{
						res = length[secondLast][index];
						maxLen = res.size();
					}
				}
			}
			if (length[secondLast][index].empty())
			{
				length[secondLast][index].push_back(input[secondLast]);
				length[secondLast][index].push_back(input[index]);
			}
		}
	}
	return res;
}

//products of subsets of primes
//product of elements in the array some thing like the sets;
void dfs(unordered_set<int>& res, vector<int>& input, vector<int>& path, int pos)
{
	if (!path.empty())
	{
		int re = 1;
		for (int x : path)re *= x;
		res.insert(re);
		//return;
	}
	for (int i = pos; i <input.size(); ++i)
	{
		path.push_back(input[i]);
		dfs(res, input, path, i + 1);
		path.pop_back();
	}
}
vector<int>product(vector<int>& input)
{
	unordered_set<int>res;
	vector<int>path;
	sort(input.begin(), input.end());
	dfs(res, input, path, 0);
	vector<int>ans(res.begin(), res.end());
	return ans;
}

public List<Integer> subsets(int[] nums) {
	List<Integer> res = new ArrayList<>();
	if (nums == null || nums.length == 0) {
		return res;
	}
	helper(res, nums, 1, 0);
	//Arrays.sort(res); if res should be sorted, add this
	return res;
}

private void helper(List<Integer> res, int[] nums, int product, int index) {
	//if we only need to print the results, we don't need res, we can use this:
	// if (product != 1) {
	//     System.out.print(product + " ");
	// }
	if (product != 1) {
		res.add(product);
	}
	for (int i = index; i < nums.length; i++) {
		product *= nums[i];
		helper(res, nums, product, i + 1);
		product /= nums[i];
	}
}

// products of subsets of nums: (no dups or have dups in nums are the same)
public class Solution {
	public List<Integer> subsets(int[] nums) {
		if (nums == null || nums.length == 0) {
			return new ArrayList<>();
		}
		HashSet<Integer> res = new HashSet<>();
		helper(res, nums, 1, 0);
		return new ArrayList<>(res);
		//Arrays.sort(res); if res should be sorted, create a new list and add this, then return it
	}

	private void helper(HashSet<Integer> res, int[] nums, int product, int index) {
		//if we only need to print the results, we don't need res, we can use this:
		// if (product != 1) {
		//     System.out.print(product + " ");
		// }
		if (product != 1 && !res.contains(product)) {
			res.add(product);
		}
		for (int i = index; i < nums.length; i++) {
			product *= nums[i];
			helper(res, nums, product, i + 1);
			product /= nums[i];
		}
	}
}

// products of subsets of primes: (have dups in nums)
public class Solution {
	public List<Integer> subsets(int[] nums) {
		List<Integer> res = new ArrayList<>();
		if (nums == null || nums.length == 0) {
			return res;
		}
		Arrays.sort(nums);//to avoid dups, we need this, or you can directly use hashset though
		helper(res, nums, 1, 0);
		//Arrays.sort(res); if res should be sorted, add this
		return res;
	}

	private void helper(List<Integer> res, int[] nums, int product, int index) {
		//if we only need to print the results, we don't need res, we can use this:
		// if (product != 1) {
		//     System.out.print(product + " ");
		// }
		if (product != 1) {
			res.add(product);
		}
		for (int i = index; i < nums.length; i++) {
			if (i != index && nums[i] == nums[i - 1]) {
				continue;//to avoid dups, we need this
			}
			product *= nums[i];
			helper(res, nums, product, i + 1);
			product /= nums[i];
		}
	}
}

// you can use bit manupilation

//products of subsets of primes: (no dups in nums)
//iterative: O((existOrNot ^ nums.length) * nums.length)=O((2^n) * n) time, O(1) space
public class Solution {
	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> res = new ArrayList<>();
		if (nums == null || nums.length == 0) {
			return res;
		}
		int n = nums.length;
		//Arrays.sort(nums); no need to sort
		for (int i = 0; i < (1 << n); i++) {//2^n kinds of state 
			int product = 1;
			for (int j = 0; j < n; j++) {//if jth bit of i is 1,nums[j] exists in this combination;Note set doesn't have order
				if ((i & (1 << j)) != 0) {//don't use ==1 cuz this's only jth bit! eg.110 & 010=010=2,doesn't means it's 1 !! 
					product *= nums[j];//also remember to add () for (i & (1 << j)) !!!!!!
				}
			}
			res.add(product);
		}
		return res;
	}
}

//combination sum
void dfs(vector<vector<int>>& res, vector<int>& path, int n, int k, int cur)
{
	if (path.size() == k)
	{
		res.push_back(path);
		return;
	}
	else if (path.size() > k)return;
	for (int i = cur; i <= n; ++i)
	{
		path.push_back(i);
		dfs(res, path, n, k, i + 1);
		path.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>>res;
	vector<int>path;
	dfs(res, path, n, k, 1);
	return res;
}

//combination sum
void backtracking(vector<vector<int>>&res, vector<int>& path, vector<int> candidates, int target, int cur)
{
	if (target == 0)
	{
		res.push_back(path);
		return;
	}
	else if (target < 0)return;
	for (int i = cur; i < candidates.size(); ++i)
	{
		if (target >= candidates[i])
		{
			path.push_back(candidates[i]);
			backtracking(res, path, candidates, target - candidates[i], i);
			path.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>>res;
	vector<int>path;
	backtracking(res, path, candidates, target, 0);
	return res;
}


//II
void dfs(vector<vector<int>> &res, vector<int> &path, vector<int>& candidates, int target, int cur)
{
	if (target == 0)
	{
		res.push_back(path);
		return;
	}
	else if (target<0)return;
	for (int i = cur; i<candidates.size(); ++i)
	{
		if (i>cur&& candidates[i] == candidates[i - 1])continue;
		if (target >= candidates[i])
		{
			path.push_back(candidates[i]);
			dfs(res, path, candidates, target - candidates[i], i + 1);
			path.pop_back();
		}
		else return;
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>>res;
	vector<int>path;
	if (candidates.empty() || target <= 0)return res;
	sort(candidates.begin(), candidates.end());
	dfs(res, path, candidates, target, 0);
	return res;
}

///iii
void dfs(vector<vector<int>> &res, vector<int> &path, int k, int n, int cur)
{
	if (path.size() == k && n == 0)
	{
		res.push_back(path);
		return;
	}
	for (int i = cur; i <= 9; ++i)
	{
		if (n >= i)
		{
			path.push_back(i);
			dfs(res, path, k, n - i, i + 1);
			path.pop_back();
		}
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>>res;
	if (k <= 0 || n <= 0)return res;
	vector<int>path;
	dfs(res, path, k, n, 1);
	return res;
}

//IV
// 377 combination sum IV

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

//@taobupt

// normal solution, without sort
public class Solution {
	public int combinationSum4(int[] nums, int target) {
		if (nums == null) {
			return 0;
		}
		int[] dp = new int[target + 1];//dp[i] means how many combinations of sum we can have for i with those nums
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			for (int j : nums) {
				if (i >= j) {
					dp[i] += dp[i - j];
				}
			}
		}
		return dp[target];
	}
}


//// if target is much larger than num of nums, we can sort nums and break the inner for loop if j > i
int combinationSum4(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<int>dp(target + 1, 0);
	dp[0] = 1;
	int n = nums.size();
	for (int i = 1; i <= target; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i >= nums[j])
			{
				dp[i] += dp[i - nums[j]];
			}
			else break;
		}
	}
	return dp[target];
}

//recrusive memory based

int combinationSum4Recrusive(vector<int>& nums, int target, vector<int>& dp)
{
	if (dp[target] != -1)return dp[target];
	int res = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (target >= nums[i])
		{
			res += combinationSum4Recrusive(nums, target - nums[i], dp);
		}
		else break;
	}
	dp[target] = res;
	return res;

}

int combinationSum4(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<int>dp(target + 1, -1);
	dp[0] = 1;
	return combinationSum4Recrusive(nums, target, dp);
}


//follow up
//What if negative numbers are allowed in the given array ?
//Then adding a num to the combination is not guaranteed to be increasing, which means I can add a huge bounch of negative nums
//and add a huge bounch of positive nums to achieve a target sum.eg.target = 0 : [-1, 1], [-1, -1, 1, 1], [-1, -1, -1, 1, 1, 1]...

//How does it change the problem ?
//We will have lots of lots of possible combinations, even infinity.

//What limitation we need to add to the question to allow negative numbers ?
//For example, each negative num can only be used once, etc.

// get next inorder 
TreeNode* getNext(TreeNode* x)
{
	if (x == NULL)return NULL;
	TreeNode* successor = NULL;
	if (x->right)
	{
		successor = x->right;
		while (successor->left)successor = successor->left;
	}
	else
	{
		successor = x->parent;
		while (successor && successor->rgiht = x)
		{
			x = x->parent;
			successor = successor->parent;
		}
	}
	return successor;
}


///
/*

给一个正数n，打印出所有相加的组合
例如10可以打印出 鏉ユ簮涓€浜�.涓夊垎鍦拌鍧�.
1+1+1+...1. Waral 鍗氬鏈夋洿澶氭枃绔�,
1+2+1+...1
..
9+1
10

*/

//actually this is combination sum

// find k th smallest from sorted arrays;
// merge k sorted arrays
// 23 merge k sorted lists
//Suppose the total number of nodes is n The total time complexity if (n * log k).For a priority queue, insertion takes logK time
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(nullptr){}
};

struct cmp{
	bool operator()(ListNode* a, ListNode* b)
	{
		return a->val>b->val;
	}
};
//// Heap O(nlogk) time and O(k) space:
ListNode* mergeKLists(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
	for (ListNode* li : lists)if (li)pq.push(li);
	ListNode* first = new ListNode(0);
	ListNode* node = first;
	while (!pq.empty())
	{
		node->next = pq.top();
		node = node->next;
		pq.pop();
		if (node && node->next)pq.push(node->next);
		if (pq.size() == 1)break;
	}
	node->next = pq.empty() ? NULL : pq.top();
	return first->next;
}

// Divide and Conquer O(nlogk) time and O(logk) space:
public class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if (lists == null || lists.length == 0) {
			return null;
		}
		return helper(lists, 0, lists.length - 1);
	}

	private ListNode helper(ListNode[] lists, int start, int end) {
		if (start == end) {
			return lists[start];
		}
		int mid = start + (end - start) / 2;
		ListNode left = helper(lists, start, mid);
		ListNode right = helper(lists, mid + 1, end);
		return merge(left, right);
	}

	private ListNode merge(ListNode head1, ListNode head2) {
		ListNode dummy = new ListNode(0);
		ListNode curr = dummy;
		while (head1 != null && head2 != null) {
			if (head1.val < head2.val) {
				curr.next = head1;
				head1 = head1.next;
			}
			else {
				curr.next = head2;
				head2 = head2.next;
			}
			curr = curr.next;
		}
		if (head1 != null) {
			curr.next = head1;
		}
		if (head2 != null) {
			curr.next = head2;
		}
		return dummy.next;
	}
}

//merge k sorted arrays
struct cmp{
	bool operator()(pair<vector<int>::iterator, vector<int>::iterator> it1, pair<vector<int>::iterator, vector<int>::iterator> it2)
	{
		return *(it1.first) > *(it2.first);
	}
};

//// iterator for merge k sorted arrays, heap: O(nlogk) time, O(k) space
vector<int> mergeKsortedArrays(vector<vector<int>>res)
{
	priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, cmp>pq;
	for (int i = 0; i < res.size(); ++i)if (!res[i].empty())pq.push(make_pair(res[i].begin(), res[i].end()));
	int count = 0, ans = 0;
	vector<int>res1;
	while (!pq.empty())
	{
		vector<int>::iterator it = pq.top().first;
		vector<int>::iterator end = pq.top().second;
		pq.pop();
		ans = (*it);
		res1.push_back(ans);
		if (it + 1 != end)pq.push(make_pair(it + 1, end));
	}
	return res1;
}

class KsortedArraysIterator{

public:
	KsortedArraysIterator(vector<vector<int>>res)
	{
		vv = res;
		for (int i = 0; i < vv.size(); ++i)if (!vv[i].empty())pq.push(make_pair(vv[i].begin(), vv[i].end()));
	}
	bool hasNext()
	{
		return !pq.empty();
	}
	int next()
	{
		vector<int>::iterator it = pq.top().first;
		vector<int>::iterator end = pq.top().second;
		pq.pop();
		int ans = (*it);
		if (it + 1 != end)pq.push(make_pair(it + 1, end));
		return ans;
	}
private:
	vector<vector<int>>vv;
	priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, cmp>pq;
};



struct cmp{
	bool operator()(pair<vector<int>::iterator, vector<int>::iterator> it1, pair<vector<int>::iterator, vector<int>::iterator> it2)
	{
		return *(it1.first) > *(it2.first);
	}
};

int kthsmallest(vector<vector<int>>res, int k)
{
	priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, cmp>pq;
	for (int i = 0; i < res.size(); ++i)if (!res[i].empty())pq.push(make_pair(res[i].begin(), res[i].end()));
	int count = 0, ans = 0;
	while (!pq.empty())
	{
		vector<int>::iterator it = pq.top().first;
		vector<int>::iterator end = pq.top().second;
		pq.pop();
		count++;
		ans = (*it);
		if (count == k)return ans;
		if (it + 1 != end)pq.push(make_pair(it + 1, end));
	}
	return 0;
}

//find median of sorted arrays
struct cmp{
	bool operator()(pair<vector<int>::iterator, vector<int>::iterator> it1, pair<vector<int>::iterator, vector<int>::iterator> it2)
	{
		return *(it1.first) > *(it2.first);
	}
};

double findMedian(vector<vector<int>>res)
{
	priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, cmp>pq;
	for (int i = 0; i < res.size(); ++i)if (!res[i].empty())pq.push(make_pair(res[i].begin(), res[i].end()));
	int count = 0, ans = 0, total = 0, prev = 0;
	for (int i = 0; i < res.size(); ++i)total += res[i].size();
	while (!pq.empty())
	{
		vector<int>::iterator it = pq.top().first;
		vector<int>::iterator end = pq.top().second;
		pq.pop();
		count++;
		prev = ans;
		ans = (*it);
		if (count == total / 2 + 1)break;
		if (it + 1 != end)pq.push(make_pair(it + 1, end));
	}
	if (total & 0x1)return 1.0*ans;
	else return (ans*1.0 + prev*1.0) / 2.0;
}


//// Use minHeap to poll out the interval with smallest start time
// Check if it has next interval to push into heap in its list
// Then check heap.peek(), which should always with the smallest start time
// check if heap.peek().start <= curInterval.end
// Then we need to merge. poll out this interval and merge
// curInterval.end = Math.max(curInterval.end, heap.peek().end)
// Keep doing the operation above util heap.peek().start > curInterval.end
// Add curInterval to result.
/*'Time complexity: O(nlgk) -- k lists of interval, total number of interval is n
Space complexity : O(k) --space of min heap'
class MergeKthSortedIntervals {
	public List<Interval> merge(Interval[][] intervals) {
		List<Interval> result = new ArrayList<>();
		if (intervals.length == 0) {
			return result;
		}
		PriorityQueue<IntervalContainer> minInterval = new PriorityQueue<>(intervals.length, new Comparator<IntervalContainer>() {
			@Override
				public int compare(IntervalContainer inter1, IntervalContainer inter2) {
				return inter1.interval.start - inter2.interval.start;
			}
		});
		for (int i = 0; i < intervals.length; i++) {
			if (intervals[i].length > 0) {
				minInterval.add(new IntervalContainer(intervals[i][0], 0, i));
			}
		}
		while (!minInterval.isEmpty()) {
			IntervalContainer curContainer = minInterval.poll();
			addNextToMinInterval(minInterval, curContainer, intervals);
			while (!minInterval.isEmpty() && minInterval.peek().interval.start <= curContainer.interval.end) {
				IntervalContainer nextContainer = minInterval.poll();
				addNextToMinInterval(minInterval, nextContainer, intervals);
				curContainer.interval.end = Math.max(curContainer.interval.end, nextContainer.interval.end);
			}
			result.add(new Interval(curContainer.interval.start, curContainer.interval.end));
		}
		return result;
	}
	private void addNextToMinInterval(PriorityQueue<IntervalContainer> minInterval, IntervalContainer container, Interval[][] intervals) {
		if (intervals[container.listIndex].length - 1 > container.index) {
			minInterval.add(
				new IntervalContainer(
				intervals[container.listIndex][container.index + 1],
				container.index + 1,
				container.listIndex));
		}
	}

}

class IntervalContainer {
	public Interval interval;
	public int index;
	public int listIndex;
	public IntervalContainer(Interval interval, int index, int listIndex) {
		this.interval = interval;
		this.index = index;
		this.listIndex = listIndex;
	}
}

class Interval {
	public int start;
	public int end;
	public Interval(int start, int end) {
		this.start = start;
		this.end = end;
	}
}
*/


// arrangeMissions
//task
//schedule
//gap 
//cooldown time
string arrange(string input, int k)
{
	if (input.size() < 1)return input;
	string res;
	unordered_map<char, int>missionTotime;//key is character and value is its corresponding time
	int time = 0, n = input.size();
	for (int i = 0; i < n; ++i)
	{
		time++;
		if (missionTotime.find(input[i]) == missionTotime.end() || time - missionTotime[input[i]] > k)//the time difference between previous input[i] and current input[i] is large than k,
		{
			missionTotime[input[i]] = time;
		}
		else
		{
			int gap = k - (time - missionTotime[input[i]] - 1);
			while (gap)
			{
				res.push_back('_');
				gap--;
			}
			time = k + missionTotime[input[i]] + 1;
			missionTotime[input[i]] = time;
		}
		res.push_back(input[i]);
	}
	return res;
}

// mission order, same task cannot be called in a period (missions,task,cd)
int missionOrder(vector<int>mission, int k)
{
	if (mission.empty())return 0;
	unordered_map<int, int>mp;// whose key is task id and its value is its'time
	int time = 0,n=mission.size();
	for (int i = 0; i < n; ++i)
	{
		time++;
		if (mp.find(mission[i]) == mp.end() || time - mp[mission[i]] > k)
		{
			mp[mission[i]] = time;
		}
		else
		{
			time = k + mp[mission[i]] + 1;
			mp[mission[i]] = time;
		}
	}
	return time;
}

//if cooldown is very small, but there are lots of tasks, how to reduce space? O(cooldown) space
private static int taskSchedule2(int[] tasks, int cooldown) {
	if (tasks == null || tasks.length == 0) {
		return 0;
	}
	Queue<Integer> queue = new LinkedList<>();//store tasks that are waiting for cooldown?
	HashMap<Integer, Integer> map = new HashMap<>();//store indices, where cooldown stops, of tasks in window
	int slots = 0;
	for (int task : tasks) {
		if (map.containsKey(task) && map.get(task) > slots) {
			//add this code if our output is a string, eg.AA, 2 -> A__A
			//int waitingTime = map.get(task) - slots;
			//for (int i = 0; i < waitingTime; i++) {
			//    sb.append("_");
			//}
			slots = map.get(task);//if we need to wait for the cooldown of the same task, just update the slots
		}
		if (queue.size() == cooldown + 1) {
			map.remove(queue.poll());//we should do this after updating the slots, cuz we store indices of cooldown
		}//stops, we don't know whether we have any idol period between these two same tasks yet, so update it first
		map.put(task, slots + cooldown + 1);//update the time slot to the time when curr task can be done again
		queue.offer(task);
		slots++;//update the used 1 slot of curr task
	}
	return slots;
}

//minimize time
// if can change the order of mission, how to minize the time ""
// always arrange the mission with highest frequence
//if its time interval is smaller than k, find the second highest mission
// if all mission's time interval smaller than k, just add '*'

//if tasks can be reordered, output the minimum time needed: O(n) time, O(n) space
private static int taskSchedule3(int[] tasks, int cooldown) {


	//统计task的次数
	HashMap<Integer, Integer> map = new HashMap<>();
	for (int task : tasks) {
		if (!map.containsKey(task)) {
			map.put(task, 1);
		}
		else {
			map.put(task, map.get(task) + 1);
		}
	}
	int maxFrequency = 0;
	int countOfMax = 0;//how many times the most frequent task occur
	for (int frequency : map.values()) {
		if (frequency > maxFrequency) {
			maxFrequency = frequency;
			countOfMax = 1;
		}
		else if (frequency == maxFrequency) {
			countOfMax++;
		}
	}
	int minimumTime = (maxFrequency - 1) * (cooldown + 1) + countOfMax;
	return Math.max(minimumTime, tasks.length);
	//(maxFrequency - 1) * (cooldown + 1) + countOfMax;
	//(maxFrequency - 1): number of minimum time interval; (cooldown + 1): length of each minimum time interval;
	//countOfMax: the number of tasks at the end (the cooldown of these tasks don't need to be filled)
	//eg. 1113, cooldown = 0, minimumTime = (3-1)*1 + 1 = 3, task.length = 4, we should return 4
	//eg. 1123, cooldown = 1, minimumTime = (2-1)*2 + 1 = 3, task.length = 4, we should return 4
	//eg. 11122, cooldown = 2, minimumTime = (3-1)*3 + 1 = 7 (1 2 _ 1 2 _ 1), task.length = 5, we should return 7
}
/**
* Find the task that appears for the most time
* Use a map to count the number of the times the task appears  then get the maximum count
* the result is decided by the maximum count and the number of tasks with maximum count
*
* two conditions:
* 1.  5 4 _ _ _ 5 4 _ _ _ 5 4 _ _ _ 5 4  the rest tasks cannot fill the empty slots
*     5 4 3 2 _ 5 4 3 2 _ 5 4 _ _ _ 5 4
*     the answer is (maxCount - 1) * (interval + 1) + CountOfMax
* 1. 5 4 _ _ _ 5 4 _ _ _ 5 4 _ _ _ 5 4  the rest tasks cannot fill the empty slots
*    5 4 3 2 1 6 5 4 3 2 1 6 5 4 6 _ _ 5 4
*    the answer is the length of the nums
*    the task which does not have max count first fills the empty slots and then just insert any valid place
* */

//output a sequence of tasks that takes least time:O(maxFrequency*klogk) time,O(n) space,n is number of unique tasks
private static String taskSchedule4(String str, int k) {
	StringBuilder rearranged = new StringBuilder();

	//统计frequence
	Map<Character, Integer> map = new HashMap<>();
	for (char c : str.toCharArray()) {
		if (!map.containsKey(c)) {
			map.put(c, 0);
		}
		map.put(c, map.get(c) + 1);
	}

	Queue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<>(new Comparator<Map.Entry<Character, Integer>>() {
		public int compare(Map.Entry<Character, Integer> entry1, Map.Entry<Character, Integer> entry2) {
			return entry2.getValue() - entry1.getValue();
		}
	});
	maxHeap.addAll(map.entrySet());//O(nlogn) time, O(n) space
	ArrayList<Map.Entry<Character, Integer>> temp = new ArrayList<>();//O(k) space

	while (!maxHeap.isEmpty()) {//O(max frequency) time
		int i = 0;
		temp.clear();
		while (i <= k && !maxHeap.isEmpty()) {//O(k) time
			Map.Entry<Character, Integer> curr = maxHeap.poll();
			rearranged.append(curr.getKey());
			curr.setValue(curr.getValue() - 1);
			temp.add(curr);
			i++;
		}

		//add this code if we wanna add _ to show that we need to wait for cooldown, eg.AABB, 2 -> AB_AB
		while (i <= k) {//i <= k, not i < k !!!
			rearranged.append("_");
			i++;//remember to add i++ !!!
		}

		for (Map.Entry<Character, Integer> e : temp) {//O(klogk) time
			if (e.getValue() > 0) {
				maxHeap.offer(e);
			}
		}
	}

	//add this code if we add "_" to the string, we need to delete all the "_" at the tail, eg.A__A__ -> A__A
	for (int i = rearranged.length() - 1; i >= 0 && rearranged.charAt(i) == '_'; i--) {
		rearranged.deleteCharAt(i);
	}

	return rearranged.toString();
}
}

// has common substring
//kcommon
//common string
//k coomon string
// Use a 2d array to record the length, and array[indexA][indexB] means that if 
// A.charAt(indexA) == B.charAt(indexB) the length of substring that ends with A.charAt(indexA)
// else it is 0
// So when we traverse the array, if A.charAt(indexA) == B.charAt(indexB)
// Then array[indexA][indexB] = array[indexA - 1][indexB - 1] + 1
bool hasCommonThanK(string A, string B, int k)
{
	if (k <1)return true;
	int m = A.size(), n = B.size();
	vector<vector<int>>common(m + 1, vector<int>(n + 1, 0));
	for (int indexA = 1; indexA <= m; ++indexA)
	{
		for (int indexB = 1; indexB <= n; ++indexB)
		{
			if (A[indexA - 1] == B[indexB - 1])
			{
				common[indexA][indexB] = common[indexA - 1][indexB - 1] + 1;
			}
			if (common[indexA][indexB] >= k)
			{
				cout << indexA << " " << indexB << endl;
				return true;
			}
		}
	}
	return false;
}

// We don't need to create DoublyListNode, we only modify left->prev,right->next
//tree to doublelist
//tree2doublelist
//treeto double list
//tree to doublelist
//tree to doublelinkedlist

//itreative way
//// recursive and iterative are all O(n) time, // I doubt O(h) space
TreeNode* bst2doublelist(TreeNode* root)
{
	TreeNode* dummy = new TreeNode(0);
	TreeNode* prev = dummy;
	stack<TreeNode*>stk;
	while (root != nullptr || !stk.empty())
	{
		while (root != nullptr)
		{
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		prev->right = root;
		root->left = prev;
		prev = root;
		root = root->right;
	}
	// if circular, add:
	prev->right = dummy->right;
	dummy->right->left = prev;
	return dummy->right;
}


//dfs way; inorder;
TreeNode* prev11 = nullptr;
void inorder(TreeNode* root)
{
	if (root == nullptr)return;
	inorder(root->left);
	root->left = prev11;
	prev11->right = root;
	prev11 = root;
	inorder(root->right);
}

TreeNode* bstToDoubleList(TreeNode* root)
{
	TreeNode* dummy = new TreeNode(0);
	prev11 = dummy;
	inorder(root);
	//if circular,add:
	prev11->right = dummy->right;
	dummy->right->left = prev11;
	return dummy->right;
}

//if global variable is not allowed,
//you can use below
void inorder(TreeNode* root, TreeNode*& prev11)// don't forget about the reference
{
	if (root == nullptr)return;
	inorder(root->left, prev11);
	root->left = prev11;
	prev11->right = root;
	prev11 = root;
	inorder(root->right, prev11);
}

TreeNode* bstToDoubleList(TreeNode* root)
{
	TreeNode* dummy = new TreeNode(0);
	TreeNode* prev11 = dummy;
	inorder(root, prev11);
	//if circular,add:
	prev11->right = dummy->right;
	dummy->right->left = prev11;
	return dummy->right;
}

//109
// sorted list to binary tree
TreeNode* makeTreebyNode(ListNode* head, ListNode* tail)
{
	if (head == tail)return NULL;
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast!=tail && fast->next!=tail)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->left = makeTreebyNode(head, slow);
	root->right = makeTreebyNode(slow->next, tail);
	return root;
}
TreeNode* sortedListToBST(ListNode* head) {
	if (head == NULL)return NULL;
	return makeTreebyNode(head, NULL);
}

//sorted array to bst
  TreeNode* makeBSTrees(vector<int>&nums, int begin, int end)
{
	if (begin > end)return NULL;
	else if (begin == end)return new TreeNode(nums[begin]);
	else
	{
		int mid = begin + (end - begin) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = makeBSTrees(nums, begin, mid - 1);
		root->right = makeBSTrees(nums, mid + 1, end);
		return root;
	}
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	int begin = 0, end = int(nums.size()) - 1;
	return makeBSTrees(nums, begin, end);
}

//flatten tree to linked list
//flatten binary tree to linked list
//morris traversal O(n) time, O(1) space
// draw a tree graph
void flatten(TreeNode *root) {
	TreeNode*now = root;
	while (now)
	{
		if (now->left)
		{
			//Find current node's prenode that links to current node's right subtree
			TreeNode* pre = now->left;
			while (pre->right)
			{
				pre = pre->right;
			}
			pre->right = now->right;
			//Use current node's left subtree to replace its right subtree(original right 
			//subtree is already linked by current node's prenode
			now->right = now->left;
			now->left = NULL;
		}
		now = now->right;
	}
}

//recrusive
//reverse preorder
TreeNode* prev1 = NULL;
void flatten(TreeNode* root) {
	if (root == NULL)return;
	flatten(root->right);
	flatten(root->left);
	root->right = prev1;
	root->left = NULL;
	prev1 = root;
}

//no use global varibale
public void flatten(TreeNode root) {
	flatten(root, null);
}
private TreeNode flatten(TreeNode root, TreeNode pre) {
	if (root == null) return pre;
	pre = flatten(root.right, pre);
	pre = flatten(root.left, pre);
	root.right = pre;
	root.left = null;
	pre = root;
	return pre;
}


//java version
//preorder
TreeNode prev = null;
public void flatten(TreeNode root) {
	if (root == null) {
		return;
	}
	if (prev != null) {//skip the first null prev node
		prev.right = root;//we move curr node to the prev node's right
		prev.left = null;//don't need to worry about losing original prev.right cuz we've already store it to "right"
	}
	prev = root;
	TreeNode right = root.right;//save root's right before flattening,otherwise it will be covered
	flatten(root.left);
	flatten(right);
}


// use no global value
// 参考以上的程序
public TreeNode flatten(TreeNode root, TreeNode prev)
{
	if (root == null) {
		return prev;
	}
	if (prev != null) {//skip the first null prev node
		prev.right = root;//we move curr node to the prev node's right
		prev.left = null;//don't need to worry about losing original prev.right cuz we've already store it to "right"
	}
	prev = root;
	TreeNode right = root.right;//save root's right before flattening,otherwise it will be covered
	prev = flatten(root.left, prev);
	prev = flatten(right, prev);
	return prev;
}
public void flatten(TreeNode root) {
	if (root == null) {
		return;
	}
	TreeNode prev = null;
	flatten(root, prev);
}



// multilevel linked list
//http://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/


// flatten in different ways
// flatten a multi-level linkedlist (down first, next second)
public class Solution {
	private ListNode tail;//全局变量

	public ListNode flatten(ListNode head) {
		if (head == null) {
			return null;
		}
		tail = head;//keep track of the tail of list，全局变量会一直到最深处，最深处然后就是可以了
		ListNode next = head.next;//store the next
		if (head.down != null) {
			head.next = flatten(head.down);//connect all nodes in curr head's down part
		}
		if (next != null) {
			tail.next = flatten(next);//connect the tail to the next part
		}
		return head;
	}
}
1 - 2 - 3 - 4
|
7 - 8 - 10 - 12
| | |
9    16   11
| |
14   17 - 18 - 19 - 20
| |
15 - 23             21
|
24
Output:
1->2->7->9->14->15->23->24->8->16->17->18->19->20->21->10->11->12->3->4


// flatten a multi-level linkedlist (level by level)
public class Solution {
	public ListNode flatten(ListNode head) {
		if (head == null) {
			return null;
		}
		ListNode curr = head;
		ListNode tail = head;
		while (tail.next != null) {
			tail = tail.next;//get the tail of first level
		}
		while (curr != tail) {//while curr hasn't reached the tail of all lists
			if (curr.down != null) {//down is not null
				tail.next = curr.down;//append down to the tail
				while (tail.next != null) {
					tail = tail.next;//update the tail
				}
				curr.down = null;//remember to update the curr.down to null !!!
			}
			curr = curr.next;//update curr to next
		}
	}
}
10 - 5 - 12 - 7 - 11
| |
4 - 20 - 13 - 17 - 6
| | |
2   16   9 - 8
| |
3   19 - 15
Output:
10->5->12->7->11->4->20->13->17->6->2->16->9->8->3->19->15


// permutattion II
// 
void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
	if (i == j - 1) {
		res.push_back(num);
		return;
	}
	for (int k = i; k < j; k++) {
		if (i != k && num[i] == num[k]) continue;
		swap(num[i], num[k]);
		recursion(num, i + 1, j, res);
	}
}
vector<vector<int> > permuteUnique(vector<int> &num) {
	sort(num.begin(), num.end());
	vector<vector<int> >res;
	recursion(num, 0, num.size(), res);
	return res;
}

void dfs(vector<vector<int>>&res, vector<int>&path, vector<int>& nums)
{
	if (path.size() == nums.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i == 0 || nums[i] != nums[i - 1])
		{
			int cnt1 = 0, cnt2 = 0;
			for (int j = 0; j < nums.size(); ++j)if (nums[j] == nums[i])cnt1++;
			for (int j = 0; j < path.size(); ++j)if (path[j] == nums[i])cnt2++;
			if (cnt1 > cnt2)
			{
				path.push_back(nums[i]);
				dfs(res, path, nums);
				path.pop_back();
			}
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	sort(nums.begin(), nums.end());
	dfs(res, path, nums);
	return res;
}


//permutation I

void dfs(vector<vector<int>>&res, vector<int>nums, int pos)
{
	if (pos == nums.size())
	{
		res.push_back(nums);
		return;
	}
	for (int i = pos; i<nums.size(); ++i)
	{
		swap(nums[pos], nums[i]);
		dfs(res, nums, pos + 1);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>>res;
	dfs(res, nums, 0);
	return res;
}

// permutattion I
//O(n) stack space
void dfs(vector<vector<int>>&res, vector<int>&path, vector<int>& nums)
{
	if (path.size() == nums.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		bool flag = true;
		for (int j = 0; j < path.size(); ++j)
		{
			if (path[j] == nums[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			path.push_back(nums[i]);
			dfs(res, path, nums);
			path.pop_back();
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>>res;
	vector<int>path;
	dfs(res, path, nums);
	return res;
}

//leetcode 168


//excel
string convertToTitle(int n) {
	string res;
	while (n)
	{
		res = char((n - 1) % 26 + 'A') + res;
		n = (n - 1) / 26;
	}
	return res;
}
//better
return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26 + 'A');

//171 excel sheet column number
int result = 0;
for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
return result;

int titleToNumber(string s) {
	int res = 0, n = s.size();
	for (int i = 0; i<n; ++i)
	{
		res = 26 * res + int(s[i] - 'A' + 1);
	}
	return res;
}

//merge sort 

ListNode* mergeList(ListNode* h1, ListNode* h2)
{
	if (h1 == NULL || h2 == NULL)return h1 ? h1 : h2;
	ListNode* first = new ListNode(0);
	ListNode* h3 = first;
	while (h1 && h2)
	{
		if (h1->val > h2->val)
		{
			h3->next = h2;
			h2 = h2->next;
		}
		else
		{
			h3->next = h1;
			h1 = h1->next;
		}
		h3 = h3->next;
	}
	h3->next = h1 ? h1 : h2;
	return first->next;
}
ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = NULL;
	return mergeList(sortList(head), sortList(fast));
}

//merge sort array, 
//lo=0,hi=n
void guibing(int a[], int lo, int mi, int hi)
{
	int *A = a + lo;
	int lb = mi - lo;
	int lc = hi - mi;
	int *B = new int[lb];
	int *C = a + mi;
	for (int i = 0; i < lb; B[i] = A[i++]);
	for (int i = 0, j = 0, k = 0; j < lb;)
	{
		if ((k >= lc) || B[j] <= C[k])A[i++] = B[j++];
		if (k<lc && (B[j]>C[k]))A[i++] = C[k++];
	}
}
void merge_sort(int a[], int low, int high)
{
	if (high - low < 2)return;
	int middle = (high + low) >> 1;
	merge_sort(a, low, middle);
	merge_sort(a, middle, high);
	guibing(a, low, middle, high);
}



//266 palindrome permutation

bool canPermutePalindrome(string s) {
	unordered_map<char, int>mp;
	for (char a : s)mp[a]++;
	int odd = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->second & 0x1)
		{
			odd++;
			if (odd>1)return false;
		}
	}
	return true;
}

//better
bool canPermutePalindrome(string s) {
	int odd = 0, counts[256] = { 0 };
	for (char c : s)
		odd += ++counts[c] & 1 ? 1 : -1;//  if odd add 1, else substract 1;
	return odd <= 1;
}


// 267 palindrome permuationII
void getAllPermutations(vector<string>&ans, string res, char special)
{
	sort(res.begin(), res.end());
	string tmp;
	do{
		tmp = res;
		reverse(tmp.begin(), tmp.end());
		ans.push_back(special == ' ' ? res + tmp : res + special + tmp);
	} while (next_permutation(res.begin(), res.end()));
}
vector<string> generatePalindromes(string s) {
	unordered_map<char, int>mp;
	for (char c : s)mp[c]++;
	string res;
	int odd = 0;
	char special = ' ';
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->second & 0x1)
		{
			if (++odd>1)return{};
			special = it->first;
		}
		res.resize(res.size() + it->second / 2, it->first);// just insert half length, then you can do the permuatiton
	}
	vector<string>ans;
	getAllPermutations(ans, res, special);
	return ans;
}

// how many palindrome in the string
// palindrome substrings
// count palindrome
// all palindrome substring
int countPalindrome(string str)
{
	int i, j, k,n = str.size();
	unordered_set<string>sets;
	for (int i = 0; i < n; ++i)
	{
		sets.insert(str.substr(i, 1));
		k = i - 1; j = i + 1;//count odd length palindromes;
		while (k >= 0 && j < n && str[k] == str[j])
		{
			sets.insert(str.substr(k, j - k + 1));
			k--;
			j++;
		}
		k = i; j = i + 1;//count even length palidrom
		while (k >= 0 && j < n && str[k] == str[j])
		{
			sets.insert(str.substr(k, j - k + 1));
			k--;
			j++;
		}
	}
	return sets.size();
}

vector<string>AllsubPalindrome(string str)
{
	int i, j, k, n = str.size();
	unordered_set<string>sets;
	for (int i = 0; i < n; ++i)
	{
		sets.insert(str.substr(i, 1));
		k = i - 1; j = i + 1;//count odd length palindromes;
		while (k >= 0 && j < n && str[k] == str[j])
		{
			sets.insert(s.substr(k, j - k + 1));
			k--;
			j++;
		}
		k = i; j = i + 1;//count even length palidrom
		while (k >= 0 && j < n && str[k] == str[j])
		{
			sets.insert(str.substr(k, j - k + 1));
			k--;
			j++;
		}
	}
	vector<string>res(sets.begin(), sets.end());
	return res;
}
//leetcode 5 longest palindrome substring
// can use manacher algorithms
string longestPalindrome(string s) {
    int n = s.size(), start = 0, maxlength = 0;
	for (int i = 0;i < n;)
	{
		if (n - i <= maxlength / 2)break;
		int left = i, right = i;
		while (right < n - 1 && s[right] == s[right + 1])right++;
		i = right + 1;
		while (left > 0 && right < n - 1 && s[right + 1] == s[left - 1]) { right++;left--; }
		if (maxlength <right - left + 1)
		{
			start = left;
			maxlength = right - left + 1;
		}
	}
	return s.substr(start, maxlength);
    }


// longest palindrome subsequence
   int longestPalindromeSubsequence(string str)
{
   int n = strlen(str);
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems
 
 
   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++)
      L[i][i] = 1;
 
    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process. The values are filled in a
    // manner similar to Matrix Chain Multiplication DP solution (See
    // http://www.geeksforgeeks.org/archives/15553). cl is length of
    // substring
    for (cl=2; cl<=n; cl++)//cl: sublength
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][n-1];
}
// 29 divide two integer
//divide integer without division
   //So the overall complexity is O(( log N)^2)
int divide(int dividend, int divisor) {
	int flag = (dividend > 0) ^ (divisor > 0);
	if (dividend == 0)return 0;
	long long divid = (long long)dividend;
	long long divis = (long long)divisor;
	divid = llabs(divid); divis = llabs(divis);
	long long res = 0;
	while (divid >= divis)
	{
		long long c = divis;
		int i = 0;
		while (divid >= c)
		{
			divid -= c;
			c = c <<= 1;
			res += (1 << i);
			i++;
		}
	}
	res *= (flag ? -1 : 1);
	if (res > INT_MAX)return INT_MAX;
	else return res;
}


public long binSearch(long start, long end, long a, long b)
{
	long mid = (start + end) >> 1;
	if (mid == a / b)
		return mid;
	else if (mid<a / b)
		return binSearch(mid + 1, end, a, b);
	else
		return binSearch(start, mid, a, b);
}
public int divide(int aa, int bb) {
	boolean negative = (aa<0) ^ (bb<0);
	long a = Math.abs((long)aa);
	long b = Math.abs((long)bb);
	long q = 1;
	while (q*b<a)
		q *= 2;

	long res = binSearch(q >> 1, q, a, b);
	res = negative ? -res : res;
	if (res>(1 << 31) - 1)
		return (1 << 31) - 1;
	else if (res<-1 << 31)
		return (-1 << 31);
	else return (int)res;
}


//natural string compare;
int stringcompare(string str1,string str2)
{
	int index1=0,index2=0,m=str1.size(),n=str2.size();
	while(index1<m && index2<n)
	{
		if(str1[index1]==str2[index2] && !isdigit(str2[index2]))
		{
			index1++;
			index2++;
		}else if(isdigit(str1[index1]) && isdigit(str2[index2]))
		{
			int number1=0,number2=0;
			while(index1<m && isdigit(str1[index1]))
			{
				number1=10*number1+str1[index1++]-'0';
			}
			while(index2<n && isdigit(str2[index2]))
			{
				number2=10*number2+str2[index2++]-'0';
			}
			if(number1!=number2)return number1>number2?1:-1;
		}else// not equal or one is number
		{
			if(isdigit(str2[index2]))return 1;
			else if(isdigit(str1[index1]))return -1;
			if(str1[index1]!=str2[index2])return str1[index1]>str2[index2]?1:-1;
		}
	}
	if(index1==m && index2==n)return 0;
	return index1<m?1:-1;
}


//sorted tranform array
// square , from n-1 to 0, bigger changes
//public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
//        int n = nums.length;
//        int[] sorted = new int[n];
//        int i = 0, j = n - 1;
//        int index = a >= 0 ? n - 1 : 0;
//        while (i <= j) {
//            if (a >= 0) {
//                sorted[index--] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
//            } else {
//                sorted[index++] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[j--], a, b, c) : quad(nums[i++], a, b, c);
//            }
//        }
//        return sorted;
//    }
//    
//    private int quad(int x, int a, int b, int c) {
//        return a * x * x + b * x + c;
//    }
//return a list of sorted squares of a sorted array; two pointers, O(n) time and O(1) space
int quad(int x)
{
	return x*x;
}
vector<int>sortTransformedArray(vector<int>nums)
{
	int n = nums.size();
	vector<int>res(n, 0);
	int i = 0, j = n - 1;
	int index = n - 1;
	while (i <= j)
	{
		res[index--] = quad(nums[i]) >= quad(nums[j]) ? quad(nums[i++]) : quad(nums[j--]);
	}
	return res;
}


[-2, -1, 1, 2];;//left is -1,right is 1;
//然后两边走。
private static int[] sortedSquares(int[] a) {
	if (a == null || a.length == 0) {
		return new int[0];
	}
	int[] res = new int[a.length];//we assume the squares will not be larger than 2^31 - 1
	int right = 0;
	while (right < a.length && a[right] < 0) {//right can be oob (== a.length) if all nums are negative
		right++;
	}
	int left = right - 1;//left is the index of first negative number (can be -1 if all nums are non-negative)
	for (int i = 0; i < res.length; i++) {
		int leftSquare = left >= 0 ? a[left] * a[left] : Integer.MAX_VALUE;//if either one is oob, it will becomes
		int rightSquare = right < a.length ? a[right] * a[right] : Integer.MAX_VALUE;//Integer.MAX_VALUE
		if (rightSquare <= leftSquare) {//smaller square is added
			res[i] = rightSquare;
			right++;//moving from center to right
		}
		else {
			res[i] = leftSquare;
			left--;//moving from center to left
		}
	}
	return res;
}


// 62 unique paths

long long C(int m, int n)
{
	if (m < n - m)m = n - m;
	long long res = 1;
	for (int i = m + 1; i <= n; ++i)res *= i;
	for (int j = 1; j <= n - m; ++j)res /= j;
	return res;
}

int uniquePaths(int m, int n) {
	if (m < 1 || m + n < 2)return 0;
	return C(m - 1, m + n - 2);
}

//63 unique paths II
int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
	if (Grid.empty() || Grid[0].empty())return 0;
	int m = Grid.size(), n = Grid[0].size();
	if (Grid[m - 1][n - 1] == 1)return 0;
	vector<vector<int>>dp(m, vector<int>(n, 0));
	dp[m - 1][n - 1] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (Grid[m - 1][i] == 0 && dp[m - 1][i + 1] == 1)dp[m - 1][i] = 1;
	}
	for (int i = m - 2; i >= 0; --i)
	{
		if (Grid[i][n - 1] == 0 && dp[i + 1][n - 1] == 1)dp[i][n - 1] = 1;
	}
	for (int i = m - 2; i >= 0; --i)
	{
		for (int j = n - 2; j >= 0; --j)
		{
			dp[i][j] = Grid[i][j] == 1 ? 0 : dp[i + 1][j] + dp[i][j + 1];
		}
	}
	return dp[0][0];
}


// save space

//shortest path
// C++ program to find the shortest path between
// a given source cell to a destination cell.
#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 10

//to store matrix cell cordinates
struct Point
{
	int x;
	int y;
};

// An Data Structure for queue used in BFS
struct queueNode
{
	Point pt;  // The cordinates of a cell
	int dist;  // cell's distance of from the source
};

// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col)
{
	// return true if row number and column number
	// is in range
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

// function to find the shortest path between
// a given source cell to a destination cell.
int BFS(int mat[][COL], Point src, Point dest)
{
	// check source and destination cell
	// of the matrix have value 1
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return INT_MAX;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	// Mark the source cell as visited
	visited[src.x][src.y] = true;

	// Create a queue for BFS
	queue<queueNode> q;

	// distance of source cell is 0
	queueNode s = { src, 0 };
	q.push(s);  // Enqueue source cell

	// Do a BFS starting from source cell
	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;

		// If we have reached the destination cell,
		// we are done
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		// Otherwise dequeue the front cell in the queue
		// and enqueue its adjacent cells
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];

			// if adjacent cell is valid, has path and
			// not visited yet, enqueue it.
			if (isValid(row, col) && mat[row][col] &&
				!visited[row][col])
			{
				// mark cell as visited and enqueue it
				visited[row][col] = true;
				queueNode Adjcell = { { row, col },
					curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	//return -1 if destination cannot be reached
	return INT_MAX;
}
/*
Well, the code is accepted but it has some obvious redundancy. There are two major concerns:

Each time when we update path[i][j], we only need path[i - 1][j] (at the same column) and path[i][j - 1] (at the left column), so it is unnecessary to maintain the full m*n matrix. Maintaining two columns is enough.
There are some cases that the loop can be terminated earlier. Suppose obstacleGrid = [[0, 1, 0, 0], [0, 1, 0, 0], [0, 1, 0, 0]], then we can see that it is impossible to reach the bottom-right corner after updating the second column since the number of paths to reach each element in the second column is 0.
Taken these into considerations, we write down the following optimized code.

class Solution {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                pre[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {
                cur[0] = pre[0];
                if (cur[0]) flag = true; 
            }
            else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] = cur[i - 1] + pre[i];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            if (!flag) return 0;
            swap(pre, cur);
        }
        return pre[m - 1];
    }
}; 
Further inspecting the above code, keeping two vectors only serve for the purpose of recovering pre[i], which is simply cur[i] before its update. So we can use only one vector and the space is further optimized.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
        for (int j = 1; j < n; j++) {
            bool flag = false;
            if (obstacleGrid[0][j])
                cur[0] = 0;
            else flag = true;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] += cur[i - 1]; 
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0; 
            }
            if (!flag) return 0;
        }
        return cur[m - 1];
    }
};
*/

// min queue

//298 binary tree longest consecutive sequence
void dfs(TreeNode* root, int value, int& res, int count)
{
	if (root->val == value)
	{
		count++;
		res = max(res, count);
	}
	else count = 1;
	if (root->left)dfs(root->left, root->val + 1, res, count);
	if (root->right)dfs(root->right, root->val + 1, res, count);
}
int longestConsecutive(TreeNode* root) {
	if (root == NULL)return 0;
	int res = 0;
	dfs(root, root->val, res, 0);
	return res;
}


// check big/small endian

//navie solution
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

/*Main function to call above function for 0x01234567*/
int main()
{
	int i = 0x01234567;
	show_mem_rep((char *)&i, sizeof(i));
	getchar();
	return 0;
}

void checkEndianness()
{
	unsigned int i = 1;
	char *c = (char*)&i;
	if (*c)
		printf("Little endian");
	else
		printf("Big endian");
}

// print binary tree boundary
//Boundary Traversal of binary tree
//print tree boundary

//// A simple function to print leaf nodes of a binary tree
void printLeaves(TreeNode* root)
{
	if (root)
	{
		printLeaves(root->left);
		if (root->left == nullptr && root->right == nullptr)
		{
			printf("%d", root->val);
		}
		printLeaves(root->right);
	}
}


// a function to pring all left boundary nodes, except a leaf node
//print the nodes in top down manner

void printBoundaryLeft(TreeNode* root)
{
	if (root)
	{
		if (root->left)
		{
			// to ensure top down order, print the node
			// before calling itself for left subtree
			printf("%d", root->val);
			printBoundaryLeft(root->left);
		}
		else if (root->right)
		{
			printf("%d", root->val);
			printBoundaryLeft(root->right);
		}
		// do nothing if it is a leaf node, this way we avoid
		// duplicates in output
	}
}

// A function to print all right boundry nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(TreeNode* root)
{
	if (root)
	{
		if (root->right)
		{
			printBoundaryRight(root->right);
			printf("%d", root->val);
		}
		else if (root->left)
		{
			printBoundaryRight(root->left);
			printf("%d", root->val);
		}
		// do nothing if it is a leaf node, this way we avoid
		// duplicates in output
	}
}


void printBoundary(TreeNode* root)
{
	if (root)
	{
		printf("%d", root->val);
		// Print the left boundary in top-down manner.
		printBoundaryLeft(root->left);
		// Print all leaf nodes
		printLeaves(root->left);
		printLeaves(root->right);
		// Print the right boundary in bottom-up manner
		printBoundaryRight(root->right);
	}
}

//bfs way
public static List<Integer> printBinaryTreeBoundary(TreeNode root) {
	if (root == null) {
		return new ArrayList<>();
	}
	List<TreeNode> leaves = new ArrayList<>();
	List<TreeNode> right = new ArrayList<>();
	List<TreeNode> left = new ArrayList<>();
	getLeaves(leaves, root);//get leaves from rightmost to leftmost

	Queue<TreeNode> queue = new LinkedList<>();
	queue.add(root);
	while (!queue.isEmpty()) {
		int size = queue.size();
		left.add(queue.peek());//put each level's leftmost node to left
		for (int i = 1; i <= size; i++) {
			TreeNode curr = queue.poll();
			if (curr.left != null) {
				queue.add(curr.left);
			}
			if (curr.right != null) {
				queue.add(curr.right);
			}
			if (i == size) {//put each level's rightmost node to right
				right.add(curr);
			}
		}
	}

	Collections.reverse(left);//reverse left cuz we need left boundary's nodes to be in bottom-up order
	right.addAll(leaves);//put leaves after right boundary's nodes
	right.addAll(left);//put left boundary's nodes after leaves
	List<Integer> res = new ArrayList<>();
	HashSet<TreeNode> visited = new HashSet<>();
	for (TreeNode node : right) {
		if (visited.contains(node)) {
			continue;//sometimes leftmost node==rightmost node(only 1 node in the level),we only print rightmost one
		}
		visited.add(node);
		res.add(node.val);
	}
	return res;
}

private static void getLeaves(List<TreeNode> leaves, TreeNode root) {
	if (root == null) {
		return;
	}
	if (root.left == null && root.right == null) {
		leaves.add(root);
		return;
	}
	getLeaves(leaves, root.right);//put right leaves at the front
	getLeaves(leaves, root.left);//left leaves at the back
}



// reverse words in a string
//151 
void reverseWords(string &s) {
	istringstream stream(s);
	string tmp;
	string res;
	while (stream >> tmp)res = " " + tmp + res;
	s = res.size() >= 1 ? res.substr(1) : "";
}

//186 reverse words in a string II
void reverseWords(string &s) {
	int n = s.size(), i = 0, start = 0;
	while (i<n)
	{
		while (i<n && !isspace(s[i]))i++;
		reverse(s.begin() + start, s.begin() + i);
		start = i + 1;
		i++;
	}
	reverse(s.begin(), s.end());
	//cout << s << endl;
}


//89 graycode
vector<int> grayCode(int n) {
	vector<int>res;
	res.push_back(0);
	for (int i = 0; i<n; ++i)
	{
		int nn = res.size();
		for (int j = nn - 1; j >= 0; --j)
		{
			res.push_back(res[j] | 1 << i);
		}
	}
	return res;
}

///build suffix array
//O(n2logn); string compare need O(N)

//actually you can improve
/*We first sort all suffixes according to first character, then according to first 2 characters, then first 4 characters 
and so on while the number of characters to be considered is smaller than 2n. The important point is, if we have sorted suffixes according to first 2i characters, 
then we can sort suffixes according to first 2i + 1 characters in O(nLogn) time using a nLogn sorting algorithm like Merge Sort.This is possible as two suffixes can be compared in O(1) 
time(we need to compare only two values, see the below example and code).*/

//and you can use radix sort to lower time complexity to O(N)log(N)
//http://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/
vector<int>buildSuffixArray(string input)
{
	vector<pair<string, int>>v;
	int n = input.size();
	for (int i = 0; i < n; ++i)
	{
		v.push_back(make_pair(input.substr(i), i));
	}
	sort(v.begin(), v.end(), [](pair<string, int>p1, pair<string, int>p2){return p1.first < p2.first; });
	vector<int>res;
	for (auto it : v)res.push_back(it.second);
	return res;
}

//ease
//O(mLogn).

/*

字符串： "banana"的所有后缀如下：

0 banana                          5 a
1 anana     对所有后缀排序        3 ana
2 nana      ---------------->     1 anana
3 ana        字典序               0 banana
4 na                              4 na
5 a                               2 nana

所以 "banana" 的后缀数组SA为： {5, 3, 1, 0, 4, 2}
*/
int search(string pattern, string text, vector<int>&suffix)
{
	int n = suffix.size();
	int m = pattern.size();
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (pattern == text.substr(suffix[mid], m))return suffix[mid];//rank mid
		else if (pattern > text.substr(suffix[mid], m))l = mid + 1;// you should make rank higher
		else r = mid - 1;//rank lower
	}
	return -1;
}

//155 minstack
// min stack
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stk.push(x);
		if (minstack.empty() || minstack.top() > x)minstack.push(x);
		else minstack.push(minstack.top());
	}

	void pop() {
		stk.pop();
		minstack.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minstack.top();
	}
private:
	stack<int>stk;
	stack<int>minstack;
};

//follow up use only one stack
//the idea is to sotre the gap between the min value and the current value
//the problem for my solution is the cast, I have no idea to avoid the cast
// since the possible gap between the current value and the min value could be integer
//MAX_VALUE-MIN_Value
class MinStack{
private:
	long long min;
	stack<long long>stk;
public:
	MinStack()
	{

	}
	void push(int x)
	{
		if (stk.empty())
		{
			stk.push(0);
			min = x;
		}
		else
		{
			stk.push(x - min);
			if (x < min)min = x;
		}
	}

	void pop()
	{
		if (stk.empty())return;
		long long pop = stk.top();
		stk.pop();
		if (pop < 0)min = min - pop;
	}
	int top()
	{
		long long top = stk.top();
		if (top > 0)return (int)(top + min);
		else return (int)min;
	}
	int getMin()
	{
		return (int)min;
	}

};

//follow max stack
//MAXSTACK
// has been tested
class MaxStack{
private:
	long long max;
	stack<long long>stk;
public:
	MaxStack()
	{

	}
	void push(int x)
	{
		if (stk.empty())
		{
			stk.push(0);
			max = x;
		}
		else
		{
			stk.push(max - x);
			if (x > max)max = x;
		}
	}

	void pop()
	{
		if (stk.empty())return;
		long long pop = stk.top();
		stk.pop();
		if (pop < 0)max = max+pop;
	}
	int top()
	{
		long long top = stk.top();
		if (top > 0)return (int)(-top + max);
		else return (int)max;
	}
	int getMin()
	{
		return (int)max;
	}

};
//min queue
class minQueue{
private:
	queue<int>q1;
	deque<int>minqueue;
public:
	minQueue()
	{

	}
	void push(int x)
	{
		while (!minqueue.empty() && minqueue.back() > x)
		{
			minqueue.pop_back();
		}
		q1.push(x);
		minqueue.push_back(x);
	}

	int front()
	{
		return q1.front();
	}

	int getMin()
	{
		return minqueue.front();
	}
	void pop()
	{
		if (q1.empty())return;
		if (q1.front() == minqueue.front())minqueue.pop_front();
		q1.pop();
	}

	bool empty()
	{
		return q1.empty();
	}
};


//find minimum in rotated sorted array
//153
//pivot
int findMin(vector<int>& nums) {
	int n = nums.size(), left = 0, right = n - 1, middle = 0;
	while (left < right)
	{
		if (nums[left] < nums[right])return nums[left];
		middle = left + (right - left) / 2;
		if (nums[middle] > nums[right])left = middle + 1;
		else right = middle;
	}
	return nums[left];
}

//find valley
//find peek
public class Solution {
	//maximum drop(must be dropped from left to right, no dups in array, only 1 peak or 1 valley, V or A shape)
	private static int maxDrop(int[] a) {
		if (a == null || a.length < 2) {
			return 0;
		}
		int n = a.length;
		if (a[0] < a[1]) {
			return findPeak(a, 0, n - 1) - a[n - 1];//peak - right min
		}
		else if (a[0] > a[1]) {
			return a[0] - findValley(a, 0, n - 1);//left max - valley
		}
		return 0;
	}

	private static int findPeak(int[] a, int start, int end) {
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (a[mid - 1] < a[mid] && a[mid] < a[mid + 1]) {
				start = mid;
			}
			else if (a[mid - 1] > a[mid] && a[mid] > a[mid + 1]) {
				end = mid;
			}
			else {
				return a[mid];
			}
		}
		// they are orginal sorted, so just return the maximum 
		if (a[start] > a[end]) {
			return a[start];
		}
		return a[end];
	}

	private static int findValley(int[] a, int start, int end) {
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (a[mid - 1] < a[mid] && a[mid] < a[mid + 1]) {
				end = mid;
			}
			else if (a[mid - 1] > a[mid] && a[mid] > a[mid + 1]) {
				start = mid;
			}
			else {
				return a[mid];
			}
		}
		//// they are orginal sorted, so just return the minimum 
		if (a[start] < a[end]) {
			return a[start];
		}
		return a[end];
	}
}

// find the index of valley or peek
//A[i]=A[i-1]+-1;
//const time solution
//two case: nums[0],nums[1];
//设结果的的index是x，value是y，nums的长度是len，解二元一次方程
//x - 0 = y - nums[0]
//x - (len - 1) = - (y - nums[len - 1])

//valley
//x - 0 =nums[0]-y
//x - (len - 1) = (y - nums[len - 1])

//binary search
int findindex(vector<int>nums)
{
	int n = nums.size();
	if (nums.empty())return -1;
	if (abs(nums[n - 1] - nums[0]) == n - 1)return -1;//there is no such valley or peak
	int left = 0, right = n - 1, mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if ((nums[mid - 1] - nums[mid])*(nums[mid + 1] - nums[mid]) > 0)return mid;
		int diffindex = mid - left;
		int diffvalue = abs(nums[mid] - nums[left]);
		if (diffindex == diffvalue)left = mid;
		else right = mid;
	}
	return mid;
}

//house robber
//198
//rob house
//robber
int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)return 0;
	
	//if(n==1)return nums[0];
	//if(n==2)return max(nums[0],nums[1]);
	int a = 0, b = 0;//it is similar to dp, you could consider a as previous max num at even, b as previous max num at odd
	for (int i = 0; i<n; ++i)
	{
		if (i & 0x1)
		{
			b = max(b + nums[i], a);
		}
		else a = max(a + nums[i], b);
	}
	return max(a, b);
}
//follow up rob which house
//parent array

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)return 0;
	//if(n==1)return nums[0];
	//if(n==2)return max(nums[0],nums[1]);
	unordered_map<int, int>mp;
	int a = 0, b = 0;
	for (int i = 0; i<n; ++i)
	{
		if (i & 0x1)
		{
			if (b + nums[i]>a)mp[b + nums[i]] = i;
			b = max(b + nums[i], a);
		}
		else
		{
			if (a + nums[i]>b)mp[a + nums[i]] = i;
			a = max(a + nums[i], b);
		}
	}
	int x = max(a, b);
	while (mp.count(x))
	{
		cout << mp[x] << " ";
		x -= nums[mp[x]];
	}
	return max(a, b);
}

// using list;;//changes always 
list<int>rob(vector<int>nums)
{
	list<int>rob_house;
	list<int>notRob_house;
	if (nums.empty())return rob_house;
	bool robCurr = true;
	int maxValue = 0;
	int rob = 0;//the max profit we can get from 0 to i house, if we rob curr i house
	int notrob = 0;//the max profit we can get from 0 to i house, if we don't rob curr i house
	int n = nums.size();
	for (int i = 0; i < n; ++i)
	{
		int tmp = rob;//store the value of "we rob last house"
		list<int>tmpRob_house(rob_house.begin(), rob_house.end());
		rob = notrob + nums[i];//if rob curr house,we can't rob last house,so rob curr = not rob last house + curr house's money
		rob_house = list<int>(notRob_house.begin(), notRob_house.end());
		rob_house.push_back(i);
		if (notrob < tmp)notRob_house = tmpRob_house;
		notrob = max(notrob, tmp);//if we don't rob curr house,we choose the max money from we rob/notRob last house
		robCurr = rob >= notrob;;
		maxValue = max(rob, notrob);//try to update the max from we rob/notRob curr house
	}
	return robCurr ? rob_house : notRob_house;
}

//66 plus one
vector<int> plusOne(vector<int>& digits) {
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9)digits[i] = 0;
		else{
			digits[i]++;
			return digits;
		}
	}
	digits[0] = 1;
	digits.push_back(0);
	return digits;
}

//给N个数，找出其中k个乘积最大的数，不需要连续。和leetcode那道题的联系度很低。
//maxK_product
public static long maxK_Product(Integer[] num, int k){
	if (num == null || num.length == 0 || k <= 0 || k>num.length)
		return 0;
	long result = Long.MIN_VALUE;
	Arrays.sort(num, new Comparator<Integer>(){
		public int compare(Integer a, Integer b){
			if ((long)(a*b)>0){
				return b - a;
			}
			else if ((long)(a*b) == 0){
				if (a == 0)
					return 1;
				else
					return -1;
			}
			else{
				return a>0 ? 1 : -1;
			}
		}
	});
	long tmp = 1;
	int count = 0;
	for (int i = 0; i<num.length; ++i){
		if (num[i] == 0){
			result = Math.max(0, result);
			break;
		}
		count++;
		tmp *= num[i];
		if (count == k){
			result = Math.max(result, tmp);
			tmp = tmp / num[i + 1 - k];
			count--;
		}
	}
	return result;
}

//long increasing sequence
//LIS
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size(), res = 1;
	if (n <= 1)return n;
	vector<int>dp(n, 1);
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[i]>nums[j])dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	//sort(dp.begin(), dp.end());// is not increaing all the way  dp[i] ：the number of <=nums[i]
	return res;
}

int lengthOfLIS(vector<int>& nums) {
vector<int> res;
for (int i = 0; i<nums.size(); i++) {
	auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
	if (it == res.end()) res.push_back(nums[i]);
	else *it = nums[i];
}
return res.size();
}
// subarray

int longestConsecutive(vector<int>& nums) {
	if (nums.empty())return 0;
	int n = nums.size(), maxLength = 1, start = 0;
	for (int i = 1; i < j; ++i)
	{
		if (nums[i] < nums[i - 1])
		{
			maxLength = max(i - start, maxLength);
			start = i;
		}
		else
		{
			maxLength = max(i - start + 1, maxLength);
		}
	}
	return maxLength;
}

//87 scramble string
// recursive: exponential complexity (O(2^n) time), O(n) stack space, O(256n) memory space?
bool isScramble(string s1, string s2) {
	if (s1.size() != s2.size())return false;
	if (s1 == s2)return true;
	int cnt[26] = { 0 };
	for (int i = 0; i < s1.size(); ++i)
	{
		cnt[s1[i] - 'a']++;
		cnt[s2[i] - 'a']--;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] != 0)return false;
	}
	for (int i = 1; i < s1.size(); ++i)
	{
		string substr = s1.substr(0, i);
		if (isScramble(substr, s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))return true;
		if (isScramble(substr, s2.substr(s1.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s1.size() - i)))return true;
	}
	return false;
}

// dp: O(n^4) time, O(n^3) memory space

bool isScramble(string s1, string s2)
{
	if (s1.size() != s2.size())return false;
	if (s1 == s2)return true;
	int n = s1.size();
	vector<vector<vector<bool>>>dp(n, vector <vector<bool>>(n, vector<bool>(n + 1, false)));
	//dp[i][j][len]:str starts from s1's i,& str starts from s2's j,both with len length,are scramble?
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)//initialize the dp[i][j][1],if two char are same, they are scramble
		{
			dp[i][j][1] = s1[i] == s2[j];////string with len 1 means the char,if 2 chars are same,return true
		}
	}
	for (int len = 2; len <= n; ++len)//start from 2 cuz we have already initialize dp[i][j][len = 1]
	{
		for (int i = 0; i <= n - len; ++i)////we can start from any index i as long as a len length string can be included
		{
			for (int j = 0; j <= n - len; ++j)
			{
				for (int k = 1; k < len; ++k)//k:the length of one of the partitioned string,the other's length is len-k
				{

					if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i + k][j][len - k] && dp[i][j + len - k][k])) {
						dp[i][j][len] = true;

					}
				}
			}
		}
	}
	return dp[0][0][n];
}



//get k max

vector<int> GetKMax(vector<int>nums, int k)// k number from nums
{
	vector<int>res(k, 0);
	int n = nums.size(), le = 0;
	for (int i = 0; i < n; ++i)
	{
		while (le && le + n - i > k && nums[i] > res[le - 1])
			le--;
		if (le < k)res[le++] = nums[i];
	}
	return res;
}

//> and < has no transitivity
//http://stackoverflow.com/questions/8704829/find-the-best-element-from-the-given-list

//34 search for a range
int mylower_bound(vector<int>& nums, int target)
{
	int pos = 0, n = nums.size(), left = 0, right = n - 1, mid = 0;
	if (target>nums.back())return n;
	while (left<right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] >= target)
		{
			right = mid;
			pos = right;
		}
		else
		{
			left = mid + 1; pos = left;
		}

	}
	return pos;
}
int myupper_bound(vector<int>& nums, int target)
{
	int pos = 0, n = nums.size(), left = 0, right = n - 1, mid = 0;
	if (target >= nums.back())return n;
	while (left<right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid]>target)
		{
			right = mid;
			pos = right;
		}
		else
		{
			left = mid + 1; pos = left;
		}

	}
	return pos;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int n = nums.size();
	int index1 = mylower_bound(nums, target);
	//cout<<index1<<endl;
	if (index1 == n || nums[index1] != target)return{ -1, -1 };
	int index2 = myupper_bound(nums, target);
	return{ index1, index2 - 1 };

}

//224 basic calculator

//O(N)

//The expression string may contain open(and closing parentheses), the plus + or minus sign - ,
//non - negative integers and empty spaces .
//You may assume that the given expression is always valid.
int calculate(string s) {
	if (s.size() == 0)return 0;
	int sign = 1;//sign: the previous sign for curr num. initialize it as 1 is important!
	int n = s.size(), res = 0;
	stack<int>stk;
	for (int i = 0; i < n;)
	{
		int cur = 0;
		while (isspace(s[i]))i++;
		while (isdigit(s[i]))
		{
			cur = 10 * cur + (s[i++] - '0');
			if (i == n || !isdigit(s[i]))
			{
				res += cur*sign;
				break;
			}
		}
		if (s[i] == '+')sign = 1;
		else if (s[i] == '-')sign = -1;
		else if (s[i] == '(')
		{
			stk.push(res);
			res = 0;
			stk.push(sign);
			sign = 1;
		}
		else if (s[i] == ')')
		{
			res *= stk.top();
			stk.pop();
			res += stk.top();
			stk.pop();
			sign = 1;
		}
		i++;
	}
	return res;
}

//find the balanced point of an array where the points' leftsum==rightsum
int balancedPoint(vector<int>nums)
{
	if (nums.empty())return -1;
	int sum = 0,n=nums.size();
	for (int x : nums)sum += x;
	int leftsum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum -= nums[i];
		if (leftsum == sum)return i;
		leftsum += nums[i];//update right sum;
	}
	return -1;

}

//shortese palindrome
//214
string shortestPalindrome(string s) {
	string s2 = s;
	reverse(s2.begin(), s2.end());
	string ss = s + "#" + s2;
	int n = ss.size();
	vector<int>next(n, 0);
	int k = 0;
	for (int i = 1; i < n; ++i)
	{
		while (k>0 && ss[i] != ss[k])k = next[k - 1];
		if (ss[i] == ss[k])k++;
		next[i] = k;
	}
	int m = s.size() - next[n - 1];
	string res = s2.substr(0, m) + s;
	return res;
}

//min insertions/removal of getting a palindrome with given string
//求出当前string和它reversed string的LCS，然后用当前length减去LCS长度得出最少删除/插入字符回文了
public class Solution {
	private static int minRemovalPalindrome(String s) {
		if (s == null || s.length() == 0) {
			return 0;
		}
		int n = s.length();
		StringBuilder sb = new StringBuilder(s);
		String rev = sb.reverse().toString();
		return n - longestCommonSubsequence(s, rev, n, n);
	}

	private static int longestCommonSubsequence(String a, String b, int a_len, int b_len) {
		int[][] dp = new int[a_len + 1][b_len + 1];
		for (int i = 1; i <= a_len; i++) {
			for (int j = 1; j <= b_len; j++) {
				if (a.charAt(i - 1) == b.charAt(j - 1)) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[a_len][b_len];
	}
}


//31 next permutation
void nextPermutation(vector<int>& nums) {
	int k = -1;
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			k = i;
			break;
		}
	}
	if (k == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}
	int l = -1;
	for (int i = nums.size() - 1; i > k; i--) {
		if (nums[i] > nums[k]) {
			l = i;
			break;
		}
	}
	swap(nums[k], nums[l]);
	reverse(nums.begin() + k + 1, nums.end());
}

//find previous permutation
public void previousPermuation(int[] nums) {
	if (nums == null || nums.length == 0) {
		return;
	}
	int firstLarger = -1;
	for (int i = nums.length - 2; i >= 0; i--) {
		if (nums[i] > nums[i + 1]) {
			firstLarger = i;
			break;
		}
	}
	if (firstLarger == -1) {
		reverse(nums, 0, nums.length - 1);
		return;
	}
	int firstSmaller = nums.length - 1;//cuz it may be the last index!!!
	for (int i = firstLarger + 1; i < nums.length - 1; i++) {
		if (nums[i] < nums[firstLarger] && nums[i + 1] >= nums[firstLarger]) {
			firstSmaller = i;//nums.get(i+1) >= nums.get(firstLarger) !!!
			break;//find the last num that's smaller than firstLarger !!!
		}
	}
	swap(nums, firstLarger, firstSmaller);
	reverse(nums, firstLarger + 1, nums.length - 1);//remember to +1 !!!
}

private void swap(int[] nums, int left, int right) {
	int temp = nums[left];
	nums[left++] = nums[right];
	nums[right--] = temp;
}

private void reverse(int[] nums, int left, int right) {
	while (left < right) {
		swap(nums, left++, right--);
	}
}

//384 shuffle an array

Time Complexity : O(n), assuming that the function rand() takes O(1) time.

How does this work ?
The probability that ith element(including the last one) goes to last position is 1 / n, because we randomly pick an element in first iteration.

The probability that ith element goes to second last position can be proved to be 1 / n by dividing it in two cases.
Case 1 : i = n - 1 (index of last element) :
The probability of last element going to second last position is = (probability that last element doesn't stay at its original position) x (probability that the index picked in previous step is picked again so that the last element is swapped)
So the probability = ((n - 1) / n) x(1 / (n - 1)) = 1 / n
Case 2: 0 < i < n - 1 (index of non - last) :
The probability of ith element going to second position = (probability that ith element is not picked in previous iteration) x(probability that ith element is picked in this iteration)
So the probability = ((n - 1) / n) x(1 / (n - 1)) = 1 / n

We can easily generalize above proof for any other position.
class Solution {
	vector<int> nums;
public:
	Solution(vector<int> nums) {
		this->nums = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> result(nums);
		for (int i = 0; i < result.size(); i++) {
			int pos = rand() % (result.size() - i);
			swap(result[i + pos], result[i]);
		}
		return result;
	}
};

//36 valid sudoku

Three flags are used to check whether a number appear.

used1: check each row

   used2 : check each column

	   used3 : check each sub - boxes
bool isValidSudoku(vector<vector<char> > &board)
{
	int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };

	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[i].size(); ++j)
			if (board[i][j] != '.')
			{
				int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
				if (used1[i][num] || used2[j][num] || used3[k][num])
					return false;
				used1[i][num] = used2[j][num] = used3[k][num] = 1;
			}

	return true;
}
//37 sudolu solver
public void solveSudoku(char[][] board) {
	if (board == null || board.length == 0)
		return;
	solve(board);
}

public boolean solve(char[][] board){
	for (int i = 0; i < board.length; i++){
		for (int j = 0; j < board[0].length; j++){
			if (board[i][j] == '.'){
				for (char c = '1'; c <= '9'; c++){//trial. Try 1 through 9
					if (isValid(board, i, j, c)){
						board[i][j] = c; //Put c for this cell

						if (solve(board))
							return true; //If it's the solution return true
						else
							board[i][j] = '.'; //Otherwise go back
					}
				}

				return false;
			}
		}
	}
	return true;
}

private boolean isValid(char[][] board, int row, int col, char c){
	for (int i = 0; i < 9; i++) {
		if (board[i][col] != '.' && board[i][col] == c) return false; //check row
		if (board[row][i] != '.' && board[row][i] == c) return false; //check column
		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' &&
			board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; //check 3*3 block
	}
	return true;
}

//shortest path between knight and target 
public class Solution {
	//output min steps from a knight to a target in a matrix
	private static int[][] move = new int[][]{{1, 2}, { 2, 1 }, { -1, 2 }, { -2, 1 }, { 1, -2 }, { 2, -1 }, { -1, -2 }, { -2, -1 }};

	private static int knightToTarget(int[][] matrix, int x1, int y1, int x2, int y2) {
		if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
			return -1;
		}
		int m = matrix.length;
		int n = matrix[0].length;
		if (!isValid(matrix, m, n, x1, y1) || !isValid(matrix, m, n, x2, y2)) {
			return -1;
		}
		Queue<Integer> queue = new LinkedList<>();
		boolean[][] visited = new boolean[m][n];
		int res = 0;
		queue.offer(x1 * n + y1);
		visited[x1][y1] = true;//if we can modify the board, use board[x1][y1] = 1;
		while (!queue.isEmpty()) {
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				int key = queue.poll();
				int x = key / n;
				int y = key % n;
				if (x == x2 && y == y2) {
					return res;
				}
				for (int k = 0; k < move.length; k++) {
					int nextX = x + move[k][0];
					int nextY = y + move[k][1];
					if (isValid(matrix, m, n, nextX, nextY) && !visited[nextX][nextY]) {//board[nextX][nextY] != 1
						queue.offer(nextX * n + nextY);
						visited[nextX][nextY] = true;//board[nextX][nextY] = 1
					}
				}
			}
			res++;
		}
		return -1;
	}

	private static boolean isValid(int[][] matrix, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n) {
			return false;
		}
		return true;
	}
}

//mutal friends
class MutalFriend {
	public List<GraphNode> findMutalFriends(GraphNode me) {
		Queue<GraphNode> explore = new LinkedList<>();
		Set<GraphNode> friends = new HashSet<>();
		HashMap<GraphNode, Integer> mutalToCount = new HashMap<>();
		int level = 0;
		explore.offer(me);
		friends.add(me);
		while (!explore.isEmpty() && level <= 2) {
			level++;
			int size = explore.size();
			for (int i = 0; i < size; i++) {
				GraphNode node = explore.poll();
				for (GraphNode friend : node.friend) {
					if (level == 1) {
						friends.add(node);
						explore.offer(node);
						continue;
					}
					if (friends.contains(friend)) {
						continue;
					}
					if (!mutalToCount.containsKey(friend)) {
						mutalToCount.put(friend, 1);
					}
					else {
						mutalToCount.put(friend, mutalToCount.get(friend) + 1);
					}
				}

			}
		}
		List<GraphNode> result = new ArrayList<>();
		for (GraphNode node : mutalToCount.keySet()) {
			result.add(node);
		}
		Collections.sort(result, new NodeComparator(mutalToCount));
		return result;
	}
	class NodeComparator implements Comparator<GraphNode> {
		private HashMap<GraphNode, Integer> map;
		public NodeComparator(HashMap<GraphNode, Integer> map) {
			this.map = map;
		}
		@Override
			public int compare(GraphNode node1, GraphNode node2) {
			return map.get(node2) - map.get(node1);
		}
	}
}

class GraphNode {
	String name;
	List<GraphNode> friend;
	public GraphNode(String name) {
		this.name = name;
		this.friend = new ArrayList<>();
	}
}

//143 reorder linkedlist
//Given a singly linked list L : L0→L1→…→Ln - 1→Ln,
//reorder it to : L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1, 2, 3, 4 }, reorder it to{ 1, 4, 2, 3 }
ListNode* reverseList(ListNode* head) {
	ListNode* newHead = NULL;
	while (head)
	{
		ListNode* next = head->next;
		head->next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}
void reorderList(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL)return;
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = NULL;
	fast = reverseList(fast);
	slow = head;
	while (fast)
	{
		ListNode* tmp = fast->next;
		fast->next = slow->next;
		slow->next = fast;
		slow = fast->next;
		fast = tmp;
	}
}


//amazing number

//brute force;
O(N^2)
// is not allowed
int getNumberofAmazingNumber(int start, vector<int>nums)
{
	int n = nums.size();
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (nums[(i + start) % n] <= i)count++;
	}
	return count;
}
int maxAmazingNumber(vector<int>nums)
{
	int maxCount = 0, n = nums.size(), res = 0;
	for (int i = 0; i < n; ++i)
	{
		int count = getNumberofAmazingNumber(i, nums);
		if (count > maxCount)
		{
			maxCount = count;
			res = i;
		}
	}
	return res;
}

public int maxXing(int[][] nums) {
	if (nums.length == 0 || nums[0].length == 0)
		return 0;
	int rowHit = 0;
	int[] colHit = new int[nums[0].length];
	int max = 0;
	for (int i = 0; i < nums.length; i++) {
		for (int j = 0; j < nums[0].length; j++) {
			if (nums[i][j] == 0) continue;
			// get rowHit. From 1point 3acres bbs
			if (j == 0 || nums[i][j - 1] == 0) {
				rowHit = 0;
				while (j + rowHit < nums[0].length && nums[i][j + rowHit] == 1)
					rowHit++;
			}
			// get colHit
			if (i == 0 || nums[i - 1][j] == 0) {
				colHit[j] = 0;
				while (i + colHit[j] < nums.length && nums[i + colHit[j]][j] == 1)
					colHit[j] ++;
			}
			max = Integer.max(max, colHit[j] + rowHit - 1);
		}
	}
	return max;
}


Find least number of intervals from A that can fully cover B
For example :
Given A = [[0, 3], [3, 4], [4, 6], [2, 7]] B = [0, 6] return 2 since we can use[0, 3][2, 7] to cover the B
Given A = [[0, 3], [4, 7]] B = [0, 6] return 0 since we cannot find any interval combination from A to cover the B

// make sure every time we choose one interval we cover more time
// every time we chooes one, make the start time as its end time
// Always choose the interval that whose end time is the biggest
// and start time is smaller or equal to current start time
// util we got the end time bigger than input.end

//'time complexity: O(nlgn)'

class MinimumCoverInterval {
	public int findCover(Interval[] intervals, Interval interval) {
		Arrays.sort(intervals, new Comparator<Interval>() {
			@Override
				public int compare(Interval inter1, Interval inter2) {
				if (inter1.start == inter2.start) {
					return inter1.end - inter2.end;
				}
				return inter1.start - inter2.start;
			}
		});
		int count = 0;
		int start = interval.start;
		int end = -1;
		int index = 0;
		while (index < intervals.length && end < interval.end) {
			if (intervals[index].end <= start) {
				index++;
				continue;
			}
			if (intervals[index].start > start) {
				break;
			}
			while (index < intervals.length && end < interval.end && intervals[index].start <= start) {
				end = Math.max(intervals[index].end, end);
				index++;
			}
			if (start != end) {
				count++;
				start = end;
			}
		}
		if (end < interval.end) {
			return 0;
		}
		return count;
	}
}