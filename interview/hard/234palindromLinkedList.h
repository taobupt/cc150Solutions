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
bool isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL)return true;
	ListNode* part1 = head;
	ListNode* part2 = head->next;
	while (part2 && part2->next)
	{
		part1 = part1->next;
		part2 = part2->next->next;
	}
	part2 = part1->next;
	part1->next = NULL;
	part1 = head;
	part2 = reverseList(part2);
	while (part2)
	{
		if (part1->val != part2->val)return false;
		part1 = part1->next;
		part2 = part2->next;
	}
	return true;
}