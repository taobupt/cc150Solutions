#include"Header.h"
#include"struct.h"
ListNode* removeDuplicate(ListNode* head)
{
	if (head == NULL || head->next == NULL)return head;
	unordered_map < int, bool >mp ;
	mp[head->val] = true;
	ListNode* prev = head;
	ListNode* cur = head->next;
	while (cur)
	{
		if (mp[cur->val]){
			prev->next = cur->next;
			cur = cur->next;
		}
		else
		{
			mp[cur->val] = true;
			prev = prev->next;
			cur = cur->next;

		}
	}
	return head;

}