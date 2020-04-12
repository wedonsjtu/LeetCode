class Solution:
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if -7 < num < 7:
            return str(num)
        s1 = "" if num > 0 else "-"
        s = ""
        num = abs(num)
        while num != 0:
            s = str(num % 7) + s
            num = num // 7
        return s1 + s


sol = Solution()
print(sol.convertToBase7(10))
print(sol.convertToBase7(7))
print(sol.convertToBase7(6))
print(sol.convertToBase7(-6))
print(sol.convertToBase7(-16))
