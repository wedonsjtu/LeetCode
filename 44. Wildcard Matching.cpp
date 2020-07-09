#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sp = 0, pp = 0, stars = -1, starp = -1;
        while (sp < s.size()) {
            if (pp < p.size() && (p[pp] == '?' || p[pp] == s[sp])) {
                    ++sp;
                    ++pp;
            }
            else if (pp < p.size() && p[pp] == '*') {
                starp = pp;
                stars = sp;
                ++pp;
            }
            else if (starp != -1) {
                pp = starp + 1;
                ++stars;
                sp = stars;
            }
            else {
                return false;
            }
        }
        
        while (pp < p.size() && p[pp] == '*') ++pp;
        return pp == p.size();
        
        // Method with DP:
        // vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        // dp[0][0] = true;
        // for (int i=1; i <= p.size(); ++i) {
        //     if (p[i-1] == '*') {
        //         dp[0][i] = true;
        //     }
        //     else {
        //         break;  // Other dp[0][i+1] is false.
        //     }
        // }
        // // dp[i][0] (i != 0) is false;
        // for (int i=1; i < dp.size(); ++i) {
        //     for (int j=1; j < dp[0].size(); ++j) {
        //         if ((s[i-1] == p[j-1]) || (p[j-1] == '?')) {
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //         else if (p[j-1] == '*') {
        //             dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[s.size()][p.size()];
    }
};

int main() {
    string s("acdcb");
    string p("a*c?b");
    auto ans = Solution().isMatch(s, p);
    cout << boolalpha << s << ' ' << p << ' ' << ans << endl;
    return 0;
}
