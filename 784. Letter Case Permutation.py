class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        if len(S) == 0:
            return [""]
        if len(S) == 1:
            if 'A' <= S[0] <= 'Z' or 'a' <= S[0] <= 'z':
                return [S.lower(), S.upper()]
            return [S]
        l1 = self.letterCasePermutation(S[1:])
        if 'A' <= S[0] <= 'Z' or 'a' <= S[0] <= 'z':
            l2 = l1.copy()
            for i in range(len(l2)):
                l2[i] = S[0].lower() + l2[i]
                l1[i] = S[0].upper() + l1[i]
            return l2 + l1
        for i in range(len(l1)):
            l1[i] = S[0] + l1[i]
        return l1


sol = Solution()
print(sol.letterCasePermutation("a1B2"))
print(sol.letterCasePermutation("A1B2"))
print(sol.letterCasePermutation("a1b2"))
print(sol.letterCasePermutation("a"))
print(sol.letterCasePermutation("2"))
