class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        l = [[False] * len(image[0]) for i in range(len(image))]

        def fF(r, c):
            if l[r][c]:
                return
            l[r][c] = True
            if r > 0 and image[r][c] == image[r - 1][c]:
                fF(r - 1, c)
            if c > 0 and image[r][c] == image[r][c - 1]:
                fF(r, c - 1)
            if r < len(image) - 1 and image[r][c] == image[r + 1][c]:
                fF(r + 1, c)
            if c < len(image[0]) - 1 and image[r][c] == image[r][c + 1]:
                fF(r, c + 1)
            image[r][c] = newColor

        fF(sr, sc)
        return image


sol = Solution()
print(sol.floodFill([[1, 1, 1], [1, 1, 0], [1, 0, 1]], 1, 1, 2))
