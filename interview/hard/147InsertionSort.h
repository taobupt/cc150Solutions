#include"struct.h"
ListNode* insertionSortList(ListNode* head) {
	ListNode* first = new ListNode(INT_MIN);
	if (head == NULL || head->next == NULL)return head;
	ListNode* node = NULL;
	while (head)
	{
		node = first;
		while (node && node->next)
		{
			if (node->val <= head->val && node->next->val > head->val)break;
			node = node->next;
		}
		ListNode* newNode=new ListNode(head->val);
		newNode->next = node->next;
		node->next = newNode;
		head = head->next;
	}
	return first->next;
}