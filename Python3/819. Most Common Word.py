class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        st = ""
        d = {}
        ig = (" ", "?", "!", "'", ",", ";", ".")
        for i in paragraph:
            i = i.lower()
            if i in ig:
                if st and st not in banned:
                    if st in d:
                        d[st] += 1
                    else:
                        d[st] = 1
                st = ""
            else:
                st += i
        if st and st not in banned:
            if st in d:
                d[st] += 1
            else:
                d[st] = 1
        return max(d, key=d.get)


sol = Solution()
print(sol.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.",
                         ["hit"]))
print(sol.mostCommonWord("I think that that 'that' that that student "
                         "wrote on the blackboard is wrong.", []))
print(sol.mostCommonWord("BoB", []))
