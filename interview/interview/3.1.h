#include"Header.h"

/*
approach 1:fixed division

we can divide the array in three equal parts and allow the individual stack to grow in 
that limited area,note
- for stack 1,we will use [0,n/3)
- for stack 2, we will use [n/3,2n/3)
- for stack 3, we wiil use [2n/3.n)


if we had additional information about the expected usages of the stakcs, then 
we could modify this algorithm accordingly, for example, if we expected stack 1 to have
many more elements than stack2,we could allocate more space to stack1 and less space 
to stack2
*/
#define stackSize 100

class ThreeStack{
private:
	int buffer[stackSize * 3];
	int stackPointer[3] = { -1, -1, -1 };
public:
	void push(int stackNum, int value)
	{
		assert(stackPointer[stackNum] + 1 < stackSize);
		stackPointer[stackNum]++;
		buffer[absTopOfStack(stackNum)] = value;
	}


	int peek(int stackNum)
	{
		int index = absTopOfStack(stackNum);
		return buffer[index];
	}

	int pop(int stackNum)
	{
		assert(stackPointer[stackNum] != -1);
		int value = buffer[absTopOfStack(stackNum)];
		buffer[absTopOfStack(stackNum)] = 0;
		stackPointer[stackNum]--;
		return value;
	}
	bool empty(int stackNum)
	{
		return stackPointer[stackNum] == -1;
	}

	int absTopOfStack(int stackNum)
	{
		return stackNum*stackSize + stackPointer[stackNum];
	}
};

/*
flexible divisions
A second approach is to allow the stack blocks to flexible in size. When one 
stack exceeds its inital capacity,we grow the allowable capacity and shift elements
as necessary
we will also design our array to be circular, such that the final stack may start at the end
of the arry and wrap aorund the beginning

please note that the code for this solution if far more complex than would be 
appropriate for an interview, you could be repossible for pseudocode, opr perhaps
the code of individual components, but the entire inplementation would be
far too challenging.
*/

class stackData{
public:
	int start, pointer, size, capacity;
	stackData(int _start, int _capacity)
	{
		start = _start;
		capacity = _capacity;
		pointer = _start - 1;
	}
	bool isWithinStack(int index, int total_size)
	{
		if (start <= index && index < start + capacity)return true;
		else if (start + capacity>total_size && index < (start + capacity) % total_size)return true;
		else return false;
	}
};

#define number_of_stacks 3
#define default_size 4
const int total_size = number_of_stacks*default_size;



