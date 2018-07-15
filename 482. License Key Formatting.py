class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        l1 = []
        j = 0
        S = S.strip('-')
        for i in range(len(S)-1, -1, -1):
            if S[i] != '-':
                l1.append(S[i].upper())
                j += 1
                if j == K and i != 0:
                    l1.append('-')
                    j = 0
        return (''.join(l1))[::-1]


sol = Solution()
print(sol.licenseKeyFormatting("5F3Z-2e-9-w", 4))
print(sol.licenseKeyFormatting("5F3Z-2e-9-w", 2))
print(sol.licenseKeyFormatting("2-5g-3-J", 2))
print(sol.licenseKeyFormatting("2-5g-3-J", 3))
print(sol.licenseKeyFormatting("-A---A-AA---AA-------", 1))
