import java.util.Arrays;

class Solution {
    public boolean increasingTriplet(int[] nums) {
        int[] dp = new int[3];
        int len = 0, i;
        for (int num: nums) {
            if (len == 0 || num <= dp[0]) i = 0;
            else if (len == 1 || num <= dp[1]) i = 1;
            else i = 2;
            
            // i is the insertion point
            dp[i] = num;
            if (i == len) ++len;
            if (len == 3) return true;
        }
        return false;
    }
}

public class _334_Increasing_Triplet_Subsequence {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {15,1,5,4,2,1,3};
        System.out.println(s.increasingTriplet(a));
    }
}
