#include"Header.h"
void reverseWords(string &s) {
	istringstream stream(s);
	string tmp;
	string res;
	while (stream >> tmp)res = " " + tmp+res;
	s = res.size() >= 1 ? res.substr(1) : "";
}