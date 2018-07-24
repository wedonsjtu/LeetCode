class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        if not nums2:
            return
        f = 0
        for i in nums2[:n]:
            while nums1[f] <= i and f != m:
                f += 1
            m += 1
            for j in range(m - 1, f, -1):
                nums1[j] = nums1[j - 1]
            nums1[f] = i


sol = Solution()

n1 = [1, 2, 3, 0, 0, 0]
m1 = 3
n2 = [2, 5, 6]
m2 = 3
sol.merge(n1, m1, n2, m2)
print(n1)

n1 = [1, 2, 3, 4, 0, 0, 0]
m1 = 4
n2 = [2, 5, 6]
m2 = 3
sol.merge(n1, m1, n2, m2)
print(n1)

n1 = [1, 2, 3, 4, 0, 0, 0, 0]
m1 = 4
n2 = [1, 2, 3, 4]
m2 = 4
sol.merge(n1, m1, n2, m2)
print(n1)

n1 = [1, 0]
m1 = 1
n2 = [2]
m2 = 1
sol.merge(n1, m1, n2, m2)
print(n1)

n1 = [3, 0]
m1 = 1
n2 = [1, 0, 0]
m2 = 1
sol.merge(n1, m1, n2, m2)
print(n1)
