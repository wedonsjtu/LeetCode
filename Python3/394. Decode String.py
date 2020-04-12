class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans1 = [""]
        ans2 = [1]
        i = 0
        num = ''
        while i < len(s):
            while ord('0') <= ord(s[i]) <= ord('9'):
                num += s[i]
                i += 1
                if not ord('0') <= ord(s[i]) <= ord('9'):
                    ans1.append("")
                    ans2.append(int(num))
                    num = ''
                    i += 1
                    break
            else:
                if s[i] == ']':
                    num = ans1.pop() * ans2.pop()
                    ans1[-1] += num
                    num = ""
                    i += 1
                    continue
                ans1[-1] += s[i]
                i += 1
        return ans1[0]


sol = Solution()
print(sol.decodeString("3[a]2[bc]"))
print(sol.decodeString("3[a2[c]]"))
print(sol.decodeString("2[abc]3[cd]ef"))
print(sol.decodeString("abcdef"))
print(sol.decodeString("abcdef2[]"))
print(sol.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef"))
