import java.util.*;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.size();
        if (len == 0) return 0;
        int[] res = new int[len];
        res[0] = triangle.get(0).get(0);
        for (int curr = 1; curr < len; ++curr) {
            // end
            res[curr] = res[curr-1] + triangle.get(curr).get(curr);
            // mid
            for (int i = curr-1; i > 0; --i) {
                res[i] = Math.min(res[i], res[i-1]) + 
                            triangle.get(curr).get(i);
            }
            // begin
            res[0] = res[0] + triangle.get(curr).get(0);
        }
        // System.out.println(Arrays.toString(res));
        int min_ans = Integer.MAX_VALUE;
        for (int i=0; i < len; ++i) {
            min_ans = Math.min(min_ans, res[i]);
        }
        // System.out.println();
        return min_ans;
    }
}

public class _120_Triangle {
    public static void main(String[] args) {
        Solution s = new Solution();
        List<List<Integer>> l = Arrays.asList(Arrays.asList(1), Arrays.asList(2,3), Arrays.asList(4,5,6));
        System.out.println(s.minimumTotal(l));
    }
}
