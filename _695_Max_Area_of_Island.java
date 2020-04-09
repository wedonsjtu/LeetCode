class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        boolean[][] isVisited = new boolean[grid.length][grid[0].length];
        int ans = 0;
        for (int i=0; i < grid.length; ++i) {
            for (int j=0; j < grid[0].length; ++j) {
                ans = Math.max(ans, area(grid, isVisited, i, j));
            }
        }
        return ans;
    }

    private int area(int[][] grid, boolean[][] isVisited, int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || isVisited[r][c] || grid[r][c] == 0) return 0;
        isVisited[r][c] = true;
        return 1 + area(grid, isVisited, r-1, c)
                 + area(grid, isVisited, r+1, c)
                 + area(grid, isVisited, r, c-1)
                 + area(grid, isVisited, r, c+1);
    }
}

public class _695_Max_Area_of_Island {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] grid = {{1,1,1,0},{0,1,1,0}};
        System.out.println(s.maxAreaOfIsland(grid));
    }
}
