#include"Header.h"
#include"struct.h"

bool hasRouteBetweenNodes(GraphNode* p, GraphNode*q)
{
	if (p == q)return true;
	else{
		for (GraphNode* child : p->children)
		{
			if (hasRouteBetweenNodes(child, q))return true;
		}
	}
	return false;
}