#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long count = 9;
        long long len = 1;
        long long start = 1;
        while (n > len * count) {
            n -= len * count;
            ++len;
            count *= 10;
            start *= 10;
        }
        int current = start + (n - 1) / len;
        int location = (n - 1) % len;
        stringstream s;
        s << current;
        return s.str()[location] - '0';
    }
};

int main() {
    cout << Solution().findNthDigit(11) << endl;
    return 0;
}
