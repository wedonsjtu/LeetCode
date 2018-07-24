class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        l = str.split(' ')
        if len(l) != len(pattern):
            return False
        d = {}
        for i in range(len(l)):
            if pattern[i] not in d:
                if l[i] in d.values():
                    return False
                d[pattern[i]] = l[i]
            else:
                if d[pattern[i]] != l[i]:
                    return False
        return True


sol = Solution()
print(sol.wordPattern("abba", "dog cat cat dog"))
print(sol.wordPattern("abba", "dog cat cat fish"))
print(sol.wordPattern("aaaa", "dog cat cat dog"))
print(sol.wordPattern("abba", "dog dog dog dog"))
