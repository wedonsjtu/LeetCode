class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = []
        i = 0
        num = ''
        while i < len(s):
            if s[i] == ' ':
                i += 1
                continue
            if s[i] == '*':
                num = ''
                i += 1
                while i < len(s) and s[i] == ' ':
                    i += 1
                while i < len(s) and ord('0') <= ord(s[i]) <= ord('9'):
                    num += s[i]
                    i += 1
                    if i == len(s) or (i < len(s) and not ord('0') <= ord(s[i]) <= ord('9')):
                        ans[-1] *= int(num)
                continue
            if s[i] == '/':
                num = ''
                i += 1
                while i < len(s) and s[i] == ' ':
                    i += 1
                while i < len(s) and ord('0') <= ord(s[i]) <= ord('9'):
                    num += s[i]
                    i += 1
                    if i == len(s) or (i < len(s) and not ord('0') <= ord(s[i]) <= ord('9')):
                        if ans[-1] >= 0:
                            ans[-1] //= int(num)
                        else:
                            ans[-1] = -((-ans[-1]) // int(num))
                continue
            if s[i] == '-':
                num = '-'
                i += 1
            elif s[i] == '+':
                num = ''
                i += 1
            while i < len(s) and ord('0') <= ord(s[i]) <= ord('9'):
                num += s[i]
                i += 1
                if i == len(s) or (i < len(s) and not ord('0') <= ord(s[i]) <= ord('9')):
                    ans.append(int(num))
            num = ''
        return sum(ans)


sol = Solution()
print(sol.calculate("5/2"))
print(sol.calculate("5*2"))
print(sol.calculate("5+2"))
print(sol.calculate("5+2 / 2* 5"))
print(sol.calculate(" 2 *5+2 / 2* 5"))
print(sol.calculate(" 2 *5-2 / 2* 5"))
print(sol.calculate(" 2  *  5 - 2 / 2* 5"))
print(sol.calculate(" 2  *  5 - 2 / 2* 5 + 2"))
