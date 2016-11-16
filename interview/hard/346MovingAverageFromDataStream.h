#include"Header.h"
class MovingAverage{
public:
	MovingAverage(int size)
	{
		window = new int[size]();// inital with u
		//window = new int[size];
		//fill_n(window, size, 0);
		insert = 0, sum = 0,n=0,length=size;
	}
	double next(int val)
	{
		if (n < length)n+=1;
		sum -= window[insert];
		sum += val;
		window[insert] = val;
		insert = (insert + 1) % length;
		return sum*1.0 / n;
	}
private:
	int* window;
	int insert, sum, n, length;
};

//