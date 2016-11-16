#include"Header.h"
struct HuffmanCode {
	int freq;
	char c;
	HuffmanCode *left, *right;
	HuffmanCode(int freq, char c) :c(c), freq(freq), left(NULL), right(NULL){}
};

struct cmpare {
	bool operator()(HuffmanCode* a, HuffmanCode* b)
	{
		return a->freq > b->freq;
	}
};

class Huffman {
private:
	unordered_map<char, int>mp;//get the frequenecy;
	priority_queue<HuffmanCode*, vector<HuffmanCode*>, cmpare>pq;
	HuffmanCode* root;
	string target;
	unordered_map<char, string> res;
	map<string, char> reverse_res;
public:
	Huffman(string target)
	{
		buildTree(target);
		this->target = target;
	}
	void buildTree(string target)
	{
		for (char c : target)mp[c]++;
		for (unordered_map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			pq.push(new HuffmanCode(it->second, it->first));
		}
		while (pq.size()>1)
		{
			HuffmanCode* z = new HuffmanCode(0, ' ');
			z->left = pq.top();
			pq.pop();
			z->right = pq.top();
			pq.pop();
			z->freq = z->left->freq + z->right->freq;
			pq.push(z);
		}
		root = pq.top();
		pq.pop();
	}
	void dfs(HuffmanCode* root, unordered_map<char, string> &res, string &path)
	{
		if (root->left == NULL && root->right == NULL)
		{
			res[root->c] = path;
			return;
		}
		if (root->left)
		{
			path.push_back('0');
			dfs(root->left, res, path);
			path.pop_back();
		}
		if (root->right)
		{
			path.push_back('1');
			dfs(root->right, res, path);
			path.pop_back();
		}
	}
	string encode()
	{
		string path;
		if (root == NULL)return "";
		dfs(root, res, path);
		for (auto it = res.begin(); it != res.end(); ++it)
		{
			reverse_res[it->second] = it->first;
		}
		string ans = "";
		for (char c : target)
		{
			ans += res[c];
		}
		return ans;

	}
	string decode(string res)
	{
		int i = 0, n = res.size();
		string x = "";
		while (i < n)
		{
			int k = 1;
			for (; k <= n - i; ++k)
			{
				string sub = res.substr(i, k);
				if (reverse_res.find(sub) != reverse_res.end())
				{
					x.push_back(reverse_res[sub]);
					break;
				}
			}
			i += k;
		}
		return x;
	}
};