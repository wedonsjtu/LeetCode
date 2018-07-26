# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class SummaryRanges:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = []

    def addNum(self, val):
        """
        :type val: int
        :rtype: void
        """
        from bisect import bisect
        position = bisect(self.l, val)
        if position == 0 or self.l[position - 1] != val:
            self.l.insert(position, val)

    def getIntervals(self):
        """
        :rtype: List[Interval]
        """
        if not self.l:
            return []
        d = []
        s = 0
        e = 0
        for i in range(len(self.l)):
            if s == e or self.l[i] - self.l[i - 1] <= 1:
                e += 1
            else:
                d.append(Interval(self.l[s], self.l[e - 1]))
                s = e
                e += 1
        d.append(Interval(self.l[s], self.l[e - 1]))
        return d

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()