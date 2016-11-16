#include"Header.h"


//must see the optimal solution
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){ }
};
ListNode* partition(ListNode* head, int x) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* small = new ListNode(0);
	ListNode* p = small;
	ListNode* greater = new ListNode(0);
	ListNode* k = greater;
	ListNode* q = head;
	while (q)
	{
		if (q->val < x)
		{
			p->next = new ListNode(q->val);
			p = p->next;
		}
		else
		{
			k->next = new ListNode(q->val);
			k = k->next;
		}
		q = q->next;
	}
	p->next = greater->next;
	return small->next;
}
