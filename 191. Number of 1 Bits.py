class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n != 0:
            ans += n & 1
            n >>= 1
        return ans


sol = Solution()
print(sol.hammingWeight(0))
print(sol.hammingWeight(1))
print(sol.hammingWeight(11))
print(sol.hammingWeight(128))
