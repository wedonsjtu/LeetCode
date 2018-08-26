class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = [[0, True]]
        positive = True
        num = ''
        i = 0
        while i < len(s):
            if s[i] == ' ':
                i += 1
                continue
            if s[i] == '-':
                positive = False
                i += 1
                continue
            if s[i] == '+':
                positive = True
                i += 1
                continue
            if s[i] == '(':
                if positive or i == 0 or s[i - 1] == '(':
                    ans.append([0, True])
                else:
                    ans.append([0, False])
                positive = True
                i += 1
                continue
            if s[i] == ')':
                if ans[-1][1]:
                    ans[-2][0] += ans[-1][0]
                    ans.pop()
                else:
                    ans[-2][0] -= ans[-1][0]
                    ans.pop()
                i += 1
                continue
            while i < len(s) and ord('0') <= ord(s[i]) <= ord('9'):
                num += s[i]
                i += 1
                if i == len(s) or (i < len(s) and not ord('0') <= ord(s[i]) <= ord('9')):
                    num = int(num)
                    if positive:
                        ans[-1][0] += num
                    else:
                        ans[-1][0] -= num
                    i -= 1
                    break
            else:
                i -= 1
            i += 1
            num = ''
        return ans[0][0]


sol = Solution()
print(sol.calculate("1+( 5 - ( 5 ) + 2) - 2"))
