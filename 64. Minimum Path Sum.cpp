#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int* dp = new int[grid[0].size()]();
		int rows = grid.size(), cols = grid[0].size();
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[i][j];
                }
                else if (i == 0) {
                    dp[j] = dp[j-1] + grid[i][j];
                }
                else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                }
                else {
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }
            }
        }
        int ans = dp[cols-1];
        delete[] dp;
        return ans;
    }
};

int main() {
	Solution a;
	vector<vector<int>> v = {vector<int>({1, 3, 1}), vector<int>({1, 5, 1}), vector<int>({4, 2, 1})};
	cout << a.minPathSum(v) << endl;
	return 0;
}
