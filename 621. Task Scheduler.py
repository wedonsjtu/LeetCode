class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        if len(tasks) <= 1:
            return len(tasks)
        ans = 0
        list1 = [0] * 26
        for i in tasks:
            list1[ord(i) - ord('A')] += 1
        list1.sort()
        max1 = list1[-1] - 1
        idle = max1 * n
        for i in range(24, -1, -1):
            if list1[i] == 0:
                break
            idle -= min(list1[i], max1)
        if idle > 0:
            return idle + len(tasks)
        return len(tasks)


sol = Solution()
print(sol.leastInterval(["A", "A", "A", "B", "B", "B"], 2))
