class Solution:
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        r = 0
        r1 = ''
        r2 = ''
        d = dict()
        for i in range(len(A)):
            if A[i] != B[i]:
                r += 1
                if (r > 2) or (r2 != '' and r2 != A[i]) or (r1 != '' and r1 != B[i]):
                    return False
                r1 = A[i]
                r2 = B[i]
            else:
                if A[i] in d:
                    d[A[i]] += 1
                else:
                    d[A[i]] = 1
        if r == 2:
            return True
        if r == 1:
            return False
        for i in d:
            if d[i] >= 2:
                return True
        return False



sol = Solution()
print(sol.buddyStrings("asdf", "asfd"))
print(sol.buddyStrings("asdf", "adsf"))
print(sol.buddyStrings("adfs", "sdfa"))
print(sol.buddyStrings("assd", "asfd"))
print(sol.buddyStrings("asd", "afd"))
print(sol.buddyStrings("assd", "assd"))
print(sol.buddyStrings("as", "as"))
print(sol.buddyStrings("aa", "as"))
print(sol.buddyStrings("aa", "sa"))
print(sol.buddyStrings("as", "sa"))
