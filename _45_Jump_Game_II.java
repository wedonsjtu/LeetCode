class Solution {
    public int jump(int[] nums) {
        int last = 0;
        int ans = 0;
        int can_jump = 0;
        for (int i=0; i < nums.length-1; ++i) {
            can_jump = Math.max(can_jump, i + nums[i]);
            if (i == last) {
                ans++;
                last = can_jump;
                if (last >= nums.length-1) return ans;
            }
        }
        return ans;
    }
}

public class _45_Jump_Game_II {
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
        Solution s = new Solution();
        System.out.println(s.jump(nums));
    }
}
