#include"Header.h"
#include"struct.h"

string DoubleToBinary(double a)
{
	if (a >= 1.0 || a <= 0.0)return "Error!";
	string res = "0.";
	while (a > 0)
	{
		if (res.size() > 32)return "Error";
		a *= 2;
		if (a >=1.0)
		{
			res.push_back('1');
			a -= 1.0;
		}
		else res.push_back('0');
	}
	return res;
}
