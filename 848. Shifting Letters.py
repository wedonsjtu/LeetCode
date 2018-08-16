class Solution:
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        sum1 = sum(shifts)
        s = [ch for ch in S[:len(shifts)]]
        for i in range(len(s)):
            sum2 = sum1 % 26
            if ord(s[i]) + sum2 > ord('z'):
                s[i] = chr(ord(s[i]) + sum2 - 26)
            else:
                s[i] = chr(ord(s[i]) + sum2)
            if i < len(shifts):
                sum1 -= shifts[i]
            else:
                break
        return ''.join(s)


sol = Solution()
print(sol.shiftingLetters("abc", [3, 5, 9]))
