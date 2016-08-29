#include"Header.h"
#include"struct.h"
string insertMtoN(string N, string M, int i, int j)
{
	reverse(N.begin(), N.end());
	reverse(M.begin(), M.end());
	for (int k = 0; k < int(M.size());++k)
	{
		N[k + i] = M[k];
	}
	reverse(N.begin(), N.end());
	return N;
}