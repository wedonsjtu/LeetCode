class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) <= 2:
            return 0
        res = 0
        left = 0
        right = len(height) - 1
        leftm = 0
        rightm = 0
        while left < right:
            if height[left] < height[right]:
                if height[left] > leftm:
                    leftm = height[left]
                else:
                    res += leftm - height[left]
                left += 1
            else:
                if height[right] > rightm:
                    rightm = height[right]
                else:
                    res += rightm - height[right]
                right -= 1
        return res


sol = Solution()
print(sol.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))


'''#TLE
class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) <= 2:
            return 0
        res = 0
        d = {}
        left = 0
        for h in height:
            if h >= left:
                if left != 0:
                    res += sum(d.values())
                    d.clear()
                left = h
            for i in range(h + 1):
                if i in d:
                    res += d.pop(i)
            for i in range(h + 1, left + 1):
                d[i] = d.get(i, 0) + 1
        return res'''