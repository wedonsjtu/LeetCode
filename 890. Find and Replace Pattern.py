class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        ans = []
        for word in words:
            d = dict()
            for i in range(len(word)):
                if pattern[i] in d:
                    if d[pattern[i]] != word[i]:
                        break
                else:
                    if word[i] in d.values():
                        break
                    d[pattern[i]] = word[i]
            else:
                ans.append(word)
        return ans


sol = Solution()
print(sol.findAndReplacePattern(["abc", "deq", "mee", "aqq", "dkd", "ccc"], "abb"))
print(sol.findAndReplacePattern(["abc", "deq", "mee", "aqq", "dkd", "ccc"], "abc"))
print(sol.findAndReplacePattern([], "abc"))
