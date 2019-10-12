#include <iostream>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int nums[n];
		nums[0] = 1;
		int ii=0, iii=0, v=0;  // 2 3 5
		for (int i=1; i < n; ++i) {
			nums[i] = min(nums[ii] * 2, min(nums[iii] * 3, nums[v] * 5));
			if (nums[i] == nums[ii] * 2) ++ii;
			if (nums[i] == nums[iii] * 3) ++iii;
			if (nums[i] == nums[v] * 5) ++v;
		}
		return nums[n-1];
    }
};

int main() {
	Solution a;
	for (int i=1; i < 20; ++i) cout << a.nthUglyNumber(i) << ' ';
	cout << endl;
	return 0;
}
