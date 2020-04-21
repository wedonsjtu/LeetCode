class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int begin = 0, end = nums.length - 1, mid;
        while (begin <= end) {
            mid = (begin + end) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[end]) {
                if (nums[mid] < target || target <= nums[end]) begin = mid + 1;
                else end = mid - 1;
            }
            else {
                if (nums[mid] < target && target <= nums[end]) begin = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
}

public class _33_Search_in_Rotated_Sorted_Array {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.search(new int[]{4,5,6,7,8,1,2,3}, 1));
    }
}
