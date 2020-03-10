#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min_price = INT_MAX, max_profit_only_once = 0,
//             min_price_second = INT_MAX, max_profit_once_or_twice = 0;
//         for (int current_price: prices) {
//             min_price = min(min_price, current_price);
//             max_profit_only_once = max(max_profit_only_once, current_price - min_price);
//             min_price_second = min(min_price_second, current_price - max_profit_only_once);
//             // At the first time we must earn some money, so at the second time you only need to spend (current_price - max_profit_only_once);
//             max_profit_once_or_twice = max(max_profit_once_or_twice, current_price - min_price_second);
//         }
//         return max_profit_once_or_twice;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int cash_once=0, cash_twice=0, 
            hold_once=-prices[0], hold_twice=-prices[0];
        for (int i=1; i < prices.size(); ++i) {
            cash_once = max(cash_once, hold_once + prices[i]);
            hold_once = max(hold_once, -prices[i]);
            cash_twice = max(cash_twice, hold_twice + prices[i]);
            hold_twice = max(hold_twice, cash_once - prices[i]);
        }
        return cash_twice;
    }
};

int main() {
    Solution s;
    vector<int> v{3,3,5,0,0,3,1,4};
    cout << s.maxProfit(v) << endl;
}
