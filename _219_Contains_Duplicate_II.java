import java.util.*;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> s = new HashMap<>();
        for (int i=0; i < nums.length; ++i) {
            if (s.containsKey(nums[i]) && i-s.get(nums[i]) <= k) {
                return true;
            }
            else {
                s.put(nums[i], i);
            }
        }
        return false;
    }
}

public class _219_Contains_Duplicate_II {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1,2,3,1};
        System.out.println(s.containsNearbyDuplicate(nums, 1));
        System.out.println(s.containsNearbyDuplicate(nums, 3));
    }
}
