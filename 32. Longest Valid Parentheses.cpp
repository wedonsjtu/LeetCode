#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int ans = 0;
        for (char ch: s) {
            if (ch == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                ans = max(ans, left + right);
            } else if (left < right) {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for (int i=s.size()-1; i >= 0; --i) {
            char ch = s[i];
            if (ch == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                ans = max(ans, left + right);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().longestValidParentheses(")()())");
    cout << ans << endl;
    return 0;
}
