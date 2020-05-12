class Solution {
    public int singleNonDuplicate(int[] nums) {
        int begin=0, end=nums.length-1;
        int mid;
        while (begin <= end) {
            mid = begin + (end - begin) / 2;
            if (mid % 2 == 0 && mid + 1 < nums.length && nums[mid] == nums[mid+1] ||
               mid % 2 == 1 && mid - 1 >= 0 && nums[mid] == nums[mid-1]) {
                begin = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return nums[begin];
    }
}

public class _540_Single_Element_in_a_Sorted_Array {
    public static void main(String[] args) {
        int[] li = {1,1,2,2,3,3,4,4,5,5,6};
        Solution s = new Solution();
        System.out.println(s.singleNonDuplicate(li));
    }
}
