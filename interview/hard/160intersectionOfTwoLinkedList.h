#include"Header.h"

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL)return NULL;
	ListNode* p = headA;
	ListNode* q = headB;
	int lengthA = 0, lengthB = 0;
	while (p || q)
	{
		if (p)
		{
			lengthA++;
			p = p->next;
		}
		if (q)
		{
			lengthB++;
			q = q->next;
		}
	}
	p = headA; q = headB;
	int diff = abs(lengthA - lengthB);
	if (lengthA > lengthB)
	{
		while (diff--)p = p->next;
		while (p&&q)
		{
			if (p == q)break;
			p = p->next;
			q = q->next;
		}
		return p;
	}
	else
	{
		while (diff--)q = q->next;
		while (p&&q)
		{
			if (p == q)break;
			p = p->next;
			q = q->next;
		}
		return p;
	}
}
