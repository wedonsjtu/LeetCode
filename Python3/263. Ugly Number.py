class Solution:
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        for f in (2, 3, 5):
            while num % f == 0:
                num //= f
        return num == 1


sol = Solution()
print(sol.isUgly(6))
print(sol.isUgly(8))
print(sol.isUgly(14))
