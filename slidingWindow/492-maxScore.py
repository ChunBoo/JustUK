import math
class Solution(object):
    def maxScore(self, cardPoints, k):
        """
        :type cardPoints: List[int]
        :type k: int
        :rtype: int
        """
        n=len(cardPoints)
        if k>=n:
            return sum(cardPoints)
        
        a=sum(cardPoints[:n-k])
        i=n-k
        ma=a
        while i<n:
            a+=cardPoints[i]
            a-=cardPoints[i-n+k]
            ma=min(ma,a)
            i+=1
        return sum(cardPoints)-ma
    
c=[1,2,3,4,5,6,1]
k=3
print(Solution().maxScore(c,k))