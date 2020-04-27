#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long begin = 0, end = c, mid;
        long long cc = c;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (mid * mid == cc) return true;
            if (mid * mid < cc) {
                begin = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        long long l = 0, r = mid;
        while (l <= r) {
            if (l * l + r * r == cc) {
                return true;
            }
            if (l * l + r * r > cc) {
                --r;
            }
            else {
                ++l;
            }
        }
        return false;
    }
};

int main() {
    cout << boolalpha;
    cout << Solution().judgeSquareSum(2076274201) << endl;
    cout << Solution().judgeSquareSum(3242) << endl;
    cout << Solution().judgeSquareSum(4) << endl;
    return 0;
}
