# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):


class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = 1
        h = n
        while l <= h:
            mid = l + (h - l) // 2
            ans = guess(mid)
            if ans == 0:
                return mid
            if ans == -1:
                h = mid - 1
            else:
                l = mid + 1
        return -1
