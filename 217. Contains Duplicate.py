class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return len(set(nums)) != len(nums)


sol = Solution()
print(sol.containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]))
print(sol.containsDuplicate([1, 2, 3, 4]))
print(sol.containsDuplicate([]))
