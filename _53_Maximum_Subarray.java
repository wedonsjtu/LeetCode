class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int tmp = 0;
        for (int num: nums) {
            tmp += num;
            ans = Math.max(ans, tmp);
            if (tmp < 0) tmp = 0;
        }
        return ans;
    }
}

public class _53_Maximum_Subarray {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(s.maxSubArray(nums));
    }
}
