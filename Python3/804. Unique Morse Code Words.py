class Solution:
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        M = [".-", "-...", "-.-.", "-..", ".", "..-.",
             "--.", "....", "..", ".---", "-.-", ".-..",
             "--", "-.", "---", ".--.", "--.-", ".-.", "...",
             "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]

        def MorseString(s):
            ss = ""
            for i in s:
                ss += M[ord(i) - ord('a')]
            return ss

        l = []
        le = 0
        for i in words:
            st = MorseString(i)
            if st not in l:
                l.append(st)
                le += 1
        return le


sol = Solution()
ls = []
print(sol.uniqueMorseRepresentations(ls))