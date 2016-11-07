#include"Header.h"


const double centerx = 1.0;
const double centery = 2.0;

struct Point{
	double x;
	double y;
	Point(double x, double y) :x(x), y(y){}
	bool operator<(Point b)
	{
		return hypot(x - centerx, y - centery) < hypot(b.x - centerx, b.y - centery);
	}
};
//int partition(vector<int>& A, int left, int right)
//{
//	int i = left, j = right, key = A[left];
//	while (i < j)
//	{
//		while (i < j && A[j] >= key)j--;
//		A[i] = A[j];
//		while (i < j && A[i] <= key)i++;
//		A[j] = A[i];
//	}
//	A[i] = key;
//	return i;
//}

int partition(vector<int>&nums, int left, int right)
{
	int begin = left, end = right, key = nums[left];
	while (begin < end)
	{
		while (begin < end && nums[end] >= key)--end;
		nums[begin] = nums[end];
		while (begin < end && nums[begin] <= key)begin++;
		nums[end] = nums[begin];
	}
	nums[begin] = key;
	return begin;
}

int findKthMin(vector<int> A, int start, int end, int k){
	int i = partition(A, start, end);
	if (i + 1 == k){
		return A[i];
	}
	else if (i + 1<k){
		return findKthMin(A, i + 1, end, k);
	}
	else{
		return findKthMin(A, start, i - 1, k);
	}
}


// partition

//int partition(vector<int>nums, int left, int right)
//{
//	int begin = left, end = right, key = nums[begin];
//	while (begin < end)
//	{
//		while (begin < end && nums[end] >= key)--end;
//		nums[begin] = nums[end];
//		while (begin < end && nums[begin] <= key)begin++;
//		nums[end] = nums[begin];
//	}
//	nums[begin] = key;
//	return begin;
//}
//
//
//int findKth(vector<int>A, int start, int end, int k)
//{
//	int index = partition(A, start, end);
//	if (index + 1 == k)return A[index];
//	else if (index + 1 < k)return findKth(A, index + 1, end, k);
//	else return findKth(A, start, index - 1, k);
//}
