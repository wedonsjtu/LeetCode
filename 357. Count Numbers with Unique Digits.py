class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """

        def f(x):
            ans = 1
            while x > 0:
                ans *= x
                x -= 1
            return ans

        if n == 0:
            return 1
        if n == 1:
            return 10
        if n > 10:
            n = 10
        return self.countNumbersWithUniqueDigits(n - 1) + 9 * f(9) // f(9 - n + 1)


sol = Solution()
for i in range(16):
    print(sol.countNumbersWithUniqueDigits(i))
