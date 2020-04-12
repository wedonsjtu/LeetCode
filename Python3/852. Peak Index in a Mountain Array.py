class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def pIIMA(B, f, l):
            len1 = len(B)
            if len1 <= 1:
                return f
            if len1 == 2:
                return f if B[0] > B[1] else l
            if B[0] > B[1]:
                return f
            if B[-1] > B[-2]:
                return l
            if len1 == 3:
                return f + 1
            if B[len1//2 - 1] > B[len1 // 2]:
                return pIIMA(B[:len1//2], f, f + len1//2 - 1)
            return pIIMA(B[len1//2:], f + len1//2, l)

        return pIIMA(A, 0, len(A)-1)


sol = Solution()
l = [1,2,3,4,4.4,5.5,5,3,1,0,-1]
print(sol.peakIndexInMountainArray(l))