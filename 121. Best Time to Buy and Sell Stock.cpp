#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() <= 1) return 0;
//         int maxprofit=0, minprice = INT_MAX;
//         for (int i=0; i < prices.size(); ++i) {
//             // if (prices[i] < minprice) minprice = prices[i];
//             // else if (prices[i] - minprice > maxprofit) maxprofit = prices[i] - minprice;
//             minprice = min(minprice, prices[i]);
//             maxprofit = max(maxprofit, prices[i] - minprice);
//         }
//         return maxprofit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int cash = 0, hold = -prices[0];
        for (int i=1; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i]);
            hold = max(hold, -prices[i]);
        }
        return cash;
    }
};

int main() {
    Solution s;
    vector<int> v{4,7,5,3,5,8,3,2};
    cout << s.maxProfit(v) << endl;
}
