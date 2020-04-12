class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        len1 = len(candies) // 2
        len2 = len(set(candies))
        if len1 <= len2:
            return len1
        return len2


sol = Solution()
print(sol.distributeCandies([1,2,3,3]))
print(sol.distributeCandies([1,2,3,4]))
print(sol.distributeCandies([1,2,3,2,2,2,2,2,2,2,2]))
