#sliding windows to get the substring in s1
from collections import Counter
from itertools import count

def countAS(s0,s1):
    ans=0
    n0=R=len(s0)
    n1=len(s1)
    C,cur=Counter(s0),Counter(s1[:R])    
    if(cur==C):
        ans+=1
    while(R<n1):
        cur[s1[R]]+=1
        cur[s1[R-n0]]-=1
        if(cur[s1[R-n0]]==0):
            del cur[s1[R-n0]]
        if cur==C:
            ans+=1
        R+=1
    return ans
    
        


print(countAS("abc","bacbdacb"))