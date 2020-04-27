#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string s1, s2;
        if (text1.size() >= text2.size()) {
            s2 = text1;
            s1 = text2;
        }
        else {
            s2 = text2;
            s1 = text1;
        }
        // s1 is short
        // s2 is long
        if (s2.size() == 0) return 0;
        int* _last = new int[s2.size()+1]();
        int* _now = new int[s2.size()+1]();
        int *last = _last, *now = _now, *tmp;
        // DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j]
        // DP[i][j] = max(DP[i - 1][j], DP[i][j - 1])
        for (int i=0; i < s1.size(); ++i) {
            for (int j=1; j <= s2.size(); ++j) {
                if (s1[i] == s2[j-1]) {
                    now[j] = last[j-1] + 1;
                }
                else {
                    now[j] = max(last[j], now[j-1]);
                }
            }
            tmp = last;
            last = now;
            now = tmp;
        }
        int ans = last[s2.size()];
        delete[] _last;
        delete[] _now;
        return ans;
    }
};

int main() {
    cout << Solution().longestCommonSubsequence("abcde","acef") << endl;
    cout << Solution().longestCommonSubsequence("abcde", "ace") << endl;
    cout << Solution().longestCommonSubsequence("abc", "abc") << endl;
    cout << Solution().longestCommonSubsequence("abc", "def") << endl;
    cout << Solution().longestCommonSubsequence("abc", "dea") << endl;
    return 0;
}
