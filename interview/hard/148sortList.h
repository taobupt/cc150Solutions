#include"struct.h"


ListNode* merge(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL || head2 == NULL)return head1 ? head1 : head2;
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	while (head1 && head2)
	{
		if (head1->val < head2->val)
		{
			p->next = new ListNode(head1->val);
			p = p->next;
			head1 = head1->next;
		}
		else
		{
			p->next = new ListNode(head2->val);
			p = p->next;
			head2 = head2->next;
		}
	}
	p->next = head1 ? head1 : head2;
	return first->next;
}

ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* p = head;
	ListNode* q = head->next;
	while (q && q->next)
	{
		q = q->next->next;
		p = p->next;
	}
	q = p->next;
	p->next = NULL;
	return merge(sortList(head), sortList(q));
}