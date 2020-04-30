#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
};

int main() {
    cout << Solution().isPowerOfFour(1024) << endl;
    cout << Solution().isPowerOfFour(2048) << endl;
    return 0;
}
