
from itertools import accumulate
def  maxScore(cardPoints,k):
    s=sum(cardPoints)
    n=len(cardPoints)
    p=[0]+list(accumulate(cardPoints))
    
    ans=0
    for i in range(k+1):
        cur=p[i]+s-p[n-(k-i)]
        ans=max(ans,cur)
    return ans
c=[96,90,41,82,39,74,64,50,30]
k=8
print(maxScore(c,k))