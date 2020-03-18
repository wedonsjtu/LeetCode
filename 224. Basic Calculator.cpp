#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long ans = 0, num = 0;
        int sign = +1;  // positive +1 negative -1
        for (char ch: s) {
            switch (ch) {
            case ' ':  // ignore space
                break;
            case '+':
                ans += num * sign;
                sign = +1;
                num = 0;
                break;
            case '-':
                ans += num * sign;
                sign = -1;
                num = 0;
                break;
            case '(':
                st.push(ans);
                st.push((long long)sign);
                ans = 0;
                num = 0;
                sign = +1;
                break;
            case ')':
                ans += num * sign;
                sign = st.top();
                st.pop();
                ans = st.top() + sign * ans;
                st.pop();
                sign = +1;
                num = 0;
                break;
            default:  // digit
                num = num * 10 + (ch - '0');
                break;
            }
        }
        return ans + sign * num;
    }
};

int main() {
    Solution a;
    cout << a.calculate("1+2+3+4+5") << endl;
    cout << a.calculate("1+2+3+(4+5)") << endl;
    cout << a.calculate("1+(-2)+3+(4+5)") << endl;
    cout << a.calculate("1-(2+2+4)+5") << endl;
    cout << a.calculate("1+2+3-(4+5)") << endl;
    cout << a.calculate("(-1+2+3-4+5)") << endl;
    return 0;
}
