class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid == []:
            return 0
        p = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    p += 4
                    if j > 0 and grid[i][j-1] == 1:
                        p -= 1
                    if j < len(grid[0]) - 1 and grid[i][j+1] == 1:
                        p -= 1
                    if i > 0 and grid[i-1][j] == 1:
                        p -= 1
                    if i < len(grid) - 1 and grid[i+1][j] == 1:
                        p -= 1
        return p


sol = Solution()
l = [[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
print(sol.islandPerimeter(l))