#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long ans = 0, left_num = 0, right_num = 0;
        char op = '+';
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            right_num = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                if (s[i] == ' ') {
                    ++i;
                    continue;
                }
                right_num = right_num * 10 + (s[i] - '0');
                ++i;
            }
            switch (op)
            {
            case '+':
                ans += left_num;
                left_num = right_num;
                break;
            case '-':
                ans += left_num;
                left_num = -right_num;
                break;
            case '*':
                left_num *= right_num;
                break;
            case '/':
                left_num /= right_num;
                break;
            default:
                break;
            }
            if (i < s.size()) op = s[i++];  // new operator
        }
        return ans + left_num;
    }
};

int main() {
    Solution a;
    cout << a.calculate("-1") << endl;
    cout << a.calculate("1*2") << endl;
    cout << a.calculate("3/2") << endl;
    cout << a.calculate("1-3+4-24+34+2") << endl;
    cout << a.calculate("1*32/3+343*324-2342*123/324+21-13-12*3") << endl;
    cout << a.calculate("-1+2-3+4-5+6") << endl;
    cout << a.calculate("1-2+3-4+5-6") << endl;
    return 0;
}
