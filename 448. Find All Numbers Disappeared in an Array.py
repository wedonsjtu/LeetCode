class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for i in nums:
            while i != nums[i - 1]:
                nums[i - 1], i = i, nums[i - 1]
        for i in range(len(nums)):
            if nums[i] != i + 1:
                ans.append(i + 1)
        return ans


sol = Solution()
print(sol.findDisappearedNumbers([4, 3, 2, 7, 8, 2, 3, 1]))
