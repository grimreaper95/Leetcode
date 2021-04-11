#329. Longest Increasing Path in a Matrix

class Solution:
    def longestIncreasingPath(self, M: List[List[int]]) -> int:
        ylen, xlen = len(M), len(M[0])
        @lru_cache(maxsize=None)
        def dfs(y, x):
            val = M[y][x]
            return 1 + max(
                dfs(y+1,x) if y < ylen - 1 and val > M[y+1][x] else 0,
                dfs(y-1,x) if y > 0 and val > M[y-1][x] else 0, 
                dfs(y,x+1) if x < xlen - 1 and val > M[y][x+1] else 0,
                dfs(y,x-1) if x > 0 and val > M[y][x-1] else 0)
        return max(dfs(y, x) for y in range(ylen) for x in range(xlen))
      
      
#371. Sum of Two Integers

class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask=0xFFFFFFFF # to avoid RTE exception due to infinite loop we mask till 32-bits
        while b:
            k=(a&b)&mask
            a=(a^b)&mask
            b=k<<1
        if (a>>31) & 1: return ~(a^mask) #if a number is negative it does 2's complement twice (once to get the original abs value and then to negate it)
        return a
