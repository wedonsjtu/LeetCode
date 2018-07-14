class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return [[]]
        if len(nums) == 1:
            return [nums, []]
        l1 = self.subsets(nums[1:])
        l2 = l1.copy()
        for i in range(len(l2)):
            l2[i] = [nums[0]] + l2[i]
        return l2 + l1


sol = Solution()
print(sol.subsets([1, 2, 3, 4]))
print(sol.subsets([1, 2, 3]))
print(sol.subsets([1, 2]))
print(sol.subsets([1]))
print(sol.subsets([]))
