class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs or not strs[0]:
            return ""

        def lCP(s1, s2):
            res = ""
            for i in range(len(s1)):
                if i >= len(s2) or s1[i] != s2[i]:
                    return res
                else:
                    res += s1[i]
            return res

        p = strs[0]
        for i in range(1, len(strs)):
            if not strs[i]:
                return ""
            p = lCP(p, strs[i])
            if p == "":
                return ""
        return p


sol = Solution()
print(sol.longestCommonPrefix(["flower", "flow", "flight"]))
print(sol.longestCommonPrefix(["dog", "racecar", "car"]))
print(sol.longestCommonPrefix(["dog"]))
print(sol.longestCommonPrefix(["dog", "dog"]))
print(sol.longestCommonPrefix([]))
