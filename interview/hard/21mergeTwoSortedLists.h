#include"Header.h"
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL || l2 == NULL)return l1 ? l1 : l2;
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			p->next = new ListNode(l1->val);
			l1 = l1->next;
		}
		else{
			p->next = new ListNode(l2->val);
			l2 = l2->next;
		}
		p = p->next;
	}
	p->next = l1 ? l1 : l2;
	return first->next;
}