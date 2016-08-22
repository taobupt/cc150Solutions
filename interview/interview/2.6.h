#include"Header.h"
#include"struct.h"
ListNode *detectCycle(ListNode *head) {
	if (head == NULL||head->next==NULL)return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)break;
	}
	if (slow != fast)return;
	while (head != slow)
	{
		slow = slow->next;
		head = head->next;
	}
	return slow;
}