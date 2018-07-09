class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        a = n ^ (n >> 1)
        return not a & (a & (a + 1))


sol = Solution()
print(sol.hasAlternatingBits(5))
print(sol.hasAlternatingBits(0b10101))
print(sol.hasAlternatingBits(0b101101))
print(sol.hasAlternatingBits(0b1011101))
