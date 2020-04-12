class Solution:
    def plus(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if a == 0:
            return b
        if b == 0:
            return a
        while b != 0:
            c = a & b
            a = a ^ b
            b = c << 1
        return a

    def minus(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if a == 0:
            return -b
        if b == 0:
            return a
        while b != 0:
            c = ~a & b
            a = a ^ b
            b = c << 1
        return a

    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        if a == 0:
            return b
        if b == 0:
            return a
        if a > 0 and b > 0:
            return self.plus(a, b)
        if a < 0 and b < 0:
            return -self.plus(-a, -b)
        if a > 0:
            if a > -b:
                return self.minus(a, -b)
            else:
                return -self.minus(-b, a)
        if -a < b:
            return self.minus(b, -a)
        else:
            return -self.minus(-a, b)


sol = Solution()
print(sol.getSum(-23, 56))
print(sol.getSum(-1, -1))
print(sol.getSum(134, -1))
print(sol.getSum(12, 341))
print(sol.getSum(12, -341))
print(sol.getSum(-341, 12))
print(sol.getSum(341, -12))
print(sol.getSum(-341, -12))
print(sol.getSum(2, -2))
print(sol.getSum(-2, 2))
