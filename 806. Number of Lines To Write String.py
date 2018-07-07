class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        if not S:
            return [0, 0]
        units = 0
        lines = 1
        for o in S:
            length = widths[ord(o) - ord('a')]
            if units + length > 100:
                lines += 1
                units = length
            else:
                units += length
        return [lines, units]


sol = Solution()
ww = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
ss = "abcdefghijklmnopqrstuvwxyz"
print(sol.numberOfLines(ww, ss))
