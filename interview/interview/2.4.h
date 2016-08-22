#include"struct.h"
#include"Header.h"

ListNode* partitionNode(ListNode* head,int val)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	ListNode* second = new ListNode(0);
	ListNode* q = second;
	while (head)
	{
		if (head->val < val)
		{
			p->next = new ListNode(head->val);
			p = p->next;
		}
		else
		{
			q->next = new ListNode(head->val);
			q = q->next;
		}
		head = head->next;
	}
	p->next = second->next;
	return first->next;
}