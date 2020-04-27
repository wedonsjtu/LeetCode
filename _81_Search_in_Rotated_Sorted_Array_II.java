class Solution {
    public boolean search(int[] nums, int target) {
        // [1,1,3,1] 3 should be true
        if (nums.length == 0) return false;
        int begin = 0, end = nums.length - 1, mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[mid] == target) return true;
            if (nums[begin] == nums[mid]) ++begin;
            else if (nums[mid] > nums[end]) {
                if (target < nums[begin] || target >= nums[mid]) begin = mid + 1;
                else end = mid - 1;
            }
            else {
                if (nums[mid] < target && target <= nums[end]) begin = mid + 1;
                else end = mid - 1;
            }
        }

        return false;
    }
}

public class _81_Search_in_Rotated_Sorted_Array_II {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {1,1,3,1};
        System.out.println(s.search(a, 1));
    }
}
