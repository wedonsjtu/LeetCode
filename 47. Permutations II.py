class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return []
        if len(nums) == 1:
            return [nums]
        ans = [()]
        for i in range(len(nums)):
            le = len(ans)
            l = 0
            while l < le:
                l1 = list(ans.pop(0))
                l1.insert(0, nums[i])
                if tuple(l1) not in ans:
                    ans.append(tuple(l1))
                for j in range(len(l1) - 1):
                    l1[j], l1[j+1] = l1[j+1], l1[j]
                    if tuple(l1) not in ans:
                        ans.append(tuple(l1))
                l += 1
        return [list(x) for x in ans]


sol = Solution()
print(sol.permuteUnique([]))
print(sol.permuteUnique([11]))
print(sol.permuteUnique([11, 11, 22]))
print(sol.permuteUnique([11, 11, 22, 11]))
print(sol.permuteUnique([11, 22, 33]))
print(sol.permuteUnique([11, 22, 33, 22, 11]))
