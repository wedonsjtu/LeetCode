class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        f = 0
        l = 1
        m = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                l += 1
            else:
                m = max(m, l - f)
                f = l
                l += 1
        if f != l:
            m = max(m, l - f)
        return m


sol = Solution()
print(sol.findLengthOfLCIS([1, 2, 3, 3, 3]))
print(sol.findLengthOfLCIS([1, 2, 3]))
print(sol.findLengthOfLCIS([1]))
print(sol.findLengthOfLCIS([1, 1, 1]))
