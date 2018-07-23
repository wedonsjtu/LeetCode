class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        i = 1
        j = 10
        ii = 1
        jj = 100
        while True:
            if x == ii:
                return i
            if ii < x < jj:
                break
            i *= 10
            j *= 10
            ii *= 100
            jj *= 100

        def mS(y, f, l):
            mid = (f + l) // 2
            mid2 = mid ** 2
            if mid2 == y:
                return mid
            fmid2 = (mid - 1) ** 2
            if fmid2 <= y < mid2:
                return (mid - 1)
            elif mid2 < y:
                return mS(y, mid, l)
            return mS(y, f, mid)

        return mS(x, i, j)


sol = Solution()
print(sol.mySqrt(756745345234867876757454653))
print(sol.mySqrt(2))
print(sol.mySqrt(43))
print(sol.mySqrt(49))
print(sol.mySqrt(361))
