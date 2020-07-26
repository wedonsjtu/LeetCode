#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int ans = 0;
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i=0; i < matrix.size(); ++i) {
            for (int j=0; j < matrix[0].size(); ++j) {
                backtracking(matrix, m, i, j, ans);
            }
        }
        return ans;
    }
    
private:
    int backtracking(const vector<vector<int>>& matrix, vector<vector<int>>& m, int r, int c, int &ans) {
        if (m[r][c] != 0) {
            return m[r][c];
        }
        int left = 0, right = 0, up = 0, down = 0;
        if (r < matrix.size() && r >= 0 && 
            c-1 < matrix[0].size() && c-1 >= 0 && 
            matrix[r][c-1] > matrix[r][c]) {
                left = backtracking(matrix, m, r, c-1, ans);
        }
        if (r < matrix.size() && r >= 0 && 
            c+1 < matrix[0].size() && c+1 >= 0 && 
            matrix[r][c+1] > matrix[r][c]) {
                right = backtracking(matrix, m, r, c+1, ans);
        }
        if (r-1 < matrix.size() && r-1 >= 0 && 
            c < matrix[0].size() && c >= 0 && 
            matrix[r-1][c] > matrix[r][c]) {
                up = backtracking(matrix, m, r-1, c, ans);
        }
        if (r+1 < matrix.size() && r+1 >= 0 && 
            c < matrix[0].size() && c >= 0 && 
            matrix[r+1][c] > matrix[r][c]) {
                down = backtracking(matrix, m, r+1, c, ans);
        }
        m[r][c] = 1 + max(left, max(right, max(up, down)));
        ans = max(ans, m[r][c]);
        return m[r][c];
    }
};

int main() {
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};
    auto ans = Solution().longestIncreasingPath(matrix);
    cout << ans << endl;
    return 0;
}
