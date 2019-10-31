#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int* last = new int[grid[0].size()]();
        int* now = new int[grid[0].size()]();
		int i, j;
		int* last_opt = last;
		int* now_opt = now;
		int* tmp;
		for (i=0; i < grid.size(); ++i) {
			for (j=0; j < grid[0].size(); ++j) {
				if (i == 0 && j == 0) now_opt[0] = grid[0][0];
				else if (i == 0) now_opt[j] = now_opt[j-1] + grid[i][j];
				else if (j == 0) now_opt[j] = last_opt[j] + grid[i][j];
				else now_opt[j] = min(now_opt[j-1], last_opt[j]) + grid[i][j];
			}
			// cout << now_opt[0] << ' ' << now_opt[1] << ' ' << now_opt[2] << endl;
			tmp = last_opt;
			last_opt = now_opt;
			now_opt = tmp;
		}
		int ans = last_opt[grid[0].size()-1];
		delete[] last;
		delete[] now;
		return ans;
    }
};

int main() {
	Solution a;
	vector<vector<int>> v = {vector<int>({1, 3, 1}), vector<int>({1, 5, 1}), vector<int>({4, 2, 1})};
	cout << a.minPathSum(v) << endl;
	return 0;
}
