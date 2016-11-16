#include"struct.h"

ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* after = after;
	while (after)
	{
		cur->next = pre;
		pre = cur;
		cur = after;
		after = cur->next;
	}
	cur->next = pre;
	return cur;
}