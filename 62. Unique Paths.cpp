#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
		if (m == 1 || n == 1) return 1;
        int last[m] = {1}, now[m] = {1};
		int i, j;
		for (i=1; i < m; ++i) {
			last[i] = 1;
			now[i] = 0;
		}
		int* last_opt = last;
		int* now_opt = now;
		int* tmp;
		for (i=1; i < n; ++i) {
			for (j=1; j < m; ++j) {
				now_opt[j] = last_opt[j] + now_opt[j-1];
			}
			tmp = last_opt;
			last_opt = now_opt;
			now_opt = tmp;
		}
		return last_opt[m-1];
    }
};

int main() {
	Solution a;
	cout << a.uniquePaths(7, 3) << endl;
	return 0;
}
