class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        if not A:
            return []
        return [[row[i] for row in A] for i in range(len(A[0]))]


sol = Solution()
print(sol.transpose([[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]))
print(sol.transpose([[1, 5, 9]]))
print(sol.transpose([[1], [5], [9]]))
print(sol.transpose([]))
print(sol.transpose([[1]]))
