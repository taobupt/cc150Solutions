#include"Header.h"

struct Person{
	string num;
	string name;
	Person(string name, string num) :num(num), name(name){}
};
int romanToInt(string s)
{
	unordered_map<char, int>mp = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
	int res = mp[s.back()];
	int n = s.size();
	for (int i = n - 2; i >= 0; --i)
	{
		res += mp[s[i]] < mp[s[i + 1]] ? -mp[s[i]] : mp[s[i]];
	}
	return res;
}

vector<string>getSortedList(vector<string>v)
{
	vector<Person>ans;
	for (int i = 0; i < v.size(); ++i)
	{
		int index = v[i].find_first_of(' ');
		Person p(v[i].substr(0, index), v[i].substr(index + 2));
		ans.push_back(p);
	}
	sort(ans.begin(), ans.end(), [](Person p1, Person p2){return p1.name == p2.name ? romanToInt(p1.num) < romanToInt(p2.num) : p1.name < p2.name; });
	vector<string>res;
	for (int i = 0; i < ans.size();++i)res.push_back(ans[i].name+"  "+ans[i].num);
	return res;
}