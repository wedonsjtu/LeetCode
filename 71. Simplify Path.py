class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        s = path.split('/')
        ans = []
        for i in s:
            if i == '' or i == '.':
                continue
            if i == '..':
                if ans:
                    ans.pop()
                continue
            ans.append(i)
        return '/' + '/'.join(ans)


sol = Solution()
print(sol.simplifyPath("/home/"))
print(sol.simplifyPath("/home"))
print(sol.simplifyPath("//"))
print(sol.simplifyPath("a/c/"))
print(sol.simplifyPath("././"))
print(sol.simplifyPath("./../"))
print(sol.simplifyPath(".././"))
print(sol.simplifyPath("///"))
print(sol.simplifyPath("/a/./b/../../c/"))
