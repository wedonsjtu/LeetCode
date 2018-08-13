class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) <= 1:
            return len(s)
        first = 0
        end = 0
        ans = 0
        for ch in s:
            for j in range(first, end):
                if ch == s[j]:
                    ans = max(ans, end - first)
                    first = j + 1
                    break
            end += 1
        return max(ans, end - first)


sol = Solution()
print(sol.lengthOfLongestSubstring("abcabcbb"))
print(sol.lengthOfLongestSubstring("bbbbb"))
print(sol.lengthOfLongestSubstring("pwwkew"))
print(sol.lengthOfLongestSubstring("asdfg"))
print(sol.lengthOfLongestSubstring("as"))
print(sol.lengthOfLongestSubstring("aa"))
