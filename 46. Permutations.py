class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <= 1:
            return [nums]
        ans = [[]]
        for i in range(len(nums)):
            le = len(ans)
            l = 0
            while l < le:
                l1 = ans.pop(0)
                l1.insert(0, nums[i])
                ans.append(l1.copy())
                for j in range(len(l1) - 1):
                    l1[j], l1[j+1] = l1[j+1], l1[j]
                    ans.append(l1.copy())
                l += 1
        return ans


sol = Solution()
print(sol.permute([]))
print(sol.permute([11]))
print(sol.permute([11, 22]))
print(sol.permute([11, 22, 33]))
print(sol.permute([11, 22, 33, 44]))
