class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        ans = [len(S)] * len(S)
        k = -1
        for i in range(len(S)):
            if S[i] == C:
                ans[i] = 0
        for i in range(len(S)):
            if ans[i] == 0:
                for j in range(i-1, k, -1):
                    ans[j] = min(i - j, ans[j])
                k = i
                for j in range(i+1, len(S)):
                    if ans[j] == 0:
                        break
                    ans[j] = j - i
        return ans


sol = Solution()
print(sol.shortestToChar("werewfdsvfvetrjnecdsevcx", "e"))
