#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int tmp;
        while (a) {
            // cout << bitset<sizeof(int)*8>(a) << ' ' << bitset<sizeof(int)*8>(b) << ' '
            //      << bitset<sizeof(int)*8>(a^b) << ' ' << bitset<sizeof(int)*8>((unsigned int)(a & b) << 1) << endl;
            // cout << a << ' ' << b << ' ' << (a^b) << ' ' << ((a & b) << 1) << endl;
            tmp = a ^ b;
            // a = ((a & b) & 0x7fffffff) << 1;
            a = (unsigned int)(a & b) << 1;
            b = tmp;
        }
        return b;
    }
};

int main() {
    Solution sol;
    cout << sol.getSum(-23, 45) << endl;
    return 0;
}
