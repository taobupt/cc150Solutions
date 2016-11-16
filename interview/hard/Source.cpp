#include"Codec.h"
template<typename T>
void printVector(vector<T>v)
{
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); ++it)cout << *it << " ";
	printf("\n");
}

template<class T>
void printVectorVector(vector<vector<T>>res)
{
	for (typename vector<vector<T>>::iterator it = res.begin(); it != res.end(); ++it)printVector(*it);
	printf("\n");
}


//// leetcode 314 vertical order
////@taobupt
//vector<vector<int>>verticalOrder(TreeNode* root)
//{
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	map<int, vector<int>>m;
//	queue<pair<TreeNode*, int>>q;
//	q.push(make_pair(root, 0));
//	while (!q.empty())
//	{
//		int size = q.size();
//		while (size--)
//		{
//			TreeNode* node = q.front().first;
//			int tmp = q.front().second;
//			q.pop();
//			m[tmp].push_back(node->val);
//			if (node->left)
//			{
//				q.push(make_pair(node->left, tmp - 1));
//			}
//			if (node->right)
//			{
//				q.push(make_pair(node->right, tmp + 1));
//			}
//		}
//	}
//	for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it)res.push_back(it->second);
//	return res;
//}
//
////104 maximum depth of tree
////@taobupt
//int maxDepth(TreeNode* root) {
//	if (root == NULL)return 0;
//	else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//}
//
//
////101 Minimum Depth of Binary Tree
////@taobupt
//int minDepth(TreeNode* root) {
//	if (root == NULL)return 0;
//	else if (root->left == NULL)return minDepth(root->right) + 1;
//	else if (root->right == NULL)return minDepth(root->left) + 1;
//	return min(minDepth(root->left), minDepth(root->right)) + 1;
//}
//
//
////226 Invert Binary Tree
////@taobupt
//TreeNode* invertTree(TreeNode* root) {
//	if (root == NULL)return NULL;
//	TreeNode* right = root->right;
//	root->right = invertTree(root->left);
//	root->left = invertTree(right);
//	return root;
//}
//
//
////100 same Tree
////@taobupt
//bool isSameTree(TreeNode* p, TreeNode* q) {
//	if (p == NULL || q == NULL)return p == q;
//	return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
////110 balance tree
////@ taobupt
//
//int GetHeight(TreeNode* root)
//{
//	if (root == NULL)return 0;
//	int l = GetHeight(root->left);
//	int r = GetHeight(root->right);
//	if (l < 0 || r < 0 || abs(l - r)>1)return -1;
//	return max(l, r)+1;   ////////I just froget the "+1"// wrong answer.
//}
//bool isBalanced(TreeNode* root) {
//	if (root == NULL)return true;
//	int l = GetHeight(root->left);
//	int r = GetHeight(root->right);
//	if (l < 0 || r < 0 || abs(l - r)>1)return false;
//	return true;
//}
//
//
//// 235 LCA of BST
////@ taobupt
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//	if (root == NULL || p == NULL || q == NULL)return NULL;
//	if (root->val > max(p->val, q->val))return lowestCommonAncestor(root->left, p, q);
//	else if (root->val < min(p->val, q->val))return lowestCommonAncestor(root->right, p, q);
//	return root;
//}
//
////236 LCA of binary tree
////@taobupt
//
//
////------------------------this is recrusive way--------------------------
//TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q) {
//	if (root == NULL || root == p || root == q)return root;
//	TreeNode* left = lowestCommonAncestorBT(root->left, p,q);
//	TreeNode* right = lowestCommonAncestorBT(root->right, p, q);
//	if (left && right)return root;
//	return left ? left : right;
//}
//
//// ----------------this is iterative way-----------
//vector<TreeNode*>stkToVector(stack<TreeNode*>stk)
//{
//	vector<TreeNode*>res;
//	while (!stk.empty())
//	{
//		res.push_back(stk.top());
//		stk.pop();
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}
//
//TreeNode* lowestCommonAncestorBTIterative(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//	stack<TreeNode*>stk;
//	vector<TreeNode*>pv;
//	vector<TreeNode*>qv;
//	if (root == NULL)return NULL;
//	unordered_map<TreeNode*, bool>vis;
//	stk.push(root);
//	vis[root] = true;
//	TreeNode* node = NULL;
//	while (!stk.empty())
//	{
//		node = stk.top();
//		if (node->left && !vis[node->left])
//		{
//			vis[node->left] = true;
//			stk.push(node->left);
//			if (node->left == p)
//			{
//				pv = stkToVector(stk);
//				if (!qv.empty())break;
//			}
//			if (node->left == q)
//			{
//				qv = stkToVector(stk);
//				if (!pv.empty())break;
//			}
//			continue;
//		}
//		if (node->right && !vis[node->right])
//		{
//			vis[node->right] = true;
//			stk.push(node->right);
//			if (node->right == p)
//			{
//				pv = stkToVector(stk);
//				if (!qv.empty())break;
//			}
//			if (node->right == q)
//			{
//				qv = stkToVector(stk);
//				if (!pv.empty())break;
//			}
//		}
//		stk.pop();
//	}
//	int i = 0;
//	int n = min(pv.size(), qv.size());
//	for (; i <n; ++i)
//	{
//		if (pv[i] != qv[i])break;
//	}
//	return i>=1?pv[i - 1]:NULL;
//}
//
//// leetcode 96 unique bst
////@taobupt
//
//
////cataland number
//int numTrees(int n) {
//	vector<int>catalan(n + 1, 1);
//	catalan[2] = 2;
//	catalan[3] = 5;
//	for (int i = 4; i <= n; ++i)
//	{
//		catalan[i] = 0;
//		for (int j = 0; j < i; ++j)
//		{
//			catalan[i] += catalan[j] * catalan[i - 1 - j];// derivate function
//		}
//	}
//	return catalan[n];
//
//}
//
//
//// leetcode 101 systemtic tree
////@ taobupt
//
//bool isSymmetric(TreeNode* p, TreeNode* q)
//{
//	if (p == NULL || q == NULL)return p == q;
//	return (p->val == q->val) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
//}
//bool isSymmetric(TreeNode* root) {
//	/*if (root == NULL||(root->left==NULL && root->right==NULL))return true;
//	if (root->left == NULL || root->right == NULL)return false;
//	return (root->left->val == root->right->val) && isSameTree(root->left->left, root->right->right) && isSameTree(root->left->right, root->right->left);*/
//	return root == NULL || isSymmetric(root->left, root->right);
//}
//
//
////leetcode 112 path sum
////@taobupt
//
//bool hasPathSum(TreeNode* root, int sum) {
//	if (root == NULL)return false;
//	if (root->left == NULL && root->right == NULL && sum == root->val)return true;
//	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
//}
//
//
////leetcode 102 level order traversal
//// @taobupt
//
//
////------------bfs---------
//vector<vector<int>> levelOrder(TreeNode* root) {
//	vector<vector<int>>res;
//	vector<int>inner;
//	queue<TreeNode*>q;
//	q.push(root);
//	TreeNode* node = NULL;
//	while (!q.empty())
//	{
//		int size = q.size();
//		inner.clear();
//		while (size--)
//		{
//			node = q.front();
//			q.pop();
//			inner.push_back(node->val);
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//		res.push_back(inner);
//	}
//	return res;
//}
//
//
////--------------------dfs------------
//
//
//void dfsLevelOrder(TreeNode* root, int level, vector<vector<int>>& res)
//{
//	if (root == NULL)return;
//	res[level].push_back(root->val);
//	dfsLevelOrder(root->left, level + 1, res);
//	dfsLevelOrder(root->right, level + 1, res);
//}
//
//vector<vector<int>> levelOrderDFS(TreeNode* root) {
//	int level = maxDepth(root);
//	vector<vector<int>>res(level);
//	dfsLevelOrder(root, 0, res);
//	return res;
//}
//
//
////leetcode 98 valid bst
////@taobupt
//
//TreeNode* pre = NULL;
//bool isValidBST(TreeNode* root) {
//	if (root == NULL)return true;
//	if (!isValidBST(root->left))return false;
//	if (pre != NULL && pre->val >= root->val)return false;
//	pre = root;
//	return isValidBST(root->right);
//}
//
//
////leetcode 124 maxPathsum
////@taobupt
//
//
//int dfsSum(TreeNode* root, int& res)
//{
//	if (root == NULL)return 0;
//	int l = dfsSum(root->left, res);
//	int r = dfsSum(root->right, res);
//	int ans = max(root->val, max(l, r) + root->val);
//	res = max(res, max(ans, l + r + root->val));
//	return ans;
//}
//
//int maxPathSum(TreeNode* root) {
//	int res = INT_MIN;
//	dfsSum(root, res);
//	return res;
//}
//
/////116 Populating Next Right Pointers in Each Node   actually you can solve it without data structrue. I will review tongiht
//// @taobupt
//void connect(TreeLinkNode *root) {
//	if (root == NULL)return;
//	queue<TreeLinkNode*>q;
//	q.push(root);
//	TreeLinkNode* node=NULL;
//	while (!q.empty())
//	{
//		int size = q.size();
//		while (size--)
//		{
//			node = q.front();
//			q.pop();
//			if (size > 0)node->next = q.front();  // have a bad status today, forget add two line below
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//	}
//
//}
//
////leetcode 173 BST iterator
////@taobupt
//class BSTIterator {
//public:
//	void inorder(TreeNode* root)
//	{
//		if (root == NULL)return;
//		inorder(root->left);
//		res.push_back(root->val);
//		inorder(root->right);
//	}
//	BSTIterator(TreeNode *root) {
//		inorder(root);
//		size = 0;
//	}
//
//	/** @return whether we have a next smallest number */
//	bool hasNext() {
//		return size<(int)res.size();
//	}
//
//	/** @return the next smallest number */
//	int next() {
//		return res[size++];
//	}
//private:
//	vector<int>res;
//	int size;
//};
//
//
///// converted sorted array to bst 108
////@taobupt
//
//TreeNode* createBST(vector<int>& nums, int left, int right)
//{
//	if (left > right)return NULL;
//	else if (left == right)return new TreeNode(nums[left]);
//	else
//	{
//		int mid = left + (right - left) / 2;
//		TreeNode* root = new TreeNode(nums[mid]);
//		root->left = createBST(nums, left, mid - 1);
//		root->right = createBST(nums, mid + 1, right);
//		return root;
//	}
//}
//
//TreeNode* sortedArrayToBST(vector<int>& nums) {
//	if (nums.empty())return NULL;
//	int n = nums.size();
//	return createBST(nums, 0, n - 1);
//}
//
//
//// 144 preorder sequence of tree
////@ taobupt
//
//vector<int> preorderTraversal(TreeNode* root) {
//	vector<int>res;
//	stack<TreeNode*>stk;
//	if (root == NULL)return res;
//	stk.push(root);
//	TreeNode* node = NULL;
//	while (!stk.empty())
//	{
//		node = stk.top();
//		stk.pop();
//		res.push_back(node->val);
//		if (node->right)stk.push(node->right);
//		if (node->left)stk.push(node->left);
//	}
//	return res;
//}
//
//
//void preorderDFS(TreeNode* root,vector<int>& res)
//{	
//	if (root == NULL)return;
//	res.push_back(root->val);
//	preorderDFS(root->left, res);
//	preorderDFS(root->right, res);
//}
//vector<int> preorderRecrusive(TreeNode* root) {
//	vector<int>res;
//	preorderDFS(root, res);
//	return res;
//}
//
//
//// 94 inorder Traversal 
//// @taobupt
//
//
//void inorderDFS(TreeNode* root, vector<int>& res)
//{
//	if (root == NULL)return;
//	inorderDFS(root->left, res);
//	res.push_back(root->val);
//	inorderDFS(root->right, res);
//}
//vector<int> inorderRecrusive(TreeNode* root) {
//	vector<int>res;
//	inorderDFS(root, res);
//	return res;
//}
//vector<int> inorderTraversal(TreeNode* root) {
//	vector<int>res;
//	if (root == NULL)return res;
//	stack<TreeNode*>stk;
//	while (root)
//	{
//		stk.push(root);
//		root = root->left;
//	}
//	TreeNode* node = NULL;
//	while (!stk.empty())
//	{
//		node = stk.top();
//		stk.pop();
//		res.push_back(node->val);
//		if (node->right)
//		{
//			node = node->right;
//			while (node)
//			{
//				stk.push(node);
//				node = node->left;
//			}
//		}
//	}
//	return res;
//}
//
//
////114 flatten binary tree to linked list
////@taobupt 
//
//void flatten(TreeNode* root) {
//	if (root == NULL)return;
//	TreeNode* save_right = root->right;
//	flatten(root->left);
//	root->right = root->left;
//	root->left = NULL;   /// this is very important ;
//	flatten(save_right);
//	TreeNode* node = root;
//	while (node->right)node = node->right;
//	node->right = save_right;
//}
//
/////222 count the complete nodes
////@taobupt
//int getLeftHeight(TreeNode* root)
//{
//	if (root == NULL)return 0;
//	int count = 0;
//	while (root)
//	{
//		count++;
//		root = root->left;
//	}
//	return count;
//}
//int getRightHeight(TreeNode* root)
//{
//	if (root == NULL)return 0;
//	int count = 0;
//	while (root)
//	{
//		count++;
//		root = root->right;
//	}
//	return count;
//}
//int countNodes(TreeNode* root) {
//	if (root == NULL)return 0;
//	int l = getLeftHeight(root);
//	int r = getRightHeight(root);
//	if (l == r)return (1 << l) - 1;
//	else return countNodes(root->left) + countNodes(root->right) + 1;
//}
//
//
//
//// google oa1
////-----------------------------------
////int replaceLarger(int input)
////{
////	int minValue = INT_MAX, maxValue = INT_MIN;
////	bool negative = input < 0;
////	unsigned int x = input < 0 ? -input:input;
////	string str = to_string(x);
////	int n = str.size();
////	for (int i = 1; i < n; ++i)
////	{
////		if (str[i]>str[i - 1])
////		{
////			maxValue = max(maxValue, stoi((i>=1?str.substr(0, i - 1):"") + str.substr(i)));
////			minValue = min(minValue, stoi((i>=1?str.substr(0, i - 1):"") + str.substr(i)));
////		}
////		else
////		{
////			maxValue = max(maxValue, stoi((i >= 1 ? str.substr(0, i) : "") + str.substr(i+1)));
////			minValue = min(minValue, stoi((i >= 1 ? str.substr(0, i) : "") + str.substr(i+1)));
////		}
////	}
////	return negative ? -1 * maxValue : minValue;
////}
////
////
////int replaceRound(int input)
////{
////	int maxValue = INT_MIN;
////	string str = to_string(input);
////	int n = str.size();
////	for (int i = 1; i < n; ++i)
////	{
////		int tmp = ((str[i] - '0') + (str[i - 1] - '0'));
////		tmp = (tmp % 2 == 0 ? tmp / 2 : (tmp + 1) / 2);
////		maxValue = max(maxValue, stoi((i >= 1 ? str.substr(0, i - 1) : "") + char(tmp+'0')+str.substr(i+1)));
////	}
////	return maxValue;
////	
////}
////
////
////int replaceGroup(int input)
////{
////	int maxValue = INT_MIN;
////	string str = to_string(input);
////	int n = str.size();
////	for (int i = 1; i < n; ++i)
////	{
////		if (str[i] == str[i - 1])
////		{
////			maxValue = max(maxValue, stoi((i >= 1 ? str.substr(0, i - 1) : "") + str.substr(i)));
////			maxValue = max(maxValue, stoi((i >= 1 ? str.substr(0, i) : "") + str.substr(i + 1)));
////		}
////	}
////	return maxValue;
////}
////
////
////
////string dash(string input,int k)
////{
////	if (input.empty() || k <= 0)return input;
////	int n = input.size(),count=0;
////	string res;//
////	for (int i = n - 1; i >= 0; --i)
////	{
////		if (input[i] == '-')continue;
////		else
////		{
////			if (count>0 && count% k == 0)res.push_back('-');
////			res.push_back(toupper(input[i]));
////			count++;
////		}
////	}
////	reverse(res.begin(), res.end());
////	return res;
////}
////
////
////
////struct info{
////	bool isbst;//
////	int size, min, max;
////	info() :size(0), min(INT_MAX), max(INT_MIN), isbst(true){}
////};
////
////	info* findLargest(TreeNode* root,int lower1,int bound1)
////	{
////		if (root == NULL)return new info();
////		info* left = findLargest(root->left,lower1,bound1);
////		info* right = findLargest(root->right,lower1,bound1);
////		info* m = new info();
////		if (!left->isbst ||!right->isbst|| !(right->max<=bound1 && left->min>=lower1 && root->val>=lower1 && root->val<=bound1))
////		{
////			m->isbst = false;
////			m->size = max(left->size, right->size);
////			return m;
////		}
////		m->size = left->size + right->size + 1;
////		m->isbst = true;
////		m->min = root->left ? left->min : root->val;
////		m->max = root->right ? right->max : root->val;
////		return m;
////	}
////	int largestBSTSubtree(TreeNode* root,int lower1,int bound1) {
////		return findLargest(root,lower1,bound1)->size;
////	}
////-----------------------------------------------------
//
////leetcode 95 unique binary tree
////@taobupt
//
//
//vector<TreeNode*>createTrees(int begin, int end)
//{
//	vector<TreeNode*>res;
//	if (begin > end)
//	{
//		res.push_back(NULL);
//		return res;
//	}
//	if (begin == end)
//	{
//		res.push_back(new TreeNode(begin));
//		return res;
//	}
//	for (int i = begin; i <= end; ++i)
//	{
//		vector<TreeNode*>left = createTrees(begin, i-1);
//		vector<TreeNode*>right = createTrees(i + 1, end);
//		for (int l = 0; l < (int)left.size(); ++l)
//		{
//			for (int r = 0; r < (int)right.size(); ++r)
//			{
//				TreeNode* root = new TreeNode(i);
//				root->left =left[l];
//				root->right =right[r];
//				res.push_back(root);
//			}
//		}
//	}
//	return res;
//}
//vector<TreeNode*> generateTrees(int n) {
//	return createTrees(1, n);
//}
//
//
//
/////99 recover bianry search tree
////@taobupt
//
//TreeNode* pre99 = NULL;
//TreeNode* first = NULL;
//TreeNode* second = NULL;
//
//void recoverDFS(TreeNode* root)
//{
//	if (root == NULL)return;
//	recoverDFS(root->left);
//	if (pre99 && pre99->val >= root->val)
//	{
//		if (first == NULL)first = pre99;
//		second = root;
//	}
//	pre99 = root;
//	recoverDFS(root->right);
//}
//void recoverTree(TreeNode* root) {
//	if (root == NULL || root->left == NULL && root->right == NULL)return;
//	recoverDFS(root);
//	swap(first->val, second->val);
//}
//
//
////Binary Tree Zigzag Level Order Traversal 103
////@taobupt
//vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	vector<int>inner;
//	queue<TreeNode*>q;
//	q.push(root);
//	TreeNode* node = NULL;
//	while (!q.empty())
//	{
//		int size = q.size();
//		inner.clear();
//		while (size--)
//		{
//			node = q.front();
//			q.pop();
//			inner.push_back(node->val);
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//		if (res.size() % 2 == 1)reverse(inner.begin(), inner.end());
//		res.push_back(inner);
//	}
//	return res;
//}
//
//
//// 107 binary tree level order travseral II 
////@taobupt
//
//vector<vector<int>> levelOrderBottom(TreeNode* root) {
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	vector<int>inner;
//	queue<TreeNode*>q;
//	q.push(root);
//	TreeNode* node = NULL;
//	while (!q.empty())
//	{
//		int size = q.size();
//		inner.clear();
//		while (size--)
//		{
//			node = q.front();
//			q.pop();
//			inner.push_back(node->val);
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//		res.push_back(inner);
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}
//
//
//
////leetcode 105 Construct Binary Tree from Preorder and Inorder Traversal
////@taobupt
//
//
//TreeNode* createTree(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2)
//{
//	if (begin1 > end1)return NULL;
//	if (begin1 == end1)return new TreeNode(preorder[begin1]);
//	TreeNode* root = new TreeNode(preorder[begin1]);
//	int index = begin2;
//	while (index <= end2)
//	{ 
//		if (preorder[begin1] == inorder[index])break;
//		index++;
//	}
//	root->left = createTree(preorder, begin1 + 1,index-begin2+begin1, inorder, begin2, index - 1);
//	root->right = createTree(preorder, index+begin1-begin2+1, end1, inorder, index + 1, end2);
//	return root;
//}
//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//	int n = preorder.size();
//	return createTree(preorder, 0, n - 1, inorder, 0, n - 1);
//}
//
//
/////113 path sumII
////@taobupt
//
//
//void pathSumDfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path)
//{
//	if (root->left == NULL && root->right == NULL && sum == 0)
//	{
//		res.push_back(path);
//		return;
//	}
//
//	if (root->left)
//	{
//		path.push_back(root->left->val);
//		pathSumDfs(root->left, sum - root->left->val, res, path);
//		path.pop_back();
//	}
//	if (root->right)
//	{
//		path.push_back(root->right->val);
//		pathSumDfs(root->right, sum - root->right->val, res, path);
//		path.pop_back();
//	}
//}
//
//
//vector<vector<int>> pathSum(TreeNode* root, int sum) {
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	vector<int>path;
//	path.push_back(root->val);
//	pathSumDfs(root, sum - root->val, res, path);
//	return res;
//}
//// 106 Construct Binary Tree from Inorder and Postorder Traversal
////@taobupt
//
//
//TreeNode* createTreeByInPo(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2)
//{
//	if (begin2 > end2)return NULL;
//	else if (begin2 == end2)return new TreeNode(postorder[begin2]);
//	TreeNode* root = new TreeNode(postorder[end2]);
//	int index = begin1;
//	while (begin1 < end1)
//	{
//		if (postorder[end2] == inorder[index])break;
//		index++;
//	}
//	root->left = createTreeByInPo(inorder, begin1, index - 1, postorder, begin2, index - 1 + begin2 - begin1);
//	root->right = createTreeByInPo(inorder, index + 1, end1, postorder, begin2 - begin1 + index, end2 - 1);
//	return root;
//}
//
//TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
//	int n = inorder.size();
//	return createTreeByInPo(inorder, 0, n - 1, postorder,0, n - 1);
//}
//
//
//
////117. Populating Next Right Pointers in Each Node II   O(N) space 
////@taobupt
//void connect1(TreeLinkNode *root) {
//	if (root == NULL)return;
//	queue<TreeLinkNode*>q;
//	q.push(root);
//	TreeLinkNode* node = NULL;
//	while (!q.empty())
//	{
//		int size = q.size();
//		while (size--)
//		{
//			node = q.front();
//			q.pop();
//			if (size > 0)node->next = q.front();  // have a bad status today, forget add two line below
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//	}
//}
//
//
//
////127 sum root to leaf number
////@taobupt
//
//
//void dfssumNumber(TreeNode* root, int& res, vector<int>& path)
//{
//	if (root->left == NULL && root->right == NULL)
//	{
//		int sum = 0;
//		for (int x : path)sum = 10 * sum + x;
//		res += sum;
//		return;
//	}
//	if (root->left)
//	{
//		path.push_back(root->left->val);
//		dfssumNumber(root->left, res, path);
//		path.pop_back();
//	}
//
//	if (root->right)
//	{
//		path.push_back(root->right->val);
//		dfssumNumber(root->right, res, path);
//		path.pop_back();
//	}
//}
//
//int sumNumbers(TreeNode* root) {
//	int res = 0;
//	vector<int>path;
//	if (root == NULL)return 0;
//	path.push_back(root->val);
//	dfssumNumber(root, res, path);
//	return res;
//}
//
////  leetcode 145 binary tree postorder 
////@taobupt
//
////-----  traversal-----
//
//void postorder(TreeNode* root,vector<int>& res)
//{
//	if (root == NULL)return;
//	postorder(root->left, res);
//	postorder(root->right, res);
//	res.push_back(root->val);
//
//}
//
//vector<int> postorderTraversal(TreeNode* root) {
//	vector<int>res;
//	postorder(root, res);
//	return res;
//}
//
//
//// --iterative
//
//vector<int> postorderTraversal1(TreeNode* root) {
//	vector<int>res;
//	stack<TreeNode*>stk;
//	if (root == NULL)return res;
//	stk.push(root);
//	TreeNode* pre = NULL;
//	TreeNode* node = NULL;
//	while (!stk.empty())
//	{
//		node = stk.top();
//		if (pre == NULL || pre->left == node || pre->right == node)
//		{
//			if (node->left)stk.push(node->left);
//			else if (node->right)stk.push(node->right);
//			else
//			{
//				stk.pop();
//				res.push_back(node->val);
//			}
//		}
//		else if (node->left == pre)
//		{
//			if (node->right)stk.push(node->right);
//			else
//			{
//				stk.pop();
//				res.push_back(node->val);
//			}
//		}
//		else if (node->right == pre)
//		{
//			stk.pop();
//			res.push_back(node->val);
//		}
//		pre = node;
//	}
//	return res;
//}
//
//
//
//// 199 199. Binary Tree Right Side View 
////@taobupt
//
//vector<int> rightSideView(TreeNode* root) {
//	vector<int>res;
//	queue<TreeNode*>q;
//	if (root == NULL)return res;
//	q.push(root);
//	TreeNode* node = NULL;
//	while (!q.empty())
//	{
//		int size = q.size();
//		while (size--)
//		{
//			node = q.front();
//			q.pop();
//			if (size == 0)res.push_back(node->val);
//			if (node->left)q.push(node->left);
//			if (node->right)q.push(node->right);
//		}
//	}
//	return res;
//
//}
//
//
//
////230 Kth Smallest Element in a BST
//// taobupt
//
//void inorderKth(TreeNode* root,  int k, int& res)
//{
//	if (root == NULL)return;
//	inorderKth(root->left, k, res);
//	k--;
//	if (k == 0)
//	{
//		res = root->val;
//		return;
//	}
//	inorderKth(root->right, k, res);
//}
//
//int kthSmallest(TreeNode* root, int k) {
//	int res = 0;
//	inorderKth(root,  k, res);
//	return res;
//}
//
//
//
//
//// 257 binary tree path
////@taobupt
//
//void dfsPath(vector<string>& res, string path, TreeNode* root)
//{
//	if (root->left == NULL && root->right == NULL)
//	{
//		res.push_back(path);
//		return;
//	}
//	if (root->left)
//	{
//		dfsPath(res, path + "->" + to_string(root->left->val), root->left);
//	}
//	if (root->right)
//	{
//		dfsPath(res, path + "->" + to_string(root->right->val), root->right);
//	}
//}
//vector<string> binaryTreePaths(TreeNode* root) {
//	vector<string>res;
//	string path;
//	if (root == NULL)return res;
//	path += to_string(root->val);
//	dfsPath(res, path, root);
//	return res;
//}
//
//
//
//// 337 house robbIII
////@taobupt
//
//
//vector<int>dfsRob(TreeNode* root)
//{
//	if (root == NULL)return {0,0};
//	vector<int>res(2, INT_MIN);// res[0] root res[1] none root;
//	vector<int>left = dfsRob(root->left);
//	vector<int>right = dfsRob(root->right);
//	res[0] =left[1]+right[1]+root->val;
//	res[1] = max(left[0], left[1]) + max(right[0], right[1]);
//	return res;
//}
//int rob(TreeNode* root) {
//	vector<int>res(2, 0);
//	res = dfsRob(root);
//	return max(res[0], res[1]);
//}
//
////404. Sum of Left Leaves
////@taobupt
//
//
//void dfsLeafLeaves(TreeNode* root, int &res)
//{
//	if (root == NULL || root->left == NULL && root->right == NULL)return;
//	if (root->left && root->left->left == NULL && root->left->right == NULL)
//	{
//		res += root->left->val;
//	}
//	if (root->left)
//	{
//		dfsLeafLeaves(root->left, res);
//	}
//	if (root->right)
//	{
//		dfsLeafLeaves(root->right, res);
//	}
//}
//int sumOfLeftLeaves(TreeNode* root) {
//	if (root == NULL || (root->left == NULL && root->right == NULL))return 0;
//	int res = 0;
//	dfsLeafLeaves(root, res);
//	return res;
//}
//
//
//
////leetcode 285 285. Inorder Successor in BST; doesnot have parnet information
////@taobupt
//
//TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//	if (p == NULL || root == NULL)return NULL;
//	TreeNode* successor = NULL;
//	if (p->right)
//	{
//		successor = p->right;
//		while (successor->left)successor = successor->left;
//		return successor;
//	}
//	else
//	{
//		TreeNode* node = root;
//		while (node)
//		{
//			if (node->val > p->val)
//			{
//				successor = node;
//				node = node->left;
//			}
//			else if (node->val < p->val)node = node->right;
//			else break;
//		}
//		return successor;
//	}
//}
////----- has parent information
////TreeNode* Successor(TreeNode* root, TreeNode* node)
////{
////	if (node->right != NULL)
////	{
////		node = node->right;
////		while (node->left)node = node->left;
////		return node;
////	}
////	else
////	{
////		TreeNode* p = node->parent;
////		while (p && p->right == node)
////		{
////			node = p;
////			p = p->parent;
////		}
////		return p;
////	}
////}
//
//
//// extend look for preorder
//
//TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p)
//{
//	if (root == NULL || p == NULL)return NULL; 
//	TreeNode* Predecessor = NULL;
//	if (p->left)
//	{
//		Predecessor = p->left;
//		while (Predecessor->right)Predecessor = Predecessor->right;
//		return Predecessor;
//	}
//	else
//	{
//		TreeNode* node = root;
//		while (node)
//		{
//			if (node->val < p->val)
//			{
//				Predecessor = node;
//				node = node->right;
//			}
//			else if (node->val > p->val)node = node->left;
//			else break;
//		}
//		return Predecessor;
//	}
//}
//
////has parent infromation
////----- has parent information
////TreeNode* Predecessor(TreeNode* root, TreeNode* node)
////{
////	if (node->left != NULL)
////	{
////		node = node->left;
////		while (node->right)node = node->right;
////		return node;
////	}
////	else
////	{
////		TreeNode* p = node->parent;
////		while (p && p->left == node)
////		{
////			node = p;
////			p = p->parent;
////		}
////		return p;
////	}
////}
//
//
/////-----------------------------
////leetcode 298 298. Binary Tree Longest Consecutive Sequence 
////@taobupt
//
//
//
//void dfsLongestConesecutive(TreeNode* root, int count, int value,int &maxsize)
//{
//	if (root == NULL)return;
//	if (root->val == value)count++;
//	else count = 1;
//	maxsize = max(maxsize, count);
//	dfsLongestConesecutive(root->left, count, root->val + 1,maxsize);
//	dfsLongestConesecutive(root->right, count, root->val + 1,maxsize);
//}
//
//int longestConsecutive(TreeNode* root) {
//	int count = 0,maxsize=0;
//	if (root == NULL)return maxsize;
//	dfsLongestConesecutive(root, count, root->val,maxsize);
//	return maxsize;
//}
//
//
//
////leetcode 255
////Verify Preorder Sequence in Binary Search Tree
////@taobupt
//bool verifyPreorder(vector<int>& preorder) {
//	int index = -1, minValue = INT_MIN;
//	for (int x : preorder)
//	{
//		if (x < minValue)return false;
//		while(index >= 0 && x <= preorder[index])
//		{
//			minValue = preorder[index--];
//		}
//		preorder[++index] = x;
//	}
//	return true;
//}
//
////extend verifyPostorder
//bool verifyPostorder(vector<int>& postorder) {
//	int index = -1, maxValue = INT_MAX;
//	reverse(postorder.begin(), postorder.end());
//	for (int x : postorder)
//	{
//		if (x > maxValue)return false;
//		while (index >= 0 && x <= postorder[index])
//		{
//			maxValue = postorder[index--];
//		}
//		postorder[++index] = x;
//	}
//	return true;
//}
//
//
//// leetcode 270 closest binary search tree value
////@taobupt
//
//int closestValue(TreeNode* root, double target) {
//	int res = root->val;
//	while (root)
//	{
//		res = fabs(root->val - target) > fabs(res - target) ? res : root->val;
//		if (root->val > target)root = root->left;
//		else if (root->val < target)root = root->right;
//		else return root->val;
//	}
//	return res;
//}
//
//
////leetcode 156 binary tree upsieddown
////@taobupt
//TreeNode* upsideDownBinaryTree(TreeNode* root) {
//	if (root == NULL || (root->left == NULL && root->right == NULL))return root;
//	TreeNode* res = upsideDownBinaryTree(root->left);
//	TreeNode* p = res;
//	while (p->right)p = p->right;
//	p->right = root;
//	p->left = root->right;
//	root->left = NULL;
//	root->right = NULL;
//	return res;
//}
//
//
//
/////333 largest BST substree
//struct info{
//	bool isBst;
//	int minValue, maxValue, size;
//	info() :minValue(INT_MAX), maxValue(INT_MIN), size(0), isBst(true){}
//};
//
//info* findLargest(TreeNode* root)
//{
//	if (root == NULL)return new info();
//	info* left = findLargest(root->left);
//	info* right = findLargest(root->right);
//	info* m = new info();
//	if (!left->isBst || !right->isBst || root->val >= right->minValue || root->val <= left->maxValue)
//	{
//		m->isBst = false;
//		m->size = max(left->size, right->size);
//		return m;
//	}
//	m->isBst = true;
//	m->size = left->size + right->size + 1;
//	m->minValue = root->left ? left->minValue : root->val;// rember that it is root->left not left?
//	m->maxValue = root->right ? right->maxValue : root->val;
//	return m;
//}
//
//int largestBSTSubtree(TreeNode* root) {
//	return findLargest(root)->size;
//}
//
//
//
///// 250 count unival substree;
//
//struct information{
//	bool isUnival;
//	int value;
//	information() :value(INT_MIN), isUnival(true){}
//};
//
//information* findUnivalSubstree(TreeNode* root, int& count)
//{
//	if (root == NULL)return NULL;
//	if (root->left == NULL && root->right == NULL)
//	{
//		information* m = new information();
//		m->isUnival = true;
//		m->value = root->val;
//		count += 1;
//		return m;
//	}
//	information* left = findUnivalSubstree(root->left, count);
//	information* right = findUnivalSubstree(root->right, count);
//	information* m = new information();
//	if ((left && !left->isUnival) || (right && !right->isUnival) || !(root->val == (left ? left->value : root->val) && root->val == (right ? right->value : root->val)))
//	{
//		m->isUnival = false;
//		return m;
//	}
//	m->isUnival = true;
//	count++;
//	m->value = root->val;
//	return m;
//}
//int countUnivalSubtrees(TreeNode* root) {
//	int count = 0;
//	findUnivalSubstree(root, count);
//	return count;
//}
//
//// -- second solution
//
//int countt = 0;
//bool dfs(TreeNode* root)
//{
//	if (root->left == NULL && root->right == NULL){ countt++; return true; }
//	bool a = true, b = true;
//	a = root->left ? dfs(root->left) : true;
//	b = root->right ? dfs(root->right) : true;
//	if (a&&b && (root->val == (root->left ? root->left->val : root->val) && root->val == (root->right ? root->right->val : root->val)))
//	{
//		countt++;
//		return true;
//	}
//	return false;
//}
//int countUnivalSubtrees1(TreeNode* root) {
//	if (root == NULL)return countt;
//	dfs(root);
//	return countt;
//}
//
//
////366 find leaves of binary tree
//void dfs366(TreeNode* &root, vector<int>& inner)
//{
//	if (root->left == NULL && root->right == NULL)
//	{
//		inner.push_back(root->val);
//		root = NULL;
//		return;
//	}
//	if (root->left)dfs366(root->left, inner);
//	if (root->right)dfs366(root->right, inner);
//}
//vector<vector<int>> findLeaves(TreeNode* root) {
//	vector<vector<int>>res;
//	if (root == NULL)return res;
//	vector<int>inner;
//	while (root)
//	{
//		inner.clear();
//		dfs366(root, inner);
//		res.push_back(inner);
//	}
//	return res;
//}
//
//
//// second soultioin
//int MaxHeight(TreeNode* root)
//{
//	if (root == NULL)return 0;
//	else return max(MaxHeight(root->left), MaxHeight(root->right)) + 1;
//}
//
//void dfsFindLeaves(TreeNode* root, vector<vector<int>> &res)
//{
//	if (root == NULL)return;
//	int level = max(MaxHeight(root->left), MaxHeight(root->right));
//	res[level].push_back(root->val);
//	dfsFindLeaves(root->left, res);
//	dfsFindLeaves(root->right, res);
//}
//
//vector<vector<int>> findLeaves1(TreeNode* root) {
//	int depth = MaxHeight(root);
//	vector<vector<int>>res(depth, vector<int>());
//	if (root == NULL)return res;
//	dfsFindLeaves(root, res);
//	return res;
//}
//
//
/////leetcode 272 Closest Binary Search Tree Value II 
////@taobupt
//
//void inorder(TreeNode* root, stack<int>& stk, bool reverse, double target)
//{
//	if (root == NULL)return;
//	reverse ? inorder(root->right, stk, reverse, target) : inorder(root->left, stk, reverse, target);
//	if (reverse && root->val <= target || !reverse && root->val>target)return;
//	stk.push(root->val);
//	reverse ? inorder(root->left, stk, reverse, target) : inorder(root->right, stk, reverse, target);
//}
//
//vector<int> closestKValues(TreeNode* root, double target, int k) {
//	vector<int>res;
//	stack<int>predecessor;
//	stack<int>succssor;
//	inorder(root, predecessor, false, target);
//	inorder(root, succssor, true, target);
//	while (k--)
//	{
//		if (predecessor.empty()){
//			res.push_back(succssor.top()); succssor.pop();
//		}
//		else if (succssor.empty())
//		{
//			res.push_back(predecessor.top()); predecessor.pop();
//		}
//		else if (fabs(target - predecessor.top()) > fabs(target - succssor.top()))
//		{
//			res.push_back(succssor.top());
//			succssor.pop();
//		}
//		else
//		{
//			res.push_back(predecessor.top());
//			predecessor.pop();
//		}
//	}
//	return res;
//}


























/// new problem

/// leetcode 438

vector<int> findAnagrams(string S, string p) {
	vector<int> ans;
	vector<string>L;
	for (char c : p)
	{
		string s(1, c);
		L.push_back(s);
	}
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














int thirdMax(vector<int>& nums) {
	int n = nums.size();
	if (n <= 0)return 0;
	if (n == 1)return nums[0];
	if (n == 2)return max(nums[0], nums[1]);
	sort(nums.begin(), nums.begin() + 3);
	int max3 = nums[0], max2 = nums[1], max1 = nums[2];
	for (int i = 3; i<n; ++i)
	{
		if (nums[i] == max1 || nums[i] == max3 || nums[i] == max2)continue;
		if (nums[i]>max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
		}
		else if (nums[i]>max2)
		{
			max3 = max2;
			max2 = nums[i];
		}
		else if (nums[i]>max3)
		{
			max3 = nums[i];
		}
	}
	if (max3 == max2 || max3 == max1 || max1 == max2)return max1;
	return max3;
}


//#include"DigitalImage.h"

//bool canCross(vector<int>& stones) {
//	
//}





//have been tested
//struct compare{
//	bool operator() (pair<vector<int>::iterator, vector<int>::iterator>pair1, pair<vector<int>::iterator, vector<int>::iterator>pair2)
//	{
//		return *pair1.first > *pair2.first;
//	}
//};
//int findKsmallest(vector<vector<int>>vec, int k)
//{
//	priority_queue <pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, compare>pq;
//	for (int i = 0; i < (int)vec.size(); ++i)if (!vec[i].empty())pq.push(make_pair(vec[i].begin(), vec[i].end()));
//	while (!pq.empty())
//	{
//		pair<vector<int>::iterator, vector<int>::iterator>it = pq.top();
//		pq.pop();
//		k--;
//		if (k == 0)return *it.first;
//		if (it.first + 1 != it.second)pq.push(make_pair(it.first + 1, it.second));
//	}
//	return 0;
//}







//#include"85MaximalRectangle.h"
//#include"127wordladder.h"
//#include"163MissingRanges.h"
#include"346MovingAverageFromDataStream.h"
#include"Prim.h"
//#include"bellman_ford.h"
//#include"Dijkstra.h"
//#include"Floyd.h"
//#include"MaxFlow.h"
int main()
{
	//LazyString a("asdf"); //allocate new storage
	//LazyString b(a);// shares storage with a
	//assert(a.get() == b.get()); //they have smae sotrage
	//b.copy_from("asdf"); //modifei b, allocate new storage
	//assert(a.get() != b.get());// they have different sotrage
	//solve();

	vector<string>v{ "1", "2", "3", "4", "5", "#", "#" };
	Codec c;
	TreeNode* node = c.deserialize(v);
	vector<vector<char>>matrix = { { '1','0','1','0','0' }, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' } };
	//maximalRectangle(matrix);
	//string beginword = "hit";
	//string endword = "cog";
	//unordered_set<string>wordLists{ "hot", "dot", "dog", "lot", "log" };
	//cout << ladderLength1(beginword, endword, wordLists);
	//vector < int > vv{ 2147483647 };
	//findMissingRanges(vv, 0, 2147483646 + 1);
	/*MovingAverage obj(4);
	cout<<obj.next(100)<<endl;
	cout<<obj.next(-10)<<endl;
	cout<<obj.next(-300)<<endl;
	cout << obj.next(50) << endl;;
	cout << obj.next(0) << endl;;*/
	//cout<<prim()<<endl;
	//E_K();
	freopen("input.txt", "r", stdin);
	prim();
	return 0;
}
