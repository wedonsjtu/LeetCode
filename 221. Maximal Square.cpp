#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] = min(dp[i-1][j], dp[i-1][j-1],dp[i][j-1])+1
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int* _last = new int[cols]();
        int* _now = new int[cols]();
        int *last = _last, *now = _now, *tmp;
        int ans = 0;
        for (int i=0; i < rows; ++i) {
            if (matrix[i][0] == '1') {
                now[0] = 1;
                ans = max(ans, 1);
            }
            else now[0] = 0;
            for (int j=1; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    now[j] = min(last[j], min(last[j-1], now[j-1])) + 1;
                    ans = max(ans, now[j]);
                }
                else {
                    now[j] = 0;
                }
            }
            tmp = last;
            last = now;
            now = tmp;
        }
        delete[] _last;
        delete[] _now;
        return ans*ans;
    }
};

int main() {
    vector<vector<char>> matrix{vector<char>{'1','1','0','1'}, 
                                vector<char>{'1','1','1','0'}};
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}
