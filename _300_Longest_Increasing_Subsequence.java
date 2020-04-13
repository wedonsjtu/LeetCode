import java.util.*;

class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0, i;
        for (int num: nums) {
            // https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/Arrays.html#binarySearch(int[],int,int,int)
            // i = Arrays.binarySearch(dp, 0, len, num);
            i = binarySearch(dp, 0, len, num);
            if (i < 0) {  // - insertion_point - 1
                i = -(i + 1);  // insertion_point
            }
            dp[i] = num;
            if (i == len) ++len;
        }
        return len;
    }
    
    private int binarySearch(int[] array, int begin_in, int end_ex, int num) {
        while (begin_in < end_ex) {
            int mid = (begin_in + end_ex - 1) / 2;
            if (num == array[mid]) return mid;
            else if (num > array[mid]) {
                begin_in = mid+1;
            }
            else {
                end_ex = mid;
            }
        }
        return (-begin_in-1);
    }
}

public class _300_Longest_Increasing_Subsequence {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {10,9,2,5,3,7,101,18};
        System.out.println(s.lengthOfLIS(a));
    }
}
