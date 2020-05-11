#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) {  // avoid overflow
            n /= 2;
            x = x * x;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        // if (n % 2 == 0) {  // recursion
        //     return myPow(x*x, n/2);
        // }
        // else {
        //     return x * myPow(x*x, n/2);
        // }

        double ans = 1;
        while (n > 0) {
            if (n & 1) ans *= x;
            x = x * x;
            n /= 2;
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().myPow(3.14159, 12);
    cout << fixed << ans << endl;
    return 0;
}
