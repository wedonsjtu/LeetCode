class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() < 2) return;
        int rows = matrix.size(), tmp;
        for (int i=0; i < rows / 2; ++i) {
            for (int j=i; j < rows-i-1; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[rows-j-1][i];
                matrix[rows-j-1][i] = matrix[rows-i-1][rows-j-1];
                matrix[rows-i-1][rows-j-1] = matrix[j][rows-i-1];
                matrix[j][rows-i-1] = tmp;
            }
        }
    }
};
