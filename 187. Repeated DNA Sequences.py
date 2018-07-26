class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        d = {}
        for i in range(len(s) - 9):
            st = s[i:i + 10]
            if st in d:
                d[st] += 1
                if d[st] == 2:
                    ans.append(st)
            else:
                d[st] = 1
        return ans


sol = Solution()
print(sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
print(sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCC"))
print(sol.findRepeatedDnaSequences("AAAAACCCCC"))
