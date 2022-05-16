#sliding windows to get the substring in s1 with the value of s0

from collections import Counter
#from itertools import count

def countAS(s0,s1):
    n0=R=len(s0)
    n1=len(s1)
    C=Counter(s0)
    Cur=Counter(s1[:R])
    ans=0
    
    if(C==Cur):
        ans+=1
    while(R<n1):
        Cur[s1[R]]+=1
        Cur[s1[R-n0]]-=1
        if(Cur[s1[R-n0]]==0):
            del Cur[s1[R-n0]]
        if(C==Cur):
            ans+=1
        R+=1
    return ans
        


print(countAS("abc","bacbdacb"))