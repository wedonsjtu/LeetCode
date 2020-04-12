class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        g = [[False] * len(grid[0]) for i in range(len(grid))]

        def mAOI(x, y):
            if g[x][y]:
                return 0
            g[x][y] = True
            if grid[x][y] == 0:
                return 0
            res = 1
            if x != 0:
                res += mAOI(x - 1, y)
            if x != len(grid) - 1:
                res += mAOI(x + 1, y)
            if y != 0:
                res += mAOI(x, y - 1)
            if y != len(grid[0]) - 1:
                res += mAOI(x, y + 1)
            return res

        ans = 0
        for i in range(len(g)):
            for j in range(len(g[0])):
                if g[i][j]:
                    continue
                ans = max(ans, mAOI(i, j))
        return ans


sol = Solution()
print(sol.maxAreaOfIsland([[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                           [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                           [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                           [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
                           [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
                           [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                           [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                           [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]))
