#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        	max_profit += max(prices[i]-prices[i-1], 0);
        return max_profit;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.empty()) return 0;
//         int cash = 0, hold = -prices[0]; 
//         for (int i = 1; i < prices.size(); ++i) {
//             cash = max(cash, hold + prices[i]);
//             hold = max(hold, cash - prices[i]);
//         }
//         return cash;
//     }
// };

int main() {
	Solution a;
	vector<int> v {7,1,5,3,6,4};
	cout << a.maxProfit(v) << endl;
}
