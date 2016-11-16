#include"Header.h"
void solve()
{
	double res1 = 0.0,res2=0,res3=0.0;
	vector<vector<int>>v{ { 246, 112, 50, 220, 225 }, { 106, 32, 39, 4, 216 }, { 69, 115, 219, 65, 187 }, { 186, 55, 221, 164,84 }, { 147, 235, 162, 25, 20 } };
	//vector<vector<double>>filter{ { 0.1153, 0.0643, 0.0 }, { 0.1264, 0.1131, 0.0953 }, { 0.1663, 0.1042, 0.2151 } };
	vector<vector<double>>filterx{ { 0, -1, 0 }, { 0, 0, 0 }, { 0, 1, 0 } };
	vector<vector<double>>filtery{ { 0, 0, 0 }, { -1, 0,1 }, { 0, 0, 0 } };
	int m = 3, n = 3;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			res1 += filterx[i][j] * v[i][j + 1];
			res2 += filtery[i][j] * v[i][j + 2];
			res2 += filtery[i][j] * v[i][j];
		}
	}
	//cout << res1 << endl;
	cout << res2-res3 << endl;
}

void solveQuiz7()
{
	vector<vector<int>>v{ { 246, 112, 50, 220, 225 }, { 106, 32, 39, 4, 216 }, { 69, 115, 219, 65, 187 }, { 186, 55, 221, 164, 84 }, { 147, 235, 162, 25, 20 } };
	vector<pair<int, int>>postivex{ { 2, 2 }, { 2, 1 }, { 2, 0 } };
	vector<pair<int, int>>negativex{ { 0, 2 }, { 0, 1 }, { 0, 0 } };

	vector<pair<int, int>>postivey{ { 0, 2 }, { 1, 2 }, { 2, 2 } };
	vector<pair<int, int>>negativey{ { 2, 0 }, { 1, 0 }, { 0, 0 } };

	int resx = 0,resy=0;
	for (auto it : postivex)resx += v[it.first][it.second + 1];
	for (auto it : negativex)resx -= v[it.first][it.second + 1];

	for (auto it : postivey)resy += v[it.first][it.second + 1];
	for (auto it : negativey)resy -= v[it.first][it.second + 1];
	//cout << resx << "  " << resy << endl;












	/// gaussian

	vector<vector<int>>vv{ { 138, 190, 109, 180, 132 }, { 200, 107, 104, 193, 131 }, { 103, 145, 121, 135, 164 }, { 129, 189, 105, 182, 129 }, { 166, 144, 107, 187, 139 } };
	vector<vector<int>>Gaussian{ { 15, 32, 14 }, { 34, 65, 30 }, { 18, 33, 14 } };
	/*int gauss1 = 10000000;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			gauss1 = min(gauss1, Gaussian[i][j] * vv[i][j + 1]);
		}
	}
	cout << gauss1 << endl;*/
	long long g = 0;
	int h = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			g += Gaussian[i][j] * Gaussian[i][j] * vv[i][j + 1] * vv[i][j + 1];
			h += Gaussian[i][j] * Gaussian[i][j];
		}
	}
	cout << g <<"    " <<h << endl;
}