#include"Header.h"

#define capacity 20
class SetOfStacks{

public:
	void push(int v);
	int pop();
	int popAt(int index);
private:
	vector<stack<int>>res;
};

void SetOfStacks::push(int v)
{
	stack<int>last = res.back();
	if (!last.empty() && last.size() != capacity)
	{
		last.push(v);
	}
	else
	{
		stack<int>s;
		s.push(v);
		res.push_back(s);
	}
}

int SetOfStacks::pop()
{
	stack<int>last = res.back();
	int val = last.top();
	if (last.size() == 1)res.pop_back();
	return val;
}



//put all left data into a vector,and then push it into setsofstack
int  SetOfStacks::popAt(int index)
{
	int index1 = index / capacity, index2 = index%capacity;
	int index3 = capacity - index1-1;
	stack<int>tmp;
	while (index3--){ tmp.push(res[index1].top()); res[index1].pop(); }
	
	int val = res[index1].top();
	res[index1].pop();

	while (!tmp.empty()){ res[index1].push(tmp.top()); tmp.pop(); }
	vector<int>data;
	int size = res.size();
	for (int i = size-1; i >index1; --i)
	{
		while (!res[i].empty())
		{
			data.push_back(res[i].top());
			res[i].pop();
		}
		res.pop_back();
	}
	for (int i = (data.size() - 1); i >= 0; --i)push(data[i]);
	return val;
}