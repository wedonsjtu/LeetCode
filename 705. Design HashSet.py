class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = []

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        from bisect import bisect
        position = bisect(self.l, key)
        if position == 0 or self.l[position - 1] != key:
            self.l.insert(position, key)

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        from bisect import bisect
        position = bisect(self.l, key)
        if position != 0 and self.l[position - 1] == key:
            self.l.pop(position - 1)

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        from bisect import bisect
        position = bisect(self.l, key)
        return position != 0 and self.l[position - 1] == key

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)