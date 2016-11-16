#include"Header.h"
class TrieNode {
public:
	// Initialize your data structure here.
	char content;
	bool isEnd;
	vector<TrieNode*>nodes;
	TrieNode* getNode(char c)
	{
		if (!nodes.empty())
		{
			for (auto it : nodes)
			{
				if (it->content == c)return it;
			}
		}
		return nullptr;
	}
	TrieNode() :content(' '), isEnd(false){}
	TrieNode(char c):content(c), isEnd(false){}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* newNode=cur->getNode(c);
			if (newNode == nullptr)
			{
				newNode = new TrieNode(c);
				cur->nodes.push_back(newNode);
			}
			cur = newNode;
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* newNode = cur->getNode(c);
			if (newNode == nullptr)return false;
			cur = newNode;
		}
		return cur->isEnd;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* cur = root;
		for (char c : prefix)
		{
			TrieNode* newNode = cur->getNode(c);
			if (newNode == nullptr)return false;
			cur = newNode;
		}
		return true;
	}

private:
	TrieNode* root;
};