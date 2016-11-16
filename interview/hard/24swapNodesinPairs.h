#include"Header.h"
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};

ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)return head;
	ListNode* save = head->next;
	head->next = swapPairs(head->next->next);
	save->next = head;
	return save;
}