#include"Header.h"
string encode(vector<string>& strs)
{
	string encoded;
	for (string str : strs)
	{
		int len = str.size();
		encoded += to_string(len) + "@" + str;
	}
	return encoded;
}

vector<string>decode(string s)
{
	vector<string>res;
	int head = 0;
	while (head < s.size())
	{
		int at_pos = s.find_first_of("@",head);//has start point
		int len = stoi(s.substr(head, at_pos - head));
		head = at_pos + 1;
		r.push_back(s.substr(head, len));
		head += len;

	}
	return res;
}