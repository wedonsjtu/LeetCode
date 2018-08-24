class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        if not indexes or not S:
            return S
        ans = S
        p = 0
        matrix = sorted([[indexes[i], sources[i], targets[i]] for i in range(len(indexes))], key=lambda x: x[0])
        for i in range(len(indexes)):
            if S[matrix[i][0]: matrix[i][0] + len(matrix[i][1])] == matrix[i][1]:
                ans = ans[:matrix[i][0] + p] + matrix[i][2] + ans[matrix[i][0] + p + len(matrix[i][1]):]
                p += len(matrix[i][2]) - len(matrix[i][1])
        return ans


sol = Solution()
print(sol.findReplaceString("abcd", [0, 2], ["a", "cd"], ["eee", "ffff"]))
print(sol.findReplaceString("abcd", [0, 2], ["abs", "cd"], ["eee", "ffff"]))
print(sol.findReplaceString("abcd", [0, 2], ["ab", "cde"], ["eee", "ffff"]))
print(sol.findReplaceString("abcd", [0, 2, 3], ["ab", "c", "d"], ["a", "fff", "gg"]))
print(sol.findReplaceString("vmokgggqzp", [3, 5, 1], ["kg", "ggq", "mo"], ["s", "so", "bfr"])) # "vbfrssozp"
