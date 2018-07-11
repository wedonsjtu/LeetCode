class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def bC(s):
            sharp = 0
            i = 0
            st = ""
            for i in range(len(s)-1, -1, -1):
                if s[i] == '#':
                    st = s[i+1:]
                    sharp += 1
                    break
            if sharp == 0:
                return s
            for j in range(i-1, -1, -1):
                if s[j] == '#':
                    sharp += 1
                else:
                    if sharp > 0:
                        sharp -= 1
                        continue
                    st = s[j] + st
            return st

        return bC(S) == bC(T)


sol = Solution()
print(sol.backspaceCompare("ab#c", "ad#c"))
print(sol.backspaceCompare("ab##", "c#d#"))
print(sol.backspaceCompare("a##c", "#a#c"))
print(sol.backspaceCompare("a#c", "b"))
print(sol.backspaceCompare("ac", "b"))
print(sol.backspaceCompare("ac#", "#"))
print(sol.backspaceCompare("acdsd#", "########"))
print(sol.backspaceCompare("#a#cdsd#", "###q##"))
