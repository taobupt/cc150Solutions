//#include"Header.h"
//#include"1.1.h"
//#include"1.2.h"
//#include"1.7.h"
//#include"1.6.h"
//#include"1.4.h"
//#include"1.5.h"
//#include"ArrayReduction.h"
//#include"RoyalName.h"
//#include"2.1.h"
//#include"2.2.h"
//#include"2.3.h"
//#include"2.6.h"
//#include"2.7.h"
//#include"2.4.h"
//#include"2.5.h"

//#include"3.5.h"
//#include"3.2.h"
//#include"3.1.h"
//#include"3.3.h"
//#include"3.6.h
//#include"3.7.h"
//#include"3.4.h"

//#include"4.1.h"
//#include"4.2.h"
//#include"4.3.h"
//#include"4.4.h"
//#include"4.5.h"
//#include"4.6.h"
//#include"4.7.h"
//#inlcude"4.8.h"
//#include"4.9.h"

//#include"5.4.h"
//#include"5.1.h"
//#include"5.3.h"
//#include"5.5.h"


//#include"7.7.h"


//#include"9.4.h"
//#include"9.5.h"
//#include"9.6.h"
//#include"9.1.h"
//#include"9.3.h"
//#include"9.8.h"
//#include"9.7.h"
//#include"9.11.h"

//#include"17.4.h"
//#include"17.1.h"
//#include"17.7.h"

//#include"17.8.h"



//#include"13.1.h"
//template<typename T>
//void traverse_vector(vector<T>& v)
//{
//	for (vector<T>::iterator it = v.begin(); it != v.end(); ++it)
//	{
//		
//		printf("%d ", *it);
//	}
//	printf("\n");
//}
//
//template<typename T>
//void traverse_stack(stack<T>& s)
//{
//	while (!s.empty())
//	{
//		printf("%d ", s.top());
//		s.pop();
//	}
//	printf("\n");
//}
//
//int getLength(ListNode* head)
//{
//	if (head == NULL)return 0;
//	else return getLength(head->next) + 1;
//}
//
//
//ListNode* swapNodes(ListNode* head, int x, int y)
//{
//	ListNode* first = new ListNode(0);
//	first->next = head;
//	ListNode *pre = first;
//	ListNode* cur = head;
//	ListNode* save_x = NULL;
//	ListNode* save_xx = NULL;
//	while (cur)
//	{
//		if (cur->val == x)
//		{
//			save_x = pre;
//			save_xx = cur;
//		}
//		if (cur->val == y)
//		{
//			pre->next = cur->next;
//			cur->next = save_x->next->next;
//			save_x->next = cur;
//			save_xx->next = pre->next;
//			pre->next = save_xx;
//			break;
//		}
//		cur = cur->next;
//		pre = pre->next;
//	}
//	return first->next;
//}


//ListNode* reverseList(ListNode* head)
//{
//	if (head == NULL || head->next == NULL)return head;
//	ListNode* pre = NULL;
//	ListNode* cur = head;
//	ListNode* after = head->next;
//	while (after)
//	{
//		cur->next = pre;
//		pre = cur;
//		cur = after;
//		after = cur->next;
//	}
//	cur->next = pre;
//	return cur;
//
//}

//#include"205isomorphicString.h"
//#include"46permutations.h"
//#include"236LCAofBinaryTree.h"
//#include"238ProductOfArrayExceptArray.h"
//#include"187RepeatedDNASequence.h"
//#include"findKsmall.h"
//bool canJump(vector<int>A, int n) {
//	int i = 0;
//	for (int reach = 0; i < n && i <= reach; ++i)
//		reach = max(i + A[i], reach);
//	return i > n;
//}
//#include"254FactorsCombinations.h"
//#include"311SparseMatrixMul.h"
//#include"244.h"
//#include"450DeleteNodeInBst.h"

//#include"findKsmall.h"
//#include"253meetingRoomsII.h"
//#include"geekforgeeks.h"
//#include"LinkedList.h"
#include<sstream>
#include<iostream>
#include<fstream>
using namespace std;
#include"Header.h"
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val):val(val), right(NULL), left(NULL){}
};

bool inorderBST(TreeNode* root, TreeNode*& pre)
{
	if (root == NULL)return true;
	if (!inorderBST(root->left, pre))return false;
	if (pre && pre->val >= root->val)return false;
	pre = root;
	return inorderBST(root->right, pre);
}
bool isValidBST1(TreeNode* root) {
	// the naive way is to store all of the number into vector,and check whether the 
	//vector is ordered;
	TreeNode* pre = NULL;
	return inorderBST(root, pre);
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>res;
	unordered_map<string, int>mp;
	string sub;
	vector<string>inner;
	for (string s : strs)
	{
		sub = s;
		sort(sub.begin(), sub.end());
		if (mp.find(sub) == mp.end())
		{
			inner.clear();
			inner.push_back(s);
			mp[sub] = res.size();
			res.push_back(inner);
		}
		else res[mp[sub]].push_back(s);
	}
	return res;
}

int main()
{
	//ListNode* head = new ListNode(1);
	//head->next = new ListNode(2);
	//head->next->next =head;
	////detectCycle(head);
	//
	//ifstream in("input.txt");
	//stringstream buffer;
	//buffer << in.rdbuf();
	//vector<string>res;
	//string token;
	//while (getline(buffer, token, '\t'))
	//{
	//	res.push_back(token);
	//}

	//ListNode* head = new ListNode(8);
	//head->next = new ListNode(9);
	//head->next->next = new ListNode(9);
	////head->next->next->next = new ListNode(4);
	////head->next->next->next->next = new ListNode(5);
	///*reverseBetween(head, 1, 5);*/
	//plusOneWithoutExtraSpace(head);


	/*vector<int>vv{ 0, 1, 0, 3, 12 ,0,13,0,12,3,9,0,0,4,3,0,2};
	int index= moveZeroesWithMinimumSetps(vv);
	for (int i = 0; i <=index; ++i)cout << vv[i] << endl;*/


	vector<string>strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	groupAnagrams(strs);
	return 0;
}