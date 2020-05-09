#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount <= 0) return 0;
        if (coins.empty()) return -1;
        // dp[i] 价钱为i最少需要的币
        // dp[i] = min_c(dp[i-c]) + 1
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i=1; i <= amount; ++i) {
            for (int coin: coins) {
                if (i >= coin) {
                    dp[i] = min((long long)dp[i], 1LL + dp[i-coin]);  // avoid overflow
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        else return dp[amount];
    }
};

int main() {
    vector<int> v{1, 2, 5};
    cout << Solution().coinChange(v, 11) << endl;
    return 0;
}
