#include"Header.h"

string compress(string x)
{
	int count = 1;
	string newX ="";
	int i = 0;
	for (i = 0; i<int(x.size())-1; ++i)
	{
		if (x[i + 1] != x[i])
		{
			newX.push_back(x[i]);
			newX += to_string(count);
			count = 1;
		}
		else
		{
			count++;
		}
	}
	newX.push_back(x[i]);
	newX += to_string(count);
	return newX.size()<x.size()?newX:x;
}