#include"Header.h"

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};
bool hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL)return false;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)break;
	}
	return slow == fast;

}