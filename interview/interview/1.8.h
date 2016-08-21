#include"Header.h"


bool isRotation(string x, string y)
{
	if (x.length != y.length)return false;
	x += x;
	return x.find(y) != x.npos;
}