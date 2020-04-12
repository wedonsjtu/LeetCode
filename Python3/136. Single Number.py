class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for i in nums:
            a ^= i
        return a


sol = Solution()
print(sol.singleNumber([1, 5, 7, 2, 7, 5, 2]))
