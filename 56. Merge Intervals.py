# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        d = []
        for interval in intervals:
            d.append((interval.start, True))
            d.append((interval.end, False))
        d.sort(key=lambda x: (x[0], not x[1]))
        d1 = []
        for i in d:
            if i[1]:
                d1.append(i)
            elif d1[-1][0] == d1[0] and d1[-1][1]:
                d1.pop()
            else:
                while not d1[-1][1]:
                    del d1[-2:]
                d1.append(i)
        # print(d1)
        d = []
        for i in range(len(d1) // 2):
            d.append(Interval(d1[2 * i][0], d1[2 * i + 1][0]))
        return d


sol = Solution()
sol.merge([Interval(4, 6), Interval(1, 2), Interval(0, 5)])
sol.merge([Interval(4, 6), Interval(1, 2), Interval(0, 2)])
sol.merge([Interval(4, 6), Interval(1, 3), Interval(0, 2)])
sol.merge([Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)])
sol.merge([Interval(1, 4), Interval(4, 5)])
