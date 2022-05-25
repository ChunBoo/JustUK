from collections import defaultdict

class Solution:
    def __init__(self):
        pass
    
    def mostFrequencyNumber(self,intervals):
        d=defaultdict(int)
        
        for i in intervals:
            d[i[0]]+=1
            d[i[1]+1]-=1
        
        c=most=0
        ans=0
        for i in sorted(d.keys()):
            c+=d[i]
            if c>most:
                most=c
                ans=i
        return ans
    
intervals=[[1,3],[1,3,4]]
print(Solution().mostFrequencyNumber(intervals))
            