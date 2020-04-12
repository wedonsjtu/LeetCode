class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        sx = bin(x)
        sy = bin(y)
        lx = len(sx)-2
        ly = len(sy)-2
        a = 0
        if lx > ly:
            for i in range(ly):
                if sx[-i-1] != sy[-i-1]:
                    a += 1
            for i in range(2, lx - ly + 2):
                if sx[i] == '1':
                    a += 1
        else:
            for i in range(lx):
                if sx[-i-1] != sy[-i-1]:
                    a += 1
            for i in range(2, ly - lx + 2):
                if sy[i] == '1':
                    a += 1
        return a


sol = Solution()
print(sol.hammingDistance(1, 8))