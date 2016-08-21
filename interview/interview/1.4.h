#include"Header.h"
string replaceString(string x)
{
	for (int i = 0; i < int(x.size());++i)
	{
		if (x[i] == ' ')
		{
			while (x[i] == ' ')
			{
				//x.pop_back();
				x.erase(x.begin() + i);
			}
			x.insert(i, "%20");
		}
	}
	return x;
}