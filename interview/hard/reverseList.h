#include"Header.h"
struct Node
{
	int data;
	struct Node *next;
};
void ReversePrint(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 
	if (head == NULL || head->next == NULL)return;
	Node* prev = NULL;
	Node* cur = head;
	Node* after = head->next;
	while (after)
	{
		cur->next = prev;
		prev = cur;
		cur = after;
		after = after->next;
	}
	cur->next = prev;
	head = cur;
}


