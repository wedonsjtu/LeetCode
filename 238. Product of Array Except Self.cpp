#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
		vector<int> res(n, 1);
		int begin = 1;
		int end = 1;
		for (int i=0; i < n; ++i) {
			res[i] *= begin;
			begin *= nums[i];
			res[n-i-1] *= end;
			end *= nums[n-i-1];
		}
		return res;
    }
};

int main() {
	Solution a;
	vector<int> v = {1, 2, 3, 4};
	v = a.productExceptSelf(v);
	for (int i: v) cout << i << endl;
	return 0;
}
