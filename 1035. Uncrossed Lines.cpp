#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=1; i <= m; ++i) {
            for (int j=1; j <= n; ++j) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<int> A{1,4,5,6}, B{5,4,1,6};
    auto ans = Solution().maxUncrossedLines(A, B);
    cout << ans << endl;
    return 0;
}
