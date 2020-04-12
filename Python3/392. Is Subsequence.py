class Solution:
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if not s:
            return True
        if len(s) > len(t):
            return False
        for ch in s:
            if ch not in t:
                return False
        i = 0
        for ch in t:
            if ch == s[i]:
                i += 1
                if i == len(s):
                    return True
        return False


sol = Solution()
print(sol.isSubsequence("abc", "ahbgdc"))
print(sol.isSubsequence("acb", "ahbgdc"))
print(sol.isSubsequence("caa", "caa"))
print(sol.isSubsequence("axc", "ahbgdc"))
