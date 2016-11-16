#include"struct.h"

ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL)return head;
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* pre = first;
	ListNode* cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
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