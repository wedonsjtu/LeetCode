class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        ans = [[1]]
        for i in range(1, numRows):
            l1 = [1] * (i + 1)
            for j in range(1, i):
                l1[j] = ans[-1][j-1] + ans[-1][j]
            ans.append(l1)
        return ans


sol = Solution()
for ii in range(6):
    print(ii, sol.generate(ii))
