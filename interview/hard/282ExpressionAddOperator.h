#include"Header.h"

void dfs(vector<string>& res,string path,string num,int target,int pv,int cv,char oper ,int pos)
{
	if (cv == target && pos == num.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = pos + 1; i <=num.size(); ++i)
	{
		string sub = num.substr(pos, i-pos);
		long now = stol(sub);
		if (to_string(now) != sub)continue;
		dfs(res, path + '+' + sub, num, target, now, cv + now, '+', i);
		dfs(res, path + '-' + sub, num, target, now, cv - now, '-', i);
		dfs(res, path + '*' + sub, num, target, pv*now, (oper == '-') ? cv + pv - pv*now : ((oper == '+') ? cv - pv + pv*now : pv*now), oper, i);
	}
}

vector<string> addOperators(string num, int target) {
	vector<string>res;
	string path;
	int n = num.size();
	if (num.empty()) return res;
	for (int i = 1; i <=n; ++i)
	{
		string substr = num.substr(0, i);
		long cur = stol(substr);
		if (to_string(cur)!= substr)continue;
		dfs(res, path + substr, num, target, cur, cur, '#',i);
	}
	return res;
}

//void dfs(std::vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
//	if (pos == num.size() && cv == target) {
//		res.push_back(cur);
//	}
//	else {
//		for (int i = pos + 1; i <= num.size(); i++) {
//			string t = num.substr(pos, i - pos);
//			long now = stol(t);
//			if (to_string(now).size() != t.size()) continue;
//			dfs(res, num, target, cur + '+' + t, i, cv + now, now, '+');
//			dfs(res, num, target, cur + '-' + t, i, cv - now, now, '-');
//			dfs(res, num, target, cur + '*' + t, i, (op == '-') ? cv + pv - pv*now : ((op == '+') ? cv - pv + pv*now : pv*now), pv*now, op);
//		}
//	}
//}
//
//	vector<string> addOperators(string num, int target) {
//		vector<string> res;
//		if (num.empty()) return res;
//		for (int i = 1; i <= num.size(); i++) {
//			string s = num.substr(0, i);
//			long cur = stol(s);
//			if (to_string(cur).size() != s.size()) continue;
//			dfs(res, num, target, s, i, cur, cur, '#');         // no operator defined.
//		}
//
//		return res;
//	}