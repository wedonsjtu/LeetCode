class Solution:
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        from bisect import insort
        list1 = []
        for t1 in timePoints:
            t2 = int(t1[:2]) * 60 + int(t1[3:])
            insort(list1, t2)
            if t2 <= 720:
                insort(list1, t2 + 1440)
        ans = list1[1] - list1[0]
        for i in range(1, len(list1) - 1):
            ans = min(ans, list1[i + 1] - list1[i])
        return ans


sol = Solution()
print(sol.findMinDifference(["23:59", "00:00"]))
print(sol.findMinDifference(["23:59", "12:00", "00:00"]))
