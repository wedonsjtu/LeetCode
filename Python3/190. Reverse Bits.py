class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return int("0b" + "{:0<32}".format(bin(n)[2:][::-1]), 2)


sol = Solution()
print(sol.reverseBits(0))
print(sol.reverseBits(43261596))
