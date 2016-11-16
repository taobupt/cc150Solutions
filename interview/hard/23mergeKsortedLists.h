#include"struct.h"

struct cmp{
	bool operator()(ListNode* node1, ListNode* node2)
	{
		return node1->val > node2->val;
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	priority_queue < ListNode*, vector<ListNode*>, cmp > pq;
	for (ListNode* it : lists)if(it)pq.push(it);//compare two null would cause wrong answer;
	ListNode* first = new ListNode(0);
	ListNode* node = first;
	while (!pq.empty())
	{
		node->next = pq.top();
		pq.pop();
		node = node->next;
		if (node && node->next)pq.push(node->next);
		
	}
	return first->next;
}

///

//struct cmp{
//	bool operator()(ListNode* node1, ListNode* node2)
//	{
//		return node1->val > node2->val;
//	}
//};
//ListNode* mergeKLists(vector<ListNode*>& lists)
//{
//	priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
//	for (ListNode* it : lists)if (it)pq.push(it);
//	ListNode* first = new ListNode(0);
//	ListNode* node = first;
//	while (!pq.empty())
//	{
//		node->next = pq.top();
//		pq.pop();
//		node = node->next;
//		if (node && node->next)pq.push(node->next);
//	}
//	return first->next;
//}




struct cmp{
	bool operator()(ListNode* a,ListNode* b)
	{
		return a->val > b->val;
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
	for (ListNode* node : lists)if(node)pq.push(node);
	ListNode* first = new ListNode(0);
	ListNode* node = first;
	while (!pq.empty())
	{
		node->next = pq.top();
		pq.pop();
		node = node->next;
		if (node&& node->next)pq.push(node->next);
	}
	return first->next;
}


// extend to the array


struct compare{
	bool operator() (pair<vector<int>::iterator, vector<int>::iterator>pair1, pair<vector<int>::iterator , vector<int>::iterator>pair2)
	{
		return *pair1.first > *pair2.first;
	}
};
int findKsmallest(vector<vector<int>>vec,int k)
{
	priority_queue <pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, compare>pq;
	for (int i = 0; i < vec.size(); ++i)if (!vec[i].empty())pq.push(make_pair(vec[i].begin(),vec[i].end()));
	while (!pq.empty())
	{
		pair<vector<int>::iterator, vector<int>::iterator>it = pq.top();
		pq.pop();
		k--;
		if (k == 0)return *it.first;
		if(it.first+1!=it.second)pq.push(make_pair(it.first+1,it.second));
	}
	return 0;
}


