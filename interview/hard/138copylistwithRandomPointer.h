#include"Header.h"

struct RandomListNode{
	int label;
	RandomListNode* next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL){}
};

unordered_map<RandomListNode*, RandomListNode*>mp;

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)return head;
	if (mp.find(head) == mp.end())
	{
		mp[head] = new RandomListNode(head->label);
		mp[head]->next = copyRandomList(head->next);
		mp[head]->random = copyRandomList(head->random);
	}
	return mp[head];
}




unordered_map<RandomListNode*, RandomListNode*>mp;
RandomListNode* copyRandomList(RandomListNode* head)
{
	if (head == NULL)return head;
	if (mp.find(head) == mp.end())
	{
		mp[head] = new RandomListNode(head->label);
		mp[head]->next = copyRandomList(head->next);
		mp[head]->random = copyRandomList(head->random);
	}
	else return mp[head];
}


RandomListNode *copyRandomList1(RandomListNode *head)
{

	unordered_map<RandomListNode*, RandomListNode*>mp;
	RandomListNode* save_head = head;
	while (head)
	{
		RandomListNode* node = new RandomListNode(head->label);
		mp[head] = node;
		head = head->next;
	}
	head = save_head;
	RandomListNode* newHead = NULL, *newTail = NULL;
	while (head)
	{
		RandomListNode* cur = mp[head];
		cur->next = mp[head->next];
		cur->random = mp[head->random];
		if (newHead == NULL)
		{
			newHead = cur;
			newTail = cur;
		}
		else
		{
			newTail->next = cur;
			newTail = newTail->next;
		}
		
		head = head->next;
	}
	return newHead;
}