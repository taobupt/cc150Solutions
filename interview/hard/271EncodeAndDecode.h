#include"Header.h"
struct HuffmanCode {
	int freq;
	string ss;
	HuffmanCode *left, *right;
	HuffmanCode(int freq, string c) :ss(c.begin(), c.end()), freq(freq), left(NULL), right(NULL){}
};

struct cmpare {
	bool operator()(HuffmanCode* a, HuffmanCode* b)
	{
		return a->freq > b->freq;
	}
};

class Codec {

private:
	unordered_map<string, int>mp;//get the frequenecy;
	priority_queue<HuffmanCode*, vector<HuffmanCode*>, cmpare>pq;
	HuffmanCode* root;
	vector<string> target;
	unordered_map<string, string> res;//frequene express
	map<string, string> reverse_res;
public:
	Codec()
	{

	}
	void buildTree(vector<string> target)
	{
		if (target.empty())return ;
		for (string c : target)mp[c]++;
		for (unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			pq.push(new HuffmanCode(it->second, it->first));
		}
		while (pq.size()>1)
		{
			HuffmanCode* z = new HuffmanCode(0, " ");
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
	void dfs(HuffmanCode* root, unordered_map<string, string> &res, string &path)
	{
		if (root->left == NULL && root->right == NULL)
		{
			res[root->ss] = path;
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
	string encode(vector<string>target)
	{
		buildTree(target);
		this->target = target;
		string path;
		if (root == NULL)return "";
		dfs(root, res, path);
		if (res.size()==1)
		{
			path.push_back('0');
			res[root->ss] = "0";
		}
		for (auto it = res.begin(); it != res.end(); ++it)
		{
			reverse_res[it->second] = it->first;
		}
		string ans = "";
		for (string c : target)
		{
			ans += res[c];
		}
		return ans;

	}
	vector<string> decode(string res)
	{
		int i = 0, n = res.size();
		vector<string> x;
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






class codec{
public:
	string encode(vector<string>& strs)
	{
		string encoded = "";
		for (string& str : strs)
		{
			int len = str.size();
			encoded += to_string(len) + "@" + str;
		}
		return encoded;
	}
	vector<string>decode(string s)
	{
		vector<string>r;
		int head = 0;
		while (head < s.size())
		{
			int at_pos = s.find_first_of('@', head);
			int len = stoi(s.substr(head, at_pos - head));
			head = at_pos + 1;
			r.push_back(s.substr(head, len));
			head += len;
		}
		return r;
	}
};