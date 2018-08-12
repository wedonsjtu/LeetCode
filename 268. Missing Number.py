class Solution:
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len(nums) * (len(nums) + 1) // 2 - sum(nums)


sol = Solution()
print(sol.missingNumber([9, 6, 4, 2, 3, 5, 7, 0, 1]))
print(sol.missingNumber([0]))
