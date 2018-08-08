class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s1 = ""
        for ch in s:
            if ord('a') <= ord(ch) <= ord('z') or ord('0') <= ord(ch) <= ord('9'):
                s1 += ch
            elif ord('A') <= ord(ch) <= ord('Z'):
                s1 += chr(ord(ch) - ord('A') + ord('a'))
        return s1 == s1[::-1]


sol = Solution()
print(sol.isPalindrome("A man, a plan, a canal: Panama"))
print(sol.isPalindrome("race a car"))
print(sol.isPalindrome("race car"))
print(sol.isPalindrome(""))
