class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        a = m
        b = n
        for op in ops:
            a = min(a, op[0])
            b = min(b, op[1])
        return a * b


sol = Solution()
print(sol.maxCount(3, 3, [[2, 2], [3, 3]]))
print(sol.maxCount(3, 3, [[3, 3], [2, 2]]))
print(sol.maxCount(3, 2, [[3, 1], [1, 2]]))
l1 = [[18717, 11856], [3154, 2135], [561, 10977], [14679, 3527], [17166, 1028],
      [20980, 3893], [13125, 7906], [23463, 6555], [8173, 2966], [18316, 12040],
      [22715, 6802], [13774, 6466], [22370, 4428], [23389, 8396], [1436, 8292],
      [26525, 8913], [19736, 9021], [6483, 4026]]
print(sol.maxCount(26797, 12287, l1))
