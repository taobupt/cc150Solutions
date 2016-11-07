#include"Header.h"
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL){}
};


struct GraphNode{
	int val;
	vector<GraphNode*>children;
	GraphNode(int val) :val(val){}
	~GraphNode()
	{
		for (auto child : children)
		{
			delete child;
		}
	}
};
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* father;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

struct DoubleListNode{
	int val;
	DoubleListNode* prev;
	DoubleListNode* next;
	DoubleListNode(int val) :val(val),next(NULL),prev(NULL){}
};

class DoubleList{
public:
	DoubleListNode* getHead(){ return head; }
	DoubleList(int arr[], int lenth);
	void PrintDoubleListNode(DoubleListNode* head);

private:
	DoubleListNode* head;

};

DoubleList::DoubleList(int arr[], int length)
{
	if (length < 1)return;
	head = new DoubleListNode(arr[0]);
	DoubleListNode* p = head;
	DoubleListNode* newNode;
	for (int i = 1; i < length; ++i)
	{
		newNode = new DoubleListNode(arr[i]);
		p->next = newNode;
		newNode->prev = p;
		p = p->next;
	}
}


void DoubleList::PrintDoubleListNode(DoubleListNode* head)
{
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

class List{

public:
	ListNode* getHead(){ return head; }
	List(int arr[], int length);
	void printListNode(ListNode* head);
private:
	ListNode* head;
};

List::List(int arr[], int length)
{
	if (length == 0)return;
	head = new ListNode(arr[0]);
	ListNode* p = head;
	for (int i = 1; i < length; ++i)
	{
		p->next = new ListNode(arr[i]);
		p = p->next;
	}
}

void List::printListNode(ListNode* head)
{
	while (head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

struct Point{
	double x;
	double y;
	Point(double x, double y) :x(x), y(y){}
};

ostream& operator <<(ostream& out, Point& x)
{
	out << "(" << x.x << "," << x.y << ")";
	return out;
}