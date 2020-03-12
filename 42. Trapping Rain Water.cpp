class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while (left <= right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (height[left] <= height[right]) {
                ans += (left_max - height[left]);
                ++left;
            }
            else {
                ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
