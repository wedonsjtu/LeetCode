class Solution:
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        from math import ceil
        s1 = ""
        for i in range(int(ceil(len(s)/(2*k)))):
            s1 += s[2*k*i:2*k*i+k][::-1]
            s1 += s[2*k*i+k:2*k*(i+1)]
        return s1


sol = Solution()
print(sol.reverseStr("abcdefg", 1))
print(sol.reverseStr("abcdefg", 2))
print(sol.reverseStr("abcdefg", 3))
print(sol.reverseStr("abcdefg", 4))
