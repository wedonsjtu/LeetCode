#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // if travel, dp[i] = min(dp[i-1]+costs[0], dp[i-7]+costs[1], dp[i-30]+costs[2]);
        if (days.empty()) return 0;
        int ans = 0, day_index = 0;
        vector<int> dp(366, 0);
        for (int i=1; i <= 365; ++i) {
            if (days[day_index] != i) {
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = dp[i-1] + min(costs[0], min(costs[1], costs[2]));
            if (i >= 7) dp[i] = min(dp[i], dp[i-7]+min(costs[1], costs[2]));
            else dp[i] = min(dp[i], min(costs[1], costs[2]));
            if (i >= 30) dp[i] = min(dp[i], dp[i-30]+costs[2]);
            else dp[i] = min(dp[i], costs[2]);
            ++day_index;
            if (day_index == days.size()) return dp[i];
        }
        return -1;
    }
};

int main() {
    vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs{2,16,1};
    cout << Solution().mincostTickets(days, costs) << endl;
    return 0;
}
