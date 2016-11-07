//#include"Header.h"
using namespace std;
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<queue>
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

//102 linkedlistCycle
//@taobupt
//Given a linked list, determine if it has a cycle in it.
bool hasCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL)return false;
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)break;
	}
	return fast == slow;	
}


//lt 142 linked list CcyleII
//@taobupt


//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.

//Note: Do not modify the linked list.

	  //Follow up :
//Can you solve it without using extra space ?

ListNode *detectCycle(ListNode *head) {
	if (head == NULL || head->next == NULL)return NULL;
	ListNode* fast = head;// if this is head->next, then it will cause error
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)break;
	}
	if (slow != fast)return NULL;
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;

}



//19 remove  Nth Node from end of list
//@taobuot

/*Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list : 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note :
	 Given n will always be valid.
	 Try to do this in one pass.
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL || n == 0)return head;
	ListNode* p = head;
	while (p && n)
	{
		n--;
		p = p->next;
	}
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* q = first;
	while (p&&q)
	{
		p = p->next;
		q = q->next;
	}
	q->next = q->next->next;
	return first->next;
}

//lt 21 merge two sorted lists
// @taobupt
//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL || l2 == NULL)return l1 ? l1 : l2;
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	p->next = l1 ? l1 : l2;
	return first->next;
}

ListNode* mergeTwoListsRecrusive(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL || l2 == NULL)return l1 ? l1 : l2;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoListsRecrusive(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoListsRecrusive(l1, l2->next);
		return l2;
	}
}

//lt 160 intersection of TwoLinkedList
//@taobupt

/*Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists :

A :     a1 → a2
	          ↘
	           c1 → c2 → c3
	          ↗
B : b1 → b2 → b3
	begin to intersect at node c1.


Notes :

	  If the two linked lists have no intersection at all, return null.
	  The linked lists must retain their original structure after the function returns.
	  You may assume there are no cycles anywhere in the entire linked structure.
	  Your code should preferably run in O(n) time and use only O(1) memory.
	  */

//idea get the two lenghts of two list respectively, and then move the difference
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL)return NULL;
	int la = 0, lb = 0;
	ListNode* pa = headA;
	ListNode* pb = headB;
	while (pa){ la++; pa = pa->next; }
	while (pb){ lb++; pb = pb->next; }
	pa = headA; pb = headB;
	int diff = abs(la - lb);
	if (la > lb)while (diff--)pa = pa->next;
	else while (diff--)pb = pb->next;
	while (pa && pb)
	{
		if (pa == pb)return pa;
		pa = pa->next;
		pb = pb->next;
	}
	return NULL;

}

// optimal solution
ListNode *getIntersectionNodeBetter(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL)return NULL;
	ListNode* a = headA;
	ListNode* b = headB;
	while (a != b)
	{
		a = a == NULL ? headB : a->next;
		b = b == NULL ? headA : b->next;
	}
	return a;
}



//lt 83 remove Duplicates from sorted list
//@taobupt

/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* p = head;
	while (p->next)
	{
		if (p->next->val == p->val)p->next = p->next->next;
		else p = p->next;
	}
	return head;
}

ListNode* recrusiveDeleteDuplicates(ListNode* head)
{
	if (head == NULL || head->next == NULL)return head;
	head->next = recrusiveDeleteDuplicates(head->next);
	return head->val == head->next->val ? head->next : head;
}

//lt82
ListNode* deleteDuplicatesII(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* cur = head;
	if (cur->val == cur->next->val)
	{
		while (cur && cur->next && cur->val == cur->next->val)cur = cur->next;
		return deleteDuplicatesII(cur->next);
	}
	else
	{
		head->next = deleteDuplicatesII(head->next);
		return head;
	}

}

ListNode* deleteDuplicatesII1(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* pre = first;
	ListNode* cur = head;
	while (cur && cur->next)
	{
		if (cur->val == cur->next->val)
		{
			while (cur->next && cur->val == cur->next->val)cur = cur->next;
			pre->next = cur->next;
			cur = cur->next;
		}
		else
		{
			pre = pre->next;
			cur = cur->next;
		}
	}
	return first->next;
}

// lt 203 remove linked list elements
//@taobupt

/*Remove all elements from a linked list of integers that have value val.

Example
Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/
ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL)return NULL;
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* p = first;
	while (head)
	{
		if (head->val == val)
		{
			p->next = head->next;
		}
		else
		{
			p = p->next;
		}
		head = head->next;
	}
	return first->next;
}

ListNode* removeElementsRecrusive(ListNode* head, int val) {
	if (head == NULL)return NULL;
	head->next = removeElementsRecrusive(head->next, val);
	return head->val == val ? head->next : head;
}

//lt 206 reverse linked list
// @taobupt
// Reverse a singly linked list. A linked list can be reversed either iteratively or recursively. Could you implement both?
ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next==NULL)return head;
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* after = head->next;
	while (after)
	{
		cur->next = pre;
		pre = cur;
		cur = after;
		after = after->next;
	}
	cur->next = pre;
	return cur;
}

//something like 156
ListNode* reverseListRecrusive(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* node = reverseListRecrusive(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}


// lt 234 palindrome linked list
//@taobupt
/*Given a singly linked list, determine if it is a palindrome.

Follow up :
Could you do it in O(n) time and O(1) space ?*/
 
bool isPalindrome(ListNode* head)
{
	// naive solution
	/*vector<int>nums;
	while (head){ nums.push_back(head->val); head = head->next; }
	int n = nums.size();
	for (int i = 0; i < n / 2; ++i)
	{
		if (nums[0] != nums[n - 1 - i])return false;
	}
	return true;*/

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

//237 delete node in a linked list
//@taobupt 

/*Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.*/

void deleteNode(ListNode* node) {
	swap(node->val, node->next->val);
	node->next = node->next->next;
}

// lt 24 swap nodes in Pairs
//@taobupt

/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.
*/
ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode *node = head->next;
	head->next = swapPairs(node->next);
	node->next = head;
	return node;
}




// 按部就班的来，不必急于求成。 先搞定前两个就够了，然后再沿着这条绳子搞下去。 首先先解决 1->2->3->4 先搞成 2-1-3,然后一步一步推进
ListNode* swapPairsIterative(ListNode* head)
{

	/*if (head == NULL || head->next == NULL)return head;
	ListNode* tmp = new ListNode(0);
	ListNode* first = new ListNode(0);
	first->next = head->next;
	ListNode* p = head;
	ListNode* q = head->next;
	while (p &&q->next)
	{
		tmp = p;
		p->next = q->next->next;
		if (p->next == NULL)break;
		p = q->next;
		q->next = tmp;
		q = q->next->next;
	}
	p->next = q->next;
	q->next = p;
	return first->next;*/

	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* cur = dummy;
	while (cur->next && cur->next->next)
	{
		ListNode* first = cur->next;
		ListNode* second = cur->next->next;
		first->next = second->next;
		cur->next = second;
		cur->next->next = first;
		cur = cur->next->next;
	}
	return dummy->next;
}


//lt 138 copy list with Random pointer
//@taobupt

//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

//Return a deep copy of the list.

unordered_map<RandomListNode*, RandomListNode*>mp;
RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)return NULL;
	if (mp.find(head) == mp.end())
	{
		mp[head] = new RandomListNode(head->label);
		mp[head]->next = copyRandomList(head->next);
		mp[head]->random = copyRandomList(head->random);
	}
	return mp[head];
}

unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>has;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if (node == NULL)return nullptr;
	if (has.find(node) == has.end())
	{
		has[node] = new UndirectedGraphNode(node->label);
		for (auto n : node->neighbors)
		{
			has[node]->neighbors.push_back(cloneGraph(n));
		}
	}
	return has[node];
}

// iterative way
RandomListNode* copyRandomListIterative(RandomListNode * head)
{
	if (head == NULL)return NULL;
	unordered_map<RandomListNode*, RandomListNode*>mp;
	RandomListNode* save_head = head;
	RandomListNode* new_head = NULL;
	RandomListNode* new_tail = NULL;
	while (head)
	{
		mp[head]= new RandomListNode(head->label);
		head = head->next;
	}
	head = save_head;
	while (head)
	{
		RandomListNode* cur = mp[head];
		cur->next = mp[head->next];
		cur->random = mp[head->random];
		if (new_head = NULL)
		{
			new_head = cur;
			new_tail = cur;
		}else
		{
			new_tail->next = cur;
			new_tail = new_tail->next;
		}
		head = head->next;
	}
	return new_head;
}

//23 merge k sorted lists
//@ taobupt
//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.


struct cmp{
	bool operator()(ListNode* a, ListNode* b)
	{
		return a->val > b->val;
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	//naive solution, store all elements to vector,sort and build new lists;
	priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
	for (ListNode* list : lists)if (list)pq.push(list);
	ListNode* first = new ListNode(0);
	ListNode* node = first;
	while (!pq.empty())
	{
		node->next = pq.top();
		pq.pop();
		node = node->next;
		if (node && node->next)pq.push(node->next);
	}
	return first->next;
}



//25 reverse nodes in K-Group
//@taobupt
/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list : 1->2->3->4->5

For k = 2, you should return : 2->1->4->3->5

For k = 3, you should return : 3->2->1->4->5*/

ListNode* reverseKGroup(ListNode* head, int k) {
	/*if (head == NULL || head->next == NULL || k <= 1)return head;
	int i = 0;
	ListNode* p = head;
	while (i < k-1 && p)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)return head;
	ListNode* q = p->next;
	p->next = NULL;
	head=reverseList(head);
	p = head;
	while (p->next)p = p->next;
	p->next = reverseKGroup(q, k);
	return head;*/

	if (head == NULL || head->next == NULL || k <= 1)return head;
	int i = 0;
	ListNode* p = head;
	while (i <k&& p)
	{
		i++;
		p = p->next;
	}
	if (i!=k)return head;
	p = reverseKGroup(p, k);
	int count = k;
	while (count--)
	{
		ListNode* tmp = head->next;
		head->next = p;
		p = head;
		head = tmp;
	}
	head =p;// the last should be NULL,so head should equal to the last one.
	return head;
}


//lt 2
//@taobupt

/*You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
   Output : 7 -> 0 -> 8
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL || l2 == NULL)return l1 ? l1 : l2;
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	int extra = 0, sum1 = 0;
	while (l1 || l2 || extra)
	{
		sum1 = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
		p->next = new ListNode(sum1 % 10);
		extra = sum1 >= 10 ? 1 : 0;
		p = p->next;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	return first->next;
}


//lt 445 add two number II
//@taobupt
/*You are given two linked lists representing two non - negative numbers.The most significant digit comes first and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up :
What if you cannot modify the input lists ? In other words, reversing the lists is not allowed.

Example :

	Input : (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
		Output : 7 -> 8 -> 0 -> 7
*/

ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) {
	if (l1 == NULL || l2 == NULL)return l1 ? l1 : l2;
	l1 = reverseList(l1);
	l2 = reverseList(l2);
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	int extra = 0;
	while (l1 || l2 || extra)
	{
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
		p->next = new ListNode(sum % 10);
		extra = sum / 10;
		p = p->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return reverseList(first->next);
}


//148 merge sort list
//Sort a linked list in O(n log n) time using constant space complexity.

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

	fast = slow->next;// forget this
	slow->next = NULL;
	return mergeList(sortList(head), sortList(fast));
}


//143 reorder list
//@taobupt
// 

//Given a singly linked list L : L0→L1→…→Ln - 1→Ln,
//reorder it to : L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1, 2, 3, 4 }, reorder it to{ 1, 4, 2, 3 }.

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



ListNode* join(ListNode* head1, ListNode* head2)
{
	if (head2 == NULL)return head1;
	head2->next = join(head1->next, head2->next);
	head1->next = head2;
	return head1;
}
void reorderListRecrusive(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL)return;
	ListNode* p = head;
	ListNode* q = head->next;
	while (q && q->next)
	{
		q = q->next->next;
		p = p->next;
	}
	q = p->next;
	p->next = NULL;
	q = reverseList(q);
	head = join(head, q);
}


// insertion sort list
//@taobupt


//Sort a linked list using insertion sort.
ListNode* insertionSortList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* first = new ListNode(INT_MIN);
	ListNode* p = NULL;
	while (head)
	{
		p = first;
		while (p)
		{
			if (p->next == NULL)
			{
				p->next = new ListNode(head->val);
				break;
			}
			if (head->val >= p->val && head->val < p->next->val)
			{
				ListNode* newNode = new ListNode(head->val);
				newNode->next = p->next;
				p->next = newNode;
				break;
			}
			p = p->next;
		}
		head = head->next;
	}
	return first->next;
}

// better solution
ListNode* insertionSortListbetter(ListNode* head)
{
	ListNode* new_head = new ListNode(0);
	new_head->next = head;
	ListNode* pre = new_head;
	ListNode* cur = head;
	while (cur)
	{
		if (cur->next && cur->next->val < cur->val)
		{
			while (pre->next && pre->next->val < cur->next->val)pre = pre->next;
			//insert
			ListNode*tmp = pre->next;
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = tmp;
			pre = new_head;
		}
		else cur = cur->next;
	}
	ListNode* res = new_head->next;
	delete new_head;
	return res;
}


//328 odd even linked list
//@taobupt


//Given a singly linked list, group all odd nodes together followed by the even nodes.Please note here we are talking about the node number and not the value in the nodes.

//You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.
ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL)return head;
	ListNode* q = head;
	ListNode* save = head->next;
	ListNode* p = head->next;
	while (p && p->next)
	{
		q->next = q->next->next;
		p->next = p->next->next;
		q = q->next;
		p = p->next;
	}
	q->next = save;
	return head;
}

//109 convert sorted list to binary search tree
// @taobupt


// use vector, sometimes you are not allowed to use extra space

TreeNode* makeTree(vector<int>& nums, int begin, int end)
{
	if (begin > end)return NULL;
	else if (begin == end)return new TreeNode(nums[begin]);
	else
	{
		int mid = begin + (end - begin) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = makeTree(nums, begin, mid - 1);
		root->right = makeTree(nums, mid + 1, end);
		return root;
	}
}

TreeNode* sortedListToBST(ListNode* head) {
	ListNode* p = head;
	vector<int>res;
	while (p)
	{
		res.push_back(p->val);
		p = p->next;
	}
	int n = res.size();
	return makeTree(res, 0, n - 1);
}

TreeNode* makeTreebyNode(ListNode* head, ListNode* tail)
{
	if (head == tail)return NULL;
	ListNode* fast = head->next;// head or head->next are ok, they are just different structures of BS trees
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
TreeNode* sortedListToBSTWithoutExtraSpace(ListNode* head) {
	if (head == NULL)return NULL;
	return makeTreebyNode(head, NULL);
}



// 86 partition list
//@taobupt


//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

//You should preserve the original relative order of the nodes in each of the two partitions.

//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.
ListNode* partition(ListNode* head, int x) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* small = new ListNode(0);
	ListNode* p = small;
	ListNode* greater = new ListNode(0);
	ListNode* k = greater;
	ListNode* q = head;
	while (q)
	{
		if (q->val < x)
		{
			p->next =q;// there is no need to new a list node, waste resource
			p = p->next;
		}
		else
		{
			k->next = q;
			k = k->next;
		}
		q = q->next;
	}
	k->next = NULL;// important, otherwise you will get LTE
	p->next = greater->next;
	return small->next;
}


//92 reverseListII
//@taobupt

//Reverse a linked list from position m to n.Do it in - place and in one - pass.

//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,

//return 1->4->3->2->5->NULL.

struct TwoNode{
	ListNode* head;
	ListNode* tail;
	TwoNode() :tail(NULL), head(NULL){}
};

TwoNode* reverseListTwoNode(ListNode* head)
{
	TwoNode* two = new TwoNode();
	if (head == NULL || head->next == NULL)
	{
		two->head=head;
		two->tail = head;
		return two;
	}
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* after = head->next;
	while (after)
	{
		cur->next = pre;
		pre = cur;
		cur = after;
		after = after->next;
	}
	cur->next = pre;
	two->tail = head;
	two->head= cur;
	return two;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	ListNode* q = head;
	first->next = head;
	while (m > 1){ p = p->next; m--;}
	while (n > 1){ q = q->next; n--;}
	ListNode* save_tail = q->next;
	q->next = NULL;
	TwoNode* two=reverseListTwoNode(p->next);
	p->next = two->head;
	two->tail->next = save_tail;
	return first->next;
}



// lt 61 rotate list

//@taobupt
//Given a list, rotate the list to the right by k places, where k is non - negative.

//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

// link the list into a cycle
ListNode* rotateRight(ListNode* head, int k) {
	int le = 0;
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* p = head;
	ListNode* save_tail = NULL;
	while (p){ le++; p = p->next; if (p)save_tail = p; }
	save_tail->next = head;
	k = le - k%le;
	if (k == le)return head;// this is a bug here, if you forget this ,you will have a bug, but you can link it into a cycle first;
	p = first;
	while (k--){ p = p->next; }
	ListNode* save_right = p->next;
	p->next = NULL;
	return save_right;

}

/// lt 83
//@taobupt
//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
ListNode* deleteDuplicatesII(ListNode* head) {
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* pre = first;
	ListNode* cur = head;
	while (cur&&cur->next)// cur and cur->next must be seen in the same time ,otherwise it will call bugs
	{
		if (cur->val == cur->next->val)
		{
			while (cur->next && cur->val == cur->next->val)cur = cur->next;
			pre->next = cur->next;
			cur = cur->next;
		}
		else
		{
			pre = pre->next;
			cur = cur->next;
		}
	}
	return first->next;
}

ListNode* deleteDuplicatesRecrusive(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* cur = head;
	if (cur->val == cur->next->val)
	{
		while (cur && cur->next && cur->val == cur->next->val)cur = cur->next;
		return deleteDuplicatesRecrusive(cur->next);
	}
	else
	{
		head->next = deleteDuplicatesRecrusive(head->next);
		return head;
	}

}

// lt 369 plus one linked list
//@taobupt

/*Given a non - negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input :
	1->2->3

Output :
	   1->2->4
*/

// or you can use the reverselist
ListNode* plusOne(ListNode* head) {
	stack<ListNode*>stk;
	ListNode* p = head;
	while (p)
	{
		stk.push(p);
		p = p->next;
	}
	while (!stk.empty())
	{
		if (stk.top()->val == 9)stk.top()->val = 0;
		else
		{
			stk.top()->val += 1;
			return head;
		}
		stk.pop();
	}
	ListNode* first = new ListNode(1);
	first->next = head;
	return first;

}

ListNode* plusOneWithoutExtraSpace(ListNode* head)
{
	head = reverseList(head);
	ListNode* p = head;
	while (p)
	{
		if (p->val == 9)p->val = 0;
		else{
			p->val += 1;
			return reverseList(head);
		}
		p = p->next;
	}
	head = reverseList(head);
	ListNode* first = new ListNode(1);
	first->next = head;
	return first;
}

// better version; the idea is to find the last not 9 

ListNode* plusOneBetter(ListNode* head)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* lastNodenine = dummy;
	ListNode* node = head;
	while (node)
	{
		if (node->val != 9)lastNodenine = node;
		node = node->next;
	}
	lastNodenine->val++;
	node = lastNodenine->next;
	while (node)
	{
		node->val = 0;
		node = node->next;
	}
	return dummy->val == 1 ? dummy : head;
}

// recrusive


int getCarry(ListNode* head)
{
	if (head == NULL)return 1;
	int carry = getCarry(head->next);
	if (carry == 0)return 0;
	int val = head->val + 1;
	head->val = val % 10;
	return val / 10;
}
ListNode* plusOneRecrusive(ListNode* head)
{
	if (getCarry(head) == 0)return head;
	else
	{
		ListNode* dummy = new ListNode(1);
		dummy->next = head;
		return dummy;
	}
}