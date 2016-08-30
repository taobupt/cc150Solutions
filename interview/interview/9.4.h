#include"Header.h"
#include"struct.h"


//the n is the set ,must order
void print_subset(vector<int> n, vector<int> &a) {
	// if (cur > n.size())return;
	for (int i = 0; i < a.size(); i++)
		printf("%d ", a[i]);
	printf("\n");
	int s = a.empty() ? 0 : lower_bound(n.begin(), n.end(), a.back()) - n.begin()+1;
	for (int i = s; i < n.size(); i++) {
		a.push_back(n[i]);
		print_subset(n, a);
		a.pop_back();
	}
}