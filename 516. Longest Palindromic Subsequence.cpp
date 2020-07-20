#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i=dp.size()-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j=i+1; j < dp[0].size(); ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main() {
    auto ans = Solution().longestPalindromeSubseq("bbbab");
    cout << ans << endl;
    return 0;
}
