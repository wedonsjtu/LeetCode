class Solution:
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word) <= 1:
            return True

        def all_A_a(s, C):
            for ii in s:
                if ord('a' if C else 'A') <= ord(ii) <= ord('z' if C else 'Z'):
                    return False
            return True

        return all_A_a(word[1:], False) or all_A_a(word, True)


sol = Solution()
print(sol.detectCapitalUse("Asdsf"))
print(sol.detectCapitalUse("ssdsf"))
print(sol.detectCapitalUse("ADSAWDF"))
print(sol.detectCapitalUse("ADSAdDF"))
print(sol.detectCapitalUse("AdfsfSs"))
print(sol.detectCapitalUse("dfsdfAdfe"))
