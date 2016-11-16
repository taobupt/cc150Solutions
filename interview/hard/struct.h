#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), right(NULL), left(NULL){}
};

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};

struct DoubleListNode{
	int val;
	DoubleListNode* pre;
	DoubleListNode* next;
	DoubleListNode(int val) :val(val), next(NULL), pre(NULL){}
};