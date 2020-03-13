#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        int mid, div, mod;
        while (left <= right) {
            mid = (left + right) / 2;
            div = x / mid;
            mod = x % mid;
            if (div == mid) return mid;
            if (div > mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};

int main() {
    Solution a;
    for (int i=0; i <= 200; ++i) {
        cout << i;
        if (a.mySqrt(i+1) != a.mySqrt(i)) cout << endl; else cout << ' ';
    }
    cout << endl << endl;
    cout << a.mySqrt(2147395600 - 1) << endl;
    cout << a.mySqrt(2147395600) << endl;
    cout << a.mySqrt(2147483647) << endl;
}
