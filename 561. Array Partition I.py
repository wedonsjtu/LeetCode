class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = sorted(nums)
        s = 0
        for i in range(len(a) // 2):
            s += a[2*i]
        return s


sol = Solution()
l = [3, 1, 5, 6, 4, 4, 3, 2]
print(sol.arrayPairSum(l))