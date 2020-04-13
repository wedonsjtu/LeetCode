import java.util.*;

class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, -1);
        int ans = 0, count = 0;
        for (int i=0; i < nums.length; ++i) {
            if (nums[i] == 1) ++count;
            else --count;
            if (m.containsKey(count)) {
                ans = Math.max(ans, i - m.get(count));
            } else {
                m.put(count, i);
            }
        }
        return ans;
    }
}

public class _525_Contiguous_Array {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {0,1,0,1,0,0,0,0};
        System.out.println(s.findMaxLength(nums));
    }
}
