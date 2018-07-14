class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return [[]]
        if len(nums) == 1:
            return [nums, []]
        l1 = self.subsetsWithDup(nums[1:])
        le = len(l1)
        for i in range(le):
            l3 = sorted([nums[0]] + l1[i])
            if l3 not in l1:
                l1.append(l3)
        return l1


sol = Solution()
print(sol.subsetsWithDup([1, 2, 2, 3]))
print(sol.subsetsWithDup([1, 2, 3]))
print(sol.subsetsWithDup([1, 2]))
