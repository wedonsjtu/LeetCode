#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
private:
    stack<int> prices;
    stack<int> seq;
public:
    StockSpanner(): prices(), seq() {}
    
    int next(int price) {
        int ans = 1;
        while (!prices.empty() && prices.top() <= price) {
            ans += seq.top();
            prices.pop();
            seq.pop();
        }
        seq.push(ans);
        prices.push(price);
        return ans;
    }
};

int main() {
    StockSpanner ss;
    vector<int> v{100, 80, 60, 70, 60, 75, 85};
    for (int i: v) cout << ss.next(i) << ' ';
    cout << endl;
    return 0;
}
