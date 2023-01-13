#used the prefix and suffix method
from itertools import accumulate
def  maxScore(cardPoints,k):
    n=len(cardPoints)
    p=[0]+list(accumulate(cardPoints))  #p =[0,1,3,6,10,15,21,22]
    s=sum(cardPoints)
    ans=0
    for i in range(k+1):
        cur=p[i]+s-p[n-(k-i)] # here 
        ans=max(ans,cur)
    return ans
c=[96,90,41,82,39,74,64,50,30]
k=8
print(maxScore(c,k))