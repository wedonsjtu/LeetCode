class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = dict()
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = [False, i]
            elif not d[s[i]][0]:
                d[s[i]][0] = True
        ans = -1
        for (b, i) in d.values():
            if not b:
                if i < ans or ans == -1:
                    ans = i
        return ans


sol = Solution()
print(sol.firstUniqChar("leetcode"))
print(sol.firstUniqChar("loveleetcode"))
print(sol.firstUniqChar("hola"))
print(sol.firstUniqChar("hello"))
print(sol.firstUniqChar("byebye"))
