#include"Header.h"
#include"struct.h"

void print_permuation(string ss, string &s, int cur)
{
	if (cur == int(ss.size()))
	{
		for (int i = 0; i < s.size(); ++i)printf("%c", s[i]);
		printf("\n");
		return;
	}
	else if (cur>int(ss.size()))return;
	for (int i = 0; i < ss.size(); ++i)
	{
		int ok = 1;
		for (int j = 0; j < cur; ++j)
		{
			if (s[j] == ss[i])
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			s.push_back(ss[i]);
			print_permuation(ss, s, cur + 1);
			s.pop_back();
		}
	}
}