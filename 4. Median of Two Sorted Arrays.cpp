#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n=nums2.size();
		vector<int> *A, *B;
		if (m > n) A = &nums2, B = &nums1, m = m + n, n = m - n, m = m - n;
		else A = &nums1, B = &nums2;
		int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
		int i, j;
		int maxLeft = 0, minRight = 0;
		while (imin <= imax) {
			i = (imin + imax) / 2;
			j = halfLen - i;
			if (i < imax && (*B)[j-1] > (*A)[i]) imin = i + 1;
			else if (i > imin && (*A)[i-1] > (*B)[j]) imax = i - 1;
			else {
				maxLeft = 0;
				if (i == 0) maxLeft = (*B)[j-1];
				else if (j == 0) maxLeft = (*A)[i-1];
				else maxLeft = max((*A)[i-1], (*B)[j-1]);
				if ((m + n) % 2 == 1) return maxLeft;
				minRight = 0;
				if (i == m) minRight = (*B)[j];
				else if (j == n) minRight = (*A)[i];
				else minRight = min((*A)[i], (*B)[j]);
				return (double)(maxLeft + minRight) / 2.0;
			}
		}
		return 0;
    }
};

int main() {
	Solution a;
	vector<int> n1 = {1, 3}, n2 = {2};
	cout << a.findMedianSortedArrays(n2, n1) << endl;
	vector<int> n3 = {100001}, n4 = {100000};
	cout << a.findMedianSortedArrays(n3, n4) << endl;
	return 0;
}
