class Solution:
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        a = 1
        while True:
            if n == a:
                return True
            if n < a:
                return False
            a = a * 2


sol = Solution()
for i in range(100000):
    if sol.isPowerOfTwo(i):
        print(i)
