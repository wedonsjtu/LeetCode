class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        ans = []
        m = [[True] * len(matrix[0]) for i in range(len(matrix))]
        r = 0
        c = 0
        d = 'r'
        while True:
            ans.append(matrix[r][c])
            m[r][c] = False
            if d == 'r':
                if c + 1 < len(matrix[0]) and m[r][c + 1]:
                    c += 1
                    continue
                else:
                    d = 'd'
                    if r + 1 < len(matrix) and m[r + 1][c]:
                        r += 1
                        continue
                    return ans
            if d == 'd':
                if r + 1 < len(matrix) and m[r + 1][c]:
                    r += 1
                    continue
                else:
                    d = 'l'
                    if c - 1 >= 0 and m[r][c - 1]:
                        c -= 1
                        continue
                    return ans
            if d == 'l':
                if c - 1 >= 0 and m[r][c - 1]:
                    c -= 1
                    continue
                else:
                    d = 'u'
                    if r - 1 >= 0 and m[r - 1][c]:
                        r -= 1
                        continue
                    return ans
            if d == 'u':
                if r - 1 >= 0 and m[r - 1][c]:
                    r -= 1
                    continue
                else:
                    d = 'r'
                    if c + 1 < len(matrix[0]) and m[r][c + 1]:
                        c += 1
                        continue
                    return ans


sol = Solution()
print(sol.spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
print(sol.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]))
