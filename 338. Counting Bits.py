class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ans = [0]
        m = 1
        for i in range(1, num + 1):
            if i >= 2 * m:
                m *= 2
            ans.append(ans[i - m] + 1)
        return ans


sol = Solution()
print(sol.countBits(0))
print(sol.countBits(1))
print(sol.countBits(5))
