class Solution:
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) <= 1:
            return 0
        m = 0
        n = 0
        p = None
        ans = -1
        for d in s:
            if p == d:
                m += 1
                if n >= m:
                    ans += 1
            else:
                n = m
                m = 1
                ans += 1
            p = d
        return ans


sol = Solution()
print(sol.countBinarySubstrings("00110011"))
print(sol.countBinarySubstrings("001100"))
print(sol.countBinarySubstrings("00110"))
print(sol.countBinarySubstrings("010"))
print(sol.countBinarySubstrings("00"))
print(sol.countBinarySubstrings("01"))
print(sol.countBinarySubstrings("10"))
