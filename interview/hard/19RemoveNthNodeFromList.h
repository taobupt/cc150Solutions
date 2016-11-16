#include"Header.h"
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* first = new ListNode(0);
	first->next = head;
	ListNode* p = first;
	ListNode* q = first;
	while (n--)p = p->next;
	while (p)
	{
		p = p->next;
		q = q->next;
	}
	q->next = q->next->next;
	return head;
}
