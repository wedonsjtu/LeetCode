class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        sc = []
        for i in ops:
            if i == 'C':
                sc.pop()
            elif i == 'D':
                sc.append(sc[-1] * 2)
            elif i == '+':
                sc.append(sc[-1] + sc[-2])
            else:
                sc.append(int(i))
        return sum(sc)


sol = Solution()
print(sol.calPoints(["1"]))
