#include"struct.h"
ListNode *detectCycle(ListNode *head) {
	if (head == NULL || head->next == NULL)return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)break;
	}
	if (fast != slow)return NULL;
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}