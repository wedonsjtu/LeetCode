class Solution:
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        l1 = sorted(list(enumerate(nums)), key=lambda x: x[1], reverse=True)
        ans = [""] * len(nums)
        for i in range(len(l1)):
            if i == 0:
                ans[l1[i][0]] = "Gold Medal"
            elif i == 1:
                ans[l1[i][0]] = "Silver Medal"
            elif i == 2:
                ans[l1[i][0]] = "Bronze Medal"
            else:
                ans[l1[i][0]] = str(i + 1)
        return ans


sol = Solution()
print(sol.findRelativeRanks([4, 6, 1, 3]))
print(sol.findRelativeRanks([]))
print(sol.findRelativeRanks([1]))
print(sol.findRelativeRanks([2, 1]))
