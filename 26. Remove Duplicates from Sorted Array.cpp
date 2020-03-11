class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;
        int i, j=1;
        for (i=1; i < nums.size(); ++i) {
            if (nums[i-1] != nums[i]) {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};