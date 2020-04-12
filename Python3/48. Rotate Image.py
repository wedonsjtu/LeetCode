class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        def r(x, y):
            if y == 0 or y == 1:
                return
            for i in range(x, x + y - 1):
                matrix[x][i], matrix[i][x + y - 1], \
                matrix[x + y - 1][2 * x + y - i - 1], matrix[2 * x + y - i - 1][x] \
                    = matrix[2 * x + y - i - 1][x], matrix[x][i], \
                      matrix[i][x + y - 1], matrix[x + y - 1][2 * x + y - i - 1]
            r(x + 1, y - 2)

        r(0, n)


sol = Solution()
l1 = [[1, 2], [3, 4]]
sol.rotate(l1)
print(l1)
l1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
sol.rotate(l1)
print(l1)
l1 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
sol.rotate(l1)
print(l1)
