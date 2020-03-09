#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int cash_sell_yesterday = -prices[0], cash_not_sell_yesterday = 0, hold = -prices[0];
        int max_cash;
        for (int i=1; i < prices.size(); ++i) {
            max_cash = max(cash_sell_yesterday, cash_not_sell_yesterday);
            cash_sell_yesterday = hold + prices[i];
            hold = max(hold, cash_not_sell_yesterday - prices[i]);
            cash_not_sell_yesterday = max_cash;
        }
        return max(cash_sell_yesterday, cash_not_sell_yesterday);
    }
};

int main() {
	Solution a;
	vector<int> v {7,1,5,3,4,2,6,9,0,6,4};
	cout << a.maxProfit(v) << endl;
}
