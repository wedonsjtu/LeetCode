class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n == 0:
            return []
        res = [[0] * n for i in range(n)]
        r = 0
        c = 0
        i = 1
        d = 'r'
        while True:
            res[r][c] = i
            i += 1
            if d == 'r':
                if c + 1 < n and not res[r][c + 1]:
                    c += 1
                    continue
                else:
                    d = 'd'
                    if r + 1 < n and not res[r + 1][c]:
                        r += 1
                        continue
                    return res
            if d == 'd':
                if r + 1 < n and not res[r + 1][c]:
                    r += 1
                    continue
                else:
                    d = 'l'
                    if c - 1 >= 0 and not res[r][c - 1]:
                        c -= 1
                        continue
                    return res
            if d == 'l':
                if c - 1 >= 0 and not res[r][c - 1]:
                    c -= 1
                    continue
                else:
                    d = 'u'
                    if r - 1 >= 0 and not res[r - 1][c]:
                        r -= 1
                        continue
                    return res
            if d == 'u':
                if r - 1 >= 0 and not res[r - 1][c]:
                    r -= 1
                    continue
                else:
                    d = 'r'
                    if c + 1 < n and not res[r][c + 1]:
                        c += 1
                        continue
                    return res


sol = Solution()
for ii in range(5):
    print(sol.generateMatrix(ii))
