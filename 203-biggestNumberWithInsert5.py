
import math
def biggestNumber(origin):
    s=str(origin)
    ans="";
    i=0
    if(origin<0):
        s+='5'
    else:
        for i in range(len(s)):
            if(s[i]>'5'):
                ans+=s[i]
            else:
                ans+='5'
                break;
    return ans+s[i:]

def maxNumber(n):
    ans=-math.inf
    s=str(n)
    if(n>0):
        f=0
    else:
        f=1
    for i in range(f,len(s)+1):
        c=s[:i]+"5"+s[i:]
        ans=max(ans,int(c))
    return ans

print(maxNumber(123))
                
                
