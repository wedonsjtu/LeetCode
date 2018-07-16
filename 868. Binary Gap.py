class Solution:
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        ans = 0
        f = 0
        s = bin(N)[2:]
        for i in range(1, len(s)):
            if s[i] == '1':
                ans = max(ans, i - f)
                f = i
        return ans


sol = Solution()
print(sol.binaryGap(22))
print(sol.binaryGap(8))
print(sol.binaryGap(4))
print(sol.binaryGap(2))
print(sol.binaryGap(3))
print(sol.binaryGap(5))
