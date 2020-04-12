class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        B = []
        for i in range(len(A)):
            B.append(A[i][::-1])
            for j in range(len(B[i])):
                B[i][j] = 1 - B[i][j]
        return B


sol = Solution()
l = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
l = [[1],[1]]
print(sol.flipAndInvertImage(l))