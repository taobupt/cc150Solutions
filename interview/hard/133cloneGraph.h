#include"Header.h"

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>hash1;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (!node)return nullptr;
	if (hash1.find(node) == hash1.end())
	{
		hash1[node] = new UndirectedGraphNode(node->label);
		for (auto it : node->neighbors)
		{
			hash1[node]->neighbors.push_back(cloneGraph(it));
		}
	}
	return hash1[node];
}

//if null return ptr
// if find()==end then hash[node]=new 
