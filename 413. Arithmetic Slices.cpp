#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
		int ans = 0;
		int last_opt = 0;
		// vector<int> opt(A.size(), 0);
		for (int i=2; i < A.size(); ++i) {
			if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
				last_opt++;
				ans += last_opt;
			}
			else {
				last_opt = 0;
			}
		}
        return ans;
    }
};

int main() {
	Solution a;
	vector<int> v = {1,3,2,3,4};
	cout << a.numberOfArithmeticSlices(v) << endl;
	return 0;
}
