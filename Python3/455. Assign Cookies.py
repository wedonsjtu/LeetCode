class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if not g:
            return 0
        g.sort()
        s.sort()
        first = 0
        for i in range(len(s)):
            if first >= len(g):
                break
            if g[first] > s[i]:
                continue
            first += 1
        return first


sol = Solution()
print(sol.findContentChildren([1, 2, 3], [1, 1]))
print(sol.findContentChildren([1, 2], [1, 2, 3]))
