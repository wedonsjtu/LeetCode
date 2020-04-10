import java.util.Arrays;

class Solution {
    public void setZeroes(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        int rows = matrix.length, cols = matrix[0].length;
        boolean firstColWithZero = false;
        for (int i=0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                firstColWithZero = true;
            }
            for (int j=1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i=1; i < rows; ++i) {
            for (int j=1; j < cols; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int j=0; j < cols; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (firstColWithZero) {
            for (int i=0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
}

public class _73_Set_Matrix_Zeroes {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] a = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        s.setZeroes(a);
        for (int[] r: a) System.out.println(Arrays.toString(r));
    }
}
