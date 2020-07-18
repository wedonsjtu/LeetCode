#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for (int i=0; i <= s1.size(); ++i) {
            for (int j=0; j <= s2.size(); ++j) {
                int p = i + j - 1;
                if (i > 0 && j > 0) {
                    dp[i][j] = ((dp[i-1][j] && (s1[i-1] == s3[p])) || 
                                (dp[i][j-1] && (s2[j-1] == s3[p])));
                } else if (i > 0) {
                    dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[p]));
                } else if (j > 0) {
                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[p]));
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main() {
    cout << boolalpha;
    Solution sol;
    bool ans;
    ans = sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    cout << ans << endl;
    ans = sol.isInterleave("aabcc", "dbbca", "aadbbbaccc");
    cout << ans << endl;
    return 0;
}
