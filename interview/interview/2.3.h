#include"struct.h"
#include"Header.h"
void DeleteNode(ListNode* node)
{
	assert(node->next != NULL);
	swap(node->val, node->next->val);
	node->next = node->next->next;
}