class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ar = 0
        ai = 0
        br = 0
        bi = 0
        for i in range(len(a)):
            if a[i] == '+':
                ar = int(a[:i])
                ai = int(a[i+1:-1])
                break
        for i in range(len(b)):
            if b[i] == '+':
                br = int(b[:i])
                bi = int(b[i+1:-1])
                break
        cr = ar * br - ai * bi
        ci = ai * br + ar * bi
        return '{0}+{1}i'.format(cr, ci)


sol = Solution()
print(sol.complexNumberMultiply("1+1i", "1+1i"))
print(sol.complexNumberMultiply("1+-1i", "1+-1i"))
