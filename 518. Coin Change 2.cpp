#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        for (int i=1; i < dp.size(); ++i) {
            dp[i][0] = 1;
            for (int j=1; j < dp[0].size(); ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main() {
    vector<int> coins{1,5,2};
    auto ans = Solution().change(5, coins);
    cout << ans << endl;
    return 0;
}
