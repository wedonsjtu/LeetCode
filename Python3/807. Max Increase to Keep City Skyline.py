class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid == [] or grid[0] == []:
            return 0
        r = len(grid)
        c = len(grid[0])
        r1 = [0] * r
        c1 = [0] * c
        for i in range(r):
            r1[i] = max(grid[i])
        for j in range(c):
            c1[j] = max([grid[i][j] for i in range(r)])
        ans = 0
        for i in range(r):
            for j in range(c):
                ans += (min(r1[i], c1[j]) - grid[i][j])
        return ans


sol = Solution()
l = [[3, 0, 8, 4], [2, 4, 5, 7], [9, 2, 6, 3], [0, 3, 1, 0]]
print(sol.maxIncreaseKeepingSkyline(l))
