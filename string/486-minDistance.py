
from math import inf
def minDistance(s,w1,w2):
    arr=s.split()
    ans=inf
    last=None
    for i,cur in enumerate(arr):
        if cur in (w1,w2):
            if last!=None and cur!=arr[last]:
                ans=min(ans,i-last-1)
            last=i
    return ans if ans!=inf else -1
    
    
    
s="a b b c c d"
print(minDistance(s,"a","d"))