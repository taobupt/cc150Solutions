#include"struct.h"
bool hasArrayTwoCandiates(int A[], int arr_size, int sum)
{
	unordered_map<int, int>mp;
	for (int i = 0; i < arr_size; ++i)
	{
		auto it = mp.find(sum - A[i]);
		if (it != mp.end())return true;
		mp[A[i]] = i;
	}
	return false;
}

// merge an array if size n into another array of m+n
// no need to add new space;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i]>nums2[j])nums1[k--] = nums1[i--];
		else nums1[k--] = nums1[j--];
	}
	while (j >= 0)nums1[k--] = nums1[j--];
}

// find median of two sorted arrays

// the time complexity is O(logk)=O(log(m+n))
double findkth(int a[], int m, int b[], int n, int k)
{
	if (m > n)return findkth(b, n, a, m, k);
	if (m == 0)return b[k - 1];
	if (k == 1)return min(a[0], b[0]);
	int pa = min(k / 2, m), pb = k - pa;
	if (a[pa - 1] < b[pb - 1])
	{
		return findkth(a + pa, m - pa, b, n, k - pa);
	}
	else if (a[pa - 1] > b[pb - 1])return findkth(a, m, b + pb, n - pb, k - pb);
	else return a[pa - 1];
}
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	int total = m + n;
	if (total & 0x1)return findkth(A, m, B, n, total / 2 + 1);
	else return (findkth(A, m, B, n, total / 2 + 1) + findkth(A, m, B, n, total / 2)) / 2;
}





// find the kth smallest value in an array
// time complexity is O(n)
int partition(vector<int>& v, int left, int right)
{
	int begin = left, end = right, key = v[begin];
	while (begin < end)
	{
		while (begin < end && v[end] >= key)end--;
		v[begin] = v[end];
		while (begin < end && v[begin] <= key)begin++;
		v[end] = v[begin];
	}
	v[begin] = key;
	return begin;
}

int getKth(vector<int>&nums, int begin,int end,int k)
{
	int index = partition(nums, begin, end);
	if (index + 1 == k)return nums[index];
	else if (index + 1 < k)return getKth(nums, index + 1, end, k);
	else return getKth(nums, begin, index - 1, k);
}



// failed in the google

// shift right
int gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a%b);
}
void shiftarrayright(int a[], int n, int d)
{
	int common = gcd(n, d);
	d = d%n;
	for (int i = n - 1; i > n - 1 - common; --i)
	{
		int j = i;
		int tmp = a[j];
		while (true)
		{
			int index = (j - d) < 0 ? n + (j - d) : j - d;
			if (i == index)break;
			a[j] = a[index];
			j=index;
		}
		a[j] = tmp;
	}
}

void leftRotate(int arr[], int d, int n)
{
	int i, j, k, temp;
	for (i = 0; i < gcd(d, n); i++)
	{
		/* move i-th values of blocks */
		temp = arr[i];
		j = i;
		while (1 != 0)
		{
			k = j + d;
			if (k >= n)
				k = k - n;
			if (k == i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

//Leaders in an array; scan form right
// reverse sequence ; merge sort binary index tree
//103 find subarray sum=0  ;;  sum sotre [0,i], hashmpa serach