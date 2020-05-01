#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
        
        // return n > 0 && 1162261467 % n == 0;  // 1162261467 = 3 ** 19
    }
};

int main() {
    cout << Solution().isPowerOfThree(27) << endl;
    return 0;
}
