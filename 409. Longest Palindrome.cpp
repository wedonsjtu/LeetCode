#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char ch: s) {
            if (m.find(ch) == m.end()) {
                m[ch] = 1;
            }
            else {
                m[ch]++;
            }
        }
        int ans = 0;
        bool isOdd = false;
        int tmp;
        for (auto it=m.begin(); it!=m.end(); ++it) {
            tmp = it->second;
            ans += tmp / 2 * 2;
            if (tmp % 2 == 1) isOdd = true;
        }
        if (isOdd) ans++;
        return ans;
    }
};

int main() {
    cout << Solution().longestPalindrome("abcdddde") << endl;
    return 0;
}
