#include"struct.h"
#include"Header.h"

vector<int> KtoLast(ListNode* head,int k)
{
	vector<int>v;
	while (head)
	{
		v.push_back(head->val);
		head = head->next;
	}
	assert(k < int(v.size()));
	vector<int>ans(v.begin() + k-1, v.end());
	return ans;
}