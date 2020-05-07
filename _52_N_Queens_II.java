class Solution {
    // private int ans = 0;
    public int totalNQueens(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        boolean[] cols = new boolean[n];
        boolean[] lu = new boolean[2*n-1];
        boolean[] ru = new boolean[2*n-1];
        return backtracking(n, 0, cols, lu, ru);
        // return ans;
    }
    
    private int backtracking(int n, int r, boolean[] cols, 
                             boolean[] lu, boolean[] ru) {
        int ans = 0;
        if (r == n) {
            return 1;
        }
        for (int c=0; c < n; ++c) {
            if (cols[c] || lu[n-r+c-1] || ru[r+c]) continue;
            cols[c] = true;
            lu[n-r+c-1] = true;
            ru[r+c] = true;
            ans += backtracking(n, r+1, cols, lu, ru);
            cols[c] = false;
            lu[n-r+c-1] = false;
            ru[r+c] = false;
        }
        return ans;
    }
}

public class _52_N_Queens_II {
    public static void main(String[] args) {
        Solution s = new Solution();
        for (int i=1; i <= 10; ++i) {
            System.out.println(Integer.toString(i) + ' ' + s.totalNQueens(i));
        }
    }
}
