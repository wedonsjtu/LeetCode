class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        l1 = []
        l2 = []
        for i in s:
            if i in vowels:
                l2.append(i)
        for i in s:
            if i not in vowels:
                l1.append(i)
            else:
                l1.append(l2.pop())
        return ''.join(l1)


sol = Solution()
print(sol.reverseVowels("hello"))
print(sol.reverseVowels("aeiou"))
print(sol.reverseVowels("qqqqq"))
print(sol.reverseVowels(""))
print(sol.reverseVowels("a"))
print(sol.reverseVowels("q"))
