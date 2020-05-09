#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 1 <= m, n <= 100
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int zeros, ones;
        for (string str: strs) {
            zeros = 0;
            ones = 0;
            for (char ch: str) {
                if (ch == '1') ++ones;
                else ++zeros;
            }
            for (int i=m; i >= zeros; --i) {
                for (int j=n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<string> v{"10","0001","111001","1","0"};
    cout << Solution().findMaxForm(v, 5, 3) << endl;
    return 0;
}
