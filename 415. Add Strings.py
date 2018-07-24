class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1 = num1[::-1]
        num2 = num2[::-1]
        l = []
        j = 0
        n = 0
        len1 = len(num1)
        len2 = len(num2)
        len3 = max(len1, len2)
        for i in range(len3):
            if len1 - 1 >= i and len2 - 1 >= i:
                n = ord(num1[i]) + ord(num2[i]) - 2 * ord('0')
            elif len1 < i + 1:
                n = ord(num2[i]) - ord('0')
            else:
                n = ord(num1[i]) - ord('0')
            l.append(chr((j + (n % 10)) % 10 + ord('0')))
            if j + (n % 10) < 10:
                j = n // 10
            else:
                j = 1
        if j == 1:
            l.append('1')
        return ''.join(l[::-1])


sol = Solution()
print(sol.addStrings('12', '1'))
print(sol.addStrings('9', '1'))
print(sol.addStrings('9', '8'))
print(sol.addStrings('2', '8'))
print(sol.addStrings('2', '6'))
