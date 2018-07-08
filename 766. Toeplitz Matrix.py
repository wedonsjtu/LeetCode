class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        if len(matrix) <= 1 or len(matrix[0]) <= 1:
            return True
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][j] != matrix[i-1][j-1]:
                    return False
        return True


sol = Solution()
print(sol.isToeplitzMatrix([[1,2,3,4],[5,1,2,3],[9,5,1,2]]))
print(sol.isToeplitzMatrix([[1,2,3,4],[5,1,2,3]]))
print(sol.isToeplitzMatrix([[1,2,3,4]]))
print(sol.isToeplitzMatrix([[1,2,32,4],[5,1,2,3],[9,5,1,2]]))
