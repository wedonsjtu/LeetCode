class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        def C(down, up):
            ans = 1
            for i in range(down, up, -1):
                ans *= i
            for i in range(2, down - up + 1):
                ans //= i
            return ans

        return [C(rowIndex, i) for i in range(rowIndex + 1)]


sol = Solution()
for j in range(6):
    print(sol.getRow(j))
