
import math

def maximumValueAfterInsertingFive(val):
    s=str(val)
    if(val<0):
        f=1
    else:
        f=0
    ans=-math.inf
    for i in range(f,len(s)+1):
        c=s[:i]+"5"+s[i:]
        ans=max(int(c),ans)
    
    return ans


print(maximumValueAfterInsertingFive(823))
        