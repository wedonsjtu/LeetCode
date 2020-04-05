#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // cout << a << " " << b << " " << c << " " << a+b+c << endl;
        string ans;
        int len = a + b + c;
        int a_num = 0, b_num = 0, c_num = 0;
        for (int i=0; i < len; ++i) {
            if ((a >= b && a >= c && a_num != 2) || (b_num == 2 && a > 0) || (c_num == 2 && a > 0)) {
                ans += 'a';
                --a;
                ++a_num;
                b_num = 0;
                c_num = 0;
            }
            else if ((b >= a && b >= c && b_num != 2) || (a_num == 2 && b > 0) || (c_num == 2 && b > 0)) {
                ans += 'b';
                --b;
                ++b_num;
                a_num = 0;
                c_num = 0;
            }
            else if ((c >= a && c >= b && c_num != 2) || (a_num == 2 && c > 0) || (b_num == 2 && c > 0)) {
                ans += 'c';
                --c;
                ++c_num;
                a_num = 0;
                b_num = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution a;
    cout << a.longestDiverseString(2,3,4) << endl;
    cout << a.longestDiverseString(2,4,1) << endl;
    cout << a.longestDiverseString(1,1,7) << endl;
    return 0;
}
