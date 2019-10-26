#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid[0].size();
		int n = obstacleGrid.size();
		if (m == 1) {
			for (int i=0; i < n; ++i) {
				if (obstacleGrid[i][0]) return 0;
			}
			return 1;
		}
		long long* last = new long long[m]();
		last[0] = 1;
		long long* now = new long long[m]();
		int i, j;
		for (i=1; i < m; ++i) {
			last[i] = 0;
		}
		
		long long* last_opt = last;
		long long* now_opt = now;
		long long* tmp;
		for (i=0; i < n; ++i) {
			// cout << i << endl;
			// for (int k=0; k < m; ++k) cout << last_opt[k] << ' ';
			// cout << endl;
			// for (int k=0; k < m; ++k) cout << now_opt[k] << ' ';
			// cout << endl;
			if (obstacleGrid[i][0] == 1) now_opt[0] = 0;
			else now_opt[0] = last_opt[0];
			for (j=1; j < m; ++j) {
				if (obstacleGrid[i][j] == 1) now_opt[j] = 0;
				else now_opt[j] = last_opt[j] + now_opt[j-1];
			}
			tmp = last_opt;
			last_opt = now_opt;
			now_opt = tmp;
		}
		// for (int k=0; k < m; ++k) cout << last_opt[k] << ' ';
		// 	cout << endl;
		int ans = last_opt[m-1];
		last_opt = NULL;
		now_opt = NULL;
		delete[] last;
		delete[] now;
		return ans;
    }
};

int main() {
	Solution a;
	vector<vector<int>> v = {vector<int>({0,0,1,0}), vector<int>({0,0,1,0}),vector<int>({0,0,0,0})};
	cout << a.uniquePathsWithObstacles(v) << endl;
	return 0;
}
