class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) <= 1:
            return len(s)
        d = dict()
        for i in s:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        ans = 0
        aba = False
        for i in d:
            ans += (d[i] // 2) * 2
            if not aba and d[i] % 2:
                aba = True
        return ans + int(aba)


sol = Solution()
print(sol.longestPalindrome("abccccdd"))
print(sol.longestPalindrome("ab"))
print(sol.longestPalindrome("abc"))
print(sol.longestPalindrome("aabbcc"))
print(sol.longestPalindrome(""))
