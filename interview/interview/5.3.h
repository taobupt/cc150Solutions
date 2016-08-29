#include"Header.h"
#include"struct.h"
vector<int> getMaxMin(int num)
{
	int count = 0;
	for (int i = 0; i < 32; ++i)
	{
		count += (num >> i) & 1;
	}
	return{ (1 << count) - 1, ((1<<count)-1)<<(31-count)};
}