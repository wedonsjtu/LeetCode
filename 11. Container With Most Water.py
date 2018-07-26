class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max1 = 0
        l = 0
        r = len(height) - 1
        while l < r:
            minup, where = (height[l], True) \
                if height[l] <= height[r] else (height[r], False)
            max1 = max(max1, (r - l) * minup)
            if where:
                l += 1
            else:
                r -= 1
        return max1


sol = Solution()
print(sol.maxArea([1,8,6,2,5,4,8,3,7]))
