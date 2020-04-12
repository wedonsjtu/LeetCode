import copy


class Solution:
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        if not M:
            return M
        m = copy.deepcopy(M)
        for i in range(len(M)):
            for j in range(len(M[0])):
                a1 = 1
                a2 = M[i][j]
                if 0 < i < len(M) - 1 and 0 < j < len(M[0]) - 1:
                    a1 = 9
                    a2 += (M[i - 1][j - 1] + M[i - 1][j] + M[i - 1][j + 1] +
                           M[i][j - 1] + M[i][j + 1] +
                           M[i + 1][j - 1] + M[i + 1][j] + M[i + 1][j + 1])
                    m[i][j] = a2 // a1
                    continue
                if i > 0 and j > 0:
                    a1 += 1
                    a2 += M[i - 1][j - 1]
                if i > 0:
                    a1 += 1
                    a2 += M[i - 1][j]
                if i > 0 and j < len(M[0]) - 1:
                    a1 += 1
                    a2 += M[i - 1][j + 1]
                if j > 0:
                    a1 += 1
                    a2 += M[i][j - 1]
                if j < len(M[0]) - 1:
                    a1 += 1
                    a2 += M[i][j + 1]
                if i < len(M) - 1 and j > 0:
                    a1 += 1
                    a2 += M[i + 1][j - 1]
                if i < len(M) - 1:
                    a1 += 1
                    a2 += M[i + 1][j]
                if i < len(M) - 1 and j < len(M[0]) - 1:
                    a1 += 1
                    a2 += M[i + 1][j + 1]
                m[i][j] = a2 // a1
        return m


sol = Solution()
print(sol.imageSmoother([[1, 1, 1], [1, 0, 1], [1, 1, 1]]))
print(sol.imageSmoother([]))
print(sol.imageSmoother([[]]))
print(sol.imageSmoother([[1]]))
