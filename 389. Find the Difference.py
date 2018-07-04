class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if len(s) == 0:
            return t
        d1 = dict([[chr(i), 0] for i in range(ord('a'), ord('z')+1)])
        for i in s:
            d1[i] -= 1
        for i in t:
            d1[i] += 1
        for i in range(ord('a'), ord('z')+1):
            if d1[chr(i)] == 1:
                return chr(i)


sol = Solution()
print(sol.findTheDifference("", "a"))
