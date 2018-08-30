class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        d = dict()
        for ch in magazine:
            if ch in d:
                d[ch] += 1
            else:
                d[ch] = 1
        for ch in ransomNote:
            if ch in d:
                if d[ch] == 0:
                    return False
                d[ch] -= 1
            else:
                return False
        return True


sol = Solution()
print(sol.canConstruct("as", "swa"))
print(sol.canConstruct("aws", "swa"))
print(sol.canConstruct("awq", "swa"))
