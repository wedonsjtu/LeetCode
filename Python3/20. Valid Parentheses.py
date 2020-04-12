class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True
        if len(s) % 2 == 1 or s[-1] in ('(', '[', '{'):
            return False

        def iV(c, ch):
            return (c == '(' and ch == ')') or (c == '[' and ch == ']') or (c == '{' and ch == '}')

        st = ''
        for i in s:
            if not st:
                if i in (')', ']', '}'):
                    return False
                st += i
            elif iV(st[-1], i):
                st = st[:-1]
            elif i in (')', ']', '}'):
                return False
            else:
                st += i
        return not st


sol = Solution()
print(sol.isValid("((()))"))
print(sol.isValid("()"))
print(sol.isValid("[}"))
print(sol.isValid("(]"))
print(sol.isValid("]("))
print(sol.isValid("(())"))
print(sol.isValid("()()"))
print(sol.isValid("[(])"))
print(sol.isValid("([])"))
print(sol.isValid("([{}])"))
