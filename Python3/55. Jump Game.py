class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        r = len(nums) - 1
        for i in range(r, -1, -1):
            if i + nums[i] >= r:
                r = i
        return r == 0


sol = Solution()
print(sol.canJump([2, 3, 1, 1, 4]))
print(sol.canJump([3, 2, 1, 0, 4]))
