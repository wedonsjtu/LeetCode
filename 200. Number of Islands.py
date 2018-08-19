class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        g = [[False] * len(grid[0]) for i in range(len(grid))]

        def nI(x, y):
            if g[x][y]:
                return 0
            g[x][y] = True
            if grid[x][y] == '0':
                return 0
            if x != 0:
                nI(x - 1, y)
            if x != len(grid) - 1:
                nI(x + 1, y)
            if y != 0:
                nI(x, y - 1)
            if y != len(grid[0]) - 1:
                nI(x, y + 1)
            return 1

        ans = 0
        for i in range(len(g)):
            for j in range(len(g[0])):
                if g[i][j]:
                    continue
                ans += nI(i, j)
        return ans


sol = Solution()
print(sol.numIslands([["1", "1", "1", "1", "0"],
                      ["1", "1", "0", "1", "0"],
                      ["1", "1", "0", "0", "0"],
                      ["0", "0", "0", "0", "0"]]))  # 1
print(sol.numIslands([["1", "1", "0", "1", "0"],
                      ["1", "1", "0", "1", "0"],
                      ["1", "1", "0", "0", "0"],
                      ["0", "0", "0", "0", "0"]]))  # 1
print(sol.numIslands([["0", "1", "0", "1", "0"],
                      ["1", "0", "0", "1", "0"],
                      ["1", "1", "0", "0", "0"],
                      ["0", "0", "0", "0", "0"]]))  # 1
