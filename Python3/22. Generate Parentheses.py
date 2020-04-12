class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0:
            return ['']
        ans = []
        for i in range(n):
            for left in self.generateParenthesis(i):
                for right in self.generateParenthesis(n - i - 1):
                    ans.append('({}){}'.format(left, right))
        return ans


sol = Solution()
for ii in range(4):
    print(sol.generateParenthesis(ii))
