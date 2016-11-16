#include"Header.h"


struct TrieNode
{
	char content;
	bool isEnd;
	vector<TrieNode*>children;
	TrieNode() :content(' '), isEnd(false){}
	TrieNode(char c) :content(c), isEnd(false){}
	TrieNode* getSubNode(char c)
	{
		if (!children.empty())
		{
			for (auto child : children)
			{
				if (child->content == c)return child;
			}
		}
		return nullptr;

	}
};

class WordDictionary {
public:
	WordDictionary()
	{
		root = new TrieNode();
		//root->isEnd = true;
	}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* newNode = cur->getSubNode(c);
			if (newNode==nullptr)
			{
				newNode = new TrieNode(c);
				cur->children.push_back(newNode);
			}
			cur=newNode;
		}
		cur->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return find(word, root, 0);
	}

	bool find(string word, TrieNode* root, int cur)
	{
		if (cur == word.size())return root->isEnd;
		if (word[cur] == '.')
		{
			for (auto child : root->children)
			{
				if (find(word, child, cur + 1))return true;
			}
			return false;
		}
		else
		{
			return root->getSubNode(word[cur]) ? find(word, root->getSubNode(word[cur]), cur + 1) : false;
		}
		return false;
	}
private:
	TrieNode* root;
};