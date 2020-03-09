#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0) return 0;
        int prices_len = prices.size();
        if (prices_len < 2) return 0;
        if (k >= prices_len / 2) {  // same as doing arbitrary transactions
            int ans = 0;
            for (int i=1; i < prices_len; ++i) {
                ans += max(prices[i] - prices[i-1], 0);
            }
            return ans;
        }
        int cash[k+1], hold[k+1];
        for (int i=0; i < k+1; ++i) {
            cash[i] = 0;
            hold[i] = -prices[0];
        }
        for (int i=1; i < prices_len; ++i) {
            for (int j=1; j < k+1; ++j) {
                cash[j] = max(cash[j], hold[j] + prices[i]);
                hold[j] = max(hold[j], cash[j-1] - prices[i]);
            }
        }
        return cash[k];
    }
};

int main() {
	Solution a;
	vector<int> v {1, 3, 2, 8, 4, 9};
	cout << a.maxProfit(2, v) << endl;
}
