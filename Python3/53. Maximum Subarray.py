class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        tmp = nums[0]
        ans = nums[0]
        for v in nums[1:]:
            tmp = tmp + v if tmp + v > v else v
            ans = max(tmp, ans)
        return ans


sol = Solution()
print(sol.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
print(sol.maxSubArray([-2]))
