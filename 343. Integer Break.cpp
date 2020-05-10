#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) return 1;
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int num=3; num <= n; ++num) {
            for (int i=1; i <= num / 2; ++i) {
                dp[num] = max(dp[num], max(i * (num-i), i * dp[num-i]));
            }
        }
        return dp[n];
    }
};

int main() {
    for (int i=1; i<=10; ++i) {
        auto ans = Solution().integerBreak(i);
        cout << i << ' ' << ans << endl;
    }
    return 0;
}
