#include"Header.h"
int mul(vector<int>v1, vector<int>v2)
{
	int res = 0;
	for (int i = 0; i<v1.size(); ++i)res += v1[i] * v2[i];
	return res;
}
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	if (A.empty() || B.empty())return{};
	vector<vector<int>>res(A.size(), vector<int>(B[0].size(), 0));
	int m = A.size(), n = A[0].size(), k = B[0].size();
	for (int i = 0; i<m; ++i)
	{
		for (int o = 0; o<k; ++o)
		{
			vector<int>tmp;
			for (int j = 0; j<n; ++j)tmp.push_back(B[j][o]);
			res[i][o] = mul(A[i], tmp);
		}
	}
	return res;

}