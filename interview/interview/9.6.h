#include"Header.h"
#include"struct.h"


void AllpopParenethesis(vector<string>& output, stack<int>& stk, stack<int>& input, string& sequence,int n)
{
	if (stk.empty() && input.empty() && sequence.size() == 2 * n)
	{
		output.push_back(sequence);
		return;
	}
	if (!input.empty())
	{
		int top = input.top();
		input.pop();
		stk.push(top);
		sequence.push_back(')');
		AllpopParenethesis(output, stk, input, sequence, n);
		sequence.pop_back();
		stk.pop();
		input.push(top);
	}
	if (!stk.empty())
	{
		int top = stk.top();
		stk.pop();
		sequence.push_back('(');
		AllpopParenethesis(output, stk, input, sequence, n);
		sequence.pop_back();
		stk.push(top);
	}
}
vector<string>generate(int n)
{
	vector<string>output;
	string sequence = "";
	stack<int>stk;
	stack<int>input;
	for (int i = 1; i <= n; ++i)
	{
		input.push(i);
	}
	AllpopParenethesis(output, stk, input, sequence,n);
	return output;
}

