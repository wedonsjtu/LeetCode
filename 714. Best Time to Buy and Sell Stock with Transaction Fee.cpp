#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int cash = 0, hold = -prices[0]; 
        for (int i = 1; i < prices.size(); ++i) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};

int main() {
	Solution a;
	vector<int> v {1, 3, 2, 8, 4, 9};
	cout << a.maxProfit(v, 2) << endl;
}
