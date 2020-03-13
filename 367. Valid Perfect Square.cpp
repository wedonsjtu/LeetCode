#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left = 0, right = num;
        int mid, div, mod;
        while (left <= right) {
            mid = (left + right) / 2;
            div = num / mid;
            mod = num % mid;
            if (div == mid && mod == 0) return true;
            if (div >= mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution a;
    cout << a.isPerfectSquare(2147395600) << endl;
    cout << a.isPerfectSquare(2147483647) << endl;
}
