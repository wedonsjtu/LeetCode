#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned sum1 = 1;
        while (sum1 < num) sum1 = (sum1 << 1) + 1;
        return sum1 ^ num;
    }
};

int main() {
    cout << Solution().findComplement(5) << endl;
    cout << Solution().findComplement(INT_MAX) << endl;
    cout << Solution().findComplement(32767) << endl;
    return 0;
}
