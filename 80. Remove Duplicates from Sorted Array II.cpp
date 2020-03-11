class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        int i, j = 1, count = 1;
        for (int i=1; i < len; ++i) {
            if (nums[i] == nums[i-1]) ++count;
            else count = 1;
            if (count <= 2) {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};