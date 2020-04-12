class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        ans = 0
        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                continue
            if ((i > 0 and flowerbed[i - 1] != 1) or i == 0) and \
                ((i < len(flowerbed) - 1 and flowerbed[i + 1] != 1) or
                 i == len(flowerbed) - 1):
                ans += 1
                if ans >= n:
                    return True
                flowerbed[i] = 1
        return ans >= n


sol = Solution()
print(sol.canPlaceFlowers([1, 0, 0, 0, 1], 1))
print(sol.canPlaceFlowers([1, 0, 0, 0, 1], 2))
print(sol.canPlaceFlowers([1, 0, 0, 0], 2))
print(sol.canPlaceFlowers([1, 0, 0, 1], 2))
