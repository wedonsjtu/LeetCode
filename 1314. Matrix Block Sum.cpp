#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> csum(mat);
        int rows = mat.size(), cols = mat[0].size();
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                if (i > 0) csum[i][j] += csum[i-1][j];
                if (j > 0) csum[i][j] += csum[i][j-1];
                if (i > 0 && j > 0) csum[i][j] -= csum[i-1][j-1];
            }
        }
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                int xr = min(i+K, rows-1), yr = min(j+K, cols-1);
                ans[i][j] += csum[xr][yr];
                int x = i-K-1, y = j-K-1;
                if (x >= 0 && y >= 0) ans[i][j] += (csum[x][y] - csum[x][yr] - csum[xr][y]);
                else if (x >= 0 && y < 0) ans[i][j] -= csum[x][yr];
                else if (x < 0 && y >= 0) ans[i][j] -= csum[xr][y];
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
    auto ans = Solution().matrixBlockSum(mat, 2);
    for (auto& i: ans) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
