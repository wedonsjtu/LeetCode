class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        if len(S) == 0:
            return S
        le = ('a', 'e', 'o', 'i', 'u', 'A', 'E', 'I', 'O', 'U')
        l = S.split(' ')
        for i in range(len(l)):
            if l[i][0] in le:
                l[i] = l[i] + "ma" + ("a" * (i+1))
            else:
                l[i] = l[i][1:] + l[i][0] + "ma" + ("a" * (i+1))
        return ' '.join(l)


sol = Solution()
print(sol.toGoatLatin("bs"))
