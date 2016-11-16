#include"Header.h"
//struct TrieNode{
//	bool isEnd;
//	char content;
//	TrieNode() :content(' '), isEnd(false){}
//	TrieNode(char c) :content(c), isEnd(false){}
//	vector<TrieNode*>children;
//	TrieNode* getNode(char c)
//	{
//		if (!children.empty())
//		{
//			for (auto it : children)
//			{
//				if (it->content == c)return it;
//			}
//		}
//		return nullptr;
//	}
//};
//
//class Trie{
//public:
//	Trie(){ root = new TrieNode(); }
//	void addword(string word)
//	{
//		TrieNode* cur = root;
//		for (char c : word)
//		{
//			TrieNode* node = cur->getNode(c);
//			if (node == nullptr)
//			{
//				node = new TrieNode(c);
//				cur->children.push_back(node);
//			}
//			cur = node;
//		}
//		cur->isEnd = true;
//	}
//	void addWords(vector<string>words)
//	{
//		for (string x : words)addword(x);
//	}
//public:
//	TrieNode* root;
//};


//void findword(vector<vector<char>>& board, TrieNode* root, string& word, int i, int j, set<string>& result_set)
//{
//	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == ' ')return;
//	if (root->getNode(board[i][j]) != nullptr)
//	{
//		word.push_back(board[i][j]);
//		root = root->getNode(board[i][j]);
//		if (root->isEnd)
//		{
//			result_set.insert(word);
//			return;
//		}
//		char c = board[i][j];
//		board[i][j] = ' ';
//		findword(board, root, word, i + 1, j, result_set);
//		findword(board, root, word, i , j+1, result_set);
//		findword(board, root, word, i -1, j, result_set);
//		findword(board, root, word, i, j-1, result_set);
//		board[i][j] = c;
//		word.pop_back();
//	}
//}
//
//vector<string> findWords(vector<vector<char>> board, vector<string> words)
//{
//	vector<string>res;
//	if (board.empty() || board[0].empty() | words.empty())return res;
//	int m = board.size(), n = board[0].size();
//	Trie* t = new Trie();
//	t->addWords(words);
//	set<string>result;
//	string word = "";
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			findword(board, t->root, word, i, j, result);
//		}
//	}
//	for (string x : result)res.push_back(x);
//}




//void dfs(vector<vector<char>>& board, TrieNode* root, int dx[], int dy[], int i, int j, vector<vector<bool>> &vis, set<string>& result_set,string word)
//{
//	if (root->isEnd)
//	{
//		result_set.insert(word);
//		return;
//	}
//	for (int k = 0; k < 4; ++k)
//	{
//		int nx = dx[k] + i, ny = dy[k] + j;
//		if (nx < 0 || nx >= (int)board.size() || ny < 0 || ny >= (int)board[0].size() || vis[nx][ny] || root->getNode(board[nx][ny]) == nullptr)continue;
//		vis[nx][ny] = true;
//		word.push_back(board[nx][ny]);
//		dfs(board, root->getNode(board[nx][ny]), dx, dy, nx, ny, vis, result_set, word);
//		word.pop_back();
//		vis[nx][ny] = false;
//	}
//	
//}
//vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//	vector<string>res;
//	if (board.empty() || board[0].empty() | words.empty())return res;
//	int m = board.size(), n = board[0].size();
//	int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
//	vector<vector<bool>>vis(m, vector<bool>(n, 0));
//	set<string>result_set;
//	string word;
//	Trie t;
//	t.addWords(words);
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (t.root->getNode(board[i][j]) != nullptr && !vis[i][j])
//			{
//				vis[i][j] = true;
//				word.push_back(board[i][j]);
//				dfs(board, t.root->getNode(board[i][j]), dx, dy, i, j, vis, result_set,word);
//				word.pop_back();
//				vis[i][j] = false;
//			}
//		}
//	}
//	for (string x : result_set)res.push_back(x);
//	return res;
//}

struct TrieNode{
	bool isend;
	char content;
	vector<TrieNode*>children;
	TrieNode() :isend(false), content(' '){}
	TrieNode(char c) :isend(false), content(c){}
	TrieNode* subNode(char c)
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
	~TrieNode()
	{
		for (auto child : children)delete child;
	}
};

class Trie{

public:
	Trie(){ root = new TrieNode(); }
	void addword(string word)
	{
		TrieNode* cur = root;
		for (char c : word)
		{
			TrieNode* child = cur->subNode(c);
			if (child == nullptr)
			{
				child = new TrieNode(c);
				cur->children.push_back(child);
			}
			cur = child;
		}
		cur->isend = true;
	}
	void addWords(vector<string> words)
	{
		for (string x : words)addword(x);
	}
public:
	TrieNode* root;
};

void findword(vector<vector<char>>& board, TrieNode* root, string& word, int i, int j, set<string>& result_set)
{
	if (i<0 || i >= board.size() || j<0 || j >= board[0].size() || board[i][j] == ' ')return;
	if (root->subNode(board[i][j]) != nullptr)
	{
		word.push_back(board[i][j]);
		root = root->subNode(board[i][j]);
		if (root->isend)
		{
			result_set.insert(word);
		}
		char c = board[i][j];
		board[i][j] = ' ';
		findword(board, root, word, i + 1, j, result_set);
		findword(board, root, word, i - 1, j, result_set);
		findword(board, root, word, i, j + 1, result_set);
		findword(board, root, word, i, j - 1, result_set);
		board[i][j] = c;
		word.pop_back();

	}
}

vector<string> findWords(vector<vector<char>> board, vector<string> words) {
	vector<string>res;
	if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)return res;
	int m = board.size(), n = board[0].size();
	Trie* t = new Trie();
	t->addWords(words);
	set<string> result_set;
	string word = "";
	for (int i = 0; i<m; ++i)
	{
		for (int j = 0; j<n; ++j)
		{
			findword(board, t->root, word, i, j, result_set);
		}
	}
	for (string x : result_set)res.push_back(x);
	return res;
}