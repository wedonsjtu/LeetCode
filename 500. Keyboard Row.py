class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """

        K = (('q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
              'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'),
             ('a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
              'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'),
             ('z', 'x', 'c', 'v', 'b', 'n', 'm',
              'Z', 'X', 'C', 'V', 'B', 'N', 'M'))

        def fW(word):
            kn = 2
            if not word:
                return True
            for i in (0, 1):
                if word[0] in K[i]:
                    kn = i
                    break
            for i in range(1, len(word)):
                if word[i] not in K[kn]:
                    return False
            return True

        return [word for word in words if fW(word)]


sol = Solution()
l = ["Hello", "Alaska", "Dad", "Peace"]
print(sol.findWords(l))
