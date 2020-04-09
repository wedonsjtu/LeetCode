import java.util.*;

class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> res = new LinkedList<>();
        if (matrix.length == 0 || matrix[0].length == 0) return res;
        boolean[][] pacific = new boolean[matrix.length][matrix[0].length];
        boolean[][] atlantic = new boolean[matrix.length][matrix[0].length];
        for (int i=0; i < matrix.length; ++i) {
            search(matrix, pacific, i, 0);
            search(matrix, atlantic, i, matrix[0].length - 1);
        }
        for (int i=0; i < matrix[0].length; ++i) {
            search(matrix, pacific, 0, i);
            search(matrix, atlantic, matrix.length - 1, i);
        }
        for (int i=0; i < matrix.length; ++i) {
            for (int j=0; j < matrix[0].length; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    List<Integer> tmp = new LinkedList<>();
                    tmp.add(i);
                    tmp.add(j);
                    res.add(tmp);
                }
            }
        }
        return res;
    }

    private void search(int[][] matrix, boolean[][] ocean, int r, int c) {
        if (r < 0 || r >= matrix.length || c < 0 || c >= matrix[0].length || ocean[r][c]) return;
        ocean[r][c] = true;
        if (r > 0 && matrix[r][c] <= matrix[r-1][c]) search(matrix, ocean, r-1, c);
        if (r < matrix.length - 1 && matrix[r][c] <= matrix[r+1][c]) search(matrix, ocean, r+1, c);
        if (c > 0 && matrix[r][c] <= matrix[r][c-1]) search(matrix, ocean, r, c-1);
        if (c < matrix[0].length - 1 && matrix[r][c] <= matrix[r][c+1]) search(matrix, ocean, r, c+1);
    }
}

public class _417_Pacific_Atlantic_Water_Flow {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
        System.out.println(s.pacificAtlantic(matrix));
    }
}
