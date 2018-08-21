class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    for jj in range(len(matrix[i])):
                        if matrix[i][jj] != 0:
                            matrix[i][jj] = True
                    for ii in range(len(matrix)):
                        if matrix[ii][j] != 0:
                            matrix[ii][j] = True
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] is True:
                    matrix[i][j] = 0


sol = Solution()
l1 = [[1, 1, 1],
      [1, 0, 1],
      [1, 1, 1]]
sol.setZeroes(l1)
print(l1)
l2 = [[0, 1, 2, 0],
      [3, 4, 5, 2],
      [1, 3, 1, 5]]
sol.setZeroes(l2)
print(l2)
