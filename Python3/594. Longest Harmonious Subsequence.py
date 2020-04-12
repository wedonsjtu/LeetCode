class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        ans = 0
        for i in d:
            if i+1 in d:
                ans = max(ans, d[i] + d[i + 1])
        return ans


sol = Solution()
print(sol.findLHS([1, 3, 2, 2, 5, 2, 3, 7]))
print(sol.findLHS([]))
print(sol.findLHS([1]))
print(sol.findLHS([1, 1]))
print(sol.findLHS([1, 2]))
