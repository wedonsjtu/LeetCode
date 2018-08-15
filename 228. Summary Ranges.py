class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
            return []
        ans = [str(nums[0])]
        h = nums[0]
        f = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == f + 1:
                f = nums[i]
                if i == len(nums) - 1 and h != f:
                    ans[-1] += "->" + str(f)
            else:
                if h != f:
                    ans[-1] += "->" + str(f)
                ans.append(str(nums[i]))
                h = nums[i]
                f = nums[i]
        return ans


sol = Solution()
print(sol.summaryRanges([]))
print(sol.summaryRanges([7]))
print(sol.summaryRanges([0, 1, 2, 4, 5, 7]))
print(sol.summaryRanges([0, 2, 3, 4, 6, 8, 9]))
print(sol.summaryRanges([0, 1, 2, 3, 4, 5, 6]))
