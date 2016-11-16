#include"Header.h"
struct Node
{
	int data;
	struct Node *next;
};

Node* MergeLists(Node *headA, Node* headB)
{
	if (headA == NULL || headB == NULL)return headA ? headA : headB;
	Node* first = new Node();
	Node* p = first;
	while (headA && headB)
	{
		if (headA->data<headB->data)
		{
			p->next = new Node();
			p->next->data = headA->data;
			headA = headA->next;
			p = p->next;
		}
		else
		{
			p->next = new Node();
			p->next->data = headB->data;
			headB = headB->next;
			p = p->next;
		}
	}
	p->next = headA ? headA : headB;
	return first->next;
	// This is a "method-only" submission. 
	// You only need to complete this method 
}

void printNode(Node* head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}