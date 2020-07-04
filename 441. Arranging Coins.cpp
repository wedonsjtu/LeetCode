#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long begin=0, end=n;
        long long mid;
        long long curr;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            curr = mid * (mid + 1) / 2;
            if (curr == n) return mid;
            if (curr > n) end = mid - 1;
            else begin = mid + 1;
        }
        return end;
    }
};


int main() {
    Solution sol;
    for (int i=0; i <= 20; ++i) {
        cout << i << ' ' <<  sol.arrangeCoins(i) << endl;
    }
    return 0;
}
