#include"struct.h"

//ListNode* reverseList(ListNode* head)
//{
//	if (head == NULL || head->next == NULL)return head;
//	ListNode* prev = NULL;
//	ListNode* cur = head;
//	ListNode* after = head->next;
//	while (after)
//	{
//		cur->next = prev;
//		prev = cur;
//		cur = after;
//		after = after->next;
//	}
//	cur->next = prev;
//	return cur;
//}


//reverselist

//have been tested
ListNode* reverseList(ListNode* head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* after = head->next;
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


DoubleListNode* reverseDoubleList(DoubleListNode* head)
{
	if (head == NULL || head->next == NULL)return NULL;
	DoubleListNode* prev = NULL;
	DoubleListNode* cur = head;
	DoubleListNode* after = head->next;
	while (after)
	{
		cur->next = prev;
		if(prev)prev->pre = cur;
		prev = cur;
		cur = after;
		after = after->next;
	}
	cur->next = prev;
	prev->pre = cur;
	cur->pre = NULL;
	return cur;
}

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
ListNode* reverseKGroup(ListNode* head, int k) {
	if (head == NULL || head->next == NULL || k <= 1)return head; // notice
	ListNode* p = head;
	int n = k - 1;
	while (n>0)  //notice
	{
		p = p->next;
		if (p == NULL)break;
		n--;
	}
	if (n>0)return head;//notice if(n) is not serious, pay attention to this
	ListNode* q = p->next;
	p->next = NULL;
	head = reverseList(head);
	p = head;
	while (p->next)p = p->next;
	p->next = reverseKGroup(q, k);
	return head;
}