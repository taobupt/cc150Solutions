#include"struct.h"
#include"Header.h"

ListNode* addTwoNumber(ListNode* headA, ListNode* headB)
{
	if (headA == NULL)return headB;
	if (headB == NULL)return headA;
	ListNode* first = new ListNode(0);
	ListNode* p = first;
	int carry = 0;
	while (headA || headB || carry)
	{
		int sum = (headA ? headA->val : 0) + (headB ? headB->val : 0) + carry;
		p->next = new ListNode(sum % 10);
		carry = sum >= 10 ? 1 : 0;
		headA = headA ? headA->next : NULL;
		headB = headB ? headB->next : NULL;
		p = p->next;
	}
	return first->next;
}

//follow up

ListNode* reverseList(ListNode*head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode* pre = head;
	ListNode* cur = head->next;
	ListNode* after = cur->next;
	pre->next = NULL;
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

ListNode* addTwoNumber_order(ListNode* headA, ListNode* headB)
{
	if (headA == NULL)return headB;
	if (headB == NULL)return headA;
	return reverseList(addTwoNumber(reverseList(headA), reverseList(headB)));
}
