class Solution:
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        if len(bits) == 1:
            return True
        i = 0
        while i < len(bits) - 1:
            if bits[i] == 1:
                i += 2
                continue
            i += 1
        if i == len(bits) - 1:
            return True
        return False
