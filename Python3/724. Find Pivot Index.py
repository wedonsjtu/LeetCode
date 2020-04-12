class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        if len(nums) == 1:
            return 0
        left = 0
        right = sum(nums)
        for i in range(len(nums)):
            if i != 0:
                left += nums[i - 1]
            right -= nums[i]
            if left == right:
                return i
        return -1


sol = Solution()
print(sol.pivotIndex([1, 7, 3, 6, 5, 6]))
print(sol.pivotIndex([1, 7]))
print(sol.pivotIndex([1, 2, 1]))
print(sol.pivotIndex([1, -1, 2]))
print(sol.pivotIndex([1]))
print(sol.pivotIndex([]))
