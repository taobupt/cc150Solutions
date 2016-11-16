#include"struct.h"
ListNode* reverseList(ListNode* head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* after = head->next;
	while (after)
	{
		cur->next = prev;
		prev = cur;
		cur = after;
		after = cur->next;
	}
	cur->next = prev;
	return cur;
}
ListNode* join(ListNode* head1, ListNode* head2)
{
	if (head2 == NULL)return head1;
	head2->next = join(head1->next, head2->next);
	head1->next = head2;
	return head1;
}
void reorderList(ListNode* head) {
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