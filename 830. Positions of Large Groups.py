class Solution:
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        if len(S) < 3:
            return []
        ans = []
        i = 0
        for j in range(1, len(S)):
            if S[i] != S[j]:
                if j - i >= 3:
                    ans.append([i, j - 1])
                i = j
            elif j == len(S) - 1:
                if j - i >= 2:
                    ans.append([i, j])
        return ans


sol = Solution()
print(sol.largeGroupPositions("abbxxxxzzy"))
print(sol.largeGroupPositions("abc"))
print(sol.largeGroupPositions("abcdddeeeeaabbbcd"))
print(sol.largeGroupPositions("aaasss"))
print(sol.largeGroupPositions("sss"))
