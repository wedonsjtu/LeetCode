class MyHashMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = []
        self.v = []

    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: void
        """
        from bisect import bisect
        position = bisect(self.l, key)
        if position == 0 or self.l[position - 1] != key:
            self.l.insert(position, key)
            self.v.insert(position, value)
        elif self.l[position - 1] == key:
            self.v[position - 1] = value

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        from bisect import bisect
        position = bisect(self.l, key)
        if position == 0 or self.l[position - 1] != key:
            return -1
        return self.v[position - 1]

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: void
        """
        from bisect import bisect
        position = bisect(self.l, key)
        if position != 0 and self.l[position - 1] == key:
            self.l.pop(position - 1)
            self.v.pop(position - 1)

# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
