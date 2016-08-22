#include"struct.h"
#include"Header.h"
bool isPalindrome(ListNode* head)
{
	if (head == NULL || head->next == NULL)return true;
	vector<int>v;
	while (head)
	{
		v.push_back(head->val);
		head = head->next;
	}
	int n = v.size();
	for (int i = 0; i<n/2;++i)
	{ 
		if (v[i] != v[n - 1 - i])return false;
	}
	return true;
}