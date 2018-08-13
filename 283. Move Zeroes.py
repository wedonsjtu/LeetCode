class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i] = nums[j]
                i += 1
        for j in range(i, len(nums)):
            nums[j] = 0


sol = Solution()
l1 = [2, 5, 0, 3, 0, 3, 0]
sol.moveZeroes(l1)
print(l1)
l1 = [2, 5, 3, 0, 0]
sol.moveZeroes(l1)
print(l1)
