class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        len1 = len(seats)
        left = [len1] * len1
        right = [len1] * len1
        for i in range(len1):
            if seats[i] == 1:
                left[i] = 0
            elif i > 0:
                left[i] = left[i - 1] + 1
        for i in range(len1 - 1, -1, -1):
            if seats[i] == 1:
                right[i] = 0
            elif i < len1 - 1:
                right[i] = right[i + 1] + 1
        return max(min(left[i], right[i]) for i, seat in enumerate(seats) if not seat)


sol = Solution()
print(sol.maxDistToClosest([1, 0, 0, 0, 1, 0, 1]))
print(sol.maxDistToClosest([1, 0, 0, 0]))
