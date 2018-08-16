class Solution:
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        i = 0
        while m != n:
            m >>= 1
            n >>= 1
            i += 1
        return m << i


sol = Solution()
print(sol.rangeBitwiseAnd(4, 7))
print(sol.rangeBitwiseAnd(5, 7))
print(sol.rangeBitwiseAnd(0, 1))
