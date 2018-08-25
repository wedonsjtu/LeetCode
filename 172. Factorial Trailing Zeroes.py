class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n > 0:
            n //= 5
            ans += n
        return ans


sol = Solution()
print(sol.trailingZeroes(3))
print(sol.trailingZeroes(5))
print(sol.trailingZeroes(23))
print(sol.trailingZeroes(100))
