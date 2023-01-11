from math import ceil
class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """

        # ans=0
        def f(r):
            return sum(ceil(i/r) for i in piles)
        M=max(piles)
        L=1
        R=M
        while L<R:
            mid=(L+R)//2
            if f(mid)<=h:
                R=mid
            else:
                L=mid+1
        return L

piles=[30,11,23,4,20]

h=6
# 6
print(Solution().minEatingSpeed(piles,h))