#include"Header.h"

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};
ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* p = head;
	ListNode* q = head->next;
	while (p && q)
	{
		if (p->val != q->val)
		{
			p->next = q;
			p = p->next;
			q = q->next;
		}
		else
		{
			q = q->next;
		}
	}
	p->next = NULL;
	return head;
}