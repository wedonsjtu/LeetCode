#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int i, j, rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> ans = matrix;
        for (i=0; i < rows; ++i) {
            for (j=0; j < cols; ++j) {
                if (ans[i][j] == 0) continue;
                ans[i][j] = INT_MAX-1;
                if (i > 0) ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                if (j > 0) ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
            }
        }
        for (j = cols - 1; j >= 0; --j) {
            for (i = rows - 1; i >= 0; --i) {
                if (ans[i][j] == 0) continue;
                if (i < rows - 1) ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                if (j < cols - 1) ans[i][j] = min(ans[i][j], ans[i][j+1] + 1);
            }
        }
        return ans;
    }
};