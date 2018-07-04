class Solution:
    def checkRecord(self, s):
        flagA = False
        flagL = 0
        for i in s:
            if i == 'A':
                if flagA:
                    return False
                else:
                    flagA = True
                    flagL = 0
            elif i == 'L':
                if flagL == 2:
                    return False
                else:
                    flagL += 1
            elif flagL > 0:
                flagL = 0
        return True


Sol = Solution()
print(Sol.checkRecord("PLPLALLP"))
print(Sol.checkRecord("LALL"))
