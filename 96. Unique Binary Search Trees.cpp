#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
		if (n <= 1) return 1;
        unsigned long long* opt = new unsigned long long [n+1]();
		opt[0] = 1;  // 0 node
		opt[1] = 1;  // 1 node
		int i, j;
		for (i = 2; i <= n; ++i) {
			for (j = 0; j < i; ++j) {
				opt[i] += (opt[j] * opt[i-1-j]);
			}
		}
		unsigned long long ans = opt[n];
		delete[] opt;
		return ans;
    }
};

int main() {
	Solution a;
	for (int i=0; i <= 10; ++i) cout << i << ' ' << a.numTrees(i) << endl;
	return 0;
}
