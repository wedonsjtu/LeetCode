class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A) <= 2:
            return True
        start = False
        increasing = True
        for i in range(1, len(A)):
            if not start:
                if A[i] == A[i - 1]:
                    continue
                start = True
                if A[i] < A[i - 1]:
                    increasing = False
            else:
                if increasing:
                    if A[i] < A[i - 1]:
                        return False
                else:
                    if A[i] > A[i - 1]:
                        return False
        return True


sol = Solution()
print(sol.isMonotonic([1, 2, 2, 3]))
print(sol.isMonotonic([1, 1, 2, 2, 3]))
print(sol.isMonotonic([6, 5, 3, 3]))
print(sol.isMonotonic([3, 3, 3]))
print(sol.isMonotonic([1, 3, 2]))
print(sol.isMonotonic([2, 1, 3]))
