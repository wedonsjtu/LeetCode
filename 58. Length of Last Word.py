class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = s.split()
        return 0 if not l else len(l[-1])


sol = Solution()
print(sol.lengthOfLastWord("  "))
print(sol.lengthOfLastWord("Hello World  "))
