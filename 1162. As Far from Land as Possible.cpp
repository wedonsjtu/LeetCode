#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int i=0; i < m; ++i) {
            for (int j=0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                // dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                if (i > 0) {
                    dp[i][j] = dp[i-1][j];
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                }
                if (dp[i][j] != INT_MAX) {
                    ++dp[i][j];
                }
            }
        }
        int curr;
        for (int i=m-1; i >= 0; --i) {
            for (int j=n-1; j >= 0; --j) {
                // dp[i][j] = min(dp[i][j], p[i-1][j] + 1, dp[i][j-1] + 1);
                curr = dp[i][j];
                if (i < m - 1) {
                    dp[i][j] = dp[i+1][j];
                }
                if (j < n - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j+1]);
                }
                if (dp[i][j] != INT_MAX) {
                    ++dp[i][j];
                }
                dp[i][j] = min(dp[i][j], curr);
                ans = max(ans, dp[i][j]);
            }
        }
        if (ans == 0 || ans == INT_MAX) return -1;
        return ans;
    }
};

int main() {
    vector<vector<int>> grid{{1,0,0},{0,0,0},{0,0,0}};
    auto ans = Solution().maxDistance(grid);
    cout << ans << endl;
    return 0;
}
