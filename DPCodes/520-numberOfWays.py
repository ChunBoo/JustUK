from functools import lru_cache
class Solution:
    def numberOfWays(self, startPos: int, endPos: int, k: int) -> int:    
        @lru_cache
        def f(s,e,kk):
            d=abs(s-e)
            if d>kk:
                return 0
            if d&1 !=kk&1:  #for the reason of d and kk should be odd or even at same time
                return 0
            if kk==0:
                if s==e:
                    return 1
                else:
                    return 0
            return f(s-1,e,kk-1)+f(s+1,e,kk-1)
        return f(startPos,endPos,k)%(10**9+7)
    
    
start=1
end=2
k=3
print(Solution().numberOfWays(start,end,k))