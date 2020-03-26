#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> row_v(rows, INT_MAX), col_v(cols, 0);
        vector<int> row_index(rows, -1), col_index(cols, -1);
        for (int i=0; i < rows; ++i) {
            for (int j=0; j < cols; ++j) {
                if (row_v[i] > matrix[i][j]) {
                    row_v[i] = matrix[i][j];
                    row_index[i] = j;
                }
                if (col_v[j] < matrix[i][j]) {
                    col_v[j] = matrix[i][j];
                    col_index[j] = i;
                }
            }
        }
        int row = 0, col = 0;
        for (int i=0; i < rows; ++i) {
            row = i;
            col = row_index[i];
            if (col_index[col] == row) res.push_back(row_v[row]);
        }
        return res;
    }
};
