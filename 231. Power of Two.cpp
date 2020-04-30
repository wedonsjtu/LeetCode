#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    cout << Solution().isPowerOfTwo(3) << endl;
    cout << Solution().isPowerOfTwo(16) << endl;
    return 0;
}
