#include"Header.h"
#include"struct.h"
//
//string words(int num, vector<string> &to19, vector<string> &tens,vector<string> &higher)
//{
//	if (num < 20)return (num==0?"":to19[num-1]);
//	else if (num < 100) return tens[num / 10 - 2] +(num%10>0?" "+to19[num%10-1]:"");
//	else if (num < 1000) return (num/100>0?to19[num / 100-1]:"") + " Hundred " + words(num % 100, to19, tens,higher);
//	int i = 1;
//	long long a = 0;;
//	for (; i <= 3; ++i)
//	{
//		a = (long long)pow(1000, i+1);
//		if (num < a)break;
//	}
//	a /= 1000;
//	return words(num / a, to19, tens, higher) + " " + higher[i] + " " + words(num%a, to19, tens, higher);
//}
//string numberToWords(int num) {
//	vector<string>to19{"One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
//	vector<string>tens{ "Twenty", "Thirty", "Forty","Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
//	vector<string>higher{ " ", "Thousand", "Million", "Billion" };
//	string res = words(num, to19, tens, higher);
//	if (res.back()==' ')res.pop_back();
//	return num==0?"Zero":res;
//}
/*

https://leetcode.com/submissions/detail/62279279/
class Solution(object):
def numberToWords(self, num):
"""
:type num: int
:rtype: str
"""
to19 = 'One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve Thirteen Fourteen '\
'Fifteen Sixteen Seventeen Eighteen Nineteen'.split()
tens='Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety'.split()
def words(n):
if n<20:
return to19[n-1:n]
if n<100:
return [tens[n/10-2]]+words(n%10)
if n<1000:
return [to19[n/100-1]]+['Hundred']+words(n%100)
for p,w in enumerate(('Thousand','Million','Billion'),1):
if n<1000**(p+1):
return words(n/1000**p)+[w]+words(n%1000**p)
return ' '.join(words(num)) or 'Zero'
*/