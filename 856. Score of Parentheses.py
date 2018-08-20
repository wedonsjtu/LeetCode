class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = [0]
        for i in S:
            if i == '(':
                stack.append(0)
            else:
                score = stack.pop()
                if score == 0:
                    stack[-1] += 1
                else:
                    stack[-1] += 2 * score
        return stack[0]


sol = Solution()
print(sol.scoreOfParentheses("()"))
print(sol.scoreOfParentheses("()()"))
print(sol.scoreOfParentheses("(())"))
print(sol.scoreOfParentheses("(()(()))"))
